/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:43:06 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/21 02:06:01 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int	point = 8;
		int					value;
	
	public:
		Fixed();							// Constructor
		~Fixed();							// Destructor
		Fixed(const Fixed&);				// Clone Constructor
		Fixed &operator=(const Fixed&);		// Affectation Operator

		int		getRawBits(void);
		void	setRawBits(int);
};

#endif