#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
}*top=NULL;

int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(int data)
{
    struct node* newnode;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Stack Overflow"); //malloc() function returns NULL when the requested memory can't be allocated
        exit(1);
    }
    newnode->data=data;
    newnode->link=top;
    top=newnode;
}

int pop()
{
    struct node*temp;
    temp=top;
    if(isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    int val=temp->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}

void print()
{
    struct node*temp;
    temp=top;
    if(isEmpty())
    {
        printf("Stack UnderFlow");
        exit(1);
    }
    printf("The Stack Elements are = ");
    while(temp)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    return top->data;
}

int main()
{
    int choice, data;
    while(1)
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the Top Element\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Please enter your choice = ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the element to be pushed = ");
            scanf("%d",&data);
            push(data);
            break;

        case 2:
            data=pop();
            printf("Deleted Element is %d\n",data);
            break;

        case 3:
            printf("The Topmost Element of the stack is %d\n",peek());
            break;

        case 4:
            print();
            break;

        case 5:
            exit(1);

        default:
            printf("Wrong Choice\n");
            break;
        }
    }
    return 0;
}


