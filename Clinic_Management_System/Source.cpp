#include<iostream> 
#include<conio.h> 
#include<fstream> 
#include<iomanip> 
#include<cstring> 
#include<string>
#include<windows.h> 
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void addPatient();
void appointDoctor();

//use global variable to select mode
int mode = 1;

//need this password to sign up as doctor
string systemDocPass = "Doc123";

//need this password to sign up as admin
string systemAdminPass = "Admin123";

// User class
class User {
public:
    string username;
    string password;

    // Constructor to initialize the user's details
    User(string username, string password) {
        if (mode == 1) {
            cout << "\nclassUser - Constructor\n" << endl;
        }
        this->username = username;
        this->password = password;
    }

    // Virtual destructor
    virtual ~User() {}

    // Getters for the user's details
    string getUsername() {
        if (mode == 1) {
            cout << "\nclassUser - getUsername\n" << endl;
        }
        return username;
    }
    string getPassword() {
        if (mode == 1) {
            cout << "\nclassUser - getPassword\n" << endl;
        }
        return password;
    }

    // Setters for the user's details
    void setUsername(string username) {
        if (mode == 1) {
            cout << "\nclassUser - setUsername\n" << endl;
        }
        this->username = username;
    }
    void setPassword(string password) {
        if (mode == 1) {
            cout << "\nclassUser - etPassword\n" << endl;
        }
        this->password = password;
    }
};

void printAllPatients() {
    // Open the patients.txt file for reading
    ifstream patientsFile("patientsInfoByAdmin.txt");
    cout << endl;
    // Read the file line by line
    string line;
    while (getline(patientsFile, line)) {
        // Split the line into fields
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, '|')) {
            fields.push_back(field);
        }

        // Print the patient's fields
        cout << "\tPatient ID      : " << fields[0] << endl;
        cout << "\tName            : " << fields[1] << endl;
        cout << "\tAge             : " << fields[2] << endl;
        cout << "\tGender          : " << fields[3] << endl;
        cout << "\tAddress         : " << fields[4] << endl;
        cout << "\tPhone           : " << fields[5] << endl;
        cout << "\tAppointed Doctor: Dr." << fields[6] << endl;
        cout << "\tAppointed Day   : " << fields[7] << endl;
        cout << "\tAppointed Shift : " << fields[8] << endl << endl << endl;
    }

    // Close the file
    patientsFile.close();
}

void printAllDoctors() {
    // Open the patients.txt file for reading
    ifstream DocsFile("doctors.txt");

    // Read the file line by line
    string line;
    while (getline(DocsFile, line)) {
        // Split the line into fields
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, '|')) {
            fields.push_back(field);
        }

        // Print the patient's fields
        cout << "\tDoctor         : Dr." << fields[0] << endl;
        cout << "\tAvailable Days : " << fields[2] << endl;
        cout << "\tAvailable Shift: " << fields[3] << endl << endl;
    }

    // Close the file
    DocsFile.close();
}

// Doctor class derived from the User class
class Doctor : public User {
public:
    string availableDays;
    string shifts;

    // Constructor to initialize the doctor's details
    Doctor(string username, string password, string availableDays, string shifts)
        : User(username, password) {
        if (mode == 1) {
            cout << "\nclassDoctor - Constructor\n" << endl;
        }
        this->availableDays = availableDays;
        this->shifts = shifts;
    }

    // Getters for the doctor's details
    string getAvailableDays() {
        if (mode == 1) {
            cout << "\nclassDoctor - getAvailableDays\n" << endl;
        }
        return availableDays;
    }
    string getShifts() {
        if (mode == 1) {
            cout << "\nclassDoctor - getShifts\n" << endl;
        }
        return shifts;
    }

    // Setters for the doctor's details
    void setAvailableDays(string availableDays) {
        if (mode == 1) {
            cout << "\nclassDoctor - setAvailableDays\n" << endl;
        }
        this->availableDays = availableDays;
    }
    void setShifts(string shifts) {
        if (mode == 1) {
            cout << "classDoctor - setShifts" << endl;
        }
        this->shifts = shifts;
    }
    //void setPatientsID(string patientsID) { this->patientsID = patientsID; }

    void printAllPatients() {
        if (mode == 1) {
            cout << "classDoctor - printAllPatients" << endl;
        }

        cout << endl;
        cout << "\t-------- Patients List --------" << endl;
        cout << endl;

        ifstream patients_file1("patientsInfoByAdmin.txt");
        string line;

        // Read the file line by line
        while (getline(patients_file1, line)) {
            // Split the line into fields using the '|' delimiter
            int start = 0;
            int end = line.find('|');
            string patient_id = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string name = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string age = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string gender = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string address = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string phone = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string appointed_doctor = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string appointed_day = line.substr(start, end - start);
            start = end + 1;
            string appointed_shift = line.substr(start);

            // Check if the doctor's username matches the appointed doctor's username

            // Print the patient's details
            cout << "\t  Patient ID : " << patient_id << endl;
            cout << "\t  Name       : " << name << endl;
            cout << "\t  Age        : " << age << endl;
            cout << "\t  Gender     : " << gender << endl;
            cout << "\t  Address    : " << address << endl;
            cout << "\t  Phone      : " << phone << endl;
            cout << "\t  Appointed day  : " << appointed_day << endl;
            cout << "\t  Appointed shift: " << appointed_shift << endl;
            cout << endl;
        }
        patients_file1.close();
    }


    void viewOwnPatients() {
        if (mode == 1) {
            cout << "classDoctor - viewPatients" << endl;
        }

        cout << endl;
        cout << "\t-------- Patients List --------" << endl;
        cout << endl;

        ifstream patients_file("patientsInfoByAdmin.txt");
        string line;

        // Read the file line by line
        while (getline(patients_file, line)) {
            // Split the line into fields using the '|' delimiter
            int start = 0;
            int end = line.find('|');
            string patient_id = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string name = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string age = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string gender = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string address = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string phone = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string appointed_doctor = line.substr(start, end - start);
            start = end + 1;
            end = line.find('|', start);
            string appointed_day = line.substr(start, end - start);
            start = end + 1;
            string appointed_shift = line.substr(start);

            // Check if the doctor's username matches the appointed doctor's username
            if (appointed_doctor == username) {
                // Print the patient's details
                cout << "\t  Patient ID : " << patient_id << endl;
                cout << "\t  Name       : " << name << endl;
                cout << "\t  Age        : " << age << endl;
                cout << "\t  Gender     : " << gender << endl;
                cout << "\t  Address    : " << address << endl;
                cout << "\t  Phone      : " << phone << endl;
                cout << "\t  Appointed day  : " << appointed_day << endl;
                cout << "\t  Appointed shift: " << appointed_shift << endl;
                cout << endl;
            }
        }

        patients_file.close();
    }

    void addPatientNotes() {
        string patientId, name;
        cout << "\n\n\tPatients appointed to you: " << endl;
        vector<string> patients;
        int i = 1;
        ifstream patientsFile("patientsInfoByAdmin.txt");
        string line;

        cout << "\t\tNo.\t" << "Id\t" << "Name" << endl;

        while (getline(patientsFile, line)) {
            // Split the line by '|'
            int startIndex = 0;
            int endIndex = line.find('|');
            patientId = line.substr(startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            endIndex = line.find('|', startIndex);
            name = line.substr(startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            endIndex = line.find('|', startIndex);
            string age = line.substr(startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            endIndex = line.find('|', startIndex);
            string gender = line.substr(startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            endIndex = line.find('|', startIndex);
            string address = line.substr(startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            endIndex = line.find('|', startIndex);
            string phone = line.substr(startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            endIndex = line.find('|', startIndex);
            string appointedDoc = line.substr(startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            endIndex = line.find('|', startIndex);
            string appointedDay = line.substr(startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            endIndex = line.find('|', startIndex);
            string appointedShift = line.substr(startIndex, endIndex - startIndex);


            // If the patient is appointed to this doctor, add their name to the list
            if (appointedDoc == username) {
                cout<<"\t\t" << i << ".\t" << patientId << "\t" << name << endl;
                patients.push_back(patientId);
                i++;
            }
        }

        patientsFile.close();

        // Ask the user to select a patient
        int patientNumber;
        cout << "\n\tEnter the No. of the patient you want to add notes for: ";
        cin >> patientNumber;
        if (patientNumber < 1 || patientNumber > patients.size()) {
            cout << "\tInvalid patient number." << endl;
            return;
        }
        // Get the patient's id
        patientId = patients[patientNumber - 1];

        // Get the patient's symptoms, disease, and medication
        string symptoms, disease, medication;
        cout << "\n\tEnter the patient's symptoms  : ";
        cin.ignore();
        getline(cin, symptoms);
        cout << "\n\tEnter the patient's disease   : ";
        getline(cin, disease);
        cout << "\n\tEnter the patient's medication: ";
        getline(cin, medication);

        // Append the patient's notes to the doctor's notes file
        ofstream outFile("doctornotes.txt", ios::app);
        outFile << patientId << "|" << name << "|" << symptoms << "|" << disease << "|" << medication << endl;
        outFile.close();
    }


    void printPatientNote() {
        cout << endl;
        cout << "\t-------- Patients Medical records --------" << endl;
        cout << endl;

        // Open the doctors.txt file
        ifstream file("doctornotes.txt");
        string line;
        while (getline(file, line)) {
            // Split the line into separate fields
            stringstream ss(line);
            string field;
            vector<string> fields;
            while (getline(ss, field, '|')) {
                fields.push_back(field);
            }

            // Print the fields
            cout << "\t  Patient's ID :" << fields[0] << endl;
            cout << "\t  Name         : " << fields[1] << endl;
            cout << "\t  symptoms     : " << fields[2] << endl;
            cout << "\t  disease      : " << fields[3] << endl;
            cout << "\t  medication   : " << fields[4] << endl;
            cout << endl;
        }
    }

    void DocMenu(Doctor* doctor) {

        if (mode == 1) {
            cout << "classDoctor - Menu" << endl;
        }

        //system("CLS");
        cout << "\n\n\t--------------------- Doctor Dashboard -----------------------\n\n";

        cout << "\t   Welcome back, Dr. " << doctor->getUsername() << "!" << endl;
        // viewPatients();
        while (true) {
            cout << "\t\t1. View patients appointed " << endl;
            cout << "\t\t2. Write Symptoms, Disease, and Medication for Patients" << endl;
            cout << "\t\t3. View previous records of the Patients" << endl;
            cout << "\t\t4. View all patients" << endl;
            cout << "\t\t5. Sign out" << endl;
            cout << "\n\tEnter the number of your selection: ";


            int choice;

            while (!(cin >> choice)) {
                cout << "\n\tEnter correct choice number!\n";
                cout << "\n\tEnter your choice : ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            switch (choice) {
            case 1: {
                viewOwnPatients();
                break;
            }
            case 2: {
                addPatientNotes();
                break;
            }
            case 3: {
                printPatientNote();
                break;
            }
            case 4: {
                printAllPatients();
                break;
            }
            case 5: {
                return;
                break;
            }
            default: {
                cout << "\n\t\t\t------- Invalid choice! -------" << endl;
            }

            }
        }
        return;

    }
};


// Administrator class derived from the User class
class Administrator : public User {
private:
    string patientID;
    string appointmentDate;

public:
    Administrator(string username, string password) : User(username, password) {
        if (mode == 1) {
            std::cout << "\nclassAdministrator - Constructor\n" << std::endl;
        }

    }

    void AdminMenu(Administrator* admin) {
        if (mode == 1) {
            cout << "classaAdimistrator - Menu" << endl;
        }

        cout << "\n\n\t--------------------- Administration Dashboard -----------------------\n\n";

        cout << "\t   Welcome back, Mr./Mrs. " << admin->getUsername() << "!" << endl;
        int choice1;
        while (true) {
            cout << "\t\t1. Add Patient" << endl;
            cout << "\t\t2. View All Patient" << endl;
            cout << "\t\t3. View All doctors" << endl;
            cout << "\t\t4. Logout" << endl;


            int choice1;
            cout << "\n\tEnter your choice : ";
            cin >> choice1;

            switch (choice1) {
            case 1: {
                addPatient();
                break;
            }
            case 2: {
                printAllPatients();
                break;
            }
            case 3: {
                printAllDoctors();
                break;
            }
            case 4: {
                return;
            }

            default: {
                cout << "\n\t\t\t------- Invalid choice! -------" << endl;
                break;
            }
            }
        }
        return;
    }
};

class Patient {
public:
    string id;
    string name;
    int age;
    string gender;
    string address;
    string phone;
    string symptoms;
    string disease;
    string medication;
    string appointedDoc;
    string appointedDay;
    string appointedShift;

    // Constructor to initialize the patient's details
    Patient(string id, string name, int age, string gender, string address,
        string phone, string appointedDoc, string appointedDay, string appointedShift) {
        if (mode == 1) {
            cout << "\nclassPatient - Constructor\n" << endl;
        }

        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->address = address;
        this->phone = phone;
        this->appointedDoc = appointedDoc;
        this->appointedDay = appointedDay;
        this->appointedShift = appointedShift;
    }

    string getId() {
        if (mode == 1) {
            cout << "\nclassPatient - getId\n" << endl;
        }
        return id;
    }
    void setId(string id) {
        if (mode == 1) {
            cout << "\n classPatient - setId\n" << endl;
        }
        this->id = id;
    }

    string getName() {
        if (mode == 1) {
            cout << "\nclassPatient - getName\n" << endl;
        }
        return name;
    }
    void setName(string name) {
        if (mode == 1) {
            cout << "\nclassPatient - setName\n" << endl;
        }
        this->name = name;
    }

    int getAge() {
        if (mode == 1) {
            cout << "\nclassPatient - getAge\n" << endl;
        }
        return age;
    }
    void setAge(int age) {
        if (mode == 1) {
            cout << "\nclassPatient - setAge\n" << endl;
        }
        this->age = age;
    }

    string getGender() {
        if (mode == 1) {
            cout << "\nclassPatient - getGender\n" << endl;
        }
        return gender;
    }
    void setGender(string gender) {
        if (mode == 1) {
            cout << "\nclassPatient - setGender\n" << endl;
        }
        this->gender = gender;
    }

    string getAddress() {
        if (mode == 1) {
            cout << "\nclassPatient - getAddress\n" << endl;
        }
        return address;
    }

    void setAddress(string address) {
        if (mode == 1) {
            cout << "\nclassPatient - setAddress\n" << endl;
        }
        this->address = address;
    }

    string getPhone() {
        if (mode == 1) {
            cout << "\nclassPatient-getPhone\n" << endl;
        }
        return phone;
    }
    void setPhone(string phone) {
        if (mode == 1) {
            cout << "\nclassPatient-setPhone\n" << endl;
        }
        this->phone = phone;
    }

    string getSymptoms() {
        if (mode == 1) {
            cout << "\nclassPatient-getSymptoms\n" << endl;
        }
        return symptoms;
    }
    void setSymptoms(string symptoms) {
        if (mode == 1) {
            cout << "\nclassPatient-setSymptoms\n" << endl;
        }
        this->symptoms = symptoms;
    }

    string getDisease() {
        if (mode == 1) {
            cout << "\nclassPatient-getDisease\n" << endl;
        }
        return disease;
    }
    void setDisease(string disease) {
        if (mode == 1) {
            cout << "\nclassPatient-setDisease\n" << endl;
        }
        this->disease = disease;
    }

    string getMedication() {
        if (mode == 1) {
            cout << "\nclassPatient-getMedication\n" << endl;
        }
        return medication;
    }
    void setMedication(string medication) {
        if (mode == 1) {
            cout << "\nclassPatient-setMedication\n" << endl;
        }
        this->medication = medication;
    }

    string getAppointedDoc() {
        if (mode == 1) {
            cout << "\nclassPatient-getAppointedDoc\n" << endl;
        }
        return appointedDoc;
    }
    void setAppointedDoc(string appointedDoc) {
        if (mode == 1) {
            cout << "\nclassPatient-setAppointedDoc\n" << endl;
        }
        this->appointedDoc = appointedDoc;
    }

    string getAppointedDay() {
        if (mode == 1) {
            cout << "\nclassPatient-getAppointedDay\n" << endl;
        }
        return appointedDay;
    }
    void setAppointedDay(string appointedDay) {
        if (mode == 1) {
            cout << "\nclassPatient - Constructor\n" << endl;
        }
        this->appointedDay = appointedDay;
    }

    string getAppointedShift() {
        if (mode == 1) {
            cout << "\nclassPatient-getAppointedShift\n" << endl;
        }
        return appointedShift;
    }
    void setAppointedShift(string appointedShift) {
        if (mode == 1) {
            cout << "\nclassPatient-setAppointedShift\n" << endl;
        }
        this->appointedShift = appointedShift;
    }

};

Doctor* signInDoctor() {
    while (true) {
        string username, password;
        cout << "\n\t------------ Welcome back! ------------\n";
        cout << "\t\t\t Login ";
        cout << "\n\t\t\t-------\n\n";

        cout << "\t\tUsername  : ";
        cin >> username;
        cout << "\t\tPassword  : ";
        cin >> password;

        ifstream doctorsFile("doctors.txt");
        string line;
        vector<Doctor> doctors;
        while (getline(doctorsFile, line)) {
            stringstream ss(line);
            string docUsername, docPassword, availableDays, shifts;
            getline(ss, docUsername, '|');
            getline(ss, docPassword, '|');
            getline(ss, availableDays, '|');
            getline(ss, shifts, '|');
            doctors.emplace_back(docUsername, docPassword, availableDays, shifts);
        }

        for (auto& doctor : doctors) {
            if (doctor.getUsername() == username && doctor.getPassword() == password) {
                return new Doctor(doctor);
            }
        }

        cout << "\n\t---- Invalid username or password! ----\n" << endl;
        cout << "\tWould you like to try again (y/n)? ";
        char tryAgain;
        cin >> tryAgain;
        if (tryAgain == 'n') {
            return nullptr;
        }
    }
}

Administrator* signInAdmin() {
    while (true) {
        string username, password;
        cout << "\n\t------------ Welcome back! ------------\n";
        cout << "\t\t\t Login ";
        cout << "\n\t\t\t-------\n\n";

        cout << "\t\tUsername  : ";
        cin >> username;
        cout << "\t\tPassword  : ";
        cin >> password;

        ifstream adminsFile("admins.txt");
        string line;
        vector<Administrator> admins;
        while (getline(adminsFile, line)) {
            stringstream ss(line);
            string adminUsername, adminPassword;
            getline(ss, adminUsername, '|');
            getline(ss, adminPassword, '|');
            admins.emplace_back(adminUsername, adminPassword);
        }

        for (auto& admin : admins) {
            if (admin.getUsername() == username && admin.getPassword() == password) {
                return new Administrator(admin);
            }
        }

        cout << "\n\t---- Invalid username or password! ----\n" << endl;
        cout << "\tWould you like to try again (y/n)? ";
        char tryAgain;
        cin >> tryAgain;
        if (tryAgain == 'n') {
            return nullptr;
        }
    }
}

string idGenerator()
{
    // Generate a patient ID by scanning the existing patient IDs in the patients.txt file
    string patientID = "000";
    ifstream file("patientsInfoByAdmin.txt");
    string line;
    while (getline(file, line)) {
        size_t pos = line.find('|');
        string id = line.substr(0, pos);
        int idNum = stoi(id);
        if (idNum > stoi(patientID)) {
            patientID = id;
        }
    }
    file.close();
    int idNum = stoi(patientID);
    idNum++;
    patientID = to_string(idNum);
    if (idNum < 10) {
        patientID = "00" + patientID;
    }
    else if (idNum < 100) {
        patientID = "0" + patientID;
    }
    else {
        patientID = patientID;
    }

    return patientID;
}

void addPatient()
{
    Patient* patient = new Patient("", "", 0, "", "", "", "", "", "");

    cout << "\n\t------------- Add Patients -------------\n\n";

    string patientID = idGenerator();
    cout << "\t\tAutogenerated Id:" << patientID << endl;
    cout << "\t\tName\t\t: ";
    cin.ignore();
    getline(cin, patient->name);

    cout << "\t\tAge\t\t: ";
    cin >> patient->age;
    cout << "\t\tGender\t\t: ";
    cin.ignore();
    getline(cin, patient->gender);
    cout << "\t\tAddress\t\t: ";
    getline(cin, patient->address);
    cout << "\t\tPhone number\t: ";
    cin >> patient->phone;

    vector<Doctor> doctors;
    ifstream wfile("doctors.txt");
    string line;
    while (getline(wfile, line)) {
        size_t pos1 = line.find('|');
        string username = line.substr(0, pos1);
        line.erase(0, pos1 + 1);
        size_t pos2 = line.find('|');
        string password = line.substr(0, pos2);
        line.erase(0, pos2 + 1);
        size_t pos3 = line.find('|');
        string availableDays = line.substr(0, pos3);
        line.erase(0, pos3 + 1);
        size_t pos4 = line.find('|');
        string shifts = line.substr(0, pos4);
        string patientsID = line.substr(pos4 + 1);
        Doctor doctor(username, password, availableDays, shifts);
        doctors.push_back(doctor);
    }
    wfile.close();

    // Print the list of doctors
    cout << "\n\tDoctor list : " << endl;
    for (int i = 0; i < doctors.size(); i++) {
        cout << "\t\t" << i + 1 << ". " << doctors[i].getUsername() << endl;
    }

    // Get the user's choice of doctor
    cout << "\n\tSelect a doctor : ";
    int choice;
    cin >> choice;
    cin.ignore();
    Doctor doctor = doctors[choice - 1];

    // Print the doctor's available days
    cout << "\n\tDoctor available days : " << endl;
    string availableDays = doctor.getAvailableDays();
    int dayNum = 1;
    size_t pos = 0;
    while ((pos = availableDays.find(',')) != string::npos) {
        cout << "\t\t" << dayNum << ". " << availableDays.substr(0, pos) << endl;
        availableDays.erase(0, pos + 1);
        dayNum++;
    }
    cout << "\t\t" << dayNum << ". " << availableDays << endl;

    // Get the user's choice of day
    cout << "\n\tSelect a day : ";
    int dayChoice;
    cin >> dayChoice;
    cin.ignore();
    string day = doctor.getAvailableDays();
    for (int i = 0; i < dayChoice - 1; i++) {
        size_t pos = day.find(',');
        day.erase(0, pos + 1);
    }
    if (dayChoice >= 1) {
        size_t pos = day.find(',');
        day = day.substr(0, pos);
    }

    // Print the doctor's available shifts for the chosen day
    cout << "\n\tDoctor available shifts : " << endl;
    string shifts = doctor.getShifts();
    int shiftNum = 1;
    pos = 0;
    while ((pos = shifts.find(',')) != string::npos) {
        cout << "\t\t" << shiftNum << ". " << shifts.substr(0, pos) << endl;
        shifts.erase(0, pos + 1);
        shiftNum++;
    }
    cout << "\t\t" << shiftNum << ". " << shifts << endl;

    // Get the user's choice of shift
    cout << "\n\tSelect shift : ";
    int shiftChoice;
    cin >> shiftChoice;
    cin.ignore();
    string shift = doctor.getShifts();
    for (int i = 0; i < shiftChoice - 1; i++) {
        size_t pos = shift.find(',');
        shift.erase(0, pos + 1);
    }
    if (shiftChoice >= 1) {
        size_t pos = shift.find(',');
        shift = shift.substr(0, pos);
    }

    cout << "\n\tAppointment created for " << doctor.getUsername() << " on " << day << " at " << shift << "." << endl;

    // Create the appointment
    patient->getAppointedDoc() = doctor.getUsername();
    patient->getAppointedDay() = day;
    patient->getAppointedShift() = shift;



    // Open the patients.txt file in append mode
    ofstream file("patientsInfoByAdmin.txt", ios_base::app);

    // Write the patient's data to the file
    file << patientID << "|" << patient->getName() << "|" << patient->getAge() << "|" << patient->getGender() << "|"
        << patient->getAddress() << "|" << patient->getPhone() << "|" << doctor.getUsername() << "|" << day << "|" << shift << endl;

    // Close the file
    file.close();

    cout << "\n\t\t--------- Patient added successfully! ---------\n" << endl;
    int choice1 = 0;
    cout << "\n\t\t Clear screen?(1/0) :";
    cin >> choice1;
    if (choice1 == 1) {
        system("cls");

    }
}

// Function to sign up as a doctor
void signUp(Doctor* doctor) {

    cout << "\n\t----------------- Doctor Registration -----------------\n\n";

    cout << "\tEnter your desired username : ";
    cin >> doctor->username;

    // Check if the desired username is already taken
    ifstream file("doctors.txt");
    string line;
    bool usernameTaken = false;
    while (getline(file, line)) {
        // Split the line into separate fields
        vector<string> fields;
        stringstream ss(line);
        string field;
        while (getline(ss, field, '|')) {
            fields.push_back(field);
        }

        if (fields[0] == doctor->username) {
            // The desired username is already taken
            usernameTaken = true;
            break;
        }
    }

    if (usernameTaken) {
        system("cls");
        cout << "\n\tUsername already taken. Please choose a different username.\n" << endl;
        cout << "\tEnter your desired username : ";
        cin >> doctor->username;
    }

    cout << "\tEnter your desired password : ";
    cin >> doctor->password;

    string pass;
    while (true) {
        cout << "\tEnter system password       :";
        cin >> pass;
        if (pass.compare(systemDocPass) == 0) {
            break;
        }
        else {
            cout << "\tInvalid system password! Please enter again!\n";
        }
    }

    cout << "\tEnter your available days (separated by commas) : ";
    cin.ignore(); // Ignore any remaining characters in the input stream
    getline(cin, doctor->availableDays);

    cout << "\tEnter your shifts (separated by commas)\t\t: ";
    getline(cin, doctor->shifts);


    // Open the doctors.txt file in append mode
    ofstream outFile("doctors.txt", ios_base::app);

    // Write the doctor's details to the file
    outFile << doctor->getUsername() << '|' << doctor->getPassword() << '|' << doctor->getAvailableDays() << '|' << doctor->getShifts() << endl;

    cout << "\n\t----------------  Registration successful!  ----------------\n\n" << endl;
}

// Function to sign up as a administrator
void signUp(Administrator* administrator) {

    cout << "\n\t----------------- Administrator Registration -----------------\n\n";

    cout << "\tEnter your desired username : ";
    cin >> administrator->username;

    // Check if the desired username is already taken
    ifstream file("admins.txt");
    string line;
    bool usernameTaken = false;
    while (getline(file, line)) {
        // Split the line into separate fields
        vector<string> fields;
        stringstream ss(line);
        string field;
        while (getline(ss, field, '|')) {
            fields.push_back(field);
        }

        if (fields[0] == administrator->username) {
            // The desired username is already taken
            usernameTaken = true;
            break;
        }
    }

    if (usernameTaken) {
        system("cls");
        cout << "\n\tUsername already taken. Please choose a different username.\n" << endl;
        cout << "\tEnter your desired username : ";
        cin >> administrator->username;
    }

    cout << "\tEnter your desired password : ";
    cin >> administrator->password;

    string pass;
    while (true) {
        cout << "\tEnter system password       :";
        cin >> pass;
        if (pass.compare(systemAdminPass) == 0) {
            break;
        }
        else {
            cout << "\tInvalid system password! Please enter again!\n";
        }
    }


    // Open the admins.txt file in append mode
    ofstream outFile("admins.txt", ios_base::app);

    // Write the doctor's details to the file
    outFile << administrator->getUsername() << '|' << administrator->getPassword() << endl;

    cout << "\n\t----------------  Registration successful!  ----------------\n\n" << endl;
}


int main()
{
    cout << "\t--------------------------------------\n";
    cout << "\t\t   Mode Selection" << endl;
    cout << "\t--------------------------------------\n";
    cout << "\t1. Education Mode (Enter - 1)" << endl;
    cout << "\t2. Regular Mode" << endl;

    cout << "\n\t Select the Mode : ";
    cin >> mode;

    while (true) {


        cout << "\n\t*********************************************************************" << endl;
        cout << "\t\t\t   CLINIC MANAGEMENT SYSTEM" << endl;
        cout << "\t*********************************************************************" << endl;

        cout << "\t\t\t1. Sign in as doctor" << endl;
        cout << "\t\t\t2. Sign in as administrator" << endl;
        cout << "\t\t\t3. Sign up as doctor" << endl;
        cout << "\t\t\t4. Sign up as administrator" << endl;
        cout << "\t\t\t5. Exit" << endl;

        int choice;
        cout << "\n\tEnter your choice : ";
        while (!(cin >> choice)) {
            cout << "\n\tEnter correct choice number!\n";
            cout << "\n\tEnter your choice : ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        system("cls");
        Administrator* admin = new Administrator("", "");
        Doctor* doctor = new Doctor("", "", "", "");
        Patient* patient = new Patient("", "", 0, "", "", "", "", "", "");

        switch (choice) {
        case 1: {
            doctor = signInDoctor();
            if (doctor != nullptr) {
                system("cls");
                cout << "\n\tUser successfully signed in as a doctor.\n";
                // You can now use the 'doctor' object to access the doctor's username, password, available days, and shifts
                doctor->DocMenu(doctor);
            }
            else {
                cout << "\n\tUnsuccessfull";
                // User did not successfully sign in as a doctor
                // You can either return or do something else here
            }
            break;
        }
        case 2: {
            admin = signInAdmin();
            if (admin != nullptr) {
                system("cls");
                cout << "\n\tUser successfully signed in as a admin.\n";
                // You can now use the 'doctor' object to access the doctor's username, password, available days, and shifts
                admin->AdminMenu(admin);
            }
            else {
                cout << "\n\tUnsuccessfull";
                // User did not successfully sign in as a doctor
                // You can either return or do something else here
            }
            break;
        }
        case 3: {
            signUp(doctor);
            break;
        }
        case 4: {
            signUp(admin);
            break;
        }
        case 5: {
            return 0;
        }
        default: {
            cout << "\n\tInvalid choice." << endl;
        }
        }
    }

    return 0;
}