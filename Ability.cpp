#include <string>
#include "Ability.h"

string Ability::getName() {
    return name;
}
double Ability::getMin() {
    return min_damage;
}
double Ability::getMax() {
    return max_damage;
}
double Ability::getAverage(){
    return average_damage;
}
int Ability::getBleed() {
    return bleed;
}
void Ability::addToMin(double n) {
    min_damage += n;
    average_damage = (min_damage + max_damage) / 2.0;
}
void Ability::addToMax(double n) {
    max_damage += n;
    average_damage = (min_damage + max_damage) / 2.0;
}
void Ability::setMin(double n) {
    min_damage = n;
    average_damage = (min_damage + max_damage) / 2.0;
}
void Ability::setMax(double n) {
    max_damage = n;
    average_damage = (min_damage + max_damage) / 2.0;
}
void Ability::subtractFromMax(double n) {
    max_damage -= n;
    average_damage = (min_damage + max_damage) / 2.0;
}
void Ability::setStunDuration(double n) {
    stun_duration = n;
}
void Ability::setBindDuration(double n) {
    bind_duration = n;
}
void Ability::setNumHits(double n) {
    number_of_hits = n;
}

