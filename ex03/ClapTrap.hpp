/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:10:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/21 17:31:33 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include "colors.h"

class ClapTrap
{
private :
	static const char	_className[];
protected:
	std::string	_name;
	unsigned short	_hit_point;
	unsigned short	_energy_point;
	unsigned short	_attack_dmg;
public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &Cpy);
	ClapTrap(const std::string name);
	~ClapTrap();
	ClapTrap & operator = (const ClapTrap &Cpy);
	void				attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	unsigned short		getAttack(void) const;
};


/*MACRO MESSAGES*/

//ATTACK

# define ATCK_INIT_MSG \
"You must initialize this " << this->_className << " before attacking"\
	<< std::endl
# define ATCK_TRGT_MSG \
"You must specify a valid target" << std::endl
# define ATCK_DEAD_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't attack cause it is dead." << std::endl
# define ATCK_NO_NRG_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't attack cause it has no energy left.." << std::endl
//TAKE DAMAGE

# define DMG_INIT_MSG \
	"You must initialize this " << this->_className << " before taking damages" << std::endl
# define DMG_DEAD_ERR_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" is dead, stop hiting it!" << std::endl
# define DMG_DYING_MSG \
this->_className << " "  << UGRN + this->_name + reset \
	<< BHRED << " died.." << reset << std::endl

//REPAIR

# define REPAIR_INIT_MSG \
"You must initialize this " << this->_className << " before attacking" \
	<< std::endl
# define REPAIR_AMOUNT \
"Amount repaired needs to be at least 1" \
	<< std::endl
# define REPAIR_DEAD_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't repair cause it is dead." << std::endl
# define REPAIR_NO_ENERGY_MSG \
this->_className << " "  << UGRN + this->_name + reset \
	<< " can't repair cause it has no energy left.." << std::endl
#endif
