// Copyright 2022 GHA Test Team

#pragma once
#include <string>
#include <map>
#include <list>

enum states { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {

private:
	float cash;
	map<string, int> prices;
	states state;

public:
    Automata();
    void on();
    void off();
    void coin(int money);
    void getMenu();
    states getState();
    void choice(std::string name);
    bool check(std::string name);
    void cancel();
    void cook(std::string name);
    void finish(std::string name);
};
