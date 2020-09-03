#pragma once
#ifndef CIRCLE_SINGLE_LINKED_LIST
#define CIRCLE_SINGLE_LINKED_LIST

template <typename T>
class CLLNode {
public:
	CLLNode() {
		next = 0;
	}
	CLLNode(T el, CLLNode *ptr = 0) {
		data = el;
		next = ptr;
	}
	T data;
	CLLNode *next;
};

template <typename T>
class CircleSingleLinkedList {
public:
	CircleSingleLinkedList() {
		tail = 0;
	}
	~CircleSingleLinkedList() {
		while (!is_empty()) {
			if (tail->next != tail) {
				CLLNode<T> *ptr = tail->next;
				tail->next = tail->next->next;
				delete ptr;
			}
			else
			{
				delete tail;
				tail = 0;
			}
		}
	}

	bool is_empty() {
		return tail == 0;
	}

	void add_to_head(T el) {
		if (tail != 0)
		{
			tail->next = new CLLNode<T>(el, tail->next);
		}
		else {
			tail = new CLLNode<T>(el);
			tail->next = tail;
		}
	}

	void add_to_tail(T el) {
		if (is_empty()) {
			tail = new CLLNode<T>(el);
			tail->next = tail;
		}
		else {
			tail->next = new CLLNode<T>(el, tail->next);
			tail = tail->next;
		}

	}

	T delete_from_tail() {
		T el = tail->data;
		if (tail->next == tail) {
			delete tail;
			tail = 0;
		}
		else {
			CLLNode<T> *pre = tail->next;
			while (pre->next != tail)
				pre = pre->next;
			pre->next = pre->next->next;
			delete tail;
			tail = pre;
		}
		return el;
	}

	T delete_from_head() {
		T el = tail->next->data;
		if (tail->next == tail) {
			delete tail;
			tail = 0;
		}
		else
		{
			CLLNode<T> *pre = tail->next;
			tail->next = tail->next->next;
			delete pre;
		}
		return el;
	}

	void delete_node(T el) {
		if (tail != 0) {
			if (tail->next == tail && tail->next->data == el) {
				tail->next = tail->next->next;
				delete tail->next;
			}
			else if (tail->next->data == el) {
				CLLNode<T> *tmp = tail->next;
				tail->next = tail->next->next;
				delete tmp;
			}
			else {
				CLLNode<T> *prev,*tmp;
				for (prev = tail->next, tmp = tail->next->next; tmp != 0 && tmp->data != el; prev = prev->next, tmp = tmp->next);
				if (tmp != 0) {
					prev->next = tmp->next;
					if (tmp == tail)
						tail = prev;
					delete tmp;
				}
			}
		}
	}

	void print_list() const {
		CLLNode<T> *pre = tail;
		while (pre->next != tail && pre != 0) {
			pre = pre->next;
			std::cout << pre->data << " ";	
		}
		std::cout << pre->next->data << endl;
	}

	bool is_in_list(T el) const {
		if (tail->data != el) {
			CLLNode<T> *pre = tail;
			while (pre->next != tail && pre != 0 && pre->data != el)
				pre = pre->next;
			return pre->next != tail;
		}
		else
			return 1;

	}
private:
	CLLNode<T> *tail;
};

#endif // !CIRCLE_SINGLE_LINKED_LIST
