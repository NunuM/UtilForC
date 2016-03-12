/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

const char *filename = "heap.c";
const unsigned short sizeFactor = 1;

/**
 * Increase memory Macro:
 * Decrease memory Macro:
 * @param integer x
 */
#define increaseM(x)   (x<<sizeFactor)
#define decreaseM(x)   (x>>sizeFactor)

/**
 * Helper Macros
 * @param x integer
 */
#define parent(x) ((x-1)/2)
#define leftChild(x) ((2*x)+1)
#define rightChild(x) ((2*x)+2)

/**
 * Swap pointer values.
 * @param st list structure
 * @param x integer
 * @param y integer
 */
void swap(list *st, int x, int y) {
    int xValue = st->data[x];
    *(st->data + x) = st->data[y];
    *(st->data + y) = xValue;
}

/**
 * Moves the entry at index j higher, if necessary, to restore the heap
 * property.
 * @param st list structure
 * @param j integer
 */
void percolateUp(list *st, int j) {
    int ind = parent(j);
    while (ind >= 0 && st->data[j] < st->data[ind]) {
        swap(st, ind, j);
        j = ind;
        ind = parent(j);
    }
}

int hasLeft(list *st, int j) {
    return leftChild(j) < st->size - 1;
}

int hasRight(list *st, int j) {
    return rightChild(j) < st->size - 1;
}

/**
 * Moves the entry at index j lower, if necessary, to restore the heap
 * property.
 * @param st list structure
 * @param j integer
 */
void percolateDown(list *st, int j) {

    while (hasLeft(st, j)) {
        int small = leftChild(j);

        if (hasRight(st, j)) {
            if (st->data[leftChild(j)] > st->data[rightChild(j)]) {
                small = rightChild(j);
            }
        }

        if (st->data[j] > st->data[small]) {
            swap(st, j, small);
            j = small;
        } else {
            break;
        }
    }

}

/**
 * Increase memory if needed by compare the current factor, that give the 
 * current space available.
 * @param st list structure
 */
void memoryManagementForAdd(list *st) {
    if (st->size == 0) {
        if ((st->data = (int *) malloc(sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 25, "Memory error allocation");

        } else {
            st->currentFactor++;
            return;
        }
    }

    int increase = increaseM(st->currentFactor);

    if ((st->currentFactor - st->size) < 1) {
        if ((st->data = realloc(st->data, increase * sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 38, "Memory allocation was failure");
        }
        st->currentFactor = increase;
    }

}

/**
 * Decrease memory if needed by compare the current factor, that give the 
 * current space available.
 * @param st list structure
 */
void memoryManagementForRemove(list *st) {
    int decrease = decreaseM(st->currentFactor);
    if (st->size < decrease) {
        if ((st->data = realloc(st->data, decrease * sizeof (int))) == NULL) {
            error_at_line(-1,
                    EFAULT, filename, 54, "Memory allocation was failure");
        }
        st->currentFactor = decrease;
    }
}

/**
 * Returns a pointer for empty list.
 * @return list structure pointer
 */
list *createHeap() {
    list *st = malloc(sizeof (list));

    if (st == NULL) {
        error_at_line(-1,
                EFAULT, filename, 67, "Stack Memory allocation was failure");
    } else {
        st->size = 0;
    }
    return st;
}

/**
 * Free heap allocated memory.
 * @param st list structure
 */
void destroyHeap(list *st) {
    free(st->data);
    free(st);
}

/**
 * Insert into heap.
 * @param st list structure
 * @param n integer
 */
void insert(list *st, int n) {
    memoryManagementForAdd(st);

    *(st->data + st->size) = n;

    percolateUp(st, st->size);
    st->size++;

}

/**
 * Give it back integer.
 * @param st list structure
 * @return integer
 */
int removeMin(list *st) {

    if (st->size == 0) {
        perror("Stack is empty");
        return -1;
    }


    int value = *(st->data);

    swap(st, 0, st->size - 1);
    st->size--;
    percolateDown(st, 0);


    memoryManagementForRemove(st);
    return value;
}

/**
 * Return but not remove value from heap
 * @param st list structure
 * @return integer minimum value of heap
 */
int min(list *st) {
    return *(st->data);
}

