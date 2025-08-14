#include "file.h"

#include <stdio.h>

void create_dir(const char *path)
{
    #ifndef _WIN32
        _mkdir(path);
    #else
        mkdir(path, 0755);
    #endif
}

void write_file(const char *path, const char *content) 
{
    FILE *f = fopen(path, "w");
    if (!f)
    {
        perror(path);
        return;
    }

    fputs(content, f);
    fclose(f);
}