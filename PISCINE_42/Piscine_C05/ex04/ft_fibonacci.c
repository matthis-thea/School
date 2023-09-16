/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:07:49 by mthea             #+#    #+#             */
/*   Updated: 2022/07/23 16:37:23 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_fibonacci(int index)
{
	if (index == 0)
		return (0);
	if (index > 0)
	{
		if (index == 1)
			return (1);
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
	return (-1);
}
