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
*        This program supplies and tests a robust vector that can grow, shrink
*        add values to the front, end, or specified location from a number of inputs
*        basically its a data type that is actually usable (as long as your program
*        has a short life, as this does NOT clean itself up in memory. I don't think
*        we are there in class.)
* 
*  Usage:
*        ./main
         ./input.dat
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
            pushRear(A[i]);
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


    /**
     * public : popFront
     * 
     * Description:
     *      pop an int from the front of the vector
     * 
     * Params:
     *  - none
     *  
     * Returns: 
     *      - 1 int, from front of array
     */
    int popFront() {
        node *temp = head;
        head = head->next;
        return temp->data;
    }
    /**
     * public : popFront
     * 
     * Description:
     *      pop an int from the rear of the vector
     * 
     * Params:
     *  - none
     *  
     * Returns: 
     *      - 1 int, from rear of array
     */
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
    /**
     * public : popAt
     * 
     * Description:
     *      pop an int from a specified index of the array
     * 
     * Params:
     *  - int location, the location of the int you want
     *  
     * Returns: 
     *      - one int, from the supplied location
     */
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

    /**
     * public : find
     * 
     * Description:
     *      looks through the vector for a value matching the inputted one
     *      returns the index of that integer, not the value
     * 
     * Params:
     *  - int value, the integer you're looking for
     *  
     * Returns: 
     *      - one int, the index of the value.
     */
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

    /**
     * public : print
     * 
     * Description:
     *      Writes output of vector to a supplied file.
     * 
     * Params:
     *  - ofstream file, a file to write to.
     *  
     * Returns: 
     *      - nothing
     */
    void print(ofstream& file)
    {
        node *temp = head; // temp pointer copies head
        file << "[";
        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`
            file << temp->data; // print data from node
            if (temp->next)
            {
                file << ", ";
            }
            temp = temp->next; // move to next node
        }
        file << "]" << endl;
    }


    /**
     * public : print
     * 
     * Description:
     *      prints the contents of the vector to console
     * 
     * Params:
     *  - nothing
     *  
     * Returns: 
     *      - nothing
     */
    void print()
    {
        node *temp = head; // temp pointer copies head
        cout << "[";
        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            cout << temp->data; // print data from node
            if (temp->next)
            {
                cout << ", ";
            }
            temp = temp->next; // move to next node
        }
        cout << "]" << endl;
    }

    ~MyVector()
    {
    }
};

    int main() {

        ofstream file;
        file.open("test.out");
        cout << "Dylan Miles" << endl;
        cout << "Sept 9, 2021" << endl;
        cout << "Fall 2143" << endl;


        file << "Dylan Miles" << endl;
        file << "Sept 9, 2021" << endl;
        file << "Fall 2143" << endl;
        int x = 0;

        MyVector v1;
        v1.pushFront(18);
        v1.pushFront(20);
        v1.pushFront(25);
        v1.pushRear(18);
        v1.pushRear(20);
        v1.pushRear(25);
        v1.print();
        v1.print(file);
        // [25, 20, 18, 18, 20, 25]

        int A[] = {11,25,33,47,51};
        MyVector v2(A,5);
        v2.print();
        v2.print(file);
        // [11, 25, 33, 47, 51]

        v2.pushFront(9);
        //v2.inOrderPush(27);
        v2.pushRear(63);
        v2.print();
        v2.print(file);
        // [9, 11, 25, 33, 47, 51, 63]

        v1.pushRear(v2);
        v1.print();
        v1.print(file);
        // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

        x = v1.popFront();
        x = v1.popFront();
        x = v1.popFront();
        v1.print();
        v1.print(file);
        // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
        cout<<x<<endl;
        file<<x<<endl;
        // 18

        x = v1.popRear();
        x = v1.popRear();
        x = v1.popRear();
        v1.print();
        v1.print(file);
        // [18, 20, 25, 9, 11, 25, 27, 33]
        cout<<x<<endl;
        file<<x<<endl;
        // 47

        x = v2.popAt(3);
        v2.print();
        v2.print(file);
        // [9, 11, 25, 33, 47, 51, 63]
        cout<<x<<endl;
        file<<x<<endl;
        // 27

        x = v2.find(51);
        cout<<x<<endl;
        file<<x<<endl;
        // 5

        x = v2.find(99);
        cout<<x<<endl;
        file<<x<<endl;
        // -1

        MyVector v3(v1);
        v3.print();
        v3.print(file);
        // [18, 20, 25, 9, 11, 25, 27, 33]

        v3.pushFront(v2);
        v3.print();
        v3.print(file);
        //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

        MyVector v4("input.dat");
        v4.pushRear(v3);
        v4.print();
        v4.print(file);

        file.close();
    }