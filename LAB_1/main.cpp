#include "ArrayList.hpp"
#include "SDHTLinkedList.hpp"
#include "SHLinkedList.hpp"
#include "SHTLinkedList.hpp"
#include "Zapis.hpp"

#include <iostream>
#include <time.h>


int main() {
	const unsigned n_copy = 2;
	//ArrayList* list = new ArrayList[n_copy];
	//Zapis plik("ArrayList.csv");
	SDHTLinkedList *Llist = new SDHTLinkedList[n_copy];

	for (unsigned k = 0; k < 1; k++) {
		printf("____________dla %d elementu dodanego do tablicy____________\n\n\n", k);

		Llist->addat(0, 2);
		Llist->addat(0, 1);
		Llist->addat(1, 10);
		Llist->addat(2, 20);
		Llist->addat(3, 30);
		
		//plik.shot(k, unsigned(duration), n_copy);
		;		//std::cout << "Czas dodawania na " << n_copy << " kopiach wynosi " << duration << "ms"
				//	<< "\nper pojedynczy " << duration / n_copy << "ms\n\n\n" << std::endl;

	}
	Llist->printAll();

	Llist->delat(3);
	Llist->delat(1);

	Llist->printAll();

}