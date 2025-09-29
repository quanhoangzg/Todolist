#include <iostream>
#include <vector>
#include <limits>
using namespace std;
//Making the list struct to store data
struct task
{
    /* data */
    int order;
    string task_content;
    string date_start;
    string date_end;
};

task addTask() {
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

    task newTask;
    newTask.order = order;
    newTask.task_content = task_content;
    newTask.date_start = date_start;
    newTask.date_end = date_end; 
    return newTask;
}



// Design the interface first anyways
void display(vector<task> tasks) {
    int EXIT = 0;
    while (EXIT == 0) {
        cout << "***************************" << '\n';
        cout << "*WELCOME TO YOUR TO DO LIST*" << '\n';
        cout << "The list:" << '\n';
        for (task tsk : tasks) {
            cout << "Task " << tsk.order << " || Task: " + tsk.task_content +" || Date Start:" +
                    tsk.date_start + " || Date End: " + tsk.date_end << '\n';
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
    vector<task> tasks;
    display(tasks);

    return 0;
}