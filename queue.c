#include<stdio.h>
#define MAX 5

int front=-1,rear=-1; int q[MAX]; int opt;

void display();
void linear_insert()
{
    int element;
    if(rear==MAX-1)
        printf("\nQueue is full");
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d",&element);
        q[++rear]=element;
        if(front==-1)
            front=0;
	display();
    }
}

void linear_delete()
{
    if(front==-1)
        printf("\nQueue is empty");
    else
    {
        int data=q[front];
        printf("\nDeleted element: %d \n",data);
        if(front==rear)
            front =rear=-1;
        else
            front++;
	display();
    }
}

void circ_insert()
{
    int element;
    if((rear==MAX-1 && front==0)||(front==rear+1))
        printf("\nCircular queue is full \n");
    else
    {
        printf("Enter the element to be inserted: ");
        scanf("%d",&element);
        rear=(rear+1)%MAX;
        q[rear]=element;
        if(front==-1)
            front=0;
	display();
    }
}

void circ_delete()
{
    int data;
    if(front==-1)
        printf("\nCircular queue is empty");
    else
    {
        if(front==rear)
        {
            data=q[front];
            front=rear=-1;
        }
        else
        {
            data=q[front];
            front=(front+1)%MAX;
        }
        printf("\nDeleted element: %d \n",data);
	display();
    }
}

void display()
{   
    int i;
    if(front==-1)
        printf("\nQueue is empty");
    else
    {
        printf("\nThe queue elements are: ");
        if(opt==1)
        {   
            for(i=front;i<=rear;i++)
                printf("%d ",q[i]);
        }
        else
        {   
            i=front;
            if(front<=rear)
                while(i<=rear)
                {
                    printf("%d ",q[i]);
                    i++;
                }
            else
            {
                while(i<=MAX-1)
                {
                    printf("%d ",q[i]);
                    i++;
                }
                i = 0;
                while(i<=rear)
                {
                    printf("%d ",q[i]);
                    i++;
                }
            }
        }    
    }
}

void isempty()
{
    if(front==-1)
        printf("\nQueue is empty");
    else
        printf("\nQueue not empty");
}

void isfull()
{
    if(opt==1)
    {
        if(rear==MAX-1)
            printf("\nQueue is full");
        else
            printf("\nQueue not full");
    }
    else
    {
        if((rear==MAX-1 && front==0)||(front==rear+1))
            printf("\nCircular queue is full");
        else
            printf("\nCircular queue not full");
    }
}

int main()
{
    int opt1;
    printf("Which queue?\n1.Linear Queue 2.Circular queue\nEnter option: ");
    scanf("%d",&opt);
    do
    {
        printf("\nWhat would you like to do?");
        printf("\n1.Insert\n2.Delete\n3.isempty\n4.isfull\n5.Display\n6.Exit\nEnter option: ");
        scanf("%d",&opt1);
        switch(opt1)
        {
            case 1: if(opt==1)
                        linear_insert();
                    else    
                        circ_insert();
                    break;
            
            case 2: if(opt==1)
                        linear_delete();
                    else    
                        circ_delete();
                    break;
                    
            case 3: isempty();
                    break;

            case 4: isfull();
                    break;

            case 5: display();
                    break;
            
            case 6: printf("Program Exited");
                    break;
            default: printf("Invalid option");
        }
    } while (opt1!=6);
    return 0;
}
