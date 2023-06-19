/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - JetPlane.java                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 19:01:39 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.aircrafts;

import dev.blankrose.exceptions.CoordinatesException;
import dev.blankrose.simulation.Coordinates;
import dev.blankrose.simulation.Logging;

/**
 * JetPlane specializations of Aircraft.
 * */
public class JetPlane extends Aircraft {

	private static final Logging LOGGER = Logging.getInstance();

	public JetPlane(long p_id, String p_name, Coordinates p_coordinates) {
		super(p_id, p_name, p_coordinates);
	}

	/**
	 * Updates the coordinates depending on the current weather
	 * at given location (provided by WeatherTower):
	 * 
	 * <ul>
	 * <p> SUN - Latitude increases with 10, Height increases with 2
	 * <p> RAIN - Latitude increases with 5
	 * <p> FOG - Latitude increases with 1
	 * <p> SNOW - Height decreases with 7
	 * </ul>
	 */
	@Override
	public void updateConditions() {
		final String weather = weatherTower.getWeather(coordinates);

		try {
			switch (weather.toUpperCase()) {
				case "SUN":
					LOGGER.tower_log(this, "What a nice day to SPEED through the skies!");
					coordinates.moveLatitude(10);
					coordinates.moveHeight(2);
					break;
				case "RAIN":
					LOGGER.tower_log(this, "Rainy day... Oh Well!");
					coordinates.moveLatitude(5);
					break;
				case "FOG":
					LOGGER.tower_log(this, "It's hard to see through this fog...");
					coordinates.moveLatitude(1);
					break;
				case "SNOW":
					LOGGER.tower_log(this, "I need to land... NOW!");
					coordinates.moveHeight(-7);
					break;
				default:
					break;
			}
		} catch (CoordinatesException exception) {}
	}

}
