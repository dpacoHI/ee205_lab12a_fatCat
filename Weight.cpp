///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatWeight - EE 205 - Spr 2022
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
#include <stdbool.h>
#include <string.h>
#include <memory>
#include <iomanip>
#include <cassert>
#include "Weight.h"


using namespace std;

const float Weight::UNKNOWN_WEIGHT = -1;
const float Weight::SLUGS_IN_A_POUND = .031081;
const float Weight::KILOS_IN_A_POUND = .453592;

// Defined Static Public Member Functions (Conversions)
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
    cout << "Cannot convert " << fromWeight << endl;
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

// Boolean (Validation) Functions
bool Weight::isWeightValid(float checkWeight) const
noexcept {
    if (checkWeight <= 0){
        cout << "ERROR: " << checkWeight << " is not greater than 0" << endl;
    } else if (bHasMax == true){
        if (checkWeight > maxWeight){
            cout << "ERROR: " << checkWeight << " is greater than " << maxWeight << endl;
        }
    }
return true;
}

bool Weight::hasMaxWeight() const
noexcept {
    if (bHasMax == true){
        return true;
    } else {
        return false;
    }
}

bool Weight::validate() const
noexcept {
    if (bIsKnown == true){
        if(isWeightValid(weight) == false){
            return false;
        }
    } else if (bHasMax == true){
        if (isWeightValid(maxWeight) == false){
            return false;
        }
    }
    return true;
}

// Getters and Setters
float Weight::getWeight() const
noexcept {
    if (bIsKnown == true){
        return weight;
    } else {
        return UNKNOWN_WEIGHT;
    }
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const
noexcept {
    return convertWeight(weight, unitOfWeight, weightUnits);
}

void Weight::setWeight(float newWeight) {
    if (isWeightValid(newWeight) == true) {
        bIsKnown = true;
        weight = newWeight;
    }
}

void Weight::setWeight(float newWeight, UnitOfWeight weightUnits) {
    setWeight(convertWeight(newWeight, weightUnits, unitOfWeight  ));
}

float Weight::getMaxWeight() const
noexcept {
    if(bHasMax == true) {
        return maxWeight;
    } else {
    return UNKNOWN_WEIGHT;
    }
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

// Private Member Function Defined
void Weight::setMaxWeight(float newMaxWeight) {
    if (bHasMax == false){
        if (isWeightValid(newMaxWeight) == true){
            bHasMax = true;
            maxWeight = newMaxWeight;
        }
    }
}

// Public Member Functions
Weight::Weight() noexcept{
}

Weight::Weight(float newWeight) { // Creates Weight with Value
    setWeight(newWeight);
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept { // Create Weight with Unit of Weight
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) { // Create Weight with Value and Unit of Weight
    setWeight(newWeight, newUnitOfWeight);
}

Weight::Weight(float newWeight, float newMaxWeight) { // Create Weight with Value and Max Weight
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) { // Create Weight with Unit of Weight and Max Weight
    unitOfWeight = newUnitOfWeight;
    setMaxWeight(newMaxWeight);
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) { // Create Weight with Value, Unit of Weight and Max Weight
    setMaxWeight(newMaxWeight);
    setWeight(newWeight);
    unitOfWeight = newUnitOfWeight;
}
// Operator Functions
std::ostream& operator<<( ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << POUND_LABEL ;
        case Weight::KILO: return lhs_stream << KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}

bool Weight::operator==( const Weight& rhs_Weight ) const {
    /// Remember to convert the two weight's units into a common unit!
    /// Treat unknown weights as 0 (so we can sort them without dealing
    /// with exceptions)
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}
bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}
Weight &Weight::operator+=(float &rhs_addToWeight) {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float sum = lhs_weight + rhs_addToWeight;
    return *this;
}

void Weight::dump() const
noexcept {
    //assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight", "this" ) << &weight << endl ;
    FORMAT_LINE( "Weight", "isKnown" ) << bIsKnown << endl ;
    FORMAT_LINE( "Weight", "weight" ) << getWeight() << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << unitOfWeight << endl ;
    FORMAT_LINE( "Weight", "hasMax" ) << bHasMax << endl ;
    FORMAT_LINE( "Weight", "maxWeight" ) << getMaxWeight() << endl ;
}