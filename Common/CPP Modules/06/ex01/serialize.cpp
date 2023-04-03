/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - serialize.cpp                     */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 17:49:12 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "header.hpp"

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t> (ptr);
}

Data*		deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*> (raw);
}