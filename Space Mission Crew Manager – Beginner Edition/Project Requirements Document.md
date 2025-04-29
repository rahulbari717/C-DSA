# 1. Project Requirements Document

## 1.1 Overview
The Crew Management System (CMS) is designed to track and manage astronaut personnel for space missions. It allows users to input, store, search, and display information about astronauts with different roles.

## 1.2 Functional Requirements
| ID | Requirement | Description |
|-----|-------------|-------------|
| FR-1 | Variable Crew Size | System shall allow users to specify any number of astronauts to manage. |
| FR-2 | Astronaut Information | System shall collect and store name, age, and ID for each astronaut. |
| FR-3 | Role Classification | System shall categorize astronauts as either Pilots or Scientists. |
| FR-4 | Role-Specific Data | System shall store flight hours for Pilots and specialization for Scientists. |
| FR-5 | Display All Records | System shall provide functionality to display all astronaut records in formatted output. |
| FR-6 | Search Capability | System shall allow users to search for specific astronauts by ID. |
| FR-7 | Memory Management | System shall properly allocate and free memory as required. |
| FR-8 | Menu Interface | System shall provide a simple menu-driven interface using function pointers. |

| ID    | Requirement      | Description |
|-------|------------------|-------------|
| NFR-1 | Dynamic Memory   | System shall use dynamic memory allocation for astronaut records. |
| NFR-2 | Data Structures  | System shall utilize structs, unions, typedefs, arrays, and strings. |
| NFR-3 | Modular Design   | System shall be organized into logical functions and modules. |
| NFR-4 | Error Handling   | System shall validate user inputs and handle memory allocation failures. |
| NFR-5 | Clean Exit       | System shall release all allocated memory on program termination. |