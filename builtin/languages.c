#include "builtin.h"
#include "sup.h"

#include <stdio.h>

const char *title_supported_languages =
    "list of supported languages for initx:\n";

int languages_cmd(int argc, const char **argv)
{
    printf("%s\n", title_supported_languages);
    show_list_lang("- ");

    return 0;
}