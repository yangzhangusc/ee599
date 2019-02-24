#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void bubbleSort(int *arr,int n);
void mergeSort(int *arr,int n);
void Merge(int *arr,int *Larr,int Ln,int *Rarr, int Rn );
void selectionSort(int *arr,int n);
int getMax(int *arr,int n);
void countSort(int *arr, int n,int exp);
void radixSort(int *arr, int n);
void quickSort(int *arr,int low, int high);
int  partition(int *arr, int low,int high);
int main()
{
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n;
  in>>n;
  int *p=new int[n];
  for(int i=0;i<n;i++)
    {
      in>>p[i];
    }
  //bubbleSort(p,n);
  //mergeSort(p,n);
  //selectionSort(p,n);
  //radixSort(p,n);
  quickSort(p,0,n-1);
  for(int i=0;i<n;i++)
    {
      out<<p[i]<<endl;
    }
  delete p;
  return 0;
}

void bubbleSort(int *arr, int n)
{
  int temp;
  for(int i=0;i<n-1;i++)
   
    {
      for(int j=i;j<n;j++)
	{
	  if(arr[i]>arr[j])
	    {
	      temp=arr[i];
	      arr[i]=arr[j];
	      arr[j]=temp;
	    }
	}
    }
}
void mergeSort(int *arr,int n)
{
  int mid, *R, *L;
  if(n<2)
    {return;}
  else
    {
  mid=n/2;
  R=new int[mid];
  L=new int[n-mid];
  for(int i=0;i<mid;i++)
    {
      L[i]=arr[i];
    }
  for(int i=mid;i<n;i++)
    {
      R[i-mid]=arr[i];
    }
  mergeSort(L,mid);
  mergeSort(R,(n-mid));
  Merge(arr,L,mid,R,n-mid);
    
  delete []L;
  delete []R;
    }
  
}
void Merge(int *arr,int *L,int Ln,int *R, int Rn )
{
  int i,j,k;
 
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;
 
	while(i<Ln && j< Rn) {
		if(L[i]  < R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}
	while(i < Ln) arr[k++] = L[i++];
	while(j < Rn) arr[k++] = R[j++];

}

void selectionSort(int *arr,int n)
{
  int index;int temp;
  for(int i=0;i<n-1;i++)
    {
    index=i;
    for(int j=i+1;j<n;j++)
      {
	if(arr[index]>arr[j])
	  {
	    index=j;
	  }
      }
    if(index!=i)
      {
	temp=arr[i];
	arr[i]=arr[index];
	arr[index]=temp;
      }
    }
  
 
}

int  getMax(int *arr,int n)
{
  int max=arr[0];
  for(int i=0;i<n;i++)
    {
      if (max<arr[i])
	{
	  max=arr[i];
	}
    }
  return max;
 
}

void countSort(int *arr, int n,int exp)
{
  int *output=new int[n];
  int buckets[10]={0};
  for(int i=0;i<n;i++)
    {
      buckets[(arr[i]/exp)%10]++;
    }
  for(int i=1;i<10;i++)
    {
      buckets[i]+=buckets[i-1];
    }
  for(int i=n-1;i>=0;i--)
    {
      output[buckets[ (arr[i]/exp)%10 ] - 1] = arr[i];
      buckets[ (arr[i]/exp)%10 ]--;
    }
  for (int i=0;i<n; i++)
    {
     arr[i] = output[i];
    }
  delete []output;
  
}

void radixSort(int *arr,int n)
{
  int exp;
  int max=getMax(arr,n);
  for(exp=1;max/exp>0;exp*=10)
    {
      countSort(arr,n,exp);
    }
}

int  partition(int *arr, int low,int high)
{
  int pivot = arr[high];
  int i=low-1;
  int temp1,temp2;
  for(int j=low;j<high;j++)
    {
      if(arr[j]<=pivot)
	{
	  i+=1;
	  temp1=arr[i];
	  arr[i]=arr[j];
	  arr[j]=temp1;
	}
    }
  temp2=arr[i+1];
  arr[i+1]=arr[high];
  arr[high]=temp2;
  return i+1;
}

void quickSort(int *arr,int low, int high)
{ int q;
  if(low<high)
    {
      q=partition(arr,low,high);
      quickSort(arr,low,q-1);
      quickSort(arr,q+1,high);
    }
}
