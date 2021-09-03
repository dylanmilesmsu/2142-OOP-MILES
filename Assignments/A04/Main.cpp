/*****************************************************************************
*                    
*  Author:           Professor griffin
*  Email:            dylanbmiles@gmail.com
*  Label:            A04
*  Title:            Commenting practice
*  Course:           CMPS-2143-101
*  Semester:         Fall 2021
* 
*  Description:
*        This program implements a fixed size circular array.
* 
*  Usage:
*        ./main
* 
*  Files:            Main.cpp
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * Class CircularArrayQue
 * 
 * Description:
 *      A circular queue with a fixed size and integer data type. Default size 10. 
 * 
 * Public Methods:
 *      void Push - adds an item to the rear of the queue.
 *      int Pop - removes an item from the front of the array and returns that item.
 *      
 *      
 * 
 * Private Methods:
 *      void init - initializes the array at a specified size
 *      bool full - returns if the array is full
 * 
 * Usage: 
 *      CircularArrayQue name[size];
 *      name.push(int);
 *      name.pop();
 *      cout << name;      
 */
class CircularArrayQue {
private:
    int *Container; // Pointer to int container
    int Front; // Front of the array, starts at 0 until items are removed using pop()
    int Rear; // Rear of the array, also starts at 0 until items are added using push()
    int QueSize; // items in the queue
    int CurrentSize; // current size of the queue. Cannot exceed QueSize
    /**
     * private : init
     * 
     * Description:
     *      Initializes the array
     * 
     * Params:
     *  - int size, size of the array
     *  
     * Returns: 
     *      - Nothing
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * private : Full
     * 
     * Description:
     *      Returns true if the array is full
     * 
     * Params:
     *  - none
     *  
     * Returns: 
     *      - boolean true if the current array size is equal to the maximum array size
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    /**
     * public : CircularArrayQue
     * 
     * Description:
     *      Constructor with default size as 10
     * 
     * Params:
     *  - none
     *  
     * Returns: 
     *      - nothing
     */
    CircularArrayQue() {
        Container = new int[10]; //Create array with pre-defined size 10
        init(10);
    }
    /**
     * public : CircularArrayQue
     * 
     * Description:
     *      Constructor with size defined by param size
     * 
     * Params:
     *  - int size, size of array
     *  
     * Returns: 
     *      - nothing
     */
    CircularArrayQue(int size) {
        Container = new int[size]; //Create array with defined size
        init(size);
    }
    /**
     * public : Push
     * 
     * Description:
     *      Push an integer to the rear of the array
     * 
     * Params:
     *  - int item, to be appended to the array
     *  
     * Returns: 
     *      - nothing
     */
    void Push(int item) {
        if (!Full()) {                   //Check that array isn't full
            Container[Rear] = item;      //Set rear of container to equal the provided item
            Rear = (Rear + 1) % QueSize; //Advance the rear of the array
            CurrentSize++;               //Increment the size of the array
        } else {
            cout << "FULL!!!!" << endl;  //Error message
        }
    }
    /**
     * public : Pop
     * 
     * Description:
     *      Pop an integer from the front of the array.
     *      Removes the int from the front of the array and returns it.
     * 
     * Params:
     *  - none
     *  
     * Returns: 
     *      - int from front of the array
     */
    int Pop() {
        int temp = Container[Front];  //Temporarily store the front of the array
        Front = (Front + 1) % QueSize;//Advance the front of the array
        CurrentSize--;                //Decrement the size of the array
        return temp;                  //Return the temporarily stored int value
    }
    //gain access to variables for `<<` override 
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};
    /**
    * public : <<
    * 
    * Description: 
    *     Override the '<<' operator in order to nicely print the contents of the array
    * 
    *  Params:
    *       - ostream
    *       - CircularArray
    * 
    *   Returns: 
    *       ostream - output stream containing all elements of array
    */
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    //Loop through the entire array
    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " "; //Add array elements to ostream 
    }                                    //seperated by space
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
    //Create Circular array with defined size of 5
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    //Push integers to array
    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);

    //Print out contents of array
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    //Print out contents of array
    cout << C1 << endl;
}