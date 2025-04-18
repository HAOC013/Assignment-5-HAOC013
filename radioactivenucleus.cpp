// C++ Assignment 5: RadioactiveNucleus class implementation
// ID: 11010580
// Date: 19th April 2025
//

#include "radioactivenucleus.h"
#include <iostream>

RadioactiveNucleus::RadioactiveNucleus(double atomic_mass, int atomic_number,
                                       const std::string& nucleus_type,
                                       double half_life, const std::vector<double>& photon_energies)
  : Nucleus(atomic_mass, atomic_number, nucleus_type),
    half_life_(half_life),
    photon_energies_(photon_energies) {}

RadioactiveNucleus::~RadioactiveNucleus() = default;

RadioactiveNucleus::RadioactiveNucleus(const RadioactiveNucleus& other)
  : Nucleus(other),
    half_life_(other.half_life_),
    photon_energies_(other.photon_energies_) {}

RadioactiveNucleus& RadioactiveNucleus::operator=(const RadioactiveNucleus& other) {
  if (this != &other) {
    Nucleus::operator=(other);
    half_life_ = other.half_life_;
    photon_energies_ = other.photon_energies_;
  }
  return *this;
}

RadioactiveNucleus::RadioactiveNucleus(RadioactiveNucleus&& other) noexcept
  : Nucleus(std::move(other)),
    half_life_(other.half_life_),
    photon_energies_(std::move(other.photon_energies_)) {}

RadioactiveNucleus& RadioactiveNucleus::operator=(RadioactiveNucleus&& other) noexcept {
  if (this != &other) {
    Nucleus::operator=(std::move(other));
    half_life_ = other.half_life_;
    photon_energies_ = std::move(other.photon_energies_);
  }
  return *this;
}

void RadioactiveNucleus::decay() {
  if (decayed_) return;

  std::cout << "Decaying " << nucleus_type_ << "...\n";

  int total_pathways = static_cast<int>(photon_energies_.size()) + (nucleus_type_ == "Na" ? 1 : 0);

  for (size_t i = 0; i < photon_energies_.size(); ++i) {
    std::cout << "  Decay pathway " << (i + 1) << " of " << total_pathways << ":\n";

    auto photon = std::make_shared<Photon>(photon_energies_[i]);
    photon->print_data();
    emitted_photons_.push_back(photon);

    // IMPORTANT: pair production should be attempted BEFORE energy is changed
    std::cout << "    --> Attempting pair production:\n";
    auto electrons = pair_production(*photon);
    if (!electrons.empty()) {
      std::cout << "        Pair production successful:\n";
      for (auto& e : electrons) {
        std::cout << "          ";
        e->print_data();
        std::cout << "          Address: " << e.get() << "\n";

        auto extra_photon = std::make_shared<Photon>(0.1);
        e->add_photon(extra_photon);

        auto emitted = radiate(*e);
        if (emitted) {
          std::cout << "          Radiated photon energy: " << emitted->get_energy() << " MeV\n";
          std::cout << "          Photon address: " << emitted.get() << "\n";
        }
      }
    }
    // Apply other interactions after pair production check
    std::cout << "    --> Photoelectric effect:\n";
    double absorbed = photoelectric_effect(*photon);
    std::cout << "        Energy absorbed: " << absorbed << " MeV\n";

    std::cout << "    --> Compton scattering:\n";
    double scattered = compton_scattering(*photon);
    std::cout << "        Scattered energy: " << scattered << " MeV\n";
  }

  if (nucleus_type_ == "Na") {
    std::cout << "  Decay pathway " << total_pathways << " of " << total_pathways << ":\n";
    std::cout << "    Positron emitted (beta-plus decay)\n";
  }

  decayed_ = true;
}


void RadioactiveNucleus::print_data() const {
  std::cout << "Radioactive Nucleus: " << nucleus_type_
            << " (Z=" << atomic_number_ << ", A=" << atomic_mass_
            << ", Half-life=" << half_life_ << ")\n";
}