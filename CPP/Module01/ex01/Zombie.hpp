/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:12:18 by mthea             #+#    #+#             */
/*   Updated: 2023/08/29 12:31:12 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE
#include <iostream>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class Zombie
{
	private:
		std::string		_name;
		int				_N;
	public:
		Zombie(void);
		~Zombie(void);
		int				setZombie(std::string name);
		int				setN(int N);
		void			announce(void);
		void			boucle_announce(int N, Zombie zombie[]);
};

Zombie*					zombieHorde(int N, std::string name);


#endif
