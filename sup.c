#include "sup.h"
#include "array.h"
#include "string.h"

#include <stdio.h>

typedef struct
{
    const char *language;
    const char *version;
} language_version_struct;

static language_version_struct language_with_version[] = 
{
    {"c", "v11"},
    {"golang", "v1.23"},
};

const char *supported_languages[] = {"golang", "c"};

int show_list_lang(char *custom_out)
{
    for (size_t i = 0, n = sizeof(supported_languages)/sizeof(supported_languages[0]); i < n; i++)
    {
        printf("%s%s\n", custom_out, supported_languages[i]);
    }

    return 0;
}

const char *get_version(const char *language)
{
    for (size_t i = 0, n = ARRAY_SIZE(language_with_version); i < n; i++)
    {
        if (!strcmp(language_with_version[i].language, language))
        {
            return language_with_version[i].version;
        }
    }

    return NULL;
}