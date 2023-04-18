#include <stdio.h>
#define COLLEEN "#include <stdio.h>%2$c#define COLLEEN %3$c%1$s%3$c%2$c#define GRACE int main() {FILE *f = fopen(%3$cGrace_kid.c%3$c, %3$cw%3$c); if (!f) return 1; fprintf(f, COLLEEN, COLLEEN, 10, 34); fclose(f);}%2$c/*%2$c	This program will print its own source when run.%2$c*/%2$c%2$cGRACE"
#define GRACE int main() {FILE *f = fopen("Grace_kid.c", "w"); if (!f) return 1; fprintf(f, COLLEEN, COLLEEN, 10, 34); fclose(f);}
/*
	This program will print its own source when run.
*/

GRACE