# C Programs: Calculator & Library Management

This repository contains two C programs that demonstrate **basic file handling** and **menu-driven functionality** in C.

---

## 📌 Program 1 — Menu-Based Calculator

This program is a simple calculator that performs addition, subtraction, multiplication, division, and modulus operations.

**Features:**

* Menu-driven interface.
* Handles division/modulus by zero.
* Stores calculation history in `history.txt`.
* View or clear calculation history.

**Functions:**

* `add`, `subtract`, `multiply`, `divide`, `modulus` → perform arithmetic operations.
* `saveToFile` → saves each calculation to a file.
* `viewHistory` → displays all past calculations.
* `clearHistory` → clears the file storing calculations.

**Usage:**

```bash
gcc calculator.c -o calculator
./calculator
```

**Example Menu:**

```
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Modulus
6. View Calculation History
7. Clear History
8. Exit
```

---

## 📌 Program 2 — Library Management System

This program allows users to manage a simple book list with file storage.

**Features:**

* Add book (title, author, publication year) to `daftar_buku.txt`.
* View list of books.
* Clear all book data.
* Menu-driven interface.

**Functions:**

* `tambahBuku` → Add a book to the file.
* `lihatBuku` → View all books stored in the file.
* `clearBuku` → Clear the file storing book data.
* `trimNewline` → Removes newline characters from strings to maintain clean formatting.

**Usage:**

```bash
gcc library.c -o library
./library
```

**Example Menu:**

```
1. Add Book
2. View Books
3. Clear Books History
4. Exit
```

---

## 🛠 Learning Objectives

These programs teach:

* File handling (`fopen`, `fclose`, `fprintf`, `fgets`) in C.
* Menu-driven programming.
* Input validation (division/modulus by zero).
* Storing and retrieving structured data from text files.
* String manipulation (`strtok`, `strcspn`) for parsing data.

---

---

## 📌 Program 3 — Student Management System

This program manages student records using a text file (`daftar_mahasiswa.txt`). It allows adding, viewing, updating, deleting, and fully purging all student data.

**Features:**

* Add new student data (Name, NIM, Major, IPK)
* View all stored student data
* Update a specific record based on NIM
* Delete a specific record based on NIM
* Purge (clear) all student data with confirmation
* Clean input handling using `trimNewline`

**Functions:**

* `createDataMahasiswa` → Add a new student
* `readDataMahasiswa` → Display all student records
* `updateDataMahasiswa` → Modify a record by NIM
* `deleteDataMahasiswa` → Remove a record by NIM
* `purgeDataMahasiswa` → Delete all records
* `trimNewline` → Remove unwanted newline from string input

**Usage:**

```bash
gcc mahasiswa.c -o mahasiswa
./mahasiswa
```

**Example Menu:**

```
1. Add Data
2. View Data
3. Update Data
4. Delete Data Based on NIM
5. Purge Data
6. Exit
```

---

All three programs are beginner-friendly examples of combining file handling, string manipulation, and menu-driven logic in C. examples of combining arrays, strings, and file operations in practical C applications.

