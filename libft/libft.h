/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:30:15 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/02 11:13:30 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*********************************************************/
/*                                                       */
/*                   STANDARDS INCLUDES                  */
/*     Every standards includes used by this library     */
/*                                                       */
/*********************************************************/

# include <stdlib.h>
# include <stdarg.h>

# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif

/*********************************************************/
/*                                                       */
/*                    LIBRARY INCLUDES                   */
/*     Every includes prefined by the library itself     */
/*                                                       */
/*********************************************************/

# include "headers/defines.h"
# include "headers/structures.h"
# include "headers/functions.h"

#endif
