#ifndef TASK_H
#define TASK_H

#include <iostream>
using namespace std;

class Task {
    private:
        int order;
        string task_content;
        string date_start;
        string date_end;
    public: 
        Task (int order, string task_content, string date_start, string date_end);

        //Getter
        int getOrder() const;
        string getTask_content() const;
        string getDate_start() const;
        string getDate_end() const;

        //Setter
        void setOrder(int order) ;
        void setTask_content(string task_content);
        void setDate_start(string date_start);
        void setDate_end(string date_end);
};

#endif