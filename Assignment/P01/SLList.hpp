#pragma once
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
*        This Hpp file contains a singly linked list that will contain data
*        read from a JSON file and will be able to traverse the list to find
*       data based on varous different keys and determine how much nodes needed
*
*
*  Usage:
*      - create instance of list
*      - insert json data into the list
*      - find data based the key data you want
*      - find out how many nodes had to be checked before finding the data
*
*  Files:
*        Database.hpp     :        database header file
*        SLList.hpp       :        the singly linked list
*****************************************************************************/
//necessary Libraries
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Database.hpp"
using namespace std;
/**
 * ListNode
 *
 * Description:
 *      This is a node that contains a next pointer and all the data taken from a
 *      json file.
 *
 * Public Methods:
 *            ListNode(jsondata d)   //overloaded constructor for node
 *
 * Private Methods:
 *
 *       N/A
 *
 * Usage:
 *
 *     ListNode(jsondata d)  //passes jsondata into a node
 *
 *
 */
struct ListNode {
    jsondata data;    //the data that is being stored in the node 
    ListNode* next;   // the location of the next node in the list 
    ListNode(jsondata d) {
        next = nullptr;
        data.id = d.id;
        data.first_name = d.first_name;
        data.last_name = d.last_name;
        data.email = d.email;
        data.phone_number = d.phone_number;
        data.address = d.address;
        data.longitude = d.longitude;
        data.latitude = d.latitude;
        data.car_model = d.car_model;
        data.car = d.car;
        data.car_color = d.car_color;
        data.job_title = d.job_title;
        data.pet = d.pet;
        data.city = d.city;
        data.state = d.state;
        data.favorite_movie = d.favorite_movie;
        for (int i = 0; i < d.stocks.size(); i++) {
            data.stocks.push_back(d.stocks[i]);
        }
    }
};
/**
 * LList
 *
 * Description:
 *      A singly list that containing data collected from a json file
 *
 * Public Methods:
 *      void      Print()
 *      void      Insert(jsondata d)
 *      bool      FindallID(int key)
 *      bool      FindallFN(string key)
 *      bool      FindallLN(string key)
 *      bool      FindallEM(string key)
 *      bool      FindallPH(string key)
 *      bool      FindallAD(string key)
 *      bool      FindallJT(string key)
 *      bool      FindallCM(string key)
 *      int       GetNodesChecked()
 *
 * Private Methods:
 *
 *       N/A
 *
 * Usage:
 *
 *     LList Test;  //creating intance of list
 *     Test.Insert(data) //adds data to the list
 *     Test.FindallID(1) // returns 1 or 0 if the ID# 1 is found in the list
 *     Test.GetNodesChecked() //returns the amount of nodeds checked to find ID#1
 *     Test.Print() //displays all the data stored in the list
 *
 *
 */
class LList {
private:
    ListNode* head;     //the beginning of the list
    ListNode* tail;     // the end of the list
    int nodeschecked;   // stores the amount of nodes checeked to find a piece of data
public:
    /**
     * Public: LList
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
    LList() {
        head = NULL;
        tail = NULL;
    }
    /**
     * Public: Print
     *
     * Description:
     *     displays all the data in the list
     *
     * Params:
     *      N/A
     *
     * Returns:
     *      N/A
    */
    void Print() {
        ListNode* traverse = head;
        while (traverse) {
            traverse->data.display();
            traverse = traverse->next;
        }
    }
    /**
     * Public: Insert
     *
     * Description:
     *     Inserts data into the back of the list
     *
     * Params:
     *      jsondata    d // the data being stored into the list
     *
     * Returns:
     *      N/A
    */
    void Insert(jsondata d) {
        ListNode* temp = new ListNode(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
            temp->next = NULL;
        }
    }
    /**
     * Public: FindallID
     *
     * Description:
     *     Produces a true or false based on if the ID passed
     *     is located in the list and also count all the nodes
     *     that had to be checked to find the node
     *
     * Params:
     *      int    key  // the id to be searched
     *
     * Returns:
     *      bool   : true or false (1 or 0)
    */
    bool FindallID(int key) {
        ListNode* traverse = head;
        nodeschecked = 1;
        while (traverse) {
            if (traverse->data.id != key) {
                nodeschecked++;
                traverse = traverse->next;
            }
            else {
                return true;
            }
        }
        nodeschecked = -1;
        return false;
    }
    /**
     * Public: FindallFN
     *
     * Description:
     *     Produces a true or false based on if the first name passed
     *     is located in the list and also count all the nodes
     *     that had to be checked to find the node
     *
     * Params:
     *      string    key
     *
     * Returns:
     *      bool   : true or false (1 or 0)
    */
    bool FindallFN(string key) {
        ListNode* traverse = head;
        nodeschecked = 1;
        while (traverse) {
            if (traverse->data.first_name != key) {
                nodeschecked++;
                traverse = traverse->next;
            }
            else {
                return true;
            }
        }
        nodeschecked = -1;
        return false;
    }
    /**
     * Public: FindallLN
     *
     * Description:
     *     Produces a true or false based on if the last name passed
     *     is located in the list and also count all the nodes
     *     that had to be checked to find the node
     *
     * Params:
     *      string    key
     *
     * Returns:
     *      bool   : true or false (1 or 0)
    */
    bool FindallLN(string key) {
        ListNode* traverse = head;
        nodeschecked = 1;
        while (traverse) {
            if (traverse->data.last_name != key) {
                nodeschecked++;
                traverse = traverse->next;
            }
            else {
                return true;
            }
        }
        nodeschecked = -1;
        return false;
    }
    /**
     * Public: FindallEM
     *
     * Description:
     *     Produces a true or false based on if the email passed
     *     is located in the list and also count all the nodes
     *     that had to be checked to find the node
     *
     * Params:
     *      string    key
     *
     * Returns:
     *      bool   : true or false (1 or 0)
    */
    bool FindallEM(string key) {
        ListNode* traverse = head;
        nodeschecked = 1;
        while (traverse) {
            if (traverse->data.email != key) {
                nodeschecked++;
                traverse = traverse->next;
            }
            else {
                return true;
            }
        }
        nodeschecked = -1;
        return false;
    }
    /**
     * Public: FindallPH
     *
     * Description:
     *     Produces a true or false based on if the phone number passed
     *     is located in the list and also count all the nodes
     *     that had to be checked to find the node
     *
     * Params:
     *      string    key
     *
     * Returns:
     *      bool   : true or false (1 or 0)
    */
    bool FindallPH(string key) {
        ListNode* traverse = head;
        nodeschecked = 1;
        while (traverse) {
            if (traverse->data.phone_number != key) {
                nodeschecked++;
                traverse = traverse->next;
            }
            else {
                return true;
            }
        }
        nodeschecked = -1;
        return false;
    }
    /**
     * Public: FindallAD
     *
     * Description:
     *     Produces a true or false based on if the address passed
     *     is located in the list and also count all the nodes
     *     that had to be checked to find the node
     *
     * Params:
     *      string    key
     *
     * Returns:
     *      bool   : true or false (1 or 0)
    */
    bool FindallAD(string key) {
        ListNode* traverse = head;
        nodeschecked = 1;
        while (traverse) {
            if (traverse->data.address != key) {
                nodeschecked++;
                traverse = traverse->next;
            }
            else {
                return true;
            }
        }
        nodeschecked = -1;
        return false;
    }
    /**
     * Public: FindallJT
     *
     * Description:
     *     Produces a true or false based on if the Jobtitle passed
     *     is located in the list and also count all the nodes
     *     that had to be checked to find the node
     *
     * Params:
     *      string    key
     *
     * Returns:
     *      bool   : true or false (1 or 0)
    */
    bool FindallJT(string key) {
        ListNode* traverse = head;
        nodeschecked = 1;
        while (traverse) {
            if (traverse->data.job_title != key) {
                nodeschecked++;
                traverse = traverse->next;
            }
            else {
                return true;
            }
        }
        nodeschecked = -1;
        return false;
    }
    /**
     * Public: FindallCM
     *
     * Description:
     *     Produces a true or false based on if the Car model passed
     *     is located in the list and also count all the nodes
     *     that had to be checked to find the node
     *
     * Params:
     *      string    key
     *
     * Returns:
     *      bool   : true or false (1 or 0)
    */
    bool FindallCM(string key) {
        ListNode* traverse = head;
        nodeschecked = 1;
        while (traverse) {
            if (traverse->data.car_model != key) {
                nodeschecked++;
                traverse = traverse->next;
            }
            else {
                return true;
            }
        }
        nodeschecked = -1;
        return false;
    }
    /**
   * Public: GetNodesChecked
   *
   * Description:
   *     returns the amount of nodes checked when searching for
   *     the last data being searched for.
   *
   * Params:
   *      double    key
   *
   * Returns:
   *      N/A
  */
    int GetNodesChecked() {
        return nodeschecked;
    }
};
