//
//  main.c
//  pman
//
//  Created by Joel Machens on 2/10/22.
//
#define TRUE 1
#define FALSE 0
typedef int bool;

#include "configmanager.h"

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        printf("No argument given!\n");
        return -1;
    }

    if (parseconfig() == -1)
        return -1;
    
    //process command
    if (strcmp(argv[1], "-c") == 0) { //config
        if (argc == 4) { //edit a configuration setting
            
        }
        else if (argc == 3) { //get a configuration key
            int t = getKeyType(argv[2]);
            switch (t)
            {
            case 0: //string
                printf("%s : %s\n", argv[2], getStringKey(argv[2]));
                break;
            case 1: //int
                printf("%s : %d\n", argv[2], getIntKey(argv[2]));
                break;
            case 2: //bool
                printf("%s : %d\n", argv[2], getBoolKey(argv[2]));
                break;
            }
        } 
        else {
            printf("Improper use of configuration command!\n");
        }
    }
    else if (strcmp(argv[1], "-h") == 0) {
        printf("Help:\nUse \"-c\" for configuration,\nUse \"-a\" to add projects,\nUse \"-d\" to delete projects,\nUse \"-i\" for task information,\nand Use \"-p\" to print all current projects");
    }
    else {
        printf("Unknown Command : \"%s\"\nUse \"-h\" for help!\n", argv[1]);
    }
    
    return 0;
}
