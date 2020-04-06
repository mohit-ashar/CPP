#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{

    //Check deep copy for the squad object. Internal objects are deep copied.
    ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;

    ISquad* vlc = new Squad;
    ISquad* vlc2(vlc);

    std::cout << vlc->getUnit(4) << std::endl;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;
    return 0;
}
