#include<stdio.h>
void swap(int *arr,int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void heapify(int *arr,int i)
{
    int j;
    for(j=1;j<i;j++)
    {
     int root=(j-1)/2;
     int s=j;
     while(arr[root]<arr[s] && root>=0)
     {
         swap(arr,root,s);
         s=root;
         root=(s-1)/2;

      }
   }
}
void print(int arr[],int j)
{
int i;
for(i=0;i<j;i++)
{
    printf("%d ",arr[i]);
}

}
int main()
{
    int i,j,k;
    printf("Enter no of elements in array\n");
    scanf("%d",&i);
    int heap[i];
    for(j=0;j<i;j++)
    {
        scanf("%d",&heap[j]);
    }

    for(j=0;j<i;j++)
    {
       heapify(heap,i-j);
       swap(heap,i-1-j,0);
    }
  printf("Printing array>>");

    print(heap,i);

}
