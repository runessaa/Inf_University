#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <cmath>

// ������� ��� ��������� �������
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // ���������� �������� �������

        // �������������� ��������� � ��������
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // ���������� ����� � ������ ������
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

// ����������� ����
int determineZone(float x, float y) {
    float y1 = 4 * x + 8; // ������ ������
    float y2 = 6 * x; // ������ ������

    if (y > y1 && y > y2) {
        return 2;
    }
    else if (y > y1 && y < y2) {
        return 4;
    }
    else if (y < y1 && y < y2) {
        return 1;
    }
    else if (y < y1 && y > y2) {
        return 3;
    }

    return 0;
}

int main() {
    // �������� ����
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphing application");

    // ���������� ��� �������� ���������������� �����
    sf::CircleShape userPoint(5); // ������ 5 ��������
    userPoint.setFillColor(sf::Color::Yellow);
    bool userPointExists = false; // ���������� ��� �������� ������������� ���������������� �����

    // �������� ������
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) return -1;

    // ����� ��� ����������� ��������� �����
    sf::Text coordinatesText("", font, 20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    // ��� X � Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(0, 300); // ������ ��� X
    xAxis[0].color = sf::Color::White; // ���� ���
    xAxis[1].position = sf::Vector2f(800, 300); // ����� ��� X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 0); // ������ ��� Y
    yAxis[0].color = sf::Color::White; // ���� ���
    yAxis[1].position = sf::Vector2f(400, 600); // ����� ��� Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // �������� ����� �����
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // ��������� ������� �����
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // �������������� �������� ��������� � "��������������"
                    float mathX = (mousePos.x - 400) / 20.0f; // ������� 20 �� X
                    float mathY = -(mousePos.y - 300) / 2.5f; // ������� 2.5 �� Y

                    // ��������� ����� ���������������� �����
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; // ��������, ��� ����� ����������

                    // ����������� ����
                    int zone = determineZone(mathX, mathY);

                    // ���������� ������ � ������������ �����
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) +
                        ")\nZone: " + std::to_string(zone));
                }
            }
        }

        // ������� ������
        window.clear();

        // ��������� ����
        window.draw(xAxis);
        window.draw(yAxis);

        // ��������� ������� y1 = 4x + 8
        drawGraph(window, [](float x) { return 4 * x + 8; }, -10, 10, 20, 2.5, sf::Color::Red);

        // ��������� ������� y2 = 6x
        drawGraph(window, [](float x) { return 6 * x; }, -10, 10, 20, 2.5, sf::Color::Blue);

        // ��������� ���������������� �����, ���� ��� ����������
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // ����������� ������ �����
        window.display();
    }

    return 0;
}