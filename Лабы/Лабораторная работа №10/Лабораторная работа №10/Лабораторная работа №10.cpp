#include <iostream>
#include <fstream>
#include <queue>
#include "job.h"

// Класс PQueue представляет очередь приоритетов для заданий
class PQueue {
private:
    std::priority_queue<JobRequest> jobPool; // Очередь приоритетов заданий

public:
    // Функция для вставки задания в очередь приоритетов
    void insertJob(const JobRequest& job) {
        jobPool.push(job);
    }

    // Функция для извлечения задания из очереди приоритетов
    JobRequest extractJob() {
        JobRequest job = jobPool.top();
        jobPool.pop();
        return job;
    }

    // Функция для проверки, пуста ли очередь приоритетов
    bool isEmpty() const {
        return jobPool.empty();
    }
};

// Функция для печати информации о задании
void PrintJobInfo(const JobRequest& job) {
    std::cout << "ID-номер задания: " << job.id << std::endl;
    std::cout << "Категория сотрудника: " << job.category << std::endl;
    std::cout << "Время выполнения: " << job.time << " часов" << std::endl;
    std::cout << std::endl;
}

// Функция для печати сводки по выполненным заданиям
void PrintJobSummary(const std::vector<JobRequest>& completedJobs) {
    std::cout << "Сводка по выполненным заданиям:" << std::endl;

    for (const JobRequest& job : completedJobs) {
        std::cout << "ID-номер задания: " << job.id << std::endl;
        std::cout << "Категория сотрудника: " << job.category << std::endl;
        std::cout << "Время выполнения: " << job.time << " часов" << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    std::ifstream inputFile("job.dat"); // Открываем файл с заданиями
    PQueue jobQueue; // Создаем очередь приоритетов

    if (!inputFile.is_open()) {
        std::cout << "Ошибка открытия файла job.dat" << std::endl;
        return 1;
    }

    JobRequest job;
    std::vector<JobRequest> completedJobs; // Вектор для хранения выполненных заданий

    // Читаем записи из файла и вставляем их в очередь приоритетов
    while (inputFile >> job.category >> job.id >> job.time) {
        jobQueue.insertJob(job);
    }

    inputFile.close(); // Закрываем файл

    // Извлекаем задания из очереди приоритетов и печатаем информацию о них
    while (!jobQueue.isEmpty()) {
        JobRequest currentJob = jobQueue.extractJob();
        PrintJobInfo(currentJob);
        completedJobs.push_back(currentJob); // Добавляем выполненное задание в вектор
    }

    // Печатаем сводку по выполненным заданиям
    PrintJobSummary(completedJobs);

    return 0;
}
