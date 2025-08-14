#include "initx-lang.h"
#include "file.h"
#include "initx.h"

#include <stdio.h>

void initx_golang_backend(base_initx_struct *s)
{
    const path[256];

    create_dir(s->directory);

    sprintf(path, sizeof(path), "%s/cmd", s->directory);
    create_dir(path);

    sprintf(path, sizeof(path), "%s/config", s->directory);
    create_dir(path);

    sprintf(path, sizeof(path), "%s/handler", s->directory);
    create_dir(path);

    sprintf(path, sizeof(path), "%s/infra", s->directory);
    create_dir(path);

    sprintf(path, sizeof(path), "%s/middleware", s->directory);
    create_dir(path);

    sprintf(path, sizeof(path), "%s/pkg", s->directory);
    create_dir(path);

    sprintf(path, sizeof(path), "%s/tests", s->directory);
    create_dir(path);

    sprintf(path, sizeof(path), "%s/util", s->directory);
    create_dir(path);

    // go.mod
    sprintf(path, sizeof(path), "%s/go.mod", s->directory);
    char go_mod[512];
    sprintf(go_mod, sizeof(go_mod), "module %s\n\ngo 1.20\n", s->project_name);
    write_file(s->directory, go_mod);
}

int initx_golang_console(char *directory)
{
    return 0;
}