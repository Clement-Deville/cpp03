/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:05:49 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 17:21:49 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

const char	DiamondTrap::_className[] = "DiamondTrap";

DiamondTrap::DiamondTrap(void): FragTrap()
{
	std::cout << "\e[0;32m" << this->_className << " Default constructor called\e[0m" << std::endl;
	this->FragTrap::setDefaultHp();
	this->ScavTrap::setDefaultEp();
	this->FragTrap::setDefaultAd();
	this->_name = "";
}
DiamondTrap::DiamondTrap(const DiamondTrap &Cpy): FragTrap(Cpy)
{
	std::cout << "\e[0;32m" << this->_className << "Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}
DiamondTrap::DiamondTrap(const std::string name): FragTrap(name+ "_ClapTrap")
{
	std::cout << "\e[0;32m" << this->_className << "Name constructor called\e[0m" << std::endl;
	this->FragTrap::setDefaultHp();
	this->ScavTrap::setDefaultEp();
	this->FragTrap::setDefaultAd();
	this->_name = name;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31m" << this->_className << "Destructor called\e[0m" << std::endl;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap &Cpy)
{
	std::cout << "\e[0;32mCopy assignement operator called\e[0m";
	if (this == &Cpy)
		return (*this);
	this->_name = Cpy._name;
	FragTrap::operator=(Cpy);
	return (*this);
}


void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello, i am " + this->_name + " and my ClapTrap name is "
		+ this->FragTrap::_name << std::endl;
	// std::cout << "DIAMONDTRAP adress : " << &this->_hit_point <<
	// 	 "Hit Points = " << this->_hit_point << "; Energy points = "
	// 	<< this->_energy_point << "; Attack damage = " << this->_attack_dmg
	// 	<< std::endl;
	std::cout << "FRAGTRAP adress: " << &this->FragTrap::_hit_point <<
	 "Hit Points = " << this->FragTrap::_hit_point << "; Energy points = "
		<< this->FragTrap::_energy_point << "; Attack damage = " << this->FragTrap::_attack_dmg
		<< std::endl;
	std::cout << "SCAVTRAP adress: " << &this->ScavTrap::_hit_point
		<< "Hit Points = " << this->ScavTrap::_hit_point << "; Energy points = "
		<< this->ScavTrap::_energy_point << "; Attack damage = " << this->ScavTrap::_attack_dmg
		<< std::endl;
}
