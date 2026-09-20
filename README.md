# Placement Board — College Placement Management System

A CLI-based Object-Oriented C++ application developed for **MCA Semester-1**. The system automates college placement management activities across three distinct user roles: **Admin**, **Student**, and **Company**.

---

## Key Features

* **Admin Dashboard:** Manage student records, onboard company profiles, and oversee placement operations.
* **Student Dashboard:** View individual academic profiles, track applications, and view available placement drives.
* **Company Dashboard:** Access company profile information, manage company details, and post job placement drives.
* **Console Masking & Validation:** Secure password entry with asterisks masking and input sanitization to prevent infinite menu loops.
* **File-Based Database:** Persistent storage for user records using formatted text files.

---

## Object-Oriented Programming (OOP) Concepts Demonstrated

* **Inheritance:** `admin`, `student`, and `company` classes inherit common authentication properties from the base `User` class.
* **Polymorphism:** Method overriding via a `virtual bool login()` function implemented differently across derived classes.
* **Encapsulation:** Class attributes (`private`/`protected`) are encapsulated safely with public interface methods.
* **Abstraction & Data Persistence:** Hides file I/O complexity (`data/*.txt`) behind clean member function calls.

---

## Project Structure

```text
PlacementBoard/
│
├── main.cpp          # Application entry point and main menu routing
├── user.cpp          # Base User class & shared authentication utilities
├── admin.cpp         # Admin management functions and dashboard
├── student.cpp       # Student profile management and dashboard
├── company.cpp       # Company profile management and dashboard
├── README.md         # Project documentation
└── data/             # Text file database directory
    ├── admin.txt
    ├── student.txt
    └── company.txt