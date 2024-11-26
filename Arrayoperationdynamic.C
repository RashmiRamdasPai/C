#include <stdio.h>
#include<stdlib.h>

void insert_by_pos(int *p,int *n,int pos,int key);
void delete_by_pos(int *p,int *n,int pos);
void insert_by_key(int *p,int *n,int key);
void delete_by_key(int *p,int *n,int key);
void insert_by_order(int *p,int *n,int key);
int search_by_key(int *p,int *n,int key);
int search_by_pos(int *p,int *n,int pos);
void reverse(int *p,int n);
void display(int *p,int n);
void read(int *p,int n);
void sort(int *p,int *n);

int main() {
    
    int n,pos,key,choice;
    printf("\n Enter the array size");
    scanf("%d",&n);
    int *p=(int *)malloc(n*sizeof(int));
    if(p==NULL){
        printf("Memory allocation failed");
        return 1;
    }
        do{
            printf("\n Enter your choice:");
            printf("\n 1.Read \n 2.Display \n 3.Insert by position \n4.Deelete by position \n 5.Insert by key \n 6.Delete by key \n 7.Insert by order \n 8.Search by key \n 9.Search by position \n 10.Reverse \n 11.Quir \n");
            scanf("%d",&choice);
            switch(choice){
                case 1:read(p,n);
                       break;
                case 2:display(p,n);
                      break;
                case 3:printf("\n Enter the position and element");
                       scanf("%d %d",&pos,&key);
                       insert_by_pos(p,&n,pos,key);
                       break;
                case 4:printf("\n Enter the position");
                       scanf("%d",&pos);
                       delete_by_pos(p,&n,pos);
                       break;
                case 5:printf("\n Enter the key where insertion should take place");
                     scanf("%d",&key);
                     insert_by_key(p,&n,key);
                     break;
                case 6:printf("\n Enter the key where deletion should take place");
                     scanf("%d",&key);
                     delete_by_key(p,&n,key);
                     break;
                case 7:printf("\n Enter the key which should be inserted");
                       scanf("%d",&key);
                       insert_by_order(p,&n,key);
                       break;
                case 8:printf("\n Enter the key which should be searched");
                       scanf("%d",&key);
                       printf("%d",search_by_key(p,&n,key));
                       break;
                case 9:printf("\n Enter the position of the key");
                       scanf("%d",&pos);
                        printf("%d",search_by_pos(p,&n,pos));
                        break;
                case 10:reverse(p,n);
                        break;
                case 11:printf("Exit");
                        exit(0);
            }
        }while(choice>0 && choice<=11);
           return 0; }
     void read(int *p,int n){
         printf("\n Enter the array elements:");
         for(int i=0;i<n;i++)
            scanf("%d",(p+i));
     }
     void display(int *p,int n){
         printf("\n the array elements are");
         for(int i=0;i<n;i++)
            printf("%d",*(p+i));
     }
     void insert_by_pos(int *p,int *n,int pos,int key){
         (pos)--;
         if(pos<0 || pos>(*n)){
             printf("\n Invalid position");
             return;
         }
         p=realloc(p,(*n+1)*sizeof(int));
         if(p==NULL){
             printf("Memory Allocation Failed");
             return ;
         }
         for(int i=((*n)-1);i>=pos;i--)
             *(p+i+1)=*(p+i);
             *(p+pos)=key;
             (*n)++;
     }
      void delete_by_pos(int *p,int *n,int pos){
         (pos)--;
         if(pos<0 || pos>=*n){
             printf("\n Invalid position");
             return;
         }
         for(int i=pos;i<=*n;i++)
             *(p+i)=*(p+i+1);
            
             (n)--;
     }
     int search_by_key(int *p,int* n,int key){
         for(int i=0;i<*n;i++){
             if(*(p+i)==(key)){
                 return i+1;
             }
         }
         return -1;
     }
      int search_by_pos(int *p,int *n,int pos){
          (pos)--;
          if((pos)<0 || (pos)>=*n){
             printf("\n Invalid position");
             return -1;
         }
         return *(p+pos);
         
     }
     void insert_by_key(int *p,int *n,int key){
         int pos=search_by_key(p,n,key);
         if(pos==-1){
             printf("\n Key not found");
             return;
         }
         pos--;
         int ele;
         printf("\n Enter the key element to be inserted");
         scanf("%d",&ele);
          p=realloc(p,(*n+1)*sizeof(int));
         if(p==NULL){
             printf("Memory Allocation Failed");
             return ;
         }
         
         for(int i=*n-1;i>=pos;i--)
             *(p+i+1)=*(p+i);
             *(p+pos)=ele;
             (*n)++;
     }
      void delete_by_key(int *p,int *n,int key){
         int pos=search_by_key(p,n,key);
         if(pos==-1){
             printf("\n Key not found");
             return;
         }
         pos--;
         for(int i=pos;i<=*n;i++){
             *(p+i)=*(p+i+1);
         }
         ((*n)--);
      }
      void insert_by_order(int *p,int *n,int key){
          sort(p,n);
          int pos=0;
          while(pos<*n && *(p+pos)<key){
              pos++;
          }
           p=realloc(p,(*n+1)*sizeof(int));
         if(p==NULL){
             printf("Memory Allocation Failed");
             return ;
         }
            for(int i=*n-1;i>=pos;i--)
             *(p+i+1)=*(p+i);
             
             (*n)++;
             *(p+pos)=key;
     }
     void sort(int *p,int *n){
         for(int i=0;i<*n;i++){
             int flag=0;
             for(int j=0;j<(*n-i-1);j++){
                 if(*(p+j)>*(p+j+1)){
                     flag=1;
                     int temp=*(p+j);
                     *(p+j)=*(p+j+1);
                     *(p+j+1)=temp;
                 }
             }
             if(flag==0){
                 break;
             }
         }
     }
     void reverse(int *p,int n){
         int left=0;
         int right=n-1;
         int temp;
         while(left<right){
             temp=*(p+left);
             *(p+left)=*(p+right);
             *(p+right)=temp;
             left++;
             right--;
         }
     }
     
