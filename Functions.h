#pragma once
void printAll(Ability* array[]);
void Initialize_Array(Ability * array[]);
void applyEquillibrium(Ability* array[], int optional = 0);
void applyPrecise(Ability* array[], int optional = 6);
void applyCaroming(Basic &GreaterRicochet, int optional = 4);
void applyFlanking(Basic &BindingShot, Threshold &TightBindings, int optional = 0);
void applyIgneousCape(Ultimate &Deadshot);
void applyT99prayer(Ability * array[]);
void applyElderOverload(Ability * array[]);
void copyEverything(Ability * array[], Ability * original_values[]);
//void simulateAttackRotation(Ability **array);
double soulSplit(double dmg_number);
void splitSoul(Ability * array[], double ability_damage);


