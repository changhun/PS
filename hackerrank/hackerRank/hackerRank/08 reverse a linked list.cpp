#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
	while (node) {
		cout << node->data;

		node = node->next;

		if (node) {
			cout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

 
#if 0
SinglyLinkedListNode* reverse(SinglyLinkedListNode* cur, SinglyLinkedListNode* prev) {
	SinglyLinkedListNode* next = cur->next;
	cur->next = prev;

	if (next == NULL) {
		return cur;
	}

	return reverse(next, cur);
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
	return reverse(llist, NULL);
}
#endif

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
	SinglyLinkedListNode *prev, *cur, *next;
	prev = NULL;
	cur = llist;
	next = cur->next;

	while (1) {
		cur->next = prev;
		if (next == NULL) return cur;
		prev = cur;
		cur = next;
		next = cur->next;
	}
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	int tests;
	cin >> tests;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
		SinglyLinkedList* llist = new SinglyLinkedList();

		int llist_count;
		cin >> llist_count;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist_count; i++) {
			int llist_item;
			cin >> llist_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			llist->insert_node(llist_item);
		}

		SinglyLinkedListNode* llist1 = reverse(llist->head);

		//print_singly_linked_list(llist1, " ", fout);
		print_singly_linked_list(llist1, " ");
		cout << "\n";

		free_singly_linked_list(llist1);
	}



	return 0;
}
