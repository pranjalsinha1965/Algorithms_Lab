#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// selection sort function
void selection_sort(int a[], int n)
{
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (a[j] < a[min])
      {
        min = j;
      }
    }
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
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
  selection_sort(a, n);
  e1=clock();
  printf("\nTotal time taken to sort a random array is %f\n", (double)(e1 - s1) / CLOCKS_PER_SEC);
  
  s2=clock();
  selection_sort(a, n);
  e2=clock();
  printf("\nTotal time taken to sort a sorted array is %f\n", (double)(e2 - s2) / CLOCKS_PER_SEC);
  //reverse the array
  for(i=0;i<n/2;i++)
  {
    int temp=a[i];
    a[i]=a[n-i-1];
    a[n-i-1]=temp;
  }
  s3=clock();
  selection_sort(a, n);
  e3=clock();
  printf("\nTotal time taken to sort a reverse sorted array is %f\n", (double)(e3 - s3) / CLOCKS_PER_SEC);
  return 0;
}
