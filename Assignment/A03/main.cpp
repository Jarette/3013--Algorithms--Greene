/*****************************************************************************
*                    
*  Author:           Jarette Greene
*  Email:            jkgreene0406@my.msutexas.edu / jarettegreene09@gmail.com
*  Label:            A03
*  Title:            Basic Project Organization
*  Course:           CMPS 3013
*  Semester:         Spring 2023
* 
*  Description:
*        This program contains a class that creates a circular array based 
*        queue. This is an array that stores integers and when integers are
*       added to the queue it is added to the back of the queue and items 
*       can only be taken off the queue from the front. This program was 
*       mainly created to display proper organization and commenting 
*       for any programs created for Fall 2023 CMPS 3013
* 
*  Usage:
*       - create instance of CircularArrayQue
*       - use push function to add
*       - pop function to remove
*       - cout << [instance name] to display the entire queue
* 
*  Files:           
*        main.cpp      :        driver program 
*****************************************************************************/

// Libraries used
#include <iostream>

// namespace standard
using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      This class implements an array based circular queue.This class contains 
 *      a dynamically allocated with constructors that allows the user to set
 *      the size of the array. Thenn the user can push items onto the rear of the 
 *      list and pop items off the front of the list. 
 * 
 * Public Methods:
 *                               CircularArrayQue()
 *                              CircularArrayQue(int)
 *          void                Push(int)
 *          int                 Pop()
 *          friend ostream      &operator << (ostream &, const CircularArrayQue)            
 * 
 * Private Methods:
 *          void                init(int size = 0)
 *          bool                Full()
 * 
 * Usage: 
 * 
 *     CircularArrayQue List1;              // creates queue with default size of 10
 *     CircularArrayQue List2(5);           // creates queue with default size of  5
 *     List1.Push(10);                      // pushes 10 to the rear of list
 *     List1.Pop();                         // takes item at the front of the list off the list
 *     cout << List1;                       // displays the whole list 
 */
class CircularArrayQue {
private:
    //private attributes

    int *Container; //pointer cointaining items of the list
    int Front;  // item at the front of the list
    int Rear;   /// item at the back of the list
    int QueSize; // items in the queue
    int CurrentSize; // the current amount of items in the queue

/**
     * Private : init
     * 
     * Description:
     *     Initializes the values inside of the class
     * 
     * Params:
     *      int    :  default paramenter which is the size of the list
     * 
     * Returns:
     *      N/A
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }
/**
     * Private : init
     * 
     * Description:
     *     checks to see if the queue is full
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      bool    :   true or false based on if the queue is filled or not
     */
    bool Full() {
        return CurrentSize == QueSize;
    }
public:
/**
     * Public : CircularArrayQue
     * 
     * Description:
     *     Default constructor that intilaizes the list to the size of 10
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */
    CircularArrayQue() {
        Container = new int[10];  //dynamically allocating space for list
        init(10);
    }

    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *     Overloaded constructor that intilaizes the list to the size to 
     *      a value passed by the user
     * 
     * Params:
     *      int    :       size passed by user
     * 
     * Returns:
     *      N/A
     */

    CircularArrayQue(int size) {
        Container = new int[size];  // initializing the size of the list based 
        init(size);                 // on the size passed
    }

  /**
     * Public : Push
     * 
     * Description:
     *      This function add items to the back of the list  
     * 
     * Params:
     *      int    :      the item to be added to the list
     * 
     * Returns:
     *      N/A
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
/**
     * Public : Pop
     * 
     * Description:
     *      This function removes items from the front of the list and 
     *      returns it  
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      int     :      the item that has been removed from the front of the list
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    // Friend Prototype for overloaded ostream operator
    /**
     * Public : &operator <<
     * 
     * Description:
     *      overloaded ostrema operator to display the entire list  
     * 
     * Params:
     *      ostream       :     ostream variable passed by reference
     *      const CircularArrayQue  :      the queue that will be displayed 
     * 
     * Returns:
     *      ostream     : ostream variable
     */
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {

    // creating instance of queue
    CircularArrayQue C1(5);
    
    C1.Push(1);     // pushing items onto queue
    C1.Push(2);
    C1.Push(3);
    

    // displaying items in queue
    cout << C1 << endl;

    C1.Pop();    // removes item from list

    cout << C1 << endl;