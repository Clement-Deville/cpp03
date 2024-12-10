/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:10:29 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/25 12:48:05 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "### TESTING DIAMOND TRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		DiamondTrap a("Jo");
		DiamondTrap b("Cody");
		DiamondTrap c = b;
		DiamondTrap empty;

		std::cout << "\033[34mTesting\033[0m" << std::endl;

		empty.attack("Cody");
		empty.takeDamage(10);
		empty.beRepaired(3);
		a.guardGate();
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.guardGate();
		a.attack("some other other robot");
		a.ClapTrap::attack("Yo");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
		{
			b.attack("Jo");
			a.takeDamage(b.getAttack());
		}
		b.ClapTrap::attack("ClapTrap");
		b.attack("FragTrap");
		a.whoAmI();
		b.whoAmI();
		empty.whoAmI();
		b.beRepaired(3);
		a.guardGate();
		c.ClapTrap::attack("ClapTrap");
		b.print_names();
		c.print_names();
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}
