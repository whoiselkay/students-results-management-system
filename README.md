# Student Examination Results Management System (C++)

A beginner-friendly **Data Structures** project demonstrating **one-dimensional arrays** in C++. It stores student names and examination scores in two matching arrays (`names` and `scores`).

## Features

- Add up to 100 students and their scores (0–100)
- View all students
- Calculate total, average, highest, and lowest scores
- Search for a student by exact name
- Delete a student (remaining array elements shift left)
- Validate menu options and scores

## Run the application

This is a **console application**, not a website. GitHub hosts the source code and GitHub Actions checks that it compiles; **GitHub Pages cannot run C++ console programs**.

### On Windows (Code::Blocks)

1. Install Code::Blocks **with the MinGW compiler**.
2. Open Code::Blocks and create a **Console application → C++** project.
3. Replace the project's `main.cpp` with the contents of this repository's `main.cpp`.
4. Select **Build and Run** (F9).

### From a terminal with g++ installed

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o student-results
./student-results
```

On Windows PowerShell, compile with `g++ -std=c++17 main.cpp -o student-results.exe` and run with `./student-results.exe`.

## Example

```text
1. Add student
2. View students
3. Calculate results
4. Search student
5. Delete student
6. Exit
Enter your choice (1-6): 1
Enter student name: Ama Mensah
Enter examination score (0-100): 85
Student added successfully!
```

## How arrays are used

`names[0]` and `scores[0]` refer to the same student. A `for` loop reads each element to display scores and calculate statistics. Deleting a student shifts later elements left. This project deliberately uses fixed-size arrays rather than vectors to demonstrate the data structure.

**Note:** Records are held in memory and disappear when the program closes. This is a learning project, not a permanent student database.

## Publish to GitHub

Create a **public repository** named `student-results-management-system`, select **Add file → Upload files**, and upload `main.cpp`, `README.md`, and the `.github/workflows/build.yml` file (preserving folders). Commit the changes. Open the **Actions** tab to see the automated C++ build. GitHub hosts the code; to use the app, compile and run it on your computer.
