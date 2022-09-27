#include "DxLib.h"
#include "game.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	//�E�B���h�E���ݒ�
	SetMainWindowText(Game::kTitleText);
	//��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ���c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//���_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		//��ʂ̃N���A
		ClearDrawScreen();

		DrawString(20, 30, "��git�̃e�X�g West", GetColor(255, 255, 255));
		DrawString(20, 60, "������", GetColor(255, 255, 255));
		DrawLine(10, 100, 90, 100, GetColor(255, 255, 255));
		//������ʂ�\��ʂƓ���ւ���
		ScreenFlip();
		//esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;
		//fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
			
		}
		
	}

	DxLib_End();				// ���c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}