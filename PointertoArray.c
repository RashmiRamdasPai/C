#include <stdio.h>
#include<stdlib.h>
int n,i,*p,*end,A[10];
void read(int*);
void reverse(int*);
void display(int*);
void main()

{
    
    printf("Enter the size of the array");
    scanf("%d",&n);
    p=A;
    read(p);
    display(p);
    end = A+n-1;
    reverse(end);
    display(end);
}
void read(int *p){
    
    printf("\n enter the array elements");
    for(i=0;i<n;i++)
     scanf("%d",p+i);
}
void display(int *p){
    
    printf("\n array elements are:");
    for(i=0;i<n;i++)
     printf("%d",*(p+i));
}
void reverse(int *end){
    
    printf("\n array elements in reverse order");
     for(i=0;i<n;i++)
     printf("%d",*(end-i));
    
}
