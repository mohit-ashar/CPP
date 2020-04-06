
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include <typeinfo>

int main(void)
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	
	std::cout << "\033[1;32m### copy constructor test ###\033[0m" << std::endl;
	Victim copied(jim);
	std::cout << copied.getName() << std::endl;
	Peon copied2(joe);
	std::cout << copied2.getName() << std::endl;

	std::cout << "\033[1;32m### = overide test ###\033[0m" << std::endl;
	Victim *newVictim = new Victim("david");
	std::cout << *newVictim;
	*newVictim = jim;
	std::cout << *newVictim;
	delete newVictim;

	std::cout << "\033[1;32m### << overide test ###\033[0m" << std::endl;
	std::cout << robert << jim << joe;

	std::cout << "\033[1;32m### polymorph test ###\033[0m" << std::endl;
	std::cout << typeid(jim).name() << std::endl;
	std::cout << typeid(joe).name() << std::endl;
	robert.polymorph(jim); // little sheep
	robert.polymorph(joe); // pink pony
	jim.getPolymorphed(); // little sheep
	joe.getPolymorphed(); // pink pony

	Victim *up_cast = &joe;
	std::cout << typeid(up_cast).name() << std::endl;
	std::cout << typeid(joe).name() << std::endl;
	robert.polymorph(joe); // pink pony
	robert.polymorph(*up_cast); // pink pony
	joe.getPolymorphed(); // pink pony
	up_cast->getPolymorphed(); // pink pony

	std::cout << "\033[1;31m### Destruction ###\033[0m" << std::endl;

	return (0);
}