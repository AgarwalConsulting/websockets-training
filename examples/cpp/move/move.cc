#include<iostream>
#include<stdio.h>
#include <cstring>

class Move_constructor_demo_class {
    public:
        Move_constructor_demo_class() = default;
        Move_constructor_demo_class(const char* string) {
            std::cout<<"CREATED\n";
            m_Size = strlen(string);
            m_Data = new char[m_Size];
            std::cout<<"ADDRESS OF STRING: "<<&m_Data<<std::endl;
            memcpy(m_Data, string, m_Size);
        }

        Move_constructor_demo_class(const Move_constructor_demo_class& other) {
            std::cout<<"COPIED\n";
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
        }

        Move_constructor_demo_class(Move_constructor_demo_class&& other) noexcept {
            std::cout<<"MOVED\n";
            m_Size = other.m_Size;
            m_Data = other.m_Data;
            std::cout<<"ADDRESS OF STRING AFTER MOVING: "<<&m_Data<<std::endl;
            other.m_Size=0;
            other.m_Data=nullptr;
        }

        ~Move_constructor_demo_class() {
            std::cout<<"DESTROYED "<<&m_Data<<"\n";
            delete m_Data;
        }

        void Print() {
            for (uint32_t i = 0; i < m_Size; i++)
            {
                printf("%c", m_Data[i]);
            }
            printf("\n");

        }

    private:
        char* m_Data;
        uint32_t m_Size;

};

class Run {
    public:
        Move_constructor_demo_class m_Name;
        Run(const Move_constructor_demo_class& name)
            : m_Name(name)
        {}

        Run(Move_constructor_demo_class&& name)
            : m_Name(std::move(name))
        {}

        void PrintName() {
            m_Name.Print();
        }

};

int main() {
    Run Run(Move_constructor_demo_class("Hello"));
    Run.PrintName();
}
