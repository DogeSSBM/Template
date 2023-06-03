#include "Includes.h"

int main(int argc, char **argv)
{
    assertExprMsg(argc == 2, "Usage: %s <SourceFile>", argv[0]);
    char *source = fileReadText(argv[1]);
    printf("source: %s\n", source);
    return 0;
}
