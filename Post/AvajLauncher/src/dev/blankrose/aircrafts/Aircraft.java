/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Aircraft.java                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:57:02 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.aircrafts;

import dev.blankrose.simulation.Coordinates;

/**
 * Aircraft
 * <p>
 * Base of all aircrafts. Each aircraft has their own unique id, name
 * and coordinates.
 * */
public class Aircraft extends Flyable {

	protected long id;
	protected String name;
	protected Coordinates coordinates;

	protected Aircraft(long p_id, String p_name, Coordinates p_coordinates) {
		id = p_id;
		name = p_name;
		coordinates = p_coordinates;
	}

	@Override
	public void updateConditions() {}

	@Override
	public String getLoggingBase() {
		return this.getClass().getSimpleName() + "#" + name + "(" + Long.toString(id) + ")";
	}

	@Override
	public boolean onGround() {
		return coordinates.getHeight() <= 0;
	}

}
