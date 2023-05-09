#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"

extern Image image;
extern Font font;

extern Game game;

int FPSCount = 0;

/********************************
* GhæÊ
********************************/
void DrawEnd() { // ¢®¬
	if (FPSCount++ < 300) {

		// wi\¦
		DrawGraph(0, 0, image.title, TRUE);

		// Thank you for playing
		DrawStringToHandle(10, 10, "Thank you for playing", 0x000000, font.handle_1_128, 0xffffff);

		//»ìÒ
		DrawStringToHandle(10, 150, "»ìÒ", 0x000000, font.handle_1_64, 0xffffff);
		DrawStringToHandle(10, 230, "V¢äK@kº¹m Ü ]@Êé¬@L³ê¬",0x000000, font.handle_1_32, 0xffffff);

		// Ó«
		//SetFontSize(40); FPSáºâè­¶
		//DrawFormatString(20, 200, 0x000000, "gpµ½fÞÌNWbg");
		//SetFontSize(32);
		DrawStringToHandle(10, 270, "gpµ½fÞ", 0x000000, font.handle_1_64, 0xffffff);
		DrawStringToHandle(10, 350, "vC[æFAAAl", 0x000000, font.handle_1_32, 0xffffff);
		DrawStringToHandle(10, 390, "SæFAAAl", 0x000000, font.handle_1_32, 0xffffff);
		DrawStringToHandle(10, 430, "tHgFAAAl", 0x000000, font.handle_1_32, 0xffffff);

		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			game.mode = EXIT;
		};

		if (FPSCount == 300) {
			game.mode = EXIT;
		}
	}
};