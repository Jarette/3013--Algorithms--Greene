## AO3 - Database Indexes... What?!?(not really)
### Jarette Greene
### Description:

    This Program will compare the effeciently of two different data
    structures, AVL trees and Linked Lists. The program will load 100,000
    data points from a json file into a vector then place them into a Singly Linked list and 8 different AVL trees that searches and adds 
    based on different criteria. Then it will search for specfic pieces of data in both data structures and times how long it took to access
    the data in both. 

### Files

|   #   | File             | Description                                        |
| :---: | ---------------  | -------------------------------------------------- |
|   1   | [Source.cpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P01/Source.cpp)| Main driver.|
|   2   | [Database.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P01/Database.hpp)| Contains a Database class that stores 8 different AVL trees.|
|   3   | [Json.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P01/json.hpp)|Contains a Database class that stores |
|   4   | [SLList.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P01/SLList.hpp)| Contains singly Linked List|
|   5   | [Timer.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P01/Timer.hpp)| Timer class used to track the time used to run functions|
|   6   | [random_person_data_01.json](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P01/random_person_data_01.json)|json file containing all data|
|   7   | [Output.txt](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P01/Output.txt)|Example output file|



### Instructions

- use load data function to load vector
- Fill the Linked list with data from vector 
- Load Database with data from vector 
- Start timer
- Search for data in database
- Stopt timer
- display the time it took to search 
- Start timer
- Search Data in Linked list
- stop timer
- display the time it took to search 

- Example Command:
'''
    // loading data into vector
    vector <jsondata> data; 					
	ifstream A("random_person_data_01.json"); 	
	json filea = json::parse(A);				
	Loaddata(filea, data);	

    // filling data into linked list and database
    for (int i = 0; i < data.size(); i++) {      
		SLL.Insert(data[i]);
	}
	cout << "Finished filling Linked List " << endl;
	Database Dbase(data);   			

    // checking tie to search for data in database
    T.Start();
	found = Dbase.FindID(72532);
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the ID#: 72532 after checking " << Dbase.GetIDnodes() << "in AVL tree " << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
'''