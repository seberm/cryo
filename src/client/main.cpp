#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Window");
    App.Create(sf::VideoMode(800, 600, 32), "SFML Window");

    //App.Create(sf::VideoMode(800, 600, 32), "SFML Window", sf::Style::Fullscreen);
    
    bool Running = true;
    while (Running) {
        sf::Event Event;

        while (App.GetEvent(Event)) {
            // Window closed
            if (Event.Type == sf::Event::Closed)
                Running = false;

            // Escape key pressed
            if ((Event.Type == sf::Event::KeyPressed) &&
                (Event.Key.Code == sf::Key::Escape)) {

                Running = false;
            }
        }

        App.Display();
    }

    return EXIT_SUCCESS;
}

