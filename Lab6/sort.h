#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Sort{
    // always sorts ascending
    private:
  void bubbleSort(int *arr,int n);
  void selectionSort(int *arr, int n);
  void mergeSort(int *arr,int n);
  void quickSort(int *arr,int low,int high);
  int partition(int *arr,int low,int high);
  void radixSort(int *arr, int n);
  void Merge(int *arr,int *Larr,int Ln,int *Rarr, int Rn );
  int getMax(int *arr,int n);
  void countSort(int *arr, int n, int exp);
 string type;
 string in;
 string out;
 int *arr;
 int n;
  
  
  
	
	
        // You may add other stuff here
        // Size of data in unknown in compile time

    public:
        // You may need other stuff here
        // What about a constructor?
        // What about a sort function calling other sort algorithms?
        // If you have dynamic data, don't forget destructor
  Sort( int size,string input,string output, string sort);
  ~Sort();
  void select();
  void save();
	
};



#endif
