#include<iostream>
using namespace std;
long long  fibonacci_recursive(int n);
long long  fibonacci_recursive(int n)
{ 
  if (n<=1)
    {
      return 0;
    }
  if (n==2)
    {
      return 1;
    }
  else
    {
      return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
    }
  
}

int main()
{int n;long long r;
  cout << "input an nonnegative integer N : ";
  cin >> n;
  r= fibonacci_recursive(n);
  cout << "The Nth is: "<<r<<endl;
  
}
