#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start=NULL,*ptr=NULL;

void display();

void insert_beg()
{
    int val;
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {
        newnode->next=start;
        start=newnode;
    }
    display();
}

void insert_end()
{
    int val;
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newnode;
    }
    display();
}

void insert_specnode()
{
    int val,key;
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    display();
    printf("\nEnter the value of node after which value to be inserted: ");
    scanf("%d",&key);
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {   
        ptr=start;
        while(ptr->data!=key)
            ptr=ptr->next;
        if(ptr->next==NULL)
            ptr->next=newnode;
        else
        {
            newnode->next=ptr->next;
            ptr->next=newnode;
        }    
    }
    display();
}

void delete_beg()
{
    if(start==NULL)
        printf("Linked list is empty");
    else
    {
        ptr=start;
        printf("The deleted element: %d \n",start->data);
        if(start->next==NULL)
            start=NULL;
        else
            start=ptr->next;
        free(ptr);
        display();
    }
}

void delete_end()
{
    if(start==NULL)
        printf("Linked list is empty");
    else
    {
        struct node *preptr=start;
        ptr=start;
        while(ptr->next!=NULL)
        {    
            preptr=ptr;
            ptr=ptr->next;
        }   
        printf("The Deleted element: %d \n",ptr->data);
        if(start->next==NULL)
            start=NULL;
        else
            preptr->next=NULL;
        free(ptr);
        display();
    }
}

void delete_specnode()
{
    int key;
    if(start==NULL)
        printf("Linked list is empty");
    else
    {
        printf("Enter the value to be deleted: ");
        scanf("%d",&key);
        ptr=start;
        if(start->data==key)
        {    
            printf("The deleted element: %d \n",start->data);
            start=ptr->next;
            free(ptr);
        }
        else
        {
            struct node *preptr=start;
            while(ptr->data!=key)
            {   
                preptr=ptr; 
                ptr=ptr->next;
            }   
            printf("The deleted element: %d \n",ptr->data);
            if(ptr->next==NULL)
                preptr->next=NULL;
            else
                preptr->next=ptr->next;
            free(ptr);   
        }
        display();
    }
}   
    
void display()
{
    if(start==NULL)
        printf("Linked list is empty");
    else
    {
        ptr=start;
        printf("The linked list is: ");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

int main()
{
    int opt;
    do
    {
        printf("\n\nWhat would you like to do?");
        printf("\n1.Insert at begining \n2.Insert at end \n3.Insert after a specified node");
        printf("\n4.Delete from begining \n5.Delete from end \n6.Delete a specified node \n7.Display \n8.Exit \nEnter an option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: insert_beg();
                    break;
            case 2: insert_end();
                    break;
            case 3: insert_specnode();
                    break; 
            case 4: delete_beg();
                    break;
            case 5: delete_end();
                    break;
            case 6: delete_specnode();
                    break;
            case 7: display();
                    break;
            case 8: printf("Program Exited");
                    break;
            default: printf("Invalid option");
        }
    }while(opt!=8);    
    return 0;
}
