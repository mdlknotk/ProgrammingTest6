//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//КР6 - Текстовые и бинарные файлы
//КТбо1-6, Кравченко Александр Андреевич
//TaskA
//11.12.2023
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char nums[199999];

int main() {
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    
    fgets(nums, 199999, fin);

    int prevj = 0;
    int returned = 0;

    for (int i = 0; nums[i]!='\0' && !returned; i++)
    {
        if (nums[i] != ' ') {
            int fnd = 0;
            for (int j = i + 1; nums[j] != '\0' && !fnd ; j++) {
                if (nums[i] == nums[j]) {
                    nums[i] = 'F';
                    nums[j] = 'F';
                    fnd = 1;
                    if (j > prevj) prevj = j;
                }
            }
            int allac = 0;
            for (int j = 0; j < prevj && !allac ; j++)
            {
                if (nums[j] != 'F' && nums[j] !=' ') allac = 1;
            }
            if (allac == 0) {
                fprintf(fout, "%d", prevj-((prevj/2)-1));
                returned = 1;
            }
        }
    }
}