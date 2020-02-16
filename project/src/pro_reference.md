Programming Reference  {#proreference}
===========

All codes in the project:

If you want to see the classes at an alphabetical order,
[**go to Class Index**](classes.html).

Otherwise below is a summary of major classes.


##Inside the SRC

###Bus
Bus class try to have more eneties that a real bus has, such as name, speed,
Passengers, routes leading it. It need to move and connect all the other
classes in this project.Modification of this class should be done in bus.h and
bus.cc. The critical method to watch out for is Update(),
which handles loading and unloading passenger, detecting it reach stop,
switching in and out route, making the bus move and even skip stops.
Developer can extend the functionality with adding some function within this class.
For instance: add fuel attribute inside of the bus, add function to manipulate the attribute.


###Passenger
Passenger class has names, and destination, etc, which try to imitate the real world passenger as real as possible.

###Route
Route class contains different stops objects, which makes bus's route.
Bus and Stop's realtioship is aggeragation.

###Stop
Stop is class that form the route class. It uses longtitude and lantitude
to have a real world location, id to identify and
passenger can show up in that class and waiting bus. Having LoadPassengers
Function can help to load passenger on bus, just like a real world senario,
which wll use Bus object as varabile, and return number of passengeer.

###ConfigManager
Class here is the class that reads the config_txt, and uses the txt to genreater stops and the routes.

###ConfigurationSimulator
This class to initialize all the component the config_sim need to compile.
It contains command line parsing, start() update().
Developer can have extend functionality to check the user input, and make the program run in their way here.


###MyPassengerGen
This class inherent passenger generator class, which generator no passenger in each class.
Developer can change it here with the way they want how passenger generated.


[Go back to Developer Tutorial](@ref devtutorial)
