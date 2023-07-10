#include <stdio.h>
#include <stdlib.h>

char* mySubstr(char* str, int fr, int to);
char* toUpperCase(char* str);

int main() {
	printf("\n==========2���� �޸� �����Ҵ�==========\n");
	// 2���� �迭 �������� ���� �� �ʱ�ȭ
	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	// row=3, col=4
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);

	// 2���� �迭 �������� �����ϰ� ���������� pArr�� �����Ѵ�.
	int** pArr = (int**)malloc(sizeof(int*) * row);
	for (int i=0; i<row; i++) {
		*(pArr+i) = (int*)malloc(sizeof(int) * col);
	}

	// arr�� ��� ��Ҹ� pArr�� ���� �� ���
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			*(*(pArr+i)+j) = *(*(arr+i)+j);
			printf("%-3d", *(*(pArr+i)+j));
		}
	}
	printf("\n");

	// 1���� �迭�� ��� ��ȯ�ϰ�, ���������� 2���� �迭�� ��ȯ�Ѵ�.
	for (int i=0; i<row; i++) {
		free(*(pArr+i));
	}
	free(pArr);

	//=======================================================
	printf("\n==========subStr()�Լ� �����غ���==========\n");

	char str[] = "0123456789";
	printf("str=%s\n", str);
	// mySubstr()�� ���� �����Ͽ� ȣ��
	printf("mySubstr(str, 3, 6)=%s\n", mySubstr(str, 3, 6));
	printf("mySubstr(str, 5, 10)=%s\n", mySubstr(str, 5, 10));
	printf("mySubstr(str, 6, 6)=%s\n", mySubstr(str, 6, 6));
	printf("mySubstr(str, 0, 11)=%s\n", mySubstr(str, 0, 11));
	printf("mySubstr(str, 7, 5)=%s\n", mySubstr(str, 7, 5));
	printf("mySubstr(str, -1, 5)=%s\n", mySubstr(str, -1, 5));
	
	//=======================================================
	printf("\n==========toUpperCase()�Լ� �����غ���==========\n");

	printf("%s -> %s\n", "abcde", toUpperCase("abcde"));
	printf("%s -> %s\n", "a1b2c3d4e5", toUpperCase("a1b2c3d4e5"));
	
	return 0;
}

// ��ȯŸ���� ���ڿ������ mySubstr()�Լ� ����
// �Ű������� ���ڿ������ ����2���� ���´�.
char* mySubstr(char* str, int fr, int to) {
	int len = to-fr;

	// �Ű������� ��ȿ�� �˻�.
	if (fr>to || to>10 || fr<0) {
		return NULL;
	}

	// ���̰� len+1��ŭ�� charũ���� �޸𸮸� �������� �Ҵ�޴´�.
	char* newStr = (char*)malloc(sizeof(char) * (len+1));
	// ���� ����
	for (int i=fr, k=0; i<to; i++, k++) {
		*(newStr+k) = *(str+i);
	}
	// ���ڿ��� �������� NULL�߰�
	*(newStr+len) = '\0';

	// ���ڿ��� ��ȯ�Ѵ�.
	return newStr;
}

char* toUpperCase(char* str) {
	// ���޹��� ���ڿ��� ���̸� ����
	char* p;
	for (p=str; *p!='\0'; p++);
	int len = p-str;
	
	// len+1ũ�⸸ŭ�� char�� �޸𸮸� �������� �Ҵ�ް� �ּҸ� upperStr�� ����
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