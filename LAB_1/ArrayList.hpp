#pragma once

class ArrayList {

private:
	int* ptr_;
	unsigned size_;
	unsigned capacity_;
public:
	ArrayList();
	ArrayList(unsigned size);
	~ArrayList();
	unsigned getsize();
	unsigned getcapacity();
	void pushback(int thing);
	void pop();
	int get(unsigned n);

};