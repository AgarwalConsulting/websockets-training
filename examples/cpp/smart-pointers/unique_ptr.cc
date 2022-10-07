#include<iostream>
#include<string>
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
        //std::unique_ptr<Something> something = new Something();
        // above construction is not possible using unique pointers

        std::unique_ptr<Something> something(new Something());
        //this is how you define a unique pointer;

        // the unique pointer has to be unique ie. it can not be copied.
        // so the below codeline would give you an error
        // std::unique_ptr<Something> s1 = something;


        something->sayHi();
        //as control goes out of this scope
        //distructor of class Something will
        //automatically be called.
    }

    // Something *s = new Something();
    // delete s;

    // As C++ does not have garbage collector so you have to manually free the memory
    // when dealing with small codes, it is fine but when the complexity of code increases
    // its really easy to forget to deallocate the memory which makes program prone to bugs
    // and memory leaks.

    return 0;
}


// int main(int argc, char const *argv[]) {

//     {
//         Something *s = new Something();
//         //this is how you define a unique pointer;

//         //the unique pointer has to be unique ie. it can not be copied.
//         //so the below codeline would give you an error
//         //std::unique_ptr<Something> s1 = something;


//         s->sayHi();

//         //as control goes out of this scope
//         //distructor of class Something will
//         //automatically be called.
//     }

//     //Something *s = new Something();
//     //delete s;
//     //As C++ does not have garbage collector so you have to manually free the memory
//     //when dealing with small codes, it is fine but when the complexity of code increases
//     //its really easy to forget to deallocate the memory which makes program prone to bugs
//     //and memory leaks.
//     std::cout<<"EXIT\n";
//     return 0;
// }
