#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    Base * res;
    srand(time(0));
    int val = rand() % 3;
    if (val == 0){
        res = new A;
        std::cout << "A was created" << std::endl;
        return res;
    }
    else if (val == 1){
        res = new B;
        std::cout << "B was created" << std::endl;
        return res;
    }
    else{
        res = new C;
        std::cout << "C was created" << std::endl;
        return res;
    }
}

void identify_from_pointer(Base * p){
    if (dynamic_cast<A *>(p) != NULL){
        std::cout << "A identified from pointer" << std::endl;
    }
    if (dynamic_cast<B *>(p) != NULL){
        std::cout << "B identified from pointer" << std::endl;
    }
    if (dynamic_cast<C *>(p) != NULL){
        std::cout << "C identified from pointer" << std::endl;
    }
}

void identify_from_reference( Base & p){
    try{
        A & a = dynamic_cast<A &>(p);
        std::cout << "A identified from reference" << std::endl;
    }
    catch (const std::exception & ex){

    }
    try{
        B & b = dynamic_cast<B &>(p);
        std::cout << "B identified from reference" << std::endl;
    }
    catch (const std::exception & ex){

    }
    try{
        C & c = dynamic_cast<C &>(p);
        std::cout << "C identified from reference" << std::endl;
    }
    catch (const std::exception & ex){

    }
}

int main(){
    Base * rand_base_ptr = generate();
    Base & rand_base_ref = *rand_base_ptr;
    identify_from_pointer(rand_base_ptr);
    identify_from_reference(rand_base_ref);
    return 0;
}