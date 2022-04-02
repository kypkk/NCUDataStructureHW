#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100000

// define structure of tree node
struct Treenode{
    int frequency;
    char data;
    struct Treenode* left;
    struct Treenode* right;
};

// define structure of a listnode that contains a treenodePointer and a listPointer
struct Listnode{
    struct Treenode* data;
    struct Listnode* next;
};

// define a structure of a character's code
struct code{
    char code[Max];
    char data;
};

// moke a new treenode that point to NULL
struct Treenode* newNode(char value){
    struct Treenode* temp = (struct Treenode*)malloc(sizeof(struct Treenode));
    temp -> data = value;
    temp -> frequency = 1;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

// determine whether the Treenode is a leaf
int isLeaf(struct Treenode* node){
    return (node -> left == NULL && node -> right == NULL);
}

// moke a new Treenode that point to two Treenodes we sent in, and store the sum of two treenode's frquency
struct Treenode* gather(struct Treenode* left, struct Treenode* right){
    struct Treenode* temp = (struct Treenode*)malloc(sizeof(struct Treenode));
    temp -> data = (left -> data < right -> data ? left -> data : right -> data);
    temp -> frequency = left -> frequency + right -> frequency;
    if(left -> frequency == right -> frequency){
        if(isLeaf(right) && !isLeaf(left)){
            struct Treenode* swap = left;
            left = right;
            right = swap;
        }
    }
    temp -> left = left;
    temp -> right = right;
    return temp;
}

// make a new listnode that point to NULL, and a treepointer
struct Listnode* NewListNode(struct Treenode* data){
    struct Listnode* temp = (struct Listnode*)malloc(sizeof(struct Listnode));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

// sort the string by ascii order
void sorting(char string[]){
    int n = strlen(string);
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(string[j] < string[j-1]){
                char temp = string[j];
                string[j] = string[j-1];
                string[j-1] = temp;
            }
        }
    }
}

// Since we store the character and its frequency into a array of treenode,
// we'll have to store it into a linked listNode
struct Listnode* ArrayToList(struct Treenode* Queue[], int total){
    // we have to make a temporary Listnode in order to let current and head point to the same list
    struct Listnode* head = (struct Listnode*)malloc(sizeof(struct Listnode));
    head -> data = NULL;
    head -> next = NULL;
    struct Listnode* current = head;

    for(int i = 0; i < total; i++){
        current -> next = NewListNode(Queue[i]);
        current = current -> next;
    }

    //after converting, we have to free the temporary node
    struct Listnode* Empty = head;
    head = head -> next;
    free(Empty);
    return head;
}

// sort the frequency from small to big
void sortFrequence(struct Listnode** head){
    struct Listnode* current = *head;
    while(current != NULL){
        struct Listnode* bubble = current;
        struct Listnode* next = current -> next;
        //bubble sort
        while(next != NULL){
            if(bubble -> data -> frequency > next -> data -> frequency){
                bubble = next;
            }
            else if(bubble -> data -> frequency == next -> data -> frequency){
                if(bubble -> data -> data > next -> data -> data){
                    bubble = next;
                }
            }
            next = next -> next;
        }
        //swap
        struct Treenode* temp = bubble -> data;
        bubble -> data = current -> data;
        current -> data = temp;

        current = current -> next;
    }
}

// make the linkedlist into a huffman tree
struct Treenode* huffman(struct Listnode* head, int total){
    while(total != 1){
        sortFrequence(&head);
        struct Listnode* first = head;
        struct Listnode* second = head -> next;
        struct Treenode* node = gather(first -> data, second -> data);
        struct Listnode* temp = head;
        head = head -> next;	// remove one;
        free(temp);
        head -> data = node;
        total--;
    }
    struct Treenode* root = head -> data;
    return root;
}

// give each character its huffman code by "left 0 right 1" rule
void make(struct Treenode* root, struct code codes[], int *i, char string[], int level){
    if(root == NULL) return;
    if(root -> left == NULL && root -> right == NULL){
        codes[*i].data = root -> data;
        for(int k = 0; k < level; k++){
            codes[*i].code[k] = string[k];
        }
        codes[*i].code[level] = '\0';
        (*i)++;
    }
    string[level++] = '0';
    make(root -> left, codes, i, string, level);
    level--;
    string[level++] = '1';
    make(root -> right, codes, i, string, level);
    level--;
    string[level] = '\0';
}

// I use this to check if I properly store the array of treeNode into a linked listNode
void printList(struct Listnode* head){
    struct Listnode* current = head;
    while(current != NULL){
        printf("char: '%c', frequency: %d\n", current -> data -> data, current -> data -> frequency);
        current = current -> next;
    }
}

// I use this to check if each character's huffman code is make properly
void printCode(struct code codes[], int total){
    for(int i = 0; i < total; i++){
        printf("char: '%c', code: %s\n", codes[i].data, codes[i].code);
    }
}

// I encode the string and print out the minimum weighted external path length
void encode(char unchange[], struct code key[], int total){
    int length = 0;
    printf("> ");
    for(int i = 0; i < strlen(unchange); i++){
        for(int j = 0; j < total; j++){
            if(unchange[i] == key[j].data){
                printf("%s", key[j].code);
                length += strlen(key[j].code);
                break;
            }
        }
    }
    printf("\n> %d", length);
}

int main() {

    // get the string
    char string[Max];
    if(fgets(string, Max, stdin) == NULL) return 0;
    char unchange[Max];

    // copy the unchanged string to the unchange, since I have to encode the string at last
    strcpy(unchange, string);

    // sort the string with the order from the smallest to the largest
    sorting(string);

    // check if the string is properly sorted
    // printf("%s", string);

    int n = strlen(string);
    struct Treenode* Queue[n];
    int total = 1;		    // total numbers of different character

    Queue[0] = newNode(string[0]);

    // store the ordered string and its frequency into an array of treeNode
    for(int i = 1; i < n; i++){
        if(string[i] == Queue[total - 1] -> data){
            (Queue[total - 1] -> frequency)++;
        }
        else{
            Queue[total++] = newNode(string[i]);
        }
    }

    // check if (the ordered) string is stored correctly
    // for(int i = 0; i < total; i++){
    //      printf("char: %c, frequency: %d\n", Queue[i] -> data, Queue[i] -> frequency);
    // }


    // convert the treenode pointer array to the linked list pointer
    struct Listnode* head = ArrayToList(Queue, total);

    // check if the array is converted correctly
    // printList(head);

    // sort the frequency of each list node in the linked list
    sortFrequence(&head);

    // check if the frequency of the list is sorted properly
    // printList(head);

    // make the huffman tree
    struct Treenode* root = huffman(head, total);
    struct code Codes[total];

    // if the string only contain one distinct character
    // if it isn't, make the huffmancode of each distinct character
    if(total == 1){
        Codes[0].data = head -> data -> data;
        Codes[0].code[0] = '0';
        Codes[0].code[1] = '\0';
    }
    else{
        int i = 0;
        char string[Max];
        int level = 0;
        make(root, Codes, &i, string, level);
    }

    // encode the string and the minimum weighted external path length
    encode(unchange, Codes, total);


    return 0;
}
