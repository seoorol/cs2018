//#include "stdafx.h"
#include "./irrlicht/include/irrlicht.h"
#include "plusEngine.h"

namespace plusEngine {
	//gdi plus �ʱ�ȭ �ڵ� 
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	
	void startUpGdiPlus()
	{
		//----------------------------------------------------------------------
		// Initialize GDI+.
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		//----------------------------------------------------------------
				

	}
	void CloseGdiPlus()
	{
		//--------------------------------------
		//gdi plus �����ڵ� 
		GdiplusShutdown(gdiplusToken);
		//--------------------------------------
	}

	void printf(Graphics *grp,Font &font,Pen &pen,Brush &brush,  int x, int y, TCHAR *fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
		static TCHAR szBuf[1024];
		vswprintf_s(szBuf, 1024, fmt, ap);
		grp->DrawString(szBuf, -1, &font, PointF((Gdiplus::REAL)x, (Gdiplus::REAL)y), &brush);
		va_end(ap);
	}

	void printf(Graphics *grp, int x, int y, const TCHAR *fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
		static TCHAR szBuf[1024];
		vswprintf_s(szBuf, 1024, fmt, ap);
		
		Pen pen(Color(255, 0, 0));
		Gdiplus::SolidBrush brushBlack(Color(0, 0, 0));
		FontFamily  fontFamily(L"����");
		Font        font(&fontFamily, 12, FontStyleRegular, UnitPixel);
		grp->DrawString(szBuf, -1, &font, PointF((Gdiplus::REAL)x, (Gdiplus::REAL)y), &brushBlack);

		va_end(ap);
	}


	//DWORD WINAPI ThreadFunc(LPVOID temp)
	void (*fpOnLoop)(double);
	void(*fpOnRender)(double,Graphics*);

	void GDIPLUS_Loop(MSG &msg, Gdiplus::Rect rectScreen)
	{
		//----------------------------------------------------------------------
		//gdi plus �ʱ�ȭ �ڵ� 
		GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR           gdiplusToken;
		fpOnLoop = NULL;
		fpOnRender = NULL;

		// Initialize GDI+.
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		//-----------------------------------------------------------------------

		{
			bool quit = false;
			//gdiplus �� �˴ٿ� �Ǳ����� ��ü���� �����Ǿ�� �ϹǷ� �Ϻη� �������������� �Ѵܰ� ������ ����ߴ�.			
			Bitmap bmpMem(rectScreen.Width, rectScreen.Height);
			Graphics* pBackScreen = Graphics::FromImage(&bmpMem);			

			while (!quit) {

				if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
				{
					if (msg.message == WM_QUIT)
						quit = true;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else {
					static LONG prev_tick;
					SYSTEMTIME time;
					GetSystemTime(&time);
					LONG time_ms = (time.wSecond * 1000) + time.wMilliseconds;
					// Get DC
					HDC hdc = GetDC(msg.hwnd);
					Graphics graphics(hdc);
					double fDelta = (time_ms - prev_tick) / 1000.;

					//����
					if (fpOnLoop) {
						fpOnLoop(fDelta);
					}

					//���� 
					if (fpOnRender) {
						fpOnRender(fDelta, pBackScreen);
					}

					graphics.DrawImage(&bmpMem, rectScreen);
					ReleaseDC(msg.hwnd, hdc);

					prev_tick = time_ms;
				}
			}
		}

		//--------------------------------------
		//gdi plus �����ڵ� 
		GdiplusShutdown(gdiplusToken);
		//--------------------------------------
	}
		

}