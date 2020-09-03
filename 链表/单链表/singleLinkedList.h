#pragma once
#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

template <typename T>
class SingleLinkedListNode {
public:
	SingleLinkedListNode() {
		next = 0;
	}
	SingleLinkedListNode(T el, SingleLinkedListNode *ptr = 0) {
		data = el;
		next = ptr;
	}
	T data;
	SingleLinkedListNode *next;
};

template <typename T>
class SingleLinkedList {
public:
	SingleLinkedList() {
		head = tail = 0;
	}

	~SingleLinkedList() {
		for (SingleLinkedListNode<T> *p; !is_empty();)
		{
			p = head->next;
			delete head;
			head = p;
		}
	}

	bool is_empty() {
		return head == 0;
	}

	void add_to_head(T el) {
		if (head != 0)
			head = new SingleLinkedListNode<T>(el, head);
		else
			head = tail = new SingleLinkedListNode<T>(el);
	}

	void add_to_tail(T el) {
		if (tail != 0) {
			tail->next = new SingleLinkedListNode<T>(el);
			tail = tail->next;
		}
		else
			head = tail = new SingleLinkedListNode<T>(el);
	}

	T delete_from_head() {
		T el = head->data;
		SingleLinkedListNode<T> *tmp = head;
		if (head != tail)
			head = head->next;
		else
			head = tail = 0;
		delete tmp;
		return el;
	}

	T delete_from_tail() {
		T el = tail->data;
		if (head == tail) {
			delete head;
			head = tail = 0;
		}
		else {
			SingleLinkedListNode<T> *tmp;
			for (tmp = head; tmp->next != tail; tmp = tmp->next);
			delete tail;
			tail = tmp;
			tail->next = 0;
		}
		return el;
	}

	void delete_node(T el) {
		if (head != 0) {
			if (head == tail && head->data == el) {
				delete head;
				head = tail = 0;
			}
			else if (head->data == el) {
				SingleLinkedListNode<T> *tmp = head;
				head = head->next;
				delete tmp;
			}
			else {
				SingleLinkedListNode<T> *pred, *tmp;
				for (pred = head, tmp = head->next; tmp->data != el && tmp != 0; pred = pred->next, tmp = tmp->next);
				if (tmp != 0) {
					pred->next = tmp->next;
					if (tail == tmp) {
						tail = pred;
					}
					delete tmp;
				}
			}
		}
	}

	bool is_in_list(T el) const {
		SingleLinkedListNode<T> *tmp;
		for (tmp = head; tmp != 0 && tmp->data != el; tmp = tmp->next);
		return tmp != 0;
	}

	void print_list() const {
		SingleLinkedListNode<T> *tmp = head;
		while (tmp->next != 0) {
			std::cout << tmp->data << "-";
			tmp = tmp->next;
		}
		cout << tmp->data << endl;
	}


private:
	SingleLinkedListNode<T> *head, *tail;
};
#endif // !SINGLE_LINKED_LIST
