#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COLLEEN "#include <stdio.h>%2$c#include <string.h>%2$c#include <stdlib.h>%2$c%2$c#define COLLEEN %3$c%1$s%3$c%2$c%2$c#define SALLY(x) %4$c%2$cint main()%4$c%2$c{%4$c%2$c	if (x <= 0) return 0;%4$c%2$c	char s[strlen(%3$cSully_XX.c%3$c) + 1], cmd[1000], o[strlen(%3$cSully_XX%3$c)];%4$c%2$c	sprintf(o, %3$cSully_%5$cd%3$c, x);%4$c%2$c	sprintf(s, %3$cSully_%5$cd.c%3$c, x);%4$c%2$c	FILE *f = fopen(s, %3$cw%3$c);%4$c%2$c	if (!f) return 1;%4$c%2$c	fprintf(f, COLLEEN, COLLEEN, 10, 34, 92, 37, x - 1);%4$c%2$c	fclose(f);%4$c%2$c	sprintf(cmd, %3$cgcc %5$cs -o %5$cs && ./%5$cs%3$c, s, o, o);%4$c%2$c	system(cmd);%4$c%2$c}%2$c%2$cSALLY(%6$d)"

#define SALLY(x) \
int main()\
{\
	if (x <= 0) return 0;\
	char s[strlen("Sully_XX.c") + 1], cmd[1000], o[strlen("Sully_XX")];\
	sprintf(o, "Sully_%d", x);\
	sprintf(s, "Sully_%d.c", x);\
	FILE *f = fopen(s, "w");\
	if (!f) return 1;\
	fprintf(f, COLLEEN, COLLEEN, 10, 34, 92, 37, x - 1);\
	fclose(f);\
	sprintf(cmd, "gcc %s -o %s && ./%s", s, o, o);\
	system(cmd);\
}

SALLY(5)