#include<stdio.h>
#include<stdlib.h>
typedef struct nod
{
    int data;
    struct nod *next;
}node;
node * createNode(int a)
{
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=a;
    newNode->next=NULL;
    return newNode;
}
void addNode(node **head,int a)
{
    node* current=createNode(a);
    if(*head==NULL)
    {
      *head =current;

    }
    else
    {
      node *temp=*head;
      while(temp->next!=NULL)
      {

          temp=temp->next;
      }
      temp->next=current;

    }
}

node* addTwoNumbers(node* A, node* B) {
int carry=0,ans=0;
node *ptr=A,*temp=NULL,*temp2=NULL;
int flag=0;
while(A || B)
{ans=0;
    if(A)
    ans+=A->data;
    if(B)
    ans+=B->data;
    ans+=carry;
    if(ans>=10)
    carry=1;
    else
    carry=0;
    if(A!=NULL)
    {A->data=ans%10;
        if(A->next==NULL)
        {temp=A;flag=1;}
    }
    else if(B!=NULL)
    {
        if(flag==1)
        {
            temp2=B;
            flag=0;
        }
        B->data=ans%10;
    }
    if(A)
    A=A->next;
    if(B)
    B=B->next;

}
if(temp)
temp->next=temp2;

if (carry==1){
    node *new_node=createNode(1);

    if(temp2==NULL)
    {
        temp->next=new_node;
        new_node->next=NULL;

    }
    else
    {
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=new_node;
        new_node->next=NULL;
    }
}
return ptr;
}
void printList(node *temp)
{

    while(temp!=NULL)
    {
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int element,i,count;
    node *A=NULL;
    printf("Enter no of elements to add in first LinkedList");
    scanf("%d",&count);
    for(i=0;i<count;i++)
    {
        scanf("%d",&element);
        addNode(&A,element);
    }
    node *B=NULL;
    printf("Enter no of elements to add in second LinkedList");
    scanf("%d",&count);
    for(i=0;i<count;i++)
    {
        scanf("%d",&element);
        addNode(&B,element);
    }

    printf("Printing element of linked List");
    node *ptr=addTwoNumbers(A,B);
    printList(ptr);


    return 0;
}
