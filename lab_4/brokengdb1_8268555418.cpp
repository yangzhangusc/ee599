#include<iostream>
 
using namespace std;
 
long factorial(int n);
 
int main()
{
    int n;
    cout<<"Please enter n:"<<endl;
    cin>>n;
    long val=factorial(n);
    cout<<"n factorial is: "<<val<<endl;

    return 0;
}
 
long factorial(int n)
{
    
    if(n)
      return n* factorial(--n);//the orinal n-- means use the value of n and then minus 1. Therefore every time the input of funtion factorial is n, which caused the segmental fault.
    else return 1;
    
    
}
