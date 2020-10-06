#include<stdio.h>
# define N 10
int queue[N];
int front = -1;
int rear = -1;

void insert(int item)
{
if((front == 0 && rear == N-1) || (front == rear+1))
{
printf("Queue Overflow \n");
return;
}
if(front == -1)
front = rear=0;
else
{
if(rear == N-1)
rear = 0;
else
rear = rear+1;
}
queue[rear] = item ;
}


void deletion()
{
if(front == -1)
{
printf("Queue Underflow\n");
return ;
}
printf("Element deleted from queue is : %dn",queue[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == N-1)
front = 0;
else
front = front+1;
}
}


void display()
{   int i=front;
    if(front== -1 && rear==-1)
    printf(" queue is empty\n");
    
    else
    {
        printf( " queue is: \n");
        while(i!=rear)
        {
            printf("%d\n",queue[i]);
            i=(i+1)%N;
        }
        printf("%d\n", queue[rear]);
    }
}



int main()
{
int choice,item;
do
{
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Quit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Input the element for insertion in queue : ");
scanf("%d", &item);
insert(item);
break;
case 2 :
deletion();
break;
case 3:
display();
break;
case 4:
break;
default:
printf("Wrong choice\n");
}
}while(choice!=4);
return 0;
}