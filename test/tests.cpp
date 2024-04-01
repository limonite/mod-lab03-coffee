// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
 protected:
    Automata Machine;
};

TEST(AutomataTest, TEST1) {
    Automata Machine;
    Machine.on();
    Machine.off();
    Machine.on();
    Machine.on();
    Machine.off();
    EXPECT_EQ(OFF, Machine.getState());
}

TEST(AutomataTest, TEST2) {
    Automata Machine;
    Machine.on();
    Machine.coin(79);
    Machine.choice("Americano");
    EXPECT_EQ(false, Machine.check("Americano"));
}

TEST(AutomataTest, TEST3) {
    Automata Machine;
    Machine.on();
    Machine.coin(79);
    Machine.choice("Americano");
    EXPECT_EQ(false, Machine.check("Americano"));
}

TEST(AutomataTest, TEST4) {
    Automata Machine;
    Machine.on();
    Machine.coin(500);
    Machine.choice("Latte Maciato");
    Machine.cook("Latte Maciato");
    Machine.finish("Latte Maciato");
    EXPECT_EQ(WAIT, Machine.getState());
}

TEST(AutomataTest, TEST5) {
    Automata Machine;
    Machine.on();
    Machine.coin(300);
    Machine.choice("Espresso");
    Machine.cook("Espresso");
    Machine.finish("Espresso");
    EXPECT_EQ(WAIT, Machine.getState());
}
