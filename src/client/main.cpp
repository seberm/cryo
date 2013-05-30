#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");

    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
