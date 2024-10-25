#include <stdio.h>
#include<stdlib.h>
struct student{
    int roll;
    float fees;
}s1,s2;

int main() {
    // Write C code here
   printf("\n Enter the first student rollno and fees paid");
   scanf("%d %f",&s1.roll,&s1.fees);
   printf("\n Enter the second student rollno and fees paid");
   scanf("%d %f",&s2.roll,&s2.fees);
   struct student *ptr1 = &s1;
   struct student *ptr2 = &s2;
   printf("\n The roll no and fees of first student are respectively:");
   printf("%d %f",ptr1->roll,ptr1->fees);
   printf("\n The roll no and fees of first student are respectively:");
   printf("%d %f",ptr2->roll,ptr2->fees);
   
   

    return 0;
}
