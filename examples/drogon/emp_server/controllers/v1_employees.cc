#include "v1_employees.h"
#include "dataStorageClass.h"
#include <string>
#include<vector>
#include <algorithm>

using namespace v1;

dataStorageClass::dataStorageClass  employees_data;

void employees::index(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value ret;
    ret=employees_data.index_action();
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void employees::show(const HttpRequestPtr &req,
                      std::function<void(const HttpResponsePtr &)> &&callback, int userId)
{
    Json::Value ret;
    ret=employees_data.show_action(userId);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void employees::create(const HttpRequestPtr& req,
                      std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto json=req->getJsonObject();
    Json::Value ret;
    std::string name = (*json)["name"].asString();
    std::string department = (*json)["department"].asString();
    std::string projectID = (*json)["projectID"].asString();
    if(name.empty() || department.empty() || projectID.empty())
    {
        ret["error"]="Bad Request - Your request is missing parameters. Please verify and resubmit.";
        ret["HTTP_response_status_code"]="400";
    }
    else
    {
        ret=employees_data.create_action(name,department,projectID);
    }
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    if(ret["HTTP_response_status_code"]=="400")
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
    callback(resp);
}

void employees::destory(const HttpRequestPtr &req,
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId)
{
    Json::Value ret;
    ret=employees_data.destory_action(userId);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    if(ret["HTTP_response_status_code"]=="400")
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
    //std::cout<<ret;
    callback(resp);
}

void employees::update(const HttpRequestPtr &req,
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId)
{

    auto json=req->getJsonObject();
    Json::Value ret;
    std::string name = (*json)["name"].asString();
    std::string department = (*json)["department"].asString();
    std::string projectID = (*json)["projectID"].asString();
    ret=employees_data.update_action(userId,name,department,projectID);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    if(ret["HTTP_response_status_code"]=="400")
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
    callback(resp);
}


void employees::update2(const HttpRequestPtr &req,
                       std::function<void (const HttpResponsePtr &)> &&callback, int userId)
{
    auto json=req->getJsonObject();
    Json::Value ret;
    std::string name = (*json)["name"].asString();
    std::string department = (*json)["department"].asString();
    std::string projectID = (*json)["projectID"].asString();
    ret=employees_data.update2_action(userId,name,department,projectID);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    if(ret["HTTP_response_status_code"]=="400")
        resp->setStatusCode(HttpStatusCode::k400BadRequest);
    callback(resp);
}
