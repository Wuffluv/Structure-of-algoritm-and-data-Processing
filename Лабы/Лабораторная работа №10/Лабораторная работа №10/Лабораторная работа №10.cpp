#include <iostream>
#include <vector>
#include <bitset>

// Функция для кодирования байта по Манчестерскому коду
std::vector<bool> manchesterEncodeByte(unsigned char byte) {
    std::vector<bool> encoded;
    for (int i = 7; i >= 0; i--) {
        // Кодирование данных
        if ((byte >> i) & 1) {
            // Если текущий бит равен 1, то добавляем переход от низкого к высокому уровню
            encoded.push_back(true);
            encoded.push_back(false);
        }
        else {
            // Если текущий бит равен 0, то добавляем переход от высокого к низкому уровню
            encoded.push_back(false);
            encoded.push_back(true);
        }
    }
    return encoded;
}

int main() {
    // Фраза, которую мы хотим закодировать
    std::string message = "hello world";

    // Кодирование фразы
    std::vector<bool> encodedMessage;
    for (char c : message) {
        std::vector<bool> encodedByte = manchesterEncodeByte(c);
        encodedMessage.insert(encodedMessage.end(), encodedByte.begin(), encodedByte.end());
    }

    // Визуальное отображение графика кодирования
    for (bool bit : encodedMessage) {
        if (bit) {
            std::cout << "+"; // Высокий уровень
        }
        else {
            std::cout << "-"; // Низкий уровень
        }
    }
    std::cout << std::endl;

    return 0;
}
