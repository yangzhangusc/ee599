#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
  ifstream in("input2.txt");
  string s;
  getline(in,s);
  int k=0;
  cout<<"Type K: ";
  k<<cin;
  int i=0;
for
  
}

int insert(string s,int k)
{ 
  int a=rand()%(s.length())+k;
 
  s.insert(a,";");
  insert(s,a+1);
}
