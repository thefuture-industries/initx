#include "sup.h"
#include "builtin.h"
#include "array.h"

#include <stdio.h>
#include <string.h>

const char *supported_scopes[] = {"backend"};

int is_supported(const char *value, const char *list[]) {
    for (size_t i = 0, n = sizeof(list)/sizeof(list[0]); i < n; i++) {
        if (strcmp(value, list[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int cmd_init(int argc, const char **argv) 
{
    argv++;
    argc--;

    if (argc < 2)
    {
        fprintf(stderr, "hint: Maybe you wanted to say 'initx <language> <project_name> [scope]'?\n");
        return 1;
    }

    const char *language = argv[0];
    const char *project_name = argv[1];
    const char *scope = (argc >= 3 && strncmp(argv[2], "--directory=", 12) != 0) ? argv[2] : "console";
    const char *version = get_version(language);

    const char *directory = project_name;

    if (argc >= 3 && !strncmp(argv[argc-1], "directory=", 12))
    {
        const char *mode = argv[argc-1] + 12;

        if (!strcmp("current", mode))
        {
            directory = ".";
        }
        else if (!strcmp("new", mode))
        {
            directory = project_name;
        }
        else
        {
            fprintf(stderr, "error: unknown directory mode '%s' (use 'new' or 'current')\n", mode);
            return 1;
        }
    }

    if (!is_supported(language, supported_languages)) {
        fprintf(stderr, "error: unsupported language: '%s'\n", language);
        return 1;
    }
    
    return 0;
}