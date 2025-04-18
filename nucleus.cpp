// Filename: Nucleus.cpp
// Purpose: Implementation of the Nucleus class and Rule of 5.
// Student ID: 
// Date: April 2025

#include "nucleus.h"

Nucleus::Nucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
  : atomic_mass_(atomic_mass),
    atomic_number_(atomic_number),
    nucleus_type_(nucleus_type),
    decayed_(false) {}

Nucleus::~Nucleus() = default;

Nucleus::Nucleus(const Nucleus& other)
  : atomic_mass_(other.atomic_mass_),
    atomic_number_(other.atomic_number_),
    nucleus_type_(other.nucleus_type_),
    decayed_(other.decayed_),
    emitted_photons_(other.emitted_photons_) {}

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

Nucleus::Nucleus(Nucleus&& other) noexcept
  : atomic_mass_(other.atomic_mass_),
    atomic_number_(other.atomic_number_),
    nucleus_type_(std::move(other.nucleus_type_)),
    decayed_(other.decayed_),
    emitted_photons_(std::move(other.emitted_photons_)) {}

Nucleus& Nucleus::operator=(Nucleus&& other) noexcept {
  if (this != &other) {
    atomic_mass_ = other.atomic_mass_;
    atomic_number_ = other.atomic_number_;
    nucleus_type_ = std::move(other.nucleus_type_);
    decayed_ = other.decayed_;
    emitted_photons_ = std::move(other.emitted_photons_);
  }
  return *this;
}

double Nucleus::get_atomic_mass() const {
  return atomic_mass_;
}

int Nucleus::get_atomic_number() const {
  return atomic_number_;
}

std::string Nucleus::get_nucleus_type() const {
  return nucleus_type_;
}
