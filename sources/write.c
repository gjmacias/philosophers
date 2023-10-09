/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:19:35 by gmacias-          #+#    #+#             */
/*   Updated: 2023/10/09 10:19:44 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	fill_llitoa(long long int nbr, int len, char *s)
{
	if (nbr == 0)
	{
		s[0] = '0';
		return ;
	}
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		s[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
}

char	*ft_llitoa(long long int nbr)
{
	long long int	n;
	int				len;
	char			*s;

	n = nbr;
	len = 0;
	if (nbr <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	fill_llitoa(nbr, len, s);
	return (s);
}

void	put_string(char *s)
{
	write(1, s, ft_strlen(s));
}

void	put_number(long long int num)
{
	char	*s;

	s = ft_llitoa(num);
	put_string(s);
	put_string(" ");
	free(s);
}

/*
** Hacemos una funcion especifica para escribir ya que no todos pueden escribir 
** por pantalla a la vez, para eso esta esta funcion con su mutex propio.
*/

void	ft_writing(t_rules *r, int id, char *s)
{
	pthread_mutex_lock(&(r->writing));
	if (!(r->death))
	{
		put_number((the_time() - r->first_time));
		put_number((long long int)(id + 1));
		put_string(s);
		put_string("\n");
	}
	pthread_mutex_unlock(&(r->writing));
}
