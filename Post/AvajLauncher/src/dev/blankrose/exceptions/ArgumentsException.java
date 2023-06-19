/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - ArgumentsException.java         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: sam. 17 juin 2023 19:51:59 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.exceptions;

public class ArgumentsException extends Exception {

	public ArgumentsException() {
		super("Arguments are invalid!");
	}

	public ArgumentsException(String reason) {
		super(reason);
	}

}