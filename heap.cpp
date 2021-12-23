// heap.cpp
// Diba Mirza
//sources: Zybooks
#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  PercolateUp(vdata.size() - 1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(vdata.size() == 0){
    cout << "Error! Nothing to pop!";
    return;
  }
  if(vdata.size() == 1){
    vdata.erase(vdata.begin());
    return;
  }
  int replaceVal = vdata[vdata.size() - 1];
  vdata[0] = replaceVal;
  vdata.pop_back();
  PercolateDown(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  if(vdata.size() == 0){
    return -1;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.size() == 0){
    return true;
  }
  return false;
}
    
void Heap::PercolateUp(int nodeIndex){
  while(nodeIndex > 0){
    int parentIndex = (nodeIndex - 1)/2;
    if(vdata[nodeIndex] >= vdata[parentIndex]){
      return;
    }
    else{
      int temp = vdata[nodeIndex];
      vdata[nodeIndex] = vdata[parentIndex];
      vdata[parentIndex] = temp;
      nodeIndex = parentIndex;
    }
  }
}

void Heap::PercolateDown(int nodeIndex){
  int childIndex1 = 2 * nodeIndex + 1;
  //int childIndex2 = 2 * nodeIndex + 2;
  int value = vdata[nodeIndex];

  while(childIndex1 < vdata.size()){
    int minVal = value;
    int minIndex = -1;
    int i = 0;
    while (i < 2 && i + childIndex1 < vdata.size()) {
      if (vdata[i + childIndex1] < minVal){
        minVal = vdata[i + childIndex1];
        minIndex = i + childIndex1;
      }
      i++;
    }
    if(minVal == value){
      return;
    }
    else{
      int temp = vdata[nodeIndex];
      vdata[nodeIndex] = vdata[minIndex];
      vdata[minIndex] = temp;
      nodeIndex = minIndex;
      childIndex1 = 2 * nodeIndex + 1;
    }
  }
}