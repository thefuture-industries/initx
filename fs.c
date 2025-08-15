#include "fs.h"

#include <stdio.h>

#ifdef _WIN32
    #include <direct.h>
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

void create_dir(const char *path)
{
#ifdef _WIN32
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