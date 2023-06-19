/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - WeatherProvider.java            */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:16:06 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.weather;

import java.util.Random;
import dev.blankrose.simulation.Coordinates;
import dev.blankrose.simulation.Logging;

/**
 * WeatherProvider
 * <p>
 * Singleton class which handles the weather by generating a random weather
 * for each coordinates and also provides the weather for any given coordinates.
 * */
public class WeatherProvider {

	private static final Logging LOGGER = Logging.getInstance();

	private static WeatherProvider instance = null;
	private static final int WRAP_WIDTH = 1000;
	private static final int WRAP_HEIGHT = 1000;
	private static final int LAYER_SIZE = WRAP_WIDTH * WRAP_HEIGHT;
	private String[] weather = null;

	private WeatherProvider() {
		LOGGER.info("Generating weather...");

		weather = new String[LAYER_SIZE * 100];
		final Random RNG = new Random();
		final String[] all_weathers = {"SUN", "FOG", "RAIN", "SNOW"};
		final int total_weathers = all_weathers.length;

		for (int x = 0; x < WRAP_WIDTH; x++)
			for (int z = 0; z < WRAP_HEIGHT; z++)
				for (int y = 0; y < 100; y++)
					weather[x * WRAP_HEIGHT + z + y * LAYER_SIZE] =
						all_weathers[RNG.nextInt(total_weathers)];

		LOGGER.info("Weather generated.");
	}

	static public WeatherProvider getInstance() {
		if (instance == null) {
			instance = new WeatherProvider();
		}
		return instance;
	}

	public String getCurrentWeather(Coordinates p_coordinates) {
		try {
			final int X = p_coordinates.getLongitude() % WRAP_WIDTH;
			final int Z = p_coordinates.getLatitude() % WRAP_HEIGHT;
			final int Y = p_coordinates.getHeight() - 1;
			return weather[X * WRAP_HEIGHT + Z + Y * LAYER_SIZE];
		} catch (Exception exception) {
			return "SUN";
		}
	}

}
