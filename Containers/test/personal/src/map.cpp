/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - map.cpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon Nov 14 12:37:51 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "test.hpp"
#define TEST_KEY	std::string
#define TEST_TYPE	int
#define TEST_PAIR	pair<TEST_KEY, TEST_TYPE>


void	test_map(void)
{
	Chrono					std_begin,	ft_begin;
	Chrono::time_type		std_end,	ft_end;



	// BASE FOR ITERATOR INSERTIONS
	std::vector<std::TEST_PAIR>		base;
	base.push_back(std::TEST_PAIR("MC", 64));
	base.push_back(std::TEST_PAIR("Error", 404));
	base.push_back(std::TEST_PAIR("MC", 15));
	base.push_back(std::TEST_PAIR("Funni", 69));
	base.push_back(std::TEST_PAIR("Hello", 456));
	base.push_back(std::TEST_PAIR("World", 1));
	base.push_back(std::TEST_PAIR("Power", 69));
	base.push_back(std::TEST_PAIR("Karen", -4864));
	base.push_back(std::TEST_PAIR("Why not?", 8146454));
	base.push_back(std::TEST_PAIR("Null", 0));
	// duplicates shouldn't be inserted by both STL and FT



	// DECLARATION
	NEW_ENTRY(32, "Starting Maps (init from Vector of Pairs)")
	// STL
	TIME_START(std_begin)
	std::map<TEST_KEY, TEST_TYPE>		origin(base.begin(), base.end());
	PRINT2("STL", origin)
	TIME_FINISH(std_end, std_begin)
	// FT
	TIME_START(ft_begin)
	ft::map<TEST_KEY, TEST_TYPE>		remake(base.begin(), base.end());
	PRINT2("FT ", remake)
	TIME_FINISH(ft_end, ft_begin)
	// TIME
	PRINTTIME(32, std_end, ft_end)



	// INSERTION
	NEW_ENTRY(32, "Insertion (Mulhouse = 42, Devil = 666, A = 65, Seq = 123456789, Karen = 0)")
	// STL
	TIME_START(std_begin)
	origin.insert(std::TEST_PAIR("Mulhouse", 42));
	origin.insert(std::TEST_PAIR("Devil", 666));
	origin.insert(std::TEST_PAIR("A", 65));
	origin.insert(std::TEST_PAIR("Seq", 123456789));
	origin.insert(std::TEST_PAIR("Karen", 0));
	TIME_FINISH(std_end, std_begin)
	PRINT2("STL", origin)
	// FT
	TIME_START(ft_begin)
	remake.insert(ft::TEST_PAIR("Mulhouse", 42));
	remake.insert(ft::TEST_PAIR("Devil", 666));
	remake.insert(std::TEST_PAIR("A", 65));
	remake.insert(std::TEST_PAIR("Seq", 123456789));
	remake.insert(std::TEST_PAIR("Karen", 0));
	PRINT2("FT ", remake)
	TIME_FINISH(ft_end, ft_begin)
	// TIME
	PRINTTIME(32, std_end, ft_end)



	// VALUE CHECK
	NEW_ENTRY(32, "Values Check")
	// SIZE
	CASUAL("Size")
	TIME_START(std_begin)
	SHOW("STL", origin.size())
	TIME_FINISH(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", remake.size())
	TIME_FINISH(ft_end, ft_begin)
	// MAX SIZE
	CASUAL("Max Size")
	TIME_START(std_begin)
	SHOW("STL", origin.max_size())
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", remake.max_size())
	TIME_ADD(ft_end, ft_begin)
	// TIME
	PRINTTIME(32, std_end, ft_end)



	// SEARCHING
	NEW_ENTRY(32, "Searcing across maps")
	// Valid Key
	CASUAL("Specific Key (Error)")
	TIME_START(std_begin)
	SHOW2("STL", *(origin.find("Error")))
	TIME_FINISH(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW2("FT ", *(remake.find("Error")))
	TIME_FINISH(ft_end, ft_begin)
	// Lower Bound
	TEST_KEY	toSearch("MC");
	CASUAL((std::string("Upper Bound (") + std::string(toSearch) + std::string(")")))
	TIME_START(std_begin)
	SHOW2("STL", *(origin.lower_bound(toSearch)))
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW2("FT ", *(remake.lower_bound(toSearch)))
	TIME_ADD(ft_end, ft_begin)
	// Upper Bound
	CASUAL((std::string("Upper Bound (") + std::string(toSearch) + std::string(")")))
	TIME_START(std_begin)
	SHOW2("STL", *(origin.upper_bound(toSearch)))
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW2("FT ", *(remake.upper_bound(toSearch)))
	TIME_ADD(ft_end, ft_begin)
	// Invalid Key
	CASUAL("Find invalid key")
	CASUAL("Condition: find() = end()")
	TIME_START(std_begin)
	SHOW("STL", origin.find("wbuipbwn") == origin.end())
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", remake.find("wbuipbwn") == remake.end())
	TIME_ADD(ft_end, ft_begin)
	// TIME
	PRINTTIME(32, std_end, ft_end)



	// VALUE COMPARE SUBCLASS
	NEW_ENTRY(32, "Value Compare")
	// Preparing test
	std::map<TEST_KEY, TEST_TYPE>::value_compare	s = origin.value_comp();
	ft::map<TEST_KEY, TEST_TYPE>::value_compare		f = remake.value_comp();
	std::TEST_PAIR	testA("Devil", 76), testB("Devil", 666), testC("Lmao", 4);
	TEST_KEY	testEntry("Devil");
	// TEST A
	CASUAL((std::string("With (") + std::string(testA.first) + std::string(" = ") + std::to_string(testA.second) + std::string(")")))
	TIME_START(std_begin)
	SHOW("STL", s(*(origin.lower_bound(testEntry)), testA))
	TIME_FINISH(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", f(*(remake.lower_bound(testEntry)), testA))
	TIME_FINISH(ft_end, ft_begin)
	// TEST B
	CASUAL((std::string("With (") + std::string(testB.first) + std::string(" = ") + std::to_string(testB.second) + std::string(")")))
	TIME_START(std_begin)
	SHOW("STL", s(*(origin.lower_bound(testEntry)), testB))
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", f(*(remake.lower_bound(testEntry)), testB))
	TIME_ADD(ft_end, ft_begin)
	// TEST C
	CASUAL((std::string("With (") + std::string(testC.first) + std::string(" = ") + std::to_string(testC.second) + std::string(")")))
	TIME_START(std_begin)
	SHOW("STL", s(*(origin.lower_bound(testEntry)), testC))
	TIME_ADD(std_end, std_begin)
	TIME_START(ft_begin)
	SHOW("FT ", f(*(remake.lower_bound(testEntry)), testC))
	TIME_ADD(ft_end, ft_begin)
	// TIME
	PRINTTIME(32, std_end, ft_end)



	// COMPARAISONS
	NEW_ENTRY(32, "Map Comparaisons")
	std::map<TEST_KEY, TEST_TYPE>	cmp(base.begin(), base.end());
	ft::map<TEST_KEY, TEST_TYPE>	dup(cmp.begin(), cmp.end());
	PRINT2("COMPARE", cmp)
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
	PRINTTIME(32, std_end, ft_end)

}