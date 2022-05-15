#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next; // self referential pointer
};
typedef struct node Node;

Node* create_head_node(int data){
    // Create first node for a given data.
    Node *myNode;
    myNode = (Node*) malloc(sizeof(Node));
    myNode->data = data;
    myNode->next = NULL;
    return myNode;
}

Node* create_interim_node(Node *array, int data){
    //Create intermediate node
    Node* myNode;
    myNode = (Node*) malloc(sizeof(Node));
    myNode->data = data;
    myNode->next = NULL;
    //Append the node to the existing array
    array->next = myNode;
    return myNode;
}


// Node* create_ll( int* arr){
//     //Create the linked list for the given array `arr`
//     int i;
//     Node* next;
//     Node* linkedList;
//     for(i=0;i<sizeof(arr);i++){
//         if(i==0){
//             next = create_head_node(arr[i]);
//             linkedList = next;
//         }
//         else{
//             next = create_imtering_node(next, arr[i]);
//         }
//     }
//     return linkedList;
// }

Node* create_ll_sibu(){
    int val,opt;
    Node *llHead, *interim;
    while (true)
    {
        printf("1. Enter 1 to create head node of linked list.\n");
        printf("2. Enter 2 to create interim node of linked list.\n");
        printf("3. Exit linked list creation mode.\n");
        printf("*******************************\n");
        scanf("%d",&opt);
        if (opt==1)
        {
            printf("Enter the value for head node\n");
            scanf("%d",&val);
            interim = create_head_node(val);
            llHead = interim;
        }
        else if(opt==2){
            printf("Enter the value for interim node\n");
            scanf("%d",&val);
            interim = create_interim_node(interim, val);
        }
        else if(opt==3){
            break;
        }
    }
    return llHead;
}

void iterate_ll(Node *ll){
    //Travers  over the nodes of the linked list and print the values.
    Node *nNode;
    nNode = ll;
    while(nNode->next != NULL){
        printf("%d\n", nNode->data);
        nNode = nNode->next;
    }
    printf("*****************************************************\n");
}

int main(){
    int option;
    Node* ll;
    while(true){
        printf("Enter 1 to create a linked list.\n");
        printf("Enter 2 to print the linked list.\n");
        printf("Enter 3 to exit the program.\n");
        printf("*******************************\n");
        scanf("%d",&option);
        if(option==1){
            ll = create_ll_sibu();
        }
        else if(option==2){
            iterate_ll(ll);
        }     
        else if(option==3)
        {
            break;
        }
        
    }
}
