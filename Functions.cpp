#include "Ability.h"
#include "Basic.h"
#include "Threshold.h"
#include "Ultimate.h"
#include "Special.h"
//#include <unistd.h> //for use of the sleep() function

void printAll(Ability * array[]){
    for (int i = 0; i < 20; ++i){
        array[i]->print();
        cout << endl;
    }
}

void Initialize_Array(Ability * array[]){
    *array[0] = Basic("Binding Shot", 1.0, 0.2, 1.0, 0.0, 0.0, 15.0, 0.0, 0.0, 0, 0, 0, 8.0);
    *array[1] = Basic("Corruption Shot", 3.0, 1.0, 1.0, 0.0, 6.0, 15.0, 0.0, 0.0, 1, 0, 0, 8.0);
    *array[2] = Basic("Fragmentation Shot", 0.37, 0.2, 5.0, 6.0, 0.0, 15.0, 0.0, 0.0, 1, 0, 1, 8.0);
    *array[3] = Basic("Greater Dazing Shot", 1.57, 0.31, 1.0, 0.0, 0.0, 15.0, 0.0, 0.0, 0, 1, 0, 8.0);
    *array[4] = Basic("Greater Ricochet", 2.0, 0.4, 3.0, 0.0, 1.2, 15.0, 0.0, 0.0, 0, 0, 0, 8.0);
    *array[5] = Basic("Needle Strike", 1.57, 0.31, 1.0, 0.0, 0.0, 15.0, 0.0, 0.0, 0, 0, 0, 8.0);
    *array[6] = Basic("Piercing Shot", 0.94, 0.188, 1.0, 0.0, 0.0, 15.0, 0.0, 0.0, 0, 0, 0, 8.0);
    *array[7] = Basic("Sacrifice", 1.0, 0.2, 1.0, 0.0, 0.0, 15.0, 0.0, 0.0, 0, 0, 0, 8.0);
    *array[8] = Basic("Snipe", 2.19, 1.25, 1.0, 1.8, 1.8, 15.0, 0.0, 0.0, 0, 0, 0, 8.0);
    *array[9] = Basic("Tuska's Wrath", 1.1, 0.3, 1.0, 0.0, 0.0, 15.0, 0.0, 0.0, 0, 0, 0, 8.0);
    *array[10] = Threshold("Bombardment", 2.19, 0.438, 1.0, 0.6, 0.6, 30.0, 0.0, 0.0, 0, 0, 0, 15.0, 50.0);
    *array[11] = Threshold("Rapid Fire", 0.94, 0.188, 8.0, 4.8, 4.8, 20.4, 3.6, 9.6, 0, 0, 0, 15.0, 50.0);
    *array[12] = Threshold("Salt the Wound", 1.88, 0.376, 1.0, 0.0, 0.0, 15.0, 0.0, 0.0, 0, 1, 0, 15.0, 50.0);
    *array[13] = Threshold("Shadow Tendrils", 1.0, 0.33, 4.124, 0.6, 0.6, 45.0, 0.0, 0.0, 0, 0, 0, 15.0, 50.0);
    *array[14] = Threshold("Snap Shot", 3.3, 2.0, 2.0, 0.0, 0.0, 20.4, 0.0, 0.0, 0, 0, 0, 15.0, 50.0);
    *array[15] = Threshold("Tight Bindings", 2.0, 0.4, 1.0, 0.0, 0.0, 15.0, 3.6, 9.6, 0, 0, 0, 15.0, 50.0);
    
    *array[16] = Ultimate("Deadshot", 0.62, 0.62, 6.0, 0.0, 0.0, 20.4, 0.0, 0.0, 1, 0, 0, 100.0, 100.0);
    *array[17] = Ultimate("Incendiary Shot", 3.5, 2.5, 1.0, 0.0, 3.6, 20.4, 0.0, 0.0, 0, 0, 0, 100.0, 100.0);
    *array[18] = Ultimate("Unload", 8.4, 3.8, 4.0, 4.2, 4.2, 60.0, 0.0, 0.0, 0, 0, 0, 100.0, 100.0);
    
    *array[19] = Special("Dark Bow EOF", 6.76, 2.96, 2.0, 4.8, 4.8, 20.4, 3.6, 9.6, 0, 0, 0, 65.0, 65.0);
    
}
void applyEquillibrium(Ability * array[], int optional = 0){
    if (optional == 0){
        cout << "equillibrium level set to 0 " << endl;
    }
    else{
        int equillibrium_level = optional;;
        double min_modifier = 0.03; //3% more minimum damage
        double max_modifier = 0.01; //1% less maximum damage
        double damage_range; //the damage range is basically just max minus min. so its 80 if ability is 20% - 100% damage.
        cout << "equillibrium level set to " << equillibrium_level << endl;
        while (equillibrium_level < 0 || equillibrium_level > 4){
            cout << "sorry, that is not a valid level, please re-enter\n";
            cin >> equillibrium_level;
        }
        for (int i = 0; i < 20; ++i){
            if (equillibrium_level == 0){
                cout << "Equillibrium not being used.\n";
                break;
            }
            if (array[i]->getBleed() == 0){ //equillibrium does not affect bleeds
                damage_range = array[i]->getMax() - array[i]->getMin();
                cout << array[i]->getName() << ": " << array[i]->getMin() * 100 << "% - " << array[i]->getMax() * 100 << "% is now ";
                array[i]->addToMin(min_modifier * equillibrium_level * damage_range);
                array[i]->subtractFromMax(max_modifier * equillibrium_level * damage_range);
                cout << array[i]->getMin() * 100 << "% - " << array[i]->getMax() * 100 << "%" << endl;
                
            }
        }
    }
}
void applyPrecise(Ability * array[], int optional = 0){
    //Modify damage values by incorporating precise
    //The current formula is: (max + (min + (precise_level * 1.5% * max))) / 2
    //Does precise modify damage after equillibrium?
    if (optional == 0){
        cout << "precise level set to 0" << endl;
        return;
    }
    else{
        int precise_level = optional;
        cout << endl << endl << "precise level set to " << precise_level << endl;
        while (precise_level < 0 || precise_level > 6){
            cout << "Please re-enter, that is not valid\n";
            cin >> precise_level;
        }
        for (int i = 0; i < 20; ++i){
            if (precise_level == 0){
                cout << "Precise not being used. \n";
                break;
            }
            if (array[i]->getBleed() == 0){//precise does not affect bleeds
                cout << array[i]->getName() << ": average increase of " << (((((array[i]->getMin() + (precise_level * 0.015 *array[i]->getMax())) +
                                                                               array[i]->getMax()) /2 ) / ((array[i]->getMin() + array[i]->getMax())/2))-1)*100 << "%   ";
                cout << array[i]->getName() << ": " << array[i]->getMin() * 100 << "% - " << array[i]->getMax() * 100 << "% is now ";
                array[i]->addToMin(precise_level * 0.015 * array[i]->getMax());
                cout << array[i]->getMin() * 100 << "% - " << array[i]->getMax() * 100 << "%" << endl;
            }
        }
    }
    cout << endl;
}
void applyCaroming(Basic &GreaterRicochet, int optional = 0){
    if (optional == 0){
        cout << "caroming level set to 0" << endl;
        return;
    }
    else{//caroming is active 1-4
        int caroming_level = optional;
        cout << "caroming level set to " << caroming_level << endl;
        while (caroming_level < 0 || caroming_level > 4){
            printf("sorry, that is not a valid level, please re-enter\n");
            cin >> caroming_level;
        }
        if (caroming_level == 0){
            return;
        }
        GreaterRicochet.setCaroming(caroming_level);
    }
}
void applyFlanking(Basic &BindingShot, Threshold &TightBindings, int optional = 0){
    if (optional == 0){
        cout << "flanking level set to 0 "<< endl;
        return;
    }
    else{ //flanking is active 1-4
        int flanking_level = optional;
        cout << "flanking level set to " << flanking_level << endl;
        while (flanking_level < 0 || flanking_level > 4){
            printf("sorry, that is not a valid level, please re-enter\n");
            cin >> flanking_level;
        }
        if (flanking_level == 0){
            cout << "Flanking is not being used, got it.\n";
        }
        else{
            cout << "Binding shot and Tight bindings no longer stun or bind...\n";
            BindingShot.setStunDuration(0.0);
            BindingShot.setBindDuration(0.0);
            TightBindings.setStunDuration(0.0);
            TightBindings.setBindDuration(0.0);
        }
        int i = 0;
        while (i < flanking_level){
            BindingShot.addToMin(0.08);
            BindingShot.addToMax(0.40);
            TightBindings.addToMin(0.06);
            TightBindings.addToMax(0.30);
            ++i;
        }
        return;
    }
}
void applyIgneousCape(Ultimate &Deadshot){
    Deadshot.setAdrenalineCost(40.0);
    Deadshot.setAdrenalineRequirement(60.0);
    Deadshot.setNumHits(8);
    Deadshot.addToMin(0.08);
    Deadshot.addToMax(0.08);
}
void applyT99prayer(Ability* array[]){
    for (int i = 0; i < 20; ++i){
        if (array[i]->getBleed() == 0){
            array[i]->setMin(array[i]->getMin() * 1.12); //basically we added 12% damage to all non-bleed abilities
            array[i]->setMax(array[i]->getMax() * 1.12); //the number is more like 11.947% but it varies it's always in the realm of 11.96 etc
        }
    }
}
void applyElderOverload(Ability* array[]){
    for (int i = 0; i < 20; ++i){
        if (array[i]->getBleed() == 1){
            array[i]->setMin(array[i]->getMin() * 1.0734); //this is a problem beause i need to apply this to the original damage value and not that which already has prayer bonuses applied
            array[i]->setMax(array[i]->getMax() * 1.0734);
        }
        else{
            array[i]->setMin(array[i]->getMin() * 1.135);
            array[i]->setMax(array[i]->getMax() * 1.144);
        }
    }
}
void copyEverything(Ability** array, Ability ** original_values){
    for (int i = 0; i < 20; ++i){
        
        original_values[i] = array[i];
        
    }
}
void simulateAttackRotation(Ability **array){
    //sleep(1);
    cout << "hello" << endl;
    //sleep(1);
    cout << "hello" << endl;
    //sleep(1);
    cout << "hello" << endl;
}
double soulSplit(double dmg_number){
    double additive_increase = 0.0;
    if (dmg_number <= 2000){
        return 0.1 * dmg_number;
    }
    else if (dmg_number > 2000 && dmg_number <= 4000){
        additive_increase += 0.1 * 2000;
        dmg_number -= 2000;
        additive_increase += 0.05 * dmg_number;
    }
    
    else{ //dmg is over 4000
        additive_increase += 0.1 * 2000;
        dmg_number -= 2000;
        additive_increase += 0.05 * 2000;
        dmg_number -= 2000;
        additive_increase += 0.0125 * dmg_number;
    }
    return additive_increase * 1.1875; // this will return a damage number like 400 ior 2000 for example
    //the 18.75 assumes amulet of souls average increase
}
void splitSoul(Ability **array, double ability_damage){
    cout << "Split soul dmg for each attack: (assuming soul amulet)" << endl;
    double avg_splitSoul_dmg = 0.0;
    for (int i = 0; i < 20; ++i){
        double max_damage = array[i]->getMax() * ability_damage;
        double min_damage = array[i]->getMin() * ability_damage; //these should now correspond to ingame numbers
        cout << array[i]->getName() << ": ";
        //cout << "split soul damage: " << soulSplit((int)min_damage) * 4 << " - " << soulSplit(max_damage) * 4 << " damage" << endl;
        avg_splitSoul_dmg = ((soulSplit(min_damage) * 4) + (soulSplit(max_damage) * 4)) / 2 ;
        cout << endl << "   average split soul dmg: " << avg_splitSoul_dmg << endl;
        cout << "   a dps increase of " << ((( (array[i]->getAverage() * ability_damage) + avg_splitSoul_dmg) / (array[i]->getAverage() * ability_damage)) -1 ) * 100 << "%" << endl;
    }
}
