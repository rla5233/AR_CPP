#include "Town.h"
#include <iostream>
#include <conio.h>
#include "Player.h"

void Town::WeaponUp(Player& _Player)
{
    // �����е��� �ǵ���� �ϴ� �κ��� ���� ���Դϴ�.

    // 1. �÷��̾��� ������ ��ȭ ���¸� �����ش�.
    // ���� �׷����� �������� ���δ� �����.
    // 1���������� ��ȭ
    //   30���� ������ �α�� ��ȭ�� �ȵȴٰ� �����.
    // 
    // 2���������� ������.

    // 2.��
    // 1������ 10�������� �����ص� ��ȭ��ġ�� �������� �ʽ��ϴ�.
    // 10������ 20�������� �����ϸ� ��ȭ��ġ�� 5�� �������ϴ�.
    // 20������ 30�������� �����ϸ� ��ȭ��ġ�� 0�� �˴ϴ�.
    // ��ȭȮ���� �������

    printf_s("��ȭ������ ���� ������ �ʾҽ��ϴ�.");
    int Select = _getch();
}

void Town::Heal(Player& _Player)
{
    printf_s("�÷��̾�� ġ��Ǿ����ϴ�.");
    int Select = _getch();
}

void Town::In(Player& _Player)
{
    while (true)
    {
        _Player.StatusRender();
        printf_s("�������� ������ �Ͻðڽ��ϱ�.\n");
        printf_s("1. ��ȭ.\n");
        printf_s("2. ġ��.\n");
        printf_s("3. ������.\n");
        int Select = _getch();

        switch (Select)
        {
        case '1':
            WeaponUp(_Player);
            break;
        case '2':
            //Heal();
            break;
        case '3':
            return;
        default:
            break;
        }

        system("cls");
    }

}
