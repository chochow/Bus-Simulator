How to run the simulator  {#run_sim}
===========

Here are 2 simulators.
1. vis_sim
It provides the project With a visualizer. You can much more easily see the results of the project and what's happening.
![](../../docs/simulation.png)

2. config_sim
It provide users having customized routes and stops. And users can also set the runtime, time between each bus and output file to capture the terminal output for the simulator.  

#How to Generator simulators.
1. Navigate to base project directory(project/)  
2. Make and start server:
```
$ cd src
$ make
```
**You will find vis_sim and config_sim under the build/bin folder.**

#How to run vis_sim.
**<port_number> can be anything. Try and pick numbers above 8000 and not multiples of 10.**
1. Navigate to base project directory(project/)
2. start server:
```
$ cd ..
$./build/bin/vis_sim <port_number>
```
3. Navigate to the following address on your browser (Firefox/Chrome):
```
http://127.0.0.1:<port_number>/web_graphics/project.html
```

#How to run config_sim.

1. Navigate to base project directory(project/)
```
$ cd ..
$./build/bin/config_sim <config file> <iterations> <time_between vector> <output_file>
```

#Note for Default Setting.
<br/>
 <config_file> <iterations> <time_between_vector> <output_file> all of them will have default
setting. Either one of them is not right, the process will use the default one<br/>
1.  <config_file> Default file: /config/config.txt <br/>
2.  <iterations> Default value: 50 <br/>
3.  <time_between_vector> Default file:[10] <br/>
4.  <output_file> Default action: No output capturing <br/>

#How to build the config file.

ROUTE_GENERAL, Campus Connector

Stop Name, Long, Lat, Pass Gen Prob


ROUTE, <route_name> <br/>
STOP, <stop_name>, <Longtitude>, <Latitude>, <Passenger Generator Probability><br/>
.<br/>
.<br/>
.<br/>
<br/>
ROUTE, <route_name> <br/>
STOP, <stop_name>, <Longtitude>, <Latitude>, <Passenger Generator Probability><br/>
.<br/>
.<br/>
.<br/>
<br/>
<br/>
...<br/>
<br/>

**config_file can be any readable formate. Try and pick .txt**

**The number of routes must be even**

[Want to see the developer guide](@ref devtutorial)
