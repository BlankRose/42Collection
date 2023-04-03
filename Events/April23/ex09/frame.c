#include <stdio.h>
#include <ctype.h>

void print_tops(size_t size)
{
	for (size_t i = 0; i < size + 4; i++)
		putchar('*');
	putchar('\n');
}

int main(int c, char **args)
{
	// Do nothing if no string is provided
	if (c < 2)
		return 0;

	// Get max word length
	size_t max = 0;
	for (size_t j = 1; j < c; j++) // Loop on each ARGS
	{
		char *l = args[j];
		for (size_t i = 0, t = 0; l[i]; t = 0) // Loop till end of STRING
		{
			while (l[i] && isspace(l[i]))
				i++;
			while (l[i] && !isspace(l[i]))
				i++, t++;
			max = max > t ? max : t;
		}
	}

	// Print out frame
	print_tops(max);
	for (size_t j = 1; j < c; j++) // Loop on each ARGS
	{
		char *l = args[j];
		for (size_t i = 0, t = 0; l[i]; t = 0) // Loop till end of STRING
		{
			while (l[i] && isspace(l[i])) // Skips spaces
				i++;
			if (l[i])
			{
				printf("* ");
				while (l[i] && !isspace(l[i])) // Fill with word and with spaces the word len < max word length
				{
					putchar(l[i++]), t++;
					while ((!l[i] || (l[i] && isspace(l[i]))) && t++ < max)
						putchar(' ');
				}
				printf(" *\n");
			}
		}
	}
	print_tops(max);
}