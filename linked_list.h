/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linked_list.h
 * Author: nuno
 *
 * Created on July 29, 2016, 8:55 PM
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "util/collection/heap.h"


#ifdef __cplusplus
extern "C" {
#endif

struct node {
    int value;
    struct node * next;
};

struct linked {
    int size;
    struct node * head;
};

int addNode(struct linked *list, int argsNum, ...);
int removeNode(struct linked * list, struct node *toRemove);
int clearNodes(struct linked * list);
int removeLinkedList(struct linked * list);
void printLinkedList(struct linked * list);

struct linked * initializeLinkedList();



#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */

