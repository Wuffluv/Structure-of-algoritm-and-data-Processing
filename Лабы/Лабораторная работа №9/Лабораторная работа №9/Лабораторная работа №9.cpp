#include <iostream>
#include <fstream>
#include <queue>
#include <string>

template<typename T>
class Queue {
private:
    std::queue<T> elements; // Очередь элементов

public:
    void enqueue(const T& item) {
        elements.push(item); // Добавление элемента в очередь
    }

    T dequeue() {
        T item = elements.front();
        elements.pop();
        return item; // Извлечение элемента из очереди
    }

    bool isEmpty() const {
        return elements.empty(); // Проверка, пуста ли очередь
    }

    size_t size() const {
        return elements.size(); // Получение размера очереди
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Queue<std::string> maleQueue; // Очередь мужчин
    Queue<std::string> femaleQueue; // Очередь женщин

    std::ifstream file("dance.dat"); // Открытие файла dance.dat для чтения данных
    if (!file) {
        std::cerr << "Ошибка открытия файла dance.dat" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        char sex = line[0]; // Первый символ - пол (F или M)
        std::string name = line.substr(2); // Остальная часть строки - имя

        if (sex == 'M')
            maleQueue.enqueue(name); // Добавление имени мужчины в очередь мужчин
        else if (sex == 'F')
            femaleQueue.enqueue(name); // Добавление имени женщины в очередь женщин
    }

    file.close(); // Закрытие файла

    while (!maleQueue.isEmpty() && !femaleQueue.isEmpty()) {
        std::string male = maleQueue.dequeue(); // Извлечение имени мужчины из очереди мужчин
        std::string female = femaleQueue.dequeue(); // Извлечение имени женщины из очереди женщин
        std::cout << "Танцуют: " << male << " и " << female << std::endl; // Печать пары для танца
    }

    if (!maleQueue.isEmpty()) {
        std::cout << "Ожидают мужчины. Количество: " << maleQueue.size() << std::endl; // Проверка наличия ожидающих мужчин
        std::cout << "Следующий человек, танцующий в следующем танце: " << maleQueue.dequeue() << std::endl; // Печать имени следующего танцующего мужчины
    }
    else if (!femaleQueue.isEmpty()) {
        std::cout << "Ожидают женщины. Количество: " << femaleQueue.size() << std::endl; // Проверка наличия ожидающих женщин
        std::cout << "Следующий человек, танцующий в следующем танце:" << femaleQueue.dequeue() << std::endl; // Печать имени следующей танцующей женщины
    }
    else {
        std::cout << "Нет ожидающих людей." << std::endl; // Вывод сообщения, если нет ожидающих людей
    }
    return 0;
}
