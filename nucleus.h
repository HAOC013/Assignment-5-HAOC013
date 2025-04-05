// Filename: Nucleus.h
// Purpose: Declares the base Nucleus class with atomic properties.
// Student ID: 
// Date: April 2025

#ifndef NUCLEUS_H
#define NUCLEUS_H

#include <string>
#include <memory>
#include <vector>
#include "Photon.h"

class Nucleus
{
public:
  Nucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type);
  virtual ~Nucleus() = default;

  virtual void decay() = 0;
  virtual void print_data() const = 0;

  double get_atomic_mass() const;
  int get_atomic_number() const;
  std::string get_nucleus_type() const;

protected:
  double atomic_mass_;
  int atomic_number_;
  std::string nucleus_type_;
  bool decayed_;
  std::vector<std::shared_ptr<Photon>> emitted_photons_;
};

#endif // NUCLEUS_H
