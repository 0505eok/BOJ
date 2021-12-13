#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

// 비밀번호 입력받음
// 맞는 경우 비밀 일기를 읽어와서 보여주고 계속 작성
// 틀린 경우 경고 메세지를 표시하고 종료

#define MAX 10000

int main(void)
{
    // fgets 와 fputs 활용
    char line[MAX]; // 파일에서 불러온 내용을 저장할 변수
    char contents[MAX]; // 일기장에 입력할 내용
    char password[20]; // 비밀번호 입력
    char c; // 비밀번호 입력 할 때 키 값 확인용 (마스킹)

    printf("'비밀일기'에 오신 것을 환영합니다\n");
    printf("비밀번호를 입력하세요 : ");

    // getchar() / getch() 의 차이?
    // getchar() : 엔터 입력받으면 동작
    // getch() : 키 입력 시 바로 동작

    int i = 0;
    while (1)
    {
        c = getch();
        if (c == 13) // Enter -> 비밀번호 입력 종료
        {
            password[i] = '\n';
            break;
        }
        else // 비밀번호 입력 중
        {
            printf("*");
            password[i] = c;
        }
        i++;
    }

    printf("\n\n === 비밀번호 확인 중...===\n\n");
    if (strcmp(password, "skehzheld") == 0) // 비밀번호 일치
    {
        printf(" === 비밀번호 확인 완료 === \n\n");
        char* fileName = "c:\\secretdiary.txt";
        FILE* file = fopen(fileName, "a+b");
        // 파일이 없으면 생성, 파일이 있으면 append 를 한다 (뒤에서부터 내용 추가)
        if (file == NULL) {
            printf("파일 열기 실패");
            return 1;
        }
        while (fgets(line, MAX, file) != NULL) {
            printf("%s", line);
        }

        printf("\n\n 내용을 계속 작성하세요 ! 종료하시려면 EXIT를 입력하세요\n\n");

        while (1) {
            scanf("%[^\n]", contents); // 새 줄(\n)이 나오기 전까지 읽음 (한 문장씩 저장)
            getchar(); // Enter 입력 (\n) Flush 처리

            if (strcmp(contents, "EXIT") == 0) {
                printf("비밀일기 입력을 종료합니다\n\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file); // Enter 를 위에서 무시 처리 하였으므로 임의로 추가
        }
        fclose(file);
    }
    else // 비밀번호 틀림
    {
        printf(" === get out === \n\n");
    }

    return 0;
}