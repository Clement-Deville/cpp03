/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:10:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/15 15:56:39 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	short	_hit_point;
	short	_energy_point;
	short	_attack_dmg;
public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &Cpy);
	~ClapTrap();
	ClapTrap & operator = (const ClapTrap &Cpy);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
