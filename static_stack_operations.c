#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int i;
struct stack{
    int arr[MAX_SIZE];
    int top;
};
typedef struct stack Stack;
void initStack(Stack * S);
void push(Stack * S,int value);
int pop(Stack * S );
void peek(Stack * S);
void display(Stack * S);

int main() {
    // Write C code here
   Stack * S;
   initStack(S);
   int choice,value,n;
   for(;;){
       printf("\n Menu \n");
       printf("\n1. Push to stack");
       printf("\n2. Pop from Stack");
       printf("\n3. Peek from Stack");
       printf("\n4. Display");
       printf("\n 5.Exit");
       printf("\n Enter your choice");
       scanf("%d",&choice);
       switch(choice){
           case 1:printf("\n Enter the value to insert into stack");
                  scanf("%d",&value);
                  push(S,value);
                  break;
            case 2:value = pop(S);
                 printf("\n Popped Value is %d",value);
                 break;
            case 3:peek(S);
                  break;
            case 4:display(S);
                  break;
            case 5:exit(0);
            default:printf("\n Invalid Choice");
       }}
       return 0;
       
   }
   void initStack(Stack * S){
       S->top=-1;
   }
   void push(Stack * S,int value){
       if(S->top==MAX_SIZE-1){
           printf("\n Stack overflow");
       }
       S->arr[++S->top]=value;
       printf("Pushed %d onto the stack",value);
       
   }
   int pop(Stack * S){
       if(S->top==-1){
           printf("\n Stack is Empty");
           return -1;
       }
       return S->arr[(S->top)--];
   }
   void  peek(Stack * S){
       if(S->top==-1){
           printf("\n Stack is Empty");
           return;
       }
       printf("\n Stack top element : %d ",S->arr[S->top]);
   }
    void  display(Stack * S){
       if(S->top==-1){
           printf("\n Stack is Empty");
           return;
       }
       for(int i=0;i<= S->top;i++);
          printf("%d",S->arr[i]);
   }

