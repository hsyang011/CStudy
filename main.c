#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// 40byte �޸� �����Ҵ�
	int* arr = (int*)malloc(sizeof(int)*10);
	// �����Ҵ翡 �����ߴٸ� �����Լ� ����
	if (arr == NULL) {
		return -1;
	}
	// 0 10 20 ... 90���� ���������� �����Ѵ�.
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
	printf("�ȳ��ϼ���! %s\n", str);
	for (int i=0; str[i]!='\0'; i++) {
		printf("%c", *(str+i));
	}

	// �Ҵ�� �޸� ��ȯ
	free(arr);
	free(str);

	return 0;
}