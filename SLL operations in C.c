#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*last,*n,*temp,*prev;
void create();
void display();
void insertbeg();
void insertend();
void insertafter();
void insertbefore();
void delbeg();
void delend();
void del();
int ch;
int main()
{
    printf("\n1.Create\n2.Display\n3.Insert begin\n4.Insert end\n5.Insert after\n6.Insert before\n7.del beg\n8.del end\n9.del\n");
    do
    {
        printf("\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();break;
            case 2: display();break;
            case 3: insertbegin();break;
            case 4: insertend();break;
            case 5: insertafter();break;
            case 6: insertbefore();break;
            case 7: delbeg();break;
            case 8: delend();break;
            case 9: del();break;
        }
    }while(ch<=9);
}
void create()
{
n=(struct node*)malloc(sizeof(struct node));
printf("Enter data\n");
scanf("%d",&n->data);
n->next=NULL;

if(head==NULL)
{
    head=n;
    last=n;
}
else
   {
    last->next=n;
    last=n;
   }
}
void display()
{
temp=head;
while(temp!=NULL)
{
    printf("%d->",temp->data);
    temp=temp->next;
}
}
void insertbegin()
{
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;

    n->next=head;
    head=n;
}
void insertend()
{
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;

    last->next=n;
    last=n;
}
void insertafter()
{
    int key;
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;

    printf("Enter the value after which you want to inert\n");
    scanf("%d",&key);

    temp=head;
    while(temp!=head)
    {
        if(temp->data==key)
            break;
        else
            temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
void insertbefore()
{
    int key;
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&n->data);
    n->next=NULL;

    printf("Enter the value after which you want to inert\n");
    scanf("%d",&key);

     temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
            break;
        else
            prev=temp;
            temp=temp->next;
    }
    n->next=temp;
    prev->next=n;
}
void delbeg()
{
    temp=head;
    head=head->next;
    free(temp);
}
void delend()
{
    temp=head;
    while(temp!=last)
    {
        prev=temp;
       temp=temp->next;
    }
    last=prev;
    last->next=NULL;
    free(temp);
}
void del()
{
    int key;
    printf("Enter data to remove\n");
    scanf("%d",&key);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
            break;
        else
        {
            prev=temp;
            temp=temp->next;
            free(temp);
        }
    }
}


