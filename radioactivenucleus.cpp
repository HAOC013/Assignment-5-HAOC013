// C++ Assignment 5: RadioactiveNucleus.cpp
// ID: 11010580
// Date: 19th April 2025
// Implements the RadioactiveNucleus class, which inherits from the Nucleus class and models radioactive decay.

#include "radioactivenucleus.h"
#include <iostream>
#include <iomanip>

// Initialising tracking counters, this is used to at the end of the output to summrise the simulations.
int total_decayed = 0;
int total_photons = 0;
int total_electrons = 0;
int total_positrons = 0;
int total_radiated_photons = 0;
int total_annihilation_photons = 0;

// Prints simulation summary (at end of program)
void print_simulation_summary() {
  std::cout << "\n==== Simulation Summary ====\n";
  std::cout << "Nuclei simulated: 4 (" << total_decayed << " decayed + " << (4 - total_decayed) << " stable)\n";
  std::cout << "Photons emitted: " << total_photons << "\n";
  std::cout << "Electrons created: " << total_electrons << "\n";
  std::cout << "Photons radiated from electrons: " << total_radiated_photons << "\n";
  std::cout << "Photons from annihilation: " << total_annihilation_photons << "\n";
  std::cout << "Positrons emitted: " << total_positrons << " (from pair creation and beta+ decay)\n";
}

// Constructor to initialize radioactive nucleus properties
RadioactiveNucleus::RadioactiveNucleus(double atomic_mass, int atomic_number,
                                       const std::string& nucleus_type,
                                       double half_life, const std::vector<double>& photon_energies)
  : Nucleus(atomic_mass, atomic_number, nucleus_type),
    half_life_(half_life),
    photon_energies_(photon_energies) {}

// Destructor for radioactive nucleus class (default destructor as for other classes in this assigment, stated for completeness)
RadioactiveNucleus::~RadioactiveNucleus() = default;

// Copy constructor
RadioactiveNucleus::RadioactiveNucleus(const RadioactiveNucleus& other)
  : Nucleus(other),
    half_life_(other.half_life_),
    photon_energies_(other.photon_energies_) {}

// Copy assignment operator
RadioactiveNucleus& RadioactiveNucleus::operator=(const RadioactiveNucleus& other) {
  if (this != &other) {
    Nucleus::operator=(other);
    half_life_ = other.half_life_;
    photon_energies_ = other.photon_energies_;
  }
  return *this;
}

// Move constructor
RadioactiveNucleus::RadioactiveNucleus(RadioactiveNucleus&& other) noexcept
  : Nucleus(std::move(other)),
    half_life_(other.half_life_),
    photon_energies_(std::move(other.photon_energies_)) {}

// Move assignment operator
RadioactiveNucleus& RadioactiveNucleus::operator=(RadioactiveNucleus&& other) noexcept {
  if (this != &other) {
    Nucleus::operator=(std::move(other));
    half_life_ = other.half_life_;
    photon_energies_ = std::move(other.photon_energies_);
  }
  return *this; // returns current object
}

// Prints radioactive nucleus data 
void RadioactiveNucleus::print_data() const {
  std::cout << "== Nucleus Data ==\n";
  std::cout << nucleus_type_
            << " (Z=" << atomic_number_
            << ", A=" << static_cast<int>(atomic_mass_)
            << ", Half-life=" << std::defaultfloat << half_life_ << " years)" << std::endl;
  std::cout << "Status: Radioactive Nucleus\n";
}
// Very imprtant function that simulates the decays of the radioactive nuceli as outlined in the brief into photons and beta+ particles
// Some decays have multiple pathways so the function loops through all pathways and simulates them.
void RadioactiveNucleus::decay() {
  if (decayed_) return;

  std::cout << "\n== Decaying " << nucleus_type_ << "... ==\n"; 

  int total_pathways = static_cast<int>(photon_energies_.size()) + (nucleus_type_ == "Na" ? 1 : 0); 
// loops through all pathways and simulates them
  for (size_t i = 0; i < photon_energies_.size(); ++i) {
    std::cout << "  Decay pathway " << (i + 1) << " of " << total_pathways << ":\n";

// creates, prints and records emitted photons
    auto photon = std::make_shared<Photon>(photon_energies_[i]);
    std::cout << "    Photon with energy: " << std::fixed << std::setprecision(3)
              << photon->get_energy() << " MeV\n";
    emitted_photons_.push_back(photon);
    total_photons++;

    // Simulates interactions of photons with matter as defined in photon class

    std::cout << "        --> Attempting pair production:\n";
    auto particles = pair_production(*photon);

    if (!particles.empty()) {
      std::cout << "            Pair production successful:\n";
      for (size_t i = 0; i < particles.size(); ++i) {
        std::string label = (i == 0) ? "Electron" : "Positron";
        if (i == 0) total_electrons++;
        else total_positrons++; 

        double total_energy = particles[i]->get_energy();
        std::cout << "                " << label << " with energy: " << std::fixed << std::setprecision(3) // 
                  << total_energy << " MeV\n";
        std::cout << "                Address: " << particles[i].get() << "\n";

        if (i == 0) {
          double kinetic = total_energy - 0.511; // calculates kinetic energy of the electron (max energy of radiated photon)
          if (kinetic > 0.01) {
            double emitted_energy = 0.5 * kinetic;
            auto radiation = std::make_shared<Photon>(emitted_energy);
            particles[i]->add_photon(radiation);

            auto emitted = radiate(*particles[i]);
            if (emitted) {
              std::cout << "                    --> Simulated radiation photon emitted: "
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
      std::cout << "           Error: Photon energy too low for pair production.\n";
    }

    std::cout << "\n        --> Attempting photoelectric effect:\n";
    double absorbed = photoelectric_effect(*photon);
    std::cout << "            Photoelectric absorbed energy: " << std::fixed << std::setprecision(3)
              << absorbed << " MeV\n";

    std::cout << "\n        --> Attempting Compton scattering:\n";
    double scattered = compton_scattering(*photon);
    std::cout << "            Photon energy after Compton scattering: " << std::fixed << std::setprecision(3)
              << scattered << " MeV\n\n";
  }

  if (nucleus_type_ == "Na") {
    std::cout << "  Decay pathway " << total_pathways << " of " << total_pathways << ":\n";
    std::cout << "    Positron emitted (beta-plus decay)\n";
    total_positrons++;

    Electron positron(0.511);  // simulate positron using electron class

    std::cout << "    Positron annihilates with electron --> Produces 2 photons of 0.511 MeV\n"; // prompt for electon-positron annihilation

    auto photon1 = std::make_shared<Photon>(0.511);
    auto photon2 = std::make_shared<Photon>(0.511);
    photon1->print_data();
    photon2->print_data();

    emitted_photons_.push_back(photon1);
    emitted_photons_.push_back(photon2);
    total_photons += 2;
    total_annihilation_photons += 2;

    std::cout << "      Interactions for annihilation photons:\n"; // Runs through all the photon interactions again for annialated photons
    for (const auto& p : {photon1, photon2}) {
      std::cout << "      Photon of energy: " << std::fixed << std::setprecision(3)
                << p->get_energy() << " MeV\n";

      std::cout << "\n        --> Attempting photoelectric effect:\n";
      std::cout << "           Photoelectric absorbed energy: " << std::fixed << std::setprecision(3)
                << photoelectric_effect(*p) << " MeV\n";

      std::cout << "\n        --> Attempting Compton scattering:\n";
      std::cout << "           Photon energy after Compton scattering: " << std::fixed << std::setprecision(3)
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
