#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "llist.h"		/* for list operations */
#define NAME_TEST "db.txt"

int menu(struct bst * root){
    int choice;
    char name[256];

    printf("\nWelcome to ACME.\n");
    printf("What do you want to do?\n");
    printf("1.- Add an employee.\n");
    printf("2.- Remove and employee.\n");
    printf("3.- List all the employees.\n");
    printf("4.- Save database.\n");
    printf("5.- Read database.\n");
    printf("6.- Exit program.\n");
    printf("Option: ");
    scanf("%d",&choice);

    if(choice==1){
        printf("Name: ");
        scanf("%s",name);
        root = insertN(root,strlen(name),name);
        menu(root);
        return 0;
    }else if(choice==2){
        printf("Name: ");
        scanf("%s",name);
        root = deleteN(root,name);
        remove(NAME_TEST);
        writeFile(root);
        menu(root);
        return 0;
    }else if(choice==3){
        traverse(root);
        menu(root);
        return 0;
    }else if(choice==4){
        readFile();
        menu(root);
        return 0;
    }else if(choice==5){
        writeFile(root);
        menu(root);
        return 0;
    }else if(choice==6){
        printf("Exiting program\n");
        //sl(3);
        return 0;
    }else{
        printf("Selected option wasn't available");
        menu(root);

    }
    }



int main (){

    struct bst *root = NULL;
    menu(root);
    return 0;
}
