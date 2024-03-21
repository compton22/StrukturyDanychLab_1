#pragma once
#include <iostream>
#include "ArrayList.hpp"

ArrayList::ArrayList() : size_(0), capacity_(0), ptr_(nullptr) {};

ArrayList::ArrayList(unsigned capacity) : size_(0), capacity_(capacity), ptr_(nullptr){
	ptr_ = new int[capacity_];
}

ArrayList::~ArrayList() {
	delete[] ptr_;
	ptr_ = nullptr;
};

unsigned ArrayList::getsize() {
	return size_;
};

unsigned ArrayList::getcapacity() {
	return capacity_;
}

void ArrayList::pushback(int thing) {
	if (capacity_ == 0) {
		int* newptr = new int[1];

		if (!newptr) {
			std::cout << "ERROR - nie udalo sie powiekszyc tablicy" << std::endl;
			return;
		}

		ptr_ = newptr;
		capacity_ = 1;
	}
	else if (size_ == capacity_) {
		int *newptr = new int[2 * capacity_];

		if(!newptr){
			std::cout << "ERROR - nie udalo sie powiekszyc tablicy" << std::endl;
			return;
		}


		for (int i = 0; i < size_; i++) {
			newptr[i] = ptr_[i];
		}

		delete[] ptr_;
		ptr_ = newptr;
		capacity_ *= 2;
	}

	ptr_[size_] = thing;//nie uzywamy size_+1 bo tablica jest od 0
	size_++;
}

void ArrayList::pop() {
	size_--;

	//jezeli ilosc danym x4 razy mniejsza od pojemnosci to zmniejsz o polowe
	if (size_ < ceil(capacity_/4)) {
		int* newptr = new int[ceil(capacity_/2)];

		if (!newptr) {
			std::cout << "ERROR - nie udalo sie pomniejszyc tablicy" << std::endl;
			return;
		}

		for (int i = 0; i < size_; i++) {
			newptr[i] = ptr_[i];
		}

		delete[] ptr_;
		ptr_ = newptr;
		capacity_ = ceil(capacity_/4);
	}
}

int ArrayList::get(unsigned n) {
	return ptr_[n];
}