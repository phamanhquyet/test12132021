#include<iostream>
#include<fstream>
#include <string>
#include<vector>
#include<iomanip>
using namespace std;
class Student {
private:
    string id;
    string fullName;
    string address;
    string specialize;
    string class_name;
    string phoneNumber;
public:
    //constructor
    Student() {
        this->id = "";
        this->fullName = "";
        this->address = "";
        this->specialize = "";
        this->class_name = "";
        this->phoneNumber = "";
    }
    Student(string id, string fullName, string address, string specialize, string class_name, string phoneNumber) {
        this->id = id;
        this->fullName = fullName;
        this->address = address;
        this->specialize = specialize;
        this->class_name = class_name;
        this->phoneNumber = phoneNumber;
    }
    //getter
    string getId() {
        return id;
    }
    string getFullName() {
        return fullName;
    }
    string getAddress() {
        return address;
    }
    string getSpecialize() {
        return specialize;
    }
    string getClassName() {
        return class_name;
    }
    string getPhoneNumber() {
        return phoneNumber;
    }
    //setter
    void setId(string id) {
        this->id = id;

    }
    void setFullName(string fullName) {
        this->fullName = fullName;

    }
    void setAddress(string address) {
        this->address = address;

    }
    void setSpecialize(string specialize) {
        this->specialize = specialize;

    }
    void setClassName(string class_name) {
        this->class_name = class_name;

    }
    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    /*void input() {
        cin.ignore();
        cout << "Nhap ma sinh vien: "; getline(cin, id);

        cout << "Nhap ten day du cua sinh vien: "; getline(cin, fullName);

        cout << "Nhap dia chi: "; getline(cin, address);

        cout << "Nhap chuyen nganh: "; getline(cin, specialize);

        cout << "Nhap ten lop: "; getline(cin, class_name);

        cout << "Nhap so dien thoai: "; getline(cin, phoneNumber);
    }*/
    void display()
    {
        cout << "| " << setw(5) << left << id << "\t\t| "
            << setw(15) << getFullName() << "\t| "
            << setw(15) << getAddress() << "\t| "
            << setw(15) << getSpecialize() << "\t| "
            << setw(10) << getClassName()<<"\t| "
            << setw(10) << getPhoneNumber() << "\t|" << endl;
    }
};

class DataStudent {
private:
    vector<Student>listStudent;
public:
    DataStudent() {
        readfile();
    }
    void readfile() {
        ifstream fi("Student.txt");
        while (!fi.eof()) {
            string id, name, address, specialize, className, phoneNumber;
            getline(fi, id, ',');
            getline(fi, name, ',');
            getline(fi, address, ',');
            getline(fi, specialize, ',');
            getline(fi, className, ',');
            getline(fi, phoneNumber, '\n');
            if (id == "" || name == "" || address == "" || specialize == "" || className == "" || phoneNumber == "")
                break;
            Student st(id, name, address, specialize, className, phoneNumber);
            listStudent.push_back(st);
        }
        fi.close();
    }
    void addToVector() {
        /*int n;
        cout << "Nhap so sinh vien muon them: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Thong tin cua sinh vien thu " << i + 1 << ":\n";
            Student s;
            s.input();
            listStudent.push_back(s);
        }*/
        //Student st(
        string id;
        string fullName;
        string address;
        string specialize;
        string class_name;
        string phoneNumber;
        int n;
        cout << "Nhap so sinh vien muon them: ";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            cout << "Nhap ma sinh vien: ";
            getline(cin, id);
            cout << "Nhap ten: ";
            getline(cin, fullName);
            handle_string(fullName);
            cout << "Nhap dia chi: ";
            getline(cin, address);
            handle_string(address);
            cout << "Nhap chuyen nganh: ";
            getline(cin, specialize);
            handle_string(specialize);
            cout << "Nhap lop: ";
            getline(cin, class_name);
            handle_string(class_name);
            cout << "So dien thoai: ";
            getline(cin, phoneNumber);
            Student st(id, fullName, address,specialize, class_name, phoneNumber);
            listStudent.push_back(st);
            writeFile();
        }

    }
    void writeFile() {
        ofstream fo("Student.txt");
        for (int i = 0; (unsigned)i <listStudent.size(); i++) {
            fo << listStudent.at(i).getId() << ","
                << listStudent.at(i).getFullName()
                << "," << listStudent.at(i).getAddress() << ","
                << listStudent.at(i).getSpecialize()
                << "," << listStudent.at(i).getClassName()
                << "," << listStudent.at(i).getPhoneNumber() << endl;
        }
        fo.close();
    }
    void handle_string(string& str) {
        while (str[0] == ' ')
        {
            str.erase(str.begin() + 0);
        }
        while (str[str.length() - 1] == ' ')
        {
            str.erase(str.begin() + str.length() - 1);
        }
        for (int i = 0; i < str.length(); i++)
        {

            if (str[i] == ' ' && str[i + 1] == ' ')
            {
                str.erase(str.begin() + i);
                i--;
            }
        }
        for (int i = 0; i < str.length(); i++) {
            //65 90
            if (str[i] >= 65 && str[i] <= 90)
                str[i] += 32;
        }
        if (str[0] != ' ')
        {
            if (str[0] >= 97 && str[0] <= 122)
            {
                str[0] -= 32;
            }

        }
        for (int i = 0; i < str.length() - 1; i++)
        {
            if (str[i] == ' ' && str[i + 1] != ' ')
            {

                if (str[i + 1] >= 97 && str[i + 1] <= 122)
                {
                    str[i + 1] -= 32;
                }
            }
        }
    }
    void display() {
        cout << setw(100) << "List of employees are working at Quyet Vjp Pro's Cafe" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "| Id\t\t| Name\t\t\t| Address\t\t| Specialize\t\t| Class\t\t| Phone Number\t|" << endl;

        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; unsigned(i) < listStudent.size(); i++) {
            listStudent.at(i).display();
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    void findByName(string name) {
        bool flag = false;
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "| Id\t\t| Name\t\t\t| Address\t\t| Specialize\t\t| Class\t\t| Phone Number\t|" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < listStudent.size(); i++) {
            if (listStudent.at(i).getFullName().find(name) != string::npos) {
                listStudent.at(i).display();
                flag = true;
            }
        }
        if (flag == false) {
            cout << "|" << setw(80) << "Can't find!\t\t\t\t\t\t|" << endl;
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    void Delete(string nameOfStudent)
    {
        int position = -1;
        for (int i = 0; (unsigned)i < listStudent.size(); i++) {
            if (listStudent.at(i).getFullName().compare(nameOfStudent) == 0) {
                position = i;
                break;
            }
        }
        if (position > -1) {
            listStudent.erase(listStudent.begin() + position);
            cout << "Success!" << endl;
        }
        else {
            cout << "Can't find this Student!" << endl;;
        }
    }
    void DeleteAnStudent()
    {
        string nameOfStudent;
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, nameOfStudent);
        fflush(stdin);
        Delete(nameOfStudent);
        writeFile();
    }
    int findById(string id)
    {
        int posOfId = -1;
        for (int i = 0; (unsigned)i < listStudent.size(); i++) {
            if (listStudent.at(i).getId().compare(id) == 0) {
                posOfId = i;
                break;
            }
        }
        return posOfId;
    }

    void EditAnStudent()
    {
        string IdOfStudent;
        string nameOfStudentWantToEdit;
        string addressWantToEdit;
        string specializeOfStudentWantToEdit;
        string classNameOfStudentWantToEdit;
        string phoneNumberOfStudentWantToEdit;
        cout << "Enter id of student: ";
        cin.ignore();
        getline(cin, IdOfStudent);
        int pos = findById(IdOfStudent);
        if (pos > -1) {
            cout << "Enter name you want to edit to: ";
            getline(cin, nameOfStudentWantToEdit);
            handle_string(nameOfStudentWantToEdit);
            cout << "Enter address you want to edit to: ";
            getline(cin, addressWantToEdit);
            handle_string(addressWantToEdit);
            cout << "Enter specialize you want to edit to: ";
            getline(cin, specializeOfStudentWantToEdit);
            handle_string(specializeOfStudentWantToEdit);
            cout << "Enter class name you want to edit to: ";
            getline(cin, classNameOfStudentWantToEdit);
            cout << "Enter phone number you want to edit to: ";
            getline(cin, phoneNumberOfStudentWantToEdit);
            listStudent.at(pos).setFullName(nameOfStudentWantToEdit);
            listStudent.at(pos).setAddress(addressWantToEdit);
            listStudent.at(pos).setSpecialize(specializeOfStudentWantToEdit);
            listStudent.at(pos).setClassName(classNameOfStudentWantToEdit);
            listStudent.at(pos).setPhoneNumber(phoneNumberOfStudentWantToEdit);
            cout << "Success!" << endl;
            writeFile();
        }
        else {
            cout << "Can't find this student!" << endl;
            return;
        }
    }

};
int main() {
    DataStudent dt;
    while (true) {
    cout << "1. Them sinh vien vao he thong" << endl;
    cout << "2. Tim kiem" << endl;
    cout << "3. Xoa sinh vien" << endl;
    cout << "4. Sua thong tin" << endl;
    cout << "5. Hien thi" << endl;
    int n;
    cin >> n;
    if (n == 1) {
        dt.addToVector();
        dt.writeFile();
        cout << "Them thanh cong"<<endl;
    }
    if (n == 2) {
        string name;
        cout << "Nhap ten sinh vien can tim: ";
        cin.ignore();
        getline(cin, name);
        dt.findByName(name);
    }
    if (n == 3) {
        dt.DeleteAnStudent();
        dt.display();
    }
    if (n == 4) {
        dt.EditAnStudent();
    }
    if (n == 5) {
        dt.display();
    }
    system("pause");
    system("cls");
    // dua cac so tu 1 den n vao file
    //    int n;
    //    cin>>n;
    //    ofstream fo("Output.txt");
    //    for(int i = 1 ; i <= n ; i++){
    //        fo<<i<<endl;
    //    }
    //    fo.close();
    //------------------------------------------------
    //lay cac so trong file in ra man hinh
    //    ifstream fi("Output.txt");
    //    int n;
    //    fi>>n;
    //    for(int i = 0 ; i < n; i++){
    //        int value;
    //        fi>>value;
    //        cout<<value<<endl;
    //    }
    //    fi.close();
    }
    return 0;
}
