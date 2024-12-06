#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 10; //размер матрицы
    const int cellSize = 50; //размер клетки
    const int windowSize = n * cellSize; //размер окна

    //создание окна
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Matrix");

    vector<sf::RectangleShape> cells(n * n); //€чейки матрицы

    //создание €чеек
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j; //индекс текущей €чейки
            cells[index].setSize(sf::Vector2f(cellSize - 2, cellSize - 2)); //ободок €чеек
            cells[index].setPosition(j * cellSize + 1, i * cellSize + 1); //смещение €чеек
            cells[index].setFillColor(sf::Color::White); //окрашивание в белый цвет
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j;
            if (j == 0 || j == n - 1 || i == j) { //первый столбец, последний столбец, главна€ диагональ
                cells[index].setFillColor(sf::Color::Green); //окрашивание в зеленый цвет
            }
        }
    }

    //основной цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { //закрытие окна
                window.close();
            }
        }

        window.clear(sf::Color::Black); //очистка окна черным цветом

        //отрисовка всех €чеек
        for (const auto& cell : cells) {
            window.draw(cell);
        }

        window.display(); //отображение содержимого окна
    }

    return 0;
}