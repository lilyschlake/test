// Recall: In terminal window: c++ filename.cpp, ./a.out
// CSC-340
// Lily Schlake, 3/18/2021

//One-based array A = <13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11>
//After quicksort array A = <2, 4, 5, 6, 7, 8, 9, 11, 12, 13, 19, 21>

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
* print_one_based(v)
*  takes integer vector v as a const reference parameter
*  Prints the contents of vector v AFTER the initial unused position
*  v is not modified
*/

void print_one_based(const vector<int> v){
   cout << "<";
  int len = v.size();
  if (len > 0) {
    for (int i = 1; i < len-1; i++)
      cout << v[i] << ","; // Comma after elements
    cout << v[len - 1]; // No comma after last element
  }
  cout << ">\n";
}

/*
* partition(A, p, r)
*    takes integer vector A as a reference parameter
*    subarray A[p..r] is the vector to partition into 3 (possibly empty) regions:
*  A[p..q-1] elements <= A[q]
*  A[q] = pivot
*  A[q+1..r] elements > A[q]
*    return q, the index of the pivot
*    A IS modified
*/

int partition(vector<int>& A, int p, int r){
  int x = A[r];
  int i = p - 1;
  for (int j = p; j <= r - 1; j++){
    if (A[j] <= x){
      i = i + 1;
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  int temp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = temp;
  return i + 1;
}

/*
* quicksort(A, p, r)
*  takes integer vector A as a reference parameter
*    subarray A[p..r] is the vector to sort
*    A IS modified
*/

int quicksort(vector<int>& A, int p, int r){
  if (p < r){
    int q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
  return 0;
}

//main function

int main(){
  vector<int> A{-1000, 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
  cout << "One-based array A = ";
  print_one_based(A);
    cout << endl;
  
  cout << "After quicksort array A = ";
  quicksort(A, 1, 11);
  print_one_based(A);
  return 0;
}
