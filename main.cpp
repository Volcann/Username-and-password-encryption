#include <iostream>
#include <fstream>
using namespace std;

void passwordWORKING(int);
void askSECURITYquestion(int);
bool passwordVALIDATION(string);
void menuworking();
void login();
void rigester();
void exitTHEprogram();
void DELETEALLcontent();
void LOGOUT();
string decryption(string);

string option;
static string username ,
              password ,
     security_question ,
       security_answer ;

void retrievedata(){
    fstream file;
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/username_database.txt",ios::in);
    while (file) {
        getline(file, username);
    }
    file.close();
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/password_ENCRYPTED_database.txt",ios::in);
    while (file) {
        getline(file, password);
    }
    file.close();
    password = decryption(password);
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/security_question_database.txt",ios::in);
    while (file) {
        getline(file, security_question);
    }
    file.close();
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/security_answer_database.txt",ios::in);
    while (file) {
        getline(file,security_answer);
    }
    file.close();
}

bool checkNUMBER(string data){
    for(int i = 0 ; i < data.size() ; i++ ){
        if(isdigit(data[i])) continue;
        else return 0;
    }
    return 1;
}

bool checkGMAIL(string data){
    for(int i = 0 ; i < data.size() ; i++ ){
        if(data[i] == '@') return 1;
        else continue;
    }
    return 0;
}

bool checkSPACE(string data){
    for(int i = 0 ; i < data.size() ; i++){
        if(data[i] == ' ') return 0;
    }
    return 1;
}

bool passwordVALIDATION(string data) {
    bool arr[3] = {0,0,0};
    
    //Upper
    for(int i = 0 ; i < data.size() ; i++) {
        if(isupper(data[i])) {
            arr[0] = 1;
            break;
        }
        else continue ;
    }

    //Lower
    for(int i = 0 ; i < data.size() ; i++) {
        if(islower(data[i])) {
            arr[1] = 1;
            break;
        }
        else continue ;
    }
    
    //Not alpha and number
    for(int i = 0 ; i < data.size() ; i++) {
        if(!isalnum(data[i])){
            arr[2] = 1;
            break;
        }
        else continue ;
    }

    for(int i = 0 ; i < 3 ; i++) {
        if(arr[i] == 0) return 0;
        else continue;
    }
    return 1;
}

bool checkUSERNAME(string data){
    if(data == username) return 1;
    return 0;
}

bool iseven(char ch){
    if(ch%2 == 0)return 1;
    return 0;
}

string encryption(string data) {
    for(int i = 0 ; i < data.size() ; i++) {
        data[i] = data[i] - 2;
    }
    return data;
}

string decryption(string data) {
    for(int i = 0 ; i < data.size() ; i++) {
        data[i] = data[i] + 2;
    }
    return data;
}

void askSECURITYquestion(int data){
    string new_security_question , new_security_answer;
    int tries = 1;
    
    cout << "Enter your question : ";
    cin.ignore();
    while (tries != -1) {
        getline(cin, new_security_question);
        if(new_security_question == security_question) break;
        else{
            cout << "Wrong Question !! "<<endl;
            if(tries == 0){
                passwordWORKING(data);
            }
        }
        tries--;
    }
    
    tries = 1;
    cout << "Enter your answer : ";
    while (tries != -1) {
        getline(cin, new_security_answer);
        if(new_security_answer == security_answer) break;
        else {
            cout << "Wrong Answer !! "<<endl;
            if(tries == 0){
                passwordWORKING(data);
            }
        }
        tries--;
    }
    if(new_security_answer == security_answer){
        cout << endl; cout << endl; cout << endl; cout << endl;
        cout << "Login SUCCESSFUL !! " << endl;
        LOGOUT();
    }
    return;
}

void passwordWORKING(int tries){
    string new_password;
    fstream file;
    tries -= 1;
    
    cout << "Enter Password : ";
    if(tries == 1 || tries == 0) cin.ignore();
    while (tries != -1) {
        getline(cin, new_password);
        if(new_password == password){
            cout << endl; cout << endl; cout << endl; cout << endl;
            cout << "Login succesfull !! " << endl;
            cout << endl; cout << endl;
            LOGOUT();
            cout << endl; cout << endl; cout << endl; cout << endl;
        }
        else {
            cout << endl; cout << endl; cout << endl;
            cout << "Wrong Password Try again !! " << endl;
            cout << "Only " << tries << " Try left. " << endl;
            cout << endl; cout << endl; cout << endl;
            cout << "Enter 1 to Try Again" << endl;
            cout << "Enter 2 to Ask Security Question" << endl;
            cout << "Enter 0 to Main Menu " << endl;
            while (true) {
                cin >> option;
                if(option == "1") passwordWORKING(tries);
                else if(option == "2") askSECURITYquestion(tries);
                else if(option == "0") menuworking();
                else cout << "Wrong INPUT !!" << endl;
            }
        }
        tries--;
    }
    if(tries == -1 && new_password != password){
        cout << endl; cout << endl; cout << endl; cout << endl;
        cout << "Account DELETED !! " << endl;
        DELETEALLcontent();
        menuworking();
    }
}

void menu(){
    cout << "--- Menu ---" << endl;
    cout << "1 - Login" << endl;
    cout << "2 - Rigester" << endl;
    cout << "3 - Exit" << endl;
}

void LOGOUT(){
    cout << "Enter 1 to Logout" << endl;
    cout << "Enter 2 to Exit" << endl;
    while (true) {
        cin >> option;
        if(option == "1") break;
        if(option == "2") break;
        if(option == "3") break;
        else
            cout << "Wrong Entered" << endl;
    }
    if(option == "1"){
        cout << "Account Logout !! " << endl;
        cout << endl; cout << endl; cout << endl; cout << endl;
        menuworking();
    }
    if(option == "2"){
        exitTHEprogram();
    }
}

void menuworking(){
    retrievedata();
    menu();
    while (true) {
        cin >> option;
        if(option == "1") break;
        if(option == "2") break;
        if(option == "3") break;
        else
            cout << "Wrong Entered" << endl;
    }
    if(option == "1"){
        login();
    }
    if(option == "2"){
        rigester();
    }
    if(option == "3"){
        exitTHEprogram();
    }
}

void login(){
    string data = "" , new_username ;
    cout << endl; cout << endl; cout << endl; cout << endl;
    cout << "Enter Username : ";
    cin.ignore();
    while (true) {
        getline(cin, new_username);
        if(checkUSERNAME(new_username)){
            break;
        }
        else {
            cout << "No Username Exist !! " << endl;
            cout << "Do you want to Rigester ? " << endl;
            cout << endl; cout << endl;
            cout << "Enter 0 to Answer security Question" << endl;
            cout << "Enter 1 to Rigester" << endl;
            cout << "Enter 2 to login with any other Userame" << endl;
            cout << "Enter 3 to Main menu" << endl;
            while (true) {
                cin >> option;
                if(option == "0")break;
                if(option == "1") break;
                if(option == "2") break;
                if(option == "3") break;
                else
                    cout << "Wrong Entered" << endl;
            }
            if(option == "0"){
                askSECURITYquestion(3);
            }
            if(option == "1"){
                rigester();
            }
            if(option == "2"){
                login();
            }
            if(option == "3"){
                menuworking();
            }
        }
    }
    if(checkUSERNAME(new_username)){
        passwordWORKING(3);
    }
}

void DELETEALLcontent(){
    fstream file;
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/username_database.txt",ios::out|ios::trunc);
    file.close();
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/password_ENCRYPTED_database.txt",ios::out|ios::trunc);
    file.close();
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/security_question_database.txt",ios::out|ios::trunc);
    file.close();
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/security_answer_database.txt",ios::out|ios::trunc);
    file.close();
}

void rigester(){
    cout << endl; cout << endl; cout << endl; cout << endl;
    fstream file;
    string first_name ,
            last_name ,
                gmail ,
               number ,
  new_security_answer ,
new_secuirty_question ,
         new_username ,
         new_password ,
             encrypted;
    
    cout << "Enter First Name : ";
    cin.ignore();
    getline(cin, first_name);
    cout << "Enter Last Name : ";
    cin.ignore();
    getline(cin, last_name);
    cout << "Enter Your Gmail : ";
    cin.ignore();
    while (true) {
        getline(cin, gmail);
        if(checkGMAIL(gmail))break;
        else cout << "Please Enter gmail in proper manner - " << endl;
    }
    cout << "Enter Your Number : ";
    cin.ignore();
    while (true) {
        getline(cin, number);
        if(checkNUMBER(number))break;
        else cout << "Please Enter number in digits - " << endl;
    }
    cout << "Enter Username (Withoutt spaces) : ";
    while (true) {
        cin >> new_username;
        if(new_username != username) break;
        else {
            cout << "Username Already existed ____" << endl;
            cout << "Enter any other Name :- " << endl;
        }
    }
    if(new_username != username){
        DELETEALLcontent();
        file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/username_database.txt",ios::out);
        file << new_username;
        file.close();
    }
    cout << "Enter Password (Upper case/Lower case/Special character) : ";
    while (true) {
        cin >> new_password;
        if(passwordVALIDATION(new_password))break;
        else cout << "Must use Upper case / Lower case / Special character" << endl;
    }
    if(passwordVALIDATION(new_password)){
        string pas_id = encryption(new_password);
        file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/password_ENCRYPTED_database.txt",ios::out);
        file << pas_id;
        file.close();
    }
    for(int i = 0 ; i < new_password.size() ; i++) {
        encrypted += "-";
    }
    
    //system("clear");
    cout << endl; cout << endl; cout << endl; cout << endl;
    cout << "Enter First Name : ";
    cout << first_name << endl;
    cout << "Enter Last Name : ";
    cout << last_name << endl;
    cout << "Enter Your Gmail : ";
    cout << gmail << endl;
    cout << "Enter Your Number : ";
    cout << number << endl;
    cout << "Enter Username : ";
    cout << new_username << endl;
    cout << "Enter Password : ";
    cout << encrypted << endl;
    
    cout << "Enter Security question : ";
    cin.ignore();
    getline(cin, new_secuirty_question);
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/security_question_database.txt",ios::out);
    file << new_secuirty_question;
    file.close();
    
    cout << "Enter Security Answer : ";
    getline(cin, new_security_answer);
    file.open("/Users/volcann/Library/Mobile Documents/com~apple~CloudDocs/Username project/Username project/security_answer_database.txt",ios::out);
    file << new_security_answer;
    file.close();
    cout << endl; cout << endl;
    cout << "DATA Saved !! " << endl;
    cout << "Welcome back to main menu " << endl;
    cout << endl; cout << endl; cout << endl; cout << endl;
    menuworking();
}

void exitTHEprogram(){
    cout << "Program exited " << endl;
    exit(0);
}

int main() {
    menuworking();
}
