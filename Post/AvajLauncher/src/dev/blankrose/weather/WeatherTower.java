/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - WeatherTower.java               */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:49:02 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.weather;

import dev.blankrose.simulation.Coordinates;

/**
 * WeatherTower
 * <p>
 * Weather specialisation of the Tower class to get the current weather.
 * */
public class WeatherTower extends Tower {

	private static final WeatherProvider WEATHER = WeatherProvider.getInstance();

	public String getWeather(Coordinates p_coordinates) {
		return WEATHER.getCurrentWeather(p_coordinates);
	}

	public void changeWeather() {
		conditionChanged();
	}

}
