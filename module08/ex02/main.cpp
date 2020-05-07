#include "mutantstack.hpp"
#include <assert.h>

int main(){
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(18);
	mstack.push(123);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while(it != ite){
		std::cout << *it << std::endl;++it;
	}

    std::cout << "\n----------Copy constructor test---------" << std::endl;
	MutantStack<int> s(mstack);

    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);

    it = s.begin();
    ite = s.end();
    while(it != ite){
		std::cout << *it << std::endl;++it;
	}

    std::cout << "\n----------String stack test---------" << std::endl;
	MutantStack<std::string> sstack;

    sstack.push("Hello");
    sstack.push("Welcome");
    sstack.push("To");
    sstack.push("The Matrix");

    MutantStack<std::string>::iterator it1 = sstack.begin();
	MutantStack<std::string>::iterator ite1 = sstack.end();

    it1 = sstack.begin();
    ite1 = sstack.end();
    while(it1 != ite1){
		std::cout << *it1 << std::endl;++it1;
	}
}
