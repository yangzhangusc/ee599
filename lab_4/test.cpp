#include<iostream>
using namespace std;

 
bool IsSquare(int n)
{
	
	double b=5*n*n-4;
	double c=b+8;
	for(int i=1; b>0; i+=2)  //变化步长为2， 初值为1，一直减到N大于0
	{
		b-=i; 
	}
	
	if(b==0)
		return true;  //如果N减到最后，恰好等于0，就是平方数
	else
	  for(int j=1;c>0;j+=2)
	  {
	    c-=j;
	  }
	  if(c==0)
	  return true;
	  else
		return false;  //否则，就不是平方数
}


int main()
{
  int a=21;
  cout << IsSquare(a);
    
  
}
