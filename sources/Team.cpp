#include "Team.hpp"

Team::Team(Character *leader) : leader(leader){
    
}

void Team::add(Character *c) {
   
}


void Team::attack(Team *enemy) {
    
}
;
int Team::stillAlive() const{
    int counter = 0;
    for (std::size_t i = 0; i < teaMates.size(); ++i) {
        if (teaMates[i]->isAlive()) {
            counter++;
        }
    }
    return counter;
}

void Team::print() const {
    
}
