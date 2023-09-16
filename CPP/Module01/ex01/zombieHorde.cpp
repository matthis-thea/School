/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:18:44 by mthea             #+#    #+#             */
/*   Updated: 2023/08/29 12:03:42 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* zombie = new Zombie[N];
	for (int i = 0; i < N; i++){
		zombie[i].setZombie(name);
	}
	return (zombie);
}
