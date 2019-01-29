#include<iostream>
using namespace std;

void print(int a);
void print(float a);
int main()
{
  int a=100;
  float b=8.99;
  print(a);
  print(b);
}
void print(int a)
{
  cout<<a<<endl;
}
void print(float a)
{
  cout<< a << endl;
}
