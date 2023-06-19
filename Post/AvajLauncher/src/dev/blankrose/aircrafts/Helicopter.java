/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Helicopter.java                 */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 19:00:51 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.aircrafts;

import dev.blankrose.exceptions.CoordinatesException;
import dev.blankrose.simulation.Coordinates;
import dev.blankrose.simulation.Logging;

/**
 * Helicopter specializations of Aircraft.
 * */
public class Helicopter extends Aircraft {

	private static final Logging LOGGER = Logging.getInstance();

	public Helicopter(long p_id, String p_name, Coordinates p_coordinates) {
		super(p_id, p_name, p_coordinates);
	}

	/**
	 * Updates the coordinates depending on the current weather
	 * at given location (provided by WeatherTower):
	 * 
	 * <ul>
	 * <p> SUN - Longitude increases with 10, Height increases with 2
	 * <p> RAIN - Longitude increases with 5
	 * <p> FOG - Longitude increases with 1
	 * <p> SNOW - Height decreases with 12
	 * </ul>
	 */
	@Override
	public void updateConditions() {
		final String weather = this.weatherTower.getWeather(this.coordinates);

		try {
			switch (weather.toUpperCase()) {
				case "SUN":
					coordinates.moveLongitude(10);
					coordinates.moveHeight(2);
					LOGGER.tower_log(this, "It's sunny! Time to fly~");
					break;
				case "RAIN":
					coordinates.moveLongitude(5);
					LOGGER.tower_log(this, "It's raining! Better watch out for lightning!");
					break;
				case "FOG":
					coordinates.moveLongitude(1);
					LOGGER.tower_log(this, "It's foggy! Better watch out for other aircrafts!");
					break;
				case "SNOW":
					coordinates.moveHeight(-12);
					LOGGER.tower_log(this, "It's snowing! We're gonna crash!");
					break;
				default:
					break;
			}
		} catch (CoordinatesException exception) {}
	}

}
