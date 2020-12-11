#include "../header/trig.hpp"

Trig::Trig(string name):Base(3),_name(name){}


double Trig::evaluating(double result){
    if(_name == "sin"){
        return sin(result);
    }
    else if(_name == "cos"){
        return cos(result);
    }
    else if(_name == "tan"){
        return tan(result);
    }
}
std::string Trig::stringify(){
    return _name;
}
