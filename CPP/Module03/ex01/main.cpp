/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:02:28 by haze              #+#    #+#             */
/*   Updated: 2023/09/15 17:26:40 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Franklin");
    ScavTrap scav2("Walther");
    ScavTrap scaav = scav;
    scav.attack("walther");
    scav2.takeDamage(500);
    scav2.beRepaired(10);
    scav2.guardGate();
    scaav.guardGate();
    scaav.takeDamage(10);
    scav.takeDamage(20);
    return 0;
}