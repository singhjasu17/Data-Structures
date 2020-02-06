#include<stdio.h>
int heap[10000],heapSize=0;
void swap(int a,int b)
{
    int c=heap[a];
    heap[a]=heap[b];
    heap[b]=c;
}
void heapifyUp(int index)
{
    int parentIndex=(index-1)/2;
    if(parentIndex<0 || heap[parentIndex]<heap[index])
        return;
        if(heap[parentIndex]>heap[index])
        {


        swap(parentIndex,index);
        heapifyUp(parentIndex);
        }
}
void heapifyDown(int index)
{
    if(index >= heapSize-1)
        return;
    int left=2*index+1;
    int right=2*index+2;
    int current=index;
    if(left < heapSize && heap[left]<heap[index])
    {
        current=left;
    }
    if(right < heapSize && heap[right]<heap[index])
    {
        current=right;
    }
    if(current!=index)
    {
        swap(current,index);
        heapifyDown(current);

    }
}

void insert(int a)
{
    heap[heapSize]=a;
    heapifyUp(heapSize);
    heapSize++;
}
void delete_min()
{
    int min=heap[0];
    swap(0,heapSize-1);
    heapSize--;
    heapifyDown(0);
}
void printheap()
{
    int i=0;
    for(i=0;i<heapSize;i++)
    {
        printf("%d ",heap[i]);
    }
}
int main()
{
    heapSize=0;
    int a,i,element;
    printf("Enter no of elements\n");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&element);
        insert(element);
    }
    printf("Printing List");
    printheap();
}
