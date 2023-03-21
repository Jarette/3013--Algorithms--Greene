/*****************************************************************************
*                    
*  Author:           Jarette Greene
*  Email:            jkgreene0406@my.msutexas.edu / jarettegreene09@gmail.com
*  Label:            P01
*  Title:            Database Indexes... What?!? (not really)
*  Course:           CMPS 3013
*  Semester:         Spring 2023
* 
*  Description:
*        This program is used to compare the speed of two data structures 
*		A database of filled with 8 different AVL trees geared to search
*		a variety of different of data and a Singly Linked list. The program
*		then searches the database and the list and finds out the time it took
*		to search each data and displays it to the screen. All data from this file
*		is read from a Json file filled with 100,000 data points.
* 
*  Usage:
*       - create vector with data
*		- fill Linked LList with data
*		- Fill Database
*		- Search for data in database
*		- Display time that it took
* 		- Search for data in Linked List
*		- Display time that it took
*		
*  Files:           
*        Database.hpp     :        database header file
*		 Json.hpp		  :		   json header file
*		 SLList.hpp		  :		   Singly Linked List header file
*		 Timer.hpp		  :		   Timer header file
*		 Source.cpp		  :		   the main driver program
*		random_person_data_01 :    json file containing data
*****************************************************************************/
//neccesary Libraries
#include "Database.hpp"
#include "json.hpp";
#include "SLList.hpp"
#include "Timer.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
// using namespace standard
using namespace std;
// needed to access json files
using json = nlohmann::json;
/**
 * Loaddata
 * 
 * Description:
 * 		Used to load data from json file to a vector
 * 
 * Parameter
 * 		json	filea
 * 		vector	<jsondata>&data
 * 
 * Return
 * 
 * 		N/A
 */
void Loaddata(json filea, vector <jsondata>& data) {
	jsondata temp;
	for (int i = 0; i < 100000; i++) {
		temp.id = filea[i]["id"];
		temp.first_name = filea[i]["first_name"];
		temp.last_name = filea[i]["last_name"];
		temp.email = filea[i]["email"];
		temp.address = filea[i]["address"];
		temp.city = filea[i]["city"];
		temp.state = filea[i]["state"];
		temp.latitude = filea[i]["latitude"];
		temp.longitude = filea[i]["longitude"];
		temp.car = filea[i]["car"];
		temp.car_model = filea[i]["car_model"];
		temp.car_color = filea[i]["car_color"];
		temp.favorite_movie = filea[i]["favorite_movie"];
		temp.pet = filea[i]["pet"];
		temp.job_title = filea[i]["job_title"];
		temp.phone_number = filea[i]["phone_number"];
		temp.stocks.push_back(filea[i]["stocks"]["stock1"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock2"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock3"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock4"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock5"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock6"]);
		temp.stocks.push_back(filea[i]["stocks"]["stock7"]);
		data.push_back(temp);
		temp.stocks.clear();

	}
}
int main() {
	Timer T;    								//timer variable
	double seconds; 							 // used to store the seconds from the timer variable
	long Milliseconds; 							 // used to store the millisecond the timet variable
	vector <jsondata> data; 					 // vector storing data from json file
	ifstream A("random_person_data_01.json"); 	// accessing json file
	json filea = json::parse(A);				
	Loaddata(filea, data);						// loading data to the vector
	cout << "Finished Loading to vector" << endl;
	LList SLL;
	for (int i = 0; i < data.size(); i++) {      //filing the singly linked list with data
		SLL.Insert(data[i]);
	}
	cout << "Finished filling Linked List " << endl;
	Database Dbase(data);   					// filing database
	cout << "Finished filling Database (AVL trees) " << endl;
	bool found;
	cout << endl;

	/**
	 * Searching for ID# in the database and Linked list and 
	 * timing how long it takes to find these data
	 * 
	 */
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
	T.Start();
	found = SLL.FindallID(72532);
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the ID#: 72532 after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
	/**
	 * Searching for First Name in the database and Linked list and 
	 * timing how long it takes to find these data
	 * 
	 */
	T.Start();
	found = Dbase.FindFN("Pancho");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the First name: Pancho after checking " << Dbase.GetFNnodes() << "in AVL tree " << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
	}
	T.Start();
	found = SLL.FindallFN("Pancho");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the First name Pancho after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
/**
	 * Searching for Last Name in the database and Linked list and 
	 * timing how long it takes to find these data
	 * 
	 */
	T.Start();
	found = Dbase.FindLN("Klimsch");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Last name: Klimsch after checking " << Dbase.GetLNnodes() << "in AVL tree " << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
	}
	T.Start();
	found = SLL.FindallLN("Klimsch");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Last name: Klimsch after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
/**
* Searching for Email in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	found = Dbase.FindEM("dstrattana@diigo.com");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Email: dstrattana@diigo.com after checking " << Dbase.GetEMnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
	}
	T.Start();
	found = SLL.FindallEM("dstrattana@diigo.com");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Email: dstrattana@diigo.com after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
/**
* Searching for Phone Number in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	found = Dbase.FindPH("(619) 1599292");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Phone Number: (619) 1599292 after checking " << Dbase.GetPHnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
	}
	T.Start();
	found = SLL.FindallPH("(619) 1599292");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Phone Number: (619) 1599292 after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
/**
* Searching for Address in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	found = Dbase.FindAD("6 Sunbrook Plaza");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Address: 6 Sunbrook Plaza after checking " << Dbase.GetADnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
	}
	T.Start();
	found = SLL.FindallAD("6 Sunbrook Plaza");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Address: 6 Sunbrook Plaza after checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
/**
* Searching for Job Tittle in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	found = Dbase.FindJT("Programmer Analyst III");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Job Title: Programmer Analyst III after checking " << Dbase.GetJTnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
	}
	T.Start();
	found = SLL.FindallJT("Programmer Analyst III");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Job Title: Programmer Analyst III checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
	T.Start();
	found = Dbase.FindCM("Range Rover");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Car Model: Range Rover after checking " << Dbase.GetCMnodes() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
	}
/**
* Searching for Car Model in the database and Linked list and 
* timing how long it takes to find these data
* 
*/
	T.Start();
	found = SLL.FindallCM("Range Rover");
	T.End();
	seconds = T.Seconds();
	Milliseconds = T.MilliSeconds();
	if (found) {
		cout << "Found the Car Model: Range Rover checking " << SLL.GetNodesChecked() << endl;
		cout << "Taking " << seconds << " seconds or " << Milliseconds << " milliseconds " << endl;
		cout << endl;
	}
	else {
		cout << "Data not found";
		cout << endl;
		cout << endl;
	}
}