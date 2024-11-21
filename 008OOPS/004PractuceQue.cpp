#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int id;
    string password;

public:
    string username;

    User (int id){
        this->id = id;
    }

    // Getter 
    string getPassword(){
        return password;
    }

    // Setter
    void setPassword(string password){
        this->password = password;
    }



};

int main() {
    User user1(101);
    user1.username = "rahul";
    user1.setPassword("1234");

    cout << "Username: " << user1.username << endl;
    cout << "Password: " << user1.getPassword() << endl;


    return 0;
}  
