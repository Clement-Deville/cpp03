/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:33:56 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/17 18:21:52 by cdeville         ###   ########.fr       */
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


void	ScavTrap::attack(const std::string& target)
{
    (void)target;
}
void    ScavTrap::guardGate(void)
{
}