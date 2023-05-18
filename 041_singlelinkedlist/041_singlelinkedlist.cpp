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
	nodebaru->noMhs = nim;
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

	node* previous = start;
	node* current = start;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "nim sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodebaru->next = current;
	previous->next = nodebaru;
}

bool serachnode(int nim, node* current, node* previous) {
	previous = start;
	current = start;
	while (current != NULL && nim > current->noMhs)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return false;
	}
	else if (current->noMhs == nim)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool deletenode(int nim) {
	node* current = start;
	node* previous = start;
	if (serachnode(nim, previous, current) == false)
		return false;
	previous->next = current->next;
	if (current == start)
		start = current->next;
	return true;
}
bool listempty() {
	if (start == NULL)
		return true;
	else
		return false;

}

void traverse() {
	if (listempty()) {
		cout << "list kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		node* currentnode = start;
		while (currentnode != NULL) {
			cout << "nim: " << currentnode->noMhs << ", nama: " << currentnode->name << endl;
			currentnode = currentnode->next;
		}
	}
}

