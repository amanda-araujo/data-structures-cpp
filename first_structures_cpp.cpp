//
// Created by Amanda on 10/03/2025.
//
/* Most common data structures:
 * Vector
 * List
 * Stack (Pilha): LIFO
 * Queue (Fila): FIFO
 * Deque: double-ended queue
 * Set
 * Map (dictionary): key/value pairs
 *
 * C++ STL: Stardard Template Library
 */

#include <iostream>
#include <vector> // Vector library
#include <list>   // List library
#include <stack>  // Stack library
#include <set>    // Set library
#include <map>    // Map library
#include <queue>  // Queue library
using namespace std; // To write 'string', otherwise std::string

// DATA STRUCTURES
// Vector: vector<Type> name;
vector<string> animals = {"Dog", "Cat", "Bird"}; // Create a vector
vector<string> cars = {"Ferrari", "BMW", "Volvo"};

// List: list<Type> listName;
list<int> bingo = {11, 27, 31, 40, 56}; // Create a list

// Stack: stack<Type> nameStack;
//stack<char> panquecas = {'a', 'b', 'c', 'd', 'e'}; // ERROR
/* C++ does not provide a direct way to initialize a stack with
 * elements upon declaration */
stack<char> pancake; // Create a stack

int main() {

    // Print vector elements
    for (string animal : animals) { // for-each loop
        cout << animal << "\n";
    }

    // Access a Vector
    cout << animals[0] << endl; // Get first element
    cout << animals.front() << endl; // First element
    cout << animals.back() << endl;  // Last element
    cout << animals.at(2) << endl; // Specified index
    //cout << animals.at(3) << endl; // out of range!
    /*.at() function is often preferred over square brackets [] because
     * it lets you know if an error occurs.*/

    // Change a Vector Element
    cout << cars[0] << endl;
    cars[0] = "Ford";
    cout << cars[0] << endl;
    cars.at(0) = "BYD";
    cout << cars.at(0) << endl;

    // Add Vector Elements
    cars.push_back("Ferrari"); // Add element at the end
    for (string car : cars) { cout << car << endl; };
    cars.pop_back(); // Remove element from the end
    for (string car : cars) { cout << car << endl; };
    cars.pop_back(); // Remove element from the end
    for (string car : cars) { cout << car << endl; };
    /* Elements are usually only added and removed from the end of the vector.
     * If you need to add or remove elements from both ends, it is often
     * better to use a deque instead of a vector.*/

    cout << cars.size() << endl; // Vector Size
    cout << cars.empty() << endl; // Bool: checks if empty
    for (int i = 0; i < cars.size(); i++) { cout << cars[i] << endl; }; // for loop
    /*It is also possible to loop through vectors with an iterator,
     *which you will learn more about in a later chapter.*/

    // Print list elements
    for (int bin : bingo) { cout << bin << endl; }; // for-each loop

    // Access list: NO referring to index numbers :( .front() and .back()
    cout << bingo.front() << endl; // First element list
    cout << bingo.back() << endl;  // Last element list

    // Change list element: .front() and .back()
    bingo.front() = 10;
    bingo.back() = 57;
    cout << bingo.front() << endl;
    cout << bingo.back() << endl;

    // Add list elements
    bingo.push_front(2); // Add at beginning
    bingo.push_back(60); // Add at the end
    for (int bin : bingo) { cout << bin << endl; }; // for-each loop

    // Remove list elements
    bingo.pop_front();
    bingo.pop_back();
    bingo.pop_back();
    bingo.pop_back();
    for (int bin : bingo) { cout << bin << endl; }; // for-each loop

    cout << bingo.size() << endl;  // List size
    cout << bingo.empty() << endl; // Check list empty (bool)

    // Add elements to the stack
    pancake.push('a'); // Add to the top of the stack
    pancake.push('b');
    pancake.push('c');

    // Access stack elements: can only access the top element
    cout << pancake.top() << endl; // The last element added

    //Change the top element
    pancake.top() = 'd'; // Change value of top element
    cout << pancake.top() << endl;

    // for (char pan : pancake) { cout << pan << endl; }; // ERROR
    /* It is not possible to use a range-based for loop (for-each loop)
     * directly with std::stack in C++, because std::stack does not provide
     * iterators*/
    // Print stack elements



    return 0;
}

/* Vectors
 * Main difference array vs. vector C++:
 * * Vectors can grow or shrink in size, but arrays cannot
 * Header file to use vectors in C++: <vector>
 */

/* Lists
 * Store multiple elements of the same type and dynamically grow in size
 * Add and remove from beginning and end of a list
 * List does not support random access (ex. index)
 */

/* Stack
 * Specific order: LIFO - Last In, First Out
 * Elements not accessed by index
 * Can only access element on top of the stack
 */