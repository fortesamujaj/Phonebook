#include <iostream>
using namespace std;

class Contact {
public:
	string name;
	string number;
};

class Phonebook {
private:
	int n;
	Contact** contacts;
	int index;
public:
	Phonebook(int size) {
		n = size;
		contacts = new Contact * [n];
		for (int i = 0; i < n; i++) {
			contacts[i] = nullptr;
		}
		index = 0;
	}
	~Phonebook() {
		if (contacts == nullptr) {
			return;
		}
		for (int i = 0; i < n; i++) {
			if (contacts[i] != nullptr) {
				delete contacts[i];
			}
		}
		delete contacts;
	}
	bool addContact(string name, string number);
	bool deleteContact(string name);
	bool editContact(string name, string number);
	void listContact();
};

bool Phonebook::addContact(string name, string number) {
	if (index < n) {
		Contact* contact = new Contact();
		contact->name = name;
		contact->number = number;
		contacts[index] = contact;
		index++;
		return true;
	}
	else {
		return false;
	}
}

bool Phonebook::deleteContact(string name) {
	if (index == 0)
		return false;
	for (int i = 0; i < n; i++) {
		if (contacts[i]->name == name) {
			index--;
			delete contacts[i];
			for (int j = i + 1; j < n; j++) {
				contacts[j - 1] = contacts[j];
			}
			contacts[n - 1] = nullptr;
			return true;
		}
	}
	return false;
}

bool Phonebook::editContact(string name, string number) {
	if (index == 0)
		return false;
	for (int i = 0; i < n; i++) {
		if (contacts[i]->name == name) {
			contacts[i]->number = number;
			return true;
		}
	}
	return false;
}

void Phonebook::listContact() {
	if (index == 0) {
		cout << "Phonebook eshte i zbrazet" << endl;
		return;
	}
	cout << "Emri\t\tNumri" << endl;
	for (int i = 0; i < n; i++) {
		if (contacts[i] != nullptr) {
			cout << contacts[i]->name << "\t\t" << contacts[i]->number << endl;
		}
	}
	cout << endl;
}

void printOptions() {
	cout << "Zgjidhni opsionin:" << endl;
	cout << "1 - fut" << endl;
	cout << "2 - fshij" << endl;
	cout << "3 - azhuro" << endl;
	cout << "4 - listo" << endl;
	cout << "5 - " << endl;
	cout << "#:";
}

int main(int argc, char* argv) {
	string emri = "";
	string numri = "";
	int size = 0;
	int opsioni = 0;
	cout << "Jep madhesine: ";
	cin >> size;

	Phonebook phonebook(size);

	while (true) {
		printOptions();
		cin >> opsioni;
		switch (opsioni) {
		case 1:
			cout << "Jep Emrin:";
			cin >> emri;
			cout << "Jep numrin:";
			cin >> numri;
			phonebook.addContact(emri, numri);
			break;
		case 2:
			cout << "Jep Emrin: ";
			cin >> emri;
			phonebook.deleteContact(emri);
			break;
		case 3:
			cout << "Jep Emrin:";
			cin >> emri;
			cout << "Jep numrin:";
			cin >> numri;
			if (phonebook.editContact(emri, numri) == false) {
				cout << "Kontakti nuk ekziston" << endl;
			}
			break;
		case 4:
			phonebook.listContact();
			break;
		case 5:
			cout << "Gjithe te mirat!" << endl;
			return 0;
		default:
			cout << "Zgjedh opsionin nga 1-4 !" << endl;
		}
		cout << endl;
	}
}