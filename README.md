# Parking_App

## Table of Contents

* [About the Project](#about-the-project)
  * [Park Vehicle](#park-vehicle)
  * [Return Vehicle](#return-vehicle)
  * [List Parked Vehicles](#list-parked-vehicles)
  * [Close Parking](#close-parking)
  * [Exit Parking](#exit-parking)
* [Getting Started](#getting-started)
  * [Compilation](#compilation)
  
* [Contact](#contact)



<!-- ABOUT THE PROJECT -->
## About The Project

Final Project for Intro to Object Oriented Programming class.

This project simulates a parking complex, allowing vehicles to enter and exit the building. There are a limited amount of parking spots and the program acts accordingly. The car owners are also able to decide if they want a car wash.


```sh
****** Seneca Valet Parking ******
*****  Available spots: 1    *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 
```

### Park Vehicle
This option asks the user for the information of the vehicle. It only parks the vehicle if all information is valid and there is space in the parking lot.

### Return Vehicle
Choose this option and input the license plate of a vehicle to remove it from the parking lot. *Tip: List the parked vehicles first to see the number plates.

### List Parked Vehicles
Choosing this option displays all the vehicles currently in the parking lot.

### Close Parking
When the parking lot closes for the day, all cars are *removed* from the building and the program terminates. If you chose to close the parking lot and rerun the program, you must use the ParkingData.csv.bak file first to retrieve the original data, or git restore ParkingData.csv. 
### Exit Parking
Exiting the parking lot saves the updated parking list to the ParkingData.csv file and terminates the program.

Focus of the code:
* Emphasis on Modularity
* Input checking to prevent bugs


## Getting Started

[![Run on Repl.it](https://repl.it/badge/github/alastairodhiambo/Parking_App)](https://repl.it/@alastairo/ParkingApp)

To run this program, download the a.out executable and run using: 

```bash
Mac: ./a.out
Linux: a.out
Windows: a.out

```

### Compilation

If compilation is preferred, download or clone the repository and run the following command.
```sh
 g++ -Wall -std=c++11 -g -o Car.cpp Menu.cpp Motorcycle.cpp Parking.cpp ParkingAppTester.cpp ReadWritable.cpp Utils.cpp Vehicle.cpp
```

<!-- CONTACT -->
## Contact

Alastair Odhiambo

Project Link: [https://github.com/alastairodhiambo/Parking_App](https://github.com/alastairodhiambo/Parking_App)
