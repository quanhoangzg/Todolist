#include <Task.h>
#include <iostream>

Task::Task (int order, string task_content, string date_start, string date_end) 
    : order(order), task_content(task_content), date_start(date_start), date_end(date_end){}

int Task::getOrder() const {
    return order;
}

string Task::getTask_content() const {
    return task_content;
}

string Task::getDate_start() const {
    return date_start;
}

string Task::getDate_end() const {
    return date_end;
}

void Task::setOrder(int order) {
    this->order = order;
}

void Task::setTask_content(string task_content) {
    this->task_content = task_content;
}

void Task::setDate_start(string date_start) {
    this->date_start = date_start;
}

void Task::setDate_end(string date_end) {
    this->date_end = date_end;
}

