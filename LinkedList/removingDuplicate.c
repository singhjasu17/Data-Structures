#include<stdio.h>
#include<stdlib.h>

typedef struct listnode
{
    int val;
    struct listnode* next;

}ListNode;
ListNode *head=NULL;

ListNode * createNode(int a)
{
    ListNode *newNode=(ListNode *)malloc(sizeof(ListNode));
    newNode->val=a;
    newNode->next=NULL;
    return newNode;
}
void addNode(int a)
{
    ListNode* current=createNode(a);
    if(head==NULL)
    {
      head =current;

    }
    else
    {
      ListNode *temp=head;
      while(temp->next!=NULL)
      {

          temp=temp->next;
      }
      temp->next=current;

    }
}

ListNode* deleteDuplicates(ListNode* A) {
    if(A->next==NULL)
    return A;
   ListNode *start=A;
   while(start->next!=NULL && start->val==start->next->val)
   start=start->next;
   if(start->next==NULL)
   return NULL;
    int count=0;
     ListNode *prev,*curr;
     int temp;
     prev=A;
     curr=A->next;
     temp=A->next->val;
     if(temp==A->val)
     count=1;

     while(curr->next!=NULL)
     {
        if(curr->val==curr->next->val)
        {
            count++;
        }
        else
        {
            if(count==0)
            {
                prev->next=curr;
                prev=curr;

            }
            count=0;

        }
        curr=curr->next;
     }
     if(count==0)
     {
         prev->next=curr;
     }
     else
     {
         prev->next=NULL;
     }
     if(A->val==temp)
     {
         A=A->next;

     }

     return A;
}

void printList()
{
    ListNode * temp=head;
    while(temp!=NULL)
    {
        printf(" %d -> ",temp->val);
        temp=temp->next;
    }
}

int main()
{
    int i,j,element;
    printf("Enter no of elements in Linked List");
    scanf("%d",&i);
    for(j=0;j<i;j++)
    {
        scanf("%d",&element);
        addNode(element);
    }
    deleteDuplicates(head);
    printList();


}
