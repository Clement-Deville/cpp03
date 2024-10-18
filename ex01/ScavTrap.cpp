/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:33:56 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/18 13:15:14 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "\e[0;32mScavTrap Default constructor called\e[0m" << std::endl;
	this->_name = "";
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &Cpy) : ClapTrap()
{
	std::cout << "\e[0;32mScavTrap Copy constructor called\e[0m" << std::endl;
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout << "\e[0;32mScavTrap Name constructor called\e[0m" << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_dmg = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mScavTrap Destructor called\e[0m" << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &Cpy)
{
	std::cout << "\e[0;32mCopy assignement operator called\e[0m";
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
	std::cout << "ScavTrap "<< UGRN + this->_name + reset
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
	std::cout << "ScavTrap "<< UGRN + this->_name + reset
		<< " is now garding the gate, Benjamin is safe." << std::endl;
}
