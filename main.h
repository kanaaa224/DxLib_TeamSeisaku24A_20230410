#pragma once

//ゲームモード管理
enum MODE{
	TITLE,
	INIT,
	MAIN,
	HELP,
	RESULT,
	INPUTNAME,
	RANKING,
	END,
	EXIT = 99
};

MODE gGameMode = TITLE;