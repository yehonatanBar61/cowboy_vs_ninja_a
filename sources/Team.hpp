#ifndef COWBOY_VS_NINJA_A_TEAM_HPP
#define COWBOY_VS_NINJA_A_TEAM_HPP

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <cfloat>


using namespace std;
namespace ariel{}

class Point{
    private:
        double x;
        double y;

    public:
        Point(double x, double y);
        Point();
        double distance(Point point);
        string print() const;
        friend Point moveTowards(Point origin, Point target, double distance);
        double getX();
        double getY();
        // for check_eq
        bool operator==(const Point& other) const;

};

class Character{
    
    private:
        Point position;
        int HitCounter;
        string name;
    
    public:
        Character(const string &name, const Point &pos, const int HitCounter);
        Character();
        bool isAlive() const;
        double distance(const Character *c);
        void hit(int num);
        virtual string print() const;
        string getName();
        Point getLocation();
        int getHitPoint();

};

class Cowboy: public Character {
    private:
        int bullets;

    public:
        /*
            A cowboy always spawns with 6 bullets and 110 hit points
        */
        Cowboy(const string &name, const Point &position);
        /*
            If the cowboy is not dead and has bullets left, the cowboy shoots the enemy, 
            subtracting 10 hit points from the enemy - and losing 1 bullet.
            Otherwise, no damage will be done to the enemy
        */
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        string print() const;
        int getBullets();
};

class Ninja: public Character {
    
    private:
        int speed;
    
    public:
        Ninja(const string &name, const Point &position, int hitPoint, int speed);
        void move(Character *enemy);
        void slash(Character *enemy);
        string print() const;
        int getSpeed();
};

class YoungNinja: public Ninja {
    public:
        YoungNinja(const string &name, const Point &position) : Ninja(name, position, 100, 14){}
};

class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const string &name, const Point &position) : Ninja(name, position, 120, 12){}
};

class OldNinja: public Ninja {
    public:
        OldNinja(const string &name, const Point &position) : Ninja(name, position, 150, 8){}
};


class Team {
    
    private:
        vector<Character*> teaMates;
        Character *leader;
    
    public:
        Team(Character *leader);
        void add(Character *c);
        void attack(Team *enemy);
        int stillAlive() const;
        void print() const;


};

class Team2: public Team{
    Team2(Character *leader);
};






#endif //COWBOY_VS_NINJA_A_TEAM_HPP