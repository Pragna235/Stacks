#include<stdio.h>
#define N 5
int stack_arr[N];
int top=-1;

int isFull()
{
    if(top==N-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int data)
{
    if(isFull())
        {
            printf("Stack Overflow");
            return ;
        }
    top=top+1;
    stack_arr[top]=data;

}

int pop()
{
    int value;
    if(isEmpty())
    {
        printf("Stack UnderFlow");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack UnderFlow");
        return;
    }
    return stack_arr[top];
}

void print()
{
    int i;
    if(isEmpty())
    {
        printf("Stack UnderFlow");
        return ;
    }
    for(i=top;i>=0;i--)
    {
        printf("%d\t",stack_arr[i]);
    }
    printf("\n");
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
