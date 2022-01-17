// Kpop Idol Hangman Game!

#include <stdio.h>  // 핵심 입력과 출력 함수
#include <stdlib.h> // 문자열 반환, 난수 생성, 메모리 관리 등의 함수
#include <string.h> // 문자열 처리 함수
#include <time.h>   // 데이터와 시간 처리 함수

#define _CRT_SERCURE_NO_WARNINGS

/*
	* 변수 words에 저장되어 있는 25그룹의 Kpop Idol중 랜덤으로 하나의 그룹이 선택됩니다.
	* 선택된 그룹은 변수 select에 저장됩니다.
	* 플레이어는 총 6번의 life안에 select에 저장된 문자열을 맞추는 게임입니다.
	*     idol_group 문자열과 guess에 저장된 값과 같을 때까지 반복합니다.
	*     idol_group 문자열에 guess가 해당되면 해당되는 빈칸 자리를 문자로 채운다.
	*     idol_group 문자열에 guess가 해당되지 않으면 기회가 하나씩 줄며 사람 형태가 그려지게 한다.
	* 기회안에 정답 문자열을 맞추면 "YOU WIN" 출력
	* 기회안에 정답 문자열을 맞추지 못하면 "YOU LOSE. TRY AGAIN" 출력
	*/

int hangman();
void present_condition(int);

void main() {
	printf("Kpop Idol Hangman Game Start!\n"); // 
	hangman();
}

int hangman() {
	int select;
	int num = 25; // Kpop Idol의 수 선언

	// Kpop Idol 배열 생성
	char words[25][10] = {
		{"bts"}, {"blackpink"}, {"apink"}, {"april"}, {"aespa"}, 
		{"stayc"}, {"itzy"}, {"izone"}, {"twice"}, {"clc"},
		{"everglow"}, {"momoland"}, {"mamamoo"}, {"weekly"}, {"ive"},
		{"idle"}, {"bravegirls"}, {"wikimiki"}, {"crayonpop"}, {"aoa"},
		{"hellovinus"}, {"tara"}, {"rainbow"}, {"exid"}, {"missa"}
	};

	srand(time(NULL));             // srand() : seed값을 통해 rand() 변화
	select = rand() % num;         // rand() : 랜덤한 숫자 변환  

	char select_group[10] = { 0, };  // 선택된 idol 이름 문자열이 저장
	char blank[10] = { 0, };       // 
	
	char guess_group;              // 플레이어가 입력한 문자
	int len_answer;                // 정답의 글자수
	int life = 0;                  // 기회를 0으로 선언 및 초기화
	
	len_answer = strlen(words[select]);   // words 배열에서 랜덤으로 선택된 idol_group 문자열의 글자수
	strcpy(select_group, words[select]);    // words[select]를 idol_group 변수에 복사

	// 글자수에 맞게 빈칸 처리
	for (int i = 0; i < len_answer; i++)
	{
		blank[i] = '_';
		printf("%c", blank[i]);
	}

	while (1)
	{
		printf("\nPlease type an alphabet : ");            // 알파벳 문자 하나 입력
		scanf_s("%c", &guess_group, sizeof(guess_group));  // 입력받은 값을 guess_group으로 받음

		int correct = 0; 

		// 정답 문자열 중에 입력받은 문자가 있는지 확인하고, 존재하면 빈칸을 채우며 성공 표시
		for (int i = 0; i < len_answer; i++)
		{
			if (select_group[i] == guess_group)
			{
				blank[i] = select_group[i];
				correct = 1;
			}
		}
		// 정답 문자열 중 입력 값이 없으면 오류 표시하고 기회를 하나씩 감소
		if (correct == 0)
		{
			printf("wrong!\n");
			life ++;
			present_condition(life);
		}

		for (int i = 0; i < len_answer; i++)
		{
			printf("%c", blank[i]);
		}

		printf("\n");
		
		// blank와 idol_group의 문자열을 비교하여 같으면 '성공' 
		if (strcmp(blank, select_group) == 0)
		{
			printf("YOU WIN\n");
			break;
		}
		
		// 6번의 기회가 끝나면 게임 종료
		if (life == 6)
		{
			printf("YOU LOSE. TRY AGAIN\n");
			printf("The answer is \"%s\"\n", select_group);
			break;
		}
		rewind(stdin); // scanf_s() 값 초기화
	}
	return 0;
}

void present_condition(int life)
{
	if (life == 0)              // 초기 단계에서 사람을 거는 장치만 출력 
	{
		printf("   r-----|\n");
		printf("         |\n");
		printf("         |\n");
		printf("         |\n");
		printf("         |\n");
	}
	else if (life == 1)         // 1번 틀릴 시, 사람의 머리 생성
	{
		printf("   r-----|\n");
		printf("   o     |\n");
		printf("         |\n");
		printf("         |\n");
		printf("         |\n");
	}
	else if (life == 2)         // 2번 틀릴 시, 사람의 머리, 몸통 생성
	{
		printf("   r-----|\n");
		printf("   o     |\n");
		printf("   |     |\n");
		printf("         |\n");
		printf("         |\n");
	}
	else if (life == 3)         // 3번 틀릴 시, 사람의 머리, 몸통, 팔 하나 생성
	{
		printf("   r-----|\n");
		printf("   o     |\n");
		printf("  /|     |\n");
		printf("         |\n");
		printf("         |\n");
	}
	else if (life == 4)         // 4번 틀릴 시, 사람의 머리, 몸통, 두 팔 생성
	{
		printf("   r-----|\n");
		printf("   o     |\n");
		printf("  /|＼   |\n");
		printf("         |\n");
		printf("         |\n");
	}
	else if (life == 5)         // 5번 틀릴 시, 사람의 머리, 몸통, 두 팔, 다리 하나 생성
	{
		printf("   r-----|\n");
		printf("   o     |\n");
		printf("  /|＼   |\n");
		printf("  /      |\n");
		printf("         |\n");
	}
	else if (life == 6)         // 6번 틀릴 시, 사람의 완전체 생성
	{
		printf("   r-----|\n");
		printf("   o     |\n");
		printf("  /|＼   |\n");
		printf("  / ＼   |\n");
		printf("         |\n");
	}
}