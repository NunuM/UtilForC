/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/**
 * Allocate linked list in heap memory.
 * 
 * @return pointer to empty linked list
 */
struct linked * initializeLinkedList(){
    
    struct linked* list = (struct linked*) malloc(sizeof (struct linked));
    
    if(list == NULL)
        return NULL;
    
    list->head = NULL;
    
    return list;
}


/**
 * Insert at end of list new allocated node, with given value.
 * 
 * @param list pointer
 * @param value to insert
 * @return boolean of action
 */
int addNode(struct linked * list, int value) {

    struct node ** next = &(list->head);
    struct node * newNode = (struct node *) malloc(sizeof (struct node));

    if (newNode == NULL)
        return EXIT_FAILURE;

    newNode->value = value;
    newNode->next = NULL;

    while (*next != NULL)
        next = &(*next)->next;

    * next = newNode;

    list->size++;

    return EXIT_SUCCESS;
}

/**
 * Free from memory all the nodes previously allocated in list.
 * 
 * @param list pointer
 * @return boolean of action
 */
int clearNodes(struct linked * list) {

    
    struct node * currentNode = list->head;
    struct node * aux = NULL;

    while (currentNode != NULL) {
        aux = currentNode;
        currentNode = currentNode->next;
        free(aux);
    }

    list->head = NULL;

    return EXIT_SUCCESS;
}

/**
 * Free all the nodes and the list from the memory.
 * 
 * @param list
 * @return boolean
 */
int removeLinkedList(struct linked * list) {

    clearNodes(list);
    free(list);

    return EXIT_SUCCESS;
}

/**
 * Search and remove node, the comparison is made by address memory value.
 * 
 * @param list pointer
 * @param node pointer to remove
 * @return boolean of action
 */
int removeNode(struct linked * list, struct node *toRemove) {

    struct node ** next = &(list->head);

    while (*next != NULL) {
        if (*next == toRemove) {
            * next = toRemove->next;
            free(toRemove);
            list->size--;
            return EXIT_SUCCESS;

        }
        next = &(((*next)->next));
    }

    return EXIT_FAILURE;
}

/**
 * Print all values from the list.
 * @param pointer to list
 */
void printLinkedList(struct linked * list) {

    struct node * currentNode = list->head;

    while (currentNode) {
        printf("%d\n", currentNode->value);
        currentNode = currentNode->next;
    }

}