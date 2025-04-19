// C++ Assignment 5: Nucleus class header
// ID: 11010580
// Date: 19th April 2025
// Headers for nuclear base class

#ifndef NUCLEUS_H
#define NUCLEUS_H

#include "photon.h"
#include <string>
#include <vector>
#include <memory>


class Nucleus {
public:
  Nucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type);
  virtual ~Nucleus();  // Rule of 5: Virtual destructor

  Nucleus(const Nucleus& other);  // Rule of 5: Copy constructor
  Nucleus& operator=(const Nucleus& other);  // Rule of 5: Copy assignment

  Nucleus(Nucleus&& other) noexcept;  // Rule of 5: Move constructor
  Nucleus& operator=(Nucleus&& other) noexcept;  // Rule of 5: Move assignment

  virtual void decay() = 0;
  virtual void print_data() const = 0;

  double get_atomic_mass() const;
  int get_atomic_number() const;
  std::string get_nucleus_type() const;

protected: // protected members which are accessible in derived classes
  double atomic_mass_;
  int atomic_number_;
  std::string nucleus_type_;
  bool decayed_;
  std::vector<std::shared_ptr<Photon>> emitted_photons_;
};

#endif // NUCLEUS_H
