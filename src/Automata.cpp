// Copyright 2022 GHA Test Team

#include "Automata.h"
#include <iostream>
#include <string>
#include <list>

Automata::Automata() {
	cash = 0;
    prices["Latte"] = 250;
    prices["Cappucino"] = 300;
    prices["Americano"] = 150;
    prices["Espresso"] = 100;
    prices["Moccochino"] = 250;
    prices["Glace"] = 350;
	state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Coffee Machine activated\n" << std::endl;
    } else {
        std::cout << "Coffee Machine is already activated\n" << std::endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Coffee Machine deactivated\n" << std::endl;
    } else {
        std::cout << "Coffee Machine is already deactivated\n" << std::endl;
    }
}

void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        cash += money;
        state = ACCEPT;
        std::cout << "Total cash: " << cash << "p.\n" << std::endl;
    } else {
        std::cout << "Error occured while coins recieving\n" << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << "Coffee machine menu:" << std::endl;
    if (state == WAIT || state == ACCEPT) {
        for (const auto& element : prices)
            std::cout << element.first << element.second << std::endl;
    }
}

states Automata::getState() {
    return state;
}

bool Automata::check(std::string name) {
    if ((state == CHECK || state == ACCEPT)
        && cash >= prices.find(name)->second)
        return true;
    state = ACCEPT;
    return false;
}

void Automata::choice(std::string name) {
    if (state == ACCEPT) {
        if (prices.count(name) == 0) {
            std::cout << "Chosen drink was not found :(\n";
        } else {
            state = CHECK;
            if (check(name))
                cook(name);
        }
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        state = WAIT;
        std::cout << "Ordering process was cancelled\n" << std::endl;
    } else {
        std::cout << "Cancel can't be performed\n" << std::endl;
    }
}

void Automata::cook(std::string name) {
    std::cout << "Cooking in progress!\n" << std::endl;
    cash -= prices.find(name)->second;
    state = COOK;
    std::cout << prices.find(name)->first << " cooked\n" << std::endl;
    finish(name);
}

void Automata::finish(std::string name) {
    std::cout << "Take a change after buying: " << cash << "p.\n" << std::endl;
    cash = 0;
    state = WAIT;
}
