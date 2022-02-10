//
//  configmanager.c
//  pman
//
//  Created by Joel Machens on 2/10/22.
//

#include "configmanager.h"

void parseconfig(char* confstr) {
    char* token = strtok(confstr, " ");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    
    struct Configuration c;
    c.user = "brickpi";
}
