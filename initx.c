#include <stdio.h>

struct cmd_struct 
{
    const char *cmd;
    int (*fn)(int, char **);
};

// static struct cmd_struct commands[]
// {
    
// };

static struct cmd_struct *get_buildin(const char *command)
{
    return NULL;
}

int main(int argc, const char **argv)
{
    const char *cmd;
    int done_help = 0;

    cmd = argv[0];
    if (!cmd) 
        cmd = "initx-help";

    return 0;
}