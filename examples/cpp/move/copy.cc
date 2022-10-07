#include<iostream>
#include<stdio.h>
#include <cstring>

class Copy_constructor_demo_class {
    public:
        Copy_constructor_demo_class() = default;
        Copy_constructor_demo_class(const char* s_variable)
        {
            std::cout<<"CREATED\n";
            m_Size = strlen(s_variable);
            m_Data = new char[m_Size];
            std::cout<<"ADDRESS OF STRING AT INIT: "<<&m_Data<<std::endl;
            memcpy(m_Data, s_variable, m_Size);
        }

        Copy_constructor_demo_class(const Copy_constructor_demo_class& other)
        {
            std::cout<<"COPIED\n";
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
            std::cout<<"ADDRESS OF COPIED STRING: "<<&m_Data<<std::endl;
        }

        ~Copy_constructor_demo_class()
        {
            delete m_Data;
        }

        void Print()
        {
            std::cout<<m_Data<<std::endl;
        }

    private:
        char* m_Data;
        uint32_t m_Size;

};

class Entity {
    public:
        Entity(const Copy_constructor_demo_class& name)
            : m_Name(name)
        {}
        void PrintName() {
            m_Name.Print();
        }

    private:
        Copy_constructor_demo_class m_Name;
};

int main() {
    Entity entity(Copy_constructor_demo_class("Hello"));
    entity.PrintName();
}
