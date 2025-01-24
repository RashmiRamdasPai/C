#include<stdio.h>
#include<stdlib.h>
int size;

struct Queue{
    int *queue;
    int front;
    int rear;
}Q;
void pushrear(int val){
    if(Q.rear==size-1 && Q.front==0||Q.front>Q.rear){
        printf("\n Queue is full,Reallocating Memory");
        size++;
        Q.queue=(int*)realloc(Q.queue,size*sizeof(int)); 
    }
    if(Q.front==-1 && Q.rear==-1){
        Q.front=Q.rear=0;
    }
    else if(Q.rear==size-1){
        Q.rear=0;
    }
      else
        Q.rear++;
        *(Q.queue+Q.rear)=val;
}
void pushfront(int val){
     if(Q.rear==size-1 && Q.front==0||Q.front>Q.rear){
        printf("\n Queue is full");
       printf("\n Reallocating the memory");
       size++;
       Q.queue=(int *)realloc(Q.queue,size*sizeof(int));
    }
    if(Q.front==-1 ){
        Q.front=Q.rear=0;
    }
    else if(Q.front==0)
      Q.front=size-1;
    else
      Q.front--;
      *(Q.queue+Q.front)=val;
}
void popfront(){
     if(Q.rear==-1 && Q.front==-1){
        printf("\n Queue is Empty");
        return;
    }
    if(Q.front==Q.rear){
        printf("Deleted element is %d ",*(Q.queue+Q.front));
        Q.front=Q.rear=-1;
}
else if(Q.front==size-1){
     printf("Deleted element is %d ",*(Q.queue+Q.front));
     Q.front=0;
     
}
else{
   printf("Deleted element is %d ",*(Q.queue+Q.front));
     Q.front++;
      
}
}

void poprear(){
     if(Q.rear==-1 && Q.front==-1){
        printf("\n Queue is Empty");
        return;
    }
    if(Q.front==Q.rear){
        printf("Deleted element is %d ",*(Q.queue+Q.rear));
        Q.front=Q.rear=-1;
}
else if(Q.rear==0){
     printf("Deleted element is %d ",*(Q.queue+Q.rear));
     Q.rear=size-1;
     
}
else{
   printf("Deleted element is %d ",*(Q.queue+Q.rear));
     Q.rear--;
      
}
}  
void display(){
    int i;
    if(Q.front==-1 && Q.rear==-1){
        printf("\n Queue is Empty");
        return;
    }
    if(Q.front<=Q.rear){
        for(i=Q.front;i<=Q.rear;i++){
            printf("%d ",*(Q.queue+i));
        }
    }
    else{
        for(i=Q.front;i<=size-1;i++){
            printf("%d ",*(Q.queue+i));
        for(i=0;i<=Q.rear;i++)
        printf("%d ",*(Q.queue+i));
        } 
    }
    }
    void main(){
        int val,choice;
        Q.front=Q.rear=-1;
        printf("\n Enter the size");
        scanf("%d",&size);
        printf("Menu \n1.Push-front \n 2.Push-rear \n 3.Pop-front \n 4.Pop-rear \n 5.Display \n 6.EXIT");
        Q.queue=(int *)malloc(size*sizeof(int));
        for(;;){
            printf("\n Enter your choice");
            scanf("%d",&choice);
            switch(choice){
                case 1:printf("\n Enter the element to be inserted");
                     scanf("%d",&val);
                     pushfront(val);
                     break;
                case 3:popfront();break;
                case 2:printf("\n Enter the element to be inserted");
                     scanf("%d",&val);
                     pushrear(val);break;
                case 4:poprear();break;
                case 5:display();break;
                case 6:printf("\n Thankyou");
                       exit(0);
                default:printf("\n You have entered invalid choice");
            }
        }
    }











