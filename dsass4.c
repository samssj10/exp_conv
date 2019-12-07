#include<stdio.h>
#include<ctype.h>//for using the function isalnum()
#include "stackhead.h"

int length(char *str)
{
    int i=0;
    while(*str!='\0')
    {
        i++;
        str++;
    }
    return i;
}

void copy(char *str,char *str2)
{
    while(*str!='\0')
    {
        *str2=*str;
        str++;
        str2++;
    }
    *str2='\0';
}

void reverse(char str[])
{
    char str2[100];
    int i=0;
    copy(str,str2);
    int len=length(str);
    for(i=len-1;i>=0;i--)
    {
        str[len-i-1]=str2[i];
    }
    //str2[i]='\0';

}
int icp(int ch)//for precedence of output or in postfix expression
{
    if(ch=='+'||ch=='-')
    return 1;

    if(ch=='*'||ch=='/')
    return 2;

    if(ch=='^')
    return 4;

    if(ch=='(')
    return 5;

    else
    return 0;
}

int isp(int ch)//for precedence of stack
{
    if(ch=='+'||ch=='-')
    return 1;

    if(ch=='*'||ch=='/')
    return 2;

    if(ch=='^')
    return 3;

    else
    return 0;
}

int icpre(int ch) //for icp of prefix
{
     if(ch=='+'||ch=='-')
    return 1;

    if(ch=='*'||ch=='/')
    return 2;

    if(ch=='^')
    return 3;

    if(ch=='(')
    return 5;

    else
    return 0;
}
int ispre(int ch) //for isp of prefix
{
   if(ch=='+'||ch=='-')
    return 1;

    if(ch=='*'||ch=='/')
    return 2;

    if(ch=='^')
    return 4;
    
    else
    return 0;  
}

void in_post (char inexp[100],char postexp[100])
{
    int i=0,k=0;
    char tkn=inexp[i];
    while (tkn!='\0')
    {
        if(isalnum(tkn))
        {
            postexp[k]=inexp[i];
            k++;
        }

        else if(tkn=='(')
        {
            push('(');
        }

        else if(tkn==')')
        {
            while((tkn=pop())!='(')
            {
                postexp[k]=tkn;
                k++;
            }
        }

        else
        {
            while(!isempty() && (isp(stk[top])>=icp(tkn)))
            {
                postexp[k]=pop();
                k++;
               
            }
            push(tkn);
        } 
        i++;
        tkn=inexp[i];
    }

    while(!isempty())
    {
        postexp[k]=pop();
        k++;
    }
    postexp[k]='\0';
     
}

void in_pre (char inexp[100],char postexp[100])
{
    int i=0,k=0;
    char tkn=inexp[i];
    while (tkn!='\0')
    {
        if(isalnum(tkn))
        {
            postexp[k]=inexp[i];
            k++;
        }

        else if(tkn=='(')
        {
            push('(');
        }

        else if(tkn==')')
        {
            while((tkn=pop())!='(')
            {
                postexp[k]=tkn;
                k++;
            }
        }

        else
        {
            while(!isempty() && (isp(stk[top])>=icp(tkn)))
            {
                postexp[k]=pop();
                k++;
               
            }
            push(tkn);
        } 
        i++;
        tkn=inexp[i];
    }

    while(!isempty())
    {
        postexp[k]=pop();
        k++;
    }
    postexp[k]='\0';
     
}

int main()
{   
    char inexp[100];
    printf("enter your expression \n");
    scanf("%s",inexp);
    char postexp[100];
    char prefexp[100];
    int n;
    printf("MENU:\n 1.infix to postfix\n 2.infix to prefix\n");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        in_post(inexp,postexp);
        printf("corresponding postfix expression is %s\n",postexp);
        break;
    
    case 2:
        reverse(inexp);
        printf("reversed string is %s",inexp);
        in_pre(inexp,prefexp);
        reverse(prefexp);
        printf("corresponding prefix expression is : %s\n",prefexp);
        break;
    }
    
    return 0;
}