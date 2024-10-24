/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:04:47 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 17:05:45 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private :
	static const char	_className[];
	std::string			_name;
	using FragTrap::_hit_point;
	using ScavTrap::_energy_point;
	using FragTrap::_attack_dmg;
public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &Cpy);
	DiamondTrap(const std::string name);
	~DiamondTrap();

	DiamondTrap & operator = (const DiamondTrap &Cpy);
	using ScavTrap::attack;
	void whoAmI(void);
};

#endif
