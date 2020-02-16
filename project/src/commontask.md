Common Tasks  {#commontask}
============

This is a tutorial written for other programmers that describes what
they would need to do in order to extend functionality of the project.

* 1. Create the class under "src" directory, including the head files
and implementation files.

  * Complete the constructor, destructor, and other necessary functions.
Details can be different, depending on what you want the class to do.
However, please remember to match the major functions in supperclasses
.For instance,you can look at how function my_passenger_generator class works
before you start constructing your new passenger generator.

  * Take the my_passenger_generator as an example. I created a my_passenger_generator just generator a certain amount of passengers per time step at each stop.


* 2. Add the usage function inside class xxx.simulator.cc, like
"my_local_simulator.cc". Inside it create a new object of the new my_passenger_generator class
with the given parameter, and then apply it to the simulator.

* 3. You are able to use it now. Just call the respective simulator.



[Go back to Developer Tutorial](@ref devtutorial)
