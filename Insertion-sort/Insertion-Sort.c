#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*insertion sort*/
void insertion_sort(int arr[],int n)
{
    int value,hole;
    int i;
    for(i=1;i<n;i++)
    {
        value=arr[i];
        hole=i-1;
        while(hole>=0 && arr[hole]>value)
        {
            arr[hole+1]=arr[hole];
            hole=hole-1;
        }
        arr[hole+1]=value;
    }
}

// main function
int main()
{
  clock_t s1,e1,s2,e2,s3,e3;
  int a[100000], n, i;
  n=2000;
  for (i = 0; i < n; i++)
  {
    a[i]=rand()%100+1;
  }

  s1=clock();
  insertion_sort(a, n);
  e1=clock();
  printf("\nTotal time taken to sort a random array is %f", (double)(e1 - s1) / CLOCKS_PER_SEC);
  
  s2=clock();
  insertion_sort(a, n);
  e2=clock();
  printf("\nTotal time taken to sort a sorted array is %f", (double)(e2 - s2) / CLOCKS_PER_SEC);
  //reverse the array
  for(i=0;i<n/2;i++)
  {
    int temp=a[i];
    a[i]=a[n-i-1];
    a[n-i-1]=temp;
  }
  s3=clock();
  insertion_sort(a, n);
  e3=clock();
  printf("\nTotal time taken to sort a reverse sorted array is %f", (double)(e3 - s3) / CLOCKS_PER_SEC);
  return 0;
}
