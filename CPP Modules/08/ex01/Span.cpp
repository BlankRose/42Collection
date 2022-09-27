/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Span.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 23:55:20 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Span.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Span::Span()
{
	this->values = std::vector<int>();
	this->limit = 1;
}

Span::Span(const size_t &n)
{
	this->values = std::vector<int>();
	this->limit = n;
}

Span::Span(const Span &s)
{
	this->values = std::vector<int>(s.values);
	this->limit = s.limit;
}

Span::~Span() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Span		&Span::operator=(const Span &s)
{
	this->values = s.values;
	this->limit = s.limit;
	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

std::vector<int>	Span::getValues(void)
{
	return this->values;
}

void		Span::addNumber(int nb)
{
	if (this->values.size() >= this->limit)
		throw MaxEntries();
	this->values.push_back(nb);
}

int		Span::shortestSpan(void)
{
	if (this->values.size() < 2)
		throw LowEntries();

	int					res = __INT_MAX__;
	std::vector<int>	tmp(this->values);
	sort(tmp.begin(), tmp.end());

	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
		if (*(it + 1) - *it < res) res = *(it + 1) - *it;
	return res;
}

int		Span::longestSpan(void)
{
	if (this->values.size() < 2)
		throw LowEntries();

	std::vector<int>	tmp(this->values);
	sort(tmp.begin(), tmp.end());

	return (*(tmp.end() - 1) - *(tmp.begin()));
}

void	Span::addNumberIterator(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->values.size() >= this->limit)
		throw MaxEntries();

	std::vector<int>	tmp(begin, end);
	if (this->limit - this->values.size() < tmp.size())
		throw NotEnoughSpace();

	copy(tmp.begin(), tmp.end(), std::back_inserter(this->values));
}
