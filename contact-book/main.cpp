#include <iostream>
#include <limits>
#include <string>
#include <map>

using namespace std;

struct Contact
{
    string name;
    string num;
    string email;
    string notes;
};

map<string, Contact> contacts;

void clr()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void instructions()
{
    cout << "Contact book" << endl << endl;
    cout << "1. Display contact" << endl;
    cout << "2. Add a contact" << endl;
    cout << "3. Remove a contact" << endl;
    cout << "4. End program" << endl << endl;
}

void display()
{
    if (contacts.empty())
    {
        cout << "Your contact list is empty" << endl << endl;
        return;
    }
    cout << "Your contact book" << endl << endl;
    for (const auto &entry : contacts)
    {
        const Contact &person = entry.second;
        cout << "Name: " << person.name << endl;
        cout << "Phone: " << person.num << endl;
        cout << "Email: " << person.email << endl;
        if (!person.notes.empty()){cout << "Notes: " << person.notes << endl;}
        cout << "------------------------" << endl;
    }
}

void add()
{
    Contact person;

    cout << "Enter the person's name" << endl << endl;
    getline(cin >> ws, person.name);

    cout << "Enter the person's phone number" << endl << endl;
    getline(cin, person.num);

    cout << "Enter the person's email" << endl << endl;
    getline(cin, person.email);

    cout << "Write a note (optional)" << endl << endl;
    getline(cin, person.notes);

    contacts[person.name] = person;
    cout << "Contact added" << endl << endl;
}

void remove()
{
    if (contacts.empty())
    {
        cout << "Your contact list is empty" << endl << endl;
        return;
    }
    string name;
    cout << "Enter the name of the contact to remove" << endl;
    getline(cin >> ws, name);
    auto it = contacts.find(name);

    if (it == contacts.end())
    {
        cout << "Contact not found" << endl;
        return;
    }
    contacts.erase(it);
    cout << "Contact removed" << endl;
}

int main(void)
{
    clr();
    instructions();
    int choice;
    while (true)
    {
        cout << "Enter a choice" << endl;
        if (!(cin >> choice))
        {
            cout << "Invalid input, please enter a choice (1/2/3/4)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice < 1 || choice > 4)
        {
            cout << "Invalid input, please enter input 1/2/3/4" << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                clr();
                instructions();
                cout << "You chose to display your contact book" << endl << endl;
                display();
                break;

            case 2:
                clr();
                instructions();
                cout << "You chose to add a contact" << endl << endl;
                add();
                break;

            case 3:
                clr();
                instructions();
                cout << "You chose to remove a contact" << endl << endl;
                remove();
                break;

            case 4:
                clr();
                cout << "Exit program" << endl;
                return 0;
        }
    }
}
