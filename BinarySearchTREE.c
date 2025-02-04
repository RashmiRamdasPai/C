#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};
typedef struct node* Node;

Node newnode(int data){
    Node node=(Node)malloc(sizeof(struct node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
Node insert(Node root,int data){
    if(root==NULL) return newnode(data);
    if(data<root->data)
      root->left=insert(root->left,data);
     else if(data >root->data)
       root->right=insert(root->right,data);
       return root;
}
Node search(Node root,int key){
    if(root==NULL || root->data==key)return root;
    if(key<root->data)
      return search(root->left,key);
      else
        return search(root->right,key);
    }
Node findMin(Node root){
    while(root && root->left!=NULL)
      root=root->left;
      return root;
}
Node delete(Node root,int data){
    if(root==NULL) return root;
    if(data<root->data)
      root->left=delete(root->left,data);
    else if(data >root->data)
      root->right=delete(root->right,data);
    else{
        if(root->left==NULL){
            Node temp=root->right;
            free(root);return temp;
        }
        else if(root->right==NULL){
            Node temp=root->left;
            free(root);
            return temp;
        }
        Node temp=findMin(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
    }
void inorder(Node root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(Node root){
    if(root==NULL)return;
    printf("%d",root->data);
    preorder(root->left);
    
    preorder(root->right);
}
void postorder(Node root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
    
}

void levelorder(Node root){
    if(root==NULL) return;
    Node queue[10];
    int front, rear=0;
    queue[rear++]=root;
    while(front<rear){
        Node current=queue[front++];
        printf("%d ",current->data);
        if(current->left!=NULL)
          queue[rear++]=current->left;
        if(current->right!=NULL)
          queue[rear++]=current->right;
    }
}
void freeTree(Node root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
int countnodes(Node root){
    if(root==NULL)
        return 0;
    return 1+countnodes(root->left)+countnodes(root->right);
}
int height(Node root){
    if(root==NULL) return -1;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return 1+(leftheight>rightheight?leftheight:rightheight);
}
void max(Node root){
    if(root==NULL){
        printf("Tree is Empty");
        return;
    }
    Node parent=NULL;
    Node current=root;
    while(current->right!=NULL){
        parent=current;
        current=current->right;
    }if(parent)
      printf("Node:%d Parent %d ",current->data,parent->data);
      else
      printf("Node:%d No parent",current->data);
}
void displayNodewithParent(Node root,int key){
    if(root==NULL){
        printf("Not found");
        return;
    }
    Node parent=NULL;
    Node current=root;
    while(current!=NULL){
        if(current->data==key){
            if(parent)
                printf("Node:%d Parent %d ",current->data,parent->data);
      else
      printf("Node:%d No parent",current->data);
       return;
            }
            parent=current;
            if(key<current->data)
                current=current->left;
            else 
            current=current->right;
        }
        printf("\n Key not found");
    }




int main() {
    // Write C code here
    Node root=NULL;
    int choice,data,key;
    for(;;){
        printf("\n 1.insert \n 2.Delete \n 3.Search \n 4.Inorder \n5.Preorder \n 6.Postorder \n 7.Levelorder \n 8.Totls nodes \n 9.height \n 10.Max \n 11.Displaywithparent \n 12.exit \n Enter ur choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\n Enter the value to insert");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2:printf("\n Enter the value to delete");
                    scanf("%d",&data);
                    root=delete(root,data);
                    break;
            case 3:printf("\n Enter the value to search");
                    scanf("%d",&key);
                    Node result=search(root,key);
                    if(result)
                      printf("\n Key foubd");
                     else
                       printf("\n Key not found");
                       break;
          case 4:printf("\n Inorder");
             inorder(root);
               break;
        case 5:printf("\n preorder");
             preorder(root);
               break;
                case 6:printf("\n postorder");
             postorder(root);
               break;
         case 7:printf("\n Level order");
             levelorder(root);
               break;
     case 8:printf("\n Total nodes:%d ",countnodes(root));
          break;
           case 9:
                printf("Height of tree: %d\n", height(root));
                break;
        case 10:max(root);
               break;
        case 11:printf("\n Enter the value to search");
                    scanf("%d",&key);
                displayNodewithParent(root,key);
                break;
    case 12:freeTree(root);
            exit(0);
    default:printf("\n Invalid choice");
        }
    }return 0;
}

               
 
