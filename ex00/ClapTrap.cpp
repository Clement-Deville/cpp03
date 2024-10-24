/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:10:36 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/21 15:31:25 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

const char	ClapTrap::_className[] = "ClapTrap";

ClapTrap::ClapTrap(void)
{
	std::cout << "\e[0;32m" << this->_className << "Default constructor called\e[0m" << std::endl;
	this->_name = "";
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap &Cpy)
{
	std::cout << "\e[0;32m" << this->_className << "Copy constructor called\e[0m" << std::endl;
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "\e[0;32m" << this->_className << "Name constructor called\e[0m" << std::endl;
	this->_name = name;
	this->_hit_point = 10;
	this->_energy_point = 10;
	this->_attack_dmg = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31m" << this->_className << "Destructor called\e[0m" << std::endl;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &Cpy)
{
	std::cout << "\e[0;32m" << this->_className << "Copy assignement operator called\e[0m";
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_name.empty())
	{
		std::cerr << ATCK_INIT_MSG;
		return ;
	}
	if (target.empty())
	{
		std::cerr << ATCK_TRGT_MSG;
		return ;
	}
	if (this->_hit_point == 0)
	{
		std::cerr << ATCK_DEAD_MSG;
		return ;
	}
	if (this->_energy_point == 0)
	{
		std::cerr << ATCK_NO_NRG_MSG;
		return ;
	}
	this->_energy_point--;
	std::cout << this->_className << " " << UGRN + this->_name + reset
		<< " attacks " << UYEL + target + reset << ", causing " << BRED
		<< this->_attack_dmg << reset
		<< (this->_attack_dmg > 1 ? " points" : " point")
		<< " of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned short	dmg_taken;

	if (this->_name.empty())
	{
		std::cerr << DMG_INIT_MSG;
		return ;
	}
	if (!this->_hit_point)
	{
		std::cout << DMG_DEAD_ERR_MSG;
		return ;
	}
	if (this->_hit_point > amount)
		dmg_taken = amount;
	else
		dmg_taken = _hit_point;
	std::cout << this->_className << " "  << UGRN + this->_name + reset
	<< " is taking " << BBLU << dmg_taken << reset
	<< (dmg_taken > 1 ? " damages" : " damage")
		<< std::endl;
	this->_hit_point -= dmg_taken;
	if (!this->_hit_point)
		std::cout << DMG_DYING_MSG;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_name.empty())
	{
		std::cerr << REPAIR_INIT_MSG;
		return ;
	}
	if (amount == 0)
	{
		std::cerr << REPAIR_NO_ENERGY_MSG;
		return ;
	}
	if (this->_hit_point == 0)
	{
		std::cerr << REPAIR_DEAD_MSG;
		return ;
	}
	if (this->_energy_point == 0)
	{
		std::cerr << REPAIR_NO_ENERGY_MSG;
		return ;
	}
	this->_energy_point--;
	std::cout << this->_className << " "  << UGRN + this->_name + reset
		<< " repaired himself " << MAG << amount << reset
		<< (amount > 1 ? " hit points" : " hit point")	<< std::endl;
}

unsigned short	ClapTrap::getAttack(void) const
{
	return (this->_attack_dmg);
}
