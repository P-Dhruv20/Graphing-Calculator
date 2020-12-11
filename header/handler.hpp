#ifndef HANDLER_HPP_
#define HANDLER_HPP_
#include "chain_request.hpp"
#include "animate.hpp"
class Handler{
public:
    Handler(Handler* handler = nullptr): _NextHandler(handler){}
    virtual void handleRequest(Request request){};
    virtual void setNextHandler(Handler* handler){
        _NextHandler = handler;
    }
    virtual int get_code(){};
    Handler* getNextHandler(){
        return _NextHandler;
    }

private:
    Handler* _NextHandler;



};

#endif // HANDLER_HPP_
