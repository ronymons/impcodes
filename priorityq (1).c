#define MAX 5
#include<stdio.h>
struct queue
{
    int data;
    int priority;
}q[MAX],temp;

int front =-1,rear=-1;
void display();

void sort()
{
    int i,j;
    for(i=0;i<rear-front;i++)
        for(j=front;j<rear;j++)
        {
            if(q[j].priority>q[j+1].priority)
            {
                temp=q[j];
                q[j]=q[j+1];
                q[j+1]=temp;
            }
        }
}

void enqueue()
{
    if(rear==MAX-1)
        printf("Queue is full");
    else
    {
        rear++;
        printf("Enter the element: ");
        scanf("%d",&q[rear].data);
        printf("Enter the priority: ");
        scanf("%d",&q[rear].priority);
        if(front==-1)
            front=0;
        sort();
	display();
    }
}
void dequeue()
{
    if(front==-1)
        printf("\nQueue is empty");
    else
    {
        printf("\nDeleted element: %d:%d \n",q[front].data,q[front].priority);
        if(front==rear)
            front =rear=-1;
        else
            front++;
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
        for(i=front;i<=rear;i++)
            printf("%d:%d ",q[i].data,q[i].priority);
    }
}

int main()
{
    int opt;
    do
    {
        printf("\nWhat would you like to do?");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Program Exited");
                    break;
            default: printf("Invalid option");
        }
    } while (opt!=4);
    return 0;
}


