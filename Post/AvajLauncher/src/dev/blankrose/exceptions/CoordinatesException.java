/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - CoordinatesException.java       */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: sam. 17 juin 2023 17:54:56 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.exceptions;

public class CoordinatesException extends Exception {

	public CoordinatesException() {
		super("An error occured while handling coordinates!");
	}

	public CoordinatesException(String reason) {
		super(reason);
	}

}
