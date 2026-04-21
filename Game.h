#ifndef GAME_H
#define GAME_H

#include "Dice.h"

class Game {
private:
    int playerMode;   // 1 為 單人對電腦，2 為 雙人對戰
    int winCondition; // 1 為 比大，2 為 比小
    Dice dice;        // 骰子物件

    // 判斷並顯示贏家 (設為私有，因為只有遊戲內部需要呼叫)
    void showWinner(int p1Roll, int p2Roll);

public:
    Game();           // 建構子，初始化預設值
    void setup();     // 遊戲初始設定 (取得玩家輸入)
    void play();      // 開始進行遊戲
};

#endif
