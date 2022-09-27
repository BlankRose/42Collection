/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:43:06 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/21 19:22:54 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#ifndef PRECISION
# define PRECISION 8
#endif

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int		getPrecision(void) const;
		int		getMaxPrecision(void) const;

		static const int	point = PRECISION;
		int					value;
	
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed&);
		~Fixed();

		Fixed	&operator=(const Fixed&);

		friend std::ostream & operator << (std::ostream &out, const Fixed &f);

		int		getRawBits(void);
		void	setRawBits(int);

		int		toInt(void) const;
		float	toFloat(void) const;

};

#endif