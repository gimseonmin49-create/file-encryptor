#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char text[100];
    int key;
    FILE* in, * out;

    printf("미는 칸 수: ");
    scanf("%d", &key);

    in = fopen("memo.txt", "r");
    if (in == NULL) {
        printf("memo.txt를 열 수 없습니다.\n");
        return 1;
    }
    fscanf(in, "%99s", text);
    fclose(in);

    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = 'A' + (text[i] - 'A' + key) % 26;
    }

    out = fopen("secret.txt", "w");
    if (out == NULL) {
        printf("secret.txt를 만들 수 없습니다.\n");
        return 1;
    }
    fprintf(out, "%s\n", text);
    fclose(out);

    printf("암호화 결과: %s\n", text);
    printf("secret.txt에 저장했습니다.\n");
    return 0;
}