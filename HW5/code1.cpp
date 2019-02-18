#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void print(string s);
void reverse(string s);

int main()
{
  ifstream in("input.txt");
  ifstream in1("input.txt");
  string s1;
  string s2[10];
  string temp;
  if(!in)
    {
      cout<<"Error: cannot open file!"<<endl;
    }
  else
    {
      getline(in,s1);
      print(s1);
      reverse(s1);
      
    }
  in.close();
  for(int i=0;i<10;i++)
    {
      in1>>s2[i];
    }
  for(int i=0;i<9;i++)
    {
      for(int j=i+1;j<10;j++)
	{
	  if(s2[i]>s2[j])
	    {
	      temp=s2[i];
	      s2[i]=s2[j];
	      s2[j]=temp;
	    }
	}
    }
  for(int i=0;i<10;i++)
    cout<<s2[i]<<" ";
  
  return 0;
}

void print(string s)
{
  for(int i=0;i<s.length();i++)
    { if(i<s.length()-1)
	 {
	   cout<<s[i];
      
	 }
      else
	{
	  cout<<s[i];
	  cout<<"\n";
	}
    }
}

void reverse(string s)
{
  ofstream out("putput.txt");
  for(int i=s.length();i>=0;i--)
    {
      if(i>0)
	{
	 
	   out<<s[i];

	}
      else
	{
	  out<<s[i];
	  out<<"\n";
	  
	}
    }
  out.close();
}
