#include "v1_employees.h"
#include <string>
#include<vector>
#include <algorithm>
#include<jsoncpp/json/json.h>
#include<jsoncpp/json/value.h>

using namespace v1;
dataStorage ds;
// Add definition of your processing function here

void employees::index(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback)
{
    //Verify the validity of the token, etc.
    //Read the database or cache to get user information
    Json::Value ret;
    //Json::Value temp;
    // TODO: Create a vector of employees & return it as JSON.

    //u2.id=2;
    //u2.projectid=2;
    //u2.name="Abhishek";
    //u2.department="Development";
    //vector_of_users.push_back(u2);
    //std::cout<<"ret"<<ret<<std::endl;    
    //for (auto i =vector_of_users.begin(); i != vector_of_users.end(); ++i)
    //{
    //    temp["id"]=(*i).id;
    //    temp["name"]=(*i).name;
    //    temp["department"]=(*i).department;
    //    temp["projectID"]=(*i).projectid;
    //    ret.append(temp);
    //}
    //std::cout<<"ret"<<ret<<std::endl; 
    
    ret=ds.index_action();
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void employees::getInfo(const HttpRequestPtr &req, 
                      std::function<void(const HttpResponsePtr &)> &&callback, int userId)
{
    Json::Value ret;

    //for (auto i =vector_of_users.begin(); i != vector_of_users.end(); ++i)
    //{
    //    if((*i).id == userId)
    //    {
    //        ret["id"]=(*i).id;
    //        ret["name"]=(*i).name;
    //        ret["department"]=(*i).department;
    //        ret["projectID"]=(*i).projectid;    
    //    }   
    //}
    ret=ds.show_action(userId);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    std::cout<<ret;
    callback(resp); 
}

void employees::addInfo(const HttpRequestPtr& req,
                      std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto json=req->getJsonObject();
    //std::cout<<json;
    //auto jsonPtr = req.getBody();
    //auto json = *jsonPtr;
    Json::Value ret;
    //auto json = HttpResponse::getBody();
    std::string name = (*json)["name"].asString();
    std::string department = (*json)["department"].asString();
    std::string projectID = (*json)["projectID"].asString();
    ret=ds.create_action(name,department,projectID);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    //std::cout<<ret;
    callback(resp); 
}

void employees::deleteInfo(const HttpRequestPtr &req,
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId)
{
    Json::Value ret;
    ret=ds.delete_action(userId);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    //std::cout<<ret;
    callback(resp); 
}

// void update_full_info(const HttpRequestPtr &req, 
//                       std::function<void (const HttpResponsePtr &)> &&callback, int userId)
// {

//     //auto jsonPtr = req.getJsonObject();
//     //auto json = *jsonPtr;
//     //Json::Value ret;
//     ////auto json = HttpRequest::getBody();
//     //std::string name = (*json)["name"].asString();
//     //std::string department = (*json)["department"].asString();
//     //int projectID = (*json)["projectID"];
//     //ret=ds.update_full_info_action(userId,name,department,projectID);
//     //auto resp=HttpResponse::newHttpJsonResponse(ret);
//     //std::cout<<ret;
//     //callback(resp); 
// }


// void update_some_info(const HttpRequestPtr &req, 
//                       std::function<void (const HttpResponsePtr &)> &&callback, int userId)
// {
    
// }