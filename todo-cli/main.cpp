#include <iostream>
#include <limits>
#include <string>

using namespace std;

void clr()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printHelp()
{
    cout << R"(
    Help commands: 
    add <todo>          Add a todo
    list                list todos
    done <id>           take a todo as completed
    remove <id>         remove a todo
    clr                 remove all todos
    help                display this help menu
    quit                exit program 
    )" << endl << endl;
}

int main(void)
{
    cout << "Todo CLI" << endl;
    cout << "Type 'help' for commands" << endl << endl;
    string input;
    // printHelp();
    return 0;
}
