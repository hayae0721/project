#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char LJW(); //�Լ�����
void Gameover();
void CheckMouse(int* yy, int* xx, int* lr);
INPUT_RECORD rec;
DWORD        dwNOER;

int main()
{
    int n;//n*n�� ����ĭ�� ����
    printf("�� ĭ�� �������� �� ���ΰ���?(n*nĭ) n : ");
    scanf("%d", &n);
    int** arr;
    arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {

        arr[i] = (int*)malloc(sizeof(int) * n);
    }



    //n*n �������� ǥ���ϱ� ���� 2���� �迭
    int i, j;   //i�� ��, j�� ��
    char c;      
    srand(time(NULL));   //�����Լ��� �������� Ȯ��

    for (i = 0; i < n; i++)   //�������� �Է�
    {
        for (j = 0; j < n; j++)  //�������� �Է�
        {
            arr[i][j] = rand() % n+2; //�����Է�
        }
    }
    while (1)     //���ѹݺ�
    {
        printf("������ : �� %d ĭ\n\n", n * n);
        printf(" ");
        for (i = 0; i < n; i++)
            printf(" %d", i + 1); //���ȣ
        printf("\n");

        for (i = 0; i < n; i++)   //�� �����
        {
            printf(" %d", i + 1);  //����ȣ
            for (j = 0; j < n; j++)  //�� �����
            {
                if (arr[i][j] == 1)
                    printf("��"); //���õ� ĭ ǥ��
                else if (arr[i][j] == 2)//���� ���
                {
                    printf("��");
                }
                else
                {
                    printf("��"); //���� ������ ĭ ǥ��
                    
                }
            }
            printf("\n");   //�ٹٲ�
        }
        
        
    ONE:
        printf("���� �����Ͻÿ� : ");
        scanf("%d", &i);     //�� ��ȣ �Է�
        if (i <= 0)       //0 ������ ���� �Է��Ҷ�
            return 0;      //���α׷� ����
        if (i > n)       //n���� ū���� �Է��Ҷ�
        {
            printf("*����! %d���� �Ѵ� ���� �����ϴ�. �ٽ� �Է��ϼ���.\n\n", n);
            goto ONE;      //ONE���� ���ư���.
        }
    TWO:
        printf("���� �����Ͻÿ� : ");
        scanf("%d", &j);     //�� ��ȣ �Է�
        if (j <= 0)       //0 ������ ���� �Է��Ҷ�
            return 0;      //���α׷� ����
        if (j > n)       // �� �������� ū���� �Է��Ҷ�
        {
            printf("*����! %d���� �Ѵ� ���� �����ϴ�. �ٽ� �Է��ϼ���.\n\n", n);
            goto TWO;      //TWO���� ���ư���.
        }
        if (arr[i - 1][j - 1] == 1)     //����� �ڸ��� ���� ���
        {
            printf("�̹� ������ ĭ�Դϴ�. �ٸ� ĭ�� �����Ͻÿ�\n");
            goto ONE;      //ONE���� ���ư���.
        }
        else if (arr[i - 1][j - 1] == 2)
        {
            Gameover();
            break;
        }

        else
        {
            arr[i - 1][j - 1] = 1;    //�����Ѵ�.
            printf("\n�ش� ��ġ�� ���� �ƴմϴ�. \n%d�� %d�� ���õƽ��ϴ�.\n\n", i, j);
          
        }


    THREE:
        printf("��� �����Ͻ÷��� 'y', �����÷��� 'n'�� �����ÿ�.\n");
        LJW();        //�Լ�ȣ��
        c = LJW();       //�Լ����� c���� �Է�
        if (c == 121)       //y�� �Է����� ���
            system("cls");     //ȭ�� �����
        else if (c == 110)      //n�� �Է����� ���
            return 0;      //���α׷� ����
        else
        {
            printf("\n'y'�Ǵ�'n'�� �Է��ϼ���\n\n");
            goto THREE;
        }
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);


}

char LJW()    //�Լ� ����
{
    char a;    //a��(���� ����)�� �Է� ����
    scanf("%c", &a); //���� �Է�
    return a;   //a���� ��ȯ
}

void Gameover()
{
    COORD Coor = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Coor, &dw); // �ܼ�â ȭ���� �����.

    printf("    ###           ###   \n");
    printf("    # #           # #    \n");
    printf("  ##  #           #  ##  \n");
    printf(" #     !#########!    #  \n");
    printf("  ###  #.       .#  ###  \n");
    printf("     :#~         ~#:     \n");
    printf("     #.           .#     \n");
    printf("     #             #     \n");
    printf("     #  ##     ##  #    \n");
    printf("     # ~# #   # #~ #  \n");
    printf("     # ~###   ###~ #     \n");
    printf("     # ~###   ###~ #    \n");
    printf("     #  ##  #  ##  #     \n");
    printf("     $     ###     $  \n");
    printf("      #    ###    #      \n");
    printf("     :~#         # ~:   \n");
    printf("  ###  ~.# # # #.~  ###  \n");
    printf("  #      $ # # $      #  \n");
    printf("  ##  #  $#####$  #  ##  \n");
    printf("    # #           # #    \n");
    printf("    ###           ###  \n");
    printf("\n        Game over\n");

   
} 

