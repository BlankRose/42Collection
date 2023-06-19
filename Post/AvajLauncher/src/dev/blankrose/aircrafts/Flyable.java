/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Flyable.java                    */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:58:11 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.aircrafts;

import dev.blankrose.weather.WeatherTower;

/**
 * Flyable
 * <p>
 * Abstract class to be inherited by all flying objects. It will provide
 * the basic methods to register and unregister to a tower, and to update
 * the conditions of the aircraft.
 * */
public abstract class Flyable {
	
	protected WeatherTower weatherTower = null;

	public abstract void updateConditions();
	public abstract String getLoggingBase();
	public abstract boolean onGround();

	public void registerTower(WeatherTower p_tower) {
		p_tower.register(this);
		weatherTower = p_tower;
	}

	public void unregisterTower() {
		weatherTower.unregister(this);
		weatherTower = null;
	}

}
