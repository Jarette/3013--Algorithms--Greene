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
*        (ID, First Name, Last Name, Email, Phone, Address, Longitude, Latitude and 
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
// neccesary Libraries
#include <fstream>
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
  string fname;
  string lname;
  string email;
  string phone;
  string address;
  double longitude;
  double latitude;
  string carmodel;
  string city;
  string state;
  string car;
  string carcolor;
  string pet;
  string jobtitle;
  string favoritemovie;
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
jsondata(){
  id = -1;
  longitude = -1;
  latitude = -1;
  fname = "Null";
  lname = "Null";
  email = "Null";
  phone = "Null";
  address = "Null";
  carmodel = "Null";
  city = "Null";
  state = "Null";
  car = "Null";
  carcolor="Null";
  pet = "Null";
  jobtitle = "Null";
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
void display(){
  cout << "ID#: " << id;
    cout << endl;
    cout << "First Name: " <<fname;
    cout << endl;
    cout << "Last Name: " <<lname;
    cout << endl;
    cout << "Email: " <<email;
    cout << endl;
   cout << "Phone number: " <<phone;
   cout << endl;
  cout << "Address: " << address;
  cout << endl;
  cout << "City: " << city;
  cout << endl;
  cout << "State: " << state;
  cout << endl;
  cout << "Longitude: " << longitude;
  cout << endl;
  cout << "Latitude: " << latitude;
  cout << endl;
  cout << "Car: " << car;
  cout << endl;
  cout << "Car Model: " << carmodel;
  cout << endl;
  cout << "Car Color: " << carcolor;
  cout << endl;
  cout << "Job Title: " << jobtitle;
  cout << endl;
  cout << "Pet: " << pet;
  cout << endl;
  cout << "Favorite Movie: " << favoritemovie;
  cout << endl;
  cout << "Stocks: ";
  cout << endl;
  for(int i = 0;i < stocks.size();i++){
     cout << "      " << stocks[i];
    cout << endl;
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
  Node *left;
  Node *right;
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
  
    left = right = nullptr; // initilizing the left right pointers 

    // initilizing the rest of the data to the data passed in 
    data.id = d.id;
    data.fname = d.fname;
    data.lname = d.lname;
    data.email = d.email;
    data.phone = d.phone;
    data.address = d.address;
    data.longitude = d.longitude;
    data.latitude = d.latitude;
    data.carmodel = d.carmodel;
    data.car = d.carmodel;
    data.carcolor = d.carcolor;
    data.jobtitle = d.jobtitle;
    data.pet = d.pet;
    data.city = d.city;
    data.state = d.state;
    for(int i = 0;i<d.stocks.size();i++){
      data.stocks.push_back(d.stocks[i]);
    }
  }
};
/**
 * IDBST
 * 
 * Description:
 *      A binary search tree that uses the ID field of the data
 *      as the main key used to search, sort and delete data
 * 
 * Public Methods:
 *           IDBST()                
 *   void    insert(jsondata data)  
 *   void    print()                 
 *   Node*   remove(int data)        
 *   int     height()                 
 *   bool    founddata(int data)    
 *   int     getnodeschecked()    
 * 
 * Private Methods:
 *   void      print(Node *root)      
 *   void      insert(json data, Node *&root)   
 *   Node      *findmin(Node*root)              
 *   Node      *remove(int data, Noderoot)      
 *   int       height()                        
 *   jsondata  findnode(int id, Node*root)     
 *   bool      founddata(string data, Node*root) 
 *        
 * 
 * Usage: 
 * 
 *      IDBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata(1)  //located where the the ID #1 is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class IDBST {
private:
  Node *root;         // the root/head of the tree
  int nodeschecked;   // the nodes checked to find a specfic piece of data 

   /**
     * Private : print
     * 
     * Description:
     *      used to print the data stored in the tree 
     * 
     * Params:
     *      Node   *root   //root of the tree 
     * 
     * Returns:
     *     N/A
     */
  void print(Node *root) {
    if (!root) {
      return;
    }
    print(root->left);
    root->data.display();  // inorder traversal
    print(root->right);
  }
  /**
     * Private : insert
     * 
     * Description:
     *      puts data into the tree 
     * 
     * Params:
     *      Node      *root   //root of the tree 
     *      jsondata  data    // data to be inserted 
     * 
     * Returns:
     *     N/A
     */
  void insert(jsondata data, Node *&root) {
    if (!root) {
      root = new Node(data);
      return;
    }
    if (data.id < root->data.id) {  //trverses left if the data is smaller than node data
      insert(data, root->left);     // right if the data is greater than node data
    } else {
      insert(data, root->right);
    }
  }
  /**
     * Private : findmin
     * 
     * Description:
     *     finds the smallest node in a tree
     * 
     * Params:
     *      Node   *root   //root of the tree 
     * 
     * Returns:
     *     Node*   : pointer to a node 
     */
  Node *findmin(Node *root) {
    Node *temp = root;
    while (temp->left != nullptr) { //traverseing left until it gets to last node
      temp = temp->left;
    }
    return temp;    //returning the node with the smallest data 
  }
  /**
     * Private : removes
     * 
     * Description:
     *     removes node from tree that contains specfied data 
     * 
     * Params:
     *      Node   *root   //root of the tree 
     *      int     data   // the data being looked for 
     * 
     * Returns:
     *     Node*   : pointer to a node 
     */
  Node *remove(int data, Node *root) {
    if (root == nullptr) {
      return nullptr;
    }
    if (data < root->data.id) {
      root->left = remove(data, root->left);
    } else if (data > root->data.id) {
      root->right = remove(data, root->right);
    } else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      } else if (root->left == nullptr) {
        Node *temp = root->right;
        delete root;
        return temp;
      } else if (root->right == nullptr) {
        Node *temp = root->left;
        delete root;
        return temp;
      } else {
        Node *minNode = findmin(root->right);
        root->data = minNode->data;
        root->right = remove(minNode->data.id, root->right);
      }
    }
    return root;
  }
/**
* Private : height
* 
* Description:
*    finds the height of the tree 
* 
* Params:
*      Node   *root   //root of the tree 
* 
* Returns:
*     int   : the height of the tree
*/
  int height(Node *root) {
    if (!root) {
      return 0;
    }
    return 1 + max(height(root->left), height(root->right));
  }
 /**
* Private : findnode
* 
* Description:
*   used to find a node and get the data from it 
* 
* Params:
*      Node   *root   //root of the tree 
*     int     data  //the data being searched for 
* 
* Returns:
*     jsondata   : the stored in the found node 
*/
  jsondata findnode(int id, Node*root){
    jsondata temp;
    if(!root){
      return temp;
    }
    if(root->data.id ==id){
      return root->data;
    }
    else if(id < root->data.id){
      return findnode(id,root->left);
    }else{
      return findnode(id,root->right);
    }
  }
  /**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
* 
* Returns:
*     int   : the height of the tree
*/
  bool founddata(int id, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.id ==id){
      return true;
    }
    else if(id < root->data.id){
      return founddata(id,root->left);
    }else{
      return founddata(id,root->right);
    }
    return false;
    }
  }

public:
  /**
* Public : IDBST
* 
* Description:
*   Defaut Constructor
* 
* Params:
*     N/A
* 
* Returns:
*    N/A
*/
  IDBST() { root = nullptr; }
  /**
* Public : insert
* 
* Description:
*   calls private insert
* 
* Params:
*     jsondata    data // the data to be added
* 
* Returns:
*    N/A
*/
  void insert(jsondata data) { insert(data, root); }
/**
* Public : print
* 
* Description:
*   calls private print
* 
* Params:
*    N/A
* 
* Returns:
*    N/A
*/
  void print() { print(root); }
  /**
* Public : remove
* 
* Description:
*   calls private remove
* 
* Params:
*    int      data  // data to b searched for 
* 
* Returns:
*    Node* :  Node to be removed
*/
  Node *remove(int data) { return remove(data, root); }
  /**
* Public : height
* 
* Description:
*   calls private height
* 
* Params:
*    N/A
* 
* Returns:
*    int    :  height of tree
*/
  int height() { return height(root); }
  /**
* Public : founddata
* 
* Description:
*   calls private founddata
* 
* Params:
*    int    data  //data being searched for 
* 
* Returns:
*    bool    :  true or false based on if data is found
*/
  bool founddata(int data){nodeschecked = 0; return founddata(data,root);}
  /**
* Public : getnodeschecked
* 
* Description:
*   gets the number of nodes needed to be checked to find data
* 
* Params:
*    N/A
* 
* Returns:
*    int     : the number of nodes cecked
*/
  int getnodeschecked(){return nodeschecked;}
};
/**
 * FNBST
 * 
 * Description:
 *      A binary search tree that uses the First Name field of the data
 *      as the main key used to search, sort and delete data
 * 
 * Public Methods:
 *           FNBST()                
 *   void    insert(jsondata data)  
 *   void    print()                 
 *   Node*   remove(string data)        
 *   int     height()                 
 *   bool    founddata(string data)    
 *   int     getnodeschecked()    
 * 
 * Private Methods:
 *   void      print(Node *root)      
 *   void      insert(json data, Node *&root)   
 *   Node      *findmin(Node*root)              
 *   Node      *remove(string data, Noderoot)      
 *   int       height()                        
 *   jsondata  findnode(string data, Node*root)     
 *   bool      founddata(string data, Node*root) 
 *        
 * 
 * Usage: 
 * 
 *      FNBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata("Jane")  //located where the the first name Jane is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class FNBST{
private:
Node*root;    //root of tree
int nodeschecked;  // the number of nodes checked to find data
/**
     * Private : print
     * 
     * Description:
     *      used to print the data stored in the tree 
     * 
     * Params:
     *      Node   *root   //root of the tree 
     * 
     * Returns:
     *     N/A
     */
void print(Node*root){
  if(!root){
    return;
 }
  print(root->left);
 root->data.display();
  print(root -> right);
  
}
 /**
* Private : insert
* 
* Description:
*      puts data into the tree 
* 
* Params:
*      Node      *root   //root of the tree 
*      jsondata  data    // data to be inserted 
* 
* Returns:
*     N/A
*/
void insert(jsondata data, Node*&root){
 
  if(!root){
    root = new Node(data);
    return;
  }
  if (data.fname < root->data.fname){
    insert(data,root->left);
  }else{
    insert(data,root->right);
  }
}
/**
* Private : findmin
* 
* Description:
*     finds the smallest node in a tree
* 
* Params:
*      Node   *root   //root of the tree 
* 
* Returns:
*     Node*   : pointer to a node 
*/
Node* findmin(Node*root){
  Node*temp=root;
  while(temp->left!=nullptr){
    temp = temp->left;
  }
  return temp;
}
/**
* Private : removes
* 
* Description:
*     removes node from tree that contains specfied data 
* 
* Params:
*      Node   *root   //root of the tree 
*      string    data   // the data being looked for 
* 
* Returns:
*     Node*   : pointer to a node 
*/
Node *remove(string data, Node *root){
  int index=0;
  if(root == nullptr){
    return nullptr;
  }
  if(data < root->data.fname){
    root->left = remove(data,root->left);
  }
  else if(data>root->data.fname){
    root->right = remove(data,root->right);
  }
  else{
    if(root->left == nullptr && root->right == nullptr){
      delete root;
      return nullptr;
    }
    else if(root->left == nullptr){
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == nullptr){
      Node*temp = root->left;
      delete root;
      return temp;
    }
    else{
      Node*minNode = findmin(root->right);
      root->data = minNode->data;
      root->right = remove(minNode->data.fname,root->right);
    }
  }
  return root;
}
/**
* Private : height
* 
* Description:
*    finds the height of the tree 
* 
* Params:
*      Node   *root   //root of the tree 
* 
* Returns:
*     int   : the height of the tree
*/
int height(Node*root){
  if(!root){
    return 0;
  }
  return 1+max(height(root->left),height(root->right));
}
/**
* Private : findnode
* 
* Description:
*   used to find a node and get the data from it 
* 
* Params:
*      Node   *root   //root of the tree 
*     string    data  //the data being searched for 
* 
* Returns:
*     jsondata   : the stored in the found node 
*/
jsondata findnode(string data,Node*root){
  jsondata temp;
  if(!root){
    return temp;
  }
  if(root->data.fname == data){
    return root->data;
  }
  else if(data<root->data.fname){
    return findnode(data,root->left);
  }
  else{
    return findnode(data,root->right);
  }
}
  /**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
* 
* Returns:
*     int   : the height of the tree
*/
bool founddata(string data, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.fname ==data){
      return true;
    }
    else if(data < root->data.fname){
      return founddata(data,root->left);
    }else{
      return founddata(data,root->right);
    }
    return false;
    }
  }
public:
  /**
* Public : FNBST
* 
* Description:
*   Defaut Constructor
* 
* Params:
*     N/A
* 
* Returns:
*    N/A
*/
FNBST(){root = nullptr;}
 /**
* Public : insert
* 
* Description:
*   calls private insert
* 
* Params:
*     jsondata    data // the data to be added
* 
* Returns:
*    N/A
*/
void insert(jsondata data){insert(data,root);}
/**
* Public : print
* 
* Description:
*   calls private print
* 
* Params:
*    N/A
* 
* Returns:
*    N/A
*/
void print(){print(root);}
/**
* Public : remove
* 
* Description:
*   calls private remove
* 
* Params:
*    string      data  // data to be searched for 
* 
* Returns:
*    Node* :  Node to be removed
*/
Node *remove(string data){return remove(data,root);}
 /**
* Public : height
* 
* Description:
*   calls private height
* 
* Params:
*    N/A
* 
* Returns:
*    int    :  height of tree
*/
int height(){return height(root);}
 /**
* Public : founddata
* 
* Description:
*   calls private founddata
* 
* Params:
*    string   data  //data being searched for 
* 
* Returns:
*    bool    :  true or false based on if data is found
*/
bool founddata(string data){nodeschecked = 0; return founddata(data,root);}
/**
* Public : getnodeschecked
* 
* Description:
*   gets the number of nodes needed to be checked to find data
* 
* Params:
*    N/A
* 
* Returns:
*    int     : the number of nodes cecked
*/
int getnodeschecked(){return nodeschecked;}
};
/**
 * FNBST
 * 
 * Description:
 *      A binary search tree that uses the last Name field of the data
 *      as the main key used to search, sort and delete data
 * 
 * Public Methods:
 *           LNBST()                
 *   void    insert(jsondata data)  
 *   void    print()                 
 *   Node*   remove(string data)        
 *   int     height()                 
 *   bool    founddata(string data)    
 *   int     getnodeschecked()    
 * 
 * Private Methods:
 *   void      print(Node *root)      
 *   void      insert(json data, Node *&root)   
 *   Node      *findmin(Node*root)              
 *   Node      *remove(string data, Noderoot)      
 *   int       height()                        
 *   jsondata  findnode(string data, Node*root)     
 *   bool      founddata(string data, Node*root) 
 *        
 * 
 * Usage: 
 * 
 *      FNBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata("jones")  //located where the the last name Jane is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class LNBST{
private:
Node*root;        // root of tree
int nodeschecked;  // holds the number of nodes checked to find data
/**
     * Private : print
     * 
     * Description:
     *      used to print the data stored in the tree 
     * 
     * Params:
     *      Node   *root   //root of the tree 
     * 
     * Returns:
     *     N/A
     */
void print(Node*root){
  if(!root){
    return;
 }
  print(root->left);
 root->data.display();
  print(root -> right);
  
}
 /**
* Private : insert
* 
* Description:
*      puts data into the tree 
* 
* Params:
*      Node      *root   //root of the tree 
*      jsondata  data    // data to be inserted 
* 
* Returns:
*     N/A
*/
void insert(jsondata data, Node*&root){
 
  if(!root){
    root = new Node(data);
    return;
  }
  if (data.lname < root->data.lname){
    insert(data,root->left);
  }else{
    insert(data,root->right);
  }
}
/**
* Private : findmin
* 
* Description:
*     finds the smallest node in a tree
* 
* Params:
*      Node   *root   //root of the tree 
* 
* Returns:
*     Node*   : pointer to a node 
*/
Node* findmin(Node*root){
  Node*temp=root;
  while(temp->left!=nullptr){
    temp = temp->left;
  }
  return temp;
}
/**
* Private : removes
* 
* Description:
*     removes node from tree that contains specfied data 
* 
* Params:
*      Node   *root   //root of the tree 
*      string    data   // the data being looked for 
* 
* Returns:
*     Node*   : pointer to a node 
*/
Node *remove(string data, Node *root){
  int index=0;
  if(root == nullptr){
    return nullptr;
  }
  if(data < root->data.lname){
    root->left = remove(data,root->left);
  }
  else if(data>root->data.lname){
    root->right = remove(data,root->right);
  }
  else{
    if(root->left == nullptr && root->right == nullptr){
      delete root;
      return nullptr;
    }
    else if(root->left == nullptr){
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == nullptr){
      Node*temp = root->left;
      delete root;
      return temp;
    }
    else{
      Node*minNode = findmin(root->right);
      root->data = minNode->data;
      root->right = remove(minNode->data.lname,root->right);
    }
  }
  return root;
}
/**
* Private : height
* 
* Description:
*    finds the height of the tree 
* 
* Params:
*      Node   *root   //root of the tree 
* 
* Returns:
*     int   : the height of the tree
*/
int height(Node*root){
  if(!root){
    return 0;
  }
  return 1+max(height(root->left),height(root->right));
}
/**
* Private : findnode
* 
* Description:
*   used to find a node and get the data from it 
* 
* Params:
*      Node   *root   //root of the tree 
*     string    data  //the data being searched for 
* 
* Returns:
*     jsondata   : the stored in the found node 
*/
jsondata findnode(string data,Node*root){
  jsondata temp;
  if(!root){
    return temp;
  }
  if(root->data.lname == data){
    return root->data;
  }
  else if(data<root->data.lname){
    return findnode(data,root->left);
  }
  else{
    return findnode(data,root->right);
  }
}
/**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
* 
* Returns:
*     int   : the height of the tree
*/
bool founddata(string data, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.lname ==data){
      return true;
    }
    else if(data < root->data.lname){
      return founddata(data,root->left);
    }else{
      return founddata(data,root->right);
    }
    return false;
    }
  }
public:
 /**
* Public : LNBST
* 
* Description:
*   Defaut Constructor
* 
* Params:
*     N/A
* 
* Returns:
*    N/A
*/
LNBST(){root = nullptr;}
/**
* Public : insert
* 
* Description:
*   calls private insert
* 
* Params:
*     jsondata    data // the data to be added
* 
* Returns:
*    N/A
*/
void insert(jsondata data){insert(data,root);}
/**
* Public : print
* 
* Description:
*   calls private print
* 
* Params:
*    N/A
* 
* Returns:
*    N/A
*/
void print(){print(root);}
/**
* Public : remove
* 
* Description:
*   calls private remove
* 
* Params:
*    string      data  // data to be searched for 
* 
* Returns:
*    Node* :  Node to be removed
*/
Node *remove(string data){return remove(data,root);}
/**
* Public : height
* 
* Description:
*   calls private height
* 
* Params:
*    N/A
* 
* Returns:
*    int    :  height of tree
*/
int height(){return height(root);}
/**
* Public : founddata
* 
* Description:
*   calls private founddata
* 
* Params:
*    string   data  //data being searched for 
* 
* Returns:
*    bool    :  true or false based on if data is found
*/
bool founddata(string data){nodeschecked = 0; return founddata(data,root);}
/**
* Public : getnodeschecked
* 
* Description:
*   gets the number of nodes needed to be checked to find data
* 
* Params:
*    N/A
* 
* Returns:
*    int     : the number of nodes cecked
*/
int getnodeschecked(){return nodeschecked;}
};

class EMBST{
private:
Node*root;
int nodeschecked;
void print(Node*root){
  if(!root){
    return;
 }
  print(root->left);
  root->data.display();
  print(root -> right);
  
}
void insert(jsondata data, Node*&root){
 
  if(!root){
    root = new Node(data);
    return;
  }
  if (data.email < root->data.email){
    insert(data,root->left);
  }else{
    insert(data,root->right);
  }
}
Node* findmin(Node*root){
  Node*temp=root;
  while(temp->left!=nullptr){
    temp = temp->left;
  }
  return temp;
}
Node *remove(string data, Node *root){
  int index=0;
  if(root == nullptr){
    return nullptr;
  }
  if(data < root->data.email){
    root->left = remove(data,root->left);
  }
  else if(data>root->data.email){
    root->right = remove(data,root->right);
  }
  else{
    if(root->left == nullptr && root->right == nullptr){
      delete root;
      return nullptr;
    }
    else if(root->left == nullptr){
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == nullptr){
      Node*temp = root->left;
      delete root;
      return temp;
    }
    else{
      Node*minNode = findmin(root->right);
      root->data = minNode->data;
      root->right = remove(minNode->data.lname,root->right);
    }
  }
  return root;
}
int height(Node*root){
  if(!root){
    return 0;
  }
  return 1+max(height(root->left),height(root->right));
}
jsondata findnode(string data,Node*root){
  jsondata temp;
  if(!root){
    return temp;
  }
  if(root->data.email == data){
    return root->data;
  }
  else if(data<root->data.email){
    return findnode(data,root->left);
  }
  else{
    return findnode(data,root->right);
  }
}
int findnodecount(string data,Node*root){
  jsondata temp;
  int nodeschecked = 1;
  if(!root){
    return nodeschecked;
  }
  if(root->data.email == data){
    return nodeschecked;
  }
  else if(data<root->data.email){
    nodeschecked++;
    return findnodecount(data,root->left);
  }
  else{
    nodeschecked++;
    return findnodecount(data,root->right);
  }
}
bool founddata(string data, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.email ==data){
      return true;
    }
    else if(data < root->data.email){
      return founddata(data,root->left);
    }else{
      return founddata(data,root->right);
    }
    return false;
    }
  }
public:
EMBST(){root = nullptr;}
void insert(jsondata data){insert(data,root);}
void print(){print(root);}
Node *remove(string data){return remove(data,root);}
int height(){return height(root);}
bool founddata(string data){nodeschecked = 0; return founddata(data,root);}
int getnodeschecked(){return nodeschecked;}
};

class PHBST{
private:
Node*root;
int nodeschecked;
void print(Node*root){
  if(!root){
    return;
 }
  print(root->left);
  root->data.display();
  print(root -> right);
  
}
void insert(jsondata data, Node*&root){
 
  if(!root){
    root = new Node(data);
    return;
  }
  if (data.phone < root->data.phone){
    insert(data,root->left);
  }else{
    insert(data,root->right);
  }
}
Node* findmin(Node*root){
  Node*temp=root;
  while(temp->left!=nullptr){
    temp = temp->left;
  }
  return temp;
}
Node *remove(string data, Node *root){
  int index=0;
  if(root == nullptr){
    return nullptr;
  }
  if(data < root->data.phone){
    root->left = remove(data,root->left);
  }
  else if(data>root->data.phone){
    root->right = remove(data,root->right);
  }
  else{
    if(root->left == nullptr && root->right == nullptr){
      delete root;
      return nullptr;
    }
    else if(root->left == nullptr){
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == nullptr){
      Node*temp = root->left;
      delete root;
      return temp;
    }
    else{
      Node*minNode = findmin(root->right);
      root->data = minNode->data;
      root->right = remove(minNode->data.phone,root->right);
    }
  }
  return root;
}
int height(Node*root){
  if(!root){
    return 0;
  }
  return 1+max(height(root->left),height(root->right));
}
jsondata findnode(string data,Node*root){
  jsondata temp;
  if(!root){
    return temp;
  }
  if(root->data.phone == data){
    return root->data;
  }
  else if(data<root->data.phone){
    return findnode(data,root->left);
  }
  else{
    return findnode(data,root->right);
  }
}
int findnodecount(string data,Node*root){
  jsondata temp;
  int nodeschecked = 1;
  if(!root){
    return nodeschecked;
  }
  if(root->data.phone == data){
    return nodeschecked;
  }
  else if(data<root->data.phone){
    nodeschecked++;
    return findnodecount(data,root->left);
  }
  else{
    nodeschecked++;
    return findnodecount(data,root->right);
  }
}
bool founddata(string data, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.phone ==data){
      return true;
    }
    else if(data < root->data.phone){
      return founddata(data,root->left);
    }else{
      return founddata(data,root->right);
    }
    return false;
    }
  }
public:
PHBST(){root = nullptr;}
void insert(jsondata data){insert(data,root);}
void print(){print(root);}
Node *remove(string data){return remove(data,root);}
int height(){return height(root);}
bool founddata(string data){nodeschecked = 0; return founddata(data,root);}
int getnodeschecked(){return nodeschecked;}
};
class ADBST{
private:
Node*root;
int nodeschecked;
void print(Node*root){
  if(!root){
    return;
 }
  print(root->left);
  root->data.display();
  print(root -> right);
  
}
void insert(jsondata data, Node*&root){
 
  if(!root){
    root = new Node(data);
    return;
  }
  if (data.address < root->data.address){
    insert(data,root->left);
  }else{
    insert(data,root->right);
  }
}
Node* findmin(Node*root){
  Node*temp=root;
  while(temp->left!=nullptr){
    temp = temp->left;
  }
  return temp;
}
Node *remove(string data, Node *root){
  int index=0;
  if(root == nullptr){
    return nullptr;
  }
  if(data < root->data.address){
    root->left = remove(data,root->left);
  }
  else if(data>root->data.address){
    root->right = remove(data,root->right);
  }
  else{
    if(root->left == nullptr && root->right == nullptr){
      delete root;
      return nullptr;
    }
    else if(root->left == nullptr){
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == nullptr){
      Node*temp = root->left;
      delete root;
      return temp;
    }
    else{
      Node*minNode = findmin(root->right);
      root->data = minNode->data;
      root->right = remove(minNode->data.address,root->right);
    }
  }
  return root;
}
int height(Node*root){
  if(!root){
    return 0;
  }
  return 1+max(height(root->left),height(root->right));
}
jsondata findnode(string data,Node*root){
  jsondata temp;
  if(!root){
    return temp;
  }
  if(root->data.address == data){
    return root->data;
  }
  else if(data<root->data.address){
    return findnode(data,root->left);
  }
  else{
    return findnode(data,root->right);
  }
}
int findnodecount(string data,Node*root){
  jsondata temp;
  int nodeschecked = 1;
  if(!root){
    return nodeschecked;
  }
  if(root->data.address == data){
    return nodeschecked;
  }
  else if(data<root->data.address){
    nodeschecked++;
    return findnodecount(data,root->left);
  }
  else{
    nodeschecked++;
    return findnodecount(data,root->right);
  }
}
bool founddata(string data, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.address ==data){
      return true;
    }
    else if(data < root->data.address){
      return founddata(data,root->left);
    }else{
      return founddata(data,root->right);
    }
    return false;
    }
  }
public:
ADBST(){root = nullptr;}
void insert(jsondata data){insert(data,root);}
void print(){print(root);}
Node *remove(string data){return remove(data,root);}
int height(){return height(root);}
bool founddata(string data){nodeschecked = 0; return founddata(data,root);}
int getnodeschecked(){return nodeschecked;}
};
class LONGBST {
private:
  Node *root;
  int nodeschecked;
  void print(Node *root) {
    if (!root) {
      return;
    }
    print(root->left);
    root->data.display();
    print(root->right);
  }
  void insert(jsondata data, Node *&root) {
    if (!root) {
      root = new Node(data);
      return;
    }
    if (data.longitude < root->data.longitude) {
      insert(data, root->left);
    } else {
      insert(data, root->right);
    }
  }
  Node *findmin(Node *root) {
    Node *temp = root;
    while (temp->left != nullptr) {
      temp = temp->left;
    }
    return temp;
  }
  Node *remove(double data, Node *root) {
    if (root == nullptr) {
      return nullptr;
    }
    if (data < root->data.longitude) {
      root->left = remove(data, root->left);
    } else if (data > root->data.longitude) {
      root->right = remove(data, root->right);
    } else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      } else if (root->right == nullptr) {
        Node *temp = root->right;
        delete root;
        return temp;
      } else if (root->right == nullptr) {
        Node *temp = root->right;
        delete root;
        return temp;
      } else {
        Node *minNode = findmin(root->right);
        root->data = minNode->data;
        root->right = remove(minNode->data.longitude, root->right);
      }
    }
    return root;
  }
  int height(Node *root) {
    if (!root) {
      return 0;
    }
    return 1 + max(height(root->left), height(root->right));
  }
  jsondata findnode(double data, Node*root){
    jsondata temp;
    if(!root){
      return temp;
    }
    if(root->data.longitude ==data){
      return root->data;
    }
    else if(data < root->data.longitude){
      return findnode(data,root->left);
    }else{
      return findnode(data,root->right);
    }
  }
int findnodecount(double data,Node*root){
  jsondata temp;
  int nodeschecked = 1;
  if(!root){
    return nodeschecked;
  }
  if(root->data.longitude == data){
    return nodeschecked;
  }
  else if(data<root->data.longitude){
    nodeschecked++;
    return findnodecount(data,root->left);
  }
  else{
    nodeschecked++;
    return findnodecount(data,root->right);
  }
}
bool founddata(double data, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.longitude ==data){
      return true;
    }
    else if(data < root->data.longitude){
      return founddata(data,root->left);
    }else{
      return founddata(data,root->right);
    }
    return false;
    }
  }
public:
  LONGBST() { root = nullptr; }
  void insert(jsondata data) { insert(data, root); }
  void print() { print(root); }
  Node *remove(double data) { return remove(data, root); }
  int height() { return height(root); }
  bool founddata(double data){nodeschecked = 0; return founddata(data,root);}
  int getnodeschecked(){return nodeschecked;}
};
class LATBST {
private:
  Node *root;
  int nodeschecked;
  void print(Node *root) {
    if (!root) {
      return;
    }
    print(root->left);
    root->data.display();
    print(root->right);
  }
  void insert(jsondata data, Node *&root) {
    if (!root) {
      root = new Node(data);
      return;
    }
    if (data.latitude < root->data.latitude) {
      insert(data, root->left);
    } else {
      insert(data, root->right);
    }
  }
  Node *findmin(Node *root) {
    Node *temp = root;
    while (temp->left != nullptr) {
      temp = temp->left;
    }
    return temp;
  }
  Node *remove(double data, Node *root) {
    if (root == nullptr) {
      return nullptr;
    }
    if (data < root->data.latitude) {
      root->left = remove(data, root->left);
    } else if (data > root->data.latitude) {
      root->right = remove(data, root->right);
    } else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      } else if (root->right == nullptr) {
        Node *temp = root->right;
        delete root;
        return temp;
      } else if (root->right == nullptr) {
        Node *temp = root->right;
        delete root;
        return temp;
      } else {
        Node *minNode = findmin(root->right);
        root->data = minNode->data;
        root->right = remove(minNode->data.latitude, root->right);
      }
    }
    return root;
  }
  int height(Node *root) {
    if (!root) {
      return 0;
    }
    return 1 + max(height(root->left), height(root->right));
  }
  jsondata findnode(double data, Node*root){
    jsondata temp;
    if(!root){
      return temp;
    }
    if(root->data.latitude ==data){
      return root->data;
    }
    else if(data < root->data.latitude){
      return findnode(data,root->left);
    }else{
      return findnode(data,root->right);
    }
  }
bool founddata(double data, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.latitude ==data){
      return true;
    }
    else if(data < root->data.latitude){
      return founddata(data,root->left);
    }else{
      return founddata(data,root->right);
    }
    return false;
    }
  }
public:
  LATBST() { root = nullptr; }
  void insert(jsondata data) { insert(data, root); }
  void print() { print(root); }
  Node *remove(double data) { return remove(data, root); }
  int height() { return height(root); }
  bool founddata(double data){nodeschecked = 0; return founddata(data,root);}
  int getnodeschecked(){return nodeschecked;}
};
class CMBST{
private:
Node*root;
int nodeschecked;
void print(Node*root){
  if(!root){
    return;
 }
  print(root->left);
 root->data.display();
  print(root -> right);
  
}
void insert(jsondata data, Node*&root){
 
  if(!root){
    root = new Node(data);
    return;
  }
  if (data.carmodel < root->data.carmodel){
    insert(data,root->left);
  }else{
    insert(data,root->right);
  }
}
Node* findmin(Node*root){
  Node*temp=root;
  while(temp->left!=nullptr){
    temp = temp->left;
  }
  return temp;
}
Node *remove(string data, Node *root){
  int index=0;
  if(root == nullptr){
    return nullptr;
  }
  if(data < root->data.carmodel){
    root->left = remove(data,root->left);
  }
  else if(data>root->data.carmodel){
    root->right = remove(data,root->right);
  }
  else{
    if(root->left == nullptr && root->right == nullptr){
      delete root;
      return nullptr;
    }
    else if(root->left == nullptr){
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == nullptr){
      Node*temp = root->left;
      delete root;
      return temp;
    }
    else{
      Node*minNode = findmin(root->right);
      root->data = minNode->data;
      root->right = remove(minNode->data.carmodel,root->right);
    }
  }
  return root;
}
int height(Node*root){
  if(!root){
    return 0;
  }
  return 1+max(height(root->left),height(root->right));
}
jsondata findnode(string data,Node*root){
  jsondata temp;
  if(!root){
    return temp;
  }
  if(root->data.carmodel == data){
    return root->data;
  }
  else if(data<root->data.carmodel){
    return findnode(data,root->left);
  }
  else{
    return findnode(data,root->right);
  }
}
bool founddata(string data, Node*root){
    nodeschecked++;
    if(!root){
      return false;
    }
    else{
    if(root->data.carmodel ==data){
      return true;
    }
    else if(data < root->data.carmodel){
      return founddata(data,root->left);
    }else{
      return founddata(data,root->right);
    }
    return false;
    }
  }
public:
CMBST(){root = nullptr;}
void insert(jsondata data){insert(data,root);}
void print(){print(root);}
Node *remove(string data){return remove(data,root);}
int height(){return height(root);}
bool founddata(string data){nodeschecked = 0; return founddata(data,root);}
int getnodeschecked(){return nodeschecked;}
};
class Database {
private:
  IDBST List1;
  FNBST List2;
  LNBST List3;
  EMBST List4;
  PHBST List5;
  ADBST List6;
  LONGBST List7;
  LATBST List8;
  CMBST List9;
  void IDSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].id < data[i].id) {
          swap(data[i], data[j]);
        }
      }
    }
  }
  void FNSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].fname < data[i].fname) {
          swap(data[i], data[j]);
        }
      }
    }
  }
  void LNSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].lname < data[i].lname) {
          swap(data[i], data[j]);
        }
      }
    }
  }
  void EMSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].email < data[i].email) {
          swap(data[i], data[j]);
        }
      }
    }
  }
  void PHSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].phone < data[i].phone) {
          swap(data[i], data[j]);
        }
      }
    }
  }
  void ADSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].address < data[i].address) {
          swap(data[i], data[j]);
        }
      }
    }
  }
  void LONGSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].longitude < data[i].longitude) {
          swap(data[i], data[j]);
        }
      }
    }
  }
  void LATSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].latitude < data[i].latitude) {
          swap(data[i], data[j]);
        }
      }
    }
  }
  void CMSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].carmodel < data[i].carmodel) {
          swap(data[i], data[j]);
        }
      }
    }
  }

public:
  Database(vector<jsondata> data) {
    IDSort(data);
    int mid = data.size() / 2;
    jsondata temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List1.insert(data[i]);
    }
    FNSort(data);
    temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List2.insert(data[i]);
    }
    LNSort(data);
    temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List3.insert(data[i]);
    }
    EMSort(data);
    temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List4.insert(data[i]);
    }
    PHSort(data);
    temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List5.insert(data[i]);
    }
    ADSort(data);
    temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List6.insert(data[i]);
    }
    LONGSort(data);
    temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List7.insert(data[i]);
    }
    LATSort(data);
    temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List8.insert(data[i]);
    }
    CMSort(data);
    temp = data[mid];
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end());
    data.insert(data.begin(),temp);
    for (int i = 0; i < data.size(); i++) {
      List9.insert(data[i]);
    }
  }
  void insert(jsondata data) {
    List1.insert(data);
    List2.insert(data);
    List3.insert(data);
    List4.insert(data);
    List5.insert(data);
    List6.insert(data);
    List7.insert(data);
    List8.insert(data);
    List9.insert(data);
  }
  void RemoveID(int data) { List1.remove(data); }
  void RemoveFN(string data) { List2.remove(data); }
  void RemoveLN(string data) { List3.remove(data); }
  void RemoveEM(string data) { List4.remove(data); }
  void RemovePH(string data) { List5.remove(data); }
  void RemoveAD(string data) { List6.remove(data); }
  void RemoveLONG(double data) { List7.remove(data); }
  void RemoveLAT(double data) { List8.remove(data); }
  void RemoveCM(string data) { List9.remove(data); }
  bool FoundID(int data){ return List1.founddata(data);}
  int  GetIDNodes(){ return List1.getnodeschecked();}
  int  GetheightID(){return List1.height();}
  bool FoundFN(string data){ return List2.founddata(data);}
  int  GetFNNodes(){ return List2.getnodeschecked();}
  int  GetheightFN(){return List2.height();}
  bool FoundLN(string data){ return List3.founddata(data);}
  int  GetLNNodes(){ return List3.getnodeschecked();}
  int  GetheightLN(){return List3.height();}
  bool FoundEM(string data){ return List4.founddata(data);}
  int  GetEMNodes(){ return List4.getnodeschecked();}
  int  GetheightEM(){return List4.height();}
  bool FoundPH(string data){ return List5.founddata(data);}
  int  GetPHNodes(){ return List5.getnodeschecked();}
  int  GetheightPH(){return List5.height();}
  bool FoundAD(string data){ return List6.founddata(data);}
  int  GetADNodes(){ return List6.getnodeschecked();}
  int  GetheightAD(){return List6.height();}
  bool FoundLONG(double data){ return List7.founddata(data);}
  int  GetLONGNodes(){ return List7.getnodeschecked();}
  int  GetheightLONG(){return List7.height();}
  bool FoundLAT(double data){ return List8.founddata(data);}
  int  GetLATNodes(){ return List8.getnodeschecked();}
  int  GetheightLAT(){return List8.height();}
  bool FoundCM(string data){ return List9.founddata(data);}
  int  GetCMNodes(){ return List9.getnodeschecked();}
  int  GetheightCM(){return List9.height();}

  void Print_inorder(int choice) {
    if (choice == 1) {
      List1.print();
    } else if (choice == 2) {
      List2.print();
    } else if (choice == 3) {
      List3.print();
    } else if (choice == 4) {
      List4.print();
    } else if (choice == 5) {
      List5.print();
    } else if (choice == 6) {
      List6.print();
    } else if (choice == 7) {
      List7.print();
    } else if (choice == 8) {
      List8.print();
    } else {
      List9.print();
    }
  }
};