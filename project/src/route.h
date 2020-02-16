/**
 * @file route.h
 *
 * @Copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef _EXPORT_SCRATCH_ROUTE_H_
#define _EXPORT_SCRATCH_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>
#include <string>
#include "./passenger_generator.h"
#include "./stop.h"
#include "src/data_structs.h"

class PassengerGenerator;

class Stop;


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of routes.
 * Calls to \ref  to have a default Route
 */
class Route {
 public:
   /**
   * @brief Constructs a passenger with a standard name and several stops, distances list,
   * number for stops and passanger generator calss.
   *
   *
   * @param[in] sting holding an an name of created
   * @param[in] Stop pointer holding a list of stops in this route.
   * @param[in] double pointer holding a list of double number as distance between different stops.
   * @param[in] int holding a number for checking how many stops route owns.
   * @param[in] PassengerGenerator pointer holding a class for GENGERATE passengers.
   *
   */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);


  /**
  * @brief copy a new Route from the current Route.
  *
  * Clone funtion will copy current and set up a same route.
  *
  * @return Pointer holding the new route copied from the current stop.
  */
  Route * Clone();
  /**
  * @brief Generation of new status of the route.
  *
  * Update funtion will be update the status of the route.
  *
  * @return NULL just update the status of the route.
  */
  void Update();
  /**
  * @brief GENGERATE the status of the route.
  *
  * Report funtion will GENGERATE current status of the route.
  *
  * @return NULL but will have output to express the status.
  */
  void Report(std::ostream&);
  /**
  * @brief Check whether the route reached the End.
  *
  * IsAtEnd funtion will check the current route has reached end or not.
  *
  * @return boolean to indicate whether the route at end or not.
  */
  bool IsAtEnd() const;
  /**
  * @brief Check the next stop on the route.
  *
  * NextStop funtion will check the next stop for the route.
  *
  * @return NULL but change the pointer to pointe rto next stop.
  */
  void NextStop();  // Change destination_stop_ to next stop
  /**
  * @brief Check the total distance for the route .
  *
  * GetTotalRouteDistance funtion will Calculate the total distance for the route.
  *
  * @return double to indicate how long is the route.
  */
  double GetTotalRouteDistance() const;
  /**
  * @brief Check the distance from current stop to the next stop.
  *
  * GetNextStopDistance funtion will check the distance from current stop to the next stop.
  *
  * @return double to indicate how long is the route.
  */
  double GetNextStopDistance() const;
  /**
  * @brief Check the next stop.
  *
  * GetDestinationStop funtion will check which is next stop.
  *
  * @return Stop pointer to pointe to the next stop.
  */
  Stop * GetDestinationStop() const;    // Get pointer to next stop
  /**
  * @brief Get Route name.
  *
  * GetName funtion will check the name of route.
  *
  * @return string to show the name of route.
  */
  std::string GetName();
  /**
  * @brief Get list of stops.
  *
  * Getstops will have a list of stop pointers.
  *
  * @return list hold some stop pointers.
  */
  std::list<Stop *> GetStops();
  /**
  * @brief Update the route data.
  *
  * Update the status of the route.
  *
  * @return NUll but route will be updated.
  */
  void UpdateRouteData();
  /**
  * @brief Get route date from data structure.
  *
  * GetRouteData Update the status of the route.
  *
  * @return data structure hold data of the route.
  */
  RouteData GetRouteData();
 /**
  * @brief Get previous top.
  *
  * GetPreStop will check the previous stop on the route.
  *
  * @return previous stop poniter.
  */
  Stop* GetPreStop();

 private:
  int GenerateNewPassengers();       // generates passengers on its route
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  double trip_time_;  // derived data - total distance travelled on route
};
#endif  // _EXPORT_SCRATCH_ROUTE_H_
