/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef  _EXPORT_SCRATCH_BUS_H_
#define  _EXPORT_SCRATCH_BUS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include "src/passenger.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/data_structs.h"


class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of Bus.
 * Calls to \ref  to have a default bus.
 */

class Bus {
 public:
   /**
   * @brief Constructs a bus with a standard name and out route, in route,
   * the mxa capacity for the bus and the speed num
   *
   * @param[in] string holding a name of a created Bus.
   * @param[in] Route pointer holding an outbound route.
   * @param[in]  Route pointer holding an inbound route.
   *
   */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                  double speed = 1);

 /**
  * @brief check Bus can have new passanger loaded.
  *
  * LoadPassenger funtion will check Bus can have new passanger loaded.
  *
  * @return boolean to indicate whether  Bus can have new passanger loaded.
  */
  bool LoadPassenger(Passenger *);  // returning revenue delta
  /**
  * @brief Move the bus.
  *
  * GetOnBus funtion will make the bus move .
  *
  * @return boolean to indicate bus move or not.
  */
  void Move();
  /**
  * @brief Generation of new status of the bus.
  *
  * Update funtion will be update the status of the bus.
  *
  * @return NULL just update the status of the bus.
  */
  void Update();
  /**
  * @brief GENGERATE the status of the bus.
  *
  * Report funtion will GENGERATE current status of the bus.
  *
  * @return NULL but will have output to express the bus status.
  */
  void Report(std::ostream &out);
  /**
  * @brief Check the bus trip is finish or not.
  *
  * IsTripComplete funtion will  Check the bus trip is finish or not.
  *
  * @return boolean to indicate the trip is over or not=.
  */
  bool IsTripComplete();
  /**
  * @brief UpdateBusDate will update the bus status.
  *
  * UpdateBusData funtion will check the bus's passenger and position.
  *
  * @return NULL but the status of bus will change.
  */
  void UpdateBusData();
  /**
  * @brief UnLoadPassenger will unload bus passenger.
  *
  * UnLoadPassenger funtion will unload passenger arrived the destination.
  *
  * @return bool to indicate the wheter the bus should unload the passenger.
  */
  bool UnLoadPassenger();
  /**
  * @brief GetBusData will return busdata.
  *
  * GetBusData funtion will send busdata to visual.
  *
  * @return busdata struct to vis_sim.
  */
  BusData GetBusData();
  /**
  * @brief GetNextStop will next stop pointer.
  *
  * GetNextStop will pointe to nextstop pointer.
  *
  * @return a pointer point to next stop.
  */
  Stop * GetNextStop();
  /**
  * @brief GetNumPassengers will indicate the passenger number.
  *
  * GetNumPassengers will count the number of passenger.
  *
  * @return the number of passenger in the bus.
  */
  size_t GetNumPassengers();
  /**
  * @brief  GetCapacity will indicate the capacity of the bus.
  *
  * GetCapacity will check the capacity of the bus.
  *
  * @return the capacity of the bus.
  */
  int GetCapacity();

 private:
  BusData BusNow;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
};
#endif  // _EXPORT_SCRATCH_BUS_H_
