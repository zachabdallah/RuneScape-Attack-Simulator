#pragma once
#include "Ability.h"

class Threshold : public virtual Ability{
private:
    double adrenaline_cost;
    double adrenaline_requirement;
    string type = "threshold";
public:
    Threshold();
    Threshold(string name, double max_damage, double min_damage, double number_of_hits, double time_to_channel, double time_until_damage_is_fully_applied, double cooldown, double stun_duration, double bind_duration, int bleed, int puncture, int walk_modifier, double adrenaline_cost, double adrenaline_requirement);
    void setAdrenalineCost(double n);
    void setAdrenalineRequirement(double n);
    double getAdrenalineCost() const;
    double getAdrenalineRequirement() const;
    void print() override;
    string getType() override{ return type ;};
    Threshold* copy(Threshold* class_that_is_passed);
};
