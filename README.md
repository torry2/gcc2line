# gcc2line
A C program to turn C programs into GCC "one liners"

```
WARNING: Program is not complete and may encounter parsing issues.
```

### Why?
- Python has one liners and so can C

## Compiling: (with GCC)
```bash
$ gcc ggc2line.c -o gcc2line
```

## Usage: (Example)
```bash
$ cat hello.c
#include <stdio.h>

int main() {
  printf("i <3 C");
  return 0;
}
$ ./gcc2line hello.c
printf '#include <stdio.h>\n\nint main() {\n\tprintf("i <3 C");\n\treturn 0;\n}\n\n' | gcc -x c -O -Wall -o hello - && ./hello ; rm hello
$ printf '#include <stdio.h>\n\nint main() {\n\tprintf("i <3 C");\n\treturn 0;\n}\n\n' | gcc -x c -O -Wall -o hello - && ./hello ; rm hello
$ i <3 C%  
```
