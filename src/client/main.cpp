#include <SFML/Window.hpp>

int main() {
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Window");
    App.Create(sf::VideoMode(800, 600, 32), "SFML Window");

    //App.Create(sf::VideoMode(800, 600, 32), "SFML Window", sf::Style::Fullscreen);
    
    while (App.IsOpened()) {
        sf::Event Event;

        while (App.GetEvent(Event)) {
            // Window closed
            if (Event.Type == sf::Event::Closed)
                App.Close();

            // Escape key pressed
            if ((Event.Type == sf::Event::KeyPressed) &&
                (Event.Key.Code == sf::Key::Escape)) {

                App.Close();
            }
        }

        App.Display();
    }

    return EXIT_SUCCESS;
}

