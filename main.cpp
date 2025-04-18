// Filename: main.cpp
// Purpose: Full simulation of radioactive decay and interactions (final version).
// Student ID: 
// Date: April 2025

#include "radioactivenucleus.h"
#include "stablenucleus.h"
#include "photon.h"
#include "electron.h"
#include <iostream>
#include <memory>
#include <vector>
void simulate_photon_interaction(const std::shared_ptr<Photon>& photon) {
  // Photoelectric effect
  std::cout << "  --> Photoelectric effect:\n";
  double absorbed_energy = photoelectric_effect(*photon);
  std::cout << "      Energy absorbed: " << absorbed_energy << " MeV\n";

  // Compton scattering
  std::cout << "  --> Compton scattering:\n";
  double scattered_energy = compton_scattering(*photon);
  std::cout << "      Scattered photon energy: " << scattered_energy << " MeV\n";

  // Pair production
  std::cout << "  --> Attempting pair production:\n";
  auto electrons = pair_production(*photon);
  if (!electrons.empty()) {
    std::cout << "      Pair production successful. Electrons created:\n";
    for (auto& e : electrons) {
      std::cout << "        ";
      e->print_data();
      std::cout << "        Address: " << e.get() << "\n";

      // Give electron an unrelated photon to radiate
      auto extra_photon = std::make_shared<Photon>(0.1);
      e->add_photon(extra_photon);

      auto emitted = radiate(*e);
      if (emitted) {
        std::cout << "        Radiated photon with energy: " << emitted->get_energy() << " MeV\n";
        std::cout << "        Photon address: " << emitted.get() << "\n";
      }
    }
  }
}


int main() {
  std::cout << "\n===== Assignment 5: Radioactive Decay & Interactions =====\n";
  std::cout << "Press Enter to start...";
  std::cin.get();

  std::vector<std::shared_ptr<Nucleus>> nuclei;

  nuclei.push_back(std::make_shared<RadioactiveNucleus>(
    137.0, 55, "Cs", 30.17, std::vector<double>{0.661}));
  nuclei.push_back(std::make_shared<RadioactiveNucleus>(
    22.0, 11, "Na", 2.6, std::vector<double>{1.2745}));
  nuclei.push_back(std::make_shared<RadioactiveNucleus>(
    60.0, 27, "Co", 5.27, std::vector<double>{1.173, 1.333}));
  nuclei.push_back(std::make_shared<StableNucleus>(
    56.0, 26, "Fe"));

  for (const auto& nucleus : nuclei) {
    std::cout << "\n=== Simulating " << nucleus->get_nucleus_type() << " ===\n";
    nucleus->print_data();
    nucleus->decay();  // decay now handles all pathway and interaction output
  }

  std::cout << "\n=== Manual Electron Test ===\n";
  Electron test_electron(1.0);
  test_electron.print_data();
  test_electron.add_photon(std::make_shared<Photon>(0.25));

  auto test_radiation = radiate(test_electron);
  if (test_radiation) {
    std::cout << "  Electron radiated photon with energy: " << test_radiation->get_energy() << " MeV\n";
  }

  std::cout << "\n=== End of Assignment 5 Program ===\n";
  return 0;
}
