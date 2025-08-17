#include "fs.h"

#include <stdio.h>
#include <errno.h>

#ifdef _WIN32
    #include <direct.h>
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

void create_dir(const char *path)
{
    int rc;

#ifdef _WIN32
    rc = _mkdir(path);
#else
    rc = mkdir(path, 0755);
#endif

    if (rc == -1)
    {
        if (errno == EEXIST)
        {
            return;
        }
        else
        {
            perror("mkdir");
        }
    }
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