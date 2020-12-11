#ifndef CONCRETEHANDLER1_H
#define CONCRETEHANDLER1_H
#include <iostream>
#include "handler.hpp"
#include "animate.hpp"
using namespace std;

class ConcreteHandler1 : public Handler{
public:
    void handleRequest(Request request){
        int val = request.getNum();
        if(val == 1){
            cout<<"Escape Key Pressed ==== CLOSING GRAPHING WINDOW ==== RETURNING TO MAIN MENU"<<endl<<endl;
        }
        else{
            getNextHandler()->handleRequest(request);
        }
    }
    int get_code(){
        return 1;
    }
};


#endif // CONCRETEHANDLER1_H
