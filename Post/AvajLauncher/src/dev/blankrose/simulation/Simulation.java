/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Simulation.java                 */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:50:58 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.simulation;

import dev.blankrose.exceptions.ArgumentsException;
import dev.blankrose.weather.WeatherTower;

/**
 * Simulation
 * <p>
 * Singleton class to manage the aircrafts simulation and the duration of it.
 * Upon starting the simulation, the weather tower will change the weather
 * conditions and notify the aircrafts about it for the duration of the
 * simulation.
 * */
public class Simulation {

	private static final Logging LOGGER = Logging.getInstance();
	private static Simulation instance = null;
	private int counter;

	private Simulation() {
		counter = 0;
	}

	public static Simulation getInstance() {
		if (instance == null) {
			instance = new Simulation();
		}
		return instance;
	}

	public void setCounter(int p_counter) throws ArgumentsException {
		if (p_counter < 0) {
			throw new ArgumentsException("The duration of simulation cannot be set to negative!");
		}
		counter = p_counter;
	}

	public void startSimulation(WeatherTower tower) {
		LOGGER.info("Starting simulation for " + counter + " days.");
		for (int i = 0; i < counter; i++) {
			tower.changeWeather();
			if (tower.getObserversCount() == 0) {
				LOGGER.info("All aircrafts have landed! Finishing " + (counter - i) + " day(s) in advance!");
				return;
			}
		}
		LOGGER.info("Simulation finished!");
	}

}
