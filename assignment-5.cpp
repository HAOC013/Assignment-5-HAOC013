// Filename: main.cpp
// Purpose: Test simulation of radioactive decay and interactions.
// Student ID: 
// Date: April 2025

#include "radioactivenucleus.h"
#include "stablenucleus.h"
#include "photon.h"
#include "electron.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<std::shared_ptr<Nucleus>> nuclei;

  nuclei.push_back(std::make_shared<RadioactiveNucleus>(137.0, 55, "Cs", 30.17, std::vector<double>{0.661}));
  nuclei.push_back(std::make_shared<RadioactiveNucleus>(22.0, 11, "Na", 2.6, std::vector<double>{1.2745}));
  nuclei.push_back(std::make_shared<RadioactiveNucleus>(60.0, 27, "Co", 5.27, std::vector<double>{1.173, 1.333}));
  nuclei.push_back(std::make_shared<StableNucleus>(56.0, 26, "Fe"));

  for (const auto& nucleus : nuclei) {
    std::cout << "\nProcessing " << nucleus->get_nucleus_type() << " nucleus:\n";
    nucleus->print_data();
    nucleus->decay();
  }

  std::cout << "\nTesting pair production with insufficient energy:\n";
  Photon test_photon(0.5);
  auto electrons = pair_production(test_photon);

  std::cout << "\nTesting valid pair production:\n";
  Photon high_photon(2.0);
  auto produced = pair_production(high_photon);
  if (!produced.empty()) {
    std::cout << "Two electrons created:\n";
    for (auto& e : produced) {
      e->print_data();

      // Demonstrate radiation
      e->add_photon(std::make_shared<Photon>(0.1));
      auto emitted = e->radiate();
      if (emitted) {
        std::cout << "  Electron radiated a photon:\n    ";
        emitted->print_data();
      }
    }
  }

  // Manually test single electron creation (was error before)
  std::cout << "\nCreating an individual test electron:\n";
  Electron electron(1.0);
  electron.print_data();

  return 0;
}
