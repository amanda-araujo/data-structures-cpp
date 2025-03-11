//
// Created by Amanda Araujo on 10/03/2025.
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
 * C++ STL: Standard Template Library
 */

#include <iostream>
#include <vector> // Vector library
#include <list>   // List library
#include <stack>  // Stack library
#include <queue>  // Queue library
#include <deque>  // Deque library
#include <set>    // Set library
#include <map>    // Map library
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

// Queue: queue<Type> nameQueue;
queue<string> fila; // Create a queue; NOT possible to declare elements

// Deque: deque<Type> dequeName; Can be declared :)
deque<int> china;
deque<int> japan = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Set: set<Type> setName;
// Automatically ascending order
set<string> set1 = {"Journal", "News", "Alphabeth"};
set<int> setIntA = {3000, 2000, 7000, 1000};
// Descending: set<Type, greater<Type> setName;
set<string> set2 = {"Journal", "News"};
set<int, greater<int>> setIntD = {3000, 2000, 7000, 1000}; // Descending order

// Map: map<keyType, valueType> mapName;
map<char, int> hotel = {{'a', 1}, {'b', 2}};

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
    for (char c : {'d', 'e', 'f', 'g'}) {
        pancake.push(c);
    };

    // Access stack elements: can only access the top element
    cout << pancake.top() << endl; // The last element added

    //Change the top element
    pancake.top() = 'z'; // Change value of top element
    cout << pancake.top() << endl;

    // Remove elements
    pancake.pop(); // Remove last element added to the stack

    // for (char pan : pancake) { cout << pan << endl; }; // ERROR
    /* It is not possible to use a range-based for loop (for-each loop)
     * directly with std::stack in C++, because std::stack does not provide
     * iterators*/
    // Print stack elements

    // while (!pancake.empty()) {
    //     cout << pancake.top() << endl;
    //     pancake.pop(); // Remove last = top element
    // } // Remove all elements at the end empty
    stack<char> pancakeTemp = pancake; // Interate using a copy
    while (!pancakeTemp.empty()) {
        cout << pancakeTemp.top() << endl;
        pancakeTemp.pop();
    }

    cout << pancake.size() << endl;  // Size of the stack
    cout << pancake.empty() << endl; // Check stack empty (bool)

    // Add elements queue
    fila.push("Amadeus");
    fila.push("Bethoveen");
    for (string name : {"Celio", "Domenicus", "Emil"}) {fila.push(name);};

    // Print queue (just like stack)
    queue<string> filaTemp = fila; // Interate using a copy
    while (!filaTemp.empty()) { // First to last
        cout << filaTemp.front() << endl;
        filaTemp.pop(); // Remove front element (oldest)
    }

    // Access queue elements: only front or the back
    cout << fila.front() << endl; // First = oldest element
    cout << fila.back() << endl;  // Last = newest element

    // Change elements queue: front and back
    fila.front() = "Andrius"; // Change value first = front element
    fila.back() = "Zózimo";   // Change value last = back element
    cout << fila.front() << endl;
    cout << fila.back() << endl;

    cout << fila.size() << endl; // Size of a queue

    // Remove elements
    fila.pop(); // Remove front = first = oldest element
    fila.pop();

    cout << fila.size() << endl; // Size of a queue
    cout << fila.empty() << endl; // Check queue empty

    // Deque
    // Print deque elements
    if (!china.empty()) { // fro-each loop
        for (int n : china) { cout << n << endl; }
    } else cout << "China empty" << endl;
    for (int n : japan) { cout << n << endl; };

    // Add deque elements
    china.push_front(71); // Add at the beginning
    china.push_back(72);  // Add at the end
    for (int n : china) { cout << n << endl; };

    // Access a deque
    cout << japan[0] << endl; // Access by index
    cout << japan[7] << endl;
    cout << japan.at(7) << endl; // Safer to use .at()
    cout << china.front() << endl; // First element
    cout << china.back() << endl;  // Last element

    // Change a deque element
    china.at(0) = 81;
    china.at(1) = 82;
    cout << china.front() << endl;
    cout << china.back() << endl;

    // Remove deque elements
    for (int n : japan) { cout << n << endl; };
    japan.pop_front(); // Remove first element
    japan.pop_back();  // Remove last element
    for (int n : japan) { cout << n << endl; };

    cout << "Sum sizes: " << china.size() + japan.size() << endl; // Deque size

    while (!japan.empty()) { japan.pop_front(); } // Check deque empty
    while (!china.empty()) { china.pop_back(); }
    cout << "Sum sizes: " << china.size() + japan.size() << endl; // Deque size

    // Print set elements: for-each loop
    for (string w : set1) { cout << w << endl; }; // ascending
    for (string w : set2) { cout << w << endl; }; // descending
    for (int n : setIntA) { cout << n << endl; }; // ascending
    for (int n : setIntD) { cout << n << endl; }; // descending

    // Add elements set
    set1.insert("Candy");
    set1.insert("Candy");
    set1.insert("News");
    for (int n : {4500, 2500, 3500}) { setIntA.insert(n); }

    for (string w : set1) { cout << w << endl; };
    for (int n : setIntA) { cout << n << endl; };

    // Remove elements from a set
    set1.erase("News"); // Remove specific element
    set1.erase("Candy");
    for (string w : set1) { cout << w << endl; };
    set1.clear(); // Remove all elements
    for (string w : set1) { cout << w << endl; };

    cout << set1.size() << endl;  // Size of set
    cout << set1.empty() << endl; // Check set empty (bool)

    // Maps
    // Print map
    /* - should use auto keyword: automatically determine the correct
     * data type fro each key-value pair
     * - .first: access key | .second: access value
     * - ascending order by key (auto)
     */
    for (auto h : hotel) { // for-each loop
        cout << h.first << " is: " << h.second << endl;
    }

    // Access map (by key)
    cout << "a is: " << hotel['a'] << endl;      // Value associated to key 'a'
    cout << "a is: " << hotel.at('a') << endl; // Value associated to key 'b'

    // Change values map
    hotel['a'] = 101;
    cout << "a is: " << hotel.at('a') << endl; // safer .at

    // Add elements map: ok to use brakets []
    hotel['c'] = 3; // Add pair key/value
    hotel['d'] = 4;
    hotel.insert({'e', 5}); // Add pair key/value
    hotel.insert({'f', 6}); // no repetition; keeps the first
    for (auto h : hotel) { // for-each loop
        cout << h.first << " is: " << h.second << endl;
    }

    // Check existence of an element
    cout << hotel.count('b') << endl; // 1 (true) if elem exists (bool)

    // Remove elements map
    hotel.erase('a'); // Remove specific element (pair key/value)
    hotel.clear();      // Remove all elements

    cout << hotel.size() << endl;  // Size of map
    cout << hotel.empty() << endl; // Check map empty

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

/* Queue: fila
 * FIFO - First In, First Out
 * Elements not accessed by index
 * Added at the end, removed from the front
 * Can only access element on the front or the back
 */

/* Deque: Double-Ended-QUEUE
 * Elements can be added/removed from both sides front/back
 * Access by index (!)
 */

/* Sets: mathematical sets
 * Automatically sorted in ascending order
 * Elements are unique, duplicates ignored
 * Can add/remove elements, but CANNOT change element value
 * Cannot be access by index (based on sorting)
 * A estrutura menos estruturada | mais solta
 */

/* Maps (Python dictionary)
 * Key/Value pairs
 * Each key is unique
 * Automatically sorted in ascending order by Key
 * Cannot be access by index (based on sorting)
 * It is also possible to loop through maps with an iterator.
 */