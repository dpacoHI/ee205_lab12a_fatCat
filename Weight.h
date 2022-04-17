///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author David Paco <dpaco@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB12A_FATCAT_WEIGHT_H
#define EE205_LAB12A_FATCAT_WEIGHT_H

#include <string>
#include <ostream>

using namespace std;

static const std::string POUND_LABEL = "Pound";
static const std::string KILO_LABEL = "Kilo";
static const std::string SLUG_LABEL = "Slug";


class Weight {

public: // Static Public Attributes
    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;

public: // Public Types
    enum UnitOfWeight{POUND, KILO, SLUG};

public: // Public Member Functions
    Weight() noexcept;
    Weight(float newWeight);
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);

    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;

    float getWeight() const noexcept;
    float getWeight(UnitOfWeight weightUnits) const noexcept;

    float getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;

    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnits);

    bool isWeightValid(float checkWeight) const noexcept;
    bool validate() const noexcept;
    void dump() const noexcept;
    bool operator==(const Weight & rhs_Weight) const;
    bool operator<(const Weight & rhs_Weight) const;
    Weight & operator+=(float rhs_addToWeight);

public: // Static Public Member Functions
    static float fromKilogramToPound(float kilogram) noexcept;
    static float fromPoundToKilogram(float pound) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug(float pound) noexcept;
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

private: // Private Member Functions
    void setMaxWeight(float newMaxWeight);

private: // Private Attributes
    bool blsKnown = false;
    bool bHasMax = false;
    enum UnitOfWeight unitOfWeight = POUND;
    float weight{};
    float maxWeight{};
};




#endif //EE205_LAB12A_FATCAT_WEIGHT_H
