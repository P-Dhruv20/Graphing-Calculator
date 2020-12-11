#ifndef __MOCK_CLASS_HPP__
#define __MOCK_CLASS_HPP__

#include "base.hpp"


class SevenOpMock: public Base {
    public:
        SevenOpMock() { };

        virtual double evaluate() { return 7.5; }
        virtual std::string stringify() { return "7.5"; }
};

class FiveOpMock: public Base {
    public:
        FiveOpMock() { };

        virtual double evaluate() { return 5.5; }
        virtual std::string stringify() { return "5.5"; }
};

class NegativeThreeOpMock: public Base {
    public:
        NegativeThreeOpMock() { };

        virtual double evaluate() { return -3.0; }
        virtual std::string stringify() { return "-3.0"; }
};

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { };

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "0.0"; }
};

class TenOpMock: public Base {
    public:
        TenOpMock() { };
        
        virtual double evaluate() { return 10.0; }
        virtual std::string stringify() { return "10.0"; }
};

class NegativeTenOpMock: public Base {
    public:
        NegativeTenOpMock() { };

        virtual double evaluate() { return -10.0; }
        virtual std::string stringify() { return "-10.0"; }
};

#endif
