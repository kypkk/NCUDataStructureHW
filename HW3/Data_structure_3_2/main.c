#include <stdio.h>
#include <stdlib.h>

// define the structure of treeNode
struct treeNode{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

// make a new treeNode that point to NULL
struct treeNode* newTreeNode(int n){
    struct treeNode* new = (struct treeNode*)malloc(sizeof(struct treeNode));
    new -> data = n;
    new -> left = NULL;
    new -> right = NULL;
    return new;
}

// insert a node into a binary search tree
struct treeNode* insert(struct treeNode* root, int data){
    if (root == NULL)
        return newTreeNode(data);
    else if((root->data) < data)
        root->right = insert((root->right), data);
    else if((root->data) > data)
        root->left = insert((root->left), data);
    return root;
}

// print the postorder of the binary search tree
void printPostorder(struct treeNode* root){
    if (root == NULL)
        return;
    printPostorder((root->left));
    printPostorder((root->right));
    printf(" %d",(root->data));
}

// print the preorder of the binary search tree
void printPreorder(struct treeNode* root){
    if (root == NULL)
        return;
    printf(" %d",(root->data));
    printPreorder(root->left);
    printPreorder(root->right);


}

// the main proc
int main( )
{
    int num;
    scanf("%d",&num);
    int datas[num];
    for(int i = 0; i < num; i++){
        scanf("%d", &datas[i]);
    }

    struct treeNode* head = newTreeNode(datas[0]);
    for(int i = 1; i < num; i++){
        insert(head, datas[i]);
    }
    printf("> Preorder:");
    printPreorder(head);
    printf("\n");
    printf("> Postorder:");
    printPostorder(head);

    return 0;
}
