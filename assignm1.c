#include<stdio.h>
 void main()
{
int arr[100];
int *p,i;
p=arr;
for(i=0;i<100;i++)
{
printf("array form arr[%d]= %d\t pointer %p value %d\n",i,arr[i],p,*p);
*p+=5;

printf("array after inc by 5 arr[%d]= %d\t pointer %p value %d\n",i,arr[i],p,*p);
p++;
}





}
