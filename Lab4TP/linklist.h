#pragma once
#include <iostream>


template <typename T>
struct node {
	T value;
	node* next;
	node* prev;
};

template <typename T>
class LinkList
{
public:
	LinkList() {
		_first = nullptr;
		_last = nullptr;
		len = 0;
	}

	LinkList(const LinkList& obj) {
		_first = nullptr;
		_last = nullptr;
		for (node<T>* i = obj._first; i != nullptr; i = i->next) {
			this->push(i->value);
		}
	}

	~LinkList() {
		while (_first != nullptr) {
			auto next = _first->next;
			delete _first;
			_first = next;
		}
		_first = _last = nullptr;
	}

	LinkList<T>& operator=(const LinkList<T>& l) {
		if (this == &l) return *this;

		if (l._first == nullptr)
			throw "Stack is Empty";


		while (_first != nullptr) {
			auto next = _first->next;
			delete _first;
			_first = next;
		}
		_first = _last = nullptr;


		for (node<T>* i = l._first; i != nullptr; i = i->next) {
			this->push(i->value);
		}

		return *this;
	}

	template<typename T>
	friend void operator==(const LinkList<T>& l1, const LinkList<T>& l2);
	template<typename T>
	friend void operator!=(const LinkList<T>& l1, const LinkList<T>& l2);

	template<typename T>
	friend LinkList<T> operator+(const LinkList<T>& l1, const  T& val);

	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, const LinkList<T>& obj);

protected:
	void push(T val) {
		if (isEmpty()) {
			_last = init(val);
			_first = _last;
		}
		else {
			_last = add(_last, val);
		}
		len++;
	}

	node<T>* add(node<T>* elem, T val) {
		node<T>* temp = new node<T>[1];
		elem->next = temp;
		temp->value = val;
		temp->prev = elem;
		temp->next = nullptr;

		return temp;
	}

	node<T>* init(T val) {
		node<T>* temp = new node<T>[1];
		temp->value = val;
		temp->next = nullptr;
		temp->prev = nullptr;
		return temp;
	}

	bool isEmpty() {
		return _first == nullptr;
	}
private:
	node<T>* _first;
	node<T>* _last;
	int len;

};

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkList<T>& obj) {
	for (node<T>* i = obj._first; i != nullptr; i = i->next) {
		out << i->value << "\t";
	}
	out << "\n";
	return out;
}

template <typename T>
LinkList<T> operator+(const LinkList<T>& l1, const T& val) {
	LinkList<T> temp(l1);
	temp.push(val);
	return temp;
}

template <typename T>
void operator==(const LinkList<T>& l1, const LinkList<T>& l2) {
	if (l1.len != l2.len)
		throw "Size mismatch";
	for (node<T>* i = l1._first, *j = l2._first; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		std::cout << i->value << " == " << j->value << " - " << ((i->value == j->value) ? "True" : "False") << std::endl;
	}
}

template <>
void operator==<char*>(const LinkList<char*>& l1, const LinkList<char*>& l2) {
	if (l1.len != l2.len)
		throw "Size mismatch";
	for (node<char*>* i = l1._first, *j = l2._first; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		std::cout << i->value << " == " << j->value << " - " << ((strcmp(i->value, j->value) == 0) ? "True" : "False") << std::endl;
	}
}

template <typename T>
void operator!=(const LinkList<T>& l1, const LinkList<T>& l2) {
	if (l1.len != l2.len)
		throw "Size mismatch";
	for (node<T>* i = l1._first, *j = l2._first; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		std::cout << i->value << " != " << j->value << " - " << ((i->value != j->value) ? "True" : "False") << std::endl;
	}
}

template <>
void operator!=<char*>(const LinkList<char*>& l1, const LinkList<char*>& l2) {
	if (l1.len != l2.len)
		throw "Size mismatch";
	for (node<char*>* i = l1._first, *j = l2._first; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		std::cout << i->value << " != " << j->value << " - " << ((strcmp(i->value, j->value) != 0) ? "True" : "False") << std::endl;
	}
}