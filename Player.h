//
// Created by Сергей on 08.04.2020.
//

#pragma once

#include "Essence.h"
#include <string>

using namespace std;

class Player : public Essence {
private:
    string name;
public:
    Player()
    {
        name = "Wanderer";
        maxHp = 100;
        hp = 100;
        mp = 6;
        damage = 2;
        armor = 0;
    }
    Player(string name)
    {
        SetName(name);
        maxHp = 100;
        hp = 100;
        mp = 6;
        damage = 2;
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
    void SetMP(int mp)
    {
        this->mp = mp;
    }
    int GetMP()
    {
        return mp;
    }
    void SetDamage(int damage)
    {
        this->damage = damage;
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

