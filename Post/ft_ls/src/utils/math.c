/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  math.c                                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 13, 2024 [06:16 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

float ceiling(float value)
{
	const int round  = value;

	if (round != value)
		return round + 1;
	return round;
}

unsigned long long stoi(const char *str)
{
	unsigned long long  res = 0;
	unsigned int        i   = 0;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return res;
}
