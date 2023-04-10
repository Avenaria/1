#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char* readEncryptedWordsFromFile(const char* filename, int& numWords) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return nullptr;
    }
    int bufferSize = 100; // начальный размер буфера
    char* buffer = new char[bufferSize];
    int bufferPos = 0;
    int wordCount = 0;
    char word[100];
    while (inFile >> word) {
        // расшифровываем слово (здесь используется простая замена символов)
        for (int i = 0; i < strlen(word); i++) {
            word[i] = word[i] - 1;
        }
        if (bufferPos + strlen(word) + 1 > bufferSize) {
            // увеличиваем размер буфера, если не хватает места
            bufferSize *= 2;
            char* newBuffer = new char[bufferSize];
            memcpy(newBuffer, buffer, bufferPos);
            delete[] buffer;
            buffer = newBuffer;
        }
        // добавляем расшифрованное слово в буфер
        memcpy(buffer + bufferPos, word, strlen(word) + 1);
        bufferPos += strlen(word) + 1;
        wordCount++;
    }
    inFile.close();
    // создаем массив символов и копируем данные из буфера
    char* decryptedWords = new char[bufferPos];
    memcpy(decryptedWords, buffer, bufferPos);
    delete[] buffer;
    numWords = wordCount;
    return decryptedWords;
}

int main() {
    int numWords;
}