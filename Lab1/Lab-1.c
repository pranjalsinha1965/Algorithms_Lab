#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start,end;
double cpu_time_used;
int *arr;
int n;
int randomiser=0;
void generate(int x)
{
 n=x;
 randomiser++;
 srand(n+randomiser);
 free(arr);
 arr=(int*)malloc(n*sizeof(int));
 for(int i=0;i<n;i++)
  *(arr+i)=rand();
}
void ascend()//ascending order
{
 int i=0,j=0,k=0,temp;
 for(i=1;i<n;i++)
 {
  k=*(arr+i);
  j=i;
  while(j>0&&*(arr+j-1)>k)
  {
   temp=*(arr+j);
   *(arr+j)=*(arr+j-1);
   *(arr+j-1)=temp;
   j=j-1;    
  }
 }
}
void descend()// descending order
{
int i=0,j=0,k=0,temp;
 for(i=1;i<n;i++)
 {
  k=*(arr+i);
  j=i;
  while(j>0&&*(arr+j-1)<k)
  {
   temp=*(arr+j);
   *(arr+j)=*(arr+j-1);
   *(arr+j-1)=temp;
   j=j-1;    
  }
 }
}
void bestcase()
{
 ascend();
 start=clock();
 ascend();
 end=clock();
 cpu_time_used=((double)(end-start)/CLOCKS_PER_SEC);
 printf("%lf",cpu_time_used);
}
void worstcase()
{
 descend();
 start=clock();
 ascend();
 end=clock();
 cpu_time_used=((double)(end-start)/CLOCKS_PER_SEC);
 printf("%lf",cpu_time_used);
}
void avgcase()
{
 start=clock();
 ascend();
 end=clock();
 cpu_time_used=((double)(end-start)/CLOCKS_PER_SEC);
 printf("%lf",cpu_time_used);
}
void totalcase()
{
 printf("\nInput\tbest case\tworst case\taverage case\n");
 for(int i=5000;i<=50000;i=i+5000)
 {
  generate(i);
  printf("\n%d",i);
  printf("\t");
  bestcase();
  printf("\t");
  worstcase();
  printf("\t");
  avgcase();
  printf("\n");
 }
}
void display()// display
{
 int i;
 for (i=0;i<n;i++)
  printf("\n%d",*(arr+i));
}
int main()//main function and menu driven part
{
 arr=(int*)malloc(100000000000000*sizeof(int));
 int opt,x;
 printf("\nEnter number of elements:");
 scanf("%d",&x);
 generate(x);
 menu:
 printf("\n1.Generate\n2.Display\n3.Sort ascending\n4.Sort descending\n5.Best case\n6.Worst case\n7.Average case\n8.Total time complexity\n9.exit\nEnter your choice:");
 scanf("%d",&opt);
 switch(opt)
 {
  case 1:
		 printf("\nEnter the number of elements:");
                 scanf("%d",&x);
                 generate(x);
		 break;
  case 2:
		 display();
		 break;
  case 3:
		 ascend();
		 break;
  case 4:
		 descend();
		 break;
  case 5:
		 bestcase();
		 break;
  case 6:
		 worstcase();
		 break;
  case 7:
		 avgcase();
		 break;
  case 8:
		 totalcase();
		 break;
  case 9:
		 return 0;
		 break;
  default:
		  printf("\nWrong option entered");
		  break;
 }
 goto menu;
}
