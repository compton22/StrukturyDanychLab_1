#pragma once

struct node {
	int data_;
	node* next_;
	node* prev_;

	node() : data_(0), next_(nullptr), prev_(nullptr) {};
	node(int data) : data_(data), next_(nullptr), prev_(nullptr) {};
};

class SDHTLinkedList {
private:
	node* head_;
	node* tail_;
	unsigned size_;
	node* current_;
public:
	SDHTLinkedList();

	int getdata();// data of current

	void addfront(int data);
	void addat(unsigned place, int data);
	void addback(int data);

	void delfront();
	void delat(unsigned place);
	void delback();

	node* next();
	void back();// wraca current_ na poczatek

	void printAll();

};