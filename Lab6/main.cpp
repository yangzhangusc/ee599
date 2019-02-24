#include "sort.h"

#include<cstring>

int main(int argc, char *argv[])
{
string input,output,sorttype,temp;
  int n;
  
  if(argc<5)
    {
      cout<<"Error: not enough arguments"<<endl;
      return 0;
    }
  else
    {
      input=argv[1];
      output=argv[2];
      temp=argv[3];
      n=atoi(temp.c_str());
      sorttype=argv[4];
      Sort a1(n,input,output,sorttype);
      a1.select();
      a1.save();
     
      
      return 0;
    }
}