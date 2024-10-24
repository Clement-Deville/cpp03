/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:33:56 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 13:14:12 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

const char	ScavTrap::_className[] = "ScavTrap";

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "\e[0;32m" << this->_className << "Default constructor called\e[0m" << std::endl;
	this->_name = "";
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &Cpy) : ClapTrap(Cpy)
{
	std::cout << "\e[0;32m" << this->_className << "Copy constructor called\e[0m" << std::endl;
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "\e[0;32m" << this->_className << "Name constructor called\e[0m" << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_dmg = 20;
	std::cout << "ClapTrap name: " + ClapTrap::_name + " ScavTrap: " + this->_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31m" << this->_className << "Destructor called\e[0m" << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &Cpy)
{
	std::cout << "\e[0;32mCopy assignement operator called\e[0m";
	if (this == &Cpy)
		return (*this);
	ClapTrap::operator = (Cpy);
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_name.empty())
	{
		std::cerr << S_ATCK_INIT_MSG;
		return ;
	}
	if (target.empty())
	{
		std::cerr << S_ATCK_TRGT_MSG;
		return ;
	}
	if (this->_hit_point == 0)
	{
		std::cerr << S_ATCK_DEAD_MSG;
		return ;
	}
	if (this->_energy_point == 0)
	{
		std::cerr << S_ATCK_NO_NRG_MSG;
		return ;
	}
	this->_energy_point--;
	std::cout << this->_className << " " << UGRN + this->_name + reset
		<< " attacks " << UYEL + target + reset << ", causing " << BRED
		<< this->_attack_dmg << reset
		<< (this->_attack_dmg > 1 ? " points" : " point")
		<< " of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_name.empty())
	{
		std::cerr << S_GRD_INIT_MSG;
		return ;
	}
	if (this->_hit_point == 0)
	{
		std::cerr << S_GRD_DEAD_MSG;
		return ;
	}
	if (this->_energy_point == 0)
	{
		std::cerr << S_GRD_NO_NRG_MSG;
		return ;
	}
	this->_energy_point--;
	std::cout << this->_className << " " << UGRN + this->_name + reset
		<< " is now garding the gate, Benjamin is safe." << std::endl;
}
