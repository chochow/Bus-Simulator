/**
 * @file configuration_sim.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <string>
#include <fstream>
#include "src/config_manager.h"
#include "src/configuration_simulator.h"

int main(int argc, char**argv) {
  // NOTE: this usage will change depending on
  //       how you build your config_sim classes
  //   E.g., how will you handle getting the length of simulation value?
  int rounds;
  std::string rounds_;
  std::string configfile_;
  std::string outputfile_;
  std::ofstream outfile;

  // Check command line params for config file name
  if (argc < 2) {
    std::cout << "Usage: ./build/bin/configuration_sim"\
    "<config_filename> <length_of_simulator> <output_filename>";
    std::cout << std::endl;
    exit(0);
  }

  ConfigManager* cm = new ConfigManager();

  ConfigurationSimulator my_sim(cm);

  switch (argc) {
    case 2 :
            configfile_ = my_sim.Checkfilename(argv);
            rounds_ = "50";
            break;

    case 3 :
            configfile_ = my_sim.Checkfilename(argv);
            rounds_ = my_sim.Checktime(argv);
            break;

    default:
            configfile_ = my_sim.Checkfilename(argv);
            rounds_ = my_sim.Checktime(argv);
            outputfile_ = my_sim.Checkoutputfile(argv);
            break;
  }


  rounds = std::stoi(rounds_);
  cm->ReadConfig(configfile_);


  if (argc > 3) {
      outfile.open(outputfile_);
      auto cout_buf = std::cout.rdbuf(outfile.rdbuf());
  }

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "         STARTING" << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "*************************/" << std::endl;


  my_sim.Start();  //   Call Start on ConfigurationSimulator

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "           BEGIN" << std::endl;
  std::cout << "          UPDATING" << std::endl;
  std::cout << "*************************/" << std::endl;

  //  Start for loop, length of simulation (set by ourself)

  for (int i = 0; i < rounds; i++) {
    my_sim.Update();  // Call Update on ConfigurationSimulator
  }

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "         COMPLETE" << std::endl;
  std::cout << "*************************/" << std::endl;

  if (argc > 3) {
      outfile.close();
  }
  return 0;
}
