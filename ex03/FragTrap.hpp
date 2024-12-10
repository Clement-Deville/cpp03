/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:11:38 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/25 12:40:16 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private :
	static const char	_className[];
public:
	FragTrap();
	FragTrap(const FragTrap &Cpy);
	FragTrap(const std::string name);
	FragTrap & operator = (const FragTrap &Cpy);
	~FragTrap();

	void	highFivesGuys(void);
	void	setDefaultHp(void);
	void	setDefaultAd(void);
	void	setDefaultEp(void);


};

//GUARD

# define F_HF_INIT_MSG \
"You must initialize this " << this->_className << " before doing a high fives"\
	<< std::endl
# define F_HF_DEAD_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't do a high fives cause it is dead." << std::endl
# define S_HF_NO_NRG_MSG \
this->_className << " "  << UGRN + this->_name + reset << \
	" can't do a high fives cause it has no energy left.." << std::endl

#endif
