/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:10:36 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/15 17:05:38 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "\e[0;32mDefault constructor called\e[0m" << std::endl;
	this->_name = "";
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap &Cpy)
{
	std::cout << "\e[0;32mCopy constructor called\e[0m" << std::endl;
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &Cpy)
{
	std::cout << "\e[0;32mCopy assignement operator called\e[0m";
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (target.empty())
		std::cerr << "You must specify a valid target" << std::endl;
	std::cout << "ClapTrap "<< this->_name
		<< "attacks " << target << ", causing "
		<< this->_attack_dmg << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	short	dmg_taken;

	if (!this->_hit_point)
	{
		std::cout << "ClapTrap " << this->_name <<
			" is dead, stop hiting him/her!" << std::endl;
	}
	if (this->_hit_point > amount)
	{
		dmg_taken = amount;
		std::cout << "ClapTrap " << this->_name
		<< " is taking " << dmg_taken << std::endl;
	}
	else
		dmg_taken = _hit_point;
	std::cout << "ClapTrap " << this->_name
	<< " is taking " << dmg_taken << std::endl;
	this->_hit_point -= dmg_taken;
	if (!this->_hit_point)
		std::cout << "ClapTrap " << this->_name
		<< " died.." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
}
