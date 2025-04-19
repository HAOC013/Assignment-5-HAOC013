// C++ Assignment 5: Nucleus class implementation
// ID: 11010580
// Date: 19th April 2025
// Creates Nucleus class that serves as a base class for radioactive and stable nuclei


#include "nucleus.h"

// Defining all 5 special member functions (Rule of 5) for the Nucleus base class


// Constructor to initialize nucleus properties
Nucleus::Nucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
  : atomic_mass_(atomic_mass),
    atomic_number_(atomic_number),
    nucleus_type_(nucleus_type),
    decayed_(false) {}

// Destructor for Nucleus class (default destructor, stated for completeness)
Nucleus::~Nucleus() = default;

// Copy constructor 
Nucleus::Nucleus(const Nucleus& other)
  : atomic_mass_(other.atomic_mass_),
    atomic_number_(other.atomic_number_),
    nucleus_type_(other.nucleus_type_),
    decayed_(other.decayed_),
    emitted_photons_(other.emitted_photons_) {}

// Copy assignment operator
Nucleus& Nucleus::operator=(const Nucleus& other) {
  if (this != &other) {
    atomic_mass_ = other.atomic_mass_;
    atomic_number_ = other.atomic_number_;
    nucleus_type_ = other.nucleus_type_;
    decayed_ = other.decayed_;
    emitted_photons_ = other.emitted_photons_;
  }
  return *this;
}

// Move Constructor
/// @param other 
Nucleus::Nucleus(Nucleus&& other) noexcept
  : atomic_mass_(other.atomic_mass_),
    atomic_number_(other.atomic_number_),
    nucleus_type_(std::move(other.nucleus_type_)),
    decayed_(other.decayed_),
    emitted_photons_(std::move(other.emitted_photons_)) {}

// Move assignment operator
Nucleus& Nucleus::operator=(Nucleus&& other) noexcept {
  if (this != &other) {
    atomic_mass_ = other.atomic_mass_;
    atomic_number_ = other.atomic_number_;
    nucleus_type_ = std::move(other.nucleus_type_);
    decayed_ = other.decayed_;
    emitted_photons_ = std::move(other.emitted_photons_);
  }
  return *this; // returns the current object
}

// Prints data about the nucleus
double Nucleus::get_atomic_mass() const {
  return atomic_mass_;
}

// Returns the atomic number of the nucleus
int Nucleus::get_atomic_number() const {
  return atomic_number_;
}

// Returns the type of the nucleus (Radioactive or Stable)
std::string Nucleus::get_nucleus_type() const {
  return nucleus_type_;
}
