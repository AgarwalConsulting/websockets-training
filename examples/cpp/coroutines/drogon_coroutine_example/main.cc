#include <drogon/drogon.h>
#include <future>
#include <iostream>

using namespace drogon;

int nth_resp = 0;

int main() {
    auto client = HttpClient::newHttpClient("http://api.github.com");

    auto req = HttpRequest::newHttpRequest();

    req->setMethod(drogon::Get);
    req->setPath("/");

    for (int i = 0; i < 10; ++i) {
        std::cout << "Sending request " << i << std::endl;

        client->sendRequest(req, [](ReqResult result, const HttpResponsePtr &response) {
                if (result != ReqResult::Ok) {
                    std::cout
                        << "error while sending request to server! result: "
                        << result << std::endl;
                    return;
                }
                std::cout << "receive response!" << std::endl;

                ++nth_resp;

                std::cout << response->getBody() << std::endl;
                std::cout << "count=" << nth_resp << std::endl;
        });
        std::cout << "Initiated request" << i << std::endl;
    }
    app().run();
}
