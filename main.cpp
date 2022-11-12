#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

//public declarations
string rarities[7] = {"Common", "Uncommon", "Rare", "Epic", "Legendary", "Mythic", "Divine"};
string action;
string animals[] = {"Dog", "Cat", "Sheep", "Goat", "Horse", "Whale", "Dolphin", "Shark", "Swift", "Eagle", "Cow", "Chicken", "Chick"};

//hunt code
void hunt() {
    cout << "You Went Hunting..." << endl;

    srand(time(0));

    int a = (rand() % 7);
    int b = (rand() % 13);

    cout << "You got " << rarities[a] << " " << animals[b] << endl;

    ofstream out("playerdata.db", ios::app);
    out << a << " " << b << "\n";
    srand(time(0));
}

void viphunt() {
    int vha;
    int hn;
    cout << "Note that autohunting is 2x slower than manual hunting!";
    cout << "Please enter how many times you want to hunt: ";
    cin >> vha;

    //if (vha > 20) {
    //    cout << "You cannot autohunt more than 20 times!" << endl;
    //    exit(0);
    //}
    while (hn < vha) {
        sleep(2);
        hunt();
        hn++;
    }
}

void invz() {
    cout << "Your Animals" << endl;

    //read db
    std::ifstream infile("playerdata.db");  
    int a, b;
    while (infile >> a >> b)
    {
        //print db
        cout << " - " << rarities[a] << " " << animals[b] << endl;
    }
}
//lootbox code
void lootbox() {
    cout << "LootBox Code!" << endl;
}
//weapon crate code
void wcrate() {
    cout << "Weapon Crate Code!" << endl;
}

//get initial user input
void userinput() {
    cout << endl << "OwO Bot's currency system remade in c++" << endl << endl;
    cout << "Select Next Action" << endl;
    cout << "1: Hunt" << endl;
    cout << "2: Open Lootbox" << endl;
    cout << "3: Open Weapon Crate" << endl;
    cout << "4: See Your Animal List" << endl;
    cout << " > "; cin >> action;
}

//choose what to do upon user action
void selaction() {
    if (action == "1") {
        sleep(1);
        hunt();
    } else if (action == "2") {
        lootbox();
    } else if (action == "3") {
        wcrate();
    } else if (action == "4") {
        invz();
    //} else if (action == "5") {
        //viphunt();
    } else {
        cout << "Invalid Input!" << endl;
    }
}


//assemble
int main()
{   
    userinput();
    selaction();
}