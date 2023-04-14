/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   LibASM - mandatory.c                            */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Feb 14 00:42:13 CET 2023      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "tools.h"

static void		print_diff(const char *a, const char *b)
{
	ft_write(1, "\nIn: ", 5);
	ft_write(1, a, ft_strlen(a));
	ft_write(1, "\nOut: ", 6);
	ft_write(1, b, ft_strlen(b));
	ft_write(1, "\n", 1);
}

void	test_in_out(char *s)
{
	char	b[1001];

	// Test for valid inputs
	if (s)
	{
		ft_write(1, "Argument test:\n", 16);
		ft_write(1, s, ft_strlen(s));
	}
	else
	{
		ft_write(1, "Input test:\n", 13);
		ft_write(1, b, ft_read(0, b, 1000));
	}

	// Test for errors
	int		fd = -1, bytes = 1;
	void *	buffer = "";
	int		error = 0, cmperrno = 0;

	error = write(fd, buffer, bytes);
	cmperrno = errno;
	errno = 0;

	printf("\nParams: %d, \"%s\", %d\n\
VALUE = %d ( = %d ), ERRNO = %d ( = %d )\n\n",
		fd, buffer, bytes,
		ft_write(fd, buffer, bytes), error,
		errno, cmperrno
	);
}

void	test_status(char *s1, char *s2)
{
	printf("S1 = %s\nS2 = %s\nLib: %d\nSTD: %d\n", s1, s2,
		ft_strcmp(s1, s2),
		strcmp(s1, s2)
	);

	printf("\nS1 = %s\nLib: %zu\nSTD: %zu\n", s1,
		ft_strlen(s1),
		strlen(s1)
	);
}

void	test_clone(char *s1, char *s2)
{
	char *	d = 0x00;

	d = ft_strdup(s1);
	if (!d) return;
	print_diff(s1, d);

	d = ft_strcpy(d, s2);
	print_diff(s2, d);
	free(d);
}