#include <iostream>
#include <vector>
#include <limits>
#include <Task.h>
#include <algorithm>
using namespace std;

Task addTask();
bool checkOrder(int order);
void deleteTask(int order);
void display();

vector<Task> tasks;

Task addTask() {
    cout << "**What do you want to add?**" <<'\n';
    int order;
    cout << "Add the piority order: ";
    cin >> order;

    //check if piority has matched
    while (checkOrder(order)) {
        cout << "This piority has been chosen, please prompt another piority number: ";
        cin >> order;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string task_content;
    string date_start;
    string date_end;

    cout << "Add the Task content: ";
    getline(cin, task_content);

    cout << "Add the start date (For example: 19:00 06/10/2025): ";
    getline(cin, date_start);

    cout << "Add the end date (For example: 19:30 06/10/2025): ";
    getline(cin, date_end);

    Task newTask(order, task_content, date_start, date_end);
    return newTask;
}

bool checkOrder(int order) {
    for (Task task : tasks) {
        if (order == task.getOrder()) {
            return true;
        }
    }
    return false;
}

void deleteTask(int order) {
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [order](const Task& task) {
        return task.getOrder() == order;
    }), tasks.end());

}




// Design the interface first anyways
void display() {
    int EXIT = 0;
    while (EXIT == 0) {
        cout << "***************************" << '\n';
        cout << "*WELCOME TO YOUR TO DO LIST*" << '\n';
        cout << "The list:" << '\n';
        for (Task tsk : tasks) {
            cout << "Task " << tsk.getOrder() << " || Task: " + tsk.getTask_content() +" || Date Start:" +
                    tsk.getDate_start() + " || Date End: " + tsk.getDate_end() << '\n';
        }
        cout << "OPTIONS:" << '\n';
        cout << "1. Add" << '\n';
        cout << "2. Delete" << '\n';
        cout << "3. Exit" << '\n';
        int option;
        cout << "Your prompt: ";
        cin >> option;

        if (option == 1) {
            tasks.push_back(addTask());  
        } else if (option == 3) {
            EXIT = 1;
        } else if (option == 2) {
            int order;
            cout << "Tell me the piority element you want to delete: ";
            cin >> order;
            deleteTask(order);
        }
        sort(tasks.begin(), tasks.end(), [](Task task1, Task task2) {
                return task1.getOrder() < task2.getOrder();
        });
    }
}
int main() {
    display();

    return 0;
}