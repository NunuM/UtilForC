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
#include <syslog.h>
#include "linked_list.h"

/*
 * 
 */

int main(int argc, char** argv) {
    
    struct linked* list = initializeLinkedList();
    
    addNode(list,2,8,77);
    
    printLinkedList(list);

    return (EXIT_SUCCESS);
}

