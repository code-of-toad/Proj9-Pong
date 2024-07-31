#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "GLOBALS.hpp"

using std::cout, std::endl;


int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Proj_9: Pong");
    window.setFramerateLimit(FPS);

    std::unordered_map<sf::Keyboard::Key, bool> keyStates;
    for (int key = sf::Keyboard::A; key <= sf::Keyboard::KeyCount; ++key)
        keyStates[static_cast<sf::Keyboard::Key>(key)] = false;


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
        window.display();
    }

    return 0;
}