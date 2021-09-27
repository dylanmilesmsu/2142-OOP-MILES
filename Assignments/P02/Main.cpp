/*****************************************************************************
*
*  Author:           Dylan Miles
*  Email:            dylanbmiles@gmail.com
*  Label:            P02
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

    node* next; // we always need a "link" in a linked list

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
void loadArr(string filename, int*& arr, int& size)
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
void printArr(int* arr, int size)
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
    node* head; // base pointer of list
    node* tail; // pointer to end of list
public:
//Overrides the '<<' operator and prints the contents of the list 
    friend ostream& operator<<(ostream& out, const MyVector& vec) {
        node* temp = vec.head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            out << temp->data; // print data from node
            if (temp->next)
            {
                out << "->";
            }
            temp = temp->next; // move to next node
        }
        out << endl;
        return out;
    }
//Overrides the '<<' operator and writes the contents of the list to an ofstream
    friend ostream& operator<<(ofstream& out, const MyVector& vec) {
        node* temp = vec.head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            out << temp->data; // print data from node
            if (temp->next)
            {
                out << "->";
            }
            temp = temp->next; // move to next node
        }
        out << endl;
        return out;
    }


  
//Overrides the '[]' operator and returns a reference to an int at a given index
    int& operator[](const int num) {
        node* temp = head;
        for (int i = 0; i < num; i++) {
            if (temp->next) {
                temp = temp->next;
            }
        }
        return temp->data;

    }
//Overrides the '+' operator and adds the values of two lists together.
    MyVector operator+(const MyVector rhs) {
        MyVector newVector;
        node* temp = head; // temp pointer copies head
        node* rhstemp = rhs.head;
        while (temp && rhstemp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`
            int newVal = temp->data + rhstemp->data;
             newVector.pushRear(newVal);
            rhstemp = rhstemp->next;
            temp = temp->next; // move to next node
        }
        while(temp) {
            newVector.pushRear(temp->data);
            temp = temp->next;
        }
        while(rhstemp) {
            newVector.pushRear(rhstemp->data);
            rhstemp = rhstemp->next;
        }
        return newVector;
    }
//Overrides the '-' operator and subtracts the values of two lists together.
    MyVector operator-(const MyVector rhs) {
        MyVector newVector;
        node* temp = head; // temp pointer copies head
        node* rhstemp = rhs.head;
        while (temp && rhstemp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`
            int newVal = temp->data - rhstemp->data;
             newVector.pushRear(newVal);
            rhstemp = rhstemp->next;
            temp = temp->next; // move to next node
        }
        while(temp) {
            newVector.pushRear(temp->data);
            temp = temp->next;
        }
        while(rhstemp) {
            newVector.pushRear(rhstemp->data);
            rhstemp = rhstemp->next;
        }
        return newVector;
    }
    //Overrides the '*' operator and multiplies the values of two lists together.
    MyVector operator*(const MyVector rhs) {
        MyVector newVector;
        node* temp = head; // temp pointer copies head
        node* rhstemp = rhs.head;
        while (temp && rhstemp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`
            int newVal = temp->data * rhstemp->data;
             newVector.pushRear(newVal);
            rhstemp = rhstemp->next;
            temp = temp->next; // move to next node
        }
        while(temp) {
            newVector.pushRear(temp->data);
            temp = temp->next;
        }
        while(rhstemp) {
            newVector.pushRear(rhstemp->data);
            rhstemp = rhstemp->next;
        }
        return newVector;
    }
        //Overrides the '/' operator and divides the values of two lists together.
    MyVector operator/(const MyVector rhs) {
        MyVector newVector;
        node* temp = head; // temp pointer copies head
        node* rhstemp = rhs.head;
        while (temp && rhstemp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`
            int newVal = temp->data / rhstemp->data;
             newVector.pushRear(newVal);
            rhstemp = rhstemp->next;
            temp = temp->next; // move to next node
        }
        while(temp) {
            newVector.pushRear(temp->data);
            temp = temp->next;
        }
        while(rhstemp) {
            newVector.pushRear(rhstemp->data);
            rhstemp = rhstemp->next;
        }
        return newVector;
    }
        //Overrides the '==' operator and checks if two list equal each other
    bool operator==(const MyVector rhs) {
        node* temp = head; // temp pointer copies head
        node* rhstemp = rhs.head;
        bool listsAreTheSame = true;
        
        while (temp && rhstemp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`
            if(temp->data != rhstemp->data) {
                 listsAreTheSame = false;
                 break;
            }
            rhstemp = rhstemp->next;
            temp = temp->next; // move to next node
        }
        if(temp || rhstemp) {
            listsAreTheSame = false;
        }
        return listsAreTheSame;
    }
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

        node* temp = other.head; // temp pointer copies head

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
        node* tempPtr = new node(x); // create a new node and
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

        node* temp = v2.head; // temp pointer copies head

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
        node* tempPtr = new node(x); // create a new node and
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

        node* temp = v2.head; // temp pointer copies head

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
        if (loc < 0) {
            cout << "you're just trolling at this point.";
            return;
        }
        node* newData = new node(val);
        if (!head) {
            head = newData;
        }
        node* temp = head;
        for (int i = 0; i < loc; i++) {
            if (temp->next) {
                temp = temp->next;
            }
            else {
                cout << "Invalid location, list is only " << i << " in length";
                delete newData;
                //the program literally lasts for 0.3s on my machine but its just too easy
            }
        }
        //temp should equal the correct location

        //required check because the condition inside the loop could pass if loc == tail
        if (temp->next) {
            newData->next = temp->next;
            temp->next = newData;
        }
        else {
            temp->next = newData;
            tail = newData;
        }

    }

    int popFront() {
        node* temp = head;
        head = head->next;
        return temp->data;
    }
    int popRear() {

        node* temp = head; // temp pointer copies head

        while (temp->next != tail)
        {
            temp = temp->next; // move to next node
        }
        //temp is now the value before tail;
        tail = temp;
        node* rv = temp->next;
        temp->next = NULL;
        return rv->data;

    }

    int popAt(int loc) {
        if (loc < 0) {
            cout << "you're just trolling at this point.";
            return 0;
        }
        node* temp = head;
        node* previous = NULL;
        for (int i = 0; i < loc; i++) {
            if (temp->next) {
                if (i == loc - 1) {
                    previous = temp;
                }
                temp = temp->next;
            }
            else {
                cout << "Invalid location, list is only " << i << " in length";
                //the program literally lasts for 0.3s on my machine but its just too easy
            }
        }
        //temp should equal the correct location
        node* next = temp->next;
        //lol variable names
        previous->next = next;
        return temp->data;
        //required check because the condition inside the loop could pass if loc == tail
    }

    //returns the index, not the value.
    int find(int val) {
        node* temp = head; // temp pointer copies head
        int i = 0;
        while (temp)
        {
            // this loops until temp is NULL
            // same as `while(temp != NULL)`
            if (val == temp->data) {
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
        node* temp = head; // temp pointer copies head

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
int a1[] = { 1, 2, 3, 4, 5 };
int a2[] = { 10, 20, 30 };

MyVector v1(a1,5);
MyVector v2(a2,3);

ofstream fout;
fout.open("output.txt");

cout << v1[2] << endl;
// writes out 3

v1[4] = 9;
// v1 now = [1,2,3,4,9]

cout << v1 << endl;
// writes out [1,2,3,4,9] to console.

fout << v1 << endl;
// writes out [1,2,3,4,9] to your output file.

MyVector v3 = v1 + v2;
cout << v3 << endl;
// writes out [11,22,33,4,9] to console.

v3 = v1 - v2;
cout << v3 << endl;
// writes out [-9,-18,-27,4,9] to console.

v3 = v2 - v1;
cout << v3 << endl;
// writes out [9,18,27,4,9] to console.

v3 = v2 * v1;
cout << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 * v2;
cout << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 / v2;
cout << v3 << endl;
// writes out [0,0,0,4,9] to console.

v3 = v2 / v1;
cout << v3 << endl;
// writes out [10,10,10,4,9] to console.

cout << (v2 == v1) << endl;
// writes 0 to console (false) .

MyVector v4 = v1;
cout << (v4 == v1) << endl;
// writes 1 to console (true) .
}