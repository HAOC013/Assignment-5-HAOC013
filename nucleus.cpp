// Filename: Nucleus.cpp
// Purpose: Implements the base Nucleus class.
// Student ID: 
// Date: April 2025

#include "Nucleus.h"

Nucleus::Nucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
  : atomic_mass_(atomic_mass),
    atomic_number_(atomic_number),
    nucleus_type_(nucleus_type),
    decayed_(false)
{
}

double Nucleus::get_atomic_mass() const
{
  return atomic_mass_;
}

int Nucleus::get_atomic_number() const
{
  return atomic_number_;
}

std::string Nucleus::get_nucleus_type() const
{
  return nucleus_type_;
}
