/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - AvajLauncher.java               */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:38:09 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose;

import java.io.File;

import dev.blankrose.exceptions.ArgumentsException;
import dev.blankrose.exceptions.ScenarioException;
import dev.blankrose.simulation.Logging;
import dev.blankrose.simulation.Parser;
import dev.blankrose.simulation.Simulation;
import dev.blankrose.weather.WeatherTower;

/**
 * Avaj Launcher
 * <p>
 * Java software that simulates an aircraft simulation program based on any given
 * scenario file. Each aircraft provided in the scenario file will be simulated
 * for a given lifetime or until all aircrafts have landed.
 * 
 * @apiNote Written in Java 17 (LTS)
 * @version 1.0.0
 * */
public class AvajLauncher {

	private static final Logging LOGGER = Logging.getInstance();
	private static final Parser PARSER = Parser.getInstance();
	private static final Simulation RUNTIME = Simulation.getInstance();

	public static void main(String[] args) {
		try {
			LOGGER.info("Reading arguments..");
			File file = PARSER.retrieveFile(args);
			LOGGER.info("Reading scenario located at \"" + file.getPath() + "\"..");
			WeatherTower tower = PARSER.readScenario(file);
			RUNTIME.startSimulation(tower);
		} catch (ArgumentsException exception) {
			LOGGER.error("Args Error: " + exception.getMessage(), 1);
		} catch (ScenarioException exception) {
			LOGGER.error("File Error: " + exception.getMessage(), 2);
		}
	}

}
