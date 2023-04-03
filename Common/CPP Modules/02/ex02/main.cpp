/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:02:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/29 08:10:58 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( 5 );
	Fixed const e(Fixed( 5.05f ) * Fixed( 2 ));
	Fixed f;

	a = Fixed( 1234.4321f );
	
	std::cout << "\nValues Check:" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;

	std::cout << "\nBasic Maths:" << std::endl;
	std::cout << b << " + " << d << " = " << b + d << std::endl;
	std::cout << b << " - " << d << " = " << b - d << std::endl;
	std::cout << b << " * " << d << " = " << b * d << std::endl;
	std::cout << b << " / " << d << " = " << b / d << std::endl;

	std::cout << "\nPre-Increment & Post-Increment:" << std::endl;
	std::cout << f << std::endl;
	std::cout << ++f << " < Pre" << std::endl;
	std::cout << f << std::endl;
	std::cout << f++ << " < Post" << std::endl;
	std::cout << f << std::endl;

	std::cout << "\nPre-Decrement & Post-Decrement:" << std::endl;
	std::cout << f << std::endl;
	std::cout << --f << " < Pre" << std::endl;
	std::cout << f << std::endl;
	std::cout << f-- << " < Post" << std::endl;
	std::cout << f << std::endl;

	std::cout << "\nEquality:" << std::endl;
	std::cout << b << " == " << b << " : " << (b == b) << std::endl;
	std::cout << b << " == " << d << " : " << (b == d) << std::endl;

	std::cout << "\nIn-equality:" << std::endl;
	std::cout << b << " != " << b << " : " << (b != b) << std::endl;
	std::cout << b << " != " << b << " : " << (b != d) << std::endl;

	std::cout << "\nSuperior OR Equal:" << std::endl;
	std::cout << b << " >= " << e << " : " << (b >= e) << std::endl;
	std::cout << b << " >= " << b << " : " << (b >= b) << std::endl;
	std::cout << b << " >= " << d << " : " << (b >= d) << std::endl;

	std::cout << "\nInferior OR Equal:" << std::endl;
	std::cout << b << " <= " << e << " : " << (b <= e) << std::endl;
	std::cout << b << " <= " << b << " : " << (b <= b) << std::endl;
	std::cout << b << " <= " << d << " : " << (b <= d) << std::endl;

	std::cout << "\nStrictly Superior:" << std::endl;
	std::cout << b << " > " << e << " : " << (b > e) << std::endl;
	std::cout << b << " > " << b << " : " << (b > b) << std::endl;
	std::cout << b << " > " << d << " : " << (b > d) << std::endl;

	std::cout << "\nStrictly Inferior:" << std::endl;
	std::cout << b << " < " << e << " : " << (b < e) << std::endl;
	std::cout << b << " < " << b << " : " << (b < b) << std::endl;
	std::cout << b << " < " << d << " : " << (b < d) << std::endl;

	std::cout << "\nMin and Max Functions:" << std::endl;
	std::cout << "Min (" << e << ", " << b << ") -> " << Fixed::min(e, b) << std::endl;
	std::cout << "Max (" << e << ", " << b << ") -> " << Fixed::max(e, b) << std::endl;

	return 0;
}