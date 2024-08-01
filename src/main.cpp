#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "GLOBALS.hpp"

#define DEBUGGG 1

using std::cout, std::endl;

void getCenterCoordLines(const sf::RenderWindow& window, sf::VertexArray& lines);

class Ball {
    sf::RenderWindow& _window;
    sf::RectangleShape _body;
    float _velX;
    float _vely;
public:
    explicit Ball(sf::RenderWindow& window): _window(window) {
        _body.setSize(sf::Vector2f(20, 20));
        _body.setFillColor(sf::Color::Red);
        _body.setOrigin(_body.getLocalBounds().width / 2, _body.getLocalBounds().height / 2);
        _body.setPosition(_window.getSize().x / 2, _window.getSize().y / 2);
    }
    ~Ball() = default;

    void draw() const {
        _window.draw(_body);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Proj_9: Pong");
    window.setFramerateLimit(FPS);

    sf::VertexArray debugLines;
    getCenterCoordLines(window, debugLines);

    std::unordered_map<sf::Keyboard::Key, bool> keyStates;
    for (int key = sf::Keyboard::A; key <= sf::Keyboard::KeyCount; ++key) {
        keyStates[static_cast<sf::Keyboard::Key>(key)] = false;
    }

    Ball ball(window);

    sf::Event event{};
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
                return EXIT_SUCCESS;
            } if (event.type == sf::Event::KeyPressed) {
                keyStates[event.key.code] = true;
            } if (event.type == sf::Event::KeyReleased) {
                keyStates[event.key.code] = false;
            }
        }

        for (const auto& [key, state] : keyStates) {
            if (state) cout << keyToString(key) << endl;
        }

        window.clear();
        ball.draw();
        if constexpr (DEBUGGG) window.draw(debugLines);
        window.display();
    }

    return 0;
}

void getCenterCoordLines(const sf::RenderWindow& window, sf::VertexArray& lines) {
    // Get the center of the window
    sf::Vector2f const center(window.getSize().x / 2, window.getSize().y / 2);

    // Resize the VertexArray to hold 4 vertices
    lines.setPrimitiveType(sf::Lines);
    lines.resize(4);

    // Horizontal line
    lines[0].position = sf::Vector2f(0, center.y);
    lines[1].position = sf::Vector2f(window.getSize().x, center.y);

    // Vertical line
    lines[2].position = sf::Vector2f(center.x, 0);
    lines[3].position = sf::Vector2f(center.x, window.getSize().y);

    // Optional: set the color of the lines
    for (int i = 0; i < 4; ++i) {
        lines[i].color = sf::Color::Green;
    }
}








