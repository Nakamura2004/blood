

#include <iostream>
#include <string>
#include <algorithm>

#define MAX_STUDENTS 15

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to swap two students
void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

// a. Bubble Sort by Roll No
void bubbleSortByRollNo(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// b. Insertion Sort by Name
void insertionSortByName(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

// c. Quick Sort by SGPA
int partition(Student students[], int low, int high) {
    float pivot = students[high].sgpa;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (students[j].sgpa > pivot) {
            swap(students[++i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSort(Student students[], int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high);
        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

// d. Search by SGPA
void searchBySGPA(Student students[], int n, float sgpa) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].sgpa == sgpa) {
            cout << "Roll No: " << students[i].rollNo 
                 << ", Name: " << students[i].name 
                 << ", SGPA: " << students[i].sgpa << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with SGPA " << sgpa << endl;
    }
}

// e. Binary Search by Name (Non-recursive)
int binarySearchByName(Student students[], int n, const string &name) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].name == name)
            return mid;
        else if (students[mid].name < name)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Name not found
}

// Function to print a student record
void printStudent(const Student &s) {
    cout << "Roll No: " << s.rollNo << ", Name: " << s.name << ", SGPA: " << s.sgpa << endl;
}

int main() {
    Student students[MAX_STUDENTS] = {
        {1, "John", 8.5}, {2, "Alice", 9.1}, {3, "Bob", 7.8}, {4, "David", 8.0},
        {5, "Eva", 9.2}, {6, "Tom", 6.9}, {7, "Sarah", 8.7}, {8, "Luke", 7.5},
        {9, "Sophia", 9.3}, {10, "James", 8.1}, {11, "Nina", 7.6}, {12, "Chloe", 9.0},
        {13, "Michael", 8.3}, {14, "Oliver", 7.4}, {15, "Lily", 9.5}
    };
    int n = MAX_STUDENTS;

    // a. Bubble Sort by Roll No
    cout << "---- Bubble Sort by Roll No ----" << endl;
    bubbleSortByRollNo(students, n);
    for (int i = 0; i < n; i++) printStudent(students[i]);

    // b. Insertion Sort by Name
    cout << "\n---- Insertion Sort by Name ----" << endl;
    insertionSortByName(students, n);
    for (int i = 0; i < n; i++) printStudent(students[i]);

    // c. Quick Sort for Top 10 Students by SGPA
    cout << "\n---- Top 10 Students by SGPA ----" << endl;
    quickSort(students, 0, n - 1);
    for (int i = 0; i < 10; i++) printStudent(students[i]);

    // d. Search by SGPA
    float searchSGPA = 8.0;
    cout << "\n---- Search by SGPA (8.0) ----" << endl;
    searchBySGPA(students, n, searchSGPA);

    // e. Binary Search by Name
    string searchName = "David";
    cout << "\n---- Binary Search by Name (David) ----" << endl;
    int index = binarySearchByName(students, n, searchName);
    if (index != -1) printStudent(students[index]);
    else cout << "Student with name " << searchName << " not found." << endl;

    return 0;
}
