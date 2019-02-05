#include<iostream>
using namespace std;

long long fibonacci_dp(int n);

long long fibonacci_dp(int n)
{
  
  if (n<=1)
    return 0;
  if(n==2)
    return 1;
  else
    {
      int  fb_array[n];
      fb_array[0]=0;
      fb_array[1]=1;
      for(int i=2;i<n;i++)
	{
	  fb_array[i]=fb_array[i-1]+ fb_array[i-2];
	}
      return fb_array[n-1];
      
    }
}

int main()
{
  int n;
  long long r;
  cout << "Input a nonnegative integer: ";
  cin >> n;
  r=fibonacci_dp(n);
  
  cout << "The result is: "<<r<<endl;
}
