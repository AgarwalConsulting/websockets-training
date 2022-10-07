#pragma once

#include <drogon/HttpController.h>

using namespace drogon;
namespace v1 {
  class employees : public drogon::HttpController<employees> {
    public:
      METHOD_LIST_BEGIN
        METHOD_ADD(employees::index, "/", Get);
        METHOD_ADD(employees::show, "/{id}", Get);
        METHOD_ADD(employees::create, "/", Post);
        METHOD_ADD(employees::update, "/{id}", Put);
        METHOD_ADD(employees::update2,"/{id}", Patch);
        METHOD_ADD(employees::destory, "/{id}", Delete);

      // use METHOD_ADD to add your custom processing function here;
      // METHOD_ADD(employees::get, "/{2}/{1}", Get); // path is /v1/employees/{arg2}/{arg1}
      // METHOD_ADD(employees::your_method_name, "/{1}/{2}/list", Get); // path is /v1/employees/{arg1}/{arg2}/list
      // ADD_METHOD_TO(employees::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

      METHOD_LIST_END

      // your declaration of processing function maybe like this:
      void index(const HttpRequestPtr &req,
                        std::function<void (const HttpResponsePtr &)> &&callback);
      void show(const HttpRequestPtr &req,
                        std::function<void (const HttpResponsePtr &)> &&callback, int userId);
      void create(const HttpRequestPtr& req,
                        std::function<void (const HttpResponsePtr &)> &&callback);
      void destory(const HttpRequestPtr &req,
                        std::function<void (const HttpResponsePtr &)> &&callback, int userId);
      void update(const HttpRequestPtr &req,
                        std::function<void (const HttpResponsePtr &)> &&callback, int userId);
      void update2(const HttpRequestPtr &req,
                        std::function<void (const HttpResponsePtr &)> &&callback, int userId);
  };
}
