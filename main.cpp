#include <iostream>
#include "Player.h"
#include "Monsters.h"
#include <string>

using namespace std;

bool VictoryCheck(Player player, Monsters monster);
void ShowStat(Player player, Monsters monster);
void PlayerMove(Player &player, Monsters &monster, int *counterBuff);
void Fight(Player &player, Monsters &monster);

int main()
{
Player player;
Monsters monster;

Fight(player,monster);

}

bool VictoryCheck(Player player, Monsters monster)
{
    if(monster.GetHP() <= 0)
    {
        cout << "You win";
        return true;
    }
    if(player.GetHP() <= 0)
    {
        cout << "You died";
        return true;
    }
}
void ShowStat(Player player, Monsters monster)
{
    cout << "You hp = " << player.GetHP() << endl;
    cout << "You mp = " << player.GetMP() << endl;
    cout << monster.GetName() << " hp = " << monster.GetHP() << endl << endl << endl;
}
void PlayerMove(Player &player, Monsters &monster, int *counterBuff)
{
    bool flag = true;
    int move;
    int buff;
    while (flag)
    {
        cout << "Enter: " << endl << "1 to attack" << endl << "2 to be healed (+40)" << endl << "3 to cast armor (+5 armor for 2 step) spell" << endl << "4 to cast attack (+5 damage for 2 step) spell" << endl;
        cin >> move;
        switch(move)
        {

            case 1:
                monster.SetHealthDamage(player.GetDamage());
                cout << "You attack the " << monster.GetName() << "!" << endl << endl;
                flag = false;
                break;
            case 2:
                if (player.GetMP() > 0)
                {
                    player.SetMP(player.GetMP()-1);
                    player.SetHealthRecovery(40);
                    cout << "You cast a healing spell" << endl;
                    cout << "You hp = " << player.GetHP() << endl;
                    cout << "You mp = " << player.GetMP() << endl;
                    flag = false;
                } else {
                    cout << "Low mp" << endl;
                }
                break;
            case 3:
                if (player.GetMP() > 0)
                {
                    player.SetMP(player.GetMP()-1);
                    buff = 5;
                    player.SetArmor(player.GetArmor()+buff);
                    cout << "You cast a defence spell" << endl;
                    cout << "You mp = " << player.GetMP() << endl;
                    cout << "You armor = " << player.GetArmor() << endl;
                    *counterBuff = 3;
                    flag = false;
                } else {
                    cout << "Low mp" << endl;
                }
                break;
            case 4:
                if (player.GetMP() > 0)
                {
                    player.SetMP(player.GetMP()-1);
                    buff = 5;
                    player.SetDamage(player.GetDamage()+buff);
                    cout << "You cast a attack spell" << endl;
                    cout << "You mp = " << player.GetMP() << endl;
                    cout << "You damage = " << player.GetDamage() << endl;
                    *counterBuff = 3;
                    flag = false;
                } else {
                    cout << "Low mp" << endl;
                }
        }
    }
}
void Fight(Player &player, Monsters &monster)
{
    bool fightEnd = false;
    int tempArmor;
    int tempDamage;
    int counter = 0; //счётчик ходов
    int counterBuff = 0; //счётчик баффа

    cout << "You are fighting the creation of evil, your goal is to win!" << endl << endl;

    while (!fightEnd)
    {
        if (counter < 1) //запоминает начальные параметры атаки и защиты
        {
            tempArmor = player.GetArmor();
            tempDamage = player.GetDamage();
        }

        if (counterBuff == 0) //когда бафф заканчивается, присваивааем начальные параметры атаки и защиты
        {
            player.SetArmor(tempArmor);
            player.SetDamage(tempDamage);
        }
        PlayerMove(player, monster, &counterBuff);

        fightEnd = VictoryCheck(player, monster);



        player.SetHealthDamage(monster.GetDamage());
        cout << monster.GetName() << " attacking you!" << endl;
        ShowStat(player, monster);

        fightEnd = VictoryCheck(player, monster);

        if (counterBuff > 0)
        {
            counterBuff--;
        }
        counter++;
    }
}