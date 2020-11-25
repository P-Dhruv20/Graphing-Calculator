#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual int evaluateInt() = 0;
	virtual std::string stringifyInt() = 0;
	virtual std::string stringify() = 0;
};

#endif //__BASE_HPP__
