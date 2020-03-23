#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simplelinkedlist.h"
 

// ���� ���Ḯ��Ʈ�� ��ġ���� 1���� �����ϵ��� ���������� ����մϴ�.


// 1. ���Ḯ��Ʈ ���� �Լ�
LinkedList* createLinkedList() {
	LinkedList* pList = NULL; // ������ �����ͺ����� NULL�� �ʱ�ȭ���־���Ѵ�.(�������, �Լ� ���� ������ ���������̹Ƿ� �Ҹ�Ǵ� �Լ��̹Ƿ� ������ �����Ҵ��Լ� malloc���� �ּҰ��� �Ҵ���� ���̱� ����) 
	pList = (LinkedList*)malloc(sizeof(LinkedList));
	if (pList != NULL) {
		(pList->currentElementCount) = 0;
		(pList->p_headerNode) = NULL;
		return pList;
	}
	else {
		printf("����, ���Ḯ��Ʈ �޸� �Ҵ� ����! \n");
		return NULL;
	}
}


// 2. ���Ḯ��Ʈ �����߰� �Լ�
void addLLElement(LinkedList* pList, int position, ListNode element) {
	ListNode* new_node = NULL;
	new_node = (ListNode*)malloc(sizeof(ListNode)); // ���ο� �����Ͱ��� ������ ���ο� ��带 �޸𸮿� �Ҵ��Ѵ�. 
	ListNode* pNode = (pList->p_headerNode); // ��������ͺ����� �����ϰ� �������� �����Ͱ����� �ʱ�ȭ�Ѵ�.
	if (new_node != NULL) {
		(new_node->data) = element.data; // ���� ���� ��忡 ���Ұ��� �������ش�. 

		if (position == 1) { // ���ο� ��尡 �����尡 �� ���
			new_node->Link = pList->p_headerNode;
			pList->p_headerNode = new_node;
		}
		else { // ���ο� ��尡 �����尡 �ƴ� ���
			for (int i = 1; i < position - 1; i++) {
				pNode = pNode->Link;
			}
			new_node->Link = pNode->Link;
			pNode->Link = new_node;
		}
		pList->currentElementCount++; // �����Ѱ��� �߰��Ͽ����Ƿ� ���� ���� ������ 1�� �÷��ش�.
	}
	else {
		printf("����, ���Ḯ��Ʈ ��� �߰� �Ҵ� ����! \n");
	}
}


// 3. ���Ḯ��Ʈ �������� �Լ�
void removeElement(LinkedList* pList, int position) {
	if (pList != NULL) {
		ListNode* pNode = (pList->p_headerNode); // ��������ͺ����� �����ϰ� �������� �����Ͱ����� �ʱ�ȭ�Ѵ�.
		ListNode* pNode2 = NULL;
		if (position == 1) { // �����ϰ����ϴ� �ڵ尡 �������� ���
			pList->p_headerNode = pNode->Link;
			free(pNode);
		}
		else { // �����ϰ����ϴ� �ڵ尡 �����尡 �ƴ� ���
			for (int i = 1; i < position - 1; i++) { // ����� ���� ���� 3��°
				pNode = pNode->Link;
			}
			pNode2 = pNode->Link;
			pNode->Link = pNode2->Link;
			free(pNode2);
		}
		pList->currentElementCount--; // ��� �� ���� ���������Ƿ� �����尳�� �Ѱ� ����
	}
	else {
		printf("����, ���Ḯ��Ʈ�� ����� ���޵����ʾҽ��ϴ�! \n");
	}
}



// 4. ���Ḯ��Ʈ �������� �Լ�
ListNode* getElement(LinkedList* pList, int position) {
	if (pList != NULL) {
		ListNode* pNode = pList->p_headerNode;
		for (int i = 1; i < position; i++) {
			pNode = pNode->Link;
		}
		return pNode;
	}
	else {
		printf("����, ���Ḯ��Ʈ�� ����� ���޵����ʾҽ��ϴ�! \n");
		return NULL;
	}
}


// 5. ���Ḯ��Ʈ �ʱ�ȭ �Լ� 
void clearLinkedList(LinkedList* pList) {
	if (pList != NULL) {
		(pList->p_headerNode)->Link = NULL;
		(pList->p_headerNode)->data = 0;
		pList->currentElementCount = 0;
	}
	else {
		printf("����, ���Ḯ��Ʈ�� ����� ���޵����ʾҽ��ϴ�! \n");
	}
}


// 6. ���Ḯ��Ʈ ���� �Լ�
void deleteLinkedList(LinkedList* pList) {
	if (pList != NULL) {
		free(pList);
	}
	else {
		printf("����, ���Ḯ��Ʈ�� ����� ���޵����ʾҽ��ϴ�! \n");
	}
}


// 7. ���Ḯ��Ʈ ���� ���� ���� ��ȯ�Լ�
int getLinkedListLength(LinkedList* pList) {
	if (pList != NULL) {
		return pList->currentElementCount;
	}
	else {
		printf("����, ���Ḯ��Ʈ�� ����� ���޵����ʾҽ��ϴ�! \n");
		return FALSE;
	}
}


// 8. ���Ḯ��Ʈ ���� ���� ����Լ�
void displayLinkedList(LinkedList* pList) {
	if (pList != NULL) {
		printf("���� ���Ḯ��Ʈ�� ����� ������ ������ �� [%d]���Դϴ�. \n\n", pList->currentElementCount);
		ListNode* pNode = pList->p_headerNode;
		for (int i = 0; i < pList->currentElementCount; i++) {
			printf("[%d ��° ����] = %d \n", i + 1, pNode->data);
			pNode = pNode->Link;
		}
	}
	else {
		printf("����, ���Ḯ��Ʈ�� ����� ���޵����ʾҽ��ϴ�! \n");
	}
}