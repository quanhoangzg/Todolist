#include <iostream>
#include <vector>
#include <limits>
#include <Task.h>
using namespace std;
//Making the list struct to store data
// struct task
// {
//     /* data */
//     int order;
//     string task_content;
//     string date_start;
//     string date_end;
// };

Task addTask() {
    cout << "**What do you want to add?**" <<'\n';
    int order;
    cout << "Add the piority order: ";
    cin >> order;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string task_content;
    string date_start;
    string date_end;

    cout << "Add the Task content: ";
    getline(cin, task_content);

    cout << "Add the start date: ";
    getline(cin, date_start);

    cout << "Add the end date: ";
    getline(cin, date_end);

    // task newTask;
    // newTask.order = order;
    // newTask.task_content = task_content;
    // newTask.date_start = date_start;
    // newTask.date_end = date_end; 
    Task newTask(order, task_content, date_start, date_end);
    return newTask;
}



// Design the interface first anyways
void display(vector<Task> tasks) {
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
        cout << "2. Exit" << '\n';
        int option;
        cout << "Your prompt: ";
        cin >> option;

        if (option == 1) {
            tasks.push_back(addTask());
        } else if (option == 2) {
            EXIT = 1;
        }
    }
    

}
int main() {
    vector<Task> tasks;
    display(tasks);

    return 0;
}