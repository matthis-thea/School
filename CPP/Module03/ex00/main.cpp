/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:02:28 by haze              #+#    #+#             */
/*   Updated: 2023/09/15 17:01:11 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap1;
    ClapTrap claptrap2("Franklin");
    ClapTrap claptrap3(claptrap2);
    ClapTrap claptrap4("Walther");

    claptrap1.attack("Ragnar Lothbrok");
    claptrap2.takeDamage(100000000);
    claptrap2.beRepaired(10);
    claptrap2.takeDamage(20);
    claptrap2.takeDamage(1);
    claptrap2.takeDamage(0);

    claptrap2.attack("Floki");
    claptrap4.takeDamage(5);
    claptrap4.beRepaired(1000);
    claptrap4.takeDamage(1010);
    claptrap4.beRepaired(1000);
    claptrap4.takeDamage(1010);
    claptrap3.takeDamage(10);
    claptrap3.takeDamage(10);
    return 0;
}