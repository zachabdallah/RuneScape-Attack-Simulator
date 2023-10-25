
#include "Ability.h"
#include "Basic.h"
#include "Threshold.h"
#include "Ultimate.h"
#include "Special.h"
#include "Functions.h"
#include <unistd.h>
#include <vector>
#include <map>
map<Ability *, double> onCooldown;
vector<Ability *> cooldownVector;
template <class T>
void use(T ability){
    cout << ability->getName() << endl;
    onCooldown[ability] = 0.0;
    cooldownVector.push_back(ability);
}
int findIndexOfMax(Ability * array[]){
    int indexOfMax = 0;
    int max = 0;
    for (int i = 0; i < 20; ++i){
        bool breaker = false;
        //basically, if the ability is on cooldown then don't compare it
        for (int j = 0; j < onCooldown.size(); ++j){
            if (cooldownVector[j]->getName() == array[i]->getName()){
                breaker = true;
                break;
            }
        }
        if (breaker == true){
            continue; //go to next iteration, do not execute below.
        }
        if (array[i]->getAverage() > max){
            max = array[i]->getAverage();
            indexOfMax = i;
        }
    }
    return indexOfMax;
}
void decrementCooldowns(){
    for (int i = 0; i < cooldownVector.size(); ++i){
        
    }
}
void simulateRotation(Ability * array[]){
    //myMap[array[0]] = 0.0;
    int indexOfMax = findIndexOfMax(array);
    use(array[indexOfMax]);
    usleep(1800000); //1.8 seconds (global cooldown) : usleep takes in a parameter of microseconds
    decrementCooldowns();
}

int main() {
    
    Basic BindingShot, CorruptionShot, FragmentationShot, GreaterDazingShot, GreaterRicochet, NeedleStrike, PiercingShot, Sacrifice, Snipe, TuskasWrath;
    Threshold Bombardment, RapidFire, SaltTheWound, ShadowTendrils, SnapShot, TightBindings;
    Ultimate Deadshot, IncendiaryShot, Unload;
    Special DarkBowEOF, ecbEOF, sgbEOF;
    
    //create a pointer array of type virtual ability that can take in basics, thresholds, ultimates, and specials
    //Basically, this is an array of pointers that point to the address of abilities derived from an abstract class (an abstract class is one that contains at least one pure virtual fucntion(a pure virtual function is a member function that is overwritten in derived classes and can only be accessed in derived classes, denoted virtual f() = 0.)). (A regular virtual function is just [virtual x();] without the "=0", that would also make the class NOT abstract).
    //The reason we're using a pointer array is because we can't instantiate a class instance of an abstract class. This also is the reason why we're taking advantage of something called polymorphism since our array elements are derived. Polymorphism is a key feature of class inheritance, and its definition is that a pointer to a derived class is type-compatible with a pointer to its base class. That's why we're able to make an array that holds 4 different classes; they're all derived from Ability.
    Ability* array[] = {
        &BindingShot, &CorruptionShot, &FragmentationShot, &GreaterDazingShot, &GreaterRicochet, &NeedleStrike, &PiercingShot, &Sacrifice, &Snipe, &TuskasWrath,
        &Bombardment, &RapidFire, &SaltTheWound, &ShadowTendrils, &SnapShot, &TightBindings,
        &Deadshot, &IncendiaryShot, &Unload,
        &DarkBowEOF, &ecbEOF, &sgbEOF
    };
    Initialize_Array(array);
    
    cout << "Type: " << GreaterRicochet.getType() << endl;
    
    double player_ability_damage = 3000.0;
    cout << "Current weapon damage: " << player_ability_damage << endl;
    //apply perks and augmentations
    applyIgneousCape(Deadshot);
    applyCaroming(GreaterRicochet, 4);
    applyFlanking(BindingShot, TightBindings);
    applyEquillibrium(array, 4);
    applyPrecise(array, 6);
    cout << "Would you like to print your new damage values for each ability? 'y' for yes: " << endl;
    char z;
    cin >> z;
    if (z == 'y'){
        printAll(array);
    }
    //simulateAttackRotation(array);
    cout << "Would you like to print split soul effects for each ability? 'y' for yes: " << endl;
    cin >> z;
    if (z == 'y'){
        splitSoul(array, player_ability_damage);
    }
    cout << "Would you like to simulate an attack rotation? 'y' for yes: " << endl;
    cin >> z;
    if (z == 'y'){
        simulateRotation(array);
    }
    return 0;
}
