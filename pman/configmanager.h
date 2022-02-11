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
#include "iniparser.h"
#ifdef WIN32
#include <windows.h>
#endif
#define CONF_PATH ".projektmanager/pm.ini"

//Configuration Data
typedef struct {
    char* user; //user who owns configuration
    int appBuild; //version of the application
} Configuration;

static Configuration CONFIG;

int parseconfig();

int getBoolKey(char* key);
int getIntKey(char* key);
char* getStringKey(char* key);

int getKeyType(char* key);

int setBoolKey(char* key, int value);
int setIntKey(char* key, int value);
int setStringKey(char* key, char* value);

#endif /* configmanager_h */
