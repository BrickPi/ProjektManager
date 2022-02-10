//
//  main.c
//  pman
//
//  Created by Joel Machens on 2/10/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#ifdef WIN32
#include <windows.h>
#define DATA_PATH "%USERPROFILE%/.projektmanager/"
#define CONF_PATH "%USERPROFILE%/.projektmanager/pm.conf"
#else
#define DATA_PATH ".projektmanager/"
#define CONF_PATH ".projektmanager/pm.conf"
#endif

#include "configmanager.h"

void rek_mkdir(char *path) {
    char *sep = strrchr(path, '/');
    if(sep != NULL) {
        *sep = 0;
        rek_mkdir(path);
        *sep = '/';
    }
    if(mkdir(path, 0777) && errno != EEXIST)
        printf("error while trying to create '%s'\n%m\n", path);
}

FILE* fopen_mkdir(char *path, char *mode) {
    char *sep = strrchr(path, '/');
    if(sep) {
        char *path0 = strdup(path);
        path0[ sep - path ] = 0;
        rek_mkdir(path0);
        free(path0);
    }
    return fopen(path,mode);
}

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        printf("No argument given!\n");
        return -1;
    }
    
    //load configuration from disk
    FILE* fp = (FILE*)fopen_mkdir(CONF_PATH, "a+");
    if(!fp) {
        fclose(fp);
        printf("Failed to open config file!");
        return -1;
    }
    char* buffer = (char*)malloc(255);
    fgets(buffer, 255, fp);
    fclose(fp);
    //parse the configuration
    parseconfig(buffer);
    free(buffer);
    
    //process actual command
    if (strcmp(argv[1], "-c") == 0) { //config
        if (argc == 3) { //edit a configuration setting
            
        }
        else {
        printf("Config:\n%s\n", buffer);
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
