#include <iostream>

//Функция для нахождения максимального элемента в массиве
int findMax(const int* arr, int size) {
    int max = arr[0]; //Инициализация максимального значения первым элементом массива
    for (int i = 1; i < size; i++) { // Проходим по массиву, начиная со второго элемента
        if (arr[i] > max) { //Если текущий элемент больше max, обновляем max
            max = arr[i];
        }
    }
    return max; //Возвращаем максимальное значение
}

//Функция для умножения всех элементов массива на заданное число
void multiplyArray(int* arr, int size, int multiplier) {
    for (int i = 0; i < size; i++) { //Проходим по каждому элементу массива
        arr[i] *= multiplier; //Умножаем текущий элемент на multiplier
    }
}

int main() {
    const int size = 5; //Размер массивов
    int A[size], B[size]; //Объявляем два массива: A и B

    //Ввод элементов массива A
    std::cout << "Enter 5 elements for array A:" << std::endl;
    for (int i = 0; i < size; i++) { //Запрашиваем ввод каждого элемента
        std::cin >> A[i];
    }

    //Ввод элементов массива B
    std::cout << "Enter 5 elements for array B:" << std::endl;
    for (int i = 0; i < size; i++) { //Запрашиваем ввод каждого элемента
        std::cin >> B[i];
    }

    //Находим максимальные элементы в массивах A и B
    int maxA = findMax(A, size); //Максимум массива A
    int maxB = findMax(B, size); //Максимум массива B

    //Копируем исходные массивы в отдельные для сохранения исходных значений
    int originalA[size], originalB[size];
    for (int i = 0; i < size; i++) {
        originalA[i] = A[i]; //Копируем элементы массива A
        originalB[i] = B[i]; //Копируем элементы массива B
    }

    //Умножаем элементы массива A на его максимум
    multiplyArray(A, size, maxA);
    //Умножаем элементы массива B на его максимум
    multiplyArray(B, size, maxB);

    //Выводим исходные и преобразованные массивы A
    std::cout << "\nSource array A: ";
    for (int i = 0; i < size; i++) { //Исходный массив A
        std::cout << originalA[i] << " ";
    }
    std::cout << "\nConverted array A: ";
    for (int i = 0; i < size; i++) { //Преобразованный массив A
        std::cout << A[i] << " ";
    }

    //Выводим исходные и преобразованные массивы B
    std::cout << "\nSource array B: ";
    for (int i = 0; i < size; i++) { //Исходный массив B
        std::cout << originalB[i] << " ";
    }
    std::cout << "\nConverted array B: ";
    for (int i = 0; i < size; i++) { //Преобразованный массив B
        std::cout << B[i] << " ";
    }

    return 0; //Завершение программы
}
