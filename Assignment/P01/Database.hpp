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
*        This header file contains the Binary Search trees used to create a the 
*        the database used in the main.cpp file. The Binary search trees in this 
*        program all accepts data from a Json file stored in a vector of structs. This file
*        contains 9 binary search trees with each searching using a different key
*        (ID, First Name, Last Name, Email, Phone, Address, Job Title and 
*         Car Model). Then places all these trees as attributes in a Database where 
*         the user can access the tree based on what what type of data they would 
*         like to search by
* 
*  Usage:
*       - create instance of database
*       - pass in vector of data into constructor
*       - Use Found function to see if data is stored within database
*       - and GetNodes to check how much nodes were checked before finding the data.
* 
*  Files:           
*        Database.hpp     :        database header file
*****************************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * jsondata
 * 
 * Description:
 *      struct used to keep all data recieved from the json file together
 * 
 * Public Methods:
 *            jsondata()   //constructor
 *    void    display();   // displays data in the struct
 * 
 * Private Methods:
 *    
 *       N/A
 * 
 * Usage: 
 * 
 *     Node(jsondata d)  //passes jsondata into a node
 *     data.display();   //displays all data stored in the struct
 *      
 */
struct jsondata {
	 // all fields collected from JSON file
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
	/**
 * Public: jsondata
 * 
 * Description:
 *     Default Constructor
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
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
/**
 * Public: display
 * 
 * Description:
 *     used to display all data stored in the struct to the screen 
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
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
/**
 * Node
 * 
 * Description:
 *      Node used to store the values within the tree;
 * 
 * Public Methods:
 *            Node()  //constructor
 * 			  Ndode(jsondata) // overloaded constructor
 * 
 * Private Methods:
 *    
 *       N/A
 * 
 * Usage: 
 * 
 *     Node *temp = new Node(d) //creates and initilizes a new node 
 *      
 */
struct Node {
	jsondata data;
	Node* left;
	Node* right;
	Node* parent;
	int avlValue;
/**
 * Public: Node
 * 
 * Description:
 *     Default Constructor
 * 
 * Params:
 *     N/A
 * 
 * Returns:
 *      N/A
*/
	Node() {

	}
/**
 * Public: Node
 * 
 * Description:
 *     Constructor that recieved a struct 
 * 
 * Params:
 *      jsondata d
 * 
 * Returns:
 *      N/A
*/
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
/**
 * IDAVL
 * 
 * Description:
 * 		An AVL tree that uses the ID field of the data as the main key for 
 * 		inseritng and searching.
 * 	
 * Public Methods:
 * 				IDAVL()
 * 				~IDAVL()
 * 		void 	insert(jsondata)
 * 		bool	search(int)
 * 		int 	GetNodes()
 * 		void	dumptree()
 * 
 * Private: 
 * 		
 * 		Node* 	root
 * 		int 	nodechecked;
 * 		int 	avlValue(Node* current)
 * 		void 	computeAvlValues(Node*& current)
 * 		int 	height(Node* current)
 * 		void 	insertNode(Node *&current, Node *&newNode)
 * 		void 	rotateleft(Node *&current)
 * 		void 	rotateright(Ndde*&current)
 * 		bool 	rightheavy(Node* current)
 * 		bool 	leftheavy(Node* current)
 * 		void 	dodumptree(Node* current)
 * 
 * Usage: 
 * 		
 * 		IDAVL List;     //creating list object
 * 		List.insert(data) //adding item to list
 * 		List.search(7432) // searching the list of ID# 7432
 * 		List.GetNodes() // the number of nodes checked to finnd the laast thing
 * 						// searched
 * 		List.dumptree() // displays the tree
 * 
 */
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
/**
 * Public: dumptree
 * 
 * Description
 * 		Used to call the dodumptree private function
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
void IDAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
/**
 * Public: dodumptree
 * 
 * Description
 * 		used to display all the elements in the tree and all their connected nodes
 * 
 * 
 * Param:
 *		Node*  current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: IDAVL
 * 
 * Description
 * 		Default constructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
IDAVL::IDAVL() {
	root = 0;
	nodeschecked = 0;
}
/**
 * Public: IDAVL
 * 
 * Description
 * 		Deconstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
IDAVL :: ~IDAVL() {
}
/**
 * Private: insertNode
 * 
 * Description
 * 		inserts data into the tree
 * 
 * Param:
 *		Node *& 	currrent, 
*		Node *& 	newNode
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: insert
 * 
 * Description
 * 		calls the private insertNode function and compute all the avl values
 * 		and performs the approipriate rotation
 * 
 * Param:
 *		jsondata	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: search
 * 
 * Description
 * 		locates all nodes needed to be checked to locate a piece of data 
 * 
 * Param:
 *		int 	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: height
 * 
 * Description
 * 		calculates the height of the tree 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the height of the tree
 * 
 */
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
/**
 * Private: avlValue
 * 
 * Description
 * 		calculates the avl value of a node 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the avl value
 * 
 */
int IDAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
/**
 * Private: computeAvlValues
 * 
 * Description
 * 		gets the avl values and performs the approipriate
 * 		rotations neccesary
 * 
 * Param:
 *		Node	*&current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateleft
 * 
 * Description
 * 		performs a left rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateright
 * 
 * Description
 * 		performs a right rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: leftheavy
 * 
 * Description
 * 		checks if a tree is scewed more the left
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool IDAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
/**
 * Private: rigthheavy
 * 
 * Description
 * 		checks if a tree is scewed more the right
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool IDAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
/**
 * Public: 	GetNodes
 * 
 * Description
 * 		returns the number of nodes checked to find a node containing
 * 		the last piece of data searched for
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int  : the number of nodes checked
 * 
 */
int IDAVL::GetNodes() {
	return nodeschecked;
}
/**
 * FNAVL
 * 
 * Description:
 * 		An AVL tree that uses the First Name field of the data as the main key for 
 * 		inseritng and searching.
 * 	
 * Public Methods:
 * 				FNAVL()
 * 				~FNAVL()
 * 		void 	insert(jsondata)
 * 		bool	search(int)
 * 		int 	GetNodes()
 * 		void	dumptree()
 * 
 * Private: 
 * 		
 * 		Node* 	root
 * 		int 	nodechecked;
 * 		int 	avlValue(Node* current)
 * 		void 	computeAvlValues(Node*& current)
 * 		int 	height(Node* current)
 * 		void 	insertNode(Node *&current, Node *&newNode)
 * 		void 	rotateleft(Node *&current)
 * 		void 	rotateright(Ndde*&current)
 * 		bool 	rightheavy(Node* current)
 * 		bool 	leftheavy(Node* current)
 * 		void 	dodumptree(Node* current)
 * 
 * Usage: 
 * 		
 * 		FNAVL List;     //creating list object
 * 		List.insert(data) //adding item to list
 * 		List.search("Hailey") // searching the list of first name Hailey
 * 		List.GetNodes() // the number of nodes checked to finnd the laast thing
 * 						// searched
 * 		List.dumptree() // displays the tree
 * 
 */
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
/**
 * Public: dumptree
 * 
 * Description
 * 		Used to call the dodumptree private function
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
void FNAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
/**
 * Public: dodumptree
 * 
 * Description
 * 		used to display all the elements in the tree and all their connected nodes
 * 
 * 
 * Param:
 *		Node*  current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: FNAVL
 * 
 * Description
 * 		Deconstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
FNAVL::FNAVL() {
	root = 0;
	nodeschecked = 0;
}
/**
 * Public: IDAVL
 * 
 * Description
 * 		Deconstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
FNAVL :: ~FNAVL() {
}
/**
 * Private: insertNode
 * 
 * Description
 * 		inserts data into the tree
 * 
 * Param:
 *		Node *& 	currrent, 
*		Node *& 	newNode
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: insert
 * 
 * Description
 * 		calls the private insertNode function and compute all the avl values
 * 		and performs the approipriate rotation
 * 
 * Param:
 *		jsondata	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: search
 * 
 * Description
 * 		locates all nodes needed to be checked to locate a piece of data 
 * 
 * Param:
 *		int 	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: height
 * 
 * Description
 * 		calculates the height of the tree 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the height of the tree
 * 
 */
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
/**
 * Private: avlValue
 * 
 * Description
 * 		calculates the avl value of a node 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the avl value
 * 
 */
int FNAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
/**
 * Private: computeAvlValues
 * 
 * Description
 * 		gets the avl values and performs the approipriate
 * 		rotations neccesary
 * 
 * Param:
 *		Node	*&current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateleft
 * 
 * Description
 * 		performs a left rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateright
 * 
 * Description
 * 		performs a right rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: leftheavy
 * 
 * Description
 * 		checks if a tree is scewed more the left
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool FNAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
/**
 * Private: rigthheavy
 * 
 * Description
 * 		checks if a tree is scewed more the right
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool FNAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
/**
 * Public: 	GetNodes
 * 
 * Description
 * 		returns the number of nodes checked to find a node containing
 * 		the last piece of data searched for
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int  : the number of nodes checked
 * 
 */
int FNAVL::GetNodes() {
	return nodeschecked;
}
/**
 * LNAVL
 * 
 * Description:
 * 		An AVL tree that uses the Last Name field of the data as the main key for 
 * 		inseritng and searching.
 * 	
 * Public Methods:
 * 				LNAVL()
 * 				~LNAVL()
 * 		void 	insert(jsondata)
 * 		bool	search(int)
 * 		int 	GetNodes()
 * 		void	dumptree()
 * 
 * Private: 
 * 		
 * 		Node* 	root
 * 		int 	nodechecked;
 * 		int 	avlValue(Node* current)
 * 		void 	computeAvlValues(Node*& current)
 * 		int 	height(Node* current)
 * 		void 	insertNode(Node *&current, Node *&newNode)
 * 		void 	rotateleft(Node *&current)
 * 		void 	rotateright(Ndde*&current)
 * 		bool 	rightheavy(Node* current)
 * 		bool 	leftheavy(Node* current)
 * 		void 	dodumptree(Node* current)
 * 
 * Usage: 
 * 		
 * 		LNAVL List;     //creating list object
 * 		List.insert(data) //adding item to list
 * 		List.search("Hailey") // searching the list of first name Hailey
 * 		List.GetNodes() // the number of nodes checked to finnd the laast thing
 * 						// searched
 * 		List.dumptree() // displays the tree
 * 
 */
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
/**
 * Public: dumptree
 * 
 * Description
 * 		Used to call the dodumptree private function
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
void LNAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
/**
 * Public: dodumptree
 * 
 * Description
 * 		used to display all the elements in the tree and all their connected nodes
 * 
 * 
 * Param:
 *		Node*  current
 * 
 * Return 
 * 		N/A
 * 
 */
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
}/**
 * Public: LNAVL
 * 
 * Description
 * 		Constructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
LNAVL::LNAVL() {
	root = 0;
	nodeschecked = 0;
}
/**
 * Public: LNAVL
 * 
 * Description
 * 		Deconstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
LNAVL :: ~LNAVL() {
}
/**
 * Private: insertNode
 * 
 * Description
 * 		inserts data into the tree
 * 
 * Param:
 *		Node *& 	currrent, 
*		Node *& 	newNode
 * 
 * Return 
 * 		N/A
 * 
 */

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
/**
 * Public: insert
 * 
 * Description
 * 		calls the private insertNode function and compute all the avl values
 * 		and performs the approipriate rotation
 * 
 * Param:
 *		jsondata	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: search
 * 
 * Description
 * 		locates all nodes needed to be checked to locate a piece of data 
 * 
 * Param:
 *		int 	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: height
 * 
 * Description
 * 		calculates the height of the tree 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the height of the tree
 * 
 */
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
/**
 * Private: avlValue
 * 
 * Description
 * 		calculates the avl value of a node 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the avl value
 * 
 */
int LNAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
/**
 * Private: computeAvlValues
 * 
 * Description
 * 		gets the avl values and performs the approipriate
 * 		rotations neccesary
 * 
 * Param:
 *		Node	*&current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateleft
 * 
 * Description
 * 		performs a left rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateright
 * 
 * Description
 * 		performs a right rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: leftheavy
 * 
 * Description
 * 		checks if a tree is scewed more the left
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool LNAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
/**
 * Private: rigthheavy
 * 
 * Description
 * 		checks if a tree is scewed more the right
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool LNAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
/**
 * Public: 	GetNodes
 * 
 * Description
 * 		returns the number of nodes checked to find a node containing
 * 		the last piece of data searched for
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int  : the number of nodes checked
 * 
 */
int LNAVL::GetNodes() {
	return nodeschecked;
}
/**
 * EMAVL
 * 
 * Description:
 * 		An AVL tree that uses the Email field of the data as the main key for 
 * 		inseritng and searching.
 * 	
 * Public Methods:
 * 				EMAVL()
 * 				~EMAVL()
 * 		void 	insert(jsondata)
 * 		bool	search(int)
 * 		int 	GetNodes()
 * 		void	dumptree()
 * 
 * Private: 
 * 		
 * 		Node* 	root
 * 		int 	nodechecked;
 * 		int 	avlValue(Node* current)
 * 		void 	computeAvlValues(Node*& current)
 * 		int 	height(Node* current)
 * 		void 	insertNode(Node *&current, Node *&newNode)
 * 		void 	rotateleft(Node *&current)
 * 		void 	rotateright(Ndde*&current)
 * 		bool 	rightheavy(Node* current)
 * 		bool 	leftheavy(Node* current)
 * 		void 	dodumptree(Node* current)
 * 
 * Usage: 
 * 		
 * 		EMAVL List;     //creating list object
 * 		List.insert(data) //adding item to list
 * 		List.search("jarettegreene09@gmail.com") // searching the list of Email jarettegreene09@gmail.com
 * 		List.GetNodes() // the number of nodes checked to finnd the laast thing
 * 						// searched
 * 		List.dumptree() // displays the tree
 * 
 */
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
/**
 * Public: dumptree
 * 
 * Description
 * 		Used to call the dodumptree private function
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
void EMAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
/**
 * Public: dodumptree
 * 
 * Description
 * 		used to display all the elements in the tree and all their connected nodes
 * 
 * 
 * Param:
 *		Node*  current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: EMAVL
 * 
 * Description
 * 		Constructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
EMAVL::EMAVL() {
	root = 0;
	nodeschecked = 0;
}
/**
 * Public: EMAVL
 * 
 * Description
 * 		Deconstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
EMAVL :: ~EMAVL() {
}
/**
 * Private: insertNode
 * 
 * Description
 * 		inserts data into the tree
 * 
 * Param:
 *		Node *& 	currrent, 
*		Node *& 	newNode
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: insert
 * 
 * Description
 * 		calls the private insertNode function and compute all the avl values
 * 		and performs the approipriate rotation
 * 
 * Param:
 *		jsondata	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: search
 * 
 * Description
 * 		locates all nodes needed to be checked to locate a piece of data 
 * 
 * Param:
 *		int 	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: height
 * 
 * Description
 * 		calculates the height of the tree 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the height of the tree
 * 
 */
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
/**
 * Private: avlValue
 * 
 * Description
 * 		calculates the avl value of a node 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the avl value
 * 
 */
int EMAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
/**
 * Private: computeAvlValues
 * 
 * Description
 * 		gets the avl values and performs the approipriate
 * 		rotations neccesary
 * 
 * Param:
 *		Node	*&current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateleft
 * 
 * Description
 * 		performs a left rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateright
 * 
 * Description
 * 		performs a right rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: leftheavy
 * 
 * Description
 * 		checks if a tree is scewed more the left
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool EMAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
/**
 * Private: rigthheavy
 * 
 * Description
 * 		checks if a tree is scewed more the right
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool EMAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
/**
 * Public: 	GetNodes
 * 
 * Description
 * 		returns the number of nodes checked to find a node containing
 * 		the last piece of data searched for
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int  : the number of nodes checked
 * 
 */
int EMAVL::GetNodes() {
	return nodeschecked;
}
/**
 * PHAVL
 * 
 * Description:
 * 		An AVL tree that uses the Phone number field of the data as the main key for 
 * 		inseritng and searching.
 * 	
 * Public Methods:
 * 				PHAVL()
 * 				~PHAVL()
 * 		void 	insert(jsondata)
 * 		bool	search(int)
 * 		int 	GetNodes()
 * 		void	dumptree()
 * 
 * Private: 
 * 		
 * 		Node* 	root
 * 		int 	nodechecked;
 * 		int 	avlValue(Node* current)
 * 		void 	computeAvlValues(Node*& current)
 * 		int 	height(Node* current)
 * 		void 	insertNode(Node *&current, Node *&newNode)
 * 		void 	rotateleft(Node *&current)
 * 		void 	rotateright(Ndde*&current)
 * 		bool 	rightheavy(Node* current)
 * 		bool 	leftheavy(Node* current)
 * 		void 	dodumptree(Node* current)
 * 
 * Usage: 
 * 		
 * 		PHAVL List;     //creating list object
 * 		List.insert(data) //adding item to list
 * 		List.search("(940) 7421213") // searching the list of Phone Number (940) 7421213
 * 		List.GetNodes() // the number of nodes checked to finnd the laast thing
 * 						// searched
 * 		List.dumptree() // displays the tree
 * 
 */
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
/**
 * Public: dumptree
 * 
 * Description
 * 		Used to call the dodumptree private function
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
void PHAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
/**
 * Public: dodumptree
 * 
 * Description
 * 		used to display all the elements in the tree and all their connected nodes
 * 
 * 
 * Param:
 *		Node*  current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: PHAVL
 * 
 * Description
 * 		Constructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
PHAVL::PHAVL() {
	root = 0;
	nodeschecked = 0;
}
/**
 * Public: PHAVL
 * 
 * Description
 * 		Deconstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
PHAVL :: ~PHAVL() {
}
/**
 * Private: insertNode
 * 
 * Description
 * 		inserts data into the tree
 * 
 * Param:
 *		Node *& 	currrent, 
*		Node *& 	newNode
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: insert
 * 
 * Description
 * 		calls the private insertNode function and compute all the avl values
 * 		and performs the approipriate rotation
 * 
 * Param:
 *		jsondata	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: search
 * 
 * Description
 * 		locates all nodes needed to be checked to locate a piece of data 
 * 
 * Param:
 *		int 	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: height
 * 
 * Description
 * 		calculates the height of the tree 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the height of the tree
 * 
 */
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
/**
 * Private: avlValue
 * 
 * Description
 * 		calculates the avl value of a node 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the avl value
 * 
 */
int PHAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
/**
 * Private: computeAvlValues
 * 
 * Description
 * 		gets the avl values and performs the approipriate
 * 		rotations neccesary
 * 
 * Param:
 *		Node	*&current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateleft
 * 
 * Description
 * 		performs a left rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateright
 * 
 * Description
 * 		performs a right rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: leftheavy
 * 
 * Description
 * 		checks if a tree is scewed more the left
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool PHAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
/**
 * Private: rigthheavy
 * 
 * Description
 * 		checks if a tree is scewed more the right
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool PHAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
/**
 * Public: 	GetNodes
 * 
 * Description
 * 		returns the number of nodes checked to find a node containing
 * 		the last piece of data searched for
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int  : the number of nodes checked
 * 
 */
int PHAVL::GetNodes() {
	return nodeschecked;
}
/**
 * ADAVL
 * 
 * Description:
 * 		An AVL tree that uses the Address field of the data as the main key for 
 * 		inseritng and searching.
 * 	
 * Public Methods:
 * 				ADAVL()
 * 				~ADAVL()
 * 		void 	insert(jsondata)
 * 		bool	search(int)
 * 		int 	GetNodes()
 * 		void	dumptree()
 * 
 * Private: 
 * 		
 * 		Node* 	root
 * 		int 	nodechecked;
 * 		int 	avlValue(Node* current)
 * 		void 	computeAvlValues(Node*& current)
 * 		int 	height(Node* current)
 * 		void 	insertNode(Node *&current, Node *&newNode)
 * 		void 	rotateleft(Node *&current)
 * 		void 	rotateright(Ndde*&current)
 * 		bool 	rightheavy(Node* current)
 * 		bool 	leftheavy(Node* current)
 * 		void 	dodumptree(Node* current)
 * 
 * Usage: 
 * 		
 * 		ADAVL List;     //creating list object
 * 		List.insert(data) //adding item to list
 * 		List.search("Comanche Suite") // searching the list of Address Comanche Suite
 * 		List.GetNodes() // the number of nodes checked to finnd the laast thing
 * 						// searched
 * 		List.dumptree() // displays the tree
 * 
 */
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
/**
 * Public: dumptree
 * 
 * Description
 * 		Used to call the dodumptree private function
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
void ADAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
/**
 * Public: dodumptree
 * 
 * Description
 * 		used to display all the elements in the tree and all their connected nodes
 * 
 * 
 * Param:
 *		Node*  current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: ADAVL
 * 
 * Description
 * 		Constructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
ADAVL::ADAVL() {
	root = 0;
	nodeschecked = 0;
}
/**
 * Public: ADAVL
 * 
 * Description
 * 		DeConstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
ADAVL :: ~ADAVL() {
}
/**
 * Private: insertNode
 * 
 * Description
 * 		inserts data into the tree
 * 
 * Param:
 *		Node *& 	currrent, 
*		Node *& 	newNode
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: insert
 * 
 * Description
 * 		calls the private insertNode function and compute all the avl values
 * 		and performs the approipriate rotation
 * 
 * Param:
 *		jsondata	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: search
 * 
 * Description
 * 		locates all nodes needed to be checked to locate a piece of data 
 * 
 * Param:
 *		int 	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: height
 * 
 * Description
 * 		calculates the height of the tree 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the height of the tree
 * 
 */
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
/**
 * Private: avlValue
 * 
 * Description
 * 		calculates the avl value of a node 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the avl value
 * 
 */
int ADAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
/**
 * Private: computeAvlValues
 * 
 * Description
 * 		gets the avl values and performs the approipriate
 * 		rotations neccesary
 * 
 * Param:
 *		Node	*&current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateleft
 * 
 * Description
 * 		performs a left rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateright
 * 
 * Description
 * 		performs a right rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: leftheavy
 * 
 * Description
 * 		checks if a tree is scewed more the left
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool ADAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
/**
 * Private: rigthheavy
 * 
 * Description
 * 		checks if a tree is scewed more the right
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool ADAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
/**
 * Public: 	GetNodes
 * 
 * Description
 * 		returns the number of nodes checked to find a node containing
 * 		the last piece of data searched for
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int  : the number of nodes checked
 * 
 */
int ADAVL::GetNodes() {
	return nodeschecked;
}
/**
 * JTAVL
 * 
 * Description:
 * 		An AVL tree that uses the Job Title field of the data as the main key for 
 * 		inseritng and searching.
 * 	
 * Public Methods:
 * 				JTAVL()
 * 				~JTAVL()
 * 		void 	insert(jsondata)
 * 		bool	search(int)
 * 		int 	GetNodes()
 * 		void	dumptree()
 * 
 * Private: 
 * 		
 * 		Node* 	root
 * 		int 	nodechecked;
 * 		int 	avlValue(Node* current)
 * 		void 	computeAvlValues(Node*& current)
 * 		int 	height(Node* current)
 * 		void 	insertNode(Node *&current, Node *&newNode)
 * 		void 	rotateleft(Node *&current)
 * 		void 	rotateright(Ndde*&current)
 * 		bool 	rightheavy(Node* current)
 * 		bool 	leftheavy(Node* current)
 * 		void 	dodumptree(Node* current)
 * 
 * Usage: 
 * 		
 * 		JTAVL List;     //creating list object
 * 		List.insert(data) //adding item to list
 * 		List.search("Manager") // searching the list of Job Title Manager
 * 		List.GetNodes() // the number of nodes checked to finnd the laast thing
 * 						// searched
 * 		List.dumptree() // displays the tree
 * 
 */
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
/**
 * Public: dumptree
 * 
 * Description
 * 		Used to call the dodumptree private function
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
void JTAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
/**
 * Public: dodumptree
 * 
 * Description
 * 		used to display all the elements in the tree and all their connected nodes
 * 
 * 
 * Param:
 *		Node*  current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: JTAVL
 * 
 * Description
 * 		Constructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
JTAVL::JTAVL() {
	root = 0;
	nodeschecked = 0;
}
/**
 * Public: JTAVL
 * 
 * Description
 * 		DeConstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
JTAVL :: ~JTAVL() {
}
/**
 * Private: insertNode
 * 
 * Description
 * 		inserts data into the tree
 * 
 * Param:
 *		Node *& 	currrent, 
*		Node *& 	newNode
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: insert
 * 
 * Description
 * 		calls the private insertNode function and compute all the avl values
 * 		and performs the approipriate rotation
 * 
 * Param:
 *		jsondata	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: search
 * 
 * Description
 * 		locates all nodes needed to be checked to locate a piece of data 
 * 
 * Param:
 *		int 	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: height
 * 
 * Description
 * 		calculates the height of the tree 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the height of the tree
 * 
 */
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
/**
 * Private: avlValue
 * 
 * Description
 * 		calculates the avl value of a node 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the avl value
 * 
 */
int JTAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
/**
 * Private: computeAvlValues
 * 
 * Description
 * 		gets the avl values and performs the approipriate
 * 		rotations neccesary
 * 
 * Param:
 *		Node	*&current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateleft
 * 
 * Description
 * 		performs a left rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateright
 * 
 * Description
 * 		performs a right rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: leftheavy
 * 
 * Description
 * 		checks if a tree is scewed more the left
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool JTAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
/**
 * Private: rigthheavy
 * 
 * Description
 * 		checks if a tree is scewed more the right
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool JTAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
/**
 * Public: 	GetNodes
 * 
 * Description
 * 		returns the number of nodes checked to find a node containing
 * 		the last piece of data searched for
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int  : the number of nodes checked
 * 
 */
int JTAVL::GetNodes() {
	return nodeschecked;
}
/**
 * CMAVL
 * 
 * Description:
 * 		An AVL tree that uses the Car Model field of the data as the main key for 
 * 		inseritng and searching.
 * 	
 * Public Methods:
 * 				CMAVL()
 * 				~CMAVL()
 * 		void 	insert(jsondata)
 * 		bool	search(int)
 * 		int 	GetNodes()
 * 		void	dumptree()
 * 
 * Private: 
 * 		
 * 		Node* 	root
 * 		int 	nodechecked;
 * 		int 	avlValue(Node* current)
 * 		void 	computeAvlValues(Node*& current)
 * 		int 	height(Node* current)
 * 		void 	insertNode(Node *&current, Node *&newNode)
 * 		void 	rotateleft(Node *&current)
 * 		void 	rotateright(Ndde*&current)
 * 		bool 	rightheavy(Node* current)
 * 		bool 	leftheavy(Node* current)
 * 		void 	dodumptree(Node* current)
 * 
 * Usage: 
 * 		
 * 		CMAVL List;     //creating list object
 * 		List.insert(data) //adding item to list
 * 		List.search("Mercedes") // searching the list of Car Model Mercedes
 * 		List.GetNodes() // the number of nodes checked to finnd the laast thing
 * 						// searched
 * 		List.dumptree() // displays the tree
 * 
 */
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
/**
 * Public: dumptree
 * 
 * Description
 * 		Used to call the dodumptree private function
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
void CMAVL::dumptree() {
	cout << "---------------------------------" << endl;
	cout << "Root:   " << root << "\n";
	dodumptree(root);
}
/**
 * Public: dodumptree
 * 
 * Description
 * 		used to display all the elements in the tree and all their connected nodes
 * 
 * 
 * Param:
 *		Node*  current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: CMAVL
 * 
 * Description
 * 		Constructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
CMAVL::CMAVL() {
	root = 0;
	nodeschecked = 0;
}

/**
 * Public: CMAVL
 * 
 * Description
 * 		DeConstructor
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
CMAVL :: ~CMAVL() {
}
/**
 * Private: insertNode
 * 
 * Description
 * 		inserts data into the tree
 * 
 * Param:
 *		Node *& 	currrent, 
*		Node *& 	newNode
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: insert
 * 
 * Description
 * 		calls the private insertNode function and compute all the avl values
 * 		and performs the approipriate rotation
 * 
 * Param:
 *		jsondata	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: search
 * 
 * Description
 * 		locates all nodes needed to be checked to locate a piece of data 
 * 
 * Param:
 *		int 	data
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: height
 * 
 * Description
 * 		calculates the height of the tree 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the height of the tree
 * 
 */
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
/**
 * Private: avlValue
 * 
 * Description
 * 		calculates the avl value of a node 
 * 
 * Param:
 *		Node* 	current
 * 
 * Return 
 * 		int	 : 	the avl value
 * 
 */
int CMAVL::avlValue(Node* current) {
	return height(current->right) - height(current->left);
}
/**
 * Private: computeAvlValues
 * 
 * Description
 * 		gets the avl values and performs the approipriate
 * 		rotations neccesary
 * 
 * Param:
 *		Node	*&current
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateleft
 * 
 * Description
 * 		performs a left rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: rotateright
 * 
 * Description
 * 		performs a right rotation on a given node
 * 
 * Param:
 *		Node	*&Subroot
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Private: leftheavy
 * 
 * Description
 * 		checks if a tree is scewed more the left
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool CMAVL::lefftheavy(Node* current) {
	return height(current->left) > height(current->right);
}
/**
 * Private: rigthheavy
 * 
 * Description
 * 		checks if a tree is scewed more the right
 * 
 * Param:
 *		Node	*current
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
bool CMAVL::rightheavy(Node* current) {
	return height(current->right) > height(current->left);
}
/**
 * Public: 	GetNodes
 * 
 * Description
 * 		returns the number of nodes checked to find a node containing
 * 		the last piece of data searched for
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int  : the number of nodes checked
 * 
 */
int CMAVL::GetNodes() {
	return nodeschecked;
}
/**
 * CMAVL
 * 
 * Description:
 * 		Class that contains 8 different AVL trees and allows easy access to add and search for
 * 		elements in every list based on the data entered
 * 	
 * Public Methods:
 * 					Database (vector<jsondata>data) 
 * 					~Database()
 * 			bool	FindID(int data) 
 *			int 	GetIDnodes() 
 *			bool 	FindFN(string data) 
 *			int 	GetFNnodes() 
 * 			bool 	FindLN(string data) 
 *			int 	GetLNnodes() 
 *			bool 	FindEM(string data) 
 *			int 	GetEMnodes()
 *			bool 	FindPH(string data) 
 *			int 	GetPHnodes() 
 *			bool 	FindAD(string data) 
 *			int 	GetADnodes() 
 *			bool 	FindJT(string data) 
 *			int 	GetJTnodes() 
 *			bool 	FindCM(string data) 
 *			int 	GetCMnodes()
 * 
 * Private: 
 * 		
 * 		IDAVL	List1
 * 		FNAVL	List2
 * 		LNAVL	List3
 * 		EMAVL	List4
 * 		PHAVL	List5
 * 		ADAVL	List6
 * 		JTAVL	List7
 * 		CMAVL	List8
 * 
 * Usage: 
 * 		
 * 		Database Dbase(data) //loads database
 * 		Dbase.FindID(123) //locates the ID# 123 inside the database
 * 		Dbase.GetIDNodes() // displays the amount of nodes needed to find the last thing searched
 * 		Dbase.Insert(data) //inserts data into the databse
 * 
 */
class Database {
private:
	IDAVL List1; // ID based AVL Tree
	FNAVL List2; //First name based AVL Tree 
	LNAVL List3; // Last Name based AVL Tree
	EMAVL List4; // Email based AVL Tree 
	PHAVL List5; //Phone number based AVL tree
	ADAVL List6; //Address based AVL tree	
	JTAVL List7; // Job Title based AVL tree	
	CMAVL List8; //Car Model based AVL tree
public:
/**
 * Public: Database
 * 
 * Description
 * 		constructor that accepts a vector of items and loads it into the Database
 * 
 * Param:
 *		vector <jsondata> 
 * 
 * Return 
 * 		N/A
 * 
 */
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
/**
 * Public: Database
 * 
 * Description
 * 		Deconstructor 
 * 
 * Param:
 *		vector <jsondata> 
 * 
 * Return 
 * 		N/A
 * 
 */
	~Database() {

	}
/**
 * Public: FindID
 * 
 * Description
 * 		Locates the ID# passed in to the function inside the list
 * 
 * Param:
 *		int		data
 * 
 * Return 
 * 		bool  : true or false
 * 
 */
	bool FindID(int data) { return List1.search(data); }
/**
 * Public: GetIDnodes
 * 
 * Description
 * 		gets the number of nodes that have to checked to to find the 
 * 		last ID searched
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int	: the number of nodes checked 
 * 
 */
	int GetIDnodes() { return List1.GetNodes(); }
/**
 * Public: FindFN
 * 
 * Description
 * 		Locates the First name passed in to the function inside the list
 * 
 * Param:
 *		string		data
 * 
 * Return 
 * 		bool:  true or false
 * 
 */
	bool FindFN(string data) { return List2.search(data); }
/**
 * Public: GetFNnodes
 * 
 * Description
 * 		gets the number of nodes that have to checked to to find the 
 * 		last First Name searched
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int	: the number of nodes checked 
 * 
 */
	int GetFNnodes() { return List2.GetNodes(); }
/**
 * Public: FindLN
 * 
 * Description
 * 		Locates the Last name passed in to the function inside the list
 * 
 * Param:
 *		string		data
 * 
 * Return 
 * 		bool:  true or false
 * 
 */
	bool FindLN(string data) { return List3.search(data); }
/**
 * Public: GetLNnodes
 * 
 * Description
 * 		gets the number of nodes that have to checked to to find the 
 * 		last Last Name searched
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int	: the number of nodes checked 
 * 
 */
	int GetLNnodes() { return List3.GetNodes(); }
/**
 * Public: FindEM
 * 
 * Description
 * 		Locates the Email passed in to the function inside the list
 * 
 * Param:
 *		string		data
 * 
 * Return 
 * 		bool:  true or false
 * 
 */
	bool FindEM(string data) { return List4.search(data); }
/**
 * Public: GetEMnodes
 * 
 * Description
 * 		gets the number of nodes that have to checked to to find the 
 * 		last Email searched
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int	: the number of nodes checked 
 * 
 */
	int GetEMnodes() { return List4.GetNodes(); }
/**
 * Public: FindPH
 * 
 * Description
 * 		Locates the phone number passed in to the function inside the list
 * 
 * Param:
 *		string		data
 * 
 * Return 
 * 		bool:  true or false
 * 
 */
	bool FindPH(string data) { return List5.search(data); }
/**
 * Public: GetPHnodes
 * 
 * Description
 * 		gets the number of nodes that have to checked to to find the 
 * 		last Phone Number searched
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int	: the number of nodes checked 
 * 
 */
	int GetPHnodes() { return List5.GetNodes(); }
/**
 * Public: FindAD
 * 
 * Description
 * 		Locates the address passed in to the function inside the list
 * 
 * Param:
 *		string		data
 * 
 * Return 
 * 		bool:  true or false
 * 
 */
	bool FindAD(string data) { return List6.search(data); }
/**
 * Public: GetADnodes
 * 
 * Description
 * 		gets the number of nodes that have to checked to to find the 
 * 		last Address searched
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int	: the number of nodes checked 
 * 
 */
	int GetADnodes() { return List6.GetNodes(); }
/**
 * Public: FindJT
 * 
 * Description
 * 		Locates the Job Title passed in to the function inside the list
 * 
 * Param:
 *		string		data
 * 
 * Return 
 * 		bool:  true or false
 * 
 */
	bool FindJT(string data) { return List7.search(data); }
/**
 * Public: GetJTnodes
 * 
 * Description
 * 		gets the number of nodes that have to checked to to find the 
 * 		last Job Title searched
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int	: the number of nodes checked 
 * 
 */
	int GetJTnodes() { return List7.GetNodes(); }
/**
 * Public: FindCM
 * 
 * Description
 * 		Locates the Car Model passed in to the function inside the list
 * 
 * Param:
 *		string		data
 * 
 * Return 
 * 		bool:  true or false
 * 
 */
	bool FindCM(string data) { return List8.search(data); }
/**
 * Public: GetCMnodes
 * 
 * Description
 * 		gets the number of nodes that have to checked to to find the 
 * 		last Car Model searched
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		int	: the number of nodes checked 
 * 
 */
	int GetCMnodes() { return List8.GetNodes(); }
/**
 * Public:	Inserts
 * 
 * Description
 * 		Adds data to the database
 * 
 * Param:
 *		N/A
 * 
 * Return 
 * 		N/A
 * 
 */
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

