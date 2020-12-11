#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
using namespace std;
class Base {
    public:
        /* Constructors */
        Base() ;
        Base(int type):_type(type){}

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringifyInt() = 0;
        virtual std::string stringify() = 0;
        virtual int precedence() = 0;
        virtual int associative() = 0;
        virtual char get_item() const{};
        virtual double get_number(){};
        int get_type(){
            return _type;
        }
    private:
        int _type;
};

#endif //__BASE_HPP__
