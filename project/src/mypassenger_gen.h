/**
 * @file random_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef _EXPORT_SCRATCH_MYPASSENGER_GEN_H_
#define _EXPORT_SCRATCH_MYPASSENGER_GEN_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <ctime>
#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief The sub class for the generation of passenger.
 * Calls to \ref  to have a default mypassenger generator.
 */

class MyPassengerGen : public PassengerGenerator{
 public:
 /**
   * @brief Constructs a passenger generation.
   *
   * @param[in] std::list hold the probs of generating passenger.
   * @param[in] std::list hold the stop pointer.
   *
   */
  MyPassengerGen(std::list<double>, std::list<Stop *>);

  /**
  * @brief gengerate the passenger.
  *
  * GeneratePassengers funtion will generate the passenger.
  *
  * @return the number of passenger has been generated.
  */
  int GeneratePassengers() override;
};

#endif  // _EXPORT_SCRATCH_MYPASSENGER_GEN_H_
