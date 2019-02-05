#include<iostream>
#include<fstream>
using namespace std;

// test whether it is a Fib number
bool IsFib(int n);
bool IsFib(int n)
{
 long long N=5*n*n-4;
 long long M=N+8;
  for(int i=1;N>0;i+=2)
    {
      N=N-i;
    }
  if(N==0)
    return true;
  else
    {
    for(int j=1;M>0;j+=2)
      {
	M=M-j;
      }
    if(M==0)
      return true;
    else 
     return false;
    }
}

class Pancake
{
 protected:
  int size;
  bool burnt;
 public:
  int Size()
  {
    return size;
  }
  bool Burnt()
  {
    return burnt;
  }
  void initial(ifstream &in)
  {
    char comma;
    in >> size >> comma >> burnt;
  }
  void setSize(int a)
  {
    size=a;
  }
  void setBurnt(bool a)
  {
    burnt=a;
  }
  
  void flip_pancake()
  {
    burnt=!burnt;
  }
};

class PancakePile : public Pancake
{
  protected:
  int z;
  Pancake *p=new Pancake[512];
  
  public:
  void setZ(int a)
  {
    z=a;
  }
  //input pile of z
  void setArray(ifstream &in)
  {
      
    for (int i=0;i<z;i++){
      
      p[i].initial(in);
      
    }
      
         
  }
  void deleteArrat()
  {
    delete []p;
  }
  //sort descendingly
  void pancake_sort_descending()
  {
        Pancake max,temp1,temp2;int id;
   
    for (int m=0;m<z;m++)
      {//look for the max in pile of m
	 max=p[m];
     
	for(int i=m;i<z;i++)
	  
	{ 
	   
          if(max.Size()<=p[i].Size())
	  {
	    max=p[i];
	    id=i;
	  }
	  
	  
       	
        }
	// flip the pancake above max (including max)
       
	 for(int j=id;j<(z-id)/2+id;j++)
	{

	  temp1=p[j];
	  p[j]=p[id+z-1-j];
	  p[id+z-1-j]=temp1;
	}

	 
	 //flip all pancake 
      for(int n=m;n<(z-m)/2+m;n++)
	{
	  
	  temp2=p[n];
	  p[n]=p[m+z-1-n];
	  p[m+z-1-n]=temp2;
	}
      
      
    
	 
       } 
  }
  void pancake_sort_ascending()
  {
       Pancake min,temp1,temp2;int id;
 
    for (int m=0;m<z;m++)
       {  min=p[m];
     
	for(int i=m;i<z;i++)
	  
	{ 
	   
          if(min.Size()>=p[i].Size())
	  {
	    min=p[i];
	    id=i;
	  }
	  
	  
       	
        }
	

	 for(int j=id;j<(z-id)/2+id;j++)
	{
        
	  temp1=p[j];
	  p[j]=p[id+z-1-j];
	  p[id+z-1-j]=temp1;
	}

	 
	 
      for(int n=m;n<(z-m)/2+m;n++)
	{

	  temp2=p[n];
	  p[n]=p[m+z-1-n];
	  p[m+z-1-n]=temp2;
	}
 
      
      
    
	 
       } 
    
  }
 virtual void pancake_sort_descending_burnt_up()
  {
     Pancake max,temp1,temp2;int id;
  
    for (int m=0;m<z;m++)
       {  max=p[m];
     
	for(int i=m;i<z;i++)
	  
	{ 
	   
          if(max.Size()<=p[i].Size())
	  {
	    max=p[i];
	    id=i;
	  }
	  
	  
       	
        }
	//check burnt side and flip if burnt side down
       if(p[id].Burnt()==0)
	{
	  p[id].flip_pancake();
	}
	 for(int j=id;j<(z-id)/2+id;j++)
	{
	  
	  temp1=p[j];
	  p[j]=p[id+z-1-j];
	  p[id+z-1-j]=temp1;
	}

	 
	 
      for(int n=m;n<(z-m)/2+m;n++)
	{
	  temp2=p[n];
	  p[n]=p[m+z-1-n];
	  p[m+z-1-n]=temp2;
	}
   
      
      
    
	 
       } 
  }

  void pancake_sort_ascending_burnt_down()
  {
    Pancake min,temp1,temp2;int id;

    for (int m=0;m<z;m++)
       {  min=p[m];
     
	for(int i=m;i<z;i++)
	  
	{ 
	   
          if(min.Size()>=p[i].Size())
	  {
	    min=p[i];
	    id=i;
	  }
	  
	  
       	
        }
	

       if(p[id].Burnt()==1)
	{
	  p[id].flip_pancake();
	}
	 for(int j=id;j<(z-id)/2+id;j++)
	{
	  
	  temp1=p[j];
	  p[j]=p[id+z-1-j];
	  p[id+z-1-j]=temp1;
	}

	 
	 
      for(int n=m;n<(z-m)/2+m;n++)
	{
	  
	  temp2=p[n];
	  p[n]=p[m+z-1-n];
	  p[m+z-1-n]=temp2;
	}
     
      
      
    
	 
       }  
  }
  void print()
  {for (int i=0;i<z;i++){
    printf("%d ",p[i].Size());
    printf("%d ",p[i].Burnt());
    if(i==z-1)
      cout<<endl;
    }
  }
  void output(ofstream &out)
  {
    for(int i=0;i<z;i++)
      {
	out<<p[i].Size()<<","<<p[i].Burnt()<<" ";
      }
    out << "\n";
  }
  
    
  
  };

class FibPancakePile : public PancakePile
{
public:
  int pancake_decode()
  {
    int i=0;int sum=0;
    if (IsFib(p[i].Size()))// check whether it contains Fib cake, if contains, go on
      // add every odd Fib pancake
      {
	
	do{
	sum+=p[i].Size();
	i+=2;
	
      }while(IsFib(p[i].Size()));
      }
    return sum;
  }
  void pancake_sort_descending_burnt_up()
  {
    Pancake max,temp1,temp2;int count=0,id;
    // put the Fib pancake on the top
     for (int i=0;i<z;i++)
     {
       if(IsFib(p[i].Size()))
	 { count+=1;
	    p[i].flip_pancake();
	   for(int j=0;j<(i)/2;j++)
           { temp1=p[j];
	     p[j]=p[i-j-1];
	     p[i-j-1]=temp1;
	   }
	   for(int k=0;k<(i+1)/2;k++)
	     {
	       temp1=p[k];
	       p[k]=p[i-k];
	       p[i-k]=temp1;
	     }
	   
	 }
     }
     // sort Fib pancake
     for(int m=0;m<count;m++)// find max for count times.
      {
	max=p[0];
	for(int n=0;n<count-m;n++)
	  {
	    if(max.Size()<=p[n].Size())
	      {
		max=p[n];
		id=n;
	      }
	  }
	if(p[id].Burnt()==1)  // flip the top Fib pancake if its burnt side is up
	      {
	        p[id].flip_pancake();
	      }
	
	    for(int f1=0;f1<(id+1)/2;f1++)
	      {
		temp2=p[f1];
		p[f1]=p[id-f1];
		p[id-f1]=temp2;
	      }

	    for(int f2=0;f2<(count-m)/2;f2++)
	      {
		temp2=p[f2];
		p[f2]=p[count-1-m-f2];
		p[count-1-m-f2]=temp2;
	      }
	    
	  }
     // flip the whole Fib pancake to make it descending
      for(int f4=0;f4<count;f4++)
	{
	  p[f4].flip_pancake();
	}
      for(int f3=0;f3<count/2;f3++)
	{
	  
	  temp2=p[f3];
	  p[f3]=p[count-1-f3];
	  p[count-1-f3]=temp2;
	}
       
	  
     
     
  }
};


class MPancakePiles
{
protected:
  int x,y;
  FibPancakePile **q=new FibPancakePile *[512];
  

public:
  void setXY(int a, int b)
  {
    x=a;
    y=b;
    
  }
  void createArray()
  {
    for (int i=0;i<512;i++)
      q[i]=new FibPancakePile[512];
  }
  void deleteXYZArray()
  {
    for(int i=0;i<512;i++)
      delete q[i];
    delete []q;
    
  }
  void setXYZArray(int a,ifstream &in)
  {
      
    for (int i=0;i<x;i++)
      for(int j=0;j<y;j++)
	{ q[i][j].setZ(a);
	  q[i][j].setArray(in);
	  
	}
  }

  void sort_interior()
  {
    for(int i=1;i<x-1;i++)
      for(int j=1;j<y-1;j++)
	{
	  q[i][j].pancake_sort_ascending_burnt_down();
	  
	}
  }
  void sort_exterior()
  { for(int i=0;i<y;i++)
   {
    q[0][i].pancake_sort_descending_burnt_up();
    q[x-1][i].pancake_sort_descending_burnt_up();
   }
    for(int j=1;j<x-1;j++)
      {
	q[j][0].pancake_sort_descending_burnt_up();
	q[j][y-1].pancake_sort_descending_burnt_up();
      }

  }
  // add up Fib pancake of exterior pile
  int addition()
  { int sum=0;
    for(int i=0;i<y;i++)
      {
	sum+=q[0][i].pancake_decode();
	sum+=q[x-1][i].pancake_decode();
      }
    for(int j=1;j<x-1;j++)
      {
	sum+=q[j][0].pancake_decode();
	sum+=q[j][y-1].pancake_decode();
      }
    return sum;
  }
  void printArray()
  {
   for(int i=0;i<x;i++)
    for(int j=0;j<y;j++)
      {
	q[i][j].print();
      }
      
  }
  void outputArray(ofstream &out)
  {
    for(int i=0;i<x;i++)
      for(int j=0;j<y;j++)
	{
	  q[i][j].output(out);
	}
  }
  };


int main()
{
  int x,y,z,code;
  MPancakePiles mpancakePile;
  // create Pancake
  ifstream in("input.txt");
  ofstream out("output.txt");
  if(!in)
    cout << "Error! Cannot open the file\n";
  else
    {
      in >>x >> y >>z;
      mpancakePile.createArray();
      mpancakePile.setXY(x,y);
      mpancakePile.setXYZArray(z,in);
     
    }
  //sorting
    mpancakePile.sort_exterior();
    mpancakePile.sort_interior();
    // decode
    
    code=(mpancakePile.addition()) % 512;
    cout << code <<endl;
    // output txt 
    out<<x<<" "<<y<<" "<<z<<"\n";
    mpancakePile.outputArray(out);
    mpancakePile.deleteXYZArray();
    in.close();
    out.close();
    
  


     
}
