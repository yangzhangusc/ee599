#include<iostream>
#include<fstream>
#include<string>

using namespace std;



void print(string s[],int n);
void reverse(string s[], int n);
void order(string s[],int n);
bool  compare(string a,string b);
int main()
{ string s1[10];
  string s;
  int n=0;
  
  ifstream in("input.txt");
 
   for(int i=0;i<10;i++)
    { 
      in>>s1[i];
    }
   for(int i=0;i<10;i++)
     if(s1[i]!="")
       {
	 n=n+1;
       }
   const int  m=n;
   string s2[m];
   for(int i=0;i<m;i++)
     {
       s2[i]=s1[i];
     }
   print(s2,m);
   reverse(s2,m);
   order(s2,m);
   in.close();
   return 0;
   
  
}

void print(string s[],int n)
{
  for(int i=0;i<n;i++)
    {
      if(i<n-1)
	{
	  cout<<s[i]<<" ";
	}
      else
	{
	  cout<<s[i]<<endl;
	}
    }
}
void reverse(string s[],int n)
{ofstream out("out1b.txt");
  for(int i=n-1;i>=0;i--)
    {
      if(i>0)
	{
	  out<<s[i]<<" ";
	}
      else
	{
	  out<<s[i]<<endl;
	}
    }
}
bool  compare(string a,string b)
{

  int a1=int(a.at(0));
  int b1=int(b.at(0));
  if(48<=a.at(0) && a.at(0)<=57)
    a1+=200;
  if(48<=b.at(0) && b.at(0)<=57)
    b1+=200;
  if(65<=a.at(0) && a.at(0)<=90)
    a1+=32;
  if(65<=b.at(0) && b.at(0)<=90)
    b1+=32;

  if( (a1-b1)<0)
    return false;
  else
    return true;
}
void order(string s[],int n)
{ string temp;
  ofstream out("out1c.txt");
  for(int i=0;i<n-1;i++)
    {
    for(int j=i+1;j<n;j++)
      {

	if(compare(s[i],s[j]))
	  {
	    temp=s[i];
	    s[i]=s[j];
	    s[j]=temp;
	  }
	  
      }
    }
  for(int i=0;i<n;i++)
    {
      if(i<n-1)
	{
	  out<<s[i]<<" ";
	}
      else
	{
	  out<<s[i]<<endl;
	}
    }
}
