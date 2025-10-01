/*
프로그램명 : ch10-ass18.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.01
난이도 : ★★★
내용 : 음원사이트의 플레이리스트 기능
조건 :
1. 이미 등록된 SONG 구조체 배열을 사용하므로, 플레이리스트 목록은 포인터 배열로 구현
	등록된 SONG 구조체 배열은 프로그램 실행 처음에만 출력
2. 전체 곡 목록을 보여주고 사용자로부터 플레이리스트에 추가할 노래 번호로 선택하게 함
	이때, 사용자가 선택한 곡 번호로 SONG 배열 원소의 주소를 playlist[i]에 저장
3. SONG 구조체 배열의 인덱스는 0부터 시작하나, 노래 번호는 1부터 시작함을 주의
4. 노래를 추가할 때마다 플레이리스트 곡 목록과 전체 재생 시간을 출력
5. 플레이리스트 최대 5곡
6. SONG 구조체는 제목, 아티스트, 장르, 재생시간(초)로 구성
7. SONG *playlist[5] = {NULL};
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct song {
	char title[30];      // 노래 제목
	char artist[30];     // 아티스트
	char genre[20];      // 장르
	int duration;        // 재생 시간(초)
} SONG;

typedef struct playlist {
	SONG* songs[5];      // 플레이리스트 곡 목록
	int count;           // 현재 플레이리스트 곡 수
} PLAYLIST;

void ass18(void);
void print_playlist(PLAYLIST* pl);

// 함수1 : 메인함수
int main() {
	ass18(); //함수 호출
	return 0;
}

// 함수2 : SONG 구조체 배열 등록 및 print_playlist 함수 호출하는 함수
void ass18(void) {
	SONG songs[] = { // SONG 구조체 배열 초기화
		{"thank u, next", "Ariana Grande", "pop", 208},
		{"Attention", "Charlie Puth", "pop", 211},
		{"별 보러 가자", "박보검	", "ballad", 316},
		{"How Long", "Charlie Puth", "pop", 198},
		{"I'm Fine", "방탄소년단", "hip-hop", 209},
		{"봄날	", "방탄소년단", "hip-hop", 274},
		{"Awake	", "방탄소년단", "ballad", 226},
		{"아낙네	", "MINO	", "hip-hop", 241}
	};
	PLAYLIST playlist = { {NULL}, 0 }; // 플레이리스트 초기화

	printf("	제목			아티스트		장르		재생시간\n");
	for (int i = 0; i < sizeof(songs) / sizeof(songs[0]); i++) {
		printf("%d:	%s		%s		%s		%d초)\n", i + 1, songs[i].title, songs[i].artist, songs[i].genre, songs[i].duration);
	}
	int choice;
	while (playlist.count < 5) {
		printf("\n플레이리스트에 추가할 곡 번호? ");
		scanf("%d", &choice);
		if (choice < 0 || choice > sizeof(songs) / sizeof(songs[0])) { //곡 번호가 범위를 벗어날 경우
			printf("잘못된 곡 번호입니다.\n");
			continue;
		}
		if (choice == 0) {
			return; // 0 입력 시 종료
		}
		playlist.songs[playlist.count] = &songs[choice - 1]; // 선택한 곡 주소 저장
		playlist.count++;
		print_playlist(&playlist); // 플레이리스트 출력
	}
	printf("플레이리스트가 가득 찼습니다.\n");
}

// 함수3 : 플레이리스트 곡 목록과 전체 재생 시간 출력하는 함수
void print_playlist(PLAYLIST* pl) {
	printf("<< 플레이리스트 >>\n");
	int total_duration = 0; // 전체 재생 시간 초기화
	for (int i = 0; i < pl->count; i++) {
		printf("	%s		%s		%s		%d초\n", pl->songs[i]->title, pl->songs[i]->artist, pl->songs[i]->genre, pl->songs[i]->duration); // 곡 정보 출력
		total_duration += pl->songs[i]->duration; // 전체 재생 시간 계산
	}
	printf("총 재생 시간: %d초\n", total_duration);
}