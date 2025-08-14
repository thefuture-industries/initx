#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "builtin.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

struct cmd_struct 
{
    const char *cmd;
    int (*fn)(int, const char **);
};

static int handle_options(int *argc, const char ***argv)
{
    while (*argc > 0)
    {
        const char *cmd = (*argv)[0];
        if (cmd[0] != '-')
        {
            break;
        }

        if (!strcmp(cmd, "--help") || !strcmp(cmd, "-h") ||
            !strcmp(cmd, "--version") || !strcmp(cmd, "-v"))
                break;

        if (!strcmp(cmd, "--directory")) 
        {
            exit(0);
        }

        (*argv)++;
		(*argc)--;
    }

    return 0;
}

static struct cmd_struct commands[] = {
    {"init", cmd_init},
    {"help", cmd_help},
};

static struct cmd_struct *get_builtin(const char *command)
{
    for (size_t i = 0; i < ARRAY_SIZE(commands); i++) {
        struct cmd_struct *p = commands + i;
        if (!strcmp(command, p->cmd)) {
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
    if (!builtin) {
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
    handle_options(&argc, &argv);

    if (argc == 0)
    {
        static const char *default_argv[] = { "help" };
        argv = default_argv;
        argc = 1;
    }

    if (!strcmp("--help", argv[0]) || !strcmp("-h", argv[0])) 
    {
        argv[0] = "help";
    }
    else if (!strcmp("--version", argv[0]) || !strcmp("-v", argv[0]))
    {
        argv[0] = "version";
    } 
    else if (!strcmp("--scopes", argv[0]) || !strcmp("-s", argv[0]))
    {
        argv[0] = "scopes";
    }
    else if (!strcmp("--languages", argv[0]) || !strcmp("-l", argv[0]))
    {
        argv[0] = "languages";
    }

    cmd = argv[0];

    handle_builtin(argc, argv);

    return 0;
}