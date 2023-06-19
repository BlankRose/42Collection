/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Avaj Launcher - Tower.java                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: lun. 19 juin 2023 18:47:51 CEST   */
/*      ||  '-'                                                          */
/* ********************************************************************* */

package dev.blankrose.weather;

import java.util.List;
import dev.blankrose.aircrafts.Flyable;
import dev.blankrose.simulation.Logging;

/**
 * Tower
 * <p>
 * Observer pattern implementation which registers and unregisters
 * {@link Flyable} objects and notifies them when the weather changes.
 * */
public class Tower {

	private static final Logging LOGGER = Logging.getInstance();
	private List<Flyable> observers = new java.util.ArrayList<Flyable>();

	public void register(Flyable p_flyable) {
		observers.add(p_flyable);
		LOGGER.file_log("Tower says: " + p_flyable.getLoggingBase() + " registered to weather tower.");
	}

	public void unregister(Flyable p_flyable) {
		observers.remove(p_flyable);
		LOGGER.tower_log(p_flyable, "landed.");
		LOGGER.file_log("Tower says: " + p_flyable.getLoggingBase() + " unregistered from weather tower.");
	}

	protected void conditionChanged() {
		// Copy to avoid ConcurrentModificationException
		// caused by unregistering when onGround() is true
		List<Flyable> copy = new java.util.ArrayList<Flyable>(observers);

		// Update conditions and unregister if on ground
		for (Flyable x: copy) {
			x.updateConditions();
			if (x.onGround()) {
				unregister(x);
			}
		}
	}

	public int getObserversCount() {
		return observers.size();
	}

}