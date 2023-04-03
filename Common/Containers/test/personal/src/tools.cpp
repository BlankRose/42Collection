/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - tools.cpp                       */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Nov 12 15:09:22 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "test.hpp"

std::ostream		&operator<<(std::ostream &o, const Chrono &t)
	{ o << t.elapsed() << "ms"; return o; }
