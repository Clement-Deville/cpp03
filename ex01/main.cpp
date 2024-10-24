/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:10:29 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/21 16:32:29 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap a("Jo");
		ScavTrap b("Cody");
		ScavTrap empty;

		std::cout << "\033[34mTesting\033[0m" << std::endl;

		empty.attack("Cody");
		empty.takeDamage(10);
		empty.beRepaired(3);
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.guardGate();
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
		{
			b.attack("Jo");
			a.takeDamage(b.getAttack());
		}
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}
