#include "Includes.h"

void cval(const char *src, const char *func)
{
    char fmtStr[] = "gcc -x c -Wall -Wextra -Wpedantic -Werror -fpic -shared -rdynamic -o borklib.so -ldl - <<EOF\n"
    "#include <stdio.h>\n#include <stdlib.h>\n%s\nEOF";
    char *buf = calloc(sizeof(fmtStr) + strlen(src) + 1, sizeof(char));
    sprintf(buf, fmtStr, src);
    system(buf);
    free(buf);
    void *handle = dlopen("./borklib.so", RTLD_NOW);
    void(*eval)(void) = NULL;
    *(void**)(&eval) = dlsym(handle, func);
    eval();
    dlclose(handle);
}

int main(void)
{
    srand(time(0));
    const char str[] =
    "void function(void)\
    {\
        printf(\"Hello doggo!\\n\");\
    }";
    cval(str, "function");

    return 0;
}
