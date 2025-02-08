#include <iostream>
#include "GameView.h"
#include "GameScene.h"

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    try
    {
        // NOTE: ���� ��� �������� ����� ����� ��������� ����������,
        // �� ������ ������. ���������� �� ����� ����� � �������
        // ������ new/delete �� make_unique � unique_ptr.

        GameView* pGameView = NewGameView({ 800, 600 });
        GameScene* pGameScene = NewGameScene();

        // �������� ���� GameLogic* ����� ������������ � void*.
        EnterGameLoop(*pGameView, UpdateGameScene, DrawGameScene, pGameScene);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
