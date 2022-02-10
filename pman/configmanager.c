//
//  configmanager.c
//  pman
//
//  Created by Joel Machens on 2/10/22.
//

#include "configmanager.h"

void parseconfig(char* confstr) {
    char* args[] = {strtok(confstr, " ")};
    int size = sizeof args / sizeof args[0];
    
    for (int i = 0; i < size; i++) {
        printf("%s\n", args[i]);
    }
    
    struct Configuration c;
    c.user = "brickpi";
}
