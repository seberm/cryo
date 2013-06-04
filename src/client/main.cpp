/*
 * Cryo
 *
 * Copyright (C) 2013-2014 Otto Sabart & Vaclav Stransky
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "gboard.h"
#include "config.h"


int main() {
    // Nastaveni funkcnosti okna
    sf::Uint32 windowStyle = sf::Style::Close | sf::Style::Titlebar;
    if (APP_FULLSCREEN)
        windowStyle = sf::Style::Fullscreen;

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Vytvoreni hlavniho okna, barevna hloubka se ziska z aktualniho nastaveni plochy
    sf::RenderWindow window(sf::VideoMode(APP_WIDTH, APP_HEIGHT, desktopMode.bitsPerPixel), APP_NAME, windowStyle);

    window.setFramerateLimit(FRAMERATE_LIMIT);

    // Vytvorime objekt hraci plochy
    GBoard board(&window);

    /*
    // Nastaveni barev a hloubky
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 1.f, 0.f);
    */

    // Hlavni cyklus okna
    while (window.isOpen()) {

        // Zpracovani udalosti
        sf::Event event;
        while (window.pollEvent(event)) {
            // Uzavreni okna
            if (event.type == sf::Event::Closed)
                window.close();

            // ESC - provede opet uzavreni okna
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            // Zmena velikosti okna
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
        }


        /*
        //toto si pak smaz ...pokud z toho nic nepouzijes
        for (float i = 0.0; i < 1; i+=0.01) {
            glClearColor(2*i, 1-i, i, i);

            // Activate the window before using OpenGL commands.
            // This is useless here because we have only one window which is
            // always the active one, but don't forget it if you use multiple windows
            window.setActive();

            // Clear color and depth buffer
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Prekreslime okno
            window.display();
        }
        */

        // Vycisteni okna pred prekreslenim
        window.clear();

        // Vykreslujeme hraci plochu
        board.draw();

        // Prekreslime okno
        window.display();
    }

    return EXIT_SUCCESS;
}
