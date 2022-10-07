#include<iostream>
#include<string>

// in order to use smart pointers you have to include this header file
#include<memory>

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
};

int main(int argc, char const *argv[]) {
    {
        std::shared_ptr<Something> s1;
        {
            std::shared_ptr<Something> something = std::make_shared<Something>();
            s1=something;
            std::cout<<"Object created"<< std::endl;
        }
        std::cout<<"I am in outter scope"<< std::endl;
    }
    return 0;
}
