/*
 Homework 2-1
 Name: Ben
 Project Title: Traversing the second half of the linked list and reverse it
 Student ID: 109201521
 Date: 2021_10_31
 */

#include <stdio.h>
#include <stdlib.h>
// linkedlist is a structure with multiple listnodes linked together
// so I give it a listPointer to point to the next node
// and data to store the current data
typedef struct listNode *listPointer;
typedef struct listNode{
    int data;
    listPointer link;
};

// This is a function to create listnodes & let them linked together
// Firstly I create a new node and assign a memory location to it
// Second I assign the data into the node and let it point to node initially
// Third if the node that I send into this Function is NULL I assign the new node to it
// Lastly if the node is not NULL I loop it till I find the last node and add the new node to it
void CreateNode(int data, listPointer *node){
    listPointer newNode = malloc(sizeof(listPointer));
    newNode -> data = data;
    newNode -> link = NULL;
    listPointer temp = *node;
    if(*node == NULL){
        *node = newNode;
        return;
    }
    while(temp -> link != NULL){
        temp = temp -> link;
    }
    temp -> link = newNode;
}

// Traversing loop through the linked list and print it out
void Traversing(listPointer node){
    listPointer temp = node;
    while(temp != NULL){
        printf(" %d", temp -> data);
        temp = temp -> link;
    }
    puts("");                       // puts("109201521") == printf("109201521\n")
}

// TraversingHalf loop through the first half of the linkedlist without printing
// then print out the second half while looping through the second half
void TraversingHalf(listPointer node, int total){
    listPointer temp = node;
    printf(">");
    int i = 0;
    for(i = 0; i < total / 2; i++){
        temp = temp -> link;
    }
    for(i = total / 2; i < total; i++){
        printf(" %d",temp -> data);
        temp = temp -> link;
    }
    puts("");
}

// Inserting insert a node in between the linkedlist by the location sent in
void Inserting(listPointer *node, int data, int location){
    listPointer newNode = malloc(sizeof(listPointer));
    listPointer temp = *node;
    newNode -> data = data;
    int i = 1;
    if(location == 0){
        newNode -> link = temp;
        *node = newNode;
        return;
    }
    while(i < location){
        temp = temp -> link;
        i++;
    }
    newNode -> link = temp -> link;
    temp -> link = newNode;
}

// deleteData delete the keyData tha was sent in
void deleteData(listPointer *node, int keyData){
    listPointer previous = *node;
    listPointer present = *node;
    if(present -> data == keyData){         // determine whether the first data is keyData
        previous = present -> link;
        *node = previous;
        free(present);
        return;
    }
    while(present -> data != keyData){
        previous = present;
        present = present -> link;
    }
    previous -> link = present -> link;
    free(present);
}

// Reverse reverses thenode by following steps
// Firstly, create three listPointers assign previous node to prev
//          assign temprorary node to temp and assign NULL to next
// Second, assign the next node to next
// Third, let temp -> link points to the previous node
// Fourth, assign temp to prev
// Fifth, assign next to temp
// Lastly, loop Second to Fifth until temp is NULL and the linkedlist is reversed
void Reverse(listPointer *node){
    listPointer temp = *node;
    listPointer prev = NULL;
    listPointer next = NULL;
    while(temp != NULL){
        next = temp -> link;
        temp -> link = prev;
        prev = temp;
        temp = next;
    }
    *node = prev;
}

int main() {
    // Create a node call first & use totals to count the numbers of the nodes
    listPointer first = malloc(sizeof(listPointer));
    int data;
    int totals = 0;
    deleteData(&first, 0);

    // while there's the program scan a data it create a new node and add it at the tail of the linked list
    //       & totals + 1 every time the program create new node
    while(scanf("%d", &data) != EOF){
        CreateNode(data, &first);
        totals++;
    }

    // the following four lines traverse the second half of the linked list & reverse it
    TraversingHalf(first, totals);
    Reverse(&first);
    printf(">");
    Traversing(first);

    return 0;
}
