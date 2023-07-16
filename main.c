#include <stdio.h>
#include <stdlib.h>

// List타입 구조체 정의
typedef struct list {
	int value;
	struct list* next;
	struct list* prev;
} List;

// 함수 헤더 정의
List** addList(int len);
void removeList(List** list, int len);
void addValue(List** list, int idx, int val);
void removeValue(List** list, int idx);

// main함수
int main() {
	int length;
	// 사용자로부터 정수를 입력받는다.
	printf("생성할 리스트의 길이를 입력하세요 >> ");
	scanf("%d", &length);
	// 입력버퍼에 남아있는 개행문자를 지워준다.
	getchar();
	
	// 리스트 생성
	List** myList = addList(length);

	// 각 인덱스에 i*10의 값을 할당. { 0, 10, 20, ... 90 }
	for (int i=0; i<length; i++) {
		addValue(myList, i, i*10);
	}

	// 아래부턴 테스트용 출력
	printf("리스트의 길이: %d\n", length);

	printf("3: %d\n", myList[3]->value);
	printf("3+++: %d\n", myList[3]->next->next->next->value);
	printf("3+++-: %d\n", myList[3]->next->next->next->prev->value);
	printf("9: %d\n", myList[9]->value);
	printf("9++-+: %d\n", myList[9]->next->next->prev->next->value);
	printf("0: %d\n", myList[0]->value);
	printf("0---: %d\n", myList[0]->prev->prev->prev->value);

	removeValue(myList, 8);

	printf("===8번 값 삭제후===\n");
	printf("8-: %d\n", myList[8]->prev->value);
	printf("8: %d\n", myList[8]->value);
	printf("8+: %d\n", myList[8]->next->value);
	
	removeList(myList, length);

	return 0;
}

// 리스트 생성
List** addList(int len) {
	// List타입 이중포인터를 선언하고 크기가 len인 배열로 메모리 동적 할당
	List** list = (List**)malloc(sizeof(List*) * len);
	for (int i=0; i<len; i++) {
		list[i] = (List*)malloc(sizeof(List));
	}
	// 포인터가 다음 요소를 가리킴
	for (int i=0; i<len; i++) {
		if (i == 0) {
			list[i]->next = list[i+1];
			// 처음 요소의 prev포인터가 마지막 요소를 가리킴
			list[0]->prev = list[len-1];
		} else if (i == len-1) {
			// 마지막 요소의 next포인터가 처음 요소를 가리킴
			list[len-1]->next = list[0];
			list[i]->prev = list[i-1];
		} else {
			// next포인터가 다음 요소, prev포인터가 이전 요소를 가리킴
			list[i]->next = list[i+1];
			list[i]->prev = list[i-1];
		}
	}
	// 구조체 배열을 가리키는 이중포인터 list 반환
	return list;
}

// 리스트 삭제
void removeList(List** list, int len) {
	// 각 포인터가 가리키는 메모리(구조체)를 차례로 반납
	for (int i=0; i<len; i++) {
		free(list[i]);
	}
	// 이중포인터가 가리키는 메모리 반납
	free(list);
}

// list의 해당 인덱스에 값 할당
void addValue(List** list, int idx, int val) {
	list[idx]->value = val;
}

// list의 해당 인덱스의 값을 0으로 초기화
void removeValue(List** list, int idx) {
	list[idx]->value = 0;
}

