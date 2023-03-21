#include "Database.hpp"
#include "json.hpp";
#include "SLList.hpp"
#include "Timer.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
using json = nlohmann::json;
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
	Timer T;
	double seconds;
	long Milliseconds;
	vector <jsondata> data;
	ifstream A("random_person_data_01.json");
	json filea = json::parse(A);
	Loaddata(filea, data);
	cout << "Finished Loading to vector" << endl;
	LList SLL;
	for (int i = 0; i < data.size(); i++) {
		SLL.Insert(data[i]);
	}
	cout << "Finished filling Linked List " << endl;
	Database Dbase(data);
	cout << "Finished filling Database (AVL trees) " << endl;
	bool found;
	cout << endl;
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