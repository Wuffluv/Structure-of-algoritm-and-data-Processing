#ifndef JOB_H
#define JOB_H

// Структура JobRequest представляет информацию о задании
struct JobRequest {
    char category; // Категория сотрудника ('M', 'S', 'W')
    int id; // ID-номер задания
    int time; // Время выполнения задания в часах

    // Оператор < для сравнения заданий
    bool operator<(const JobRequest& other) const {
        // Приоритет заданий определяется их временем выполнения
        return time > other.time;
    }
};

#endif  // JOB_H