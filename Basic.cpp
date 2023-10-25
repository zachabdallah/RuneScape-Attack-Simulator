#include "Basic.h"

Basic::Basic() { //default constructor     this->name = "basic ability";
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
    //new
    this->adrenaline_gain = 0.0;
}
Basic::Basic(string name, double max_damage, double min_damage, double number_of_hits, double time_to_channel, double time_until_damage_is_fully_applied, double cooldown, double stun_duration, double bind_duration, int bleed, int puncture, int walk_modifier, double adrenaline_gain) {
    
    this->name = name;
    this->max_damage = max_damage;
    this->min_damage = min_damage;
    this->average_damage = (min_damage + max_damage) / 2.0;
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
    this->adrenaline_gain = adrenaline_gain;
}
void Basic::setAdrenalineGain(double n) {
    this->adrenaline_gain = n;
}
double Basic::getAdrenalineGain() const {
    return this->adrenaline_gain;
}
void Basic::setCaroming(int n) {
    number_of_hits += n;
    for (int i = 0; i < n; ++i) {
        min_damage += 0.05;
        max_damage += 0.15;
    }
    average_damage = (min_damage + max_damage) / 2.0;
}
void Basic::print() {
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
    cout << "Adrenaline gain: " << adrenaline_gain << endl;
}

Basic* Basic::copy(Basic* class_that_is_passed) {
    Basic* new_class = new Basic();
    *new_class = *class_that_is_passed;
    return new_class;
}

