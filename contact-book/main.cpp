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

void clr() {cout << "\033[2J\033[H";}

void display()
{
    
}

void add()
{
    Contact person;
    cout << "Enter the person's name" << endl;
    getline(cin >> ws, person.name);

    cout << "Enter the person's phone number" << endl;
    getline(cin, person.num);

    cout << "Enter the person's email" << endl;
    getline(cin, person.email);
    cout << "Add a note (optional)" << endl;

    cout << "Write a note (optional)" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, person.notes);

    contacts[person.name] = person;
    cout << "Contact added" << endl;
}

void remove()
{
    
}

int main(void)
{
    cout << "Contact book" << endl << endl;
    cout << "1. Display contact" << endl;
    cout << "2. Add a contact" << endl;
    cout << "3. Remove a contact" << endl;
    cout << "4. End program" << endl << endl;

    int choice;
    while(1)
    {
        cout << "Enter a choice" << endl;
        if (!(cin >> choice))
        {
            cout << "Invalid input, please enter a choice (1/2/3/4)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (choice < 1 || choice > 4)
        {
            cout << "Invalid input, please enter input 1/2/3/4" << endl;
            continue; 
        }
        
        else if (choice == 1)
        {
            clr();
            cout << "You chose to display your contact book" << endl;
            display();
        }

        else if (choice == 2)
        {
            clr();
            cout << "You chose to add a contact" << endl;
            add();
        }

        else if (choice == 3)
        {
            clr();
            cout << "You chose to remove a contact" << endl;
            remove();
        }

        else if (choice == 4)
        {
            clr();
            cout << "Exit program" << endl;
            break;
        }
    }
    return 0;
}
