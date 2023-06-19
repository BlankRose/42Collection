/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - ScenarioException.java          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: dim. 18 juin 2023 11:10:47 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.exceptions;

public class ScenarioException extends Exception {

	public ScenarioException() {
		super("The content of the file is invalid!");
	}

	public ScenarioException(String reason) {
		super(reason);
	}

}
