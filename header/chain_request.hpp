#ifndef CHAIN_REQUEST_HPP_
#define CHAIN_REQUEST_HPP_
#include <iostream>
using namespace std;
class Request
{
public:
    Request(int num):_Num(num){}
    int getNum()
    {
        return _Num;
    }
private:
    int _Num;
};
#endif // CHAIN_REQUEST_HPP_
