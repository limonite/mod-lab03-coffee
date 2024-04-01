// Copyright 2022 GHA Test Team

#include <iostream>
#include "Automata.h"
#include <string>
#include <list>

int main()
{
    Automata Machine;
    Machine.on();
    Machine.getMenu();
    Machine.coin(300);
    Machine.choice("Americano");
    Machine.off();
    Machine.on();
    Machine.getMenu();
    Machine.coin(100);
    Machine.coin(50);
    Machine.coin(50);
    Machine.choice("Cappucino");
    Machine.off();
}
