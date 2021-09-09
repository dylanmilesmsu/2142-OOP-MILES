/**
*                    
*  Author:           Terry
*  Title:            Linked List Example
*  Course:           2143
*  Semester:         Fall 2021
* 
*  Description:
*        Linked List Example 
* 
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Node for our linked list
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
            PushFront(A[i]);
        }
    }

    MyVector(const MyVector& other) {
        head = tail = NULL;

        node *temp = other.head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            PushRear(temp->data); // print data from node
            temp = temp->next; // move to next node
        }
    }

    MyVector(string filename)
    {
        head = tail = NULL; // NULL = zeros
        int size;
        int* array;
        loadArr(filename, array, size);
         for (int i = 0; i < size; i++)
        {
            PushFront(array[i]);
        }


    }


    void PushFront(int x)
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

    void PushFront(MyVector v2)
    {

        //this adds in the wrong order
        //I could make this a doubly linked list, or 
        //I could just add the old values to the new list and return that instead.

        node *temp = v2.head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            PushFront(temp->data); // print data from node
            temp = temp->next; // move to next node
        }
    }

    void PushRear(int x)
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

    void PushRear(MyVector v2)
    {

        node *temp = v2.head; // temp pointer copies head

        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            PushRear(temp->data); // print data from node
            temp = temp->next; // move to next node
        }
    }

    void PushAt(int loc, int val)
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
    int* ez = new int[5] {0};
    ez[0] = 1;
    ez[1] = 2;
    MyVector pz(ez, 6);
    pz.print();
    int A[] = {1, 2, 3, 4, 5, 6}; // array initialized with 1-6
   MyVector azz("input.dat");
   azz.print();

   MyVector copy(azz);
   copy.print();


    cout << "ez" << endl;
    copy.PushFront(pz);
    copy.print();
    copy.PushRear(pz);
    copy.print();
    copy.PushAt(3, 999);
    copy.print();
    int x = copy.popFront();
    cout << endl << x << endl;
    copy.print();
    int r = copy.popRear();
    cout << "THE REAR" << endl << r << endl;
    copy.print();
    int pa = copy.popAt(5);
    cout << " PA " << pa << endl;
    copy.print();
    int index = copy.find(786);
    cout << "INDEX: " << index << endl;
    int foundn = copy.popAt(index);
    cout << "FOUND VALUE: " << foundn << endl;
}