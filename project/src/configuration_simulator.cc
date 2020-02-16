/**
 * @file configuration_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <string>
#include <fstream>
#include <iostream>
#include "src/bus.h"
#include "src/route.h"
#include "src/configuration_simulator.h"
#include "/export/scratch/configuration_simulator.h"

ConfigurationSimulator::ConfigurationSimulator(ConfigManager* configM) {
    configManager_ = configM;
}

ConfigurationSimulator::~ConfigurationSimulator() {
}

void ConfigurationSimulator::HelpMessage() {
    std::cout
    << "Usage: ./build/bin/configuration_sim"\
    "<config_filename> <length_of_simulation>"
    << std::endl;
}
// Help msg when user input is wrong, print for the right input

std::string ConfigurationSimulator::Checkfilename(char** argv) {
  std::string defaultname = "config.txt";
  std::string readfile = argv[1];
  std::ifstream infile;
  infile.open("../config/" + readfile);
  if (infile.is_open()) {
      defaultname = readfile;
    } else {
      std::cerr << "Invalid file, using defaultfile" << std::endl;
    }
    return defaultname;
}
// check filename is ok or not if not using the default one

std::string ConfigurationSimulator::Checktime(char** argv) {
  std::string  defaulttime = "50";
  if (atoi(argv[2]) == 0) {
      std::cerr<< "length_of_simulation must"\
       " be an intger great than 0"<< std::endl;
  } else {
    defaulttime.assign(argv[2]);
  }
  return defaulttime;
}
// check the time for simulator, if input is not illeage use deafult one


std::string ConfigurationSimulator::Checkoutputfile(char** argv) {
  // if len(agrv[4]) > 4
  std::string defaultoutfile = "output.txt";
  std::string outputfile = argv[3];
  std::ofstream outfile;
  outfile.open(outputfile);
  if (outfile.is_open() == 0) {
    outfile.close();
    defaultoutfile = outputfile;
  } else {
    std::cerr << "Invalid open file, using defaultfile" << std::endl;
  }
  return defaultoutfile;
}
// check the outfile, if input is not illeage use deafult one


void ConfigurationSimulator::Start() {
  timeSinceLastBus_.resize(busStartTimings_.size());
  for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
  }
    prototypeRoutes_ = configManager_->GetRoutes();
    simulationTimeElapsed_ = 0;  // init, but also allows restart

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);
        prototypeRoutes_[i]->UpdateRouteData();
    }
}

void ConfigurationSimulator::Update() {
  simulationTimeElapsed_++;

    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;

    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {
            Route * outbound = prototypeRoutes_[2* i];
            Route * inbound = prototypeRoutes_[2* i + 1];

            busses_.push_back(new Bus(std::to_string(busId),
            outbound->Clone(), inbound->Clone(), 60, 1));
            busId++;

            busses_[busses_.size() - 1]->UpdateBusData();

            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }

    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;

    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();

        if (busses_[i]->IsTripComplete()) {
            busses_.erase(busses_.begin() + i);
            continue;
        }

        // busses_[i]->UpdateBusData();

        busses_[i]->Report(std::cout);
    }

    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        // prototypeRoutes_[i]->UpdateRouteData();

        prototypeRoutes_[i]->Report(std::cout);
    }
}
