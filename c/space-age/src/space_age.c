//
// Created by Carl Youngblood on 2019-03-09.
//

#include "space_age.h"

float convert_planet_age(enum planet p, double seconds)
{
    float returnval = seconds / 31557600.0;
    switch (p) {
        case MERCURY: returnval /= 0.2408467; break;
        case VENUS: returnval /= 0.61519726; break;
        case EARTH: break;
        case MARS: returnval /= 1.8808158; break;
        case JUPITER: returnval /= 11.862615; break;
        case SATURN: returnval /= 29.447498; break;
        case URANUS: returnval /= 84.016846; break;
        case NEPTUNE: returnval /= 164.79132;
    }
    return returnval;
}
