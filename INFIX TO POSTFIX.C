#include <stdio.h>
#include <string.h>
#include<ctype.h>
char stack[50];
int i=0;j=0;top=-1;
char inf[50],post[50];
void push(int y);
int pop();
int prec(char c);
void postfix(char inf[50]);

int main()
{
   printf("Enter infix expression\n");
   gets(inf);
   postfix(inf);
   printf("Postfix expression is\n");
   puts(post);
}
void postfix(char inf[50])
{
    char x;
    for(i=0;inf[i]!='\0';i++)
    {
        if(inf[i]=='(')
            push(inf[i]);
        else if(isalpha(inf[i]))
            post[j++]=inf[i];
        else if(inf[i]==')')
        {
            while(stack[top]!='(')
                  post[j++]=pop();
                  x=pop();
        }
        else
        {
            while(prec(stack[top])>=prec(inf[i]))
            post[j++]=pop();
            push(inf[i]);
        }
    }
    while(top!=-1)
    {
        post[j++]=pop();
        post[j]='\0';
    }
}
void push(int y)
{
    stack[++top]=y;
}
int pop()
{
    return (stack[top--]);
}
int prec(char c)
{
    if(c=='*'||c=='/'||c=='%')
        return 5;
    else if(c=='+'||c=='-')
        return 3;
    else if(c=='(')
            return 1;
}
