/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - AircraftFactory.java            */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:55:20 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.aircrafts;

import java.security.InvalidParameterException;
import dev.blankrose.simulation.Coordinates;

/**
 * AircraftFactory
 * <p>
 * Factory to create aircrafts on request with the given parameters. It will
 * also give a unique id to each aircraft.
 * */
public class AircraftFactory {

	private static AircraftFactory instance = null;
	private long lastid;

	private AircraftFactory() {
		lastid = 0;
	}

	static public AircraftFactory getInstance() {
		if (instance == null) {
			instance = new AircraftFactory();
		}
		return instance;
	}

	public Flyable newAircraft(String p_type, String p_name, Coordinates p_coordinates) {
		Flyable aircraft = null;

		switch (p_type.toLowerCase()) {
			case ("helicopter"):
				aircraft = new Helicopter(lastid, p_name, p_coordinates);
				break;
			case ("jetplane"):
				aircraft = new JetPlane(lastid, p_name, p_coordinates);
				break;
			case ("baloon"):
				aircraft = new Baloon(lastid, p_name, p_coordinates);
				break;
			default:
				throw new InvalidParameterException("Provided type (" + p_type + ") is not valid!");
		}

		lastid++;
		return aircraft;
	}

}
