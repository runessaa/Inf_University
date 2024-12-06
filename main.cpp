#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 10; //������ �������
    const int cellSize = 50; //������ ������
    const int windowSize = n * cellSize; //������ ����

    //�������� ����
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Matrix");

    vector<sf::RectangleShape> cells(n * n); //������ �������

    //�������� �����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j; //������ ������� ������
            cells[index].setSize(sf::Vector2f(cellSize - 2, cellSize - 2)); //������ �����
            cells[index].setPosition(j * cellSize + 1, i * cellSize + 1); //�������� �����
            cells[index].setFillColor(sf::Color::White); //����������� � ����� ����
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j;
            if (j == 0 || j == n - 1 || i == j) { //������ �������, ��������� �������, ������� ���������
                cells[index].setFillColor(sf::Color::Green); //����������� � ������� ����
            }
        }
    }

    //�������� ����
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { //�������� ����
                window.close();
            }
        }

        window.clear(sf::Color::Black); //������� ���� ������ ������

        //��������� ���� �����
        for (const auto& cell : cells) {
            window.draw(cell);
        }

        window.display(); //����������� ����������� ����
    }

    return 0;
}