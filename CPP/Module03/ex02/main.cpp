/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:02:28 by haze              #+#    #+#             */
/*   Updated: 2023/09/18 03:08:19 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap scav("Franklin");
    FragTrap scav2("Walther");
    FragTrap scaav = scav;
    scav.attack("walther");
    scav2.takeDamage(500);
    scav2.takeDamage(100);
    scav2.beRepaired(10);
    scav2.takeDamage(100);
    scav2.highFivesGuys();
    scaav.highFivesGuys();
    scaav.takeDamage(10);
    scav.takeDamage(20);
    scav.beRepaired(100);
    scaav.attack("walther");
    return 0;
}