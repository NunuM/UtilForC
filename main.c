/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: nuno
 *
 * Created on March 8, 2016, 11:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/*
 * 
 */
int main(int argc, char** argv) {
    puts("Usage of strsplit");

    tosplit* array = strsplit("Software undergoes beta testing shortly before it’s released. Beta is Latin for “still doesn’t work", ' ');

    int e;
    for (e = 0; e < array->size; e++) {
        printf("%s\n", *(array->arguments + e));
        

    }

    freeStrSlipt(array);
    
    return (EXIT_SUCCESS);
}

