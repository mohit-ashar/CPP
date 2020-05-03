#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>

class Enemy
{
    private:
        Enemy( void );
    protected:
        int hitPoints;
        std::string enemyType;
    public:
        Enemy(int hp, std::string const & type);
        Enemy(Enemy const & enemy);
        virtual ~Enemy();
        std::string const   &getType() const;
        void                setType(std::string type);
        int                 getHP() const;
        void                setHP(int hp);
        virtual void        takeDamage(int damage);
        Enemy & operator=(Enemy const & enemy);
};


#endif