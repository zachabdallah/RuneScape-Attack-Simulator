#include "Ultimate.h"

Ultimate::Ultimate() {
    this->name = "ultimate ability";
    this->average_damage = 0.0;
    this->max_damage = 0.0;
    this->min_damage = 0.0;
    this->number_of_hits = 0.0;
    this->time_to_channel = 0.0;
    this->time_until_damage_is_fully_applied = 0.0;
    this->cooldown = 0.0;
    this->stun_duration = 0.0;
    this->bind_duration = 0.0;
    this->bleed = 0;
    this->puncture = 0;
    this->walk_modifier = 0;
    this->adrenaline_cost = 0.0;
    this->adrenaline_requirement = 0.0;
}
Ultimate::Ultimate(string name, double max_damage, double min_damage, double number_of_hits, double time_to_channel, double time_until_damage_is_fully_applied, double cooldown, double stun_duration, double bind_duration, int bleed, int puncture, int walk_modifier, double adrenaline_cost, double adrenaline_requirement) {
    
    this->name = name;
    this->max_damage = max_damage;
    this->min_damage = min_damage;
    this->average_damage = (min_damage + max_damage) / 2;
    this->number_of_hits = number_of_hits;
    this->time_to_channel = time_to_channel;
    this->time_until_damage_is_fully_applied = time_until_damage_is_fully_applied;
    this->cooldown = cooldown;
    this->stun_duration = stun_duration;
    this->bind_duration = bind_duration;
    this->bleed = bleed;
    this->puncture = puncture;
    this->walk_modifier = walk_modifier;
    //new
    this->adrenaline_cost = adrenaline_cost;
    this->adrenaline_requirement = adrenaline_requirement;
}
void Ultimate::setAdrenalineCost(double n) {
    this->adrenaline_cost = n;
}
void Ultimate::setAdrenalineRequirement(double n) {
    this->adrenaline_requirement = n;
}
double Ultimate::getAdrenalineCost() const {
    return this->adrenaline_cost;
}
double Ultimate::getAdrenalineRequirement() const {
    return this->adrenaline_requirement;
}
void Ultimate::print() {
    cout << "Name: " << name << ", " << type << endl;
    cout << "Average damage: " << average_damage << endl;
    cout << "Maximum damage: " << max_damage << endl;
    cout << "Minimum damage: " << min_damage << endl;
    cout << "Number of hits: " << number_of_hits << endl;
    cout << "Time to channel: " << time_to_channel << endl;
    cout << "Time until fully applied: " << time_until_damage_is_fully_applied << endl;
    cout << "Cooldown: " << cooldown << endl;
    cout << "Stun duration: " << stun_duration << endl;
    cout << "Bind duration: " << bind_duration << endl;
    cout << "Bleed: " << bleed << endl;
    cout << "Puncture: " << puncture << endl;
    cout << "Walk modifier: " << walk_modifier << endl;
    cout << "Adrenaline cost: " << adrenaline_cost << endl;
    cout << "Adrenaline requirement: " << adrenaline_requirement << endl;
}

Ultimate* Ultimate::copy(Ultimate* class_that_is_passed) {
    Ultimate* new_class = new Ultimate();
    *new_class = *class_that_is_passed;
    return new_class;
}
