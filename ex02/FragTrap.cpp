/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:18:08 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 14:20:12 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

const char	FragTrap::_className[] = "FragTrap";

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "\e[0;32m" << this->_className << " Default constructor called\e[0m" << std::endl;
	this->_name = "";
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_dmg = 20;
}
FragTrap::FragTrap(const FragTrap &Cpy): ClapTrap(Cpy)
{
	std::cout << "\e[0;32m" << this->_className << " Copy constructor called\e[0m" << std::endl;
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
}
FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	std::cout << "\e[0;32m" << this->_className << " Name constructor called\e[0m" << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_dmg = 20;
}

FragTrap & FragTrap::operator = (const FragTrap &Cpy)
{
	std::cout << "\e[0;32m" << this->_className << " Copy assignement operator called\e[0m";
	if (this == &Cpy)
		return (*this);
	ClapTrap::operator=(Cpy);
	this->_name = Cpy._name;
	this->_hit_point = Cpy._hit_point;
	this->_energy_point = Cpy._energy_point;
	this->_attack_dmg = Cpy._energy_point;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "\e[0;31m" << this->_className << " Destructor called\e[0m" << std::endl;
}


void	FragTrap::highFivesGuys(void)
{
	if (this->_name.empty())
	{
		std::cerr << F_HF_INIT_MSG;
		return ;
	}
	if (this->_hit_point == 0)
	{
		std::cerr << F_HF_DEAD_MSG;
		return ;
	}
	if (this->_energy_point == 0)
	{
		std::cerr << S_HF_NO_NRG_MSG;
		return ;
	}
	this->_energy_point--;
	std::cout << this->_className << " " << UGRN + this->_name + reset
		<< " is doing a high fives to everyone." << std::endl;
}
