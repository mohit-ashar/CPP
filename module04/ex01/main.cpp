#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"


int main()
{
    std::cout << "........TESTING CHARACTER........." << std::endl;
    Character* me = new Character("Pierre");
    std::cout << *me;
    std::cout << "\n........TESTING CHARACTER copy constructor........." << std::endl;
    Character* copy(me);
    std::cout << *copy;

    std::cout << "\n........TESTING RadScorpian........." << std::endl;
    Enemy* b = new RadScorpion();
    std::cout << "Scorpian HP: " << b->getHP() << std::endl;
    Enemy* mutant = new SuperMutant();
    std::cout << "Mutant HP: " << mutant->getHP() << std::endl;
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    std::cout << "\n........TESTING Equip........." << std::endl;
    me->attack(b);
    me->equip(pr);
    std::cout << *me;
    me->equip(pf);
    std::cout << *me;
 
    std::cout << "\n........TESTING Attack........." << std::endl;
    me->attack(b);
    me->attack(b);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(mutant);
    std::cout << *me;

    std::cout << "\n........TESTING Recover........." << std::endl;
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;

    std::cout << "Mutant HP: " << mutant->getHP() << std::endl;
    std::cout << "Scorpian HP: " << b->getHP() << std::endl;
    delete me;
    // delete b;
    delete pr;
    delete pf;
    delete mutant;
    return 0;
}