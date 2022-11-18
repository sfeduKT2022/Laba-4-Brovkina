﻿/******************************************************************************
Бровкина Валерия Романовна
КТбо1-2
Лабораторная работа №1 «Знакомство со средой разработки. Структура программы. Алгоритмы с ветвлением»
Вариант № 8 (6+2)
Задание:Написать программу, которая во вводимом с клавиатуры тексте
удалит все пробелы, знаки табуляции и выведет количество удаленных символов
на экран.
*******************************************************************************/
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    char s[1000];
    FILE* fp = fopen("text.txt", "r");
    FILE* nfp = fopen("new_text.txt", "w");
    int count = 0;
    if (fp == NULL)
    {
        puts("Ошибка чтения файла");
    }
    else
    {
        while (!feof(fp))
        {
            fgets(s, 1000, fp);
            int i = 0;
            while (s[i] != '\0')
            {
                if (!(s[i] == ' ' || s[i] == '\t'))
                {
                    fprintf(nfp, "%c", s[i]);
                }
                else
                {
                    count++;
                }
                i++;
            }
        }
        printf("%d", count);
    }
    fclose(nfp);
    fclose(fp);
    return 0;
}