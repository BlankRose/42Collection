/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  compare.c                                              */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 14, 2024 [01:26 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

// STRING LENGTH
size_t len(const char *s)
{
	if (!s)
		return 0;

	size_t i = 0;
	while (s[i])
		i++;
	return i;
}

size_t nlen(const long long n)
{
	unsigned long long  nb = n < 0 ? -n : n;
	size_t              i  = n < 0 ?  1 : 0;

	if (!n)
		return 1;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

// STRING COMPARE
int cmp(const char *a, const char *b, size_t n)
{
	if (!a && !b)
		return 1;
	if (!a || !b)
		return 0;

	size_t i = 0;
	while (i < n && a[i] && b[i])
	{
		if (a[i] != b[i])
			return 0;
		i++;
	}
	return a[i] == b[i];
}

// RAW MEMORY COPY
void copy(const void *s, void *d, size_t n)
{
	if (!s || !d)
		return;

	for (size_t i = 0; i < n; i++)
		((unsigned char *) d)[i] = ((unsigned char *) s)[i];
}

// RAW MEMORY DUPLICATION
char *mdup(const void *s, size_t n)
{
	if (!s)
		return NULL;

	void *d = malloc(n);
	if (!d)
		return NULL;

	copy(s, d, n);
	return d;
}

// STRING DUPLICATION
char *sdup(const char *s, size_t n)
{
	if (!s)
		return NULL;

	const size_t truesize = len(s);
	const size_t l = n > truesize ? truesize : n;

	char *d = malloc(l + 1 * sizeof(char));
	if (!d)
		return NULL;

	copy(s, d, l);
	d[l] = '\0';
	return d;
}

// STRING COMBINE
char *join(const char *a, const char *b)
{
	const size_t len_a = len(a);
	const size_t len_b = len(b);

	char *s = malloc(len_a + len_b + 1);
	if (!s)
		return NULL;

	copy(a, s, len_a);
	copy(b, &s[len_a], len_b);
	s[len_a + len_b] = '\0';

	return s;
}

size_t ulen(unsigned long long n)
{
	size_t  i = 0;

	if (!n)
		return 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return i;
}

void inplace_nb(char *buffer, const long long n)
{
	unsigned long long  nb;

	if (!n)
	{
		buffer[0] = '0';
		return;
	}
	if (n < 0)
	{
		*(buffer++) = '-';
		nb = -n;	
	}
	else
		nb = n;
	for (size_t i = ulen(nb); i > 0; i--)
	{
		buffer[i - 1] = (nb % 10) + '0';
		nb /= 10;
	}
}
