#include "Pony.hpp"

void ponyOnTheHeap(Pony *p)
{
    p->set_colour("Heap White");
    p->set_height(140);
}

void ponyOnTheStack(Pony p)
{
    p.set_colour("Stack Black");
    p.set_height(150);
    p.display_msg(p.get_colour(), p.get_height());
}

int main()
{
    Pony *p;
    Pony p1;

    p = new Pony();
    std::cout << "First, we see the Heap Pony\n";
    ponyOnTheHeap(p);
    p->display_msg(p->get_colour(), p->get_height());
    std::cout << "Now, we see the Stack Pony\n";
    ponyOnTheStack(p1);
    p1.display_msg(p1.get_colour(), p1.get_height());
    delete p;
    p = 0;
    return (0);
}
