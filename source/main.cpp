#include <iostream>
#include <vector>
#include <limits>
#include <Task.h>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

Task addTask();
bool checkOrder(int order);
void deleteTask(int order);
void display();
bool parseDateTime(string &input, tm &outTime);
bool isFuture(tm &timeStruct);
bool isFurther(tm &startTime, tm &endTime);

vector<Task> tasks;


Task addTask() {
    cout << "**What do you want to add?**" <<'\n';
    int order;
    cout << "Add the piority order: ";
    while (!(cin >> order)) {
        cout << "Invalid Input, try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    //check if piority has matched
    while (checkOrder(order)) {
        cout << "This piority has been chosen, please prompt another piority number: ";
        while (!(cin >> order)) {
            cout << "Invalid Input, try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string task_content;
    tm startTime{}, endTime{};
    string date_start;
    string date_end;

    do {
        cout << "Add the Task content: ";
        getline(cin, task_content);
    } while (task_content.empty());
    
    do {
        cout << "Add the start date (Format: HH:MM DD/MM/YYYY): ";
        getline(cin, date_start);
        
        if (!parseDateTime(date_start, startTime)) {
            cout << "Invalid format! Try again (Example: 19:30 16/02/2007)\n";
            continue;
        }

        if (!isFuture(startTime)) {
            cout << "The start time cannot be in the past.\n";
            continue;
        }
        break;
    } while (true);

    do {
        cout << "Add the end date (Format: HH:MM DD/MM/YYYY): ";
        getline(cin, date_end);

        if (!parseDateTime(date_end, endTime)) {
            cout << "Invalid format! Try again (Example: 19:30 16/02/2007)\n";
            continue;
        }

        if (!isFuture(endTime)) {
            cout << "The start time cannot be in the past.\n";
            continue;
        }

        if (!isFurther(startTime, endTime)) {
            cout << "The end time must not before the start time, please try again.\n";
            continue;
        }
        break;
    } while (true);

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

bool parseDateTime(string &input, tm &outTime) {
    std::istringstream ss(input);
    ss >> std::get_time(&outTime, "%H:%M %d/%m/%Y");
    if (ss.fail()) return false;

    // Make a copy for validation
    tm temp = outTime;

    // Normalize using mktime
    time_t t = mktime(&temp);
    if (t == -1) return false; // invalid time_t result

    // mktime() may auto-fix invalid values (e.g., 32 Jan → 1 Feb)
    // So we recheck that nothing changed
    if (temp.tm_year != outTime.tm_year ||
        temp.tm_mon  != outTime.tm_mon  ||
        temp.tm_mday != outTime.tm_mday ||
        temp.tm_hour != outTime.tm_hour ||
        temp.tm_min  != outTime.tm_min)
        return false;

    // Range check (optional double safety)
    if (outTime.tm_hour < 0 || outTime.tm_hour > 23 ||
        outTime.tm_min < 0  || outTime.tm_min > 59 ||
        outTime.tm_mday < 1 || outTime.tm_mday > 31 ||
        outTime.tm_mon < 0  || outTime.tm_mon > 11)
        return false;

    return true;
}


bool isFuture(tm &timeStruct) {
    time_t check_time = mktime(&timeStruct);
    time_t curr = time(nullptr);
    return difftime(check_time, curr) > 0;
}

bool isFurther(tm &startTime, tm &endTime) {
    time_t start = mktime(&startTime);
    time_t end = mktime(&endTime);
    return difftime(end, start) > 0;
}

// Design the interface first anyways
void display() {
    int EXIT = 0;
    while (EXIT == 0) {
        cout << "****************************" << '\n';
        cout << "*WELCOME TO YOUR TO DO LIST*" << '\n';
        cout << "****************************" << '\n';
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