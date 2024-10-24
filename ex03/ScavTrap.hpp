/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:22:34 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/24 17:05:08 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private :
	static const char	_className[];
public:
	ScavTrap(void);
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &Cpy);
	~ScavTrap();

	ScavTrap & operator = (const ScavTrap &Cpy);
	void	attack(const std::string& target);
	void	guardGate(void);

	void	setDefaultHp(void);
	void	setDefaultAd(void);
	void	setDefaultEp(void);
	void	print_names(void);
};

/*MACRO MESSAGES*/

//ATTACK

# define S_ATCK_INIT_MSG \
"You must initialize this " << this->_className << " before attacking"\
	<< std::endl
# define S_ATCK_TRGT_MSG \
"You must specify a valid target" << std::endl
# define S_ATCK_DEAD_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't attack cause it is dead." << std::endl
# define S_ATCK_NO_NRG_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't attack cause it has no energy left.." << std::endl

//GUARD

# define S_GRD_INIT_MSG \
"You must initialize this " << this->_className << " before guarding"\
	<< std::endl
# define S_GRD_DEAD_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't guard the gate cause it is dead." << std::endl
# define S_GRD_NO_NRG_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't guard the gate cause it has no energy left.." << std::endl

#endif
