/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - vector.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon Nov 14 12:37:33 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "test.hpp"
#define TEST_TYPE	int


void	test_vector(void)
{
	Chrono					std_begin,	ft_begin;
	Chrono::time_type		std_end,	ft_end;



	// DECLARATION
	NEW_ENTRY(31, "Starting Vectors")
	TEST_TYPE arr[] = {13, 56, 18, 97};
	// STL
	TIME_START(std_begin)
	std::vector<TEST_TYPE> origin(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	PRINT("STL", origin)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	ft::vector<TEST_TYPE> remake(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	PRINT("FT ", remake)
	TIME_FINISH(ft_end, ft_begin)
	// TIME
	PRINTTIME(31, std_end, ft_end)



	// ASSIGNEMENT
	NEW_ENTRY(31, "Assign(from Vector(1, 3, 5, 7, 42, 97, 34, 65, 0, 45, 9, 94))")
	TEST_TYPE arr2[] = {1, 3, 5, 7, 42, 97, 34, 65, 0, 45, 9, 94};
	std::vector<TEST_TYPE> alt(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));
	// STL
	TIME_START(std_begin)
	origin.assign(alt.begin(), alt.end());
	PRINT("STL", alt)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	remake.assign(alt.begin(), alt.end());
	PRINT("FT ", remake)
	TIME_FINISH(ft_end, ft_begin);
	// TIME
	PRINTTIME(31, std_end, ft_end)



	// PUSHING BACK
	NEW_ENTRY(31, "Push_Back(13, 21, 100, 180)")
	// STL
	TIME_START(std_begin)
	origin.push_back(13);
	origin.push_back(21);
	origin.push_back(100);
	origin.push_back(180);
	PRINT("STL", origin)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	remake.push_back(13);
	remake.push_back(21);
	remake.push_back(100);
	remake.push_back(180);
	PRINT("FT ", remake)
	TIME_FINISH(ft_end, ft_begin)
	// TIME
	PRINTTIME(31, std_end, ft_end)



	// POP BACK
	NEW_ENTRY(31, "Pop_Back() x 2")
	// STL
	TIME_START(std_begin)
	origin.pop_back();
	origin.pop_back();
	PRINT("STL", origin)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	remake.pop_back();
	remake.pop_back();
	PRINT("FT ", remake)
	TIME_FINISH(ft_end, ft_begin)
	// TIME
	PRINTTIME(31, std_end, ft_end)



	// INSERTION
	NEW_ENTRY(31, "Insert(2 * 600 & itself)")
	// STL
	TIME_START(std_begin)
	origin.insert(origin.begin() + 2, 2, 600);
	origin.insert(origin.begin() + 2, origin.begin(), origin.end());
	PRINT("STL", origin)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	remake.insert(remake.begin() + 2, 2, 600);
	remake.insert(remake.begin() + 2, remake.begin(), remake.end());
	PRINT("FT ", remake)
	TIME_FINISH(ft_end, ft_begin)
	// TIME
	PRINTTIME(31, std_end, ft_end)



	// COMPARAISONS
	NEW_ENTRY(31, "Vector Comparaisons")
	std::vector<TEST_TYPE>	cmp(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));
	ft::vector<TEST_TYPE>	dup(cmp.begin(), cmp.end());
	PRINT("COMPARE", cmp)
	// EQUAL
	CASUAL("Equal [==]")
	TIME_START(std_begin)
	SHOW("STL", cmp == origin)
	TIME_FINISH(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", dup == remake)
	TIME_FINISH(ft_end, ft_begin)
	// NOT EQUAL
	CASUAL("Not Equal [!=]")
	TIME_START(std_begin)
	SHOW("STL", cmp != origin)
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", dup != remake)
	TIME_ADD(ft_end, ft_begin)
	// SUPERIOR
	CASUAL("Superior [>]")
	TIME_START(std_begin)
	SHOW("STL", cmp > origin)
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", dup > remake)
	TIME_ADD(ft_end, ft_begin)
	// SUPERIOR OR EQUAL
	CASUAL("Superior or Equal [>=]")
	TIME_START(std_begin)
	SHOW("STL", cmp >= origin)
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", dup >= remake)
	TIME_ADD(ft_end, ft_begin)
	// INFERIOR
	CASUAL("Inferior [<]")
	TIME_START(std_begin)
	SHOW("STL", cmp < origin)
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", dup < remake)
	TIME_ADD(ft_end, ft_begin)
	// INFERIOR OR EQUAL
	CASUAL("Inferior or Equal [<=]")
	TIME_START(std_begin)
	SHOW("STL", cmp <= origin)
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", dup <= remake)
	TIME_ADD(ft_end, ft_begin)
	// TIME
	PRINTTIME(31, std_end, ft_end)

}