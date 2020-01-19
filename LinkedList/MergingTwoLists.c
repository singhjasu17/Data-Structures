#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
    int val;
    struct linkedlist *next;
}ListNode;

ListNode *createNode(int val)
{
    ListNode *node=(ListNode *)malloc(sizeof(ListNode));
    node->val=val;
    node->next=NULL;
    return node;
}

void addNode(ListNode **head,int val)
{
    ListNode *node=createNode(val);
    ListNode *temp=*head;
    if(*head==NULL)
    {
        *head=node;
        return;
    }

    while(temp->next!=NULL)
          {
              temp=temp->next;
          }
            temp->next=node;
}

ListNode* mergeLists(ListNode* A, ListNode* B)
{
    ListNode *head=NULL;

    if(A->val<B->val)
    {
        head=A;
        A=A->next;
    }
    else
    {
        head=B;
        B=B->next;
    }
    ListNode *ptr=head;
    while(A && B)
    {
        if(A->val<B->val)
        {
            ptr->next=A;
            A=A->next;
        }
        else
        {
            ptr->next=B;
            B=B->next;
        }
        ptr=ptr->next;
    }
    if(A)
    {
        ptr->next=A;

    }
    else
    {
        ptr->next=B;
    }
    return head;

}

void printList(ListNode *head)
{


    while(head!=NULL)
    {
        printf("%d",head->val);
        head=head->next;
    }
}

int main()
{
int i,j,k;
printf("Enter no of elements in first Linked List \n");
scanf("%d",&i);
ListNode *headA=NULL;
ListNode *headB=NULL;
for(j=0;j<i;j++)
{
    scanf("%d",&k);
    addNode(&headA,k);
}
printf("\nEnter no of elements in second Linked List \n");
scanf("%d",&i);


for(j=0;j<i;j++)
{
    scanf("%d",&k);
    addNode(&headB,k);
}
ListNode *str=mergeLists(headA,headB);
printList(str);


}
