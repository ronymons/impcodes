#include<stdio.h>
#define MAX 5

int front=-1,rear=-1; int q[MAX]; int opt;

void display();
void insert_rear()
{
    int element;
    if((rear==MAX-1 && front==0) || front==rear+1)
        printf("\nQueue is full");
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d",&element);
        rear =(rear+1)%MAX;
        q[rear]=element;
        if(front==-1)
            front=0;
	display();
    }
}
void insert_front()
{
    int element;
    if((rear==MAX-1 && front==0)||(front==rear+1))
        printf("Queue is full");
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d",&element);
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else if(front==0)
        {
            front=MAX-1;
        }
        else
            front=front-1;
        q[front]=element;   
	display();
    }
}

void delete_front()
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
            front=(front+1)%MAX;
	display();
    }
}
void delete_rear()
{
    int data;
    if(front==-1)
        printf("Deque empty");
    else
    {
        data = q[rear];
        if(front==rear)
        {   
            front=-1;
            rear=-1;
        }
        else if(rear==0)
            rear=MAX-1;
        else
            rear=rear-1;
        printf("The deleted element: %d",data);
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
        printf("\nThe deque elements are: ");
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

int main()
{
    int opt;
    do
    {
        printf("\nWhat would you like to do?");
        printf("\n1.Insert from rear\n2.Insert from front \n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\nEnter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: insert_rear();
                    break;
            
            case 2: insert_front();
                    break;
                    
            case 3: delete_front();
                    break;

            case 4: delete_rear();
                    break;

            case 5: display();
                    break;
            
            case 6: printf("Program Exited");
                    break;
            default: printf("Invalid option");
        }
    } while (opt!=6);
    return 0;
}
