/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:17:59 by gmacias-          #+#    #+#             */
/*   Updated: 2023/10/09 10:18:05 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	write_error(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(2, "Error: ", 7);
	write(2, s, len);
	write(2, "\n", 1);
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (write_error("At least, one wrong argument."));
	if (error == 2)
		return (write_error("Fatal error. When intializing mutex."));
	return (1);
}
