#include <stdio.h>

int main()
{
    FILE* mf;
    char str[50];
    char* estr;
    printf("Открытие файла: ");
    mf = fopen("input.txt", "r");

    if (mf == NULL) {
        printf("ошибка\n");
        return -1;
    } else
        printf("выполнено\n");

    printf("Считаны строки:\n");

    while (1) {
        estr = fgets(str, sizeof(str), mf);

        if (estr == NULL) {
            if (feof(mf) != 0) {
                printf("\nЧтение файла закончено\n");
                break;
            } else {
                printf("\nОшибка чтения из файла\n");
                break;
            }
        }
        printf("%s", str);
    }
    printf("Закрытие файла: ");
    if (fclose(mf) == EOF)
        printf("ошибка\n");
    else
        printf("выполнено\n");
    getchar();
}
