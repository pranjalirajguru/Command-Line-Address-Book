#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Structure to store contact details
struct Contact {
    string name;
    string phone;
    string email;
};

// Function to load contacts from file
void loadContacts(vector<Contact>& contacts) {
    ifstream file("contacts.txt");
    if (!file) return; // No file yet

    Contact c;
    while (getline(file, c.name) && getline(file, c.phone) && getline(file, c.email)) {
        contacts.push_back(c);
    }
    file.close();
}

// Function to save contacts to file
void saveContacts(const vector<Contact>& contacts) {
    ofstream file("contacts.txt");
    for (const auto& c : contacts) {
        file << c.name << "\n" << c.phone << "\n" << c.email << "\n";
    }
    file.close();
}

// Function to add a contact
void addContact(vector<Contact>& contacts) {
    Contact c;
    cin.ignore();  // clear buffer
    cout << "\nEnter Name: ";
    getline(cin, c.name);
    cout << "Enter Phone Number: ";
    getline(cin, c.phone);
    cout << "Enter Email: ";
    getline(cin, c.email);

    contacts.push_back(c);
    saveContacts(contacts); // Save after adding
    cout << "\n✅ Contact added successfully!\n";
}

// Function to search a contact by name
void searchContact(const vector<Contact>& contacts) {
    string searchName;
    cin.ignore();
    cout << "\nEnter name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (const auto& c : contacts) {
        if (c.name == searchName) {
            cout << "\n🔍 Contact Found:\n";
            cout << "Name: " << c.name << "\nPhone: " << c.phone << "\nEmail: " << c.email << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n⚠️ Contact not found!\n";
    }
}

// Function to view all contacts
void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "\n📭 No contacts available.\n";
        return;
    }

    cout << "\n📒 All Contacts:\n";
    for (const auto& c : contacts) {
        cout << "---------------------------\n";
        cout << "Name : " << c.name << "\nPhone: " << c.phone << "\nEmail: " << c.email << "\n";
    }
    cout << "---------------------------\n";
}

// Function to delete a contact by name
void deleteContact(vector<Contact>& contacts) {
    string delName;
    cin.ignore();
    cout << "\nEnter name to delete: ";
    getline(cin, delName);

    bool found = false;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == delName) {
            contacts.erase(it);
            saveContacts(contacts); // Save after deleting
            cout << "\n🗑️ Contact deleted successfully!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n⚠️ Contact not found!\n";
    }
}

int main() {
    vector<Contact> contacts;
    int choice;

    // Load contacts from file at start
    loadContacts(contacts);

    do {
        cout << "\n====== Address Book ======\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. View All Contacts\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                searchContact(contacts);
                break;
            case 3:
                viewContacts(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                cout << "\n👋 Exiting Address Book. Goodbye!\n";
                break;
            default:
                cout << "\n❌ Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
