#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"

#define NAME_TEST "db.txt"

struct bst {
    char name[26];
    int lng;
    struct bst *left;
    struct bst *right;
};

struct bst *root = 0;

struct bst * newNode(int num, const char * info){//Create A New Node
    struct bst * node = (struct bst*) malloc(sizeof(struct bst));
    node ->lng=num;
    strcpy(node->name,info);
    printf(node->name," was added.");
    node->left=0;
    node->right=0;
    return node;
};

void traverse(struct bst *root){//It goes through all the BST and print every node
    if(root !=0){
        traverse(root->left);
        printf("Name: ",root->name);
        traverse(root->right);
    }else{
        printf("Leaf");
    }
}

struct bst * insertN(struct bst * root, int num, const char * info){
    //Insert a new node depending on the length of the name
    if(root==NULL){
        root = newNode(num,info);
    }else{
        if(num<=root->lng){
            root->left = insertN(root->left,num,info);
        }else{
            root->right = insertN(root->right,num,info);
        }
    }
    return root;
};

struct bst * searchN(struct bst * leftL){
    //Search the minimum left node
    struct bst * current = leftL;
    while(current->left !=NULL){
        current = current->left;
    }
    return current;
};

struct bst * deleteN(struct bst * root, const char * name){
//transverse the BTS until it find the node to delete
    if(root==NULL){
        return root;
    }
    if(strlen(name)<strlen(root->name)){
        root->left = deleteN(root->left,name);
    }else if(strlen(name)>strlen(root->name)){
        root->right = deleteN(root->right,name);
    }else{
        if(root->left==NULL){
            struct bst * tmp = root->right;
            free(root);
            return tmp;
        }else if(root->right==NULL){
            struct bst * tmp = root->left;
            free(root);
            return tmp;
        }
        struct bst * tmp = searchN(root->right);
        strcpy(root->name,tmp->name);

        root->right=deleteN(root->right,tmp->name);
    }
    return root;
};

void writeFile(struct bst * root){
    //Write the BTS on a txt file
    FILE * file = fopen(NAME_TEST,"a+");

    if(root!=0){
        fputs(root->name,file);
        fputs("\n",file);
        writeFile(root->left);
        writeFile(root->right);
    }
    else{
        if(root == 0)
            printf("Processing request...\n");
        else
            printf("\nroot != NULL %d");
    }
    fclose(file);
}

void readFile(){ //reads a file
    int i = 0;
    int line = 1;
    char ch[100];

    FILE *file = fopen("db.txt","r");

    if(file){
        while(line){
         if( fscanf(file,"%s",&ch[i]) != EOF){
             printf("\n%s",&ch[i]);
         }
         else{
             line = 0;
             printf("\nWe are done!");
         }
         i++;
        }
        fclose(file);
    }
}
