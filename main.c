#include "Includes.h"

typedef void(*voidFunc)(void);

voidFunc cval(const char *src, const char *func)
{
    char fmtStr[] = "gcc -x c -Wall -Wextra -Wpedantic -Werror -fpic -shared -rdynamic -o borklib.so -ldl - <<EOF\n"
    "#include <stdio.h>\n#include <stdlib.h>\n%s\nEOF";
    char *buf = calloc(sizeof(fmtStr) + strlen(src) + 1, sizeof(char));
    sprintf(buf, fmtStr, src);
    system(buf);
    free(buf);
    void *handle = dlopen("./borklib.so", RTLD_NOW);
    voidFunc eval = NULL;
    *(void**)(&eval) = dlsym(handle, func);
    return eval;
}

int main(void)
{
    srand(time(0));
    const char str[] =
    "void function(void)\
    {\
        printf(\"Hello doggo!\\n\");\
    }";
    voidFunc function = cval(str, "function");
    function();
    return 0;
}
