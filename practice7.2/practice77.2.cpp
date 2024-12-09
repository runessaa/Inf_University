#include <iostream>
#include <vector>
#include <set>

//Функция для нахождения элементов, которые есть только в A и меньше t
void findElementsInAOnly(const int* arrA, int sizeA, const int* arrB, int sizeB, int t, std::set<int>& result) {
    //Преобразуем массив B в множество для быстрого поиска элементов
    std::set<int> setB(arrB, arrB + sizeB); //setB хранит все элементы массива B

    //Перебираем все элементы массива A
    for (int i = 0; i < sizeA; i++) {
        //Проверяем, меньше ли текущий элемент t и отсутствует ли он в множестве setB
        if (arrA[i] < t && setB.find(arrA[i]) == setB.end()) {
            result.insert(arrA[i]); //Добавляем элемент в результирующее множество result
        }
    }
}

int main() {
    int sizeA, sizeB, t; //Объявляем размеры массивов и пороговое значение t

    //Пользователь вводит размер массива A
    std::cout << "Enter array size A: ";
    std::cin >> sizeA;

    //Пользователь вводит размер массива B
    std::cout << "Enter array size B: ";
    std::cin >> sizeB;

    //Пользователь вводит   
    std::cout << "Enter threshold value t: ";
    std::cin >> t;

    //Динамическое выделение памяти для массива A
    int* A = new int[sizeA];

    //Динамическое выделение памяти для массива B
    int* B = new int[sizeB];

    //Ввод элементов массива A
    std::cout << "Enter " << sizeA << " array elements A:" << std::endl;
    for (int i = 0; i < sizeA; i++) {
        std::cin >> A[i]; //Пользователь вводит i-й элемент массива A
    }

    //Ввод элементов массива B
    std::cout << "Enter " << sizeB << " array elements B:" << std::endl;
    for (int i = 0; i < sizeB; i++) {
        std::cin >> B[i]; //Пользователь вводит i-й элемент массива B
    }

    //Создаем пустое множество для результата
    std::set<int> result;

    //Вызов функции, чтобы найти элементы, присутствующие только в A и меньше t
    findElementsInAOnly(A, sizeA, B, sizeB, t, result);

    //Вывод результата на экран
    std::cout << "Elements present only in A and less than t: ";
    for (int elem : result) { //Перебираем элементы множества result
        std::cout << elem << " "; //Выводим текущий элемент
    }
    std::cout << std::endl; //Перевод строки после вывода элементов

    //Освобождаем выделенную память для массива A
    delete[] A;

    //Освобождаем выделенную память для массива B
    delete[] B;

    return 0; //Завершение программы
}
