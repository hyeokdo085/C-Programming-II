#define _CRT_SECURE_NO_WARNINGS // CRT 보안 경고 무시

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// 전역 변수 (간소화)
char current_user_id[20] = "";
char current_user_name[20] = "";
char current_user_title[20] = "";
int is_manager = 0; // 0: 일반 직원, 1: 관리자

// 함수 원형 선언
void clear_screen();
void show_main_menu();
void show_employee_menu();
void show_manager_menu();
void handle_employee_function(int choice);
void handle_manager_function(int choice);
int authenticate();
void print_notice_list();
void print_approval_list_manager();

// 화면 지우기 함수 정의
void clear_screen() {
    // Windows 환경
#ifdef _WIN32
    system("cls");
    // Linux/macOS 환경
#else
    system("clear");
#endif
}

// 공지사항 목록 출력 (관리자 4.2, 4.3에서 사용)
void print_notice_list() {
    printf("  [공지사항 목록]\n");
    printf("  NO. 26 | 제목: 연말 워크샵 일정 공지 (2025.11.10)\n");
    printf("  NO. 25 | 제목: 2026년 연봉 협상 지침 (2025.11.01)\n");
    printf("  NO. 24 | 제목: 사내 복지 포인트 지급 안내 (2025.10.15)\n");
    printf("  NO. 23 | 제목: 주차장 이용 변경 사항 (2025.10.01)\n");
    printf("  ------------------------------------------\n");
}

// 관리자 결재 내역 목록 출력 (관리자 5.1, 5.2에서 사용)
void print_approval_list_manager() {
    printf("  2025년 3분기 결재 내역\n");
    printf("  ID        | 제목                 | 신청자  | 상태\n");
    printf("  ----------|----------------------|---------|------\n");
    printf("  20250915-1| 사무용품 구매      | 박지훈  | 승인\n");
    printf("  20250915-2| 교육비 지원 요청   | 안도혁  | 승인\n");
    printf("  20250916-1| 신규 시스템 품의   | 이은수  | 반려\n");
    printf("  ...\n");
    printf("  ------------------------------------------\n");
}

// 메인 함수
int main() {
    clear_screen();
    printf("==========================================\n");
    printf("   * 컴공상사 인사관리 프로그램 *\n");
    printf("==========================================\n");

    // 1.1 로그인 기능 호출
    if (authenticate()) {
        show_main_menu();
    }
    else {
        printf("\n[시스템 메시지] X 프로그램을 종료합니다.\n");
    }

    return 0;
}

// 1. 로그인 처리 함수
int authenticate() {
    char id[20], pw[20];
    int choice;

    while (1) {
        printf("\n[1] 로그인 | [2] 비밀번호 조회 | [0] 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        if (choice == 0) {
            return 0; // 프로그램 종료
        }

        // 입력 후 화면 지우기 
        clear_screen();

        printf("==========================================\n");
        printf("   * 컴공상사 인사관리 프로그램 *\n");
        printf("==========================================\n");

        switch (choice) {
        case 1:
            printf("\n[로그인] ID와 비밀번호를 입력해주세요.\n");
            printf("ID를 입력하세요: ");
            scanf("%s", id);
            printf("비밀번호를 입력하세요: ");
            scanf("%s", pw);

            // --- 데이터 검증 및 이름/직급 설정 ---
            if (strcmp(id, "admin") == 0 && strcmp(pw, "1234") == 0) {
                // 관리자 정보 설정: 전민규 사장
                strcpy(current_user_id, id);
                strcpy(current_user_name, "전민규");
                strcpy(current_user_title, "사장");
                is_manager = 1;

                // 로그인 성공 시 UI 정리 및 Welcome 메시지 출력 후 잠시 멈춤
                clear_screen();
                printf("\n[성공] 관리자 %s %s님 환영합니다!\n", current_user_name, current_user_title);
                printf("\n[시스템] 메인 메뉴로 이동합니다. (아무 키나 입력하세요...)\n");
                getchar();
                getchar();
                return 1;
            }
            else if (strcmp(id, "user01") == 0 && strcmp(pw, "5678") == 0) {
                // 일반 직원 정보 설정: 안도혁 대리
                strcpy(current_user_id, id);
                strcpy(current_user_name, "안도혁");
                strcpy(current_user_title, "대리");
                is_manager = 0;

                // 로그인 성공 시 UI 정리 및 Welcome 메시지 출력 후 잠시 멈춤
                clear_screen();
                printf("\n[성공] %s %s님 환영합니다!\n", current_user_name, current_user_title);
                printf("\n[시스템] 메인 메뉴로 이동합니다. (아무 키나 입력하세요...)\n");
                getchar();
                getchar();
                return 1;
            }
            else {
                printf("\n[오류] ID 또는 비밀번호가 일치하지 않습니다. 다시 시도하세요.\n");
                break;
            }

        case 2:
            printf("\n[1.2 비밀번호 조회] ID를 입력하세요.\n");
            printf("ID를 입력하세요: ");
            scanf("%s", id);
            printf("\n[알림] 해당 ID의 등록된 연락처로 비밀번호 재설정 링크를 전송했습니다.\n");
            break;

        default:
            printf("\n[오류] 잘못된 선택입니다. 다시 선택해주세요.\n");
            break;
        }
    }
}

// 메인 메뉴
void show_main_menu() {
    while (1) {
        printf("\n==========================================\n");
        printf("   + 메인 메뉴 (사용자: %s %s) +\n", current_user_name, current_user_title);
        printf("==========================================\n");

        if (is_manager) {
            show_manager_menu();
        }
        else {
            show_employee_menu();
        }

        int menu_choice;
        printf("\n[0] 로그아웃 후 종료\n");
        printf("대분류 메뉴를 선택하세요 (숫자 입력): ");
        scanf("%d", &menu_choice);

        if (menu_choice == 0) {
            printf("\n[시스템 메시지] 로그아웃 후 프로그램을 종료합니다.\n");
            break;
        }

        // 입력 후 화면 지우기
        clear_screen();

        if (is_manager) {
            handle_manager_function(menu_choice);
        }
        else {
            handle_employee_function(menu_choice);
        }

        // 기능 처리 후 사용자에게 진행을 묻는 부분
        printf("\n[시스템] 메인 메뉴로 돌아가려면 아무 키나 입력하세요...\n");
        getchar();
        getchar();
        clear_screen(); // 다음 메뉴로 돌아가기 전 화면 지우기
    }
}

// 일반 직원용 대분류 메뉴
void show_employee_menu() {
    printf("  [1] 내 정보 / 직원 조회\n");
    printf("  [2] 근태 관리\n");
    printf("  [3] 급여 / 평가\n");
    printf("  [4] 결재 처리\n");
    printf("  [5] 공지사항\n");
}

// 관리자용 대분류 메뉴
void show_manager_menu() {
    printf("  [1] 직원 데이터 관리\n");
    printf("  [2] 근태 관리\n");
    printf("  [3] 급여 관리\n");
    printf("  [4] 공지사항 관리\n");
    printf("  [5] 결재 관리\n");
}

// 일반 직원 기능 처리 함수 (소분류 메뉴 처리)
void handle_employee_function(int choice) {
    int sub_choice;

    printf("==========================================\n");
    printf("   -> 일반 직원 기능 실행 (%s %s) <-\n", current_user_name, current_user_title);
    printf("==========================================\n");

    switch (choice) {
    case 1:
        printf("  > 1. 내 정보 / 직원 조회\n");
        printf("    [1] 개인 정보 조회 | [2] 직원 조회\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            printf("------------------------------------------\n");
            printf("  이름  : %s\n", current_user_name);
            printf("  직급  : %s\n", current_user_title);
            printf("  부서  : 개발팀\n");
            printf("  연락처: 010-1234-5678\n");
            printf("  직속상사: 전민규 사장\n");
            printf("------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            printf("  직원 조회] 검색 항목을 입력하세요: 이름\n");
            printf("  > 검색할 이름: 박지훈\n");
            printf("  ------------------------------------------\n");
            printf("  이름  : 박지훈\n");
            printf("  직급  : 과장\n");
            printf("  부서  : 기획팀\n");
            printf("  연락처: 비공개\n");
            printf("  ------------------------------------------\n");

            printf("  직원 조회] 검색 항목을 입력하세요: 직급\n");
            printf("  > 검색할 직급: 사원\n");
            printf("  ------------------------------------------\n");
            printf("  이름  : 최강수\n");
            printf("  직급  : 사원\n");
            printf("  부서  : 영업팀\n");
            printf("  연락처: 비공개\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    case 2:
        printf("  > 2. 근태 관리\n");
        printf("    [1] 출퇴근 기록 | [2] 근무 기록 조회 | [3] 휴가 신청/조회\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            // 현재 상태와 퇴근 처리가 일관되도록 수정
            printf("  ------------------------------------------\n");
            printf("  현재 상태: [출근] (09:00:00)\n");
            printf("  퇴근 처리] 현재 상태가 [퇴근]으로 변경되었습니다.\n");
            printf("  금일 근무: 09:00:00 출근 -> 18:00:15 퇴근\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            printf("  ------------------------------------------\n");
            printf("  2025/11월 근무 기록\n");
            printf("  11/01(금) : 8시간 00분 (정상)\n");
            printf("  11/04(월) : 9시간 00분 (연장 1시간)\n");
            printf("  11/05(화) : 8시간 00분 (정상)\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 3) {
            // 휴가 신청 시뮬레이션: 입력 과정 추가
            printf("  휴가 신청] 신청 항목을 입력하세요:\n");
            printf("  > 휴가 유형 (연차/병가): 연차\n");
            printf("  > 시작 일자 (YYYY/MM/DD): 2025/12/25\n");
            printf("  > 종료 일자 (YYYY/MM/DD): 2025/12/25\n");
            printf("  ------------------------------------------\n");
            printf("  결과] 12/25일 연차 (1일) 신청서가 직속상사(전민규 사장)에게 발송되었습니다.\n");
            printf("  신청 현황] : 12/25 연차 (대기 중)\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    case 3:
        printf("  > 3. 급여 / 평가\n");
        printf("    [1] 급여 명세서 조회 | [2] 인사고과 조회 | [3] 인사고과 평가\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            printf("  ------------------------------------------\n");
            printf("  2025년 10월 급여 명세서\n");
            printf("  - 기본급: 3,000,000원\n");
            printf("  - 수당  : 500,000원\n");
            printf("  - 공제액: 350,000원\n");
            printf("  - 실수령액: 3,150,000원\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            printf("  ------------------------------------------\n");
            printf("  2024년 하반기 인사고과 결과\n");
            printf("  - 평가 점수: 85점\n");
            printf("  - 최종 등급: B+ (우수)\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 3) {
            // 인사고과 평가 시뮬레이션: 입력 과정 추가 (직속 상사일 때)
            printf("  ------------------------------------------\n");
            printf("  평가 기능] 평가 대상: 이은수 대리(기획팀)\n");
            printf("  > 평가 항목 1 (직무 능력): 90점\n");
            printf("  > 평가 항목 2 (협업 태도): 85점\n");
            printf("  > 처리] 평가 점수가 최종 저장되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    case 4:
        printf("  > 4. 결재 처리\n");
        printf("    [1] 결재 신청 | [2] 결재 승인 / 반려 | [3] 결재 현황 조회\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            // 결재 신청 시뮬레이션: 입력 과정 추가
            printf("  결재 신청] 품의서 제목을 입력하세요: 업무용 노트북 교체\n");
            printf("  > 결재 경로 설정 (자동: 전민규 사장)\n");
            printf("  ------------------------------------------\n");
            printf("  결과] 품의서 '업무용 노트북 교체'가 직속 상사에게 요청되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            // 결재 승인/반려 시뮬레이션: 리스트 출력 및 처리 과정 수정 (안도혁 대리 기준)
            printf("  결재 승인/반려] 처리할 결재 목록\n");
            printf("  ------------------------------------------\n");
            printf("  NO. [1] | 제목: 12/25 연차 신청 (신청자: **이은수 대리**)\n"); // 신청자 수정
            printf("  NO. [2] | 제목: 업무용품 구매 요청 (신청자: **최강수 사원**)\n"); // 신청자 및 제목 수정
            printf("  ------------------------------------------\n");
            printf("  > 처리할 결재 번호 선택: 1\n");
            printf("  > 승인(1)/반려(2) 선택: 2\n"); // 반려 처리 시뮬레이션
            printf("  ------------------------------------------\n");
            printf("  결과] '이은수 대리'의 연차 신청 건이 '반려' 처리되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 3) {
            // 결재 현황 조회 시뮬레이션: 예시 3개 유지 및 포맷 정리
            printf("  ------------------------------------------\n");
            printf("  결재 현황\n");
            printf("  ID          | 제목                 | 상태\n");
            printf("  ------------|----------------------|-------\n");
            printf("  23-11-005   | 노트북 교체        | 최종 승인 완료\n");
            printf("  23-11-006   | 교육 수강 신청     | 대기 중 (결재 예정자: 전민규 사장)\n");
            printf("  23-11-007   | 마케팅 비용 지출   | 반려 (반려자: 전민규 사장)\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    case 5:
        printf("  > 5. 공지사항\n");
        printf("    [1] 공지사항 조회\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            // 공지사항 조회 시뮬레이션: 리스트 출력 및 선택 입력 시뮬레이션
            printf("  ------------------------------------------\n");
            print_notice_list(); // 공지사항 목록 출력
            printf("  > 열람할 공지 번호 (NO.)를 입력하세요: 25\n");
            printf("  ------------------------------------------\n");
            printf("  NO. 25 - 2026년 연봉 협상 지침\n");
            printf("  * 본 공지는 인사 부서의 최종 결정에 따라 작성되었습니다.\n");
            printf("  1. 협상 기간: 2025년 12월 1일 ~ 12월 20일\n");
            printf("  2. 대상: 재직 기간 6개월 이상 직원\n");
            printf("  3. 협상 기준: 인사고과 점수 및 직무별 시장 평균 연봉 기준\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    default:
        printf("X 오류: 잘못된 메뉴 선택입니다.\n");
        break;
    }
}

// 관리자 기능 처리 함수 (소분류 메뉴 처리)
void handle_manager_function(int choice) {
    int sub_choice;

    printf("==========================================\n");
    printf("   -> 관리자 기능 실행 (%s %s) <-\n", current_user_name, current_user_title);
    printf("==========================================\n");

    switch (choice) {
    case 1:
        printf("  > 1. 직원 데이터 관리\n");
        printf("    [1] 등록 | [2] 수정 | [3] 검색\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            // 직원 등록 시뮬레이션: 입력 과정 추가
            printf("  신규 직원 등록] 정보를 입력하세요:\n");
            printf("  > ID: new_user02\n");
            printf("  > 이름: 최강수\n");
            printf("  > 직급: 사원\n");
            printf("  > 부서: 영업팀\n");
            printf("  ------------------------------------------\n");
            printf("  등록 완료] 최강수 사원 정보가 데이터베이스에 저장되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            // 직원 수정 시뮬레이션: 입력 과정 추가
            printf("  직원 정보 수정] 수정할 직원의 ID를 입력하세요: park_jh\n");
            printf("  > 수정 항목 선택 (직급)\n");
            printf("  > 변경할 값: 차장\n");
            printf("  ------------------------------------------\n");
            printf("  수정 완료] 직원 '박지훈'의 직급이 '차장'으로 변경되었습니다. (2025/11/01일자 인사 이동)\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 3) {
            // 검색 시뮬레이션: 검색 항목 입력 시뮬레이션 추가
            printf("  직원 검색] 검색 기준을 입력하세요 (예: 부서, 직급, 이름): 직급\n");
            printf("  > 검색할 값: 대리\n");
            printf("  ------------------------------------------\n");
            printf("  검색 결과] 직급 '대리' 직원 2명의 리스트를 출력했습니다.\n");
            printf("  - 안도혁 (개발팀)\n");
            printf("  - 이은수 (기획팀)\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    case 2:
        printf("  > 2. 근태 관리\n");
        printf("    [1] 전체 현황 조회 | [2] 직원 근태 수정\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            printf("  ------------------------------------------\n");
            printf("  금일 11/12 현황] 지각자 2명, 휴가 사용 1명.\n");
            printf("  연차 현황] 전체 직원 평균 잔여 휴가 일수: 10.5일\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            // 직원 근태 수정 시뮬레이션: 입력 과정 추가
            printf("  직원 근태 수정] 수정 대상 ID를 입력하세요: lee_es\n");
            printf("  > 수정 날짜: 2025/11/11\n");
            printf("  > 퇴근 시각 변경: 17:50 -> 18:30\n");
            printf("  ------------------------------------------\n");
            printf("  수정 완료] '이은수' 대리의 근태 기록이 강제 수정되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    case 3:
        printf("  > 3. 급여 관리\n");
        printf("    [1] 급여 정보 입력/수정 | [2] 총 급여 조회\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            // 급여 정보 입력/수정 시뮬레이션: 입력 과정 추가
            printf("  급여 정보 입력/수정] 대상 직원의 ID를 입력하세요: new_user02\n");
            printf("  > 항목 선택 (기본급)\n");
            printf("  > 변경 값: 2,500,000\n");
            printf("  > 항목 선택 (식대)\n");
            printf("  > 변경 값: 100,000\n");
            printf("  ------------------------------------------\n");
            printf("  정보 설정] '최강수' 사원의 급여 정보가 최종 확정되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            printf("  ------------------------------------------\n");
            printf("  총액 계산] 이번 달 전체 직원 급여 소요 총액 8,500만원이 산출되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    case 4:
        printf("  > 4. 공지사항 관리\n");
        printf("    [1] 등록 | [2] 수정 | [3] 삭제\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            // 공지사항 등록 시뮬레이션: 입력 과정 추가
            printf("  공지사항 등록] 제목을 입력하세요: 연말 워크샵 일정 공지\n");
            printf("  > 내용을 입력하세요: 12/24~25일 워크샵 예정...\n");
            printf("  ------------------------------------------\n");
            printf("  등록 완료] 제목: '연말 워크샵 일정 공지'가 NO. 26으로 등록되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            // 공지사항 수정 시뮬레이션: 목록 출력 후 선택 과정 추가
            printf("  ------------------------------------------\n");
            print_notice_list(); // 공지사항 목록 출력
            printf("  공지사항 수정] 수정할 공지 번호 (NO.)를 입력하세요: 15\n");
            printf("  > 수정 항목 선택 (내용)\n");
            printf("  > 새로운 내용 입력: 11/20일로 개발 일정이 연기됨\n");
            printf("  ------------------------------------------\n");
            printf("  수정 완료] 공지 NO. 15 '개발 일정 연기'의 내용이 업데이트되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 3) {
            // 공지사항 삭제 시뮬레이션: 목록 출력 후 선택 과정 추가
            printf("  ------------------------------------------\n");
            print_notice_list(); // 공지사항 목록 출력
            printf("  공지사항 삭제] 삭제할 공지 번호 (NO.)를 입력하세요: 12\n");
            printf("  > [확인] '구내식당 메뉴 안내'를 삭제하시겠습니까? (Y/N): Y\n");
            printf("  ------------------------------------------\n");
            printf("  삭제 완료] 공지 NO. 12 '구내식당 메뉴 안내'가 영구 삭제되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    case 5:
        printf("  > 5. 결재 관리\n");
        printf("    [1] 총 결재 내역 열람 | [2] 결재 내역 삭제\n");
        printf("    소분류를 선택하세요: ");
        scanf("%d", &sub_choice);
        printf("\n");
        if (sub_choice == 1) {
            printf("  ------------------------------------------\n");
            print_approval_list_manager(); // 결재 내역 목록 출력
            printf("  총 50건의 결재 내역이 출력되었습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else if (sub_choice == 2) {
            // 결재 내역 삭제 시뮬레이션: 목록 출력 후 선택 과정 추가
            printf("  ------------------------------------------\n");
            print_approval_list_manager(); // 결재 내역 목록 출력
            printf("  결재 내역 삭제] 삭제할 결재 ID를 입력하세요: 20250915-1\n");
            printf("  > [확인] '사무용품 구매' 내역을 삭제하시겠습니까? (Y/N): Y\n");
            printf("  ------------------------------------------\n");
            printf("  삭제 완료] 결재ID 20250915-1번 (사무용품 구매)을 영구 삭제했습니다.\n");
            printf("  ------------------------------------------\n");
        }
        else printf("X 오류: 잘못된 소분류 선택입니다.\n");
        break;

    default:
        printf("X 오류: 잘못된 메뉴 선택입니다.\n");
        break;
    }
}