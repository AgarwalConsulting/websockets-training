// Adapted from: https://github.com/drogonframework/drogon/blob/master/examples/websocket_client/WebSocketClient.cc
#include <drogon/drogon.h>
#include <drogon/WebSocketClient.h>
#include <drogon/HttpAppFramework.h>

#include <iostream>

using namespace drogon;
using namespace std::chrono_literals;

int main(int argc, char *argv[]) {
    // std::string serverString = "wss://echo.websocket.org/";
    // std::string path = "/";

    std::string serverString = "ws://localhost:3000";
    std::string path = "/echo";
    // std::string server;
    // std::string path;
    // optional<uint16_t> port;

    // // Connect to a public echo server
    // if (argc > 1 && std::string(argv[1]) == "-p")
    // {
    //     server = "wss://echo.websocket.org";
    //     path = "/";
    // }
    // else
    // {
    //     server = "ws://127.0.0.1";
    //     port = 3000;
    //     path = "/echo";
    // }

    // std::string serverString;
    // if (port.value_or(0) != 0)
    //     serverString = server + ":" + std::to_string(port.value());
    // else
    //     serverString = server;
    auto wsPtr = WebSocketClient::newWebSocketClient(serverString);
    auto req = HttpRequest::newHttpRequest();
    req->setPath(path);

    // Message handler
    wsPtr->setMessageHandler([](const std::string &message,
                                const WebSocketClientPtr &,
                                const WebSocketMessageType &type) {
        std::string messageType = "Unknown";
        if (type == WebSocketMessageType::Text)
            messageType = "text";
        else if (type == WebSocketMessageType::Pong)
            messageType = "pong";
        else if (type == WebSocketMessageType::Ping)
            messageType = "ping";
        else if (type == WebSocketMessageType::Binary)
            messageType = "binary";
        else if (type == WebSocketMessageType::Close)
            messageType = "Close";

        LOG_INFO << "new message (" << messageType << "): " << message;
    });

    // Close Handler
    wsPtr->setConnectionClosedHandler([](const WebSocketClientPtr &) {
        LOG_INFO << "WebSocket connection closed!";
    });

    // Initiate Connection
    LOG_INFO << "Connecting to WebSocket at " << serverString;
    wsPtr->connectToServer(
        req,
        [](ReqResult r,
           const HttpResponsePtr &,
           const WebSocketClientPtr &wsPtr) {
            if (r != ReqResult::Ok)
            {
                LOG_ERROR << "Failed to establish WebSocket connection!";
                wsPtr->stop();
                return;
            }
            LOG_INFO << "WebSocket connected!";
            wsPtr->getConnection()->setPingMessage("", 2s);
            wsPtr->getConnection()->send("hello!");
        });

    // Quit the application after 15 seconds
    app().getLoop()->runAfter(15, []() { app().quit(); });

    app().setLogLevel(trantor::Logger::kDebug);
    app().run();
    LOG_INFO << "bye!";
    return 0;
}
