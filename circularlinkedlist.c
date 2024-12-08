#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
int count=0;
struct Node {
    int data;
    struct Node* next;
} ;
typedef struct Node *Node;
void insertFront(Node header, int data);
void insertRear(Node header, int data);
void display(Node header);
void deleteFront(Node header);
void deleteRear(Node header);
void deleteBykey(Node header,int key);
void insertAtPosition(Node header,int data,int position);
void deleteAtPosition(Node header,int position);
void searchbykey(Node header,int key);
void reverse(Node header);
void createOrderedList(Node header);
Node copyList(Node header);

// Function to create a new node
Node createNode(int data) {
    Node  newNode = (Node)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the front of the circular linked list
void insertFront(Node header, int data) {
    Node newNode = createNode(data);
    if (header->next == header) { // If the list is empty
        header->next = newNode;
        newNode->next = header;
    } else {
        newNode->next = header->next;
        header->next = newNode;
    }
    count++;
}

// Function to insert at the rear of the circular linked list
void insertRear(Node header, int data) {
    Node newNode = createNode(data);
    if (header->next == header) { // If the list is empty
        header->next = newNode;
        newNode->next = header;
    } else {
        Node temp = header->next;
        while (temp->next != header) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = header;
    }
    count++;
}
void deleteFront(Node header){
     if (header->next == header) { // If the list is empty
        printf("List is empty\n");
        return;
    }

    Node temp = header->next;
    header->next = temp->next;
    free(temp);
    count--;

}
void deleteRear(Node header){
     if (header->next == header) { // If the list is empty
        printf("List is empty\n");
        return;
    }

    Node temp = header->next;
    while (temp->next->next != header) {
        temp = temp->next;
    }

    Node lastNode = temp->next;
    temp->next = header;
    free(lastNode);
    count--;
}
void deleteByKey(Node header, int key) {
    if (header->next == header) { // If the list is empty
        printf("List is empty\n");
        return;
    }

    Node temp = header->next;
    Node prev = header;

    while (temp != header) {
        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            count--;
            return;
        }
        prev = temp;
        temp = temp->next;
        
    }
    printf("Key not found\n");
}
void insertAtPosition(Node header, int data, int position) {
    Node newNode = createNode(data);
    if(position==1 && header->next==header){
        header->next=newNode;
        newNode->next=header;
        count++;
        return;
    }
    if (position <= 0 || position>count+1) {
        printf("Invalid position\n");
        return;
    }
    if(position==1){
        newNode->next=header->next;
        header->next=newNode;
        count++;
        return;
    }

    
    Node temp = header->next;
    int i = 1;

    while (i < position-1) {
        temp = temp->next;
        i++;
    }

  
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
  
}
void deleteAtPosition(Node header, int position) {
    if (header->next == header) { // If the list is empty
        printf("List is empty\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    Node temp = header->next;
    Node prev = header;
    int i = 1;

    while (temp != header && i < position) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == header) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    count--;
}

void searchbykey(Node header, int key) {
    Node temp = header->next;
    int pos=1;
    while (temp != header) {
        if (temp->data == key) {
            printf("\n Element found at position %d",pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    return ;
}
void reverse(Node header){
     if (header->next == header || header->next->next == header) {
        return;  // No need to reverse if the list is empty or has only one element
    }

    Node prev=header;
    Node cur=header->next;
    Node next=NULL;
    
  while(cur!=header){
      next=cur->next;
      cur->next=prev;
      prev=cur;
      cur=next;
  }
  header->next=prev;
}

void createOrderedList(Node header) {
     if (header->next == header || header->next->next == header) {
        return;  // No need to reverse if the list is empty or has only one element
    }
        for(Node i=header->next;i->next!=header;i=i->next){
            for(Node j=i->next;j!=header;j=j->next){
                if(i->data>j->data){
                    int temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }
        }
    }
    Node copyList(Node header) {
    Node newHeader = createNode(0); // Create a new header node
    Node temp = header->next;
    Node last = newHeader;

    while (temp != header) {
        Node newNode = createNode(temp->data);
        last->next = newNode;
        newNode->next = newHeader;
        last = newNode;
        temp = temp->next;
    }

    return newHeader;
}





void display(Node header){
    if (header->next == header) {
        printf("The list is empty.\n");
        return;
    }

    Node temp = header->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != header);

    printf("(Header)\n");
}


int main() {
    Node header = createNode(0); // Initialize the circular linked list with a header node
    header->next = header; // Initially points to itself (empty list)

    int choice, data, position, key;
   

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Delete by key\n");
        printf("6.Insert at specified position\n");
        printf("7.Delete At position\n");
        printf("8.Search by key\n");
        printf("9.Reverse\n");
        printf("10.Create ordered List\n");
        printf("11.Create a copy of linked list\n");
        printf("12.Display\n");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            
            case 1:printf("\n Enter the data");
                   scanf("%d",&data);
                   insertFront( header,  data);
                   break;
            case 2:printf("\n Enter the data");
                   scanf("%d",&data);
             insertRear(header, data);
                   break;
            
            case 3:deleteFront(header);
                   break;
            case 4:deleteRear(header);
                   break;
            case 5:printf("\n Enter the key to be deleted");
                   scanf("%d",&key);
                   deleteByKey(header,key);
                  break;
            case 6:printf("\n Enter the position and data to be inserted");
                   scanf("%d %d",&position,&data);
                   insertAtPosition( header,data,position);
                   break;
           case 7:printf("\n Enter the position to be deleted");
           scanf("%d",&position);
                  deleteAtPosition(header,position);
            break;
           case 8:printf("\n Enter the key to be searched");
                  scanf("%d",&key);
                  searchbykey(header,key);
                  break;
            case 9:reverse(header);
            break;
            case 10:createOrderedList(header);
            break;
                   
            case 12:display(header);
                  break;
                  case 11:
                {
                    Node newHeader= copyList(header);
                    printf("Copied list: ");
                    display(newHeader);
                    break;
                }

                
            
            case 13:exit(0);}
        }while(choice!=13);
    }
