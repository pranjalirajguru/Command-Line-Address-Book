📒 Command-Line Address Book

A simple C++ command-line program to manage your personal contacts.
This project demonstrates the use of structs, vectors, file handling, and search algorithms in C++.

🚀 Features

➕ Add Contact (Name, Phone, Email)

🔍 Search Contact by name

📑 View All Contacts

🗑️ Delete Contact by name

💾 File Persistence → Contacts are saved in contacts.txt and loaded automatically on startup

🛠️ Technologies Used

C++

File I/O (fstream)

STL Vector

📂 Project Structure
AddressBook/
│-- addressbook.cpp        # Source code
│-- contacts.txt    # Stores contact data (auto-created after first run)
│-- README.md       # Documentation

▶️ How to Run

Compile the program

g++ main.cpp -o addressbook


Run the executable

./addressbook   # (Linux/Mac)
addressbook.exe # (Windows)


Use the menu options

====== Address Book ======
1. Add Contact
2. Search Contact
3. View All Contacts
4. Delete Contact
5. Exit

📖 Example Usage

Adding a Contact

Enter Name: Dustin
Enter Phone: 9876543210
Enter Email: dustin@example.com
✅ Contact added successfully!


Viewing Contacts

📒 All Contacts:
---------------------------
Name : Dustin
Phone: 9876543210
Email: dustin@example.com


Searching Contact

Enter name to search: Dustin
🔍 Contact Found:
Name: Dustin
Phone: 9876543210
Email: dustin@example.com


Deleting Contact

Enter name to delete: Dustin
🗑️ Contact deleted successfully!

