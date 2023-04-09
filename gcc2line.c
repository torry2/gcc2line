// torry2 plagiarised or some shit ;p
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void line( char* file )
{
    FILE * fp;
    int c;

    fp = fopen(file, "r");
    if ( fp == NULL) { perror("gcc2line: could not open file"); exit(1); }
 
    fputs("printf '", stdout);
    while ((c = fgetc(fp)) != EOF) 
    {
        switch (c)
        {
            case '\t':
                fputs("\\t", stdout);
                break;
            case '\n':
                fputs("\\n", stdout);
                break;
            case '\'':
                fputs("\\'", stdout);
                break;
            case '\\':
                fputs("\\\\", stdout);
                break;
            default:
                putchar(c);
                break;
        }
    }
    fclose(fp);
    char* extension = strrchr(file, '.');
    if ( extension != NULL ) { *extension = '\0'; }
    fprintf(stdout, "' | gcc -x c -O -Wall -o %s - && ./%s ; rm %s\n", file, file, file);
}
 
void usage() { fputs("gcc2line: not enough arguments\n", stderr); exit(0); }
 
int main(int argc, char* argv[])
{
    if ( argc != 2 ) { usage(); }
    line(argv[1]);
    return 0;
}
