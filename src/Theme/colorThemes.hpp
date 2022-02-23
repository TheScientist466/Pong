#pragma once

#include <SFML/Graphics/Color.hpp>
using namespace sf;

namespace colorThemes
{
    namespace Nord
    {
        namespace PolarNight
        {
            const Color d1 (0x2E, 0x34, 0x40);
            const Color d2 (0x3B, 0x42, 0x52);
            const Color d3 (0x43, 0x4C, 0x5E);
            const Color d4 (0x4C, 0x56, 0x6A);
        }

        namespace SnowStorm
        {
            const Color d1 (0xD8, 0xDE, 0xE9);
            const Color d2 (0xE5, 0xE9, 0xF0);
            const Color d3 (0xEC, 0xEF, 0xF4);
        }

        namespace Frost
        {
            const Color d1 (0x5E, 0x81, 0xAC);
            const Color d2 (0x81, 0xA1, 0xC1);
            const Color d3 (0x88, 0xC0, 0xD0);
            const Color d4 (0x8F, 0xBC, 0xBB);
        }

        namespace Arora
        {
            const Color Red     (0xBF, 0x61, 0x6A);
            const Color Orange  (0xD0, 0x87, 0x70);
            const Color Yellow  (0xEB, 0xCB, 0x8B);
            const Color Green   (0xA3, 0xBE, 0x8C);
            const Color Purple  (0xB4, 0x8E, 0xAD);
        }

    }

    namespace Dracula
    {
        namespace Others
        {
            const Color Background  (0x28, 0x2a, 0x36);
            const Color CurrentLine (0x44, 0x47, 0x5a);
            const Color Selection   (0x44, 0x47, 0x5a);
            const Color Foreground  (0xf8, 0xf8, 0xf2);
            const Color Comment     (0x62, 0x72, 0xa4);
        }
        
        namespace Colors
        {
            const Color Cyan    (0x8b, 0xe9, 0xfd);
            const Color Green   (0x50, 0xfa, 0x7b);
            const Color Orange  (0xff, 0xb8, 0x6c);
            const Color Pink    (0xff, 0x79, 0xc6);
            const Color Purple  (0xbd, 0x93, 0xf9);
            const Color Red     (0xff, 0x55, 0x55);
            const Color Yellow  (0xf1, 0xfa, 0x8c);
        }
    }
}