#include<iostream>

using namespace std;

int main()
{
  int x,y;
  cout << "Enter X: ";
  cin >>x;
  cout << "Enter Y: ";
  cin >>y;
  int *sum=new int[y];
  int leftX=x;
  int i=1;
  int j=1;
  
  do 
   {
     if (leftX<=(i+j-1))
       {
	 sum[j-1]+=leftX;
	 break;
       }
     else
       {
	 sum[j-1]+=i+j-1;
       }
     leftX=leftX-(i+j-1);
     if (j<y)
       {
       j+=1;
       }
     else
       {
	 j=1;
	 i+=1;
       }
   }while (j<=y);
  for (int k=0;k<y;k++)
    {
    cout << sum[k] <<"\n";
    }
  delete []sum;

return 0;
}