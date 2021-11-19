/* 5�� ���Ͽ�, Ȳ���� */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



INPUT_RECORD rec; // �ܼ� �Է� ������ �Է� �̺�Ʈ ����ü->����ü �ȿ� MouseEvent�� ����
DWORD dwNOER;

HANDLE CIN = 0; //�ܼ� �Է���ġ
HANDLE COUT = 0;    // �ܼ� ��� ��ġ

int loading(); //������ �ε��Լ�
void mapcreate(); // �� �����Լ�
void gotoxy(int x, int y); //Ŀ���� x, y�� �̵���Ű�� �Լ�
void gameendf(); // ���� ����� 
void clearcon(); //�ܼ�â ȭ���� ����� �Լ�
void CheckMouse(int* yy, int* xx, int* lr); //���콺 Ŭ�� �Լ�
void setColor(int cl);

int map[30][30]; 
int ga, se;


int main() {

    int i, j;
    int lga = 0, lse = 0, lr = 0;
    int a = 0;
    int endf = 0;



    CONSOLE_CURSOR_INFO cursorInfo = { 0, }; // Ŀ�� �����
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);


    loading();


    CIN = GetStdHandle(STD_INPUT_HANDLE);
    // ���콺 Ȱ��ȭ
    GetConsoleMode(CIN, &dwNOER); // ���� �ܼ� �Է� ��带 �����´�
    SetConsoleMode(CIN, dwNOER | ENABLE_MOUSE_INPUT); // ���콺 �Է��� ����Ѵ�.

    clearcon();
    mapcreate();

    while (1) {

        if (a != 0) {

            CheckMouse(&lse, &lga, &lr);

            lse = lse - 1;
            lga = lga / 2;

            if (lr == 1 && map[lse][lga] != 1 && map[lse][lga] != 2)
            {
                map[lse][lga] = 1;
            }
            if (lr == 1 && map[lse][lga] == 2)
            {
                endf++;
            }
        }
        if (a == 0) a++;

        gotoxy(0, 0);


        printf("�������ӽ���\n");

        for (i = 0; i < se; i++) { //Ʋ����� 
            for (j = 0; j < ga; j++) {


                if (map[i][j] == 1)
                    printf("��"); //���õ� ĭ ǥ��

                else if (map[i][j] == 2)//���� ���
                {
                    printf("��");
                }
                else
                {
                    printf("��"); //���� ������ ĭ ǥ��

                }

            }
            printf("\n");

        }


        if (endf != 0) {

            clearcon();
            gameendf();
            break;
        }
    }
    return 0;

}

int loading() {

    int n;
    printf("�� ĭ�� �������� �� ���ΰ���?(n*nĭ) n : ");
    while (1) {
        scanf("%d", &n);
        if (1 <= n && n <= 30)
            break;
        printf("1�̻� 30���Ϸ� �Է����ּ��� :");
    }
    ga = n;
    se = n;

    return n;

}

void mapcreate() {

    int i, j;
    int gatsu;

    for (i = 0; i < se; i++) { //�迭 �ʱ�ȭ
        for (j = 0; j < ga; j++) {
            map[i][j] = 0;
        }
    }

    gatsu = ga;

    for (i = 0; i < gatsu; i++) {  //�λ���
        for (j = 0; j < gatsu; j++)
        {
            map[i][j] = rand() % ga + 2;  //1�϶� ���õǰ� 2�϶� ������ �����ǰ�
        }
    }

}

void gotoxy(int x, int y) {

    COORD coord = { 0,0 };
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void gameendf() {

    printf("\n\n");
    setColor(15);
    printf("    ###           ###   \n");
    setColor(12);
    printf("    # #           # #    \n");
    setColor(12);
    printf("  ##  #           #  ##  \n");
    setColor(6);
    printf(" #     !#########!    #  \n");
    setColor(6);
    printf("  ###  #.       .#  ###  \n");
    setColor(14);
    printf("     :#~         ~#:     \n");
    setColor(14);
    printf("     #.           .#     \n");
    setColor(10);
    printf("     #             #     \n");
    setColor(10);
    printf("     #  ##     ##  #    \n");
    setColor(2);
    printf("     # ~# #   # #~ #  \n");
    setColor(2);
    printf("     # ~###   ###~ #     \n");
    setColor(11);
    printf("     # ~###   ###~ #    \n");
    setColor(11);
    printf("     #  ##  #  ##  #     \n");
    setColor(9);
    printf("     $     ###     $  \n");
    setColor(9);
    printf("      #    ###    #      \n");
    setColor(1);
    printf("     :~#         # ~:   \n");
    setColor(1);
    printf("  ###  ~.# # # #.~  ###  \n");
    setColor(13);
    printf("  #      $ # # $      #  \n");
    setColor(13);
    printf("  ##  #  $#####$  #  ##  \n");
    setColor(15);
    printf("    # #           # #    \n");
    setColor(15);
    printf("    ###           ###  \n");
    setColor(15);
    printf("\n        Game over\n");

}

void setColor(int cl) //�������Լ�
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cl);
}

void clearcon() {

    COORD Coor = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Coor, &dw);

}

void CheckMouse(int* yy, int* xx, int* lr) {

    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.

    if (rec.EventType == MOUSE_EVENT) {// ���콺 �̺�Ʈ�� ���



        if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���

            int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
            int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�


            if (mouse_x < ga * 2 && mouse_y < se + 1) {
                *xx = mouse_x;
                *yy = mouse_y;
                *lr = 1;

            }


        }

        else {
            int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
            int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

            if (mouse_x < ga * 2 && 0 < mouse_y && mouse_y < se + 1) {

                *lr = 3;
            }

        }
    }

    Sleep(10);
}