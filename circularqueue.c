#include <stdio.h>
#include<stdlib.h>
int size;
struct queue{
    int front;
    int rear;
    int *queue;
}   Q;

void enqueue(int val);
void dequeue();
void display();

void enqueue(int val){
    if((Q.rear+1)%size==Q.front){
        printf("Queue is full,so reallocating the memory");
        size++;
        Q.queue=(int *)realloc(Q.queue,size*sizeof(int));
        
        
    }
    if(Q.front==-1){
        Q.front=0;
    }
    Q.rear=(Q.rear+1)%size;
    *(Q.queue+Q.rear)=val;
}
void dequeue(){
    if(Q.front==-1 && Q.rear==-1){
        printf("\n Queue is empty");
        return;
    }
    if(Q.front==Q.rear)
      {
          Q.front=Q.rear=-1;
          return;
      }
      printf("\n Deleted element is %d",*(Q.queue+Q.front));
      Q.front=(Q.front+1)%size;
      return;
    
    
}
void display(){
    if(Q.front==-1 && Q.rear==-1){
        printf("\n Queue is empty");
        return;
    }
    if(Q.front<Q.rear){
        for(int i=Q.front;i<=Q.rear;i++)
          printf("%d",*(Q.queue+i));
    }
    else{
        for(int i=Q.front;i<size;i++)
            printf("%d",*(Q.queue+i));
        for(int i=0;i<=Q.rear;i++)
           printf("%d",*(Q.queue+i));
    }
}

int main() {
    // Write C code here
    int value;
    printf("\n Enter the size");
    scanf("%d",&size);
    Q.queue=(int *)malloc(size*sizeof(int));
    int choice;
    Q.front=Q.rear=-1;
    for(;;){
        printf("\n Enter your choice");
        scanf("%d",&choice);
    switch(choice){
        case 1:printf("\n Enter the value");
    scanf("%d",&value);
    enqueue(value);
    break;
    case 2:dequeue();break;
    case 3:display();break;
    case 4:exit(0);
    }
    }
}
    
   
