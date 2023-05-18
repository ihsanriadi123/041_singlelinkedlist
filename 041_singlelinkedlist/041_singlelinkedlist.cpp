#include <iostream>
using namespace std;

struct node {
	int noMhs;
	string name;
	node* next;
};

node* start = NULL;

void addnode() {
	int nim;
	string nama;
	node* nodebaru = new node();
	cout << "masukkan nim: ";
	cin >> nim;
	cout << "masukkan nama: ";
	cin >> nama;
	nodebaru -> noMhs = nim;
	nodebaru->name = nama;

	if (start == NULL || nim <= start->noMhs) {
		if (start != NULL && nim == start->noMhs)
		{
			cout << "nim sudah ada" << endl;
			return;
		}

		nodebaru->next = start;
		start = nodebaru;
		return;
	}

