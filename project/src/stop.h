/**
 * @file stop.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef _EXPORT_SCRATCH_STOP_H_
#define _EXPORT_SCRATCH_STOP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <list>
#include <iostream>
#include "src/bus.h"
#include "src/passenger.h"
#include "src/data_structs.h"



class Bus;
// struct StopData StopNow;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of Stop.
 * Calls to \ref  to have a default stop
 */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of Stop.
 * Calls to \ref  to have a default stop
 */

class Stop {
 public:
   /**
   * @brief Constructs a passenger with a id and latitude and longitude
   *
   *
   * @param[in] int holding an id number.
   * @param[in] double holding a name as latitude.
   * @param[in] double holding a name as longitude.
   *
   */
  explicit Stop(int, double = 44.973723, double = -93.235365);
  // Adding passengers to the stop (from the generator)
  /**
  * @brief Get of Stop Id.
  *
  * GetId funtion will get id of the stop.
  *
  * @return Int as number of stop id.
  */  // struct StopData StopNow;
  int GetId() const;
  /**
  * @brief Add a passenger to the stop.
  *
  * @param[in] Pointer holding an passenger object.
  *
  * AddPassengers funtion will add a passenger to the stop.
  *
  * @return an INT to indicate add passenger successfull.
  */
  int AddPassengers(Passenger *);
  /**
  * @brief Generation of new status of the Stop.
  *
  * Update funtion will be update the status of the Stop.
  *
  * @return NULL just update the status of the Stop.
  */
  void Update();
  /**
  * @brief GENGERATE the status of the stop.
  *
  * Report funtion will GENGERATE current status of the stop.
  *
  * @return NULL but will have output to express the status.
  */
  void Report(std::ostream &out) const;
  /**
  * @brief Load passenger from stop to bus.
  *
  * LoadPassenger Load passenger from stop to bus.
  *
  * @param[in] Bus pointer holding an bus object.
  *
  * @return NULL but will have output to express the status.
  */
  int LoadPassengers(Bus * bus);
  /**
  * @brief StopData get stop status.
  *
  * StopData get stop status.
  *
  * @return DataStructure hold stop data information.
  */
  StopData GetStopData();
  /**
  * @brief UPdate stop status.
  *
  * GetStopsUpdate update stop status.
  *
  * @return NULL the data sturct will get update.
  */
  void GetStopsUpdate();
  /**
  * @brief Get size of passenger in the stop.
  *
  * PassengerSize check passenger size.
  *
  * @return int number indicate the number of passenger.
  */
  int PassengerSize();

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // _EXPORT_SCRATCH_STOP_H_
