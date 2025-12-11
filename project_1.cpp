#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title, author, isbn;
    bool isIssued;
    int dueDays; // for fine calculation

    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isIssued = false;
        dueDays = 0;
    }
};

vector<Book> library;

// ------------------ Add Book ------------------
void addBook() {
    string t, a, i;
    cout << "\nEnter Title: ";
    cin.ignore();
    getline(cin, t);
    cout << "Enter Author: ";
    getline(cin, a);
    cout << "Enter ISBN: ";
    getline(cin, i);

    library.push_back(Book(t, a, i));
    cout << "\nBook Added Successfully!\n";
}

// ------------------ Search Book ------------------
void searchBook() {
    string key;
    cout << "\nEnter Title/Author/ISBN to Search: ";
    cin.ignore();
    getline(cin, key);

    bool found = false;
    for (auto &b : library) {
        if (b.title == key || b.author == key || b.isbn == key) {
            cout << "\nBook Found!\n";
            cout << "Title: " << b.title << "\nAuthor: " << b.author
                 << "\nISBN: " << b.isbn
                 << "\nStatus: " << (b.isIssued ? "Issued" : "Available") << "\n";
            found = true;
        }
    }
    if (!found) cout << "\nBook Not Found!\n";
}

// ------------------ Issue Book ------------------
void issueBook() {
    string key;
    cout << "\nEnter ISBN of Book to Issue: ";
    cin >> key;

    for (auto &b : library) {
        if (b.isbn == key) {
            if (!b.isIssued) {
                b.isIssued = true;
                cout << "Enter number of due days: ";
                cin >> b.dueDays;
                cout << "\nBook Issued Successfully!\n";
            } else {
                cout << "\nBook Already Issued!\n";
            }
            return;
        }
    }
    cout << "\nBook Not Found!\n";
}

// ------------------ Return Book ------------------
void returnBook() {
    string key;
    cout << "\nEnter ISBN of Book to Return: ";
    cin >> key;

    int lateDays;
    for (auto &b : library) {
        if (b.isbn == key) {
            if (b.isIssued) {
                cout << "Enter Late Days: ";
                cin >> lateDays;

                int fine = lateDays * 5; // ₹5 per day fine

                cout << "\nBook Returned Successfully!";
                cout << "\nFine Amount: ₹" << fine << "\n";

                b.isIssued = false;
                b.dueDays = 0;
            } else {
                cout << "\nThis Book was not Issued!\n";
            }
            return;
        }
    }
    cout << "\nBook Not Found!\n";
}

// ------------------ MAIN MENU ------------------
int main() {
    int choice;

    while (true) {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: cout << "\nExiting...\n"; return 0;
            default: cout << "\nInvalid Choice! Try Again.\n";
        }
    }
}
