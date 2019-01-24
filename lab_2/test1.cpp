#include<stdio.h>
using namespace std;

unsigned int nextpowerof2(unsigned int n);
int main()
{
  int n=8;
  n=nextpowerof2(n);
  printf("%d",n);
  getchar();
}

unsigned int nextpowerof2(unsigned int n)
{
 unsigned int p=1;
  if(n&&!(n&(n-1)))
    return n;
  else
    {
      while(p<n)
	{
	  p<<=1;
	}
      return p;
    }
      
}
