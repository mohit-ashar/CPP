#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>

class Enemy
{
    protected:
        Enemy( void );
        int hitPoints;
        std::string enemyType;
    public:
        Enemy(int hp, std::string const & type);
        Enemy(Enemy & enemy);
        virtual ~Enemy() = 0;
        std::string const   getType() const;
        void                setType(std::string type);
        int                 getHP() const;
        void                setHP(int hp);
        virtual void        takeDamage(int damage);
        Enemy & operator=(Enemy const & enemy);
};


#endif