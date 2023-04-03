#include <stdio.h>

int main(int c, char **args)
{
	// Checks if a deck is given
	if (c < 2)
		return (printf("0\n"), 0);

	// Adds non-AS values
	size_t v = 0, a = 0;
	for (size_t j = 1; j < c; j++)
	{
		char *l = args[j];
		for (size_t i = 0; l[i]; i++)
		{
			if (l[i] >= '2' && l[i] <= '9')
				v += l[i] - '0';
			else if (l[i] == 'T' || l[i] == 'J' || l[i] == 'Q'
				|| l[i] == 'D' || l[i] == 'K' || l[i] == 'R')
				v += 10;
			else if (l[i] == 'A')
				a++;
			else
				return (printf("It contains a non-valid character: [%c]\n", l[i]), 1);
		}
	}

	// Adds the AS values
	while (a)
	{
		if (v + a >= 21 || v + 11 >= 21)
		{
			v += a;
			break;
		}
		v += 11;
		a--;
	}

	// Output the results
	if (v == 21)
		printf("Blackjack!\n");
	else
		printf("%zu\n", v);
	return 0;
}
