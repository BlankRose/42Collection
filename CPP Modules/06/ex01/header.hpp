/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - header.hpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 18:00:18 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __HEADER_HPP__
# define __HEADER_HPP__

#include <iostream>
#include <string>

typedef struct s_data{
	std::string	str;
	int			nb;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif