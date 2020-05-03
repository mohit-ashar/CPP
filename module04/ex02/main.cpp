#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

void check_deep_copy()
{
	Squad sq;
	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;

	std::cout << std::endl;
	std::cout << "create squad(2 units)" << std::endl;
	sq.push(bob);
	sq.push(jim);

	std::cout << std::endl;
	std::cout << "1. copied by assignation(=) " << std::endl;
	Squad sq2 = sq;
	for (int i = 0; i < sq.getCount(); i++)
	{
		std::cout << "unit " << i << " ";
		std::cout << (sq2.getUnit(i) != sq.getUnit(i) ? "deep copied" : "not deep copied") << std::endl;
	}

	std::cout << std::endl;
	std::cout << "2. copied by copy constructor " << std::endl;
	Squad sq3(sq2);
	for (int i = 0; i < sq.getCount(); i++)
	{
		std::cout << "unit " << i << " ";
		std::cout << (sq3.getUnit(i) != sq2.getUnit(i) ? "deep copied" : "not deep copied") << std::endl;
	}

	std::cout << std::endl;
}



int main()
{

    //Check deep copy for the squad object. Internal objects are deep copied.
    std::cout << ".......Create marines and squad......." << std::endl;
    ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;


    ISquad* vlc = new Squad;

    std::cout << "\n.......Check getUnit without adding any marines......." << std::endl;
    std::cout << vlc->getUnit(4) << std::endl;
    std::cout << "\n.......Check push by adding marines......." << std::endl;
    std::cout << vlc->push(bob) << std::endl;
    std::cout << vlc->push(jim) << std::endl;
    std::cout << "\n.......Check battleCry, rangedAttack and meleeAttack......." << std::endl;
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
        std::cout << std::endl;
    }

    std::cout << "\n.......Check Null push......." << std::endl;
    std::cout << vlc->push(NULL) << std::endl;

    std::cout << "\n.......Check Already existing marine push......." << std::endl;
    std::cout << vlc->push(bob) << std::endl;

    delete vlc;

    std::cout << "\n.......Check Deep copy......." << std::endl;
    check_deep_copy();
    return 0;
}
