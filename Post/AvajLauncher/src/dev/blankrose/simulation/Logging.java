/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Logging.java                    */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:53:19 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.simulation;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import dev.blankrose.aircrafts.Flyable;

/**
 * Logging
 * <p>
 * Singleton class to manage all of the logs of the simulation. It will write
 * the simulation's result in a file and the debug logs in the standard output.
 * */
public class Logging {

	private static Logging instance = null;
	private static final String OUTPUT = "simulation.txt";

	private File file;
	private FileWriter writer;

	private Logging() {
		try {
			file = new File(OUTPUT);
			if (file.exists()) {
				file.delete();
			}

			file.createNewFile();
			writer = new FileWriter(file);
		} catch (IOException exception) {
			error("File Error: Unable to create file " + OUTPUT);
		}
	}

	public static Logging getInstance() {
		if (instance == null) {
			instance = new Logging();
		}
		return instance;
	}

	public void file_log(String p_message) {
		try {
			writer.write(p_message + '\n');
			writer.flush();
		} catch (IOException exception) {
			error("File Error: Unable to write to file " + OUTPUT);
		}
	}

	public void tower_log(Flyable p_entity, String p_message) {
		try {
			writer.write(p_entity.getLoggingBase() + ' ' + p_message + '\n');
			writer.flush();
		} catch (IOException exception) {
			error("File Error: Unable to write to file " + OUTPUT, 4);
		}
	}

	public void info(String p_message) {
		System.out.println("[avaj-launcher][INFO] " + p_message);
	}

	public void error(String p_message) {
		System.out.println("[avaj-launcher][ERROR] " + p_message);
		System.exit(-1);
	}

	public void error(String p_message, int p_code) {
		System.out.println("[avaj-launcher][ERROR] " + p_message);
		System.exit(p_code);
	}

}
