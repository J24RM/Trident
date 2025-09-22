# Pokedex in C++

## 📌 Description
This program implements an **interactive Pokedex** in C++. It allows you to:
- Load a list of Pokémon from a file (`pokemons.txt`).  
- Add new Pokémon and save them to the file.  
- Display the list of registered Pokémon.  
- Automatically keep the list sorted by Pokédex number using **Merge Sort**.  

The program simulates Professor Oak’s Pokedex, showing a simple menu to interact with the registered Pokémon.  

---

## Compilation and Execution

To compile:  
```bash
g++ main.cpp -o main
```

To run:

```bash
./main
```
⚠️ Important: the pokemons.txt file must be in the same folder as main.cpp and the executable.

---

🎯 # Competencies Developed
## SICT0301: Evaluate Components

A complexity analysis of the Merge Sort algorithm was performed:

-Best case: O(n log n)

-Average case: O(n log n)

-Worst case: O(n log n)

This guarantees efficient sorting of Pokémon even as the list grows.

## SICT0302: Decision Making

Algorithm selection:
For this program, Merge Sort was chosen because:

-It is an efficient and stable algorithm for sorting objects.

-Its worst case is better than algorithms such as Bubble Sort or Insertion Sort.
