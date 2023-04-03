/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - stack.cpp                       */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon Nov 14 12:38:59 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "test.hpp"

#define TEST_TYPE		int
#define TEST_CONTAINER	std::vector<TEST_TYPE>


// Mutant Stack from CPP Module 08
// used by tests for easier printing contents with iterators
template<typename Type, typename Container>
class MutantStack : public Container
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<Type, Container>& src) { *this = src; }
	MutantStack<Type, Container>& operator=(const MutantStack<Type, Container>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename Container::container_type::iterator			iterator;
	typedef typename Container::container_type::reverse_iterator	reverse_iterator;

	iterator			begin() { return this->c.begin(); }
	iterator			end() { return this->c.end(); }

	reverse_iterator	rbegin() { return this->c.rbegin(); }
	reverse_iterator	rend() { return this->c.rend(); }
};


void	test_stack(void)
{
	Chrono					std_begin,	ft_begin;
	Chrono::time_type		std_end,	ft_end;



	// DECLARATIONS
	// Left non-mutant in case I need to proof that they are not iteratable
	NEW_ENTRY(33, "Starting Stack")
	// STL
	TIME_START(std_begin)
	MutantStack<TEST_TYPE, std::stack<TEST_TYPE, TEST_CONTAINER> >	origin;
//	std::stack<TEST_TYPE, TEST_CONTAINER>							origin;
	PRINT("STL", origin)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	MutantStack<TEST_TYPE, ft::stack<TEST_TYPE, TEST_CONTAINER> >	remake;
//	ft::stack<TEST_TYPE, TEST_CONTAINER>							remake;
	PRINT("FT ", remake)
	TIME_FINISH(ft_end, ft_begin);
	// TIME
	PRINTTIME(33, std_end, ft_end)



	// PUSHING ELEMENTS
	NEW_ENTRY(33, "Pushing values")
	TEST_TYPE	arr[] = {515, -79, 67, -45648, 0, 48, 153};
	std::vector<TEST_TYPE> a(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	// STL
	TIME_START(std_begin)
	for (std::vector<TEST_TYPE>::iterator it = a.begin(); it != a.end(); it++)
		origin.push(*it);
	PRINT("STL", origin)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	for (std::vector<TEST_TYPE>::iterator it = a.begin(); it != a.end(); it++)
		remake.push(*it);
	PRINT("FT ", remake)
	TIME_FINISH(ft_end, ft_begin);
	// TIME
	PRINTTIME(33, std_end, ft_end)



	// POP ELEMENTS
	NEW_ENTRY(33, "Pop out values (3 times)")
	size_t		count = 3;
	// STL
	TIME_START(std_begin)
	for (size_t i = 0; i < count; i++)
		origin.pop();
	PRINT("STL", origin)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	for (size_t i = 0; i < count; i++)
		remake.pop();
	PRINT("FT ", remake)
	TIME_FINISH(ft_end, ft_begin);
	// TIME
	PRINTTIME(33, std_end, ft_end)



	// TOP ELEMENT
	NEW_ENTRY(33, "Top value")
	TIME_START(std_begin)
	SHOW("STL", origin.top())
	TIME_FINISH(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", remake.top())
	TIME_FINISH(ft_end, ft_begin);
	// TIME
	PRINTTIME(33, std_end, ft_end)



	// STACK SIZE
	NEW_ENTRY(33, "Size of Stack")
	TIME_START(std_begin)
	SHOW("STL", origin.size())
	TIME_FINISH(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", remake.size())
	TIME_FINISH(ft_end, ft_begin);
	// TIME
	PRINTTIME(33, std_end, ft_end)

}