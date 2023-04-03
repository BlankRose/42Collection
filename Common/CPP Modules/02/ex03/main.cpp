/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:02:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/29 00:26:59 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main( void )
{
	Point const	a, b(0, 20), c(10.0f, 15.0f), d(b), e(0, 5), f(10.0f, 30.0f), g(50, 50), h(20.0f, 0.0f);

	std::cout << "\nVariables Checks:" << std::endl;
	std::cout << "a is: X = " << a.getX() << " ; Y = " << a.getY() << std::endl;
	std::cout << "b is: X = " << b.getX() << " ; Y = " << b.getY() << std::endl;
	std::cout << "c is: X = " << c.getX() << " ; Y = " << c.getY() << std::endl;
	std::cout << "d is: X = " << d.getX() << " ; Y = " << d.getY() << std::endl;
	std::cout << "e is: X = " << e.getX() << " ; Y = " << e.getY() << std::endl;
	std::cout << "f is: X = " << f.getX() << " ; Y = " << f.getY() << std::endl;
	std::cout << "g is: X = " << g.getX() << " ; Y = " << g.getY() << std::endl;
	std::cout << "h is: X = " << h.getX() << " ; Y = " << h.getY() << std::endl;

	std::cout << "\nBSP Checks:" << std::endl;
	std::cout << "Is D inside of the triangle BCA? " << bsp(b, c, a, d) << std::endl;
	std::cout << "Should be 0 (FALSE) since D is same as B" << std::endl;
	std::cout << "Is E inside of the triangle ABF? " << bsp(a, b, f, e) << std::endl;
	std::cout << "Should be 0 (FALSE) since E is on edge AB" << std::endl;
	std::cout << "Is G inside of the triangle DFE? " << bsp(d, f, e, g) << std::endl;
	std::cout << "Should be 0 (FALSE) since G is far outside" << std::endl;
	std::cout << "Is C inside of the triangle AHF? " << bsp(a, h, f, c) << std::endl;
	std::cout << "Should be 1 (TRUE) since C is within" << std::endl;

	return 0;
}