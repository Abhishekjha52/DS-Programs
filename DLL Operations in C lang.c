#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*last,*n,*temp,*prev1;
void create();
void displayforward();
void displaybackward();
void insertbegin();
void insertend();
void insertafter();
void insertbefore();
void delbegin();
void delend();
void del();
int ch;
int main()
{
    printf("\n1.create\n2.displayforward\n3.displaybackward\n4.insertbegin\n5.insertend\n6.insertafter\n7.insertbefore\n8.delbegin\n9.delend\n10.del\n");
    do
    {
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();break;
            case 2: displayforward();break;
            case 3: displaybackward();break;
            case 4: insertbegin();break;
            case 5: insertend();break;
            case 6: insertafter();break;
            case 7: insertbefore();break;
            case 8: delbegin();break;
            case 9: delend();break;
            case 10: del();break;

        }
    }while(ch<=10);
}
void create()
{
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;
    n->prev=NULL;

if(head==NULL)
{
    head=n;
    last=n;
}
else
{
    last->next=n;
    n->prev=last;
    last=n;
}
}
void displayforward()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
void displaybackward()
{
    temp=last;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->prev;
    }
}
void insertbegin()
{
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;
    n->prev=NULL;

    n->next=head;
    head->prev=n;
    head=n;
}
void insertend()
{
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;
    n->prev=NULL;

    last->next=n;
    n->prev=last;
    last=n;
}
void insertafter()
{
    int key;
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;
    n->prev=NULL;

    printf("Enter the node after which you want to insert\n");
    scanf("%d",&key);

    temp=head;
    while(temp!=NULL)
    {
       if(temp->data==key)
            break;
       else{
        temp=temp->next;
       }
    }
    n->next=temp->next;
    (temp->next)->prev=n;
    temp->next=n;
    n->prev=temp;
}
void insertbefore()
{
    int key;
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;
    n->prev=NULL;

    printf("Enter the node before which you want to insert\n");
    scanf("%d",&key);

    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
            break;
        else
        {
            prev1=temp;
            temp=temp->next;
        }
    }
    n->next=temp;
    temp->prev=n;
    prev1->next=n;
    n->prev=prev1;
}
void delbegin()
{
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void delend()
{
    temp=last;
    last=last->prev;
    last->next=NULL;
    free(temp);
}
void del()
{
    int key;

    printf("Enter the node you want to delete\n");
    scanf("%d",&key);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
            break;
            else{
                prev1=temp;
                temp=temp->next;
            }
    }
    prev1->next=temp->next;
    (temp->next)->prev=prev1;
    free(temp);
}
