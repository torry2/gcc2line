#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void line( const char* file )
{
	FILE * fp;
	char c;

	char *string;
	long size;

	fp = fopen(file, "r");
	if ( fp == NULL) { puts("gcc2line: could not open file"); exit(1); }

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);

	string = (char*) malloc(size + 69);
	if ( string == NULL ) { puts("gcc2line: malloc failed"); exit(1); }

	string[size] = '\0';	

	while ((c = fgetc(fp)) != EOF) 
	{

	char cc[2] = {c, '\0'};

	char tab[] = "\\t";
        char new[] = "\\n";
        char dubble[] = "\"";
        char single[] = "\\'";
	char esc[] = "\\";


		switch (c)
		{
			case '\t':
				strcat(string, tab);
				break;
			case '\n':
				strcat(string, new);
				break;
			case '"':
				strcat(string, dubble);
				break;
			case '\'':
				strcat(string, single);
				break;
			case '\\':
				strcat(string, esc);
				break;
			default:
				strcat(string, cc);
				break;
		}
	}
	fclose(fp);

	const char* pstring = strdup(string);
	free(string);

	const char* filename = strdup(file);
        char* extension = strrchr(filename, '.');
        if ( extension != NULL ) { *extension = '\0'; }

	printf("printf \'%s\' | gcc -x c -O -Wall -o %s - && ./%s ; rm %s\n", pstring, filename, filename, filename);

}

void usage() { puts("gcc2line: not enough arguments"); exit(0); }

int main(int argc, char* argv[])
{
	if ( argc != 2 ) { usage(); }
	line(argv[1]);
	return 0;
}
