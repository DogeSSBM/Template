#include "Includes.h"

int main(int argc, char **argv)
{
    assertExprMsg(argc > 1, "Usage: %s <arg> [arg]", argv[0]);
    for(int i = 0; i < argc; i++)
        printf("argv[%i]: \"%s\"\n", i, argv[i]);

    return 0;
}
