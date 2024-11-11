#include <stdio.h>
#include<stdlib.h>
int main() {
    // Write C code here
    int A[10],n,pos,ele,i;
    
    system("clear");
    printf("\n enter the size of the array");
    scanf("%d",&n);
     printf("\n enter the array elements in sorted form only!!");
    for( i=0;i<n;i++)
      scanf("%d",&A[i]);
    
    printf("\n enter the element to be inserted ");
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(A[i]>ele){
            pos=i;
            break;
        }
        else{
            pos=n;
        }
    }
    for(int i=n;i>pos;i--)
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
