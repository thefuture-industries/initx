#include "language.h"

#include <stdio.h>

const char *supported_languages[] = {"golang", "c"};

int show_list_lang(char *custom_out)
{
    for (size_t i = 0, n = sizeof(supported_languages)/sizeof(supported_languages[0]); i < n; i++)
    {
        printf("%s%s\n", custom_out, supported_languages[i]);
    }

    return 0;
}