#include <stdlib.h>
#include <stdio.h>

void starwalker(int current, int depth)
{
	if (current > depth)
		return;
    unsigned max_len = depth * 4 + 1;
	unsigned cur_len = (depth - current + 1) * 4 + 1;


	for (int i = 0; i < current - 1; ++i)
		printf("* ");
	for (int i = 0; i < cur_len; ++i)
		printf("*");
	for (int i = 0; i < current - 1; ++i)
		printf(" *");
	printf("\n");

	for (int i = 0; i < current * 2; ++i)
		printf("* ");
	printf("\n");

	if (current == depth)
	{
		for (int i = 0; i < depth * 2 + 1; ++i)
			printf("* ");
		printf("\n");
	}
	starwalker(current + 1, depth);

	for (int i = 0; i < current * 2; ++i)
		printf("* ");
	printf("\n");

	for (int i = 0; i < current - 1; ++i)
		printf("* ");
	for (int i = 0; i < cur_len; ++i)
		printf("*");
	for (int i = 0; i < current - 1; ++i)
		printf(" *");
	printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return printf("42\n");
    int depth = atoi(argv[1]);
    if (depth < 2)
        return printf("42\n");
    else
        starwalker(1, depth - 1);
}