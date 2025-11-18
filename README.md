# Pokedex in C++

## 📌 Description
This program implements an **interactive Pokedex** in C++. It allows you to:
- Load a list of Pokémons from a file (`pokemones.txt`).  
- Add new Pokémons and save them to the file.  
- Display the list of registered Pokémons.  
- Automatically keep the list sorted by Pokédex number using **Merge Sort**.  

The program simulates Professor Oak’s Pokedex, showing a simple menu to interact with the registered Pokémons.  

---

## Compilation and Execution

To compile:  
```bash
g++ main.cpp sorting.cpp Historial.cpp Menun.cpp Pfunc.cpp -o main
```

To run:

```bash
./main
```
⚠️ Important: the pokemones.txt file must be in the same folder as main.cpp and the executable.

---

# 🎯 Competencies Developed
## SICT0301: Evaluate Components

### Performs a correct and complete complexity analysis for the sorting algorithms used in the program.

A complexity analysis of the Merge Sort algorithm was performed:

- Best case: O(n log n)

- Average case: O(n log n)

- Worst case: O(n log n)

This algorithm also requires $O(n)$ auxiliary space for the temporary vector used during the merging process. 
This guarantees efficient and predictable sorting performance, which is crucial as the function is called every time a new Pokémon is added to maintain the list's order.

### It performs a correct and complete complexity analysis of all data structures and each of their uses in the program.

An analysis was performed in the  data structures used in the program: std::stack.

A LIFO (Last-In, First-Out) container used to store a log of user actions.

- Saving Action (historial.push): Adding a new action to the top of the stack (used in Menu Options 1, 2, 3, 4) is a constant time operation: O(1).
- Viewing History (Menu Option 4): This involves creating a copy of the stack and then popping h (history size) elements one by one. This operation is O(h).
- Viewing Consulted Pokémon (Menu Option 5): This iterates through a copy of the history stack (O(h)) and, for each relevant entry, performs a linear search on the Pokémon vector (O(n)). The total complexity for this operation is O(h * n).

### Performs a correct and complete complexity analysis for the other components of the program 

#### Menu Option 2 (Ver Pokemones)

His complexity is O(n) because it iterates through all the vector that contains the pokemones 

#### Menu Option 3 (Consultar Pokemon)

Its complexity is O(n) in the worst case because the program searches through all the vector of the pokemones until it encounters the selected Pokémon, if the Pokémon is at the end of the list the program would search through all the vector of pokemones.

#### Cargar Pokes

His complexity is O(n) because the program reads through the entire file.txt to load all the Pokemons saved in the file.txt

#### Complexity of all the program

- Best Case (O)n : Selecting Menu option 2, 3, because their complexity is O(n) + the saving action to history which has O(1) complexity, making the total complexity O(n). For Menu option 4, the complexity is O(n) + O(1) for the saving action, resulting in O(n).
  
- Average case O(n log n): This occurs when we choose Option 1 (Agregar Pokemon). The complexity is O(1) for the function's internal operations + O(n log n) for Merge Sort + O(1) for the saving action, which results in O(n log n).

- Worst case O(n * h): Selecting Menu Option 5 iterates through the entire history stack in O(h). For each entry that is a Pokémon query, the program performs a linear search in the pokemones vector in O(n). Assuming that all the entries are Pokémon queries, the complexity is O(h * n).

## SICT0302: Decision Making

### Select a sorting algorithm appropriate to the problem and use it correctly.

For this program, Merge Sort (ordenaMerge) was chosen. This choice is justified for the following reasons:

- Guaranteed Efficiency: Merge Sort has a consistent time complexity of O(n log n) in all cases (best, average, and worst). This is critical because the list is sorted not only on initialization but also every time a new Pokémon is added (Menu Option 1). Using an algorithm with a poor worst-case (like Quick Sort's O(n^2) or Insertion Sort O(n^2)) would lead to significant lag as the Pokedex list grows.

- Stability: Merge Sort is a stable sort. While Pokédex numbers are unique in this problem, stability is a good property for sorting objects, as it preserves the relative order of equivalent elements.

- Use Case: The algorithm is correctly applied in main.cpp after loading the initial data and in Menun.cpp after a new Pokémon is added, ensuring the pokemons vector remains sorted by Npoke at all times (except during the sorting process itself).

### Select a data structure appropriate to the problem and use it correctly.

std::stack<Historial>: This structure was chosen to manage the log of user actions.

- Justification: A stack is a LIFO (Last-In, First-Out) structure. This is a perfect model for a history log, where the user is typically most interested in the most recent action. When viewing the history, the last action performed is the first one shown.

- Complexity: The stack provides highly efficient O(1) complexity for its main operations: push (adding a new history entry) and top (viewing the most recent entry). This ensures that logging actions has a negligible impact on performance.

## SICT0303: Implement scientific solutions.

### Implement mechanisms to query information from the correct structures.

std::stack<Historial>: Information is consulted by creating a temporary copy of the original stack (stack<Historial> tempHis = his;).

- Reasoning: This is done to preserve the original history. A stack can only be traversed by "destroying" it .

- Mechanism: A while (!tempHis.empty()) loop is used. Inside the loop, tempHis.top() accesses the most recent action to display it, and tempHis.pop() removes it to allow access to the next item. This process repeats until the temporary stack is empty, displaying all history items from most recent to oldest.

### Implements file reading mechanisms to correctly load data into structures.

The program uses the C++ <fstream> library to handle file I/O for the pokemons.txt file.

#### Reading Data (cargarPokes):

- An std::ifstream object is used to open the file for reading.

- std::getline(archivo, linea) reads the file one line at a time.

- For each line, an std::istringstream is used to treat the linea string as a stream.

- std::getline(ss, field, ';') is called repeatedly to extract each piece of data, using the semicolon (;) as a delimiter.

- The Pokémon number (a string) is converted to an integer using std::stoi.

- A new Pokemon object is created with this data and added to the std::vector<Pokemon> using pokemons.push_back(poke).

#### Writing Data (agregarPoke):

- An std::fstream object is opened using fstream::app (append mode). This ensures that new data is added to the end of the file without deleting existing content.

- The new Pokémons data is formatted into a single string (Text) separated by semicolons, followed by a newline character (\n).

- The << operator is used to write this string to the file, and archivo.close() saves the changes.
