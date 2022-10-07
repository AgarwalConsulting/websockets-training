#include <drogon/drogon.h>
#include <future>
#include <iostream>

using namespace drogon;

int nth_resp = 0;

int main()
{
        auto client = HttpClient::newHttpClient("http://www.google.com");
        auto req = HttpRequest::newHttpRequest();
        req->setMethod(drogon::Get);
        req->setPath("/");
        req->setParameter("q", "Gaurav Agarwal");

        for (int i = 0; i < 10; ++i)
        {
            LOG_INFO << "Initiating Request...";
            client->sendRequest(
                req, [](ReqResult result, const HttpResponsePtr &response) {
                    if (result != ReqResult::Ok)
                    {
                        std::cout
                            << "error while sending request to server! result: "
                            << result << std::endl;
                        return;
                    }

                    std::cout << "receive response!" << std::endl;
                    // auto headers=response.
                    ++nth_resp;
                    std::cout << response->getBody() << std::endl;
                    auto cookies = response->cookies();
                    for (auto const &cookie : cookies)
                    {
                        std::cout << cookie.first << "="
                                  << cookie.second.value()
                                  << ":domain=" << cookie.second.domain()
                                  << std::endl;
                    }
                    std::cout << "count=" << nth_resp << std::endl;
                });
            LOG_INFO << "Completed Request...";
        }

    app().run();
}
