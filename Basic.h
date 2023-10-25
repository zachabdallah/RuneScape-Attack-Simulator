#pragma once
#include "Ability.h"

class Basic : public virtual Ability{
private:
    double adrenaline_gain;
    string type = "basic";
public:
    Basic();
    Basic(string name, double max_damage, double min_damage, double number_of_hits, double time_to_channel, double time_until_damage_is_fully_applied, double cooldown, double stun_duration, double bind_duration, int bleed, int puncture, int walk_modifier, double adrenaline_gain);
    void setAdrenalineGain(double n);
    double getAdrenalineGain() const;
    void setCaroming(int n);
    void print() override;
    string getType() override{ return type ;};
    Basic* copy(Basic* class_that_is_passed);
};
