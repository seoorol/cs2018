const http = require("http");

const server = http.createServer((req, res) =>
{
    res.statucCode = 200;
    res.setHeader('Content-Type', "text/plain");
    res.end("Hello node js! \n");
});

server.listen(8080, "220.83.195.77", ()=>
    {
        console.log("Server is running....");

    })