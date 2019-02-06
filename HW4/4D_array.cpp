#include<iostream>
using namespace std;

int main()
{ int n;
  cin >> n;
  int ****p=new int ***[n];
  for(int i=0;i<n;i++)
    {
      p[i]=new int **[n];
      for (int j=0;j<n;j++)
	{
	  p[i][j]=new int *[n];
	  for(int k=0;k<n;k++)
	    {
	      p[i][j][k] = new int [n];
	      for(int m=0;m<n;m++)
		{
		  p[i][j][k][m]=m;
		  cout <<" "<< p[i][j][k][m];
		}
	    }
	}
    }
  for( int m=0;m<n;m++)
    for( int k=0;k<n;k++)
      for( int j=0;j<n;j++)
	
	  {
	    delete [] p[j][k][m];
	  }
  delete []p;
}
