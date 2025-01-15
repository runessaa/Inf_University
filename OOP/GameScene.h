#pragma once
#include "TmxLevel.h"

/// ��������������� ���������� (pre-declaration) ���������
///  �������� ���������� � ������� ��������� � ������ �� ��,
///  �� �� �������� ������������ ��� ���������,
///  ��������� �� ��� �� ����� �� ������ � ������, �� �������� ���������.
struct GameView;

/// ���������, �������������� ������� �����.
///  ��� ���� ��������� ������� � ����������� �����:
///  - ������������ ���������
///  - ������������ ����� ����� new � delete.
struct GameScene
{
    TmxLevel level;
    TmxObject player;
    std::vector<TmxObject> enemies;
    std::vector<TmxObject> coins;
};

GameScene* NewGameScene();
void UpdateGameScene(void* pData, GameView& view, float deltaSec);
void DrawGameScene(void* pData, GameView& view);
void DestroyGameScene(GameScene*& pScene);