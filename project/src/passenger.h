
/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef _EXPORT_SCRATCH_PASSENGER_H_
#define _EXPORT_SCRATCH_PASSENGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of passengers.
 * Calls to \ref  to have a default passenger
 */

class Passenger {
 public:
  /**
  * @brief Constructs a passenger with a standard name and id.
  *
  *
  * @param[in] int holding an id number
  * @param[in] string holding a name of a created passenger.
  *
  */
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
  * @brief Generation of new status of the passenger.
  *
  * Update funtion will be update the status of the passenger.
  *
  * @return NULL just update the status of the passanger.
  */
  void Update();
  /**
  * @brief Generation of new status of the passenger.
  *
  * GetOnBus funtion will be change the status of the passenger.
  *
  * @return NULL change passenger status from waitto on Bus.
  */
  void GetOnBus();
  /**
  * @brief Calculate the passeneger total wait time.
  *
  * GetTotalWait funtion will Calculate the passenger's wait time.
  *
  * @return Int is the total time stamp passenger wait.
  */
  int GetTotalWait() const;
  /**
  * @brief check passanger is on Bus or not.
  *
  * IsOnBus funtion will check whether the passenger is on bus.
  *
  * @return boolean to determinder whether passenger is on bus.
  */
  bool IsOnBus() const;
  /**
  * @brief Check passenger's destination stop.
  *
  * GetDestination funtion will get passenger's stop Id.
  *
  * @return Int as passenger's destination stop id.
  */
  int GetDestination() const;
  /**
  * @brief GENGERATE the status of the passanger.
  *
  * Report funtion will GENGERATE current status of the passenger.
  *
  * @return NULL but will have output to express the status.
  */
  void Report(std::ostream &out) const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;   // global count, used to set ID for new instances
};
#endif  // _EXPORT_SCRATCH_PASSENGER_H_
