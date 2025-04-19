// Filename: RadioactiveNucleus.cpp
// Purpose: Implements the RadioactiveNucleus class and decay logic.
// Student ID: 11010580
// Date: 19th April 2025

#include "radioactivenucleus.h"
#include <iostream>
#include <iomanip>

// Global summary tracking
int total_decayed = 0;
int total_photons = 0;
int total_electrons = 0;
int total_positrons = 0;
int total_radiated_photons = 0;
int total_annihilation_photons = 0;

void print_simulation_summary() {
  std::cout << "\n==== Simulation Summary ====\n";
  std::cout << "Nuclei simulated: 4 (" << total_decayed << " decayed + " << (4 - total_decayed) << " stable)\n";
  std::cout << "Photons emitted: " << total_photons << "\n";
  std::cout << "Electrons created: " << total_electrons << "\n";
  std::cout << "Photons radiated by electrons: " << total_radiated_photons << "\n";
  std::cout << "Photons from annihilation: " << total_annihilation_photons << "\n";
  std::cout << "Positrons emitted: " << total_positrons << " (from Na)\n";
}

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

void RadioactiveNucleus::print_data() const {
  std::cout << "== Nucleus Data ==\n";
  std::cout << nucleus_type_
            << " (Z=" << atomic_number_
            << ", A=" << static_cast<int>(atomic_mass_)
            << ", Half-life=" << half_life_ << " years)" << std::endl;
  std::cout << "Status: Radioactive Nucleus\n";
}

void RadioactiveNucleus::decay() {
  if (decayed_) return;

  std::cout << "\n== Decaying " << nucleus_type_ << "... ==\n";

  int total_pathways = static_cast<int>(photon_energies_.size()) + (nucleus_type_ == "Na" ? 1 : 0);

  for (size_t i = 0; i < photon_energies_.size(); ++i) {
    std::cout << "  Decay pathway " << (i + 1) << " of " << total_pathways << ":\n";

    auto photon = std::make_shared<Photon>(photon_energies_[i]);
    std::cout << "    Photon with energy: " << std::fixed << std::setprecision(3)
              << photon->get_energy() << " MeV\n";
    emitted_photons_.push_back(photon);
    total_photons++;

    std::cout << "        --> Attempting pair production:\n";
    auto particles = pair_production(*photon);
    if (!particles.empty()) {
      std::cout << "            Pair production successful:\n";
      for (size_t i = 0; i < particles.size(); ++i) {
        std::string label = (i == 0) ? "Electron" : "Positron";
        if (i == 0) total_electrons++;
        else total_positrons++;

        double total_energy = particles[i]->get_energy();
        std::cout << "                " << label << " with energy: " << std::fixed << std::setprecision(3)
                  << total_energy << " MeV\n";
        std::cout << "                Address: " << particles[i].get() << "\n";

        if (i == 0) {
          double kinetic = total_energy - 0.511;
          if (kinetic > 0.01) {
            double emitted_energy = 0.5 * kinetic;
            auto radiation = std::make_shared<Photon>(emitted_energy);
            particles[i]->add_photon(radiation);
            auto emitted = radiate(*particles[i]);
            if (emitted) {
              std::cout << "                    --> Electron radiated photon with energy: "
                        << std::fixed << std::setprecision(3)
                        << emitted->get_energy() << " MeV\n";
              total_radiated_photons++;
            }
          } else {
            std::cout << "                Kinetic energy too low for radiation.\n";
          }
        }
      }
    } else {
      std::cout << "            Error: Photon energy too low for pair production.\n";
    }

    std::cout << "\n        --> Attempting photoelectric effect:\n";
    double absorbed = photoelectric_effect(*photon);
    std::cout << "            Photoelectric absorbed energy: " << std::fixed << std::setprecision(3)
              << absorbed << " MeV\n";

    std::cout << "\n        --> Attempting Compton scattering:\n";
    double scattered = compton_scattering(*photon);
    std::cout << "           Photon energy after Compton scattering: " << std::fixed << std::setprecision(3)
              << scattered << " MeV\n\n";
  }

  if (nucleus_type_ == "Na") {
    std::cout << "  Decay pathway " << total_pathways << " of " << total_pathways << ":\n";
    std::cout << "    Positron emitted (beta-plus decay)\n";
    total_positrons++;

    Electron positron(0.511);  // simulate positron

    std::cout << "    Positron annihilates with electron --> Produces 2 photons of 0.511 MeV\n";

    auto photon1 = std::make_shared<Photon>(0.511);
    auto photon2 = std::make_shared<Photon>(0.511);
    photon1->print_data();
    photon2->print_data();

    emitted_photons_.push_back(photon1);
    emitted_photons_.push_back(photon2);
    total_photons += 2;
    total_annihilation_photons += 2;

    std::cout << "      Interactions for annihilation photons:\n";
    for (const auto& p : {photon1, photon2}) {
      std::cout << "      Photon of energy: " << std::fixed << std::setprecision(3)
                << p->get_energy() << " MeV\n";

      std::cout << "\n        --> Attempting photoelectric effect:\n";
      std::cout << "           Photoelectric absorbed energy: " << std::fixed << std::setprecision(3)
                << photoelectric_effect(*p) << " MeV\n";

      std::cout << "\n        --> Attempting Compton scattering:\n";
      std::cout << "           Compton scattered energy: " << std::fixed << std::setprecision(3)
                << compton_scattering(*p) << " MeV\n";

      std::cout << "\n        --> Attempting pair production:\n";
      auto electrons = pair_production(*p);
      if (!electrons.empty()) {
        std::cout << "           Pair production successful.\n";
      } else {
        std::cout << "           Error: Photon energy too low for pair production.\n";
      }
    }
  }

  decayed_ = true;
  total_decayed++;
  std::cout << std::endl;
}
