#include "builtin.h"
#include "array.h"

#include <stdio.h>
#include <string.h>

const char *supported_languages[] = {"golang", "c"};
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
    const char *language = argv[1];
    const char *project_name = argv[2];

    if (!is_supported(language, supported_languages)) {
        fprintf(stderr, "error: unsupported language: '%s'\n", language);
        return 1;
    }
    
    return 0;
}