#pragma once

struct SHTnode {
	int data_;
	SHTnode* next_;

	SHTnode() : data_(0), next_(nullptr) {};
	SHTnode(int data) : data_(data), next_(nullptr) {};
};

class SHTLinkedList {
private:
	SHTnode* head_;
	SHTnode* tail_;
	unsigned size_;
	SHTnode* current_;
public:
	SHTLinkedList();

	int getdata();// data of current
	unsigned getsize();

	void addfront(int data);
	void addat(unsigned place, int data);
	void addback(int data);

	void delfront();
	void delat(unsigned place);
	void delback();

	SHTnode* next();
	void back();// wraca current_ na poczatek

	void printAll();

};