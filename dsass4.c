    #include<stdio.h>
    #include<ctype.h>//for using the function isalnum()
    #include<string.h>
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
    }

    void concat(char *str,char *str2)
    {
        while (*str!='\0')
        {
            str++;
        }
        while(*str2!='\0')
        {
            *str=*str2;
            str++;
            str2++;
        }
        *str='\0';
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

            else if(tkn==')')
            {
                push(')');
            }

            else if(tkn=='(')
            {
                while((tkn=pop())!=')')
                {
                    postexp[k]=tkn;
                    k++;
                }
            }

            else
            {
                while(!isempty() && (ispre(stk[top])>=icpre(tkn)))
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

    void post_in(char postexp[100],char newinexp[100]) //test for (a+b)/(c-d) or (a+b)/c
    {
        int l=length(postexp);
        int i;
        char e1[100];
        int j=0;
        int k=0;
        for(i=0;i<l;i++)
        {   
            char x=postexp[i];
            if(isalnum(x))//check if x is operand
            {   
                push(x);
            }
            else // x is operator
            {
                if(i==l-1)
                {
                    if(isalnum(stk[top]))
                    {   
                        newinexp[j]=x;
                        newinexp[j+1]=stk[top];
                        k=j+1;
                    }
                    else
                    {   
                        while(newinexp[j]!='(')
                        {
                            newinexp[j]=newinexp[j-1];
                            j--;
                        }
                        newinexp[j+1]=newinexp[j];
                        newinexp[j]=x;
                    }
                }
                
                else
                {
                char op1=pop();
                char op2=pop();
                newinexp[j]='(';
                newinexp[j+1]=op2;
                newinexp[j+2]=x;
                newinexp[j+3]=op1;
                newinexp[j+4]=')';
                j=j+5;
                k=j;
                }   
            }
        }
        newinexp[k+1]='\0';
    }

    void pre_in(char prefexp[100],char inexp[100])
    {
        //printf("this is the prefix exp :%s\n",inexp);
        int l=length(prefexp);
        int i;
        int j=0; //for traversing infix expression
        for(i=0;i<l;i++)
        {
            char x=prefexp[i];
            if(isalnum(x)) //check if x is operand
            {
                printf("this : %c went to stack \n",x);
                push(x);
            }
            else //x is operator
            {
                char op1=pop();
                printf("pop1 is this : %c\n",op1);
                char op2=pop();
                printf("pop2 is this : %c\n",op2);
                inexp[j]='(';
                inexp[j+1]=op1;
                inexp[j+2]=x;
                inexp[j+3]=op2;
                inexp[j+4]=')';
                j=j+5;
            }
            inexp[j]='\0';
        }
    }

    int main()
    {   
        char inexp[100];
        printf("enter your expression \n");
        scanf("%s",inexp);
        char postexp[100];
        char prefexp[100];
        char newinexp[100];
        char newprefexp[100];
        int n;
        printf("MENU:\n 1.infix to postfix\n 2.infix to prefix\n 3.postfix to infix\n 4.prefix to infix\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            in_post(inexp,postexp);
            printf("corresponding postfix expression is %s\n",postexp);
            break;
        
        case 2:
            reverse(inexp);
            in_pre(inexp,prefexp);
            reverse(prefexp);
            printf("corresponding prefix expression is : %s\n",prefexp);
            break;
        
        case 3:
            in_post(inexp,postexp);
            printf("corresponding postfix expression is %s\n",postexp);
            post_in(postexp,newinexp);
            printf("corresponding infix expression is %s",newinexp);
            break;
        
        case 4:
            printf("enter your prefix expression\n");
            scanf("%s",prefexp);
            reverse(prefexp);
            printf("reversed exp is : %s\n",prefexp);
            pre_in(prefexp,newinexp);
            printf("corresponding prefix expression is %s",newinexp);
            break;
        }
        return 0;
    }
