#pragma once

struct SHnode {
	int data_;
	SHnode* next_;

	SHnode() : data_(0), next_(nullptr) {};
	SHnode(int data) : data_(data), next_(nullptr) {};
};

class SHLinkedList {
private:
	SHnode* head_;
	SHnode* current_;
public:
	SHLinkedList();

	int getdata();// data of current

	void addfront(int data);
	void addat(unsigned place, int data);
	void addback(int data);

	void delfront();
	void delat(unsigned place);//licz¹c od 0
	void delback();

	SHnode* next();
	void back();//wraca current na poczatek

	void printAll();

};