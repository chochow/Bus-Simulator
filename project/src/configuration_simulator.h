/**
 * @file configuration_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef _EXPORT_SCRATCH_CONFIGURATION_SIMULATOR_H_
#define _EXPORT_SCRATCH_CONFIGURATION_SIMULATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>
#include <string>
#include "src/simulator.h"
#include "src/config_manager.h"


class Route;
class Bus;
class Stop;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief The main class for configurationSimulator.
 * Calls to \ref  to have a configuration simulator.
 */

class ConfigurationSimulator {
 public:
  /**
   * @brief Constructs a configuration simualtor with a config manager pointer.
   *
   * @param[in] pointer pointe to ConfigManager.
   *
   */
  explicit ConfigurationSimulator(ConfigManager*);
  /**
   * @brief Destructs a configuration simualtor.
   *
   */
  ~ConfigurationSimulator();
  /**
  * @brief initialize the configuration simulator.
  *
  * Start funtion will set up for configuration simulator.
  *
  * @return NULL and the set up is finished
  */
  void Start();
  /**
  * @brief update the status of configuration simulator.
  *
  * update funtion will refresh the status of configuration simulator.
  *
  * @return NULL and the state of configuration simulator will be updated.
  */
  void Update();
  /**
  * @brief commandlinechecker check the command line is legal.
  * 
  * @param[in] int the number of user input.
  * @param[in] pinter char pointer hold user input string.
  * 
  * 
  * Commandlinechecker funtion will check the user input.
  *
  * @return boolean to indicate show whether the command is legal.
  */
  bool Commandlinechecker(int, char**);
  /**
  * @brief print the helpmessage for error message
  *
  * HelpMessage tell the user the right input formate.
  *
  * @return NULL but print the right input format.
  */
  void HelpMessage();
  /**
  * @brief check the length of round time in command line.
  * 
  * @param[in] pinter char pointer hold user input string.
  * 
  * checktime check the length of round time in command line.
  *
  * @return string hold the time of simulator.
  */
  std::string Checktime(char**);
  /**
  * @brief check readfile name in command line.
  * 
  * @param[in] pinter char pointer hold user input string.
  * 
  * checkfilename check readfile name in command line.
  *
  * @return string hold the readfile name.
  */
  std::string Checkfilename(char**);
  /**
  * @brief check checkoutputfile name in command line.
  * 
  * @param[in] pinter char pointer hold user input string.
  * 
  * checktiem check outputfile name in command line.
  *
  * @return string hold the outputfile name.
  */
  std::string Checkoutputfile(char**);

 private:
  ConfigManager* configManager_;
  std::vector<int> busStartTimings_;
  std::vector<int> timeSinceLastBus_;
  int simulationTimeElapsed_;

  std::vector<Route *> prototypeRoutes_;
  std::vector<Bus *> busses_;

  int busId = 1000;
};

#endif  // _EXPORT_SCRATCH_CONFIGURATION_SIMULATOR_H_
