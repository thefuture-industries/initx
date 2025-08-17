#ifndef TEMPLATES_H
#define TEMPLATES_H

typedef struct
{
    const char *language;
    const char *project_name;
    const char *scope;
    const char *version;
    const char *directory;
} base_template_struct;

int init_template(const base_template_struct *s);

#endif