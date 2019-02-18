#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string>
#include<climits>


using namespace std;
class City {
	
private:
  int x,y,index;
  string CityName;
public:
  City(int a, int b ,int c){
    CityName="CityNo";
    CityName+=to_string(a);
    x=b;
    y=c;
    index=a;
  }
  ~City(){
  }

  string GetName(){
    return CityName;
  }
  int GetX(){
    return x;
  }
  int GetY(){
    return y;
  }
  int GetIndex(){
    return index;
  }
   

        
};
class SimulatedAnnealing {
private:
	double T_start;//intial temperature
	double T_end;//end temperature
        double Tk;
        double beta;
        int num;
	City **cities;//we want you to practice pointer in this lab
        City **temcities;
        
public:
	SimulatedAnnealing() {
		cities = NULL;
		temcities=NULL;
	}
  SimulatedAnnealing(double value1, double value2,double value3,int n, ifstream & infile) {
                int a,b,c;
		T_start = value1;
		T_end = value2;
		Tk=value1;
		beta=value3;
	        num=n;
                cities=new City*[n];
		temcities=new City*[n];
		
                for (int i=0;i<n;i++){
		  infile>>a>>b>>c;
                  cities[i]=new City(a,b,c);
		  temcities[i]=new City(a,b,c);
		  
      
                   }
   
        
	}
	~SimulatedAnnealing() {
		delete[] cities;
		delete[] temcities;
	}

  
  void Print(){
    for(int i=0;i<num;i++)
      { cout<<cities[i]->GetName()<<" "<<cities[i]->GetX()<<" "<<cities[i]->GetY()<<" "<<cities[i]->GetIndex()<<endl;
	}
    for(int i=0;i<num;i++)
      {
	 cout<<temcities[i]->GetName()<<" "<<temcities[i]->GetX()<<" "<<temcities[i]->GetY()<<endl;
      }

    
  }
  void deletearr(City **arr)
  {
    for(int i=0;i<num;i++)
      delete arr[i];
  }
  void swap(City **arr)
  {
    int s1,s2;City *temp;
    s1=rand()%num;
    s2=rand()%num;
    while(s1==s2){
      s2=rand()%num;
    }
    temp=arr[s1];
    arr[s1]=arr[s2];
    arr[s2]=temp;
  }
  int distance(City **arr, int a, int b)
  {
    int x1=arr[a]->GetX();
    int x2=arr[b]->GetX();
    int y1=arr[a]->GetY();
    int y2=arr[b]->GetY();
    return static_cast<int>(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
  }
  int cost(City **arr)
  {
    int cost=0;
    for(int i=0;i<num-1;i++)
      {
        cost+=distance(arr,i,i+1);
      }
    cost+=distance(arr,num-1,0);
    
    return cost;
    
  }
   void CopyCity(City **arr)
      {
	deletearr(cities);
	for(int i=0;i<num;i++)
	  {
	    cities[i]=new City(temcities[i]->GetIndex(),temcities[i]->GetX(),temcities[i]->GetY());
	  }
      }
    double delta(int a,int b)
    {
      return ((b-a)/static_cast<double>(a));
    }
    double P(double delta,double Tk)
    { double x=-(delta/Tk);
      return exp(x);
      
    }
    void begin()
    {
      int iterations=0;
      int  Mindistance=INT_MAX;
      int current_cost;
      double newdelta;
      double totaldelta=0;
int k=0,t=0;
      while(true){
//t=t+1;
	swap(temcities);   
        newdelta=delta(cost(cities),cost(temcities));
	if(newdelta<=0)
	  {
	    Tk=beta * Tk;
	    CopyCity(cities);
	    // cout<<Tk<<endl;
	    
	  }
	else
	  {
	    if(Tk>T_end)
	      {
		if(P(newdelta,Tk)>=((rand()%100)/static_cast<double>(100)))
		  {
		    Tk=beta * Tk;
		    CopyCity(cities);
//totaldelta+=newdelta;
//k=k+1;
		    // cout<<Tk<<endl;
		    
		  }
	      }
	    else
	      {
// cout<<"the average delta is "<< (totaldelta)/(k)<<"the T0 = "<<(-((totaldelta)/(k))/log(0.8))<<endl;
//cout<<"iterations: "<<t<<" cost: "<<Mindistance<<endl;
		break;
	      }
	  }
	
	int currentcost=cost(temcities);
	if(currentcost<Mindistance)
	  {
	    Mindistance=currentcost;
	  }
	else
	  {
	    iterations+=1;
	  }
	if(iterations>50000)
	  {
// cout<<"the average delta is "<< (totaldelta)/(k)<<"the T0 = "<<(-((totaldelta)/(k))/log(0.8))<<endl;
//cout<<"iterations: "<<t<<" cost: "<<Mindistance<<endl;
            break;
	  }
	  
	
	  }
      ofstream output("Lab5_partI_task1_output.txt");
      output<<"Final Distance of SA Method: "<<Mindistance<<endl;
      for(int i=0;i<num;i++)
	{
	  output<<cities[i]->GetIndex()<<endl;
	}
      output.close();
    }
    
  
  
	
};
class Greedy {
private:
	
        int num;
	City **cities;//we want you to practice pointer in this lab
        
public:
	Greedy() {
		cities = NULL;
		
	}
  Greedy(int n,ifstream & infile) {

	        int a,b,c;
	        num=n;
                cities=new City*[n];
		
		
                for (int i=0;i<n;i++){
		  infile>>a>>b>>c;
                  cities[i]=new City(a,b,c);
		  
		  
      
                   }
	}
	~Greedy() {
		delete[] cities;
		
	}
   void Print(){
    for(int i=0;i<num;i++)
      { cout<<cities[i]->GetName()<<" "<<cities[i]->GetX()<<" "<<cities[i]->GetY()<<" "<<cities[i]->GetIndex()<<endl;
	}

    
  }
  void swap(City **arr,int a, int b)
  {
    City *temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
  }
  int distance(City **arr, int a, int b)
  {
    int x1=arr[a]->GetX();
    int x2=arr[b]->GetX();
    int y1=arr[a]->GetY();
    int y2=arr[b]->GetY();
    return static_cast<int>(sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
  }
  int cost(City **arr)
  {
    int cost=0;
    for(int i=0;i<num-1;i++)
      {
        cost+=distance(arr,i,i+1);
      }
    cost+=distance(arr,0,num-1);
    
    return cost;
    
  }


  void begin()
  {
      
     
      int mincost=0;
      
      int id=0;
      for (int i=0;i<num-1;i++)
	{
          int  Mindistance=INT_MAX;
	  for (int j=i+1;j<num;j++)
	    {
	      if(distance(cities,i,j)<Mindistance)
		{
		  Mindistance=distance(cities,i,j);
		  id=j;
		}
	    }
	 
	  swap(cities,i+1,id);
	   
	}
      mincost=cost(cities);
      ofstream output1("Lab5_partI_task2_output.txt");
      output1<<"Final Distance of Greedy Method: "<<mincost<<endl;
      for(int i=0;i<num;i++)
	{
	  output1<<cities[i]->GetIndex()<<endl;
	}
      output1.close();
     
  }

};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));
  ifstream infile("Lab5_partI_input.txt");
  ifstream infile1("Lab5_partI_input.txt");
  
  int num1;
  int num2;
  if(!infile)
    {
      cout << "Error: cannot open txt!"<<endl;
    }
  else
    {
      infile >>num1;
     
      SimulatedAnnealing s1(100,1e-6,0.95,num1,infile);
      s1.begin();
      //s1.Print();
    }
  if(!infile1)
    {
      cout<<"error"<<endl;
    }
  else
    {
       infile1 >>num2;
      Greedy s2(num2,infile1);

      s2.begin();
      //s2.Print();
    }
  infile.close();
  infile1.close();
	return 0;
}
