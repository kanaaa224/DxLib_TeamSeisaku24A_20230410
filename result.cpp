#include "DxLib.h"
#include "resourceLoad.h"
#include <string>
#include "Apple.h"
#include "main.h"
#include"UI.h"
#include "ranking.h"
#include "PadInput.h"
#include "result.h"

extern Image image;	
extern Font font;

extern Game game;
extern UI ui;

using std::string;
using std::to_string;

extern int RED_AppleCount		= 0;	//赤リンゴ　個数用
extern int BLUE_AppleCount		= 0;	//青リンゴ　個数用
extern int GOLD_AppleCount		= 0;	//金リンゴ　個数用
extern int POISON_AppleCount	= 0;	//毒リンゴ　個数用
extern int AppleScore			= 0;	//スコア　　個数用

/********************************
* リザルト画面
********************************/

void DrawResult() { // 未完成

	//個数及びスコアの受け渡し
	RED_AppleCount		= ReturnRA();		//returnで返した赤リンゴの個数を代入
	BLUE_AppleCount		= ReturnBL();		//returnで返した青リンゴの個数を代入
	GOLD_AppleCount		= ReturnGL();		//returnで返した金リンゴの個数を代入
	POISON_AppleCount	= ReturnPO();		//returnで返した毒リンゴの個数を代入
	AppleScore			= ReturnScore();	//returnで返したスコアを代入

	//文字列変換	個数を増分する表示はフォントが適応されないため文字列に変換
	std::string RED = "赤リンゴ：" + std::to_string(RED_AppleCount);		//REDに赤リンゴ：個数の文字列を作成　
	std::string BLUE = "青リンゴ：" + std::to_string(BLUE_AppleCount);		//BLUEに青リンゴ：個数の文字列を作成
	std::string GOLD = "黄リンゴ：" + std::to_string(GOLD_AppleCount);		//GOLDに金リンゴ：個数の文字列を作成
	std::string POISON = "毒リンゴ：" + std::to_string(POISON_AppleCount); //POISONに毒リンゴ：個数の文字列を作成
	std::string SCORE = "スコア：" + std::to_string(AppleScore);			//SCOREにスコア：スコアの文字列を作成

	// 背景表示
	DrawGraph(0, 0, image.title, TRUE);

	//リザルト
	DrawStringToHandle(320, 70, "RESULT", 0x000000, font.handle_1_64, 0xffffff);

	//背景　白
	DrawBox(300, 160, 800, 550, 0xFDF5E6, TRUE);
	DrawBox(300, 160, 801, 551, 0x000000, FALSE);

	//赤　青　黄　毒　スコア の文字列(String)を文字(Char)に変換
	DrawStringToHandle(320, 180, RED.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 250, BLUE.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 320, GOLD.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 390, POISON.c_str(), 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(320, 460, SCORE.c_str(), 0x000000, font.handle_1_64, 0xffffff);

	//カウント表示
	//DrawFormatStringFToHandle(660, 180,  0x000000, font.handle_1_64,  "%d", RED_AppleCount);
	
	// 次へ
	DrawStringToHandle(530, 670, "Bボタンですすむ", 0x000000, font.handle_1_32, 0xffffff);
	// 仮、ボタンで分岐させる処理
	if (JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		if (GetRankingFlg() == 1) {
			game.mode = INPUTNAME;
		}
		else {
			game.mode = RANKING;
		}
	};
	// キーボード対応
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (GetRankingFlg() == 1) {
			game.mode = INPUTNAME;
		}
		else {
			game.mode = RANKING;
		}
	};

	//WaitTimer(3000);
};