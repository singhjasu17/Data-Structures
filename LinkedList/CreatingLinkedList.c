#include<stdio.h>
#include<stdlib.h>
typedef struct nod
{
    int data;
    struct nod *next;
}node;
node *head =NULL;
node * createNode(int a)
{
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=a;
    newNode->next=NULL;
    return newNode;
}
void addNode(int a)
{
    node* current=createNode(a);
    if(head==NULL)
    {
      head =current;

    }
    else
    {
      node *temp=head;
      while(temp->next!=NULL)
      {

          temp=temp->next;
      }
      temp->next=current;

    }
}
void printList()
{
    node * temp=head;
    while(temp!=NULL)
    {
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int element,i,count;
    printf("Enter no of elements to add in LinkedList");
    scanf("%d",&count);
    for(i=0;i<count;i++)
    {
        scanf("%d",&element);
        addNode(element);
    }
    printf("Printing element of linked List");
    printList();


    return 0;
}
