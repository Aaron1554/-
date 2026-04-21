#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

using namespace std;

int main() {
    // 根據系統當前時間設定亂數種子，確保每次執行的骰子點數真的隨機
    srand(time(NULL));

    cout << "=== 歡迎來到擲骰子遊戲 ===" << endl;

    Game myGame;       // 建立一個遊戲物件
    myGame.setup();    // 步驟 1: 設定遊戲規則
    myGame.play();     // 步驟 2: 開始玩遊戲

    cout << "\n遊戲結束！" << endl;
    return 0;
}