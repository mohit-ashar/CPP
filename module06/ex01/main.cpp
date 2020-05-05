#include "Serialization.hpp"

int main()
{
    Serialization s;
    void *raw = s.serialize();
	Serialization::Data *data = s.deserialize(raw);

	std::cout << "# recovered data" << std::endl;
	std::cout << "s1 = " << data->s1 << std::endl;
	std::cout << "n  = " << data->n << std::endl;
	std::cout << "s2 = " << data->s2 << std::endl;
	delete (char *)raw;
	delete data;

}