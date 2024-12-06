#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 10; //ðàçìåð ìàòðèöû
    const int cellSize = 50; //ðàçìåð êëåòêè
    const int windowSize = n * cellSize; //ðàçìåð îêíà

    //ñîçäàíèå îêíà
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Matrix");

    vector<sf::RectangleShape> cells(n * n); //ÿ÷åéêè ìàòðèöû

    //ñîçäàíèå ÿ÷ååê
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j; //èíäåêñ òåêóùåé ÿ÷åéêè
            cells[index].setSize(sf::Vector2f(cellSize - 2, cellSize - 2)); //îáîäîê ÿ÷ååê
            cells[index].setPosition(j * cellSize + 1, i * cellSize + 1); //ñìåùåíèå ÿ÷ååê
            cells[index].setFillColor(sf::Color::White); //îêðàøèâàíèå â áåëûé öâåò
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j;
            if (j == 0 || j == n - 1 || i == j) { //ïåðâûé ñòîëáåö, ïîñëåäíèé ñòîëáåö, ãëàâíàÿ äèàãîíàëü
                cells[index].setFillColor(sf::Color::Green); //îêðàøèâàíèå â çåëåíûé öâåò
            }
        }
    }

    //îñíîâíîé öèêë
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { //çàêðûòèå îêíà
                window.close();
            }
        }

        window.clear(sf::Color::Black); //î÷èñòêà îêíà ÷åðíûì öâåòîì

        //îòðèñîâêà âñåõ ÿ÷ååê
        for (const auto& cell : cells) {
            window.draw(cell);
        }

        window.display(); //îòîáðàæåíèå ñîäåðæèìîãî îêíà
    }

    return 0;
}
