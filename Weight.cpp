///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <ostream>
#include <iostream>
#include <stdio.h>
#include "Weight.h"


using namespace std;

const float Weight::UNKNOWN_WEIGHT = -1;
const float Weight::SLUGS_IN_A_POUND = .031081;
const float Weight::KILOS_IN_A_POUND = .453592;


float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
if (fromWeight < 0){
    cout << "Cannot convert " << fromWeight << "\n" << endl;
    return false;
} else {
    switch (fromUnit) {
        case POUND:
            switch(toUnit){
                case POUND:
                    return fromWeight; // no conversion needed
                case SLUG:
                    return fromPoundToSlug(fromWeight);
                case KILO:
                    return fromPoundToKilogram(fromWeight);
        }
        case SLUG:
            switch(toUnit){
                case POUND:
                    return fromSlugToPound(fromWeight);
                case SLUG:
                    return fromWeight; // no conversion needed
                case KILO:
                    return fromPoundToKilogram(fromSlugToPound(fromWeight)); // Slug -> Pound -> Kilogram
            }
        case KILO:
            switch(toUnit){
                case POUND:
                    return fromKilogramToPound(fromWeight);
                case SLUG:
                    return fromPoundToSlug(fromKilogramToPound(fromWeight)); // Kilogram -> Pound -> Slug
                case KILO:
                    return fromWeight; // no conversion needed
            }
        default:
            cout << "Unknown Unit\n" << endl;
            return false;
        }
    }
}
