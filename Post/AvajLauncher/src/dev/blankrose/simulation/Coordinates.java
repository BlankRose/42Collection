/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Coordinates.java                */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:54:14 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.simulation;

import dev.blankrose.exceptions.CoordinatesException;

/**
 * Coordinates
 * <p>
 * Defintion of the coordinates for various objects. It will be used to set the
 * position of the aircrafts and define the weather for each position.
 * */
public class Coordinates {

	private static final int MAX_HEIGHT = 100;

	private int longitude;
	private int latitude;
	private int height;

	Coordinates(int p_longitude, int p_latitude, int p_height) throws CoordinatesException {
		if (p_longitude < 0 || p_latitude < 0 || p_height < 0) {
			throw new CoordinatesException("Given arguments for constructors are out of bounds!");
		}

		longitude = p_longitude;
		latitude = p_latitude;
		height = p_height;

		if (p_height > MAX_HEIGHT) {
			height = MAX_HEIGHT;
		}
	}

	public int getLongitude() {
		return longitude;
	}

	public int getLatitude() {
		return latitude;
	}

	public int getHeight() {
		return height;
	}

	public void moveLongitude(int p_offset) throws CoordinatesException {
		if (longitude + p_offset < 0) {
			throw new CoordinatesException("Given offset would set longitude to negative!");
		}

		longitude += p_offset;
	}

	public void moveLatitude(int p_offset) throws CoordinatesException {
		if (latitude + p_offset < 0) {
			throw new CoordinatesException("Given offset would set latitude to negative!");
		}

		latitude += p_offset;
	}

	public void moveHeight(int p_offset) {
		if (height + p_offset < 0) {
			height = 0;
		} else if (height + p_offset > MAX_HEIGHT) {
			height = MAX_HEIGHT;
		} else {
			height += p_offset;
		}
	}

	public void setLongitude(int p_longitude) throws CoordinatesException {
		if (p_longitude < 0) {
			throw new CoordinatesException("Coordinates cannot be negative!");
		}

		longitude = p_longitude;
	}

	public void setLatitude(int p_latitude) throws CoordinatesException {
		if (p_latitude < 0) {
			throw new CoordinatesException("Coordinates cannot be negative!");
		}

		latitude = p_latitude;
	}

	public void setHeight(int p_height) {
		if (p_height < 0) {
			height = 0;
		} else if (p_height > MAX_HEIGHT) {
			height = MAX_HEIGHT;
		} else {
			height = p_height;
		}
	}

}
