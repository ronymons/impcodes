#include<stdio.h>
int top=-1,max,stack[100];
void push()
{
    int element;
    if(top==max-1)
        printf("Stack overflow");
    else
    {
        printf("Enter the element to push: ");
        scanf("%d",&element);
        stack[++top]=element;
	
    }
}

void pop()
{
    if(top==-1)
        printf("Stack is empty");
    else
        printf("The popped element: %d",stack[top--]);
}

void peek()
{
    if(top==-1)
        printf("Stack is empty");
    else
        printf("The top element: %d",stack[top]);
}

void isempty()
{
    if(top==-1)
        printf("Stack is empty");
    else
        printf("Stack not empty");
}

void isfull()
{
    if(top==max-1)
        printf("Stack is full");
    else
        printf("Stack not full");
}

void display()
{
    if(top==-1)
        printf("Stack empty");
    else
    {   
        
        int i=top;
        printf("The elements of stack: \n");
        while(i>-1)
        {
            printf("%d ",stack[i--]);
        }
    }
}

int main()
{
    int opt;char opt1;
    printf("Enter the size of stack: ");
    scanf("%d",&max);
    do
    {
        printf("\nWhat would you like to do?");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.isempty\n5.isfull\n6.Display\nEnter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: isempty();
                    break;
            case 5: isfull();
                    break;
            case 6: display();
                    break;
            default: printf("Invalid option");
        }
        printf("\nDo you want to continue?(y/n): ");
        scanf(" %c",&opt1);
    } while (opt1=='y');
    return 0;
}
