#ifndef CONCRETEHANDLER2_HPP
#define CONCRETEHANDLER2_HPP
#include <iostream>
#include "handler.hpp"
using namespace std;

class ConcreteHandler2 : public Handler{
public:
    void handleRequest(Request request){
        int val = request.getNum();
        if(val == 2){
            cout<<"F Key Pressed ====== ENTER FUNCTION BELOW ======"<<endl<<endl;

        }
        else{
            getNextHandler()->handleRequest(request);
        }
    }
    int get_code(){
        return 2;
    }
};


#endif // CONCRETEHANDLER2_HPP
