/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:26:52 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:29:36 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	int_to_str(int num, char *str)
{
	int	i;
	int	temp_num;

	i = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return ;
	}
	temp_num = num;
	while (temp_num > 0)
	{
		temp_num /= 10;
		i++;
	}
	str[i] = '\0';
	while (num > 0)
	{
		str[--i] = (num % 10) + '0';
		num /= 10;
	}
}
