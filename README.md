# Student Database Management System

This project is a simple student database management system implemented in C. It allows for storing, searching, adding, and removing student records, and calculating class averages and individual student grades.

## Features
- **Search by ID**: Search for a student by their unique ID and display their information.
- **Print All IDs**: Print a list of all student IDs in the database.
- **Full Data**: Display full student information including their name, ID, and final grade.
- **Class Average**: Calculate and display the class average based on the students' grades.
- **Count Students**: Count and display the total number of students in the database.
- **Add Student**: Allows users to add a new student record with their first name, last name, ID, and final grade.
- **Remove Student**: Remove a student from the database by their ID.

## File Structure
- **students_database.c**: The main program file containing the `main()` function and logic to interact with the user.
- **functions.h**: Header file containing function declarations and the structure definition for `Student`.
  
## Compilation and Execution
To compile and run the program, use the following steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/vianneydb/Students-Database
   cd <repository_directory>
   ```

2. Compile in terminal:
   ```bash
   gcc -o students_database students_database.c functions.c
   ```

3. Run the program:
   ```bash
   ./students_database
   ```

## Example
Here is an example of the interaction:
```yaml
Please enter the ID to look up (8 digits): 12345678
-------------------------------------------------------
 First name: John
  Last name: Doe
         ID: 12345678
Final grade: 87.50

Do you want to print the number of students and class average?
(1) Yes  (2) No
```

## Contributing
If you want to contribute to this project, feel free to fork the repository, make your changes, and submit a pull request.


**Author**: Vianney Diaz.

**Date**: November 2024.
