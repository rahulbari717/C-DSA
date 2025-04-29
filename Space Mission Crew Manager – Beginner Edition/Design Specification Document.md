## 2. Design Specification Document

### 2.1 Data Structure Design

#### 2.1.1 Astronaut Structure
```c
typedef struct {
    char name[50];    // Astronaut's name
    int age;          // Astronaut's age
    char id[10];      // Unique identifier (e.g., A001)
    int role;         // 1 for Pilot, 2 for Scientist
    union {
        int flightHours;          // For Pilots
        char specialization[50];  // For Scientists
    } roleDetails;
} Astronaut;
```

### 2.2 Function Specifications

#### 2.2.1 Core Functions

| Function | Description | Parameters | Return Value |
|----------|-------------|------------|--------------|
| `Astronaut* allocateAstronautMemory(int count)` | Allocates memory for astronaut array | count: Number of astronauts | Pointer to allocated array or NULL on failure |
| `void getAstronautDetails(Astronaut* astronauts, int count)` | Gets details for all astronauts | astronauts: Array pointer, count: Number of astronauts | None |
| `void displayAllAstronauts(Astronaut* astronauts, int count)` | Displays all astronaut records | astronauts: Array pointer, count: Number of astronauts | None |
| `void searchAstronautById(Astronaut* astronauts, int count)` | Searches for an astronaut by ID | astronauts: Array pointer, count: Number of astronauts | None |
| `void exitProgram(Astronaut* astronauts, int count)` | Frees memory and exits | astronauts: Array pointer, count: Number of astronauts | None |

#### 2.2.2 Helper Functions

| Function | Description | Parameters | Return Value |
|----------|-------------|------------|--------------|
| `void displayMenu()` | Displays the menu options | None | None |
| `int getMenuChoice()` | Gets user's menu selection | None | Integer choice |
| `void clearInputBuffer()` | Clears stdin buffer | None | None |

### 2.3 Function Pointer Design
```c
// Array of function pointers for menu operations
typedef void (*MenuFunction)(Astronaut*, int);

MenuFunction menuFunctions[3] = {
    displayAllAstronauts,  // Option 1
    searchAstronautById,   // Option 2
    exitProgram            // Option 3
};
```

### 2.4 Program Flow

1. User inputs number of astronauts
2. System allocates memory for astronaut records
3. User inputs details for each astronaut
4. System displays menu options
5. User selects menu option
6. System executes corresponding function via function pointer
7. Steps 4-6 repeat until user selects exit option
8. System frees memory and terminates