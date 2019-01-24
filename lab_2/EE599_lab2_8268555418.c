#include <iostream>
#include <fstream>
#include<stdio.h>
#include<string.h>
#include<time.h>
using namespace std;

void NativeMultiply(int **matrixA,int a1,int a2,int **matrixB, int b1,int b2,int **matrixC,int c1,int c2,int n);

void StrassanMultiply(int **matrixA,int a1,int a2,int **matrixB,int b1,int b2,int **matrixC,int c1,int c2,int n);

int **newarr(int rows,int cols);

void Print(int **array,int row, int col,int n);

int **arrsplit(int **matrix,int rows,int cols,int topindex, int letfindex);

unsigned int nextpowerof2(unsigned int n);

void MatrixAddorSub(int **A,int a1,int a2,int **B,int b1,int b2,int **C,int c1,int c2,int count,bool add);

void deletearr(int **arr,int cols);

void  Writefile(ofstream &output,int **matrixC,int c1,int c2);










int main()
{
  ifstream in; int n; ofstream of1,of2,of3;
  time_t start1,end1,start2,end2;
  int running_time1,running_time2;
  // read input file and create the matrix
  in.open("input.txt");
  if (!in)
      cout << "Error! Cannot open file\n";
  else
  {
      const int Max=512;  
      in >> n;

      // create array
      int **matrixA,**matrixB,**matrixC;
      matrixA=newarr(Max,Max);
     
      matrixB=newarr(Max,Max);
      matrixC=newarr(Max,Max);
  
      for (int i=0;i<n;i++)
    {
      for (int j=0;j<n;j++)
	{
	  in >> matrixA[i][j];
	   
	}
      
    }
  for (int i=0;i<n;i++)
    {
      for (int j=0;j<n;j++)
	{
	  in >> matrixB[i][j];
	  
	}
    }
  // NativeMultiply of metrix and calculate the processing time.
  start1=clock();
  NativeMultiply(matrixA,n,n,matrixB,n,n,matrixC,n,n,n);
  end1=clock();
  running_time1 = (end1-start1)/CLOCKS_PER_SEC*1000;
  // write result to output_p1_m1.txt
  of1.open("output_p1_m1.txt");
  Writefile(of1,matrixC,n,n);
  of1.close();
  
  
  // prepare for StrassanMUltiply,looking for the next number of power of 2 if n is not the power of 2
  int n1=nextpowerof2(n);
  // StrassanMultiply of metrix and calculate the processing time
  start2=clock();
  StrassanMultiply(matrixA,n1,n1,matrixB,n1,n1,matrixC,n1,n1,n1);
  end2=clock();
  running_time2=1000*(end2-start2)/(CLOCKS_PER_SEC);

  // write result to outout_p1_m2.txt
  of2.open("output_p1_m2.txt");
  Writefile(of2,matrixC,n,n);
  of2.close();

  // write processing time to output_p2
  of3.open("output_p2.txt");
  of3 << running_time1 <<" " <<running_time2<<endl;
  of3.close();

  // free array
  deletearr(matrixA,Max);
  deletearr(matrixB,Max);
  deletearr(matrixC,Max);
  
 } 
}

// Native multiply of matrix
void NativeMultiply(int **matrixA,int a1,int a2,int **matrixB, int b1,int b2,int **matrixC,int c1,int c2,int n)
{
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++)
	{
	  matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];   
	}
}

// Add or subtract of matrix, if add is ture, add the two matrix, or do the sub
void MatrixAddorSub(int **A,int a1,int a2,int **B,int b1,int b2,int **C,int c1,int c2,int count,bool add)
{
  for(int i=0;i<count;i++)
    for(int j=0;j<count;j++)
      {
	if(add==true)
	  {
	    C[i][j]=A[i][j]+B[i][j];
	  }
	else
	  {
	    C[i][j]=A[i][j]-B[i][j];
	  }
      }
}

// dynamic create 2d array
int **newarr(int rows,int cols)
{
  int **p=new int *[rows];
  for(int i=0;i<rows;i++)
    {
      p[i]=new int [cols];
      memset(p[i],0,cols*sizeof(int));
    }
  
  return p;
}


// free array
void deletearr(int **arr,int cols)
{
  for(int i=0;i<cols;i++)
    delete []arr[i];
  delete []arr;
}

// split the array to 4 blocks
int **arrsplit(int **matrix,int rows,int cols,int topindex, int leftindex)
{
  int **submatrix=newarr(rows/2,cols/2);
  for(int i=0;i<rows/2;i++)
    for(int j=0;j<cols/2;j++)
      {
	submatrix[i][j]=matrix[topindex+i][leftindex+j];
      }
  return submatrix;
}


// Strassan method of metrix multiply
void StrassanMultiply(int **A,int a1,int a2,int **B,int b1,int b2,int **C,int c1,int c2,int n)
{
  
  if(n==1)
    C[0][0]=A[0][0] * B[0][0];
  else if (n==2)
    {

       NativeMultiply(A,a1,a2,B,b1,b2,C,c1,c2,n);
     
	  
    }
  else
    {
      int **ResultM1, **ResultM2,**ResultM3,**ResultM4,**ResultM5,**ResultM6,**ResultM7;
      ResultM1=newarr(n/2,n/2);
      ResultM2=newarr(n/2,n/2);
      ResultM3=newarr(n/2,n/2);
      ResultM4=newarr(n/2,n/2);
      ResultM5=newarr(n/2,n/2);
      ResultM6=newarr(n/2,n/2);
      ResultM7=newarr(n/2,n/2);
      //split matrix into 4 blocks
      int **A11=arrsplit(A,a1,a2,0,0);
      
      int **A12=arrsplit(A,a1,a2,0,a2/2);
      
      int **A21=arrsplit(A,a1,a2,a1/2,0);
      int **A22=arrsplit(A,a1,a2,a1/2,a2/2);
      int **B11=arrsplit(B,b1,b2,0,0);
      int **B12=arrsplit(B,b1,b2,0,b2/2);
      int **B21=arrsplit(B,b1,b2,b1/2,0);
      int **B22=arrsplit(B,b1,b2,b1/2,b2/2);

      
      //M1=(A11+A22)*(B11+B22)

      int **A11_A22=newarr(n/2,n/2);

      int **B11_B22=newarr(n/2,n/2);
      
      MatrixAddorSub(A11,n/2,n/2,A22,n/2,n/2,A11_A22,n/2,n/2,n/2,true);
      MatrixAddorSub(B11,n/2,n/2,B22,n/2,n/2,B11_B22,n/2,n/2,n/2,true);
      StrassanMultiply(A11_A22,n/2,n/2,B11_B22,n/2,n/2,ResultM1,n/2,n/2,n/2);

      deletearr(A11_A22,n/2);
      deletearr(B11_B22,n/2);

      //M2=(A21+A22)*(B11)

      int **A21_A22=newarr(n/2,n/2);

      MatrixAddorSub(A21,n/2,n/2,A22,n/2,n/2,A21_A22,n/2,n/2,n/2,true);
      StrassanMultiply(A21_A22,n/2,n/2,B11,n/2,n/2,ResultM2,n/2,n/2,n/2);

      deletearr(A21_A22,n/2);

      //M3=A11*(B12-B22)

      int **B12_B22=newarr(n/2,n/2);

      MatrixAddorSub(B12,n/2,n/2,B22,n/2,n/2,B12_B22,n/2,n/2,n/2,false);
      StrassanMultiply(A11,n/2,n/2,B12_B22,n/2,n/2,ResultM3,n/2,n/2,n/2);

      deletearr(B12_B22,n/2);

      //M4=A22*(B21-B11)

      int **B21_B11=newarr(n/2,n/2);
      MatrixAddorSub(B21,n/2,n/2,B11,n/2,n/2,B21_B11,n/2,n/2,n/2,false);
      StrassanMultiply(A22,n/2,n/2,B21_B11,n/2,n/2,ResultM4,n/2,n/2,n/2);

      //M5=(A11+A12)*B22

      int **A11_A12=newarr(n/2,n/2);
      MatrixAddorSub(A11,n/2,n/2,A12,n/2,n/2,A11_A12,n/2,n/2,n/2,true);
      StrassanMultiply(A11_A12,n/2,n/2,B22,n/2,n/2,ResultM5,n/2,n/2,n/2);

      deletearr(A11_A12,n/2);

      //M6=(A21-A11)*(B11+B12)

      int **A21_A11=newarr(n/2,n/2);
      int **B11_B12=newarr(n/2,n/2);

      MatrixAddorSub(A21,n/2,n/2,A11,n/2,n/2,A21_A11,n/2,n/2,n/2,false);
      MatrixAddorSub(B11,n/2,n/2,B12,n/2,n/2,B11_B12,n/2,n/2,n/2,true);
      StrassanMultiply(A21_A11,n/2,n/2,B11_B12,n/2,n/2,ResultM6,n/2,n/2,n/2);

      deletearr(A21_A11,n/2);
      deletearr(B11_B12,n/2);

      //M7=(A12-A22)*(B21+B22)

      int **A12_A22=newarr(n/2,n/2);
      int **B21_B22=newarr(n/2,n/2);

      MatrixAddorSub(A12,n/2,n/2,A22,n/2,n/2,A12_A22,n/2,n/2,n/2,false);
      MatrixAddorSub(B21,n/2,n/2,B22,n/2,n/2,B21_B22,n/2,n/2,n/2,true);
      StrassanMultiply(A12_A22,n/2,n/2,B21_B22,n/2,n/2,ResultM7,n/2,n/2,n/2);

      deletearr(A12_A22,n/2);
      deletearr(B21_B22,n/2);



      //CREATE C11 C12 C21 C22
      
      int **C11=newarr(n/2,n/2);
      int **C12=newarr(n/2,n/2);
      int **C21=newarr(n/2,n/2);
      int **C22=newarr(n/2,n/2);
      
      //C11=M1+M4-M5+M7
      
      int **C11_Temp1=newarr(n/2,n/2);
      int **C11_Temp2=newarr(n/2,n/2);
      MatrixAddorSub(ResultM1,n/2,n/2,ResultM4,n/2,n/2,C11_Temp1,n/2,n/2,n/2,true);
      MatrixAddorSub(C11_Temp1,n/2,n/2,ResultM5,n/2,n/2,C11_Temp2,n/2,n/2,n/2,false);
      MatrixAddorSub(C11_Temp2,n/2,n/2,ResultM7,n/2,n/2,C11,n/2,n/2,n/2,true);

      deletearr(C11_Temp1,n/2);
      deletearr(C11_Temp2,n/2);
      

      //C12=M3+M5

      MatrixAddorSub(ResultM3,n/2,n/2,ResultM5,n/2,n/2,C12,n/2,n/2,n/2,true);
      
      

      //C21=M2+M4

      MatrixAddorSub(ResultM2,n/2,n/2,ResultM4,n/2,n/2,C21,n/2,n/2,n/2,true);
      

      //C22=M1-M2+M3+M6

      int **C22_Temp1=newarr(n/2,n/2);
      int **C22_Temp2=newarr(n/2,n/2);
      MatrixAddorSub(ResultM1,n/2,n/2,ResultM2,n/2,n/2,C22_Temp1,n/2,n/2,n/2,false);
      MatrixAddorSub(C22_Temp1,n/2,n/2,ResultM3,n/2,n/2,C22_Temp2,n/2,n/2,n/2,true);
      MatrixAddorSub(C22_Temp2,n/2,n/2,ResultM6,n/2,n/2,C22,n/2,n/2,n/2,true);


      deletearr(C22_Temp1,n/2);
      deletearr(C22_Temp2,n/2);

      // Construct C
      for (int i=0;i<n/2;i++)
	for(int j=0;j<n/2;j++)
	  {
	    C[i][j]=C11[i][j];
	    C[i][j+n/2]=C12[i][j];
	    C[i+n/2][j]=C21[i][j];
	    C[i+n/2][j+n/2]=C22[i][j];
	  }
      

      // delete array
      deletearr(ResultM1,n/2);
      deletearr(ResultM2,n/2);
      deletearr(ResultM3,n/2);
      deletearr(ResultM4,n/2);
      deletearr(ResultM5,n/2);
      deletearr(ResultM6,n/2);
      deletearr(ResultM7,n/2);
      deletearr(A11,a1/2);
      deletearr(A12,a1/2);
      deletearr(A21,a1/2);
      deletearr(A22,a1/2);
      deletearr(B11,b1/2);
      deletearr(B12,b1/2);
      deletearr(B21,b1/2);
      deletearr(B22,b1/2);
      deletearr(C11,n/2);
      deletearr(C12,n/2);
      deletearr(C21,n/2);
      deletearr(C22,n/2);
      
  
      
      
      
      

      
      
      
      
    }
    
}


// find next power of 2
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

// print metrix for test and debug
void Print(int **array,int row,int col,int n)
{
  for (int i=0;i<n;i++)
    for (int j=0; j<n; j++)
      {
	printf("%d",array[i][j]);
	printf("\n");
      }
}


// write matrix to file
void   Writefile(ofstream &output,int **matrixC,int c1,int c2)
{ 
  for(int i=0;i<c1;i++)
    {
    for(int j=0;j<c2;j++)
      {
	output << matrixC[i][j] <<" ";
      }
    output << "\n";
    }
}
