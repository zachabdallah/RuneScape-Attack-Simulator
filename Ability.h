#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ability{
protected:
    string name;
    double average_damage;
    double max_damage;
    double min_damage;
    double number_of_hits;
    double time_to_channel;
    double time_until_damage_is_fully_applied;
    double cooldown;
    double stun_duration;
    double bind_duration;
    int    bleed;
    int    puncture;
    int    walk_modifier;
    string type = "no type";
public:
    //getters
    virtual string getType() = 0;
    virtual void print() = 0;
    
    string getName();
    double getMax();
    double getMin();
    double getAverage();
    double getNumHits();
    double getTimeToChannel();
    double getTimeUntilFullyApplied();
    double getCooldown();
    int getBleed();
    int getPuncture();
    double getStunDuration();
    double getBindDuration();
    //setters
    void addToMin(double n);
    void addToMax(double n);
    void setMin(double n);
    void setMax(double n);
    void subtractFromMax(double n);
    void setStunDuration(double n);
    void setBindDuration(double n);
    void setNumHits(double n);
};
