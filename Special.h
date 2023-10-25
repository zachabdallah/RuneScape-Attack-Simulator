#pragma once
#include "Ability.h"


class Special : public virtual Ability{
private:
    double adrenaline_cost;
    double adrenaline_requirement;
    string type = "special";
public:
    Special();
    Special(string name, double max_damage, double min_damage, double number_of_hits, double time_to_channel, double time_until_damage_is_fully_applied, double cooldown, double stun_duration, double bind_duration, int bleed, int puncture, int walk_modifier, double adrenaline_cost, double adrenaline_requirement);
    void setAdrenalineCost(double n);
    void setAdrenalineRequirement(double n);
    double getAdrenalineCost() const;
    double getAdrenalineRequirement() const;
    void print() override;
    string getType() override{ return type ;};
    Special* copy(Special* class_that_is_passed);
};

