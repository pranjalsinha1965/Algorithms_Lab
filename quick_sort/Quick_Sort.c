#include<stdio.h> 
#include <stdlib.h>
#include <time.h>

// Function to swap two elements 
void swapElements(int* x, int* y) 
{ 
int temp = *x; 
*x = *y; 
*y = temp; 
}   
// Partition function
int partition (int arr[], int lowIndex, int highIndex) 
{ 
int pivotElement = arr[highIndex];
int i = (lowIndex - 1); 
for (int j = lowIndex; j <= highIndex- 1; j++) 
{ 
if (arr[j] <= pivotElement) 
{ 
i++; 
swapElements(&arr[i], &arr[j]); 
} 
} 
swapElements(&arr[i + 1], &arr[highIndex]); 
return (i + 1); 
}   
// QuickSort Function
void quickSort(int arr[], int lowIndex, int highIndex) 
{ 
if (lowIndex < highIndex) 
{ 
int pivot = partition(arr, lowIndex, highIndex); 
// Separately sort elements before & after partition 
quickSort(arr, lowIndex, pivot - 1); 
quickSort(arr, pivot + 1, highIndex); 
} 
}   
// Function to print array
void printArray(int arr[], int size) 
{ 
int i; 
for (i=0; i < size; i++) 
printf("%d ", arr[i]); 
}   
// Main Function 
int main() 
{ 
    int n;
    
    clock_t s1, e1, s2, e2, s3, e3;

    int arr[1000000], i;
    n=2000;

    for(i=0;i<n;i++)
        {arr[i]=(rand()%100+1);}
        
        s1 = clock();
        quickSort(arr, 0, n-1); 
    e1 = clock();
    
    printf("\n Total time taken to sort is %f", (double)(e1-s1)/CLOCKS_PER_SEC);
    s2=clock();
    quickSort(arr, 0, n-1); 
  e2=clock();
  printf("\nTotal time taken to sort a sorted array is %f\n", (double)(e2 - s2) / CLOCKS_PER_SEC);
  //reverse the array
  for(i=0;i<n/2;i++)
  {
    int temp=arr[i];
    arr[i]=arr[n-i-1];
    arr[n-i-1]=temp;
  }
  s3=clock();
  quickSort(arr, 0, n-1); 
  e3=clock();
  printf("\nTotal time taken to sort a reverse sorted array is %f\n", (double)(e3 - s3) / CLOCKS_PER_SEC);
/*quickSort(arr, 0, n-1); */

return 0; 
}
