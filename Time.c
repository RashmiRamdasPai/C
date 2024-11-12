#include <stdio.h>
#include<stdlib.h>

struct Time{
    int hour;
    int minute;
    int second;
};
void readTime(struct Time *T){
    printf("Enter time(HH:MM:SS):");
    scanf("%d %d %d",&T->hour,&T->minute,&T->second);
}
void displayTime(struct Time *T){
   if(T->second >=60){
        T->minute += T->second/60;
        T->second =T->second%60;
    }
    if(T->minute >=60){
        T->hour+=T->minute/60;
        T->minute=T->minute%60;
    }
    if(T->hour >=24){
        T->hour %=24;
    }
    printf("Time:%02d:%02d:%02d",T->hour,T->minute,T->second);
    
}
void updateTime(struct Time *T){
    T->second++;
    if(T->second >=60){
        T->minute +=T->second/60;
        T->second =T->second%60;
    }
    if(T->minute>=60){
        T->hour +=T->minute/60;
        T->minute =T->minute%60;
    }
    if(T->hour >=24){
        T->hour %=24;
    }
     printf("\n Time:%02d:%02d:%02d",T->hour,T->minute,T->second);
    
    
}
struct Time addTimes(const struct Time *T1,const struct Time *T2){
    struct Time result;
    result.second = T1->second+T2->second;
    result.minute = T1->minute+T2->minute;
    result.hour = T1->hour+T2->hour;
    /*Normalise the values*/
    if(result.second >=60){
        result.minute+=result.second/60;
        result.second %=60;
    }
    if(result.minute >=60){
        result.hour += result.minute/60;
        result.minute %=60;
    }
    if(result.hour >=24){
        result.hour %=24;
    }
    return result;
}
int main(){
    struct Time T1;struct Time T2,result;
    int choice;
    do{
        printf("\n Menu:");
        printf("\n.Enter 1 to read Time");
        printf("\n.Enter 2 to display Time");
        printf("\n.Enter 3 to update the  Time by one second");
        printf("\n.Enter 4 to add the Two Times");
        printf("\n.Enter 5 to Exit the program");
        printf("\n Enter your choice");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:readTime(&T1);
                   break;
            case 2: displayTime(&T1);
                   break;
            case 3:updateTime(&T1);
                   break;
            case 4:printf("\n Enter the first time");
                   readTime(&T1);
                   printf("\n Enter the second time");
                   readTime(&T2);
                   result =addTimes(&T1,&T2);
                   printf("\n Resultant time on addition");
                   displayTime(&result);
                   break;
            case 5:printf("\n Exiting the program");
                   break;
            default:printf("\n You have entered invalid values for choice input");
        }
    }while(choice!=5);
    return 0;


    
}
