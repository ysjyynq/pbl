#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Todo
{
    int id;
    string task;
    bool completed;
};

vector<Todo> todos;

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
    list                List todos
    done <id>           Take a todo as completed
    remove <id>         Remove a todo
    clr                 Remove all todos
    help                Display this help menu
    quit                Exit program 
    )" << endl;
}

void addTodo(const string &task)
{
    int id = todos.empty() ? 1 : todos.back().id + 1;
    todos.push_back({id, task, false});
    clr();
    cout << "Added todo #" << id << ": " << task << endl << endl;
}

void listTodos()
{
    if (todos.empty())
    {
        cout << "No todos found" << endl << endl;
        return;
    }

    for (const Todo &todo : todos)
    {
        cout << "[" << (todo.completed ? "x" : " ") << "] " << todo.id << ". " << todo.task << endl << endl;
    }
}

void completeTodo(int id)
{
    for (Todo &todo : todos)
    {
        if (todo.id == id)
        {
            todo.completed = true;
            cout << "Completed todo #" << id << endl << endl;
            return;
        }
    }
    cout << "Todo #" << id << " not found" << endl << endl;
}

void removeTodo(int id)
{
    auto it = find_if(todos.begin(), todos.end(),[id](const Todo &todo)
    {
        return todo.id == id;
    });

    if (it != todos.end())
    {
        todos.erase(it);
        clr();
        cout << "Removed todo #" << id << endl << endl;
    }
    else
    {
        clr();
        cout << "Todo #" << id << " not found" << endl << endl;
    }
}

int main(void)
{
    clr();
    cout << "Todo CLI" << endl;
    cout << "Type 'help' for commands" << endl << endl;
    printHelp();
    string input;

    while (1)
    {
        cout << ">";
        getline(cin, input);

        if (input == "quit")
        {
            cout << "Exit program" << endl;
            break;
        }
        else if (input == "help")
        {
            clr();
            printHelp();
        }
        else if (input == "list")
        {
            clr();
            listTodos();
        }
        else if (input == "clr")
        {
            clr();
            todos.clear();
            cout << "All todos removed" << endl << endl;
        }
        else if (input.rfind("add ", 0) == 0)
        {
            string task = input.substr(4);

            if (!task.empty())
            {
                addTodo(task);
            }
            else
            {
                clr();
                cout << "Usage: add <todo>" << endl << endl;
            }
        }
        else if (input.rfind("done ", 0) == 0)
        {
            stringstream ss(input.substr(5));
            int id;

            if (ss >> id)
            {
                clr();
                completeTodo(id);
            }
            else
            {
                clr();
                cout << "Usage: done <id>" << endl << endl;
            }
        }
        else if (input.rfind("remove ", 0) == 0)
        {
            stringstream ss(input.substr(7));
            int id;

            if (ss >> id)
            {
                clr();
                removeTodo(id);
            }
            else
            {
                clr();
                cout << "Usage: remove <id>" << endl << endl;
            }
        }
        else if (!input.empty())
        {
            clr();
            cout << "Unknown command, type 'help' for available commands" << endl << endl;
        }
    }
    return 0;
}
