/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   LibASM - main.c                                 */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Apr 13 14:44:49 CEST 2023     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "tools.h"

int		main(int c, char **args)
{
	//////////////////////////////
	//
	//     MANDATORY PART
	//

	// TEST A: Read & Write
	if (c > 1) test_in_out(args[1]);
	else test_in_out(0x00);
	// TEST B: Length & Compare
	test_status("Cakesftyvjhvyicygy", "Cake");
	// TEST C: Copy & Duplicate
	test_clone("Hello World!", "Bruh!");

	//////////////////////////////
	//
	//     BONUS PART
	//

	// TEST A: List Insert & Size
	t_list	*lst = test_insert();
	// TEST B: List Remove
	test_destroy(&lst);
	// TEST C: Atoi Base
	test_atoi();
}
