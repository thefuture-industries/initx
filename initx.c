#include <stdio.h>
#include <string.h>

#include "builtin.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

struct cmd_struct 
{
    const char *cmd;
    int (*fn)(int, const char **);
};

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

int main(int argc, const char **argv)
{
    struct cmd_struct *builtin;
    const char *cmd;

    cmd = argv[1];
    if (!cmd) 
        cmd = "help";

    builtin = get_builtin(cmd);
    if (builtin) {
        builtin->fn(argc, argv);
    }

    return 0;
}