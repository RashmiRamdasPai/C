#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * prev;
    struct node * next;
};
typedef struct node * Node;
Node header =NULL;
int count=0;
Node createNode(int value);
void initializeheader();
void insertFront(int value);
void insertRear(int value);
void insertatpos(int value,int pos);
void deletefront();
void deleterear();
void deleteatpos(int pos);
void deletebykey(int key);
void searchbykey(int key);
void createorderedlist(int value);
void reverselist();
Node copyList();
void display();
int main(){
    initializeheader();
    int choice,value,position;
    while(1){
        printf("\n Menu \n");
        printf("\n 1.Insert at front \n 2.Insert at Rear \n 3.Insert at position \n 4.Delete front \n 5.Delete Rear \n 6.Delete at positoin \n 7.Delete by key \n 8.Search by key \n 9.Create an ordered list \n 10.Reverse \n 11.Create a copy of the list \n 12.Display \n 13.Exit \n");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\n Enter value:");
                   scanf("%d",&value);
                   insertFront(value);
                   break;
            case 2:printf("\n Enter value");
                   scanf("%d",&value);
                   insertRear(value);
                   break;
            case 3:printf("\n Enter the value and the position");
                   scanf("%d %d",&value,&position);
                   insertatpos(value,position);
                   break;
            case 4:deletefront();
                   break;
            case 5:deleterear();
                   break;
            case 6:printf("\n Enter the position");
                   scanf("%d",&position);
                   deleteatpos(position);
                   break;
            case 7:printf("\n Enter the key to delete");
                   scanf("%d",&value);
                   deletebykey(value);
                   break;
            case 8:printf("\n Enter the key to search");
                    scanf("%d",&value);
                    searchbykey(value);
                    break;
            case 9:printf("\n ENTER THE VALUE");
                    scanf("%d",&value);
                    createorderedlist(value);
                    break;
            case 10:reverselist();
                    break;
            case 11:Node copy=copyList();
                    printf("\n Copied LIST");
                    display(copy);
                    break;
            case 12:display();
                    break;
            case 13:printf("\n Exiting");
                    exit(0);
            default:printf("\n Invalid choice");
        }
    }
    return 0;
}
Node createNode(int value){
    Node newnode = (Node)malloc(sizeof(Node));
    newnode->data=value;
    newnode->prev=newnode->next=NULL;
    return newnode;
}
void initializeheader(){
    header=createNode(-1);
    header->next=header->prev=header;
}
void insertFront(int value){
    Node newnode = createNode(value);
    newnode->next=header->next;
    newnode->prev=header;
    
    header->next->prev=newnode;
    header->next=newnode;
    if(header->next==header){
        header->prev=newnode;
    }
    count++;
}
void insertRear(int value){
    Node newnode=createNode(value);
    newnode->next=header;
    newnode->prev=header->prev;
    header->prev->next=newnode;
    header->prev=newnode;
    count++;
}
void insertatpos(int value,int position){
    Node newnode=createNode(value);
    if(position==1){
        insertFront(value);
        count++;
        return;
    }
    if(position<1 || position>count+1){
        printf("\n Invalid position");
        return;
    }
    
    Node temp=header->next;
    int i=1;
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    newnode->next->prev=newnode;
    count++;
}
void deletefront(){
    if(header->next==header){
        printf("\n List is empty");
        return;
    }
    Node first=header->next;
    header->next=first->next;
    first->next->prev=header;
    free(first);
    printf("\n Deleted from front \n");
    count--;
}
void deleterear(){
    if(header->next==header){
        printf("\n List is empty");
        return;
    }
    Node last=header->prev;
    last->prev->next=header;
    header->prev=last->prev;
    free(last);
    count--;
}
void deleteatpos(int position){
    if(header->prev==header){
        printf("\n List is Empty");
        return;
    }
    if(position<1 && position>count){
        printf("\n Invalid position");
        return;
    }
    int i=1;
    Node temp=header->next;
    while(i<position){
        temp=temp->next;
        i++;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    count--;
}
void deletebykey(int key){
    if(header->next==header){
        printf("\n List is empty");
        return;
    }
    Node temp=header->next;
    while(temp!=header){
        if(temp->data==key){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            count--;
            return;
        }
        temp=temp->next;}
        printf("\n Key not found");
    
}
void searchbykey(int key){
    if(header->next==header){
        printf("\n List is empty");
        return;
    }
    Node temp=header->next;
    int pos=1;
    while(temp!=header){
        if(temp->data==key){
            printf("\n Key found at position %d",pos);
            return;}
            temp=temp->next;
            pos++;}
            printf("\n Key not found");
        
    }
    void createorderedlist(int value){
        Node temp=header->next;
        while(temp!=header &temp->data<value){
            temp=temp->next;}
            Node newnode=createNode(value);
            newnode->next=temp;
            newnode->prev=temp->prev;
            temp->prev->next=newnode;
            temp->prev=newnode;
            count++;
        }
        void reverselist(){
            if(header->next==header || header->next->next==header){
                return;
            }
            Node current=header->next;
            Node firstnode=header->next;
            Node prev=header;
            do{
                Node nextnode=current->next;
                current->next=prev;
                current->prev=nextnode;
                prev=current;
                current=nextnode;
            }while(current!=header);
            header->next=prev;
            header->prev=firstnode;
        }
        Node copyList(){
            Node newheader=createNode(-1);
            newheader->next=newheader->prev=newheader;
            Node temp=header->next;
            while(temp!=header){
                Node newnode=createNode(temp->data);
                newnode->prev=newheader->prev;
                newnode->next=newheader;
                newheader->prev->next=newnode;
                newheader->prev=newnode;
                temp=temp->next;
            }
            return newheader;
        }
        void display(){
            if(header->next==header){
                printf("\n List is empty");
                return;}
                Node temp=header->next;
                while(temp!=header){
                    printf("%d--",temp->data);
                    temp=temp->next;
                    
                }
                printf("(Header)\n");
            }  
