#include "DxLib.h"
#include "resourceLoad.h"
#include "Apple.h"
#include "main.h"
#include"UI.h"

extern Image image;
extern Font font;

extern Game game;
extern UI ui;

int RED_AppleCount		= 0;
int BLUE_AppleCount		= 0;
int GOLD_AppleCount		= 0;
int POISON_AppleCount	= 0;
int AppleScore = 0;

/********************************
* リザルト画面
********************************/
void DrawResult() {

	RED_AppleCount		= ReturnRA();
	BLUE_AppleCount		= ReturnBL();
	GOLD_AppleCount		= ReturnGL();
	POISON_AppleCount	= ReturnPO();
	AppleScore			= ReturnScore();

	// 背景表示
	DrawGraph(0, 0, image.title, TRUE);

	//赤　青　黄　毒　スコア
	DrawStringToHandle(160, 180, "赤リンゴ：", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 250, "青リンゴ：", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 320, "黄リンゴ：", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 390, "毒リンゴ：", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(220, 460, "スコア：", 0x000000, font.handle_1_64, 0xffffff);

	//カウント表示
	DrawFormatStringFToHandle(500, 180, 0x000000, font.handle_1_64, "%d", RED_AppleCount);
	DrawFormatStringFToHandle(500, 250, 0x000000, font.handle_1_64, "%d", BLUE_AppleCount);
	DrawFormatStringFToHandle(500, 320, 0x000000, font.handle_1_64, "%d", GOLD_AppleCount);
	DrawFormatStringFToHandle(500, 390, 0x000000, font.handle_1_64, "%d", POISON_AppleCount);
	DrawFormatStringFToHandle(500, 460, 0x000000, font.handle_1_64, "%d", AppleScore);

	// 戻る表示
	DrawStringToHandle(420, 670, "ESCキーまたはAボタンでもどる", 0x000000, font.handle_1_32, 0xffffff);

	// Space でタイトル
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};