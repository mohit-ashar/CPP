#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
{
    this->hitPoints = hp;
    this->enemyType = type;
}

Enemy::Enemy(Enemy const & enemy)
{
    this->hitPoints = enemy.getHP();
    this->enemyType = enemy.getType();
}

Enemy::~Enemy()
{
}

std::string const     &Enemy::getType() const
{
    return (this->enemyType);
}

void            Enemy::setType(std::string type)
{
    this->enemyType = type;
}

int             Enemy::getHP() const
{
    return (this->hitPoints);
}

void            Enemy::setHP(int hp)
{
    this->hitPoints = hp;
}

void            Enemy::takeDamage(int damage)
{
    std::cout << this->enemyType << " took a damage of " << damage << std::endl;
    if (damage < 0)
        return;
    if (this->getHP() - damage < 0)
    {
        this->setHP(0);
        return;
    }
    this->setHP(this->getHP() - damage);
}

Enemy & Enemy::operator = (Enemy const & enemy)
{
    if (this != &enemy)
    {
        this->enemyType = enemy.getType();
        this->hitPoints = enemy.getHP();
    }
    return (*this);
}