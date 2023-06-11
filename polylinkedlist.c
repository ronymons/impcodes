#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coeff;
    int expo;
    struct poly* next;
}*start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL,*ptr1,*ptr2;

void display(struct poly*start)
{
    struct poly *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%dx^%d",ptr->coeff,ptr->expo);
        ptr=ptr->next;
        if(ptr!=NULL)
            printf(" + ");
    }  
}

void insert(struct poly *start,int co,int ex,int x)
{
    struct poly *ptr;
    struct poly *newnode= (struct poly*)malloc(sizeof(struct poly));
    newnode->next=NULL;
    newnode->coeff=co;
    newnode->expo=ex;
    if(start==NULL)
    {    
        start=newnode;
        if(x==1)
            start1=start;
        else if(x==2)
            start2=start;
        else if(x==3)
            start3=start;
        else if(x==4)
            start4=start;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        ptr=ptr->next;
        ptr->next=newnode;
    }
}
void add()
{
    ptr1=start1;ptr2=start2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo>ptr2->expo)
        {
            insert(start3,ptr1->coeff,ptr1->expo,3);
            ptr1=ptr1->next;
        }
        else if(ptr1->expo<ptr2->expo)
        {
            insert(start3,ptr2->coeff,ptr2->expo,3);
            ptr2=ptr2->next;
        }
        else if(ptr1->expo==ptr2->expo)
        {
            int sum=ptr1->coeff+ptr2->coeff;
            insert(start3,sum,ptr1->expo,3);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
    }
    while(ptr1!=NULL)
    {
        insert(start3,ptr1->coeff,ptr1->expo,3);
        ptr1=ptr1->next;
    }

    while(ptr2!=NULL)
    {
        insert(start3,ptr2->coeff,ptr2->expo,3);
        ptr2=ptr2->next;
    }
    printf("\nSum polynomial: ");
    display(start3);
}
void delete_specloc(struct poly *start,struct poly*ptr)
{
    struct poly *preptr=start;
    while(preptr->next!=ptr)
        preptr=preptr->next;  
    if(ptr->next==NULL)
        preptr->next=NULL;
    else
        preptr->next=ptr->next;
    free(ptr);  
}   

void multiply()
{
    ptr1=start1;
    while(ptr1!=NULL)
    {
        ptr2=start2;
        while(ptr2!=NULL)
        {
            int co=ptr1->coeff*ptr2->coeff;
            int ex=ptr1->expo+ptr2->expo;
            insert(start4,co,ex,4);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    struct poly *ptr4,*tempptr;
    ptr4=start4;
    while(ptr4!=NULL)
    {   
        tempptr=ptr4->next;
        while(tempptr!=NULL)
        {
            if(ptr4->expo==tempptr->expo)
            {
                ptr4->coeff= ptr4->coeff+tempptr->coeff;
                delete_specloc(start4,tempptr);
            }
            tempptr=tempptr->next;
        }
        ptr4=ptr4->next;
    }
    printf("\nProduct polynomial: ");
    display(start4);
}

int main()
{
    int n1,n2,i,co,ex,opt;
    printf("\nEnter the number of terms of poly 1: ");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter the coeff and expo of term %d: ",i+1);
        scanf("%d%d",&co,&ex);
        insert(start1,co,ex,1);
    }
    printf("\nPolynomial 1: ");
    display(start1);

    printf("\n\nEnter the number of terms of poly 2: ");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter the coeff and expo of term %d: ",i+1);
        scanf("%d%d",&co,&ex);
        insert(start2,co,ex,2);
    }
    printf("\nPolynomial 2: ");
    display(start2);
     
    do
    {
        printf("\n\nWhat would you like to do?");
        printf("\n1.Add\n2.Multiply\n3.Exit\nEnter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: add();
                    break;
            case 2: multiply();
                    break;
            case 3: printf("Program Exited");
                    break;
            default: printf("Invalid option");
        }
    }while (opt!=3);
    return 0;
}

