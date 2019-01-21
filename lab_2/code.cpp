#include <iostream>
#include <fstream>
using namespace std;

int **  NativeMultiply(int Aheight, int Awidth, int A[][512],int Bheight,int Bwidth, int B[][512],int n);
int main()
{
  ifstream in; int n,Awidth,Aheight,Bwidth,Bheight,Cwidth,Cheight;
  in.open("in.txt");
  if (!in)
      cout << "Error! Cannot open file\n";
  else
    {
    
  in >> n;
  Awidth=n;
  Aheight=n;
  Bwidth=n;
  Bheight=n;
  Cwidth=n;
  Cheight=n;
  int A[Aheight][Awidth], B[Bheight][Bwidth], C[Cheight][Cwidth];
  for (int i=0;i<Aheight;i++)
    {
      for (int j=0;j<Awidth;j++)
	{
	  in >> A[i][j];
	  
	}
      
    }
  for (int i=0;i<Bheight;i++)
    {
      for (int j=0;j<Bwidth;j++)
	{
	  in >> B[i][j];
	  
	}
    }
  C =NativeMultiply(Aheight,Awidth,*A,Bheight,Bwidth,*B,n); 
  
     for (int i=0;i<Cheight;i++)
    {
      for (int j=0;j<Cwidth;j++)
	{
	  cout << C[i][j];
	  
	}
      
    }
   
 } 
}

int **  NativeMultiply(int Aheight, int Awidth, int A[][512],int Bheight,int Bwidth, int B[][512],int n)
{
  int C[n][n];
  if(n==1)
    C[0][0]=A[0][0] * B[0][0];
  else
    {
      for(int i=0; i<n; i++)
	{
	  for(int j=0; j<n; j++)
	    {
	      for( int k=0; k<n; k++)
		{
		  C[i][j]=A[i][k] * B[k][j];
		}
	    }
	}
    }
  return C;
}
