#include "builtin.h"

#include <stdio.h>

const char *initx_usage = 
    "usage: initx [-v | --version] [-h | --help] [-l | --languages]\n"
    "             [-s | --scopes] [--directory='current | new']\n"
    "             <command> [<args>]\n";

const char *initx_work_arch =
    "working with architecture creation:\n"
    "   initx [language] [project-name] [scope]";

int cmd_help(int argc, const char **argv) 
{
    printf(initx_usage);
    printf("\n%s", initx_work_arch);
    
    return 0;
}