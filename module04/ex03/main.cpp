#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void basic_test()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void deep_copy_assign_test()
{
	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
	MateriaSource src2 = src;
	MateriaSource src3 = src2;

	AMateria *tmp;
	Character me("me");	
	tmp = src.createMateria("ice");
	me.equip(tmp);
	tmp = src.createMateria("cure");
	me.equip(tmp);
	Character me2 = me;
	Character me3(me2);
}

void simple_copy_assign_test()
{
	Ice *ice1 = new Ice();
	Character me("me");
	me.equip(ice1);
	std::cout << "ice1 XP = " << ice1->getXP() << std::endl;
	me.use(0, me);
	std::cout << "ice1 XP = " << ice1->getXP() << std::endl;
	Ice ice2 = *ice1;
	std::cout << "ice2 type = " << ice2.getType() << std::endl;
	std::cout << "ice2 XP = " << ice2.getXP() << std::endl;
	Ice ice3(*ice1);
	std::cout << "ice3 type = " << ice3.getType() << std::endl;
	std::cout << "ice3 XP = " << ice3.getXP() << std::endl;

	Cure *cure1 = new Cure();
	me.equip(cure1);
	std::cout << "cure1 XP = " << cure1->getXP() << std::endl;
	me.use(1, me);
	std::cout << "cure1 XP = " << cure1->getXP() << std::endl;
	Cure cure2 = *cure1;
	std::cout << "cure2 type = " << cure2.getType() << std::endl;
	std::cout << "cure2 XP = " << cure2.getXP() << std::endl;
	Cure cure3(*cure1);
	std::cout << "cure3 type = " << cure3.getType() << std::endl;
	std::cout << "cure3 XP = " << cure3.getXP() << std::endl;
}

void use_equip_unequip_test()
{
	Character me("me");	
	me.use(0, me); // nothing happend
	me.use(-1, me); // nothing happend

	me.unequip(0); // nothing happend
	me.unequip(1); // nothing happend

	Ice *ice = new Ice();
	me.equip(ice);
	me.use(0, me);
	me.unequip(0);
	me.use(0, me); // nothring happend
	delete ice;
}

void learn_create_test()
{
	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
	src.learnMateria(NULL); // nothring happend

	AMateria *tmp;
	tmp = src.createMateria("ice");
	if (tmp)
	{
		std::cout << "ice created well" << std::endl;
		delete tmp;
	}
	tmp = src.createMateria("no name");
	if (tmp) // nothing happend
	{
		std::cout << "no name created well" << std::endl;
		delete tmp;
	}
}

int main()
{
	std::cout << "\033[1;33m" << "### basic test ###" << "\033[0m" << std::endl;
	basic_test();
	std::cout << "\033[1;33m" << "### my test ###" << "\033[0m" << std::endl;
	std::cout << "\033[1;33m" << " deep copy test" << "\033[0m" << std::endl;
	deep_copy_assign_test();
	std::cout << "\033[1;33m" << " simple copy test" << "\033[0m" << std::endl;
	simple_copy_assign_test();
	std::cout << "\033[1;33m" << " use/equip/unequip test" << "\033[0m" << std::endl;
	use_equip_unequip_test();	
	std::cout << "\033[1;33m" << " learn/create test" << "\033[0m" << std::endl;
	learn_create_test();
	return 0;
}