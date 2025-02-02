# Student-Management-System
1. Overview
The Student Management System (SMS) is a console-based program written in C, designed to manage student records efficiently. It provides operations like adding, editing, deleting, searching, and displaying student details, along with file handling for data persistence.

2. Key Features
✅ Dynamic Memory Allocation – Uses malloc() and realloc() to manage an expandable list of students.
✅ CRUD Operations – Add, update, delete, and search student records.
✅ Data Persistence – Saves and loads student records from a text file (students.txt).
✅ Validation & Error Handling – Prevents duplicate roll numbers, invalid inputs, and ensures proper memory management.
✅ Menu-Driven Approach – User-friendly interface for navigation.

3. Technologies & Concepts Used
Programming Language: C
Data Structures: Structs and dynamic arrays
Memory Management: malloc(), realloc(), and free()
File Handling: fopen(), fscanf(), fprintf() for reading/writing student data
Functions & Modular Approach: Code is split into multiple functions for better readability and maintainability
4. Functional Breakdown
a) Dynamic Memory Allocation
The program starts with an initial array size (maxStudents = 10) using malloc().
If the limit is reached, realloc() is used to double the array size dynamically.
b) File Handling for Data Persistence
saveToFile() – Saves student data into students.txt in CSV format.
loadFromFile() – Loads existing records from the file into memory.
c) Student Record Operations
addStudent() – Adds a student with roll number, name, age, and course (with duplicate check).
editStudent() – Modifies student details based on roll number.
deleteStudent() – Removes a student from the list and shifts the array.
searchStudent() – Searches for a student by roll number.
displayListOfStudents() – Prints all stored student records.
d) Input Handling & Buffer Clearing
The clearInputBuffer() function prevents input issues caused by scanf() and fgets().
Validation checks ensure roll numbers and ages are positive.
5. Challenges & Solutions
🔴 Memory Limitations? ✅ Used realloc() to dynamically adjust array size.
🔴 File Corruption? ✅ Ensured proper opening and closing of files (fopen() & fclose()).
🔴 Invalid User Input? ✅ Implemented input validation to prevent incorrect entries.

6. Future Enhancements
🚀 Use a Database (MySQL) – Replace file storage with a relational database for better scalability.
🚀 GUI Interface – Develop a web or desktop UI for an improved user experience.
🚀 Sorting & Filtering – Implement sorting by name, age, or course.

7. Conclusion
This Student Management System in C is a great example of applying data structures, file handling, and dynamic memory allocation to solve real-world problems. It is an efficient and modular solution for managing student records, and it can be extended further for more advanced functionalities.
