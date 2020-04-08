//
// Created by Сергей on 08.04.2020.
//

#pragma once

#include "Essence.h"
#include <string>

using namespace std;

class Monsters : public Essence
{
private:
    string name;
public:
    Monsters()
    {
        name = "Procreation of evil";
        maxHp = 50;
        hp = 50;
        mp = 3;
        damage = 9;
        armor = 0;
    }
    Monsters(string name)
    {
        SetName(name);
        maxHp = 50;
        hp = 50;
        mp = 3;
        damage = 9;
        armor = 0;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()
    {
        return name;
    }
    void SetHealthDamage(int damage)
    {
        if (armor < damage)
        {
            this->hp = hp - (damage - armor);
        } else {
            this->hp = hp - 1;
        }
    }
    void SetHealthRecovery(int heal)
    {
        this->hp = hp + heal;
        if(hp > maxHp)
        {
            hp = maxHp;
        }
    }
    int GetHP()
    {
        return hp;
    }
    int GetDamage()
    {
        return damage;
    }
    void SetArmor(int armor)
    {
        this->armor = armor;
    }
    int GetArmor()
    {
        return armor;
    }
};
