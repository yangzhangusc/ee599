#include<iostream>
using namespace std;
class Base{

 public:
   virtual void print(){cout<<"Base"<<endl;}
};
class Child:public Base{

 public:
  void print(){cout<<"Child"<<endl;}

};
int main()
{
  Base base;
  Child child;
  Base *p;
  p=&base;
  p->print();
  p=&child;
  p->print();
}
