#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("stack is overflow!!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack is underflow!!\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int peek(struct stack* ptr,int i){
    if (ptr->top-i+1<0) 
    {
        printf("this is invalid index\n");
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
   
}
int main()
{
    int x, n, y, choise,ind;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    while (1)
    {
       

        printf("---------------------------------\n");
        printf("1.push the value in stack\n");
        printf("2.pop the in stack\n");
        printf("3.print the value\n");
        printf("4.peek the value\n");
        printf("5.exit\n");
        printf("---------------------------------\n");
        printf("what is your choise : ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("how many values you want enter : ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &x);
                push(sp, x);
            }
            break;

        case 2:
            printf("how many you want to delete in stack\n");
            scanf("%d", &y);
            for (int i = 0; i < y; i++)
            {
                pop(sp);
            }
            break;
        case 3:
            printf("your value are : ");
            for (int i = 0; i <=sp->top; i++)
            {

                printf("%d\t", sp->arr[i]);
            }
            printf("\n");
            break;
        case 4:
        printf("enter the number of you want to be print : ");
        scanf("%d",&ind);
        peek(sp,ind);
         printf("your %d value is %d\n",ind, peek(sp,ind));
         break;
           
        case 5:
         exit(0);
           break;
         
        default:
        printf("error!!\n");
        }
        

        
    } 

    

    return 0;
}
