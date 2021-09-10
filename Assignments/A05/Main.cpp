/*****************************************************************************
*                    
*  Author:           Dylan Miles
*  Email:            dylanbmiles@gmail.com
*  Label:            P01
*  Title:            
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

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * struct node
 * 
 * Description:
 *      Contains an integer data type, and a pointer, as this is a linked list
 * 
 * 
 * Usage: 
 * node* temp = new node(int)   
 */
struct node
{
    int data; // data value (could be a lot more values)

    node *next; // we always need a "link" in a linked list

    node(int x)
    { // cunstructor to make adding values easy
        data = x;
        next = NULL;
    }
};

/**
 * @brief Load array with values from a file
 * 
 * @param string filename 
 * @param int*& arr 
 * @param int& size 
 */
void loadArr(string filename, int *&arr, int &size)
{
    ifstream fin;        // stream reference
                         //
    fin.open(filename);  // open the file
                         //
    fin >> size;         // get first value which contains
                         // number of remaining values in file
                         //
    arr = new int[size]; // allocate new array of correct size
                         //
    int i = 0;           // need an array index for our while loop
                         //
    // Can also use for loop since we know the exact count in file.
    // eof = end of file flag
    // `!fin.eof()` evaulates to true when we hit end of file.
    while (!fin.eof())
    {
        fin >> arr[i]; // read file value straight into array
                       // at index i
        i++;           // increment array index
    }
}

/**
 * @brief Prints an array
 * 
 * @param int arr 
 * @param int size
 * 
 * @returns void
 */
void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << arr[i] << "]";
    }
    cout << "\n";
}
/**
 * class MyVector 
 * 
 * Description:
 *      a variable size linked list with many overloading structures
 *      can read from a file, array, even another MyVector
 *      contains methods to find, push, pop values, and even supports pushing lists
 * 
 * 
 * Usage: 
 * MyVector v1;
 * v1.pop()
 * v1.print()
 * v1.pushFront()
 * v1.pushRear()
 * v1.find()
 */
class MyVector
{
private:
    node *head; // base pointer of list
    node *tail; // pointer to end of list
public:
    /**
     * @brief Default Constructor 
     * 
     * Creates a new Linked List object.
     * 
     * @param void
     * @return void
     */
    MyVector()
    {
        head = NULL; // NULL = zeros
                     // and zeros imply empty
    }

    /**
     * @brief Overloaded Constructor 
     * 
     * Creates a new Linked List object from 
     * an array of values.
     * 
     * @param int* A - array of values
     * @param int size - size of array
     * 
     * @return void
     */
    MyVector(int A[], int size)
    {
        head = tail = NULL; // NULL = zeros
                     // and zeros imply empty

        for (int i = 0; i < size; i++)
        {
            pushFront(A[i]);
        }
    }
    /**
     * @brief Overloaded Constructor 
     * 
     * Creates a new Linked List object from 
     * an existing MyVector
     * 
     * @param MyVector MyVector - existing vector
     * 
     * 
     * @return void
     */
    MyVector(const MyVector& other) {
        head = tail = NULL;

        node *temp = other.head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            pushRear(temp->data); // print data from node
            temp = temp->next; // move to next node
        }
    }

    /**
     * @brief Overloaded Constructor 
     * 
     * Creates a new Linked List object from 
     * a filename
     * 
     * @param string filename, name of input file
     * 
     * @return void
     */
    MyVector(string filename)
    {
        head = tail = NULL; // NULL = zeros
        int size;
        int* array;
        loadArr(filename, array, size);
         for (int i = 0; i < size; i++)
        {
            pushFront(array[i]);
        }


    }

    /**
     * public : pushFront
     * 
     * Description:
     *      Push an integer to the front of the array
     * 
     * Params:
     *  - int item, to be prepended to the array
     *  
     * Returns: 
     *      - nothing
     */
    void pushFront(int x)
    {
        node *tempPtr = new node(x); // create a new node and
                                     // add data to it

        if (!head)
        { // `!head` implies empty list
            // So does `head == NULL`
            head = tempPtr; // `head = tempPtr` places addrress of
                            // tempPtr in head (points head to tempPtr)

            tail = head;    //when pushing to the front, the tail stays put.
        }
        else
        {                         // list not empty
            tempPtr->next = head; // point tempPtr's next to what head points to
            head = tempPtr;       // now point head to tempPtr
        }
    }

    /**
     * public : pushFront
     * 
     * Description:
     *      Push an existing MyVector to the front of the array
     * 
     * Params:
     *  - MuVector object, to be prepended to the array
     *  
     * Returns: 
     *      - nothing
     */
    void pushFront(MyVector v2)
    {

        node *temp = v2.head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            pushFront(temp->data); // print data from node
            temp = temp->next; // move to next node
        }
    }

    /**
     * public : pushRear
     * 
     * Description:
     *      Push an int to the rear of the array
     * 
     * Params:
     *  - int x, to be appended to the array
     *  
     * Returns: 
     *      - nothing
     */
    void pushRear(int x)
    {
        node *tempPtr = new node(x); // create a new node and
                                     // add data to it

        if (!head)
        { // `!head` implies empty list
            // So does `head == NULL`

            head = tempPtr; // `head = tempPtr` places addrress of
                            // tempPtr in head (points head to tempPtr)
            tail = head;    //If its the only object, tail = head always
                            //but will need some code to keep track of tail
        }
        else
        {                         // list not empty
            tail->next = tempPtr; //smack our new data on the end of the list
            tail = tempPtr;       //update the tail
        }
    }

    /**
     * public : pushRear
     * 
     * Description:
     *      Push an existing MyVector to the end of the array
     * 
     * Params:
     *  - MuVector object, to be appended to the array
     *  
     * Returns: 
     *      - nothing
     */
    void pushRear(MyVector v2)
    {

        node *temp = v2.head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            pushRear(temp->data); // print data from node
            temp = temp->next; // move to next node
        }
    }
    
    /**
     * public : pushRear
     * 
     * Description:
     *      Push an existing MyVector to the end of the array
     * 
     * Params:
     *  - MuVector object, to be appended to the array
     *  
     * Returns: 
     *      - nothing
     */
    void pushAt(int loc, int val)
    {
        if(loc < 0) {
            cout << "you're just trolling at this point.";
            return;
        }
        node *newData = new node(val);
        if(!head) {
            head = newData;
        }
        node *temp = head;
        for(int i = 0; i < loc; i++) {
            if(temp->next) {
                temp = temp->next;
            } else {
                cout << "Invalid location, list is only " << i << " in length";
                delete newData;
                //the program literally lasts for 0.3s on my machine but its just too easy
            }
        }
        //temp should equal the correct location

        //required check because the condition inside the loop could pass if loc == tail
        if(temp->next) {
            newData->next = temp->next;
            temp->next = newData;
        } else {
            temp->next = newData;
            tail = newData;
        }

    }

    int popFront() {
        node *temp = head;
        head = head->next;
        return temp->data;
    }
    int popRear() {
        
        node *temp = head; // temp pointer copies head

        while (temp->next != tail)
        { 
            temp = temp->next; // move to next node
        }
        //temp is now the value before tail;
        tail = temp;
        node *rv = temp->next;
        temp->next = NULL;
        return rv->data;

    }

    int popAt(int loc) {
        if(loc < 0) {
            cout << "you're just trolling at this point.";
            return 0;
        }
        node *temp = head;
        node *previous = NULL;
        for(int i = 0; i < loc; i++) {
            if(temp->next) {
                if(i == loc-1) {
                    previous = temp;
                }
                temp = temp->next;
            } else {
                cout << "Invalid location, list is only " << i << " in length";
                //the program literally lasts for 0.3s on my machine but its just too easy
            }
        }
        //temp should equal the correct location
        node *next = temp->next;
        //lol variable names
        previous->next = next;
        return temp->data;
        //required check because the condition inside the loop could pass if loc == tail
    }

    //returns the index, not the value.
    int find(int val) {
        node *temp = head; // temp pointer copies head
        int i = 0;
        while (temp)
        { 
            // this loops until temp is NULL
            // same as `while(temp != NULL)`
            if(val == temp->data) {
                return i;
            }
            temp = temp->next; // move to next node
            i++;
        }
        cout << "Value not found." << endl;
        return -1;
    }


    void print()
    {
        node *temp = head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            cout << temp->data; // print data from node
            if (temp->next)
            {
                cout << "->";
            }
            temp = temp->next; // move to next node
        }
        cout << endl;
    }

    ~MyVector()
    {
    }
};

int main()
{
int x = 0;

MyVector v1;
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print();
// [25, 20, 18, 18, 20, 25]

int A[] = {11,25,33,47,51};
MyVector v2(A,5);
v2.print();
// [11, 25, 33, 47, 51]

v2.pushFront(9);
//v2.inOrderPush(27);
v2.pushRear(63);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]

v1.pushRear(v2);
v1.print();
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
cout<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33]
cout<<x<<endl;
// 47

x = v2.popAt(3);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]
cout<<x<<endl;
// 27

x = v2.find(51);
cout<<x<<endl;
// 5

x = v2.find(99);
cout<<x<<endl;
// -1

MyVector v3(v1);
v3.print();
// [18, 20, 25, 9, 11, 25, 27, 33]

v3.pushFront(v2);
v3.print();
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

MyVector v4("input.dat");
v4.pushRear(v3);
v4.print();

}