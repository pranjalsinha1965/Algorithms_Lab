#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*bubble sort*/
void bubbleSortExample(int arr[], int num){

    int x, y, temp;   

    for(x = 0; x < num - 1; x++){

        for(y = 0; y < num - x - 1; y++){    

            if(arr[y] > arr[y + 1]){

                temp = arr[y];

                arr[y] = arr[y + 1];

                arr[y + 1] = temp;

            }

        }

    }

}
int main()
{
    int n;
    
    clock_t s1, e1, s2, e2, s3, e3;

    int arr[1000000], i;
    n=2000;

    for(i=0;i<n;i++)
        {arr[i]=(rand()%100+1);}
        
        s1 = clock();
    bubbleSortExample(arr,n);
    e1 = clock();
    
    printf("\n Total time taken to sort is %f", (double)(e1-s1)/CLOCKS_PER_SEC);
    s2=clock();
   bubbleSortExample(arr, n);
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
   bubbleSortExample(arr, n);
  e3=clock();
  printf("\nTotal time taken to sort a reverse sorted array is %f\n", (double)(e3 - s3) / CLOCKS_PER_SEC);
}

