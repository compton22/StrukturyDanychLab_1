#pragma once
#include "SDHTLinkedList.hpp"
#include "iostream"

SDHTLinkedList::SDHTLinkedList() : head_(nullptr), tail_(nullptr), current_(nullptr), size_(0) {}

int SDHTLinkedList::getdata() {
	return current_->data_;
}

void SDHTLinkedList::addfront(int data) {
	if (!head_) head_ = new node();

	if (!head_->data_) {
		head_->data_ = data;
		size_++;
		return;
	}

	//nadpisywanie danych
	node* newnode = new node(data);

	head_->prev_ = newnode;
	newnode->next_ = head_;

	head_ = newnode;
	size_++;
}

// dodaj warunki START = size_ i I = -1
void SDHTLinkedList::addat(unsigned place, int data) {
	node* temp = head_;
	node* temp2;
	node* new_node = new node;
	unsigned START = 0;
	unsigned I = 1;

	if (place == 0) {
		addfront(data);
		size_++;
		return;
	}
	if (place == size_) {
		addback(data);
		size_++;
		return;
	}

	if (place > size_ / 2) {
		// -1 bo poczatek tablicy to 0 a nie 1
		START = size_-1;
		I = -1;
	}

	// szukanie elementu przed elementem place
	for (unsigned i = START; temp != nullptr; i = i + I) {

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

void SDHTLinkedList::addback(int data) {
	if (!tail_) tail_ = new node();

	//nadpisywanie danych
	node* newnode = new node(data);

	//dodawanie na koniec
	tail_->next_ = newnode;
	newnode->prev_ = tail_;

	tail_ = newnode;
	size_++;
}

void SDHTLinkedList::delback() {
	if (tail_ == nullptr) return;
	//tworzenie tymczasowego node wskazującego najpierw na head_
	node* temp;
	temp = tail_;

	node* prevtemp;
	prevtemp = temp;

	//jezeli lista pusta
	if (tail_ != nullptr || temp == tail_) {
		delete tail_;
		tail_ = nullptr;
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

void SDHTLinkedList::delat(unsigned place) {
	node* temp = head_;
	node* temp2;
	unsigned START = 0;
	unsigned I = 1;

	if (place == 0) {
		delfront();
		size_--;
		return;
	}
	if (place == size_-1) {
		delback();
		size_--;
		return;
	}

	// jezeli place jest blizej od konca do zmien START na koniec listy i I na dekrementacje
	if (place > size_ / 2) {
		// -1 bo poczatek tablicy to 0 a nie 1
		START = size_ - 1;
		I = -1;
	}

	// szukanie elementu przed elementem place
	for (unsigned i = START; temp != nullptr; i = i + I) {

		// jezeli znaleziony element przed elementem place
		if (i + I == place) {

			// tymczasowy next_
			temp2 = temp->next_;

			// nadpisanie next_ jezeli jest czym
			temp->next_ = temp->next_->next_;

			// ustawianie prev następnego elementu
			temp->next_->prev_ = temp;

			delete temp2;
			temp2 = nullptr;
			size_--;
			return;
		}

		// przeskoczenie do nastepnego node
		temp = temp->next_;
	}
	std::cout << "ERROR nie znaleziono elementu od pozycji: " << place << std::endl;
	return;
}

void SDHTLinkedList::delfront() {
	node* temp;

	//jezeli lista pusta zwroc 0
	if (!head_ || !head_->next_) {
		delete head_;
		head_ = nullptr;
		size_--;
		return;
	}

	temp = head_;
	head_ = head_->next_;
	head_->prev_ = nullptr;

	delete temp;
	temp = nullptr;

	size_--;
	return;
}

node* SDHTLinkedList::next() {
	//jezeli lista pusta zwroc 0
	if (!current_) return 0;

	current_ = current_->next_;
	return current_;
}

void SDHTLinkedList::back() {
	current_ = head_;
}

void SDHTLinkedList::printAll() {
	node* temp = head_;
	unsigned i = 0;

	for (i; temp != nullptr; i++) {
		printf("Elemend %d to: %d\n", i, temp->data_);
		temp = temp->next_;
	}
}