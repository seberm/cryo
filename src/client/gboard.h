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


#ifndef G_BOARD
#define G_BOARD

#include <SFML/Graphics.hpp>


class GBoard {
    public:
        /**
         * Konstruktor
         *
         * @param  window okno, na kterem se bude zobrazovat hraci plocha
         */
        GBoard(sf::RenderWindow *window);

    private:
        /**
         * Okno, na kterem se zobrazuje hraci plocha
         */
        sf::RenderWindow *m_window;
};

#endif
