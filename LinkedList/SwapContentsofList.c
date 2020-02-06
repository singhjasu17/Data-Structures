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
node* swapPairs(node* A) {
    node *head=A->next;

    if(A->next==NULL)
    return A;
    else if(A->next->next==NULL)
    {
        A->next->next=A;
        A->next=NULL;
        return head;
    }
    node* curr,*prev,*coming;
    curr=A->next;
    prev=A;
    coming=curr->next;

    while(curr && curr->next!=NULL)
    {
        if(!coming->next)
        prev->next=coming;
        else
        prev->next=coming->next;

        curr->next=prev;
        curr=coming->next;
        prev=coming;
        if(curr && curr->next!=NULL)
        coming=curr->next;

    }
    if(coming && coming->next!=NULL){
    curr->next=coming;
    coming->next=NULL;}
    return head;
}

void printList(node *ptr)
{
    while(ptr!=NULL)
    {
        printf(" %d -> ",ptr->data);
        ptr=ptr->next;
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
    node *ptr=swapPairs(head);
    printf("Printing element of linked List");
    printList(ptr);


    return 0;
}
