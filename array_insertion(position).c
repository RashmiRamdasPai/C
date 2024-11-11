#include <stdio.h>
#include<stdlib.h>
int main() {
    // Write C code here
    int A[10],n,pos,ele,i;
    system("clear");
    printf("\n enter the size of the array");
    scanf("%d",&n);
     printf("\n the array elements are");
    for(int i=0;i<n;i++)
      scanf("%d",&A[i]);
    printf("\n Enter the position");
    scanf("%d",&pos);
    printf("\n enter the element to be inserted at position %d",pos);
    scanf("%d",&ele);
    for(int i=n;i>pos-1;i--)
    {
        A[i]=A[i-1];
        
    }
    n++;
    A[pos]=ele;
    printf("\n the array elements after insertion are");
    for(int i=0;i<n;i++)
      printf("%d ",A[i]);
    
    
    return 0;
}
