/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap.h
 * Author: nuno
 *
 * Created on March 11, 2016, 10:52 PM
 */

#ifndef HEAP_H
#define HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        int size;
        int *data;
        int currentFactor;
    } list;

    list *createHeap();
    void destroyHeap(list *st);

    void insert(list *st, int data);
    int min(list *st);
    int removeMin(list *st);

#ifdef __cplusplus
}
#endif

#endif /* HEAP_H */

