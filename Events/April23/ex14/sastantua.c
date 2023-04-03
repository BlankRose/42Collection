#include <stdio.h>
#include <stdlib.h>

#define ICON_DOOR '|'
#define ICON_WALL '*'
#define ICON_HANDLE '$'

int main(int c, char **args)
{
	// Retrieve the argument
	if (c < 2)
		return 0;
	size_t f = atoi(args[1]) > 0 ? atoi(args[1]) : 0;
	if (!f)
		return 0;

	// Find the total wide
	size_t w = 1;
	for (size_t cf = 1, s = 4; cf <= f;)
	{
		if (cf < f)
			w += s;
		w += 2 * (2 + cf++);
		if (cf % 2 && cf < f)
			s += 2;
	}

	// Print the pyramid
	for (size_t cf = 1, cw = 3; cf <= f;)
	{
		for (size_t s = 0, h = 2 + cf; s < h; s++, cw += 2)
		{
			// Put Air
			for (size_t i = 0, end = (w - cw) / 2; i < end; i++)
				putchar(' ');

			// Put Structure Body
			putchar('/');
			for (size_t i = 1, d = 1 + 2 * ((cf - 1) / 2); i < cw - 1; i++)
			{
				// Put Door
				if (cf == f && i >= (cw - d) / 2 && i < (cw + d) / 2 && 2 + cf - s <= d)
					if (d >= 5 && s == 2 + cf - d / 2 - 1 && i == (cw + d) / 2 - 2)
						putchar(ICON_HANDLE);
					else
						putchar(ICON_DOOR);

				// Put Wall
				else
					putchar(ICON_WALL);
			}
			printf("\\\n");
		}
		cw += 4 + 2 * ((++cf - 2) / 2);
	}
	return 0;
}
