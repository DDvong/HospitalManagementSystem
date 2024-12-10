#ifndef PATIENTHASHTABLE_H
#define PATIENTHASHTABLE_H

#include <QString>
#include <QDate>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Patient Information
class Patient {
public:
    QString name;
    int id;
    int age;
    QString gender;
    QString phone;
    QString condition;
};

// HashTable class
class PatientHashTable {
public:
    // Store patients
    unordered_map<int, Patient> patientList;

    // Functions
    void addPatient(Patient patient) {
        patientList[patient.id] = patient;
    }

    Patient* findPatient(int id) {
        if (patientList.find(id) != patientList.end()) {
            return &patientList[id];
        }
        return nullptr;
    }

    void deletePatient(int id) {
        patientList.erase(id);
    }

    int countPatients() {
        return patientList.size();
    }   
};

struct Appointment {
    QString time;
    int patientId;
    QString reason;    // Added reason for visit
    QString date;
};

class DailyQueue {
private:
    queue<Appointment> appointments;

public:
    // Add to queue
    void enqueue(QString date, QString time, int patientId, QString reason) {
        Appointment app;
        app.date = date;
        app.time = time;
        app.patientId = patientId;
        app.reason = reason;
        appointments.push(app);
    }

    // Remove from queue
    Appointment dequeue() {
        Appointment app;  // Create appointment

        if (!isEmpty()) {
            app = appointments.front();
            appointments.pop();
        } else {
            app.patientId = -1;
        }
        return app;
    }

    QString viewQueue() {
        QString display = "Appointments:\n\n";
        queue<Appointment> temp = appointments;

        if(temp.empty()) {
            return "No appointments scheduled.";
        }

        while(!temp.empty()) {
            Appointment app = temp.front();
            display += "Date: " + app.date + "\n";
            display += "Time: " + app.time + "\n";
            display += "Patient ID: " + QString::number(app.patientId) + "\n";
            display += "Reason: " + app.reason + "\n";
            display += "------------------------\n";
            temp.pop();
        }

        return display;
    }

    bool isEmpty() {
        return appointments.empty();
    }

    int getSize() {
        return appointments.size();
    }
};

class ReportNode {
public:
    // Data stored in node
    int patientId;
    QString date;
    QString symptoms;
    QString diagnosis;
    QString treatment;
    QString notes;
    ReportNode* next;    // Points to the next report

    // Constructor to initialize node
    ReportNode(int id, QString reportDate, QString reportSymptoms, QString reportDiagnosis, QString reportTreatment) {
        patientId = id;
        date = reportDate;
        symptoms = reportSymptoms;
        diagnosis = reportDiagnosis;
        treatment = reportTreatment;

        next = nullptr;
    }
};

class MedicalReports {
    ReportNode* head;

public:
    MedicalReports() {
        head = nullptr;
    }

    void addReport(int id, QString date, QString symptoms, QString diagnosis, QString treatment) {
        ReportNode* newReport = new ReportNode(id, date, symptoms, diagnosis, treatment);
        if (head == nullptr) {
            head = newReport;
            return;
        }
        ReportNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newReport;
    }

    QString getReports() {
        QString Reports = "All Medical Reports:\n\n";
        ReportNode* current = head;
        while (current != nullptr) {
            Reports += "Patient ID: " + QString::number(current->patientId) + "\n";
            Reports += "Date: " + current->date + "\n";
            Reports += "Symptoms: " + current->symptoms + "\n";
            Reports += "Diagnosis: " + current->diagnosis + "\n";
            Reports += "Treatment: " + current->treatment + "\n";
            Reports += "------------------------\n";
            current = current->next;
        }
        return Reports;
    }
};
//structure represent node
struct TreeNode {
    QString data;  //department name
    TreeNode* left;
    TreeNode* right;

    TreeNode(QString value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
// Class to represent a binary search tree for storing departments
class DepartmentTree {
    TreeNode* root;  // Pointer to the root node of the tree

public:
    // Constructor to initialize the tree with an empty root
    DepartmentTree() {
        root = nullptr;
    }

    // Insert a department into the tree iteratively
    void insert(QString data) {
        TreeNode* newNode = new TreeNode(data); // Create a new node
        if (root == nullptr) {
            root = newNode; // If the tree is empty, set the new node as root
            return;
        }

        TreeNode* current = root;  // Start from the root
        TreeNode* parent = nullptr; // Keep track of the parent node

        while (current != nullptr) {
            parent = current; // Update the parent node
            if (data < current->data) {
                current = current->left; // Move to the left child
            } else if (data > current->data) {
                current = current->right; // Move to the right child
            } else {
                // If the department already exists, do nothing
                delete newNode;
                return;
            }
        }

        // Attach the new node to the appropriate position
        if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    // Display all departments using level-order traversal (iterative)
    QString display() {
        QString result = "Departments:\n\n";

        if (root == nullptr) {
            return "No departments available.";
        }
            // Use a std::queue for level-order traversal
            std::queue<TreeNode*> queue;  // Declare a queue to hold TreeNode pointers
            queue.push(root);  // Start with the root node

            // Vector to collect department names
            std::vector<QString> departments;

            // Level-order traversal to collect department names
            while (!queue.empty()) {
                TreeNode* current = queue.front();  // Get the front element of the queue
                queue.pop();  // Remove it from the queue
                departments.push_back(current->data);  // Add the department name to the list

                // Enqueue the left and right children, if they exist
                if (current->left != nullptr) {
                    queue.push(current->left);
                }
                if (current->right != nullptr) {
                    queue.push(current->right);
                }
            }

            // Sort the department names alphabetically
            std::sort(departments.begin(), departments.end());

            // Add sorted department names to the result string
            for (const QString& department : departments) {
                result += department + "\n";
            }
            return result;
        }
};

//structure to store information about doctor
struct Doctor {
    QString name;
    QString specialty;
};
//represents a graph for doctor referrals
class ReferralGraph {
private:
    unordered_map<QString, vector<QString>> adjacencyList;//maps a doctor to a doctor that they refer to
    unordered_map<QString, Doctor> doctors;  //store doctor info from name

public:
    void addDoctor(QString name, QString specialty) {
        doctors[name] = {name, specialty}; //doctor object to store on map
    }
    //adds referral from a doctor to another
    void addReferral(QString fromDoctor, QString toDoctor) {
        adjacencyList[fromDoctor].push_back(toDoctor);
    }

    QString displayReferrals() {
        QString result = "Doctor Referrals:\n\n";
        //iterate through adjacency list
        for(const auto& pair : adjacencyList) {
            result += pair.first + " refers to:\n";
            for(const QString& referral : pair.second) {
                result += "  - " + referral + "\n";
            }
            result += "\n";
        }
        return result;
    }
};


#endif
