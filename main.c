#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "array.h"
#include "builtin.h"

struct cmd_struct 
{
    const char *cmd;
    int (*fn)(int, const char **);
};

char *handle_options(int argc, const char **argv)
{
    char *cmd = NULL;

    if (!strcmp("--help", argv[0]) || !strcmp("-h", argv[0])) 
    {
        cmd = "help";
    }
    else if (!strcmp("--version", argv[0]) || !strcmp("-v", argv[0]))
    {
        cmd = "version";
    } 
    else if (!strcmp("--scopes", argv[0]) || !strcmp("-s", argv[0]))
    {
        cmd = "scopes";
    }
    else if (!strcmp("--languages", argv[0]) || !strcmp("-l", argv[0]))
    {
        cmd = "languages";
    }


    return cmd;
}

static struct cmd_struct commands[] = {
    {"init", cmd_init},
    {"help", cmd_help},
    {"languages", languages_cmd},
};

static struct cmd_struct *get_builtin(const char *command)
{
    for (size_t i = 0, n = ARRAY_SIZE(commands); i < n; i++) 
    {
        struct cmd_struct *p = commands + i;
        if (!strcmp(command, p->cmd)) 
        {
            return p;
        }
    }

    return NULL;
}

static int handle_builtin(int argc, const char **argv)
{
    struct cmd_struct *builtin;
    const char *cmd = argv[0];

    builtin = get_builtin(cmd);
    if (!builtin) 
    {
        printf("initx: '%s' is not a initx command. See 'initx --help'.\n", cmd);
        return 1;
    }
    
    return builtin->fn(argc, argv);
}

int main(int argc, const char **argv)
{
    const char *cmd;

    argv++;
    argc--;

    if (argc == 0)
    {
        static const char *default_argv[] = { "help" };
        argv = default_argv;
        argc = 1;
    }

    cmd = handle_options(argc, argv);
    if (cmd)
    {
        argv[0] = cmd;
    }
    else
    {
        cmd = argv[0];
    }

    handle_builtin(argc, argv);

    return 0;
}