#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
char str[100];
char stack[100],postexpr[100],evalstack[100];
int top =-1,top1=-1;

void push(char c)
{
    stack[++top]=c;
}

char pop()
{
    return stack[top--];  
}

int precedence(char c)
{
    if(c=='+'||c=='-')
        return 1;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='^')
	return 3;
    else
        return 0;
}

void evalpush(int n)
{
    evalstack[++top1]=n;
}

int evalpop()
{
    return evalstack[top1--];
}

void infixtopost()
{
    int i=0,k=0;
    while(str[i]!='\0')
    {
        if(isalnum(str[i])!=0)
        { 
            postexpr[k]=str[i];
            k++;
        }
        else if((precedence(str[i])>precedence(stack[top]))||str[i]=='(')
        {    
            push(str[i]);
        }
            
        else if(str[i]==')')
        {
            while(stack[top]!='(')
            {
                postexpr[k]=pop();
                k++;
            }
            top--;
        }
        else
        {
            while(precedence(str[i])<=precedence(stack[top]))
            {
                postexpr[k]=pop();
                k++;
            }
            push(str[i]);
        }
        i++;
    }
    postexpr[k]='\0';
    
}

void evaluatepost()
{
    int i=0,no1,no2;
    while(postexpr[i]!='\0')
    {
        if(isdigit(postexpr[i])!=0)
        {
            int n=postexpr[i]-48;
            evalpush(n);
        } 
        else if(postexpr[i]=='+')
        {
            no1=evalpop();
            no2=evalpop();
            evalpush(no2+no1);
        }  
        else if(postexpr[i]=='-')
        {
            no1=evalpop();
            no2=evalpop();
            evalpush(no2-no1);
        }
        else if(postexpr[i]=='*')
        {
            no1=evalpop();
            no2=evalpop();
            evalpush(no2*no1);
        }
        else if(postexpr[i]=='/')
        {
            no1=evalpop();
            no2=evalpop();
            evalpush(no2/no1);
        }
        else if(postexpr[i]=='^')
        {
            no1=evalpop();
            no2=evalpop();
            evalpush(pow(no2,no1));
        }
        i++;
    }
}
int main()
{
    int opt;
    char opt1;
    printf("Enter an infix expression: ");
    scanf("%s",str);
    int l=strlen(str);
    push('(');
    str[l]=')';
    str[l+1]='\0';
    infixtopost();
    do
    {
        printf("\nWhat would you like to do?");
        printf("\n1.Convert to postfix\n2.Evaluate\nEnter option:");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("\nThe postfix expression is: %s",postexpr);
                    break;
            case 2: evaluatepost();
                    printf("\nThe evaluated result: %d",evalstack[top1]);
                    break;
            default:printf("Invalid option");
        }
        printf("\nDo you like to continue?(y/n)");
        scanf(" %c",&opt1);
    } while (opt1=='y');
    return 0;
}
