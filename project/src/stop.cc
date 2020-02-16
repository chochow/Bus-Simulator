/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>

#include "./stop.h"
#include "/export/scratch/stop.h"

struct StopData StopNow;
struct Position PositionNow;

Stop::Stop(int id, double longitude, double latitude):
id_(id), longitude_(longitude), latitude_(latitude) {
  // Defaults to Westbound Coffman Union stop
  // no initialization of list of passengers necessary
}

int Stop::AddPassengers(Passenger * pass) {
  passengers_.push_back(pass);
  return 1;
}

int Stop::PassengerSize() {
  return passengers_.size();
  // return num shows the size of passengers.
}

int Stop::LoadPassengers(Bus * bus) {
    int numPload = 0;
    for (std::list<Passenger *>::iterator it = passengers_.begin();
        it != passengers_.end();) {
            if (bus->LoadPassenger(*it) != true) {
              it++;
            } else {
              it = passengers_.erase(it);
              numPload += 1;
            }
    }
    return numPload;
    // Load passenger from stop to bus
}


void Stop::Update() {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Update();
  }
  // GetStopsUpdate();
}

int Stop::GetId() const {
  return id_;
}

void Stop::Report(std::ostream &out) const {
  std::cout << "ID: " << id_ << std::endl;
  std::cout << "Passengers waiting: " << passengers_.size() << std::endl;
  for (std::list<Passenger *>::const_iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}

StopData Stop::GetStopData() {
  GetStopsUpdate();
  return StopNow;
}

void Stop::GetStopsUpdate() {
  StopNow.id = std::to_string(id_);
  PositionNow.x = longitude_;
  PositionNow.y = latitude_;
  StopNow.position = PositionNow;
  StopNow.num_people = passengers_.size();
}
