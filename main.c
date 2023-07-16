#include <stdio.h>
#include <stdlib.h>

// ListŸ�� ����ü ����
typedef struct list {
	int value;
	struct list* next;
	struct list* prev;
} List;

// �Լ� ��� ����
List** addList(int len);
void removeList(List** list, int len);
void addValue(List** list, int idx, int val);
void removeValue(List** list, int idx);

// main�Լ�
int main() {
	int length;
	// ����ڷκ��� ������ �Է¹޴´�.
	printf("������ ����Ʈ�� ���̸� �Է��ϼ��� >> ");
	scanf("%d", &length);
	// �Է¹��ۿ� �����ִ� ���๮�ڸ� �����ش�.
	getchar();
	
	// ����Ʈ ����
	List** myList = addList(length);

	// �� �ε����� i*10�� ���� �Ҵ�. { 0, 10, 20, ... 90 }
	for (int i=0; i<length; i++) {
		addValue(myList, i, i*10);
	}

	// �Ʒ����� �׽�Ʈ�� ���
	printf("����Ʈ�� ����: %d\n", length);

	printf("3: %d\n", myList[3]->value);
	printf("3+++: %d\n", myList[3]->next->next->next->value);
	printf("3+++-: %d\n", myList[3]->next->next->next->prev->value);
	printf("9: %d\n", myList[9]->value);
	printf("9++-+: %d\n", myList[9]->next->next->prev->next->value);
	printf("0: %d\n", myList[0]->value);
	printf("0---: %d\n", myList[0]->prev->prev->prev->value);

	removeValue(myList, 8);

	printf("===8�� �� ������===\n");
	printf("8-: %d\n", myList[8]->prev->value);
	printf("8: %d\n", myList[8]->value);
	printf("8+: %d\n", myList[8]->next->value);
	
	removeList(myList, length);

	return 0;
}

// ����Ʈ ����
List** addList(int len) {
	// ListŸ�� ���������͸� �����ϰ� ũ�Ⱑ len�� �迭�� �޸� ���� �Ҵ�
	List** list = (List**)malloc(sizeof(List*) * len);
	for (int i=0; i<len; i++) {
		list[i] = (List*)malloc(sizeof(List));
	}
	// �����Ͱ� ���� ��Ҹ� ����Ŵ
	for (int i=0; i<len; i++) {
		if (i == 0) {
			list[i]->next = list[i+1];
			// ó�� ����� prev�����Ͱ� ������ ��Ҹ� ����Ŵ
			list[0]->prev = list[len-1];
		} else if (i == len-1) {
			// ������ ����� next�����Ͱ� ó�� ��Ҹ� ����Ŵ
			list[len-1]->next = list[0];
			list[i]->prev = list[i-1];
		} else {
			// next�����Ͱ� ���� ���, prev�����Ͱ� ���� ��Ҹ� ����Ŵ
			list[i]->next = list[i+1];
			list[i]->prev = list[i-1];
		}
	}
	// ����ü �迭�� ����Ű�� ���������� list ��ȯ
	return list;
}

// ����Ʈ ����
void removeList(List** list, int len) {
	// �� �����Ͱ� ����Ű�� �޸�(����ü)�� ���ʷ� �ݳ�
	for (int i=0; i<len; i++) {
		free(list[i]);
	}
	// ���������Ͱ� ����Ű�� �޸� �ݳ�
	free(list);
}

// list�� �ش� �ε����� �� �Ҵ�
void addValue(List** list, int idx, int val) {
	list[idx]->value = val;
}

// list�� �ش� �ε����� ���� 0���� �ʱ�ȭ
void removeValue(List** list, int idx) {
	list[idx]->value = 0;
}

