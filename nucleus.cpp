// Nucleus.cpp
// Purpose: Implementation of the Nucleus class
// Student ID: 12345678
// Date: 2025-04-05

#include "Nucleus.h"

// Constructor for the Nucleus class
Nucleus::Nucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
    : atomic_mass_(atomic_mass), atomic_number_(atomic_number), nucleus_type_(nucleus_type), decayed_(false) {}

// Getter for the nucleus name (type)
std::string Nucleus::get_nucleus_type() const {
    return nucleus_type_;
}

// Getter for the atomic number of the nucleus
int Nucleus::get_atomic_number() const {
    return atomic_number_;
}

// Getter for the atomic mass of the nucleus
double Nucleus::get_atomic_mass() const {
    return atomic_mass_;
}
