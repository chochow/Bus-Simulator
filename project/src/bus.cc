/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/bus.h"
#include "/export/scratch/bus.h"

// struct RouteData RouteIN;
// struct RouteData RouteOut;
// struct RouteData RouteNow_1;
// struct StopData StopNow;
// struct StopData StopPrevious;
// can solved by the index one

Bus::Bus(std::string name, Route * out, Route * in, int capacity,
  double speed) {
  name_ = name;
  outgoing_route_ = out;
  incoming_route_ = in;
  passenger_max_capacity_ = capacity;
  speed_ = speed;
  distance_remaining_ = 0;
}


bool Bus::LoadPassenger(Passenger * new_passenger) {
  // loading passenger onto a bus
  if ((unsigned)passenger_max_capacity_ > passengers_.size()) {
    passengers_.push_back(new_passenger);
    new_passenger->GetOnBus();
    return true;
  }
  return false;
}


bool Bus::UnLoadPassenger() {
  Route  * current_route_ = NULL;
  if (outgoing_route_->IsAtEnd()) {
    current_route_ = incoming_route_;
  } else {
    current_route_ = outgoing_route_;
  }
  // test where which route need to handle
  Stop * stop_arrived_at = current_route_->GetDestinationStop();
    for (std::list<Passenger *>::iterator it = passengers_.begin();
        it != passengers_.end();) {
            if ((*it)->GetDestination() == stop_arrived_at->GetId()) {
             return true;
             break;
             // break and used for update function to see where to skip stop
            } else {
              ++it;
            }
        }
    return false;
}

void Bus::Move() {
  distance_remaining_ =  distance_remaining_ - speed_;
  // change the bool to void
  // cuz i want to put all function inside of update
}

// bool Refuel() {
//  // This may become more complex in the future
//  fuel_ = max_fuel_;
// }


bool Bus::IsTripComplete() {
  return outgoing_route_->IsAtEnd() && incoming_route_->IsAtEnd();
}


void Bus::Update() {
  Route  * current_route_ = NULL;
  if (outgoing_route_->IsAtEnd()) {
    current_route_ = incoming_route_;
  } else {
    current_route_ = outgoing_route_;
  }
  // change stop vecctor
  int i = 0;

  while (true) {
      if (distance_remaining_ == 0) {
        // using dis_remain = 0 to as a flag
        Stop * stop_arrived_at =  current_route_->GetDestinationStop();
        if (UnLoadPassenger()) {
          for (std::list<Passenger *>::iterator it = passengers_.begin();
          it != passengers_.end();) {
                if ((*it)->GetDestination() == stop_arrived_at->GetId()) {
                  it = passengers_.erase(it);
                } else {
                  ++it;
                }
            }
            distance_remaining_ = 0;
            UpdateBusData();
            stop_arrived_at->LoadPassengers(this);
            current_route_->NextStop();
            distance_remaining_ =  current_route_->GetNextStopDistance();
            break;
            // load passenger consume time step
        } else {
          if (stop_arrived_at->PassengerSize () != 0
              &&(passenger_max_capacity_ - passengers_.size() )> 0) {
            stop_arrived_at->LoadPassengers(this);
            distance_remaining_ = 0;
            UpdateBusData();
            current_route_->NextStop();
            distance_remaining_ =  current_route_->GetNextStopDistance();
            break;
            // get on bus consuem time
          } else {
            UpdateBusData();
            current_route_->NextStop();
            distance_remaining_ =  current_route_->GetNextStopDistance();
            break;
            // if it does not consume time then move
          }
        }
      } else {
        Stop * stop_arrived_at =  current_route_->GetDestinationStop();
        if (distance_remaining_ > 0) {
          UpdateBusData();
          Move();
          // stop in mid of the current stop and next stop, continue move
          break;
        } else {
          Stop * stop_arrived_at =  current_route_->GetDestinationStop();
          if (UnLoadPassenger()) {
            for (std::list<Passenger *>::iterator it = passengers_.begin();
            it != passengers_.end();) {
                  if ((*it)->GetDestination() == stop_arrived_at->GetId()) {
                    it = passengers_.erase(it);
                  } else {
                    ++it;
                  }
              }
              stop_arrived_at->LoadPassengers(this);
              distance_remaining_ = 0;
              UpdateBusData();
              current_route_->NextStop();
              distance_remaining_ =  current_route_->GetNextStopDistance();
              break;
              // here stop cuz need to unload people,
              // load people and consume time
          } else {
            if (stop_arrived_at->PassengerSize() != 0
            &&(passenger_max_capacity_ - passengers_.size()) > 0) {
              // pass but a stop and stop has people, bus has seats
              stop_arrived_at->LoadPassengers(this);
              distance_remaining_ = 0;
              UpdateBusData();
              current_route_->NextStop();
              distance_remaining_ =  current_route_->GetNextStopDistance();
              break;
              // here stop cuz need to pick up passenger, then consume time
            } else {
              if (current_route_->IsAtEnd()) {
                // std::cout << "how many stop i skipped"
                // << i << "and i'm at the end now"<< std::endl;
                distance_remaining_ = 0;
                UpdateBusData();
                break;
                // read the end of route
              }
              // loop begin to track the where
              // the bus need to stop
              current_route_->NextStop();
              distance_remaining_ =  current_route_->GetNextStopDistance()
                                     + distance_remaining_;
              i++;
            }
          }
        }
      }
  }
  // loop the passenger to update their onbus time
  for (std::list<Passenger *>::iterator it = passengers_.begin();
    it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

void Bus::Report(std::ostream &out) {
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}

void Bus::UpdateBusData() {
    BusNow.id = name_;
    float avgL1, avgL2;
    struct Position PositionTemp;
    if (distance_remaining_ == 0) {
       Stop* stopnow_;
       if (outgoing_route_->IsAtEnd()) {
         stopnow_ = incoming_route_->GetDestinationStop();
       } else {
         stopnow_ = outgoing_route_->GetDestinationStop();
       }
        avgL1 = (stopnow_->GetStopData()).position.x;
        avgL2 = (stopnow_->GetStopData()).position.y;
    } else {
      if (outgoing_route_->IsAtEnd()) {
      Stop* stopnow = incoming_route_->GetDestinationStop();
      Stop* stoppre = incoming_route_->GetPreStop();
      if (stopnow == NULL || stoppre == NULL) {
        avgL1 = 0.0;
        avgL2 = 0.0;
      } else {
        avgL1 = ((stopnow->GetStopData()).position.x +
         (stoppre->GetStopData()).position.x)/2;
        avgL2 = ((stopnow->GetStopData()).position.y +
         (stoppre->GetStopData()).position.y)/2;
      }
      PositionTemp.x = avgL1;
      PositionTemp.y = avgL2;
    } else {
      Stop* stopnow = outgoing_route_->GetDestinationStop();
      Stop* stoppre = outgoing_route_->GetPreStop();
      if (stopnow == NULL || stoppre == NULL) {
        avgL1 = 0.0;
        avgL2 = 0.0;
      } else {
        avgL1 = ((stopnow->GetStopData()).position.x +
         (stoppre->GetStopData()).position.x)/2;
        avgL2 = ((stopnow->GetStopData()).position.y +
         (stoppre->GetStopData()).position.y)/2;
      }
    }
  }
    PositionTemp.x = avgL1;
    PositionTemp.y = avgL2;

    BusNow.position = PositionTemp;
    BusNow.num_passengers = passengers_.size();
    BusNow.capacity = passenger_max_capacity_;

    // need to fix in the future
  }

BusData Bus::GetBusData() {
    return BusNow;
  }

  Stop * Bus::GetNextStop() {
    if (outgoing_route_->IsAtEnd()) {
       incoming_route_->NextStop();
       return incoming_route_->GetDestinationStop();

     } else {
       outgoing_route_->NextStop();
       return outgoing_route_->GetDestinationStop();
     }
  }


  size_t Bus::GetNumPassengers() {
    return passengers_.size();
  }

  int Bus::GetCapacity() {
    return passenger_max_capacity_;
  }
