
#include "Team.hpp"

using namespace ariel;

Character::Character() : position(0, 0), HitCounter(0) {}

Character::Character(const string &name, const Point &position, const int HitCounter) : name(name), position(position), HitCounter(HitCounter) {}

bool Character::isAlive() const {
    return true;
}

double Character::distance(const Character *character) {
    return this->position.distance(character->position);
}

void Character::hit(int num) {
    this->HitCounter -= num;
}

string Character::getName() {
    return this->name;
}

Point Character::getLocation() {
    return this->position;
}

int Character::getHitPoint() {
    return this->HitCounter;
}

string Character::print() const {
    return " ";
}



Cowboy::Cowboy(const string &name, const Point &position) : Character(name, position, 110), bullets(6) {}

void Cowboy::shoot(Character *enemy) {
    if (isAlive() && hasboolets()) {
        enemy->hit(10);
        this->bullets--;
    } else if (!hasboolets()) {
        this->reload();
    }
}

bool Cowboy::hasboolets() {
    if (this->bullets > 0)
        return true;
    else
        return false;
}

void Cowboy::reload() {
    this->bullets = 6;
}


string Cowboy::print() const {
    return " ";
}

int Cowboy::getBullets() {
    return this->bullets;
}


Ninja::Ninja(const string &name, const Point &position, int hitPoint, int speed) : Character(name, position, hitPoint), speed(speed) {}

void Ninja::move(Character *enemy) {
    
}

void Ninja::slash(Character *enemy) {
   
}



string Ninja::print() const {
    return " ";
}

int Ninja::getSpeed() {
    return speed;
}

