#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


int stackprecedence(char symbol){
    switch(symbol){
        case '+':
        case '-':return 1;
        case '%':
        case '/':
        case '*':return 3;
        case '^':
        case '$':return 6;
        case ')':return 0;
        case '#':return -1;
        default:return 8;
        
    }
}
    void strrev(char string[]){
        for(int i=0;i<strlen(string);i++){
            int left=0;
            int right=strlen(string)-1;
            while(left<right){
                char temp=string[left];
                string[left]=string[right];
                string[right]=temp;
                left++;
                right--;
            }
        }
    }
    int inputprecedence(char symbol){
    switch(symbol){
        case '+':
        case '-':return 2;
        case '%':
        case '/':
        case '*':return 4 ;
        case '^':
        case '$':return 5;
        case '(':return 0;
        case ')':return 9;
        default:return 7;
        
    }
}
void infixtoprefix(char infix[],char prefix[]){
    int i,j;
    int top=-1;
    char symbol;
    char S[30];
    S[++top]='#';
    strrev(infix);
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        while(stackprecedence(S[top]) > inputprecedence(symbol)){
            prefix[j++]=S[top--];
        }
        if(stackprecedence(S[top]) != inputprecedence(symbol)){
            S[++top]=symbol;
        }
        else
        top--;
    }
    while(S[top]!='#'){
        prefix[j++]=S[top--];
        
    }
    prefix[j]='\0';
    strrev(prefix);
      
}
void prefixevaluate(char prefix[]){
    int op1,op2,res;
    int Stack[30];
    int top=-1;
    strrev(prefix);
    for(int i= 0;i<strlen(prefix);i++){
      char ch=prefix[i];
      if(isdigit(ch)){
          Stack[++top]=ch-'0';
      }
      else{
          if(top<1){
              printf("\n Not enough operands");
              return;
          }
          else{
              op1=Stack[top--];
              op2=Stack[top--];
              switch(ch){
                  case '+':res=op1+op2;
                           break;
                case '-':res=op1-op2;
                           break;
                case '*':res=op1*op2;
                           break;
                case '/':res=op1/op2;
                           break;
                case '%':res=op1%op2;
                           break;
                case '^':res=pow(op1,op2);
                         break;
                           
              }
              Stack[++top]=res;
          }
      }
     
}
 printf("Result : %d",res);
}
void main(){
    char infix[30];
    char prefix[30];
    int choice;
    for(;;){
        printf("\n Enter your choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\n Enter the infix expression");
                   scanf("%s",infix);
                   break;
            case 2:infixtoprefix(infix,prefix);
                   puts(prefix);
                   break;
            case 3:prefixevaluate(prefix);
            break;
            case 4:exit(0);
            default:printf("\n Invalid choice");
        }
    }
  
}
