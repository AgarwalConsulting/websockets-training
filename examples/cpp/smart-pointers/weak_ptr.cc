#include<iostream>
#include<string>
#include<memory>//in order to use smart pointers you have to include this header file

class Something {
    public:
        Something() {
            std::cout<<"Created Something"<<std::endl;
        }

        ~Something() {
            std::cout<<"Destroyed Something"<<std::endl;
        }

        void sayHi() {
            std::cout<<"Hi"<<std::endl;
        }

        int data = 23;
};

int main(int argc, char const *argv[]) {
    {
        std::shared_ptr<Something> s1;
        std::cout<<"declared S1\n";
        {

            //std::shared_ptr<Something> somethingShared = std::make_shared<Something>();
            s1 = std::make_shared<Something>();
            std::cout<<"created shared pointer\n";

            std::weak_ptr<Something> somethingWeak = s1;

            std::cout<<"Object created"<< std::endl;

            // somethingWeak->sayHi();
            // std::cout<<somethingWeak.data << std::endl;

        }

        std::cout<<"I am in outter scope"<< std::endl;

        s1->sayHi();
    }

    return 0;
}
