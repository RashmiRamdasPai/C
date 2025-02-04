#include<stdio.h>
#include<stdlib.h>
struct dequeue{
    int *arr;
    int front;
    int rear;
    int size;
};
typedef struct dequeue DQ;
void ins_rear(DQ * dq){
     if((dq->rear+1)%dq->size==dq->front){
        int n = dq->size;
        dq->size=dq->size*2;
      dq->arr=(int *)realloc(dq->arr,dq->size*(sizeof(int)));
      if(dq->arr==NULL){
        printf("\nmemory failed");
        exit(0);
      }
      printf("\nReallocated successfully");
      if(dq->front>dq->rear){
        for (int i = 0; i < dq->front; i++) {
                dq->arr[i + n] = dq->arr[i]; // Move wrapped elements to the new position
            }
            dq->rear += n; // Update rear to the correct position
        }
        /*int i=dq->front;int j=0;
        while(i!=dq->rear){
            dq->arr[j]=dq->arr[i];
            j++;i++;
        }
        dq->arr[j]=dq->arr[i];
        dq->front=0;
        dq->rear=dq->size-1;
      }*/
    }
    if(dq->front==-1||dq->rear==-1){
         dq->arr = (int *)malloc(dq->size * sizeof(int));
if (dq->arr == NULL) {
    printf("Memory allocation failed!");
    exit(0);
}
        dq->front++;
        dq->rear++;
         printf("\nEnter item to be inserted:");
    int item;
    scanf("%d",&item);
    dq->arr[dq->rear]=item;
    return;
    }
    printf("\nEnter item to be inserted:");
    int item;
    scanf("%d",&item);
    dq->rear=(dq->rear+1)%dq->size;
    dq->arr[dq->rear]=item;
    return;
}
void del_front(DQ * dq){
    if(dq->front==-1){
        printf("\nQueue empty");
        return;
    }
    if(dq->front==dq->rear){
    dq->front=dq->rear=-1;
    return;
    }
    dq->front=(dq->front+1)%dq->size;
    return;

}
void display(DQ * dq){
    if(dq->front==-1){
        printf("\nQueue empty");
        return;
    }
    int i=dq->front;
    while(i!=dq->rear){
        printf("%d\t",dq->arr[i]);
        i=(i+1)%dq->size;
    }
       printf("%d\t",dq->arr[i]);
}
void ins_front(DQ * dq){
     if(dq->front==0){
        printf("\ncannot insert at front\n");
        return;
    }
    if(dq->front==-1||dq->rear==-1){
         dq->arr = (int *)malloc(dq->size * sizeof(int));
if (dq->arr == NULL) {
    printf("Memory allocation failed!");
    exit(0);
}
        dq->front++;
        dq->rear++;
         printf("\nEnter item to be inserted:");
    int item;
    scanf("%d",&item);
    dq->arr[dq->rear]=item;
    return;
    }
    printf("\nEnter the item to be inserted:\n");
    int item;
    scanf("%d",&item);
    dq->front=(dq->front-1+dq->size)%dq->size;
    dq->arr[dq->front]=item;
    return;
}
void del_rear(DQ * dq){
    if(dq->rear==-1){
        printf("\nQueue empty\n");
        return;
    }
    if(dq->front==dq->rear){
        dq->front=-1;
        dq->rear=-1;
    }
    int item;
item=dq->arr[dq->rear];
    dq->rear=(dq->rear-1+dq->size)%dq->size;
    return;
}
void que_front(DQ * dq){
    if(dq->front==-1){
        printf("\nQueue empty");
        return;
    }
    printf("queue front----%d",dq->arr[dq->front]);
    return;
}
void que_rear(DQ * dq){
    if(dq->front==-1){
        printf("\nQueue empty");
        return;
    }
    printf("queue rear----%d",dq->arr[dq->rear]);
    return;
}



void main(){
    DQ dq;
    dq.front=dq.rear=-1;
    int choice;
    int n;
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    dq.size=n;
   
    for(;;){
        printf("\nEnter your choice::");
        scanf("%d",&choice);
        switch(choice){
            case 1:ins_rear(&dq);
                   break;
            case 2:ins_front(&dq);
                   break;
            case 3:del_front(&dq);
                   break;  
            case 4:del_rear(&dq);
                   break;
            case 5:display(&dq);
                   break;
            case 6:que_front(&dq);
                   break;
            case 7:que_rear(&dq);
                   break;
              
                   
        }
    }
} 
