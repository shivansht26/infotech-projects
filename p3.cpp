#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

vector<Contact> contacts;
const string filename = "contacts.txt";

void saveContacts() {
    ofstream out(filename);
    for (const Contact& c : contacts) {
        out << c.name << " " << c.phone << " " << c.email << endl;
    }
    out.close();
}

void loadContacts() {
    ifstream in(filename);
    Contact c;
    while (in >> c.name >> c.phone >> c.email) {
        contacts.push_back(c);
    }
    in.close();
}

void addContact() {
    Contact c;
    cout << "Enter name: ";
    cin >> c.name;
    cout << "Enter phone: ";
    cin >> c.phone;
    cout << "Enter email: ";
    cin >> c.email;
    contacts.push_back(c);
    saveContacts();
    cout << "Contact added.\n";
}

void viewContacts() {
    if (contacts.empty()) {
        cout << "No contacts to display.\n";
        return;
    }
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". " << contacts[i].name << ", "
             << contacts[i].phone << ", " << contacts[i].email << endl;
    }
}

void editContact() {
    viewContacts();
    int index;
    cout << "Enter contact number to edit: ";
    cin >> index;
    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number.\n";
        return;
    }
    Contact& c = contacts[index - 1];
    cout << "Enter new name: ";
    cin >> c.name;
    cout << "Enter new phone: ";
    cin >> c.phone;
    cout << "Enter new email: ";
    cin >> c.email;
    saveContacts();
    cout << "Contact updated.\n";
}

void deleteContact() {
    viewContacts();
    int index;
    cout << "Enter contact number to delete: ";
    cin >> index;
    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number.\n";
        return;
    }
    contacts.erase(contacts.begin() + index - 1);
    saveContacts();
    cout << "Contact deleted.\n";
}

int main() {
    loadContacts(); // Load existing contacts from file on start

    int choice = 0;
    while (choice != 5) {
        cout << "\n1. Add Contact\n2. View Contacts\n3. Edit Contact\n4. Delete Contact\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: editContact(); break;
            case 4: deleteContact(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    }

    return 0;
}
