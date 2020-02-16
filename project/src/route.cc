/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include "./stop.h"
#include "./route.h"
#include "/export/scratch/route.h"
#include "./passenger_generator.h"

struct RouteData RouteNow;


Route::Route(std::string name, Stop ** stops, double *
distances, int num_stops, PassengerGenerator * generator) {
  for (int i = 0; i < num_stops; i++) {
    stops_.push_back(stops[i]);
  }
  for (int i = 0; i < num_stops - 1; i++) {
    distances_between_.push_back(distances[i]);
  }

  generator->GeneratePassengers();
  name_ = name;
  num_stops_ = num_stops;
  destination_stop_index_ = 0;
  trip_time_ = 0.0;

  generator_ = generator;
}

// int Route::GetStopIndex() {
//   return destination_stop_index_;
// }

Route * Route::Clone() {
  Stop ** stops_c2 = new Stop *[num_stops_];
  double * distances_c2 = new double[(num_stops_ - 1)];
  int i = 0;
  int j = 0;

  for (std::list<Stop *>::iterator it = stops_.begin();
    it != stops_.end(); it++) {
      stops_c2[i] = *it;
      i++;
  }

  for (std::list<double>::iterator it = distances_between_.begin();
    it != distances_between_.end(); it++) {
    distances_c2[j] = *it;
    j++;
  }

  Route * route_c2 = new Route (name_, stops_c2, distances_c2,
    num_stops_, generator_);
  return route_c2;
// clone the route to generate the new route
}

void Route::Update() {
  generator_->GeneratePassengers();
  for (std::list<Stop *>::iterator it = stops_.begin();
  it != stops_.end(); it++) {
    (*it)->Update();
  }
  UpdateRouteData();
}

  bool Route::IsAtEnd() const {
    if (destination_stop_index_ == num_stops_-1) {
      return true;
    } else {
      return false;
    }
  }

  Stop* Route::GetDestinationStop() const {
    int i = 0;
    std::list<Stop *>::const_iterator it;
    for (it = stops_.begin(); i != destination_stop_index_; it++) {
      i++;
    }
    return *it;
  }  // Get pointer to next stop

  void Route::NextStop() {
    if (destination_stop_index_ < num_stops_ -1) {
      destination_stop_index_ = destination_stop_index_ + 1;
      int i = 0;
      std::list<Stop *>::iterator it;
      for (it = stops_.begin(); i != destination_stop_index_; it++) {
      i++;
    }
      destination_stop_ = *it;
    }
  }

  double Route::GetTotalRouteDistance() const {
    double total_distance = 0.0;
    for (std::list<double>::const_iterator it = distances_between_.begin();
    it != distances_between_.end(); it++ ) {
      total_distance = total_distance + *it;
    }
    return  total_distance;
  // iterate the dis list to get the total dis
  }

  double Route::GetNextStopDistance() const {
      if (destination_stop_index_ < num_stops_ -1) {
        std::list<double>::const_iterator it;
        it = std::next(distances_between_.begin(), destination_stop_index_ - 1);
        return *it;
      } else {
        return 0;
      }
    // using index to track the distance between 2 stops
  }

void Route::Report(std::ostream &out) {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Num stops: " << num_stops_ << std::endl;
  int stop_counter = 0;
  for (std::list<Stop *>::const_iterator it = stops_.begin();
  it != stops_.end(); it++) {
    (*it)->Report(out);
    stop_counter++;
  }
}

std::string Route::GetName() {
  return name_;
}

std::list<Stop *> Route::GetStops() {
  std::list<Stop *> temp_;
  // using index to get current stop
  int i = 0;
  for (std::list<Stop *>::iterator it = stops_.begin();
  it != stops_.end(); it++) {
      temp_.push_back(*it);
      i++;
  }
  return temp_;
}

void Route::UpdateRouteData() {
  RouteNow.id = name_;
// Create a vector that holds StopData structs.
  std::vector <StopData> temp_;
  for (std::list<Stop *>::iterator it = stops_.begin();
    it != stops_.end(); it++) {
    temp_.push_back((*it)->GetStopData());
  }
  RouteNow.stops = temp_;
}

RouteData Route::GetRouteData() {
  return RouteNow;
}

Stop* Route::GetPreStop() {
    int i = 0;
// using index to locate the previous stop
    if (destination_stop_index_ == 0) {
      return NULL;
    } else {
        std::list<Stop *>::const_iterator it;
        for (it = stops_.begin(); i != destination_stop_index_-1; it++) {
          i++;
        }
        return *it;
    }
}
