#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char text[100];
    FILE* fp;

    printf("저장할 문자열: ");
    scanf("%99s", text);

    fp = fopen("memo.txt", "w");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    fprintf(fp, "%s\n", text);
    fclose(fp);

    printf("memo.txt에 저장했습니다.\n");
    return 0;
}