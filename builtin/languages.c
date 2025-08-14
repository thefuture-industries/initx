#include <stdio.h>

const char *supported_languages =
    "list of supported languages for initx:\n";

int languages_cmd(int argc, const char **argv)
{
    printf("%s\n", supported_languages);
    

    return 0;
}