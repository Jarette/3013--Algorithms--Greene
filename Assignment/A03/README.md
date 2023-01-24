## AO3 - Basic Project Organization
### Jarette Greene
### Description:

    This program contains a class that creates a circular array based 
    queue. This is an array that stores integers and when integers are
    added to the queue it is added to the back of the queue and items 
    can only be taken off the queue from the front. This program was 
    mainly created to display proper organization and commenting 
    for any programs created for Fall 2023 CMPS 3013

### Files

|   #   | File             | Description                                        |
| :---: | ---------------  | -------------------------------------------------- |
|   1   | [Main.cpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/A03/main.cpp)| Main driver of my project that launches game.      |


### Instructions

- Create instance of Queue 
- use push and pop functions ot add and remove from list
- use cout << [queue name] to display the entire lise 

- Example Command:

        CircularArrayQue C1(5)  // created instance of queue
        C1.Push(1);     // pushing items onto queue
        cout << C1 << endl;    // displaying items in queue
        C1.Pop();    // removes item from list
