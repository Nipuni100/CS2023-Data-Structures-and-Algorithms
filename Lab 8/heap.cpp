#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int l= 2*root+1;
   int r= 2*root+2;

   int largest = root;

   if (l<n && arr[l]> arr[largest]){
      largest= l;
   }
   if (r<n && arr[r]> arr[largest]){
      largest= r;
   }
   if (largest!= root){
      //swap elements

      int temp1= arr[root];
      arr[root]= arr[largest];
      arr[largest]= temp1;

      //arr[root], arr[largest]= arr[largest], arr[root];
      heapify(arr,n,largest);

   }  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
  
   for(int i=(n/2)-1;i>=0;i--){
   heapify(arr,n,i);
}
   
  
   // extracting elements from heap one by one
   for(int i=n-1;i>=0;i--){
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;

      heapify(arr,i,0);
   }
     
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   //int heap_arr[] = {4,17,3,12,9,6,23,45,16,12};
   int n ;
   cout<<"Enter the nunber of elements: ";
   cin>>n;
   cout<<"Input array : "<<endl;

   int arr[n];
   for (int i=0;i<n;i++){
      arr[i]= rand() %100;
   }
   displayArray(arr,n);
  
   heapSort(arr, n);
  
   cout << "Sorted array : "<<endl;
   displayArray(arr, n);
}