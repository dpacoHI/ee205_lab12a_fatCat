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


