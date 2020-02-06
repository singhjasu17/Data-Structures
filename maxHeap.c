#include <stdio.h>
// maxheap
// parent = n/2
// leftchild = 2*i+1
// rightChild = 2*i + 2;
int heapSize;
int heap[100];
void swap(int a,int b)
{
    int temp=heap[a];
    heap[a]=heap[b];
    heap[b]=temp;
}
void swim(int index)
{
    if(index<=0 || index>heapSize)
    {
        return;
    }
    int parent=index/2;
    if(heap[parent]<heap[index])
    {
        swap(parent,index);
    }
    swim(parent);
}
void insert(int a)
{
  heap[heapSize]=a;
  swim(heapSize);
  heapSize++;
}
void printlist()
{int i;
    for(i=0;i<heapSize;i++)
    {
        printf("%d ",heap[i]);
    }
}
void sink(int index)
{
    if(index<=0 || index>heapSize)
    {
        return;
    }
    int leftChild=2*index+1;
    int rightChild=2*index+2;
    int current=index;
    if(leftChild<heapSize && heap[leftChild]>heap[index])
    {
           index=leftChild;
    }
    if(rightChild<heapSize && heap[rightChild]>heap[index])
    {
        index=rightChild;
    }
    if(index!=current)
    {
        swap(index,current);
        sink(current);
    }

}
void delete()
{
    if(heapSize==0)
        return;
    swap(heapSize-1,0);
    heapSize--;
    sink(0);

}
int main()
{
    int i,j,k;
    heapSize=0;
    printf("Enter No of Elements to enter\n");
    scanf("%d",&j);
    for(i=0;i<j;i++)
       {
           scanf("%d",&k);
           insert(k);
       }

    printlist();
}
