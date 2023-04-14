// ��F����

#include "resourceLoad.h"
#include "DxLib.h"

Resourceload resourceload;
Image image;
Sound sound;
Font font;

int LoadImages(void)
{
	if ((image.title = LoadGraph("Resources/Images/title.png")) == -1) return -1;
	if ((image.controller = LoadGraph("Resources/Images/controller.png")) == -1) return -1;
	if ((image.controller_s = LoadGraph("Resources/Images/controller_sokumen.png")) == -1) return -1;
	//if ((image.apple = LoadGraph("Resources/Images/apple.png")) == -1) return -1;
	return 0;
}

int LoadSounds(void)
{
	//if ((sound.bgm = LoadSound("Resources/Sounds/bgm.mp3")) == -1) return -1;
	//if ((sound.se = LoadSound("Resources/Sounds/se_1.mp3")) == -1) return -1;
	return 0;
}

int LoadFonts(void)
{
	LPCSTR font_path = "Resources/Fonts/syokakiutage.ttf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) < 0) {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}
	if (font.state == 0) {
		font.handle_1 = CreateFontToHandle("���傩���������i�����Łj", 128, 9, DX_FONTTYPE_EDGE);
		//font.handle_2 = �ǉ��t�H���g�̃p�X
		font.state = 1;
	}
	//if ((font.s = LoadFont("Resources/Fonts/syokakiutage.ttf")) == -1) return -1;
	return 0;
}

int ResourceLoad(void)
{
	if (resourceload.state == 0) {
		if (LoadImages() == -1) return -1;
		if (LoadSounds() == -1) return -1;
		if (LoadFonts() == -1) return -1;
		resourceload.state = 1;
	}
	return 0;
}



/* old - image.h
// ��F����


#pragma once
#include "DxLib.h"

// �摜�p�̍\����
class Image {
public:
	int handle;
	char* filename;
};

// �摜��ǂݍ��ފ֐��̃v���g�^�C�v�錾
int LoadImage(Image& image, const char* filename);

// �摜��`�悷��֐��̃v���g�^�C�v�錾
void DrawImage(Image& image, int x, int y);


class IMAGE {
public:

	int Title;

	void print();
};

// �����o�[�֐��i���\�b�h�j�̒�`�Ə���
// :: �̓X�R�[�v���Z�q
void IMAGE::print() {
	printf("x : %lf y : %lf\n", x, y);
};
*/

/* old - image.cpp
// ��F����


#include "image.h"

// �摜��ǂݍ��ފ֐�
int LoadImage(Image& image, const char* filename) {
	if ((image.handle = LoadGraph(filename)) == -1) return -1;
	return 0;
}

// �摜��`�悷��֐�
void DrawImage(Image& image, int x, int y) {
	DrawGraph(x, y, image.handle, TRUE);
}

*/