//
//  configmanager.h
//  pman
//
//  Created by Joel Machens on 2/10/22.
//
#ifndef configmanager_h
#define configmanager_h

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

// Parse the Config from a string
struct Configuration {
    char* user; //user who owns configuration
    int appBuild; //version of the application
};

void parseconfig(char* confstr);

#endif /* configmanager_h */
