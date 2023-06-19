/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Parser.java                     */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:51:45 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.simulation;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import dev.blankrose.aircrafts.AircraftFactory;
import dev.blankrose.exceptions.ArgumentsException;
import dev.blankrose.exceptions.CoordinatesException;
import dev.blankrose.exceptions.ScenarioException;
import dev.blankrose.weather.WeatherTower;

/**
 * Parser
 * <p>
 * Singleton class to parse the scenario file. It will read the file and create
 * the aircrafts and register them to the weather tower. It will also check for
 * errors in the scenario file.
 * */
public class Parser {

	private static final Simulation RUNTIME = Simulation.getInstance();
	private static final AircraftFactory FACTORY = AircraftFactory.getInstance();

	private static Parser instance = null;
	private Parser() {}

	public static Parser getInstance() {
		if (instance == null) {
			instance = new Parser();
		}
		return instance;
	}

	private String gotoNextValue(BufferedReader p_reader) throws IOException {
		String buffer = p_reader.readLine();

		while (buffer != null && buffer.isBlank())
			buffer = p_reader.readLine();
		return buffer;
	}

	private static final String FORMAT =
		"FORMAT = <Type: String> <Name: String> <Longitude: Positive Integer> <Latitude: Positive Integer> <Height: Integer between 0 and 100>";

	private ScenarioException createFormatException(String p_reason, int p_line) {
		return new ScenarioException(p_reason + " (Aircraft n*" + Integer.toString(p_line) + ")\n" + FORMAT);
	}

	public File retrieveFile(String[] p_args) throws ArgumentsException {

		// STEP A: Check the amount of arguments
		// (Must only has one, which must be a valid path to a scenario file)
		if (p_args.length < 1) {
			throw new ArgumentsException("Missing requiered argument: Path to scenario file!");
		} else if (p_args.length > 1) {
			throw new ArgumentsException("Too many arguments given! Only 1 is expected: Path to scenario file!");
		}

		// STEP B: Check if given path exists and is a file which is accessible
		// (Given files might be a folder or permissions-locked)
		File target = new File(p_args[0]);
		if (!target.exists() || !target.isFile()) {
			throw new ArgumentsException("Provided path does not exists or is not a file! (" + p_args[0] + ")");
		} else if (!target.canRead()) {
			throw new ArgumentsException("Cannot read the provided file " + p_args[0] + "!");
		}

		return target;
	}

	public WeatherTower readScenario(File p_file) throws ScenarioException {
		WeatherTower tower = new WeatherTower();
		try {
			BufferedReader reader = new BufferedReader(new FileReader(p_file));
			try {

				// STEP A: Retrieve simulation's duration
				// (how many weather changes there will be)
				String buffer = gotoNextValue(reader);
				if (buffer == null)
					throw new ScenarioException("The file is empty!");
				try {
					RUNTIME.setCounter(Integer.parseInt(buffer));
				} catch (NumberFormatException exception) {
					throw new ScenarioException("First line must be a valid positive integer! (Represents simulation's lifespan)");
				}

				// STEP B: Retrieve each aircrafts listed
				// (Format: <TYPE> <NAME> <LONGITUDE> <LATITUDE> <HEIGHT>)
				for (int i = 1; (buffer = gotoNextValue(reader)) != null; i++) {
					String[] sections = buffer.split(" ");

					if (sections.length != 5) {
						throw createFormatException("Each aircraft details must be composed of five elemements!", i);
					}

					try {
						FACTORY.newAircraft(
							sections[0], // First: TYPE
							sections[1], // Second: NAME
							new Coordinates(
								Integer.parseInt(sections[2]), // Third: LONGITUDE
								Integer.parseInt(sections[3]), // Fourth: LATITUDE
								Integer.parseInt(sections[4])) // Fifth: HEIGHT
						).registerTower(tower);
					} catch (NumberFormatException exception) {
						throw createFormatException("Provided coordinates are not valid integers!", i);
					} catch (CoordinatesException exception) {
						throw createFormatException("Provided coordinates must be positive integers!", i);
					}
				}

				// STEP C: Close reader and returns tower
				// (If something went wrong, it goes into exceptions handlers)
				reader.close();
				return tower;

			} catch (Exception exception) {
				try {
					reader.close();
				} catch (IOException _ignore) {}
				throw new ScenarioException(exception.getMessage());
			}
		} catch (FileNotFoundException exception) {
			throw new ScenarioException("File failed to open!");
		}
	}

}