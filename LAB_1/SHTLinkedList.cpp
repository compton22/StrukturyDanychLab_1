#pragma once
#include "SHTLinkedList.hpp"
#include "iostream"

SHTLinkedList::SHTLinkedList() : head_(nullptr), tail_(nullptr), current_(nullptr) {
	//head_ = new SHTnode();
	//tail_ = head_;
	//if (!head_) {
	//	printf("ERROR could not create head_");
	//	return;
	//}
	//if (!tail_) {
	//	printf("ERROR could not create tail_");
	//	return;
	//}
	//current_ = head_;
}

int SHTLinkedList::getdata() {
	return current_->data_;
}

unsigned SHTLinkedList::getsize() {
	return size_;
}

void SHTLinkedList::addfront(int data) {
	if (!head_) head_ = new SHTnode();

	if (!head_->data_) {
		head_->data_ = data;
		return;
	}

	SHTnode* newnode;

	//nadpisywanie danych
	newnode = new SHTnode(data);

	newnode->next_ = head_;

	head_ = newnode;
	size_++;
}

void SHTLinkedList::addat(unsigned place, int data) {
	SHTnode* temp = head_;
	SHTnode* temp2;
	SHTnode* new_node = new SHTnode;

	if (place == 0) {
		addfront(data);
		return;
	}

	// szukanie elementu przed elementem place
	for (unsigned i = 0; temp != nullptr; i++) {

		// jezeli temp == ostatni element to dodaj na koniec
		if (temp->next_ == nullptr) {
			addback(data);
			size_++;
			return;
		}

		// jezeli znaleziony element przed elementem place
		if (i + 1 == place) {
			new_node->data_ = data;

			// wstawianie new_node
			temp2 = temp->next_;
			temp->next_ = new_node;
			new_node->next_ = temp2;
			size_++;
			return;
		}

		// przeskoczenie do nastepnego node
		temp = temp->next_;
	}

	std::cout << "ERROR Miejsce wstawienia elementu poza rozmiarem Listy\n";
}

void SHTLinkedList::addback(int data) {
	if (!tail_) tail_ = new SHTnode();

	//nadpisywanie danych
	SHTnode* newnode = new SHTnode(data);

	//dodawanie na koniec
	tail_->next_ = newnode;

	tail_ = newnode;
	size_++;
}

void SHTLinkedList::delback() {
	if (head_ == nullptr) return;
	//tworzenie tymczasowego node wskazuj¹cego najpierw na head_
	SHTnode* temp;
	temp = head_;

	SHTnode* prevtemp;
	prevtemp = temp;

	//szukanie pustego next_
	while (temp->next_) {
		prevtemp = temp;
		temp = temp->next_;
	}

	//jezeli lista pusta
	if (!head_ || temp == head_) {
		delete head_;
		head_ = nullptr;
		size_--;
		return;
	}

	//odlaczanie wskaznikow i usuwanie
	prevtemp->next_ = nullptr;
	delete temp;

	tail_ = prevtemp;

	size_--;
	return;
}

void SHTLinkedList::delat(unsigned place) {
	SHTnode* temp = head_;
	SHTnode* temp2;
	SHTnode* new_node = new SHTnode;

	if (place == 0) {
		delfront();
		size_--;
		return;
	}
	if (place == size_ - 1) {
		delback();
		size_--;
		return;
	}

	// szukanie elementu przed elementem place
	for (unsigned i = 0; temp != nullptr; i++) {

		// jezeli znaleziony element przed elementem place
		if (i + 1 == place) {

			// tymczasowy next_
			temp2 = temp->next_;

			// nadpisanie next_ jezeli jest czym
			temp->next_ = temp->next_->next_;

			delete temp2;
			temp2 = nullptr;
			size_--;
			return;
		}

		// przeskoczenie do nastepnego node
		temp = temp->next_;
	}

	std::cout << "ERROR Miejsce wstawienia elementu poza rozmiarem Listy\n";
}

void SHTLinkedList::delfront() {
	SHTnode* temp;

	//jezeli lista pusta zwroc 0
	if (!head_ || !head_->next_) {
		delete head_;
		head_ = nullptr;
		size_--;
		return;
	}

	temp = head_;
	head_ = head_->next_;

	delete temp;
	temp = nullptr;

	size_++;
	return;
}

SHTnode* SHTLinkedList::next() {
	//jezeli lista pusta zwroc 0
	if (!current_) return 0;

	current_ = current_->next_;
	return current_;
}

void SHTLinkedList::back() {
	current_ = head_;
}

void SHTLinkedList::printAll() {
	SHTnode* temp = head_;
	unsigned i = 0;

	for (i; temp != nullptr; i++) {
		printf("Elemend %d to: %d\n", i, temp->data_);
		temp = temp->next_;
	}
}