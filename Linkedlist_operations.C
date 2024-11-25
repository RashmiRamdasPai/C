#include <stdio.h>
#include<stdlib.h>

int count=0;
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE Create(int data){
    NODE X=(NODE)malloc(sizeof(struct node));
    if(X==NULL){
        printf("\n Memory allocation failed");
        exit(0);
    }
    X->data=data;
    X->next=NULL;
    return X;
    }
    NODE insert_front(NODE X,int data){
        NODE newnode=Create(data);
        newnode->next=X;
        count++;
        return newnode;
    }
    NODE insert_rear(NODE X,int data){
        NODE newnode=Create(data);
        if(X==NULL){
            count++;
            return newnode;
        }
        NODE temp=X;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        count++;
        return X;
    }
    NODE delete_front(NODE X){
        if(X==NULL){
            printf("\n List is empty");
            return NULL;
        }
        NODE temp=X;
        X=X->next;
        free(temp);
        count--;
        return X;
    }
    NODE delete_rear(NODE X){
        if(X==NULL){
            printf("List is empty");
            return X;
        }
        if(X->next==NULL){
            free(X);
            count--;
            return NULL ;
        }
        NODE temp,prev;
        temp=X;
        prev=NULL;
        while(temp->next != NULL){
            prev=temp;
            temp=temp->next;
        }
        free(temp);
        prev->next=NULL;
        count--;
        return X;
    }
    
    void display(NODE X){
        NODE temp;
        if(X==NULL){
            printf("Node is empty");
            return;
        }
        temp=X;
        while(temp->next!=NULL){
            printf("%d--",temp->data);
            temp=temp->next;
        }
printf("%d",temp->data);
}
        
        NODE insert_pos(NODE X,int data,int pos){
            NODE newnode,prev,cur;
            if(pos<1 || pos>count+1){
                printf("\n Invalid position");
                return X;
            }
            newnode=Create(data);
            if(pos==1){
                
                newnode->next=X;
                X=newnode;
                count++;
                return X;
            }
            int i=1;
            cur=X;prev=NULL;
            while(i<pos){
                prev=cur;
                cur=cur->next;
                i++;
            }
            newnode->next=cur;
            prev->next=newnode;
            count++;
            return X;
        }
        NODE delete_pos(NODE X,int pos){
            NODE temp,cur,prev;
            int i=1;
            if(X==NULL){
                printf("\n List does not exist");
                return X;
            }
            if(pos<1 || pos>count){
                printf("Invalid position");
                return X;
            }
            if(pos==1){
                temp=X;
                X=X->next;
                free(temp);
                count--;
                return X;
            }
            prev=NULL;
            cur=X;
            while(i<pos){
                prev=cur;
                cur=cur->next;
                i++;
            }
            prev->next=cur->next;
            free(cur);
            count--;
            return X;
        }
        NODE Search_key(NODE X,int key){
            NODE cur;
            int pos;
            if(X==NULL){
                printf("\n List is empty");
                return X;
            }
            if(X->data ==key){
                pos=1;
                printf("\n Element found at position %d",pos);
                return X;
            }
            cur=X;
            pos=1;
            while(cur!=NULL && cur->data!=key){
                pos++;
                cur=cur->next;
            }
            if(cur==NULL){
                printf("Key not found");
                return X;
            }else{
                printf("Key found at position %d",pos);
                return X;
            }
            }
            NODE delete_key(NODE X,int key){
                NODE temp,prev,cur;
                if(X==NULL){
                printf("\n List is empty");
                return X;}
                temp=X;
                if(key==X->data){
                    X=X->next;
                    free(temp);
                    count--;
                    return X;
                }
                prev=NULL;
                cur=X;
                while(cur!=NULL && cur->data !=key){
                    prev=cur;
                    cur=cur->next;
                }
                if(cur==NULL){
                    printf("\n Key not found");
                    return X;
                }
                else{
                    prev->next=cur->next;
                    free(cur);
                    count--;
                    return X;
                }
            }
            NODE insert_ord(NODE X,int data)
            {
                NODE cur,prev,newnode;
                cur=X;
                newnode=Create(data);
                if(X==NULL){
                    count++;
                    return newnode;
                }
                if(data < cur->data){
                    newnode->next=cur;
                    count++;
                    return newnode;
                }
                prev=NULL;
                cur=X;
                while(cur!=NULL && data>cur->data){
                    prev=cur;
                    cur=cur->next;
                }
                prev->next=newnode;
                newnode->next=cur;
                count++;
                return X;
            }
            NODE reverse(NODE X){
                NODE cur,temp;
                cur=NULL;
                while(X!=NULL){
                    temp=X;
                    X=X->next;
                    temp->next=cur;
                    cur=temp;
                }
                return cur;
            }
            NODE Creat(){
                NODE X=(NODE)malloc(sizeof(struct node));
    if(X==NULL){
        printf("\n Memory allocation failed");
        exit(0);
    }
   
    X->next=NULL;
    return X;
    }
    NODE Copy(NODE X){
        NODE y=NULL,temp_x,temp_y,cur=NULL;
        if(X==NULL){
            printf("List does not exist");
            return X;
        }
        temp_x=X;
        while(temp_x!=NULL){
            temp_y=Creat();
            temp_y->data=temp_x->data;
            if(y==NULL){
                y=temp_y;
                cur=temp_y;
            }
            else{
                cur->next=temp_y;
                cur=temp_y;
            }
            temp_x=temp_x->next;
        }
        return y;
    }
    
    void main(){
        NODE first=NULL,second=NULL;
        int ch,data,pos,key;
        for(;;){
            printf("\n 1.Insert at front \n 2.INsert_rear \n 3.Deletefront \n 4.Delete rear \n 5.Display \n 6. Insertion by position \n 7.Delete by position \n 8.Deleteby key \n 9.Search by key \n 10.Insert by key \n 11. Reverse \n 12.Copy the linked list \n 13.Exit \n Enter your choice");
            scanf("%d",&ch);
            switch(ch){
                case 1:printf("Enter the item to be inserted at front");
                       scanf("%d",&data);
                       first=insert_front(first,data);
                       break;
                case 2:printf("Enter the item to be inserted at rear");
                       scanf("%d",&data);
                       first=insert_rear(first,data);
                       break;
                case 3:first=delete_front(first);
                        break;
               
                case 4:first=delete_rear(first);
                       break;
                case 5:display(first);
                       break;
                case 6:printf("Enter the position to add item");
                       scanf("%d",&pos);
                       printf("Enter the item to be inserted");
                       scanf("%d",&data);
                       first=insert_pos(first,data,pos);
                       break;
                case 7:printf("\n Enter the position to delete");
                       scanf("%d",&pos);
                       first=delete_pos(first,pos);
                       break;
                case 8:printf("\n Enter the key to delete");
                       scanf("%d",&key);
                       first=delete_key(first,key);
                       break;
                case 9:printf("Enter the key to search");
                       scanf("%d",&key);
                       first=Search_key(first,key);
                        break;
                case 10:printf("\n Emter the item to be inserted in sorted order");
                       scanf("%d",&data);
                       first=insert_ord(first,data);
                       break;
                case 11:printf("\n Reversing");
                      first=reverse(first);
                      printf("After reversing");
                      display(first);
                      break;
                case 12:second=Copy(first);
                         display(second);
                         break;
                case 13: printf("\n Exiting");
                      exit(0);
            }
        }
}
    
