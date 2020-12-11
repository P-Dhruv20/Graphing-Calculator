#include <iostream>
#include "base.cpp"
#include <queue>
#include "eval.cpp"
#include "operator.cpp"
#include "op.cpp"
#include "add.cpp"
#include "sub.cpp"
#include "div.cpp"
#include "pow.cpp"
#include "mult.cpp"
#include "trig.cpp"

using namespace std;

int main(){
  cout<<"HELLO";
  queue<Base*> hold;
  string temp2;
  cout<<endl<<endl;
  cout<<"Input Expression: ";
  cin>>temp2;

  double val = 0;
  cout<<endl<<endl<<endl;
  cout<<"================================================="<<endl<<endl<<endl;
  cout<<"inputs: "<<temp2<<endl;
  hold = shunting_yard(temp2);
  val = eval(hold);
  cout<<endl;
  cout<<"result: "<<val;
  cout<<endl<<endl<<endl;
  cout<<"================Closed Normally=================="<<endl<<endl<<endl;
  return 0;

}
