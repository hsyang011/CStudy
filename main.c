#include <stdio.h>
#include <stdlib.h>

char* mySubstr(char* str, int fr, int to);
char* toUpperCase(char* str);

int main() {
	printf("\n==========2차원 메모리 동적할당==========\n");
	// 2차원 배열 정적으로 생성 후 초기화
	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	// row=3, col=4
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);

	// 2차원 배열 동적으로 생성하고 이중포인터 pArr에 저장한다.
	int** pArr = (int**)malloc(sizeof(int*) * row);
	for (int i=0; i<row; i++) {
		*(pArr+i) = (int*)malloc(sizeof(int) * col);
	}

	// arr의 모든 요소를 pArr에 복사 후 출력
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			*(*(pArr+i)+j) = *(*(arr+i)+j);
			printf("%-3d", *(*(pArr+i)+j));
		}
	}
	printf("\n");

	// 1차원 배열을 모두 반환하고, 마지막으로 2차원 배열을 반환한다.
	for (int i=0; i<row; i++) {
		free(*(pArr+i));
	}
	free(pArr);

	//=======================================================
	printf("\n==========subStr()함수 구현해보기==========\n");

	char str[] = "0123456789";
	printf("str=%s\n", str);
	// mySubstr()을 직접 구현하여 호출
	printf("mySubstr(str, 3, 6)=%s\n", mySubstr(str, 3, 6));
	printf("mySubstr(str, 5, 10)=%s\n", mySubstr(str, 5, 10));
	printf("mySubstr(str, 6, 6)=%s\n", mySubstr(str, 6, 6));
	printf("mySubstr(str, 0, 11)=%s\n", mySubstr(str, 0, 11));
	printf("mySubstr(str, 7, 5)=%s\n", mySubstr(str, 7, 5));
	printf("mySubstr(str, -1, 5)=%s\n", mySubstr(str, -1, 5));
	
	//=======================================================
	printf("\n==========toUpperCase()함수 구현해보기==========\n");

	printf("%s -> %s\n", "abcde", toUpperCase("abcde"));
	printf("%s -> %s\n", "a1b2c3d4e5", toUpperCase("a1b2c3d4e5"));
	
	return 0;
}

// 반환타입이 문자열상수인 mySubstr()함수 정의
// 매개변수로 문자열상수와 정수2개를 갖는다.
char* mySubstr(char* str, int fr, int to) {
	int len = to-fr;

	// 매개변수의 유효성 검사.
	if (fr>to || to>10 || fr<0) {
		return NULL;
	}

	// 길이가 len+1만큼의 char크기의 메모리를 동적으로 할당받는다.
	char* newStr = (char*)malloc(sizeof(char) * (len+1));
	// 문자 복사
	for (int i=fr, k=0; i<to; i++, k++) {
		*(newStr+k) = *(str+i);
	}
	// 문자열의 마지막에 NULL추가
	*(newStr+len) = '\0';

	// 문자열을 반환한다.
	return newStr;
}

char* toUpperCase(char* str) {
	// 전달받은 문자열의 길이를 저장
	char* p;
	for (p=str; *p!='\0'; p++);
	int len = p-str;
	
	// len+1크기만큼의 char형 메모리를 동적으로 할당받고 주소를 upperStr에 저장
	char* upperStr = (char*)malloc(sizeof(char) * (len+1));

	for (int i=0; i<len; i++) {
		char c = *(str+i);
		if ('a'<=c && c<='z') {
			*(upperStr+i) = c-32;
		} else {
			*(upperStr+i) = c;
		}
	}
	*(upperStr+len) = '\0';

	return upperStr;
}