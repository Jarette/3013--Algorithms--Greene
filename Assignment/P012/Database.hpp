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
    if (data.id <= root->data.id) {  //trverses left if the data is smaller than node data
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
*      int     id     // the data being searched for 
* Returns:
*     bool   : true or false based on  if the data is found or not
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
  if (data.fname <= root->data.fname){
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
*      string data    // the data being searched 
* Returns:
*     bool   : true or false based on if the data is found
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
  if (data.lname <= root->data.lname){
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
*      strinng data   // the data being searched
* Returns:
*     bool   : true or false based on if the data is found or not 
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
/**
 * EMBST
 * 
 * Description:
 *      A binary search tree that uses the last Name field of the data
 *      as the main key used to search, sort and delete data
 * 
 * Public Methods:
 *           EMBST()                
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
 *      EMBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata("jones@gmail.com")  //located where the email is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class EMBST{
private:
Node*root;     //root of the tree
int nodeschecked;     // stores the number of nodes needed to be checked to find item
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
  if (data.email <= root->data.email){
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
/**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
*      string  data // data being looked for 
* Returns:
*     bool   : true or false based on if the data is found 
*/
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
/**
* Public : EMBST
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
EMBST(){root = nullptr;}
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
 * PHBST
 * 
 * Description:
 *      A binary search tree that uses the Phone number field of the data
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
 *      PHBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata("782-912-2222")  //located where the the phone number is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class PHBST{
private:
Node*root;     //root of the tree
int nodeschecked;  // stores the number of nodes needed to be checked to find a node
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
  if (data.phone <= root->data.phone){
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
/**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
*      string   data  // data to be looked for 
* Returns:
*     bool : true or false based on if the data is found 
*/
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
/**
* Public : PHBST
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
PHBST(){root = nullptr;}
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
 * ADBST
 * 
 * Description:
 *      A binary search tree that uses the address field of the data
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
 *      ADBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata("PO Box 2456")  //located where the the address is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class ADBST{
private:
Node*root;        //the root of the tree
int nodeschecked;  //strores the amount of nodes needed to be checked to find a piece of data
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
  if (data.address <= root->data.address){
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
/**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
*      string   data  // data being looked for
* Returns:
*     bool   : true or false if the data is found or not
*/
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
/**
* Public : ADBST
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
ADBST(){root = nullptr;}
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
 * LONGBST
 * 
 * Description:
 *      A binary search tree that uses the longitude field of the data
 *      as the main key used to search, sort and delete data
 * 
 * Public Methods:
 *           LNBST()                
 *   void    insert(jsondata data)  
 *   void    print()                 
 *   Node*   remove(double data)        
 *   int     height()                 
 *   bool    founddata(string data)    
 *   int     getnodeschecked()    
 * 
 * Private Methods:
 *   void      print(Node *root)      
 *   void      insert(json data, Node *&root)   
 *   Node      *findmin(Node*root)              
 *   Node      *remove(double data, Noderoot)      
 *   int       height()                        
 *   jsondata  findnode(double data, Node*root)     
 *   bool      founddata(double data, Node*root) 
 *        
 * 
 * Usage: 
 * 
 *      LONGBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata("21.2232")  //located where the longitude is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class LONGBST {
private:
  Node *root;      // the root of the tree
  int nodeschecked; // stores the number of nodes to be checked to find data
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
    root->data.display();
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
    if (data.longitude <= root->data.longitude) {
      insert(data, root->left);
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
    while (temp->left != nullptr) {
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
*      double  data   // the data being looked for 
* 
* Returns:
*     Node*   : pointer to a node 
*/
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
*     double    data  //the data being searched for 
* 
* Returns:
*     jsondata   : the stored in the found node 
*/
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
/**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
*      double  data   // the data being looked for 
* Returns:
*     bool   : true or false based on if the data is found or not 
*/
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
/**
* Public : LONGBST
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
  LONGBST() { root = nullptr; }
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
*    double      data  // data to be searched for 
* 
* Returns:
*    Node* :  Node to be removed
*/
  Node *remove(double data) { return remove(data, root); }
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
*    double   data  //data being searched for 
* 
* Returns:
*    bool    :  true or false based on if data is found
*/
  bool founddata(double data){nodeschecked = 0; return founddata(data,root);}
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
 * LATBST
 * 
 * Description:
 *      A binary search tree that uses the latitude field of the data
 *      as the main key used to search, sort and delete data
 * 
 * Public Methods:
 *           LNBST()                
 *   void    insert(jsondata data)  
 *   void    print()                 
 *   Node*   remove(double data)        
 *   int     height()                 
 *   bool    founddata(string data)    
 *   int     getnodeschecked()    
 * 
 * Private Methods:
 *   void      print(Node *root)      
 *   void      insert(json data, Node *&root)   
 *   Node      *findmin(Node*root)              
 *   Node      *remove(double data, Noderoot)      
 *   int       height()                        
 *   jsondata  findnode(double data, Node*root)     
 *   bool      founddata(double data, Node*root) 
 *        
 * 
 * Usage: 
 * 
 *      LATBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata("33.1212")  //located where the latitude is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class LATBST {
private:
  Node *root; // root of the tree
  int nodeschecked; // stores the number of nodes checked when finding data
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
    root->data.display();
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
    if (data.latitude <= root->data.latitude) {
      insert(data, root->left);
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
    while (temp->left != nullptr) {
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
*      double  data   // the data being looked for 
* 
* Returns:
*     Node*   : pointer to a node 
*/
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
*     double    data  //the data being searched for 
* 
* Returns:
*     jsondata   : the stored in the found node 
*/
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
/**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
*      double  data   // the data being looked for 
* Returns:
*     bool   : true or false based on if the data is found or not 
*/
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
/**
* Public : LATBST
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
  LATBST() { root = nullptr; }
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
*    double      data  // data to be searched for 
* 
* Returns:
*    Node* :  Node to be removed
*/
  Node *remove(double data) { return remove(data, root); }
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
*    double   data  //data being searched for 
* 
* Returns:
*    bool    :  true or false based on if data is found
*/
  bool founddata(double data){nodeschecked = 0; return founddata(data,root);}
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
 * CMBST
 * 
 * Description:
 *      A binary search tree that uses the latitude field of the data
 *      as the main key used to search, sort and delete data
 * 
 * Public Methods:
 *           CMBST()                
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
 *      LATBST List1;   //creating a tree
 *      List1.insert(data)  //inserting data into tree
 *      List1.founddata("Ford Bronco")  //located where the car model is located in the tree 
 *      List1.getnodeschecked()  //gives the amount of noodes that needed to be checked to find
 *                               // data
 *      
 */
class CMBST{
private:
Node*root;   // root of tree 
int nodeschecked;   // stores the number of nodes checked to find data
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
  if (data.carmodel <= root->data.carmodel){
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
*      string  data   // the data being looked for 
* 
* Returns:
*     Node*   : pointer to a node 
*/
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
/**
* Private : founddata
* 
* Description:
*   finds the node containing data specifed and count the 
*   of nodes that was needed to checked to find it 
* 
* Params:
*      Node   *root   //root of the tree 
*      string  data   // the data being looked for 
* Returns:
*     bool   : true or false based on if the data is found or not 
*/
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
/**
* Public : CMBST
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
CMBST(){root = nullptr;}
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
 * Database
 * 
 * Description:
 *      class contianing all the Binary search trees and allows the 
 *      user to access all of the different trees easily.
 * 
 * Public Methods:
 *             Database(vector<jsondaata> data)
 *     void    insert(jsondata)
 *     void    RemoveID(int data) 
 *     void    RemoveFN(string data) 
 *     void    RemoveLN(string data) 
 *     void    RemoveEM(string data) 
 *     void    RemovePH(string data)
 *     void    RemoveAD(string data) 
 *     void    RemoveLONG(double data) 
 *     void    RemoveLAT(double data)
 *     void    RemoveCM(string data) 
 *     bool    FoundID(int data)
 *     int     GetIDNodes()
 *     int     GetheightID()
 *     bool    FoundFN(string data)
 *     int     GetFNNodes()
 *     int     GetheightFN()
 *     bool    FoundLN(string data)
 *     int     GetLNNodes()
 *     int     GetheightLN()
 *     bool    FoundEM(string data)
 *     int     GetEMNodes()
 *     int     GetheightEM()
 *     bool    FoundPH(string data)
 *     int     GetPHNodes()
 *     int     GetheightPH()
 *     bool    FoundAD(string data)
 *     int     GetADNodes()
 *     int     GetheightAD()
 *     bool    FoundLONG(double data)
 *     int     GetLONGNodes()
 *     int     GetheightLONG()
 *     bool    FoundLAT(double data)
 *     int     GetLATNodes()
 *     int     GetheightLAT()
 *     bool    FoundCM(string data)
 *     int     GetCMNodes()
 *     int     GetheightCM()
 *     void    Print_inorder(int choice)
 * 
 * Private Methods:
 * 
 *      void   IDSort(vector<jsondata> &data)
 *      void   FNSort(vector<jsondata> &data)
 *      void   LNSort(vector<jsondata> &data)
 *      void   EMSort(vector<jsondata> &data)
 *      void   PHSort(vector<jsondata> &data) 
 *      void   ADSort(vector<jsondata> &data)
 *      void   LONGSort(vector<jsondata> &data)
 *      void   LATSort(vector<jsondata> &data)
 *      void   CMSort(vector<jsondata> &data)
 * 
 * Usage: 
 *      vector <jsondata> A;
 *      Database Test(A)  // passing in data into the database
 *      Test.FoundID(1)   // returns true or false if the ID# 1 is in the database
 *      Test.GetIDNodes  // returns howmany nodes needed to be checked to find
 *                        // previously searched ID
 *      Print_in_order(1)   // displays the entire list in order based on the choice entered
 */
class Database {
private:
  IDBST List1;      //ID binary SearchTree
  FNBST List2;      // First Name Binary Search Tree
  LNBST List3;      // Last Name Binary Search Tree
  EMBST List4;      // Email Binary Search Tree
  PHBST List5;      // Phone Number Binary Search Tree
  ADBST List6;      // Address Binary Search Tree
  LONGBST List7;    // Longitude Binary Search Tree
  LATBST List8;     // Latitude Binary  Search Tree
  CMBST List9;      // Car Model Binary Search tree 

/**
* Private : IDSort
* 
* Description:
*      Sorts the vector based on the ID#
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  void IDSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].id < data[i].id) {
          swap(data[i], data[j]);
        }
      }
    }
  }
/**
* Private : FNSort
* 
* Description:
*      Sorts the vector based on the First Name
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  void FNSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].fname < data[i].fname) {
          swap(data[i], data[j]);
        }
      }
    }
  }
/**
* Private : LNSort
* 
* Description:
*      Sorts the vector based on the LAst Name
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  void LNSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].lname < data[i].lname) {
          swap(data[i], data[j]);
        }
      }
    }
  }
/**
* Private : EMSort
* 
* Description:
*      Sorts the vector based on the Email
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  void EMSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].email < data[i].email) {
          swap(data[i], data[j]);
        }
      }
    }
  }
/**
* Private : PHSort
* 
* Description:
*      Sorts the vector based on the Phone number
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  void PHSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].phone < data[i].phone) {
          swap(data[i], data[j]);
        }
      }
    }
  }
/**
* Private : ADSort
* 
* Description:
*      Sorts the vector based on the Address
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  void ADSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].address < data[i].address) {
          swap(data[i], data[j]);
        }
      }
    }
  }
/**
* Private : LONGSort
* 
* Description:
*      Sorts the vector based on the longitude
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  void LONGSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].longitude < data[i].longitude) {
          swap(data[i], data[j]);
        }
      }
    }
  }
/**
* Private : LATSort
* 
* Description:
*      Sorts the vector based on the Latitude
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  void LATSort(vector<jsondata> &data) {
    for (int i = 0; i < (data.size() - 1); i++) {
      for (int j = (i + 1); j < data.size(); j++) {
        if (data[j].latitude < data[i].latitude) {
          swap(data[i], data[j]);
        }
      }
    }
  }
/**
* Private : CMSort
* 
* Description:
*      Sorts the vector based on the Carmodel
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
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
/**
* Public : Database
* 
* Description:
*      Constructor to fill the database
* 
* Params:
*      vector<jsondata> &data 
* 
* Returns:
*      N/A
*/
  Database(vector<jsondata> data) {
    IDSort(data);        // sorts the data
    int mid = data.size() / 2;
    jsondata temp = data[mid];      // finds the median 
    data.erase(data.begin()+mid);
    random_shuffle(data.begin(),data.end()); //reshuffles data
    data.insert(data.begin(),temp);   //puts median data to the front
    for (int i = 0; i < data.size(); i++) { //puts all data in approipriate tree
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
  /**
* Public : insert 
* 
* Description:
*      Places data into each tree in the database
* 
* Params:
*      jsondata   data 
* 
* Returns:
*      N/A
*/
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
  /**
* Public : RemoveID 
* 
* Description:
*      Removes Item from tree based on the ID passed
* 
* Params:
*      int   data 
* 
* Returns:
*      N/A
*/
  void RemoveID(int data) { List1.remove(data); }
  /**
* Public : RemoveFn 
* 
* Description:
*      Removes Item from tree based on the first name passed
* 
* Params:
*      string   data 
* 
* Returns:
*      N/A
*/
  void RemoveFN(string data) { List2.remove(data); }
/**
* Public : RemoveLN
* 
* Description:
*      Removes Item from tree based on the  last name passed
* 
* Params:
*      string   data 
* 
* Returns:
*      N/A
*/
  void RemoveLN(string data) { List3.remove(data); }
/**
* Public : RemoveEM
* 
* Description:
*      Removes Item from tree based on the email passed
* 
* Params:
*      string   data 
* 
* Returns:
*      N/A
*/
  void RemoveEM(string data) { List4.remove(data); }
/**
* Public : RemovePH
* 
* Description:
*      Removes Item from tree based on the phone passed
* 
* Params:
*      string   data 
* 
* Returns:
*      N/A
*/
  void RemovePH(string data) { List5.remove(data); }
/**
* Public : RemoveAD
* 
* Description:
*      Removes Item from tree based on the address passed
* 
* Params:
*      string   data 
* 
* Returns:
*      N/A
*/
  void RemoveAD(string data) { List6.remove(data); }
/**
* Public : RemoveLONG
* 
* Description:
*      Removes Item from tree based on the longitude passed
* 
* Params:
*      double   data 
* 
* Returns:
*      N/A
*/
  void RemoveLONG(double data) { List7.remove(data); }
/**
* Public : RemoveLAT
* 
* Description:
*      Removes Item from tree based on the latitude passed
* 
* Params:
*      double   data 
* 
* Returns:
*      N/A
*/
  void RemoveLAT(double data) { List8.remove(data); }
/**
* Public : RemoveCM
* 
* Description:
*      Removes Item from tree based on the car model passed
* 
* Params:
*      string   data 
* 
* Returns:
*      N/A
*/
  void RemoveCM(string data) { List9.remove(data); }
/**
* Public : FoundID
* 
* Description:
*      returns true or false based on if the ID passed is found 
*      with the tree.
* 
* Params:
*      int    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundID(int data){ return List1.founddata(data);}
/**
* Public : GetIDNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the ID that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetIDNodes(){ return List1.getnodeschecked();}
/**
* Public : GetheightID
* 
* Description:
*      returns the height of the ID BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightID(){return List1.height();}
/**
* Public : FoundFN
* 
* Description:
*      returns true or false based on if the first name passed is found 
*      with the tree.
* 
* Params:
*      string    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundFN(string data){ return List2.founddata(data);}
/**
* Public : GetFNNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the first name that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetFNNodes(){ return List2.getnodeschecked();}
/**
* Public : GetheightFN
* 
* Description:
*      returns the height of the first name BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightFN(){return List2.height();}
/**
* Public : FoundLN
* 
* Description:
*      returns true or false based on if the last name passed is found 
*      with the tree.
* 
* Params:
*      string    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundLN(string data){ return List3.founddata(data);}
/**
* Public : GetLNNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the last name that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetLNNodes(){ return List3.getnodeschecked();}
/**
* Public : GetheightLN
* 
* Description:
*      returns the height of the last name BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightLN(){return List3.height();}
/**
* Public : FoundEM
* 
* Description:
*      returns true or false based on if the email passed is found 
*      with the tree.
* 
* Params:
*      string    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundEM(string data){ return List4.founddata(data);}
/**
* Public : GetEMNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the email that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetEMNodes(){ return List4.getnodeschecked();}
/**
* Public : GetheightEM
* 
* Description:
*      returns the height of the email BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightEM(){return List4.height();}
/**
* Public : FoundPH
* 
* Description:
*      returns true or false based on if the phone number passed is found 
*      with the tree.
* 
* Params:
*      string    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundPH(string data){ return List5.founddata(data);}
/**
* Public : GetPHNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the phone number that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetPHNodes(){ return List5.getnodeschecked();}
/**
* Public : GetheighPH
* 
* Description:
*      returns the height of the phone number BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightPH(){return List5.height();}
/**
* Public : FoundAD
* 
* Description:
*      returns true or false based on if the Address passed is found 
*      with the tree.
* 
* Params:
*      string    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundAD(string data){ return List6.founddata(data);}
/**
* Public : GetADNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the address that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetADNodes(){ return List6.getnodeschecked();}
/**
* Public : GetheightAD
* 
* Description:
*      returns the height of the address BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightAD(){return List6.height();}
/**
* Public : FoundLONG
* 
* Description:
*      returns true or false based on if the Longitude passed is found 
*      with the tree.
* 
* Params:
*      double    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundLONG(double data){ return List7.founddata(data);}
/**
* Public : GetLONGNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the longitude that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetLONGNodes(){ return List7.getnodeschecked();}
/**
* Public : GetheightLONG
* 
* Description:
*      returns the height of the longitude BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightLONG(){return List7.height();}
/**
* Public : FoundLAT
* 
* Description:
*      returns true or false based on if the latitude passed is found 
*      with the tree.
* 
* Params:
*      double    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundLAT(double data){ return List8.founddata(data);}
/**
* Public : GetLATNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the latitude that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetLATNodes(){ return List8.getnodeschecked();}
/**
* Public : GetheightLAT
* 
* Description:
*      returns the height of the Latitude BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightLAT(){return List8.height();}
/**
* Public : FoundCM
* 
* Description:
*      returns true or false based on if the car model passed is found 
*      with the tree.
* 
* Params:
*      string    data 
* 
* Returns:
*      bool   :  true or false (1 or 0)
*/
  bool FoundCM(string data){ return List9.founddata(data);}
/**
* Public : GetCMNodes
* 
* Description:
*      returns the amount of nodes that need to be checked to 
*     find the car model that was previously searched 
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the number of nodes checked 
*/
  int  GetCMNodes(){ return List9.getnodeschecked();}
/**
* Public : GetheightCM
* 
* Description:
*      returns the height of the car model BST Tree
* 
* Params:
*     N/A 
* 
* Returns:
*      int   :  the height of the tree
*/
  int  GetheightCM(){return List9.height();}
/**
* Public : Print_inorder
* 
* Description:
*      displays all elements of the list in ascending order based on the 
*      integer passed in 
* 
* Params:
*     int     choice 
* 
* Returns:
*      N/A
*/
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