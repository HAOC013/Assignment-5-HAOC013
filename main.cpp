// Filename: main.cpp
// Purpose: Simulate nuclear decays and photon interactions clearly
// Student ID: 
// Date: April 2025

#include "StableNucleus.h"
#include "RadioactiveNucleus.h"
#include "Interactions.h"
#include "Electron.h"

#include <vector>
#include <memory>
#include <cmath>
#include <iostream>

int main()
{
  std::cout << "=== Initialising Nuclei ===\n";

  // Nuclei using polymorphism
  std::vector<std::shared_ptr<Nucleus>> nuclei;

  auto Na = std::make_shared<RadioactiveNucleus>(22.99, 11, "Na", 15.0, std::vector<double>{1274.5});
  auto Co = std::make_shared<RadioactiveNucleus>(55.0, 27, "Co", 77.0, std::vector<double>{1173.0, 1333.0});
  auto Cs = std::make_shared<RadioactiveNucleus>(137.0, 55, "Cs", 30.0, std::vector<double>{661.0}); // Correct energy
  auto Fe = std::make_shared<StableNucleus>(56.0, 26, "Fe");

  nuclei.push_back(Na);
  nuclei.push_back(Co);
  nuclei.push_back(Cs);
  nuclei.push_back(Fe);

  std::cout << "\n=== Decay Process ===\n";

  for (const auto& nucleus : nuclei) {
    nucleus->print_data();
    nucleus->decay();
    std::cout << "\n";
  }

  std::cout << "=== Photon Interactions ===\n";

  // Collect all photons from all radioactive decays
  std::vector<std::shared_ptr<Photon>> all_photons;

  for (const auto& nucleus : nuclei) {
    auto rad = std::dynamic_pointer_cast<RadioactiveNucleus>(nucleus);
    if (rad) {
      for (const auto& p : rad->emitted_photons_) {
        all_photons.push_back(p);
      }
    }
  }

  // 1. Photon from Cs -> photoelectric effect
  std::cout << "\n-> Photoelectric Effect on Cs photon:\n";
  double absorbed_energy = photoelectric_effect(*all_photons[2]);
  std::cout << "Energy absorbed by matter: " << absorbed_energy << " keV\n";

  // 2. Photon from Co -> Compton scatter
  std::cout << "\n-> Compton Scatter on Co photon:\n";
  compton_scatter(*all_photons[0], M_PI / 4);
  all_photons[0]->print_data();

  // 3. Photon from Na -> Pair production (valid)
  std::cout << "\n-> Pair Production on Na photon:\n";
  auto pair = pair_production(*all_photons[1]);
  if (!pair.empty()) {
    std::cout << "Pair produced: \n";
    for (const auto& e : pair) {
      e->print_data();
    }

    // Have one electron radiate an unrelated photon
    std::cout << "\n-> Radiation from produced electron:\n";
    auto emitted_photon = std::make_shared<Photon>(100.0);
    pair[0]->add_photon(emitted_photon);

    auto output = pair[0]->radiate();
    if (output) output->print_data();
  }

  // 4. Low energy photon -> failed pair production
  std::cout << "\n-> Attempt pair production with low energy photon:\n";
  auto low_energy_photon = std::make_shared<Photon>(0.5);
  pair_production(*low_energy_photon);

  std::cout << "\n=== Positron Emission (Na decay challenge) ===\n";
  std::cout << "Na decay emits positron (e+) which will annihilate with an electron, producing two 511 keV photons.\n";
  std::cout << "Creating two annihilation photons:\n";
  auto ann1 = std::make_shared<Photon>(511.0);
  auto ann2 = std::make_shared<Photon>(511.0);
  ann1->print_data();
  ann2->print_data();

  std::cout << "\n=== Simulation Complete ===\n";

  return 0;
}
