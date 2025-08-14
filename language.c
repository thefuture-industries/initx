#include "language.h"
#include "array.h"

#include <stdio.h>

int show_list_lang()
{
    for (size_t i = 0, n = ARRAY_SIZE(supported_languages); i < n; i++)
    {
        printf("%s\n", supported_languages[i]);
    }
}