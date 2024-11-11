#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

main() {
    // Write C code here
    struct node *head,*newnode,*temp;
    head=NULL;
    int choice=1;
    do{
    printf("\n enter your choice,,,0 to end 1 to continue");
    
    scanf("%d",&choice);
    
    
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&newnode->data);
    
   
    if(head==0){
        head=temp=newnode;
    }
    else{
        temp->next = newnode;
        temp=newnode;
    }
    }while(choice!=0);

return 0;
}
