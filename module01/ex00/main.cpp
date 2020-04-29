#include "Pony.hpp"

void ponyOnTheHeap(void)
{
    Pony *p = new Pony();
    p->set_colour("Heap White");
    p->set_height(140);
    p->display_msg(p->get_colour(), p->get_height());
    delete p;
}

void ponyOnTheStack(void)
{
    Pony p1;
    p1.set_colour("Stack Black");
    p1.set_height(150);
    p1.display_msg(p1.get_colour(), p1.get_height());
}

int main()
{
    std::cout << "First, we see the Heap Pony\n";
    ponyOnTheHeap();
    std::cout << "Now, we see the Stack Pony\n";
    ponyOnTheStack();
    return (0);
}
