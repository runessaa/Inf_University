#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <cmath>

// Ôóíêöèÿ äëÿ îòðèñîâêè ãðàôèêà
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // Âû÷èñëåíèå çíà÷åíèÿ ôóíêöèè

        // Ïðåîáðàçîâàíèå êîîðäèíàò â ýêðàííûå
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // Äîáàâëåíèå òî÷êè â ìàññèâ âåðøèí
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

// Îïðåäåëåíèå çîíû
int determineZone(float x, float y) {
    float y1 = 4 * x + 8; // Ïåðâàÿ ïðÿìàÿ
    float y2 = 6 * x; // Âòîðàÿ ïðÿìàÿ

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
    // Ñîçäàíèå îêíà
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphing application");

    // Ïåðåìåííàÿ äëÿ õðàíåíèÿ ïîëüçîâàòåëüñêîé òî÷êè
    sf::CircleShape userPoint(5); // Ðàäèóñ 5 ïèêñåëåé
    userPoint.setFillColor(sf::Color::Yellow);
    bool userPointExists = false; // Ïåðåìåííàÿ äëÿ ïðîâåðêè ñóùåñòâîâàíèÿ ïîëüçîâàòåëüñêîé òî÷êè

    // Çàãðóçêà øðèôòà
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) return -1;

    // Òåêñò äëÿ îòîáðàæåíèÿ êîîðäèíàò òî÷êè
    sf::Text coordinatesText("", font, 20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    // Îñè X è Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(0, 300); // Íà÷àëî îñè X
    xAxis[0].color = sf::Color::White; // Öâåò îñè
    xAxis[1].position = sf::Vector2f(800, 300); // Êîíåö îñè X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 0); // Íà÷àëî îñè Y
    yAxis[0].color = sf::Color::White; // Öâåò îñè
    yAxis[1].position = sf::Vector2f(400, 600); // Êîíåö îñè Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Ïðîâåðêà êëèêà ìûøüþ
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Ïîëó÷åíèå ïîçèöèè êëèêà
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Ïðåîáðàçîâàíèå ýêðàííûõ êîîðäèíàò â "ìàòåìàòè÷åñêèå"
                    float mathX = (mousePos.x - 400) / 20.0f; // Ìàñøòàá 20 ïî X
                    float mathY = -(mousePos.y - 300) / 2.5f; // Ìàñøòàá 2.5 ïî Y

                    // Óñòàíîâêà íîâîé ïîëüçîâàòåëüñêîé òî÷êè
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; // Ïîìå÷àåì, ÷òî òî÷êà ñóùåñòâóåò

                    // Îïðåäåëåíèå çîíû
                    int zone = determineZone(mathX, mathY);

                    // Îáíîâëåíèå òåêñòà ñ êîîðäèíàòàìè òî÷êè
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) +
                        ")\nZone: " + std::to_string(zone));
                }
            }
        }

        // Î÷èñòêà ýêðàíà
        window.clear();

        // Îòðèñîâêà îñåé
        window.draw(xAxis);
        window.draw(yAxis);

        // Îòðèñîâêà ãðàôèêà y1 = 4x + 8
        drawGraph(window, [](float x) { return 4 * x + 8; }, -10, 10, 20, 2.5, sf::Color::Red);

        // Îòðèñîâêà ãðàôèêà y2 = 6x
        drawGraph(window, [](float x) { return 6 * x; }, -10, 10, 20, 2.5, sf::Color::Blue);

        // Îòðèñîâêà ïîëüçîâàòåëüñêîé òî÷êè, åñëè îíà ñóùåñòâóåò
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // Îòîáðàæåíèå íîâîãî êàäðà
        window.display();
    }

    return 0;
}
