#pragma once
#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

template <class T>
class DLLNode {
public:
	DLLNode() {
		next = prev = 0;
	}
	DLLNode(const T& el, DLLNode *n = 0, DLLNode *p = 0) {
		data = el;
		next = n;
		prev = p;
	}
	T data;
	DLLNode *next, *prev;
};

template <typename T>
class DoubleLinkedList {
public:
	DoubleLinkedList() {
		head = tail = 0;
	}

	bool is_empty() {
		return head == 0;
	}

	~DoubleLinkedList()
	{
		for (DLLNode<T> *p; !is_empty();) {
			p = head->next;
			delete head;
			head = p;
		}
	}

	void add_to_head(T el) {
		if (head != 0) {
			head = new DLLNode<T>(el, head, 0);
			head->next->prev = head;
		}
		else
			head = tail = new DLLNode<T>(el);
	}

	void add_to_tail(T el) {
		if (tail != 0) {
			tail = new DLLNode<T>(el, 0, tail);
			tail->prev->next = tail;
		}
		else
			head = tail = new DLLNode<T>(el);
	}

	T delete_from_head() {
		T el = head->data;
		if (head == tail)
		{
			delete head;
			head = tail = 0;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = 0;
		}
		return el;
	}

	T delete_from_tail() {
		T el = tail->data;
		if (head == tail) {
			delete head;
			head = tail = 0;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
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
			else if (el == head->data) {
				head = head->next;
				delete head->prev;
				head->prev = 0;
			}
			else {
				DLLNode<T> *tmp;
				for (tmp=head; tmp->data != el &&tmp != 0; tmp = tmp->next);
				if (tmp != 0) {
					if (tmp == tail) {
						tail = tmp->prev;
						tail->next = 0;
					}else
						tmp->prev->next = tmp->next;
					delete tmp;
				}
			}
		}
	}

	void print_list_pos() const{
		DLLNode<T> *tmp = head;
		while (tmp->next!=0) {
			std::cout << tmp->data << "-";
			tmp = tmp->next;
		}
		std::cout << tmp->data << std::endl;
	}

	void print_list_neg() const {
		DLLNode<T> *tmp = tail;
		while (tmp->prev != 0) {
			std::cout << tmp->data << "-";
			tmp = tmp->prev;
		}
		std::cout << tmp->data << std::endl;
	}

	bool is_in_list(T el) const {
		DLLNode<T> *tmp = head;
		while (tmp->data != el && tmp != 0)
			tmp = tmp->next;
		return tmp != 0;
	}

private:
	DLLNode<T> *head, *tail;
};


#endif // !DOUBLE_LINKED_LIST
