/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - UnexpectedException.java        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: sam. 17 juin 2023 19:40:41 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.exceptions;

public class UnexpectedException extends Exception {

	public UnexpectedException() {
		super("A function or method got called but was not expected to happen!");
	}

	public UnexpectedException(String reason) {
		super(reason);
	}

}
