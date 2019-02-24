#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void out(string a);

int main(int argc, char *argv[])
{
  string input,output;
  int n;
  input = argv[1];
  output= argv[2];
  cout<<input<<output<<endl;
  out(output);
}

void out(string a)
{ string outfile;
  outfile=a;
  cout<<outfile<<endl;
}
