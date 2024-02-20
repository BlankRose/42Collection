#include <stdio.h>
#define COLLEEN "#include <stdio.h>%2$c#define COLLEEN %3$c%1$s%3$c%2$c%2$cvoid out()%2$c{%2$c	printf(COLLEEN, COLLEEN, 10, 34);%2$c}%2$c%2$cint main()%2$c{%2$c	out();%2$c/*%2$c	This program will print its own source when run.%2$c*/%2$c}%2$c/*%2$c	This program will print its own source when run.%2$c*/%2$c"

void out()
{
	printf(COLLEEN, COLLEEN, 10, 34);
}

int main()
{
	out();
/*
	This program will print its own source when run.
*/
}
/*
	This program will print its own source when run.
*/
