// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


int stackprecedence(char symbol){
    switch(symbol){
    case '+':
    case '-':return 2;
    case '/':
    case '%':
    case '*':return 4;
    case '^':
    case '$':return 5;
    case '(':return 0;
    case '#':return -1;
    default:return 8;
}
}
int inputprecedence(char symbol){
    switch(symbol){
    case '+':
    case '-':return 1;
    case '/':
    case '%':
    case '*':return 3;
    case '^':
    case '$':return 6;
    case '(':return 9;
    case ')':return 0;
    case '#':return -1;
    default:return 7;
}
}
void infixtopostfix(char infix[],char postfix[]){
    int i=0;
    int j=0;
     char Stack[10];
    int top=-1;
    Stack[++top]='#';
    for(int i=0;i<strlen(infix);i++){
     char symbol=infix[i];
    while(stackprecedence(Stack[top])>inputprecedence(symbol)){
        postfix[j++]=Stack[top--];
    }
    if(stackprecedence(Stack[top])!=inputprecedence(symbol)){
        Stack[++top]=symbol;
    }
    else
      top--;
    }
    while(Stack[top]!='#'){
        postfix[j]=Stack[top--];
        j++;
    }
    postfix[j]='\0';
    }
void postfixevaluate(char postfix[]){
    int S[30];
    int top=-1;
    int i,j,result;
    for(i=0;i<strlen(postfix);i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            S[++top]=ch-'0';
        }
        else{
            if(top<1)
              printf("\n Not enough operands");
            else{
                int op2=S[top--];
                int op1=S[top--];
                switch(ch){
                    case '+':result=op1+op2;
                             break;
                    case '-':result=op1-op2;
                             break;
                    case '*':result=op1*op2;
                             break;
                    case '/':result=op1/op2;
                             break;
                    case '%':result=op1%op2;
                             break;
                    case '^':result=pow(op1,op2);
                             break;
                   default:printf("Invalid operator");
                    
                }
                S[++top]=result;
            }
              
        }
    }
    printf("\n Result:%d",result);
}

void main() {
    char infix[30];
    char postfix[30];
    int choice;
    for(;;){
    printf("\n Menu \n 1.enter the infix expression \n 2.Convert to postfix \n 3.Evaluate the postfix \n 4.Exit");
    printf("\n Enter your choice");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("\n Enter the infix expression");
               scanf("%s",infix);
               break;
        case 2:infixtopostfix(infix,postfix);
               puts(postfix);
               break;
        case 3:postfixevaluate(postfix);
               break;
        case 4:printf("\n Thank you");
              break;
        default:printf("\n Invalid choice");
    }
}
}
