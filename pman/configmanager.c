//
//  configmanager.c
//  pman
//
//  Created by Joel Machens on 2/10/22.
//

#include "configmanager.h"

int parseconfig() {
    //load configuration from disk
    dictionary* conf = iniparser_load(CONF_PATH);

    CONFIG.user = iniparser_getstring(conf, "user", "UNSET");
    CONFIG.appBuild = iniparser_getint(conf, "appBuild", -1);

    //all data in config struct, free buffer
    iniparser_freedict(conf);
}

int getKeyType(char* key) { // 0 : string, 1 : int, 2 : bool, -1 : Unknown
    if (strcmp(key, "user") == 0)
    {
        return 0;
    }
    else if (strcmp(key, "appBuild") == 0)
    {
        return 1;
    }
    else
    {
        printf("Unknown Key Type!\n");
        return -1;
    }
    
}

int getBoolKey(char* key) {
    printf("UNIMLEMENTED!");
    return -1;
}

int getIntKey(char* key) {
    if (strcmp(key, "appBuild") == 0)
    {
        return CONFIG.appBuild;
    }
    else
    {
        printf("No key with name: %s\n", key);
        return -1;
    }
}

char* getStringKey(char* key) {
    if (strcmp(key, "user") == 0)
    {
        return CONFIG.user;
    }
    else
    {
        printf("No key with name: %s\n", key);
        return "";
    }
}

int setBoolKey(char* key, int value) {
    printf("UNIMLEMENTED!");
    return -1;
}

int setIntKey(char* key, int value) {
    printf("UNIMLEMENTED!");
    return -1;
}

int setStringKey(char* key, char* value) {
    printf("UNIMLEMENTED!");
    return -1;
}
