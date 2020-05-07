#include "Serialization.hpp"

std::string Serialization::gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    char s[] = "01234567";
    srand(time(NULL));

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
    std::string str(s);
    return (str);
}

Serialization::Serialization( void )
{
    srand(time(NULL));
    this->data.s1 = gen_random(8);
    this->data.n = rand();
    this->data.s2 = gen_random(8); 
    std::cout << "# raw data\n";
    std::cout << "s1 = " << this->data.s1 << std::endl;
    std::cout << "n  = "<< this->data.n << std::endl;
    std::cout << "s2 = " << this->data.s2 << std::endl;
}

Serialization::~Serialization( void )
{

}

Serialization::Serialization( Serialization const & s)
{
    *this = s;
    return ;
}

Serialization & Serialization::operator=(Serialization const & s)
{
    this->data = s.data;
    return (*this);
}

void*           Serialization::serialize( void )
{
    char *raw = new char(20);
    int i;
    int index;

    index = 0;
    i = 0;
    while(i < 8)
        raw[index++] = this->data.s1[i++];
    *reinterpret_cast<int*>(raw + index) = this->data.n;
    i = 0;
    index += 4;
    while(i < 8)
        raw[index++] = this->data.s1[i++];
    return (raw);
}

Serialization::Data* Serialization::deserialize(void *raw)
{
	Serialization::Data *data = new Serialization::Data;

	data->s1 = std::string(static_cast<char *>(raw), 8);
	data->n = *reinterpret_cast<int *>(static_cast<char *>(raw) + 8);
	data->s2 = std::string(static_cast<char *>(raw) + 12, 8);
	return (data);
}