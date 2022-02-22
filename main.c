#include <stdio.h>

int main()
{
    FILE* fp;
    char name[] = "my.txt";
    if ((fp = fopen(name, "r")) == NULL) {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    } else {
        printf("Удалось открыть файл");
    }

    fclose(fp);
    getchar();
}
