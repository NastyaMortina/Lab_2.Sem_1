#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <locale.h> 

int main()
{
    setlocale(LC_ALL, "Russian");

    int i = 0;
    int n = 0;
    int Min = 0;
    int Max = 0;

    unsigned char* mas;

    printf("Количество чисел: ");
    scanf("%d", &n);
    printf("Min граница: ");
    scanf("%d", &Min);
    printf("Max граница: ");
    scanf("%d", &Max);
    printf("\n");

    if ((Max <= Min) || (Max > 255) || (Min > 255) || (Min <= 0) || (n <= 0) || (Max <= 0))
    {
        printf("Ошибка\n");
        return 0;
    }

    mas = (unsigned char*)malloc(n * sizeof(unsigned char));

    for (i = 0; i < n; i++)
    {
        mas[i] = (((((double)rand()) / RAND_MAX) * (Max - Min)) + Min);
    }

    FILE* file;
    file = fopen("textFile.txt", "w+");
    fprintf(file, "%d\n", n);

    for (i = 0; i < n; i++)
    {
        fprintf(file, "%d\n", mas[i]);
    }

    free(mas);
    fclose(file);
    return 0;
}
