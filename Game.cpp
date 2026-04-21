#include "Game.h"
#include <iostream>
#include <limits> 

using namespace std;

// 建構子：給定預設值
Game::Game() {
    playerMode = 1;
    winCondition = 1;
}

// 負責處理玩家設定
void Game::setup() {
    cout << "(輸入1為一個人對電腦玩，輸入2為兩個人玩)" << endl;
    cout << "玩家 : ";
    cin >> playerMode;

    cout << "(輸入1為比大，輸入2為比小): " << endl;
    cout << "比大比小: ";
    cin >> winCondition;

    // 清除輸入數字後殘留在緩衝區的 Enter 鍵，確保後面的 cin.get() 正常運作
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// 負責處理遊戲流程與規則
void Game::play() {
    int p1Roll = 0, p2Roll = 0;

    while (true) {
        // 第一點：玩家一按下 Enter
        cout << "\n玩家一按下enter開始擲骰子";
        cin.get(); // 等待玩家一按下 Enter

        // 第二點：顯示玩家一的數字
        p1Roll = dice.roll();
        cout << "玩家一擲骰子的數字是 : " << p1Roll << endl;

        if (playerMode == 1) {
            // 對電腦玩：電腦自動擲骰子，不需要按 Enter
            p2Roll = dice.roll();
            cout << "電腦擲骰子的數字是 : " << p2Roll << endl;
        }
        else {
            // 對玩家二玩：加入玩家二的專屬互動
            // 第三點：玩家二按下 Enter
            cout << "\n玩家二按下enter開始擲骰子";
            cin.get(); // 等待玩家二按下 Enter

            // 第四點：顯示玩家二的數字
            p2Roll = dice.roll();
            cout << "玩家二擲骰子的數字是:" << p2Roll << endl;
        }

        cout << "-------------------------" << endl;

        // 規則 3：數字相同則重開一次
        if (p1Roll == p2Roll) {
            cout << "點數相同！重開一次...\n" << endl;
            continue; // 跳過下面的程式，回到 while 迴圈開頭重新等待按下 Enter
        }
        else {
            // 分出勝負了，顯示贏家並跳出迴圈
            showWinner(p1Roll, p2Roll);
            break;
        }
    }
}

// 判斷輸贏的邏輯
void Game::showWinner(int p1Roll, int p2Roll) {
    bool p1Wins = false;

    if (winCondition == 1) {
        p1Wins = (p1Roll > p2Roll);
    }
    else {
        p1Wins = (p1Roll < p2Roll);
    }

    if (p1Wins) {
        cout << "=> 恭喜！玩家一 獲勝！" << endl;
    }
    else {
        if (playerMode == 1) {
            cout << "=> 很遺憾，電腦 獲勝！" << endl;
        }
        else {
            cout << "=> 恭喜！玩家二 獲勝！" << endl;
        }
    }
}