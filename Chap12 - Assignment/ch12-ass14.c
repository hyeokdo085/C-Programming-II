/*
프로그램명 : ch12-ass14.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.11.09
내용 : ass13.c 프로그램을 실행해 크기가 다른 이진 파일 2개 생성 후, 
두 파일 읽어 하나의 int 배열 생성 및 정렬하고 다시 새로운 이진 파일로 생성하는 프로그램
조건 :
1. 파일을 입력받으면 각 파일의 정수 개수를 출력
2. 두 파일의 정수를 합쳐 오름차순으로 정렬 후
새로운 파일명 입력받아 파일 생성
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MergeFiles();
// void readDatFile(); // 확인을 위한 c.dat 파일 읽기 함수

// 함수1. 메인 함수
int main() {
    MergeFiles();
    // readDatFile();
    return 0;
}

// 함수2. 두 이진 파일을 합쳐 정렬 후 새로운 이진 파일로 저장하는 함수
void MergeFiles() {
    char file1Name[25], file2Name[25], outFileName[25];
    FILE* file1 = NULL;
    FILE* file2 = NULL;
    FILE* outFile = NULL;
    int* arr1 = NULL;
    int* arr2 = NULL;
    int* mergedArr = NULL;
    int count1 = 0, count2 = 0 , countout = 0;// 각 파일의 정수 개수

    // 1. 첫 번째 파일 이름 입력받고 연 후, 정수 개수 읽기
    printf("첫 번째 파일명? ");
    scanf("%s", file1Name);

    file1 = fopen(file1Name, "rb");
    if (file1 == NULL) {
        fprintf(stderr, "첫 번째 파일을 열 수 없습니다\n");
        return;
    }

    fread(&count1, sizeof(int), 1, file1); // 정수 개수 읽기
    printf("정수 %d개를 읽었습니다.\n", count1);
    arr1 = (int*)malloc(count1 * sizeof(int)); // 정수 배열 동적 할당
    fread(arr1, sizeof(int), count1, file1); // 정수 배열 읽기
    fclose(file1);

    // 2. 두 번째 파일 이름 입력받고 연 후, 정수 개수 읽기
    printf("두 번째 파일명? ");
    scanf("%s", file2Name);

    file2 = fopen(file2Name, "rb");
    if (file2 == NULL) {
        fprintf(stderr, "두 번째 파일을 열 수 없습니다\n");
        fclose(file1);
        return;
    }

    fread(&count2, sizeof(int), 1, file2);
    printf("정수 %d개를 읽었습니다.\n", count2);
    arr2 = (int*)malloc(count2 * sizeof(int));
    fread(arr2, sizeof(int), count2, file2);
    fclose(file2);

    // 3. 두 배열 합치기
    mergedArr = (int*)malloc((count1 + count2) * sizeof(int)); // 합쳐진 배열 동적 할당
    memcpy(mergedArr, arr1, count1 * sizeof(int)); // 첫 번째 배열 복사
    memcpy(mergedArr + count1, arr2, count2 * sizeof(int)); // 두 번째 배열 이어서 복사

    // 4. 합쳐진 배열 오름차순 정렬 (버블 정렬 사용)
    for (int i = 0; i < count1 + count2 - 1; i++) { // i번째 원소와
        for (int j = i + 1; j < count1 + count2; j++) {  // i+j 번째 원소를 비교하여
            if (mergedArr[i] > mergedArr[j]) { // i번째 원소가 더 크면
                int temp = mergedArr[i]; // 두 원소 교환
                mergedArr[i] = mergedArr[j];
                mergedArr[j] = temp;
            }
        }
    }

    // 5. 새로운 파일 이름 입력받고 저장
    printf("저장할 파일명? ");
    scanf("%s", outFileName);

    outFile = fopen(outFileName, "wb");
    if (outFile == NULL) {
        fprintf(stderr, "출력 파일을 열 수 없습니다\n");
        free(arr1);
        free(arr2);
        free(mergedArr);
        return;
    }

    countout = count1 + count2;
    fwrite(&countout, sizeof(int), 1, outFile); // 정수 개수 저장
    fwrite(mergedArr, sizeof(int), countout, outFile); // 정수 배열 저장
    fclose(outFile);
    printf("정수 %d개를 저장했습니다.\n", countout);

    // 6. 동적 메모리 해제
    free(arr1);
    free(arr2);
    free(mergedArr);
}



// 확인을 위한 c.dat 파일 읽기 함수
/*
void readDatFile() {
    FILE* datFile = fopen("c.dat", "rb");
    if (datFile == NULL) {
        printf("c.dat 파일을 열 수 없습니다.\n");
        return;
    }

    int N;
    // N (정수의 개수) 읽기
    fread(&N, sizeof(int), 1, datFile);

    printf("\n[c.dat 파일에서 읽은 데이터 (총 %d개)]\n", N);

    int value;
    // N개의 정수 값 읽기 및 출력
    for (int i = 0; i < N; i++) {
        if (fread(&value, sizeof(int), 1, datFile) == 1) {
            printf("%d\n", value);
        }
        else {
            printf("데이터 읽기 오류 발생.\n");
            break;
        }
    }

    fclose(datFile);
}
*/