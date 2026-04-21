#include "Dice.h"
#include <cstdlib> // 提供 rand() 函數

int Dice::roll() {
    // rand() % 6 會產生 0~5 的數字，加 1 後變成 1~6
    return (rand() % 6) + 1;
}