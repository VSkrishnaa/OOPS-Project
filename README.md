# Student Management System

This is a simple Student Management System implemented in C++.

## Introduction

This project is a console-based application that allows users to manage student records. It provides functionalities like adding, displaying, searching, deleting, and modifying student data. The data is stored in a binary file for persistence.

## Features

- Add student records with details such as admission number, name, gender, standard, total marks, and percentage.
- Display all student records stored in the file.
- Search for a specific student record by admission number.
- Delete a student record by admission number, moving it to a trash file for recovery if needed.
- View deleted records stored in the trash file.
- Modify existing student records by admission number.

## How to Use

1. Clone the repository to your local machine.
2. Compile the code using a C++ compiler.
3. Run the executable generated after compilation.
4. Follow the on-screen menu to perform various operations on student records.

## File Descriptions

- `main.cpp`: Contains the main program logic.
- `student.dat`: Binary file to store student records.
- `trash.dat`: Binary file to store deleted student records.

## Contributing

Contributions are welcome! Feel free to submit bug reports, feature requests, or pull requests to help improve this project.
