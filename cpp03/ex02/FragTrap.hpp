#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

#define FT_DEFAULT_HITPOINTS 100
#define FT_DEFAULT_ENERGYPOINTS 100
#define FT_DEFAULT_ATTACKDAMAGE 30

class FragTrap : public ClapTrap {
private:
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &from);
	~FragTrap();
	FragTrap& operator=(const FragTrap &from);

	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif
