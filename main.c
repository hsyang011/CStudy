#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// 40byte 메모리 동적할당
	int* arr = (int*)malloc(sizeof(int)*10);
	// 동적할당에 실패했다면 메인함수 종료
	if (arr == NULL) {
		return -1;
	}
	// 0 10 20 ... 90까지 순차적으로 대입한다.
	for (int i=0; i<10; i++) {
		*(arr+i) = i*10;
		printf("%3d", *(arr+i));
	}
	printf("\n");

	arr = (int*)realloc(arr, sizeof(int)*5);

	for (int i=0; i<10; i++) {
		printf("%3d", *(arr+i));
	}
	printf("\n");

	char* str = (char*)malloc(sizeof(char)*20);
	if (str == NULL) {
		return -1;
	}
	strcpy(str, "Hello world!");
	printf("안녕하세요! %s\n", str);
	for (int i=0; str[i]!='\0'; i++) {
		printf("%c", *(str+i));
	}

	// 할당된 메모리 반환
	free(arr);
	free(str);

	return 0;
}