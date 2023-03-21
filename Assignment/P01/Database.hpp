#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct jsondata {
	int id;
	string first_name;
	string last_name;
	string email;
	string address;
	string city;
	string state;
	double latitude;
	double longitude;
	string car;
	string car_model;
	string car_color;
	string favorite_movie;
	string pet;
	string job_title;
	string phone_number;
	vector <string> stocks;

	jsondata() {
		first_name = "NULL";
		last_name = "NULL";
		email = "NULL";
		address = "NULL";
		city = " NULL";
		state = "NULL";
		latitude = -1;
		longitude = -1;
		car = "NULL";
		car_model = "NULL";
		car_color = "NULL";
		favorite_movie = "NULL";
		pet = "NULL";
		job_title = "NULL";
		phone_number = "NULL";
		stocks.push_back("NULL");
	}

	void display() {
		cout << "ID: " << id << endl;
		cout << "First Name: " << first_name << endl;
		cout << "Last Name: " << last_name << endl;
		cout << "Email: " << email << endl;
		cout << "Address: " << address << endl;
		cout << "City: " << city << endl;
		cout << "State: " << state << endl;
		cout << "Latitude: " << latitude << endl;
		cout << "Longitude: " << longitude << endl;
		cout << "Car: " << car << endl;
		cout << "Car Model: " << car_model << endl;
		cout << "Car Color: " << car_color << endl;
		cout << "Favorite Movie: " << favorite_movie << endl;
		cout << "Pet: " << pet << endl;
		cout << "Job Title: " << job_title << endl;
		cout << "Phone Number: " << phone_number << endl;
		cout << "Stocks: " << endl;
		for (int i = 0; i < stocks.size(); i++) {
			cout << "      " << stocks[i] << endl;
		}
		cout << endl;
		cout << endl;
	}
};
struct Node {
	jsondata data;
	Node* left;
	Node* right;
	Node* parent;
	int avlValue;
	Node() {

	}
	Node(jsondata d) {
		data.id = d.id;
		data.first_name = d.first_name;
		data.last_name = d.last_name;
		data.email = d.email;
		data.address = d.address;
		data.city = d.city;
		data.state = d.state;
		data.latitude = d.latitude;
		data.longitude = d.longitude;
		data.car = d.car;
		data.car_model = d.car_model;
		data.car_color = d.car_color;
		data.favorite_movie = d.favorite_movie;
		data.pet = d.pet;
		data.job_title = d.job_title;
		data.phone_number = d.phone_number;
		for (int i = 0; i < d.stocks.size(); i++) {
			data.stocks.push_back(d.stocks[i]);
		}

	}
};
class IDAVL {
	Node* root;
	int nodeschecked;
	int avlValue(Node *current);
	void computeAvlValues(Node*& current);
	int height(Node* current);
	void insertNode(Node *&current, Node *&newNode);
	void rotateleft(Node *&current);
	void rotateright(Node*& current);
	bool rightheavy(Node* current);
	bool lefftheavy(Node* current);
	void dodumptree(Node* current);
public:
	IDAVL();
	~IDAVL();

	void insert(jsondata);
	bool search(int);
	int GetNodes();
	void dumptree();
	
};
void IDAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
void IDAVL::dodumptree(Node* current) {
	if (current) {
		cout << "ADD:	" << current << endl
			<< "Parent-> " << current->parent << endl
			<< "Val: ";  current->data.display();
		cout << "AVL: " << current->avlValue << endl
			<< "Left-> " << current->left << endl
			<< "Right-> " << current->right << endl << endl;

		dodumptree(current->left);
		dodumptree(current->right);

	}
}
IDAVL::IDAVL() {
	root = 0;
	nodeschecked = 0;
}
IDAVL :: ~IDAVL() {
}
void IDAVL::insertNode(Node*& current, Node*& newNode) {
	if (current == nullptr) {
		current = newNode;
	}
	else if (newNode->data.id <= current->data.id) {
		newNode->parent = current;
		insertNode(current->left, newNode);
	}
	else {
		newNode->parent = current;
		insertNode(current->right, newNode);
	}
}
void IDAVL::insert(jsondata data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->avlValue = 0;
	newNode->left = newNode->right = nullptr;
	newNode->parent = nullptr;
	insertNode(root, newNode);
	computeAvlValues(root);
}
bool IDAVL::search(int data) {
	Node* current = root;
	while (current) {
		if (current->data.id == data) {
			nodeschecked++;
			return true;
		}
		else if (data < current->data.id) {
			nodeschecked++;
			current = current->left;
		}
		else {
			nodeschecked++;
			current = current->right;
		}
	}
	return false;
}
int IDAVL::height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	if (current == nullptr) {
		return 0;
	}
	else {
		left_height = height(current->left);
		right_height = height(current->right);
	}
	if (left_height > right_height) {
		return 1 + left_height;
	}
	else {
		return 1 + right_height;
	}
}
int IDAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
void IDAVL::computeAvlValues(Node*& current) {
	if (current) {
		computeAvlValues(current->left);
		computeAvlValues(current->right);
		current->avlValue = avlValue(current);
		if (current->avlValue > 1) {
			rotateleft(current);
		}
		else if (current->avlValue < -1) {
			rotateright(current);
		}
	}
}
void IDAVL::rotateleft(Node*& Subroot) {
	if (lefftheavy(Subroot->right)) {
		rotateright(Subroot->right);
	}
	Node* Temp;
	Temp = Subroot->right;
	Subroot->right = Temp->left;
	Temp->left = Subroot;
	Subroot = Temp;
	
	computeAvlValues(Subroot);
}
void IDAVL::rotateright(Node*& Subroot) {
	if (rightheavy(Subroot->left)) {
		rotateleft(Subroot->left);
	}
	Node* Temp;
	Temp = Subroot->left;
	Subroot->left = Temp->right;
	Temp->right = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
bool IDAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
bool IDAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
int IDAVL::GetNodes() {
	return nodeschecked;
}
class FNAVL {
	Node* root;
	int nodeschecked;
	int avlValue(Node* current);
	void computeAvlValues(Node*& current);
	int height(Node* current);
	void insertNode(Node*& current, Node*& newNode);
	void rotateleft(Node*& current);
	void rotateright(Node*& current);
	bool rightheavy(Node* current);
	bool lefftheavy(Node* current);
	void dodumptree(Node* current);
public:
	FNAVL();
	~FNAVL();

	void insert(jsondata);
	bool search(string);
	int GetNodes();
	void dumptree();

};
void FNAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
void FNAVL::dodumptree(Node* current) {
	if (current) {
		cout << "ADD:	" << current << endl
			<< "Parent-> " << current->parent << endl
			<< "Val: ";  current->data.display();
		cout << "AVL: " << current->avlValue << endl
			<< "Left-> " << current->left << endl
			<< "Right-> " << current->right << endl << endl;

		dodumptree(current->left);
		dodumptree(current->right);

	}
}
FNAVL::FNAVL() {
	root = 0;
	nodeschecked = 0;
}
FNAVL :: ~FNAVL() {
}
void FNAVL::insertNode(Node*& current, Node*& newNode) {
	if (current == nullptr) {
		current = newNode;
	}
	else if (newNode->data.first_name <= current->data.first_name) {
		newNode->parent = current;
		insertNode(current->left, newNode);
	}
	else {
		newNode->parent = current;
		insertNode(current->right, newNode);
	}
}
void FNAVL::insert(jsondata data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->avlValue = 0;
	newNode->left = newNode->right = nullptr;
	newNode->parent = nullptr;
	insertNode(root, newNode);
	computeAvlValues(root);
}
bool FNAVL::search(string data) {
	Node* current = root;
	while (current) {
		if (current->data.first_name == data) {
			nodeschecked++;
			return true;
		}
		else if (data < current->data.first_name) {
			nodeschecked++;
			current = current->left;
		}
		else {
			nodeschecked++;
			current = current->right;
		}
	}
	return false;
}
int FNAVL::height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	if (current == nullptr) {
		return 0;
	}
	else {
		left_height = height(current->left);
		right_height = height(current->right);
	}
	if (left_height > right_height) {
		return 1 + left_height;
	}
	else {
		return 1 + right_height;
	}
}
int FNAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
void FNAVL::computeAvlValues(Node*& current) {
	if (current) {
		computeAvlValues(current->left);
		computeAvlValues(current->right);
		current->avlValue = avlValue(current);
		if (current->avlValue > 1) {
			rotateleft(current);
		}
		else if (current->avlValue < -1) {
			rotateright(current);
		}
	}
}
void FNAVL::rotateleft(Node*& Subroot) {
	if (lefftheavy(Subroot->right)) {
		rotateright(Subroot->right);
	}
	Node* Temp;
	Temp = Subroot->right;
	Subroot->right = Temp->left;
	Temp->left = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
void FNAVL::rotateright(Node*& Subroot) {
	if (rightheavy(Subroot->left)) {
		rotateleft(Subroot->left);
	}
	Node* Temp;
	Temp = Subroot->left;
	Subroot->left = Temp->right;
	Temp->right = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
bool FNAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
bool FNAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
int FNAVL::GetNodes() {
	return nodeschecked;
}
class LNAVL {
	Node* root;
	int nodeschecked;
	int avlValue(Node* current);
	void computeAvlValues(Node*& current);
	int height(Node* current);
	void insertNode(Node*& current, Node*& newNode);
	void rotateleft(Node*& current);
	void rotateright(Node*& current);
	bool rightheavy(Node* current);
	bool lefftheavy(Node* current);
	void dodumptree(Node* current);
public:
	LNAVL();
	~LNAVL();

	void insert(jsondata);
	bool search(string);
	int GetNodes();
	void dumptree();

};
void LNAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
void LNAVL::dodumptree(Node* current) {
	if (current) {
		cout << "ADD:	" << current << endl
			<< "Parent-> " << current->parent << endl
			<< "Val: ";  current->data.display();
		cout << "AVL: " << current->avlValue << endl
			<< "Left-> " << current->left << endl
			<< "Right-> " << current->right << endl << endl;

		dodumptree(current->left);
		dodumptree(current->right);

	}
}
LNAVL::LNAVL() {
	root = 0;
	nodeschecked = 0;
}
LNAVL :: ~LNAVL() {
}
void LNAVL::insertNode(Node*& current, Node*& newNode) {
	if (current == nullptr) {
		current = newNode;
	}
	else if (newNode->data.last_name <= current->data.last_name) {
		newNode->parent = current;
		insertNode(current->left, newNode);
	}
	else {
		newNode->parent = current;
		insertNode(current->right, newNode);
	}
}
void LNAVL::insert(jsondata data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->avlValue = 0;
	newNode->left = newNode->right = nullptr;
	newNode->parent = nullptr;
	insertNode(root, newNode);
	computeAvlValues(root);
}
bool LNAVL::search(string data) {
	Node* current = root;
	while (current) {
		if (current->data.last_name == data) {
			nodeschecked++;
			return true;
		}
		else if (data < current->data.last_name) {
			nodeschecked++;
			current = current->left;
		}
		else {
			nodeschecked++;
			current = current->right;
		}
	}
	return false;
}
int LNAVL::height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	if (current == nullptr) {
		return 0;
	}
	else {
		left_height = height(current->left);
		right_height = height(current->right);
	}
	if (left_height > right_height) {
		return 1 + left_height;
	}
	else {
		return 1 + right_height;
	}
}
int LNAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
void LNAVL::computeAvlValues(Node*& current) {
	if (current) {
		computeAvlValues(current->left);
		computeAvlValues(current->right);
		current->avlValue = avlValue(current);
		if (current->avlValue > 1) {
			rotateleft(current);
		}
		else if (current->avlValue < -1) {
			rotateright(current);
		}
	}
}
void LNAVL::rotateleft(Node*& Subroot) {
	if (lefftheavy(Subroot->right)) {
		rotateright(Subroot->right);
	}
	Node* Temp;
	Temp = Subroot->right;
	Subroot->right = Temp->left;
	Temp->left = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
void LNAVL::rotateright(Node*& Subroot) {
	if (rightheavy(Subroot->left)) {
		rotateleft(Subroot->left);
	}
	Node* Temp;
	Temp = Subroot->left;
	Subroot->left = Temp->right;
	Temp->right = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
bool LNAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
bool LNAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
int LNAVL::GetNodes() {
	return nodeschecked;
}
class EMAVL {
	Node* root;
	int nodeschecked;
	int avlValue(Node* current);
	void computeAvlValues(Node*& current);
	int height(Node* current);
	void insertNode(Node*& current, Node*& newNode);
	void rotateleft(Node*& current);
	void rotateright(Node*& current);
	bool rightheavy(Node* current);
	bool lefftheavy(Node* current);
	void dodumptree(Node* current);
public:
	EMAVL();
	~EMAVL();

	void insert(jsondata);
	bool search(string);
	int GetNodes();
	void dumptree();

};
void EMAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
void EMAVL::dodumptree(Node* current) {
	if (current) {
		cout << "ADD:	" << current << endl
			<< "Parent-> " << current->parent << endl
			<< "Val: ";  current->data.display();
		cout << "AVL: " << current->avlValue << endl
			<< "Left-> " << current->left << endl
			<< "Right-> " << current->right << endl << endl;

		dodumptree(current->left);
		dodumptree(current->right);

	}
}
EMAVL::EMAVL() {
	root = 0;
	nodeschecked = 0;
}
EMAVL :: ~EMAVL() {
}
void EMAVL::insertNode(Node*& current, Node*& newNode) {
	if (current == nullptr) {
		current = newNode;
	}
	else if (newNode->data.email <= current->data.email) {
		newNode->parent = current;
		insertNode(current->left, newNode);
	}
	else {
		newNode->parent = current;
		insertNode(current->right, newNode);
	}
}
void EMAVL::insert(jsondata data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->avlValue = 0;
	newNode->left = newNode->right = nullptr;
	newNode->parent = nullptr;
	insertNode(root, newNode);
	computeAvlValues(root);
}
bool EMAVL::search(string data) {
	Node* current = root;
	while (current) {
		if (current->data.email == data) {
			nodeschecked++;
			return true;
		}
		else if (data < current->data.email) {
			nodeschecked++;
			current = current->left;
		}
		else {
			nodeschecked++;
			current = current->right;
		}
	}
	return false;
}
int EMAVL::height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	if (current == nullptr) {
		return 0;
	}
	else {
		left_height = height(current->left);
		right_height = height(current->right);
	}
	if (left_height > right_height) {
		return 1 + left_height;
	}
	else {
		return 1 + right_height;
	}
}
int EMAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
void EMAVL::computeAvlValues(Node*& current) {
	if (current) {
		computeAvlValues(current->left);
		computeAvlValues(current->right);
		current->avlValue = avlValue(current);
		if (current->avlValue > 1) {
			rotateleft(current);
		}
		else if (current->avlValue < -1) {
			rotateright(current);
		}
	}
}
void EMAVL::rotateleft(Node*& Subroot) {
	if (lefftheavy(Subroot->right)) {
		rotateright(Subroot->right);
	}
	Node* Temp;
	Temp = Subroot->right;
	Subroot->right = Temp->left;
	Temp->left = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
void EMAVL::rotateright(Node*& Subroot) {
	if (rightheavy(Subroot->left)) {
		rotateleft(Subroot->left);
	}
	Node* Temp;
	Temp = Subroot->left;
	Subroot->left = Temp->right;
	Temp->right = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
bool EMAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
bool EMAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
int EMAVL::GetNodes() {
	return nodeschecked;
}
class PHAVL {
	Node* root;
	int nodeschecked;
	int avlValue(Node* current);
	void computeAvlValues(Node*& current);
	int height(Node* current);
	void insertNode(Node*& current, Node*& newNode);
	void rotateleft(Node*& current);
	void rotateright(Node*& current);
	bool rightheavy(Node* current);
	bool lefftheavy(Node* current);
	void dodumptree(Node* current);
public:
	PHAVL();
	~PHAVL();

	void insert(jsondata);
	bool search(string);
	int GetNodes();
	void dumptree();

};
void PHAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
void PHAVL::dodumptree(Node* current) {
	if (current) {
		cout << "ADD:	" << current << endl
			<< "Parent-> " << current->parent << endl
			<< "Val: ";  current->data.display();
		cout << "AVL: " << current->avlValue << endl
			<< "Left-> " << current->left << endl
			<< "Right-> " << current->right << endl << endl;

		dodumptree(current->left);
		dodumptree(current->right);

	}
}
PHAVL::PHAVL() {
	root = 0;
	nodeschecked = 0;
}
PHAVL :: ~PHAVL() {
}
void PHAVL::insertNode(Node*& current, Node*& newNode) {
	if (current == nullptr) {
		current = newNode;
	}
	else if (newNode->data.phone_number <= current->data.phone_number) {
		newNode->parent = current;
		insertNode(current->left, newNode);
	}
	else {
		newNode->parent = current;
		insertNode(current->right, newNode);
	}
}
void PHAVL::insert(jsondata data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->avlValue = 0;
	newNode->left = newNode->right = nullptr;
	newNode->parent = nullptr;
	insertNode(root, newNode);
	computeAvlValues(root);
}
bool PHAVL::search(string data) {
	Node* current = root;
	while (current) {
		if (current->data.phone_number == data) {
			nodeschecked++;
			return true;
		}
		else if (data < current->data.phone_number) {
			nodeschecked++;
			current = current->left;
		}
		else {
			nodeschecked++;
			current = current->right;
		}
	}
	return false;
}
int PHAVL::height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	if (current == nullptr) {
		return 0;
	}
	else {
		left_height = height(current->left);
		right_height = height(current->right);
	}
	if (left_height > right_height) {
		return 1 + left_height;
	}
	else {
		return 1 + right_height;
	}
}
int PHAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
void PHAVL::computeAvlValues(Node*& current) {
	if (current) {
		computeAvlValues(current->left);
		computeAvlValues(current->right);
		current->avlValue = avlValue(current);
		if (current->avlValue > 1) {
			rotateleft(current);
		}
		else if (current->avlValue < -1) {
			rotateright(current);
		}
	}
}
void PHAVL::rotateleft(Node*& Subroot) {
	if (lefftheavy(Subroot->right)) {
		rotateright(Subroot->right);
	}
	Node* Temp;
	Temp = Subroot->right;
	Subroot->right = Temp->left;
	Temp->left = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
void PHAVL::rotateright(Node*& Subroot) {
	if (rightheavy(Subroot->left)) {
		rotateleft(Subroot->left);
	}
	Node* Temp;
	Temp = Subroot->left;
	Subroot->left = Temp->right;
	Temp->right = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
bool PHAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
bool PHAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
int PHAVL::GetNodes() {
	return nodeschecked;
}
class ADAVL {
	Node* root;
	int nodeschecked;
	int avlValue(Node* current);
	void computeAvlValues(Node*& current);
	int height(Node* current);
	void insertNode(Node*& current, Node*& newNode);
	void rotateleft(Node*& current);
	void rotateright(Node*& current);
	bool rightheavy(Node* current);
	bool lefftheavy(Node* current);
	void dodumptree(Node* current);
public:
	ADAVL();
	~ADAVL();

	void insert(jsondata);
	bool search(string);
	int GetNodes();
	void dumptree();

};
void ADAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
void ADAVL::dodumptree(Node* current) {
	if (current) {
		cout << "ADD:	" << current << endl
			<< "Parent-> " << current->parent << endl
			<< "Val: ";  current->data.display();
		cout << "AVL: " << current->avlValue << endl
			<< "Left-> " << current->left << endl
			<< "Right-> " << current->right << endl << endl;

		dodumptree(current->left);
		dodumptree(current->right);

	}
}
ADAVL::ADAVL() {
	root = 0;
	nodeschecked = 0;
}
ADAVL :: ~ADAVL() {
}
void ADAVL::insertNode(Node*& current, Node*& newNode) {
	if (current == nullptr) {
		current = newNode;
	}
	else if (newNode->data.address <= current->data.address) {
		newNode->parent = current;
		insertNode(current->left, newNode);
	}
	else {
		newNode->parent = current;
		insertNode(current->right, newNode);
	}
}
void ADAVL::insert(jsondata data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->avlValue = 0;
	newNode->left = newNode->right = nullptr;
	newNode->parent = nullptr;
	insertNode(root, newNode);
	computeAvlValues(root);
}
bool ADAVL::search(string data) {
	Node* current = root;
	while (current) {
		if (current->data.address == data) {
			nodeschecked++;
			return true;
		}
		else if (data < current->data.address) {
			nodeschecked++;
			current = current->left;
		}
		else {
			nodeschecked++;
			current = current->right;
		}
	}
	return false;
}
int ADAVL::height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	if (current == nullptr) {
		return 0;
	}
	else {
		left_height = height(current->left);
		right_height = height(current->right);
	}
	if (left_height > right_height) {
		return 1 + left_height;
	}
	else {
		return 1 + right_height;
	}
}
int ADAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
void ADAVL::computeAvlValues(Node*& current) {
	if (current) {
		computeAvlValues(current->left);
		computeAvlValues(current->right);
		current->avlValue = avlValue(current);
		if (current->avlValue > 1) {
			rotateleft(current);
		}
		else if (current->avlValue < -1) {
			rotateright(current);
		}
	}
}
void ADAVL::rotateleft(Node*& Subroot) {
	if (lefftheavy(Subroot->right)) {
		rotateright(Subroot->right);
	}
	Node* Temp;
	Temp = Subroot->right;
	Subroot->right = Temp->left;
	Temp->left = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
void ADAVL::rotateright(Node*& Subroot) {
	if (rightheavy(Subroot->left)) {
		rotateleft(Subroot->left);
	}
	Node* Temp;
	Temp = Subroot->left;
	Subroot->left = Temp->right;
	Temp->right = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
bool ADAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
bool ADAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
int ADAVL::GetNodes() {
	return nodeschecked;
}
class JTAVL {
	Node* root;
	int nodeschecked;
	int avlValue(Node* current);
	void computeAvlValues(Node*& current);
	int height(Node* current);
	void insertNode(Node*& current, Node*& newNode);
	void rotateleft(Node*& current);
	void rotateright(Node*& current);
	bool rightheavy(Node* current);
	bool lefftheavy(Node* current);
	void dodumptree(Node* current);
public:
	JTAVL();
	~JTAVL();

	void insert(jsondata);
	bool search(string);
	int GetNodes();
	void dumptree();

};
void JTAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
void JTAVL::dodumptree(Node* current) {
	if (current) {
		cout << "ADD:	" << current << endl
			<< "Parent-> " << current->parent << endl
			<< "Val: ";  current->data.display();
		cout << "AVL: " << current->avlValue << endl
			<< "Left-> " << current->left << endl
			<< "Right-> " << current->right << endl << endl;

		dodumptree(current->left);
		dodumptree(current->right);

	}
}
JTAVL::JTAVL() {
	root = 0;
	nodeschecked = 0;
}
JTAVL :: ~JTAVL() {
}
void JTAVL::insertNode(Node*& current, Node*& newNode) {
	if (current == nullptr) {
		current = newNode;
	}
	else if (newNode->data.job_title <= current->data.job_title) {
		newNode->parent = current;
		insertNode(current->left, newNode);
	}
	else {
		newNode->parent = current;
		insertNode(current->right, newNode);
	}
}
void JTAVL::insert(jsondata data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->avlValue = 0;
	newNode->left = newNode->right = nullptr;
	newNode->parent = nullptr;
	insertNode(root, newNode);
	computeAvlValues(root);
}
bool JTAVL::search(string data) {
	Node* current = root;
	while (current) {
		if (current->data.job_title == data) {
			nodeschecked++;
			return true;
		}
		else if (data < current->data.job_title) {
			nodeschecked++;
			current = current->left;
		}
		else {
			nodeschecked++;
			current = current->right;
		}
	}
	return false;
}
int JTAVL::height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	if (current == nullptr) {
		return 0;
	}
	else {
		left_height = height(current->left);
		right_height = height(current->right);
	}
	if (left_height > right_height) {
		return 1 + left_height;
	}
	else {
		return 1 + right_height;
	}
}
int JTAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
void JTAVL::computeAvlValues(Node*& current) {
	if (current) {
		computeAvlValues(current->left);
		computeAvlValues(current->right);
		current->avlValue = avlValue(current);
		if (current->avlValue > 1) {
			rotateleft(current);
		}
		else if (current->avlValue < -1) {
			rotateright(current);
		}
	}
}
void JTAVL::rotateleft(Node*& Subroot) {
	if (lefftheavy(Subroot->right)) {
		rotateright(Subroot->right);
	}
	Node* Temp;
	Temp = Subroot->right;
	Subroot->right = Temp->left;
	Temp->left = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
void JTAVL::rotateright(Node*& Subroot) {
	if (rightheavy(Subroot->left)) {
		rotateleft(Subroot->left);
	}
	Node* Temp;
	Temp = Subroot->left;
	Subroot->left = Temp->right;
	Temp->right = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
bool JTAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
bool JTAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
int JTAVL::GetNodes() {
	return nodeschecked;
}
class CMAVL {
	Node* root;
	int nodeschecked;
	int avlValue(Node* current);
	void computeAvlValues(Node*& current);
	int height(Node* current);
	void insertNode(Node*& current, Node*& newNode);
	void rotateleft(Node*& current);
	void rotateright(Node*& current);
	bool rightheavy(Node* current);
	bool lefftheavy(Node* current);
	void dodumptree(Node* current);
public:
	CMAVL();
	~CMAVL();

	void insert(jsondata);
	bool search(string);
	int GetNodes();
	void dumptree();

};
void CMAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
void CMAVL::dodumptree(Node* current) {
	if (current) {
		cout << "ADD:	" << current << endl
			<< "Parent-> " << current->parent << endl
			<< "Val: ";  current->data.display();
		cout << "AVL: " << current->avlValue << endl
			<< "Left-> " << current->left << endl
			<< "Right-> " << current->right << endl << endl;

		dodumptree(current->left);
		dodumptree(current->right);

	}
}
CMAVL::CMAVL() {
	root = 0;
	nodeschecked = 0;
}
CMAVL :: ~CMAVL() {
}
void CMAVL::insertNode(Node*& current, Node*& newNode) {
	if (current == nullptr) {
		current = newNode;
	}
	else if (newNode->data.car_model <= current->data.car_model) {
		newNode->parent = current;
		insertNode(current->left, newNode);
	}
	else {
		newNode->parent = current;
		insertNode(current->right, newNode);
	}
}
void CMAVL::insert(jsondata data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = data;
	newNode->avlValue = 0;
	newNode->left = newNode->right = nullptr;
	newNode->parent = nullptr;
	insertNode(root, newNode);
	computeAvlValues(root);
}
bool CMAVL::search(string data) {
	Node* current = root;
	while (current) {
		if (current->data.car_model == data) {
			nodeschecked++;
			return true;
		}
		else if (data < current->data.car_model) {
			nodeschecked++;
			current = current->left;
		}
		else {
			nodeschecked++;
			current = current->right;
		}
	}
	return false;
}
int CMAVL::height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	if (current == nullptr) {
		return 0;
	}
	else {
		left_height = height(current->left);
		right_height = height(current->right);
	}
	if (left_height > right_height) {
		return 1 + left_height;
	}
	else {
		return 1 + right_height;
	}
}
int CMAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
void CMAVL::computeAvlValues(Node*& current) {
	if (current) {
		computeAvlValues(current->left);
		computeAvlValues(current->right);
		current->avlValue = avlValue(current);
		if (current->avlValue > 1) {
			rotateleft(current);
		}
		else if (current->avlValue < -1) {
			rotateright(current);
		}
	}
}
void CMAVL::rotateleft(Node*& Subroot) {
	if (lefftheavy(Subroot->right)) {
		rotateright(Subroot->right);
	}
	Node* Temp;
	Temp = Subroot->right;
	Subroot->right = Temp->left;
	Temp->left = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
void CMAVL::rotateright(Node*& Subroot) {
	if (rightheavy(Subroot->left)) {
		rotateleft(Subroot->left);
	}
	Node* Temp;
	Temp = Subroot->left;
	Subroot->left = Temp->right;
	Temp->right = Subroot;
	Subroot = Temp;

	computeAvlValues(Subroot);
}
bool CMAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
bool CMAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
int CMAVL::GetNodes() {
	return nodeschecked;
}
class Database {
private:
	IDAVL List1;
	FNAVL List2;
	LNAVL List3;
	EMAVL List4;
	PHAVL List5;
	ADAVL List6;
	JTAVL List7;
	CMAVL List8;
public:
	Database(vector<jsondata>data) {
		int n = 0;
		swap(data[0], data[49999]);
		random_shuffle(data.begin()+1, data.end());
		for (int i = 0; i < data.size(); i++) {
			List1.insert(data[i]);          
		}
		cout << "finished loading ID" << endl;
		while (data[n].first_name.front() != 'M' && data[n].first_name.front() == 'm') {
			n++;
		}
		swap(data[0], data[n]);
		for (int i = 0; i < data.size(); i++) {
			List2.insert(data[i]);
		}
		cout << "finished loading FN" << endl;
		n = 0;
		while (data[n].last_name.front() != 'M' && data[n].last_name.front() == 'm') {
			n++;
		}
		swap(data[0], data[n]);
		for (int i = 0; i < data.size(); i++) {
			List3.insert(data[i]);
		}
		cout << "finished loading LN" << endl;
		n = 0;
		while (data[n].email.front() != 'M' && data[n].email.front() == 'm') {
			n++;
		}
		swap(data[0], data[n]);
		for (int i = 0; i < data.size(); i++) {
			List4.insert(data[i]);
		}
		cout << "finished loading EM" << endl;
		n = 0;
		while (data[n].phone_number[1] != '5') {
			n++;
		}
		swap(data[0], data[n]);
		for (int i = 0; i < data.size(); i++) {
			List5.insert(data[i]);
		}
		cout << "finished loading PH" << endl;
		n = 0;
		while (data[n].address.front() != 'I' && data[n].address.front() == 'i') {
			n++;
		}
		swap(data[0], data[n]);
		for (int i = 0; i < data.size(); i++) {
			List6.insert(data[i]);
		}
		cout << "finished loading AD" << endl;
		n = 0;
		while (data[n].job_title.front() != 'M' && data[n].job_title.front() == 'm') {
			n++;
		}
		swap(data[0], data[n]);
		for (int i = 0; i < data.size(); i++) {
			List7.insert(data[i]);
		}
		cout << "finished loading JT" << endl;
		n = 0;
		while (data[n].car_model.front() != 'M' && data[n].car_model.front() == 'm') {
			n++;
		}
		swap(data[0], data[n]);
		for (int i = 0; i < data.size(); i++) {
			List8.insert(data[i]);
		}
		cout << "finished loading CM" << endl;
	}
	~Database() {

	}
	bool FindID(int data) { return List1.search(data); }
	int GetIDnodes() { return List1.GetNodes(); }
	bool FindFN(string data) { return List2.search(data); }
	int GetFNnodes() { return List2.GetNodes(); }
	bool FindLN(string data) { return List3.search(data); }
	int GetLNnodes() { return List3.GetNodes(); }
	bool FindEM(string data) { return List4.search(data); }
	int GetEMnodes() { return List4.GetNodes(); }
	bool FindPH(string data) { return List5.search(data); }
	int GetPHnodes() { return List5.GetNodes(); }
	bool FindAD(string data) { return List6.search(data); }
	int GetADnodes() { return List6.GetNodes(); }
	bool FindJT(string data) { return List7.search(data); }
	int GetJTnodes() { return List7.GetNodes(); }
	bool FindCM(string data) { return List8.search(data); }
	int GetCMnodes() { return List8.GetNodes(); }

	void Insert(jsondata data) {
		List1.insert(data);
		List2.insert(data);
		List3.insert(data);
		List4.insert(data);
		List5.insert(data);
		List6.insert(data);
		List7.insert(data);
		List8.insert(data);
	}

};

