#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   //int largest = arr[root];
   int Largeindex = root;     //defining indexes
   int Lchild = 2*root+1;
   int Rchild = 2*root+2;
   
   if (Lchild < n && arr[Lchild] > arr[Largeindex])
   {
       Largeindex = Lchild;     //finding the largest number's index
   }
   if (Rchild < n && arr[Rchild] > arr[Largeindex])
   {
       Largeindex = Rchild; 
   }
   
   if (root != Largeindex)
   {
       swap(arr[root],arr[Largeindex]);    //swapping 
       heapify(arr,n,Largeindex);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    for (int j = n/2-1 ;j>= 0 ;j--)  
    {
        heapify(arr,n,j);
    }
    
    for (int k = n-1;k>=0;k--)
    {
        swap(arr[0],arr[k]);
        heapify(arr,k,0);
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
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}