#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    // Create the main window
    sf::Window window(sf::VideoMode(640, 480, 32), "SFML Window", sf::Style::Default, sf::ContextSettings(32));

    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 1.f, 0.f);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape key : exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            // Resize event : adjust viewport
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
       }

        for (float i = 0.0; i < 1; i+=0.01) {
            glClearColor(2*i, 1-i, i, i);

        // Activate the window before using OpenGL commands.
        // This is useless here because we have only one window which is
        // always the active one, but don't forget it if you use multiple windows
        window.setActive();

        // Clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Finally, display the rendered frame on screen
        window.display();
        }
    }

    return 0;
}
