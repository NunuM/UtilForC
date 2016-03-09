/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.h
 * Author: nuno
 *
 * Created on March 8, 2016, 11:29 PM
 */

#ifndef UTIL_H
#define UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        char ** arguments;
        char inputString[128];
        short size;
        char splitChar;
    } tosplit;

    tosplit* strsplit(char *input, char spliChar);
    void freeStrSlipt(tosplit * freeStrplitStruct);

#ifdef __cplusplus
}
#endif

#endif /* UTIL_H */

