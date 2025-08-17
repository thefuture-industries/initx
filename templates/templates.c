#include "templates.h"
#include "templ_golang.h"

#include <stdio.h>
#include <string.h>

int init_template(const base_template_struct *s)
{
    if (!strcmp("golang", s->language))
    {
        templ_golang(s);
    }
    else if (!strcmp("c", s->language))
    {
        //
    }
    else
    {
        fprintf(stderr, "error: unsupported language: '%s'\n", s->language);
        return 1;
    }

    return 0;
}