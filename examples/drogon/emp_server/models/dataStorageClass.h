using namespace std;

namespace dataStorageClass {
  class dataStorageClass {
    public:
    class employee {
        public:
        int id;
        std::string name;
        std::string department;
        std::string projectid;
    };

    std::vector<employee> vector_of_employee;

    int last_generated_id=0;

    dataStorageClass() {
        create_action("Gaurav", "LnD", "1001");
    }

    Json::Value index_action() {
      Json::Value final_json;
      Json::Value employee_json;
      for (auto i =vector_of_employee.begin(); i != vector_of_employee.end(); ++i)
      {
        employee_json["id"]=(*i).id;
        employee_json["name"]=(*i).name;
        employee_json["department"]=(*i).department;
        employee_json["projectID"]=stoi((*i).projectid);
        final_json.append(employee_json);
      }
      return final_json;
    }

    Json::Value show_action(int ID) {
      Json::Value final_json;
      for (auto i =vector_of_employee.begin(); i != vector_of_employee.end(); ++i)
      {
        if((*i).id == ID)
        {
            final_json["id"]=(*i).id;
            final_json["name"]=(*i).name;
            final_json["department"]=(*i).department;
            final_json["projectID"]=stoi((*i).projectid);
            return final_json;
        }
      }
      final_json["HTTP_response_status_code"]="400";
      final_json["error"]="User not found";
      return final_json;
    }

    Json::Value create_action(std::string Name, std::string Department, std::string ProjectID) {
      int size_of_vector=vector_of_employee.size();
      employee employee_object;
      employee_object.id=last_generated_id+1;
      last_generated_id=last_generated_id+1;
      employee_object.projectid=ProjectID;
      employee_object.name=Name;
      employee_object.department=Department;
      vector_of_employee.push_back(employee_object);
      return show_action(employee_object.id);
    }

    Json::Value update_action(int ID, std::string Name, std::string Department, std::string ProjectID) {
      Json::Value final_json;
      if(Name.empty() || Department.empty() || ProjectID.empty())
      {
          final_json["error"]="Bad Request - Your request is missing parameters. Please verify and resubmit.";
          final_json["HTTP_response_status_code"]="400";
          return final_json;
      }
      for (auto i =vector_of_employee.begin(); i != vector_of_employee.end(); ++i)
        {
          if((*i).id == ID)
          {
            (*i).name=Name;
            (*i).department=Department;
            (*i).projectid=ProjectID;
            break;
          }
        }
        return show_action(ID);
    }

    Json::Value update2_action(int ID, std::string Name, std::string Department, std::string ProjectID) {
      Json::Value final_json;
      for (auto i =vector_of_employee.begin(); i != vector_of_employee.end(); ++i)
        {
          if((*i).id == ID)
          {
            if(!Name.empty())
              (*i).name=Name;
            if(!Department.empty())
              (*i).department=Department;
            if(!ProjectID.empty())
              (*i).projectid=ProjectID;
            return show_action(ID);
          }
        }
        final_json["error"]="Bad Request - User not found";
        final_json["HTTP_response_status_code"]="400";
        return final_json;
    }

    Json::Value destory_action(int ID) {
      Json::Value final_json;
      int position;
      for(int i=0; i < vector_of_employee.size(); i++)
      {
        if(vector_of_employee[i].id== ID)
        {
          position = i;
          vector_of_employee.erase(vector_of_employee.begin()+position);
          final_json["Status"]="User deleted";
          return final_json;
        }
      }
      final_json["HTTP_response_status_code"]="400";
      final_json["error"]="User not found";
      return final_json;
    }
  };
}
