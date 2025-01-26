#include<stdlib.h>
#include <stdio.h>
#define size 4
struct queue{
    int a[size];
    int front;
    int rear;
}Q;
int prioritycheck(int X){
    int i=0;
    while(Q.a[i]<X && i<=Q.rear)
    i++;
    return i;
}
void enqueue(int X){
    int i,pos;
    if(Q.rear==size-1){
      printf("\n Queue is Full");
      return;
}
if(Q.rear==-1 && Q.front==-1){
    Q.front=Q.rear=0;
    Q.a[Q.rear]=X;
}
else{
    pos=prioritycheck(X);
    Q.rear++;
    for(i=Q.rear;i>=pos;i--)
      Q.a[i]=Q.a[i-1];
    Q.a[pos]=X;
}
}
void dequeue(){
    if(Q.front==-1 && Q.rear==-1){
        printf("\n Queue is Empty");
        return;
    }
    if(Q.front==Q.rear){
        printf("\n Deleted element is %d ",Q.a[Q.front]);
        Q.front=Q.rear=-1;
    }else{
        printf("\n Deleted element is %d ",Q.a[Q.front]);
        Q.front++;
    }
}
void display(){
    if(Q.front==-1 && Q.rear==-1){
        printf("\n Queue is EMPTY");
        return;
    }
    for(int i=Q.front;i<=Q.rear;i++)
      printf("%d ",Q.a[i]);
}

int main() {
    int choice,value;
    Q.front=Q.rear=-1;
    printf("\n MENU \n1.Insert \n 2.Delete \n 3.Display \n4.Exit");
    for(;;){
        printf("\n Enter ur choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\n Enter the value to be inserted");
            scanf("%d",&value);
            enqueue(value);
            break;
        case 2:dequeue();break;
        case 3:display();break;
        case 4:exit(0);
        default:printf("\n Invalid choice");
        }
    }

    return 0;
}
