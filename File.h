#ifndef FILE_H
#define FILE_H

uint fileLen(const char *filePath)
{
    if(!filePath)
        panic("Cannot open NULL file path");
    File *f = fopen(filePath, "r");
    if(!f)
        panic("Could not open file: \"%s\"", filePath);
    int c = ' ';
    uint len = 0;
    while((c = fgetc(f)) != EOF)
        len++;
    fclose(f);
    return len;
}

char* fileReadText(const char *filePath)
{
    const uint len = fileLen(filePath);
    char *buf = calloc(len+1, sizeof(char));
    buf[len] = '\0';
    if(!filePath)
        panic("Cannot open NULL file path");
    File *f = fopen(filePath, "r");
    if(!f)
        panic("Could not open file: \"%s\"", filePath);
    int c = ' ';
    uint pos = 0;
    while((c = fgetc(f)) != EOF){
        buf[pos] = c;
        pos++;
    }
    fclose(f);
    if(c == EOF && pos != len)
        panic("Size mismatch");
    return buf;
}

bool fileWriteText(File *f, const char *text)
{
    if(!f || !text)
        return false;
    const st len = strlen(text);
    return fwrite(text, sizeof(char), len, f) == len;
}

File* fileOpenWriteText(const char *filePath, const char *text)
{
    File *f = fopen(filePath, "w");
    fwrite(text, sizeof(char), strlen(text), f);
    return f;
}

bool fileOutputWriteText(const char *filePath, const char *text)
{
    if(!filePath || !text)
        return false;
    File *f = fopen(filePath, "w");
    if(!f)
        return false;
    const bool ret = fileWriteText(f, text);
    if(fclose(f))
        return false;
    return ret;
}

#endif /* end of include guard: FILE_H */
