#include "Brain.hpp"
#include <sstream>
#include <iostream>

std::string Brain::identify() const
{
    std::stringstream ss;
	std::string ret = "0x";

	ss << std::uppercase << std::hex << (unsigned long)this;
	ret.append(ss.str());
	return (ret);
}

void		Brain::think() const
{
	std::cout << "Thinking........." << std::endl;
}