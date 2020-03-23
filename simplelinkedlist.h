#ifndef _SIMPLELINKEDLIST_  // �迭����ũ���� ������ �Ͱ� ���� �������� �� �ڵ带 ������
#define _SIMPLELINKEDLIST_

typedef struct ListNodeType {   // ���Ḯ��Ʈ������ �� ��尡 �ڷᰪ�� 'data'�� �����Ͱ��� 'link'�� ��� �������־�� �ϹǷ� ������ ���� ���·� ����ü�� �����Ѵ�.
	int data;
	struct ListNodeType* Link;
} ListNode;

typedef struct LinkedListType {  // ���Ḯ��Ʈ������ ���� ���� ���尳���� ù��° ���(������)�� ���� ������ ���ϰ� ������ ��. �����忡�� �ڷᰪ�� ���� ��带 ����Ű�� �����Ͱ��� ������.
	int currentElementCount; //  ���Ḯ��Ʈ�� �ִ� ���� ������ ���� ���� �ʿ䰡 ���� ������ ���� �������� �ʴ´�.
	ListNode* p_headerNode;
} LinkedList;

LinkedList* createLinkedList();  // �ƹ��� �Է°��� �ʿ�� �����ʰ� �׳� ���ο� ���Ḯ��Ʈ�� ������ ��(�����常 ������), �� ���Ḯ��Ʈ�� ���� ������ ����ü �����Ͱ����� ��ȯ�Ѵ�. 
void addLLElement(LinkedList* pList, int position, ListNode element); // ���Ḯ��Ʈ�� ����ü �����Ͱ�, �����ϰ� ���� ��ġ, �����ϰ���� ���� ���޹޾� ���ϴ� ��ġ�� �ڷḦ �߰��ϰ�, �������θ� T/F�� ��ȯ�Ѵ�.
void removeElement(LinkedList* pList, int position); // ���Ḯ��Ʈ�� ����ü �����Ͱ�, �����ϰ� ���� ��ġ�� ���޹޾� ���ϴ� ��ġ�� ���Ҹ� �����ϰ�, �������θ� T/F�� ��ȯ�Ѵ�.
ListNode* getElement(LinkedList* pList, int position); // ���Ḯ��Ʈ�� ����ü �����Ͱ�, �����ϰ� ���� ��ġ�� ���޹޾� ���ϴ� ��ġ�� ����Ǿ��ִ� ���Ҹ� �����Ͽ� �ش� ����� ����ü�����Ͱ��� ��ȯ�Ѵ�.
void clearLinkedList(LinkedList* pList); // ���Ḯ��Ʈ�� ��� ���� �� �����带 �����ϰ� ��� �����Ѵ�. -> ���Ḯ��Ʈ ��ü�� �����ϴ� ���� �ƴ�
void deleteLinkedList(LinkedList* pList); // ���Ḯ��Ʈ�� ���� ��� ������ �����Ѵ�. -> ������� ��� ��������� ��
int getLinkedListLength(LinkedList* pList); // ���Ḯ��Ʈ�� ����Ǿ��ִ� ���� ���� ������ ��ȯ�Ѵ�. 
void displayLinkedList(LinkedList* pList); // ���Ḯ��Ʈ�� ����Ǿ��ִ� ���� ���� ������ ���ҵ��� �ڷᰪ�� ��� ������ִ� �Լ�

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif