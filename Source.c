#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <locale.h>
#include <time.h>

void bubble(unsigned char* mas, int n)
{
    int i = 0;
    int j = 0;
    unsigned char temp = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

void quick(unsigned char* mas, int n)
{
    int i = 0;
    int j = n - 1;
    int mid = mas[n / 2];

    do
    {
        while (mas[i] < mid) i++;
        while (mas[j] > mid) j--;

        if (i <= j)
        {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) quick(mas, j + 1);
    if (i < n) quick(&mas[i], n - i);
}

void insertion(unsigned char* mas, int n)
{
    unsigned char temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = mas[i];
        int j = i;
        while ((j > 0) && (mas[j - 1] > temp))
        {
            mas[j] = mas[j - 1];
            j--;
        }
        mas[j] = temp;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n = 0;
    int i = 0;
    unsigned char* mas;
    int choice = 0;

    FILE* file;
    file = fopen("C:/Users/Nastya/source/repos/Project.Laboratornaya2/Project.Laboratornaya2/textFile.txt", "r+");

    fscanf_s(file, "%d", &n);

    mas = (unsigned char*)malloc(n * sizeof(unsigned int));

    for (i = 1; i < n + 1; i++)
    {
        fscanf_s(file, "%u\n", &mas[i - 1]);
    }


    printf("[1] Печать\n");
    printf("[2] Сортировка пузырёк\n");
    printf("[3] Быстрая сортировка\n");
    printf("[4] Сортировка вставкой\n");
    printf("[5] Выход\n\n");
    printf("Выбор: ");
    scanf_s("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\n");
        for (i = 0; i < n; i++)
        {
            printf("%u\n", mas[i]);
        }
        break;
    case 2:
        printf("\n");
        unsigned int start1 = clock();
        bubble(mas, n);
        for (i = 0; i < n; i++)
        {
            printf("%u\n", mas[i]);
        }
        unsigned int end1 = clock();
        unsigned int search1 = end1 - start1;
        printf("\nВремя: %u мс\n", search1);
        break;
    case 3:
        printf("\n");
        unsigned int start2 = clock();
        quick(mas, n);
        for (i = 0; i < n; i++)
        {
            printf("%u\n", mas[i]);
        }
        unsigned int end2 = clock();
        unsigned int search2 = end2 - start2;
        printf("\n\nВремя: %u мс\n", search2);
        break;
    case 4:
        printf("\n");
        unsigned int start3 = clock();
        insertion(mas, n);
        for (i = 0; i < n; i++)
        {
            printf("%u\n", mas[i]);
        }
        unsigned int end3 = clock();
        unsigned int search3 = end3 - start3;
        printf("\n\nВремя: %u мс\n", search3);
        break;
    case 5:
        free(mas);
        fclose(file);
        return 0;
    }

    free(mas);
    fclose(file);
    return 0;
}

