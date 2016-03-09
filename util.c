/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.c
 * Author: nuno
 *
 * Created on March 8, 2016, 11:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


void splitHelper(tosplit *arguments) {
    size_t c;
    size_t nextPos = 0;
    size_t pointer = 0;
    size_t i = 0;
    size_t counter = 1;

    while (*(arguments->inputString + i) != 0) {
        if (*(arguments->inputString + i) == arguments->splitChar) {
            counter++;
        }
        i++;
    }

    arguments->size = counter;
    if((arguments->arguments = (char **) malloc(counter * sizeof (char *)))==NULL)
            fprintf(stderr, "Memory allocation was failure");
    

    counter = 0;
    for (c = 0; c <= i; c++) {
        if (*(arguments->inputString + c) == arguments->splitChar
                || *(arguments->inputString + c) == '\0'
                || *(arguments->inputString + c) == '\n') {
            size_t wordSize = (c) - nextPos;
            nextPos = c + 1;
            size_t wordPos = c - wordSize;
            pointer = 0;
            if((*(arguments->arguments + counter) = malloc((wordSize + 1) * sizeof (char)))==NULL)
                fprintf(stderr, "Memory allocation was failure");
            while (wordSize > 0) {

                *(*(arguments->arguments + counter) + pointer) = *(arguments->inputString + wordPos);
                wordPos++;
                wordSize--;
                pointer++;
            }
            *(*(arguments->arguments + counter) + pointer) = '\0';
            counter++;
        }

    }
}

tosplit * strsplit(char *input, char spliChar) {
    tosplit *sliptStruct;
    if((sliptStruct = malloc(sizeof (tosplit)))==NULL)
        fprintf(stderr, "Memory allocation was failure");

    sliptStruct->splitChar = spliChar;
    strcpy(sliptStruct->inputString, input);
    splitHelper(sliptStruct);

    return sliptStruct;
}

void freeStrSlipt(tosplit * freeStrplitStruct) {
    size_t e;
    for (e = 0; e < freeStrplitStruct->size; e++) {
        free(*(freeStrplitStruct->arguments + e));
    }

    free(freeStrplitStruct->arguments);
    free(freeStrplitStruct);
}
