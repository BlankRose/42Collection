/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Baloon.java                     */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 19:02:06 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.aircrafts;

import dev.blankrose.exceptions.CoordinatesException;
import dev.blankrose.simulation.Coordinates;
import dev.blankrose.simulation.Logging;

/**
 * Baloon specializations of Aircraft.
 * */
public class Baloon extends Aircraft {

	private static final Logging LOGGER = Logging.getInstance();

	public Baloon(long p_id, String p_name, Coordinates p_coordinates) {
		super(p_id, p_name, p_coordinates);
	}

	/**
	 * Updates the coordinates depending on the current weather
	 * at given location (provided by WeatherTower):
	 * 
	 * <ul>
	 * <p> SUN - Longitude increases with 2, Height increases with 4
	 * <p> RAIN - Height decreases with 5
	 * <p> FOG - Height decreases with 3
	 * <p> SNOW - Height decreases with 15
	 * </ul>
	 */
	@Override
	public void updateConditions() {
		final String weather = weatherTower.getWeather(coordinates);

		try {
			switch (weather.toUpperCase()) {
				case "SUN":
					coordinates.moveLongitude(2);
					coordinates.moveHeight(4);
					LOGGER.tower_log(this, "We can relax now, it's sunny!");
					break;
				case "RAIN":
					coordinates.moveHeight(-5);
					LOGGER.tower_log(this, "Not a great day for flying... We're gonna get wet!");
					break;
				case "FOG":
					coordinates.moveHeight(-3);
					LOGGER.tower_log(this, "With such fog, we can't see the birds...");
					break;
				case "SNOW":
					coordinates.moveHeight(-15);
					LOGGER.tower_log(this, "Nope, I'm out! I'm not flying in this cold weather!");
					break;
				default:
					break;
			}
		} catch (CoordinatesException exception) {}
	}

}
