#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

//A struct that holds all the information about a user in the system
struct User {
     std::string username;
     float gpa;
     int age;
};

//A function that adds a user to the array of users
void addUser(User users[], std::string _username, float _gpa, int _age, int length)
{
     User newUser; //Intilizes a new user

     //Sets the new users info
     newUser.username = _username;
     newUser.gpa = _gpa;
     newUser.age = _age;

     users[length] = newUser; //Adds the user too the array
}

//Prints out the information of each user in the array
void printList(const User users[], int length)
{
     //For each user in the array, print out their information
     for(int i = 0; i<length; i++)
     {
          std::cout << users[i].username << " [" << users[i].gpa << "] age: " << users[i].age << '\n';
     }
}

int main(int argc, char *argv[])
{
     User users[100];
     int numOfUsers = 0;

     std::ifstream data;
     std::string line;
     data.open(argv[1]);

     //For each line row in the file fill out the user information based off the cell information
     while(std::getline(data,line))
     {
         std::stringstream ss;
         ss<<line;
         std::string cell;

         std::getline(ss,cell,',');
         users[numOfUsers].username = cell;

         std::getline(ss,cell,',');
         users[numOfUsers].gpa = stof(cell);

         std::getline(ss,cell);
         users[numOfUsers].age = stoi(cell);

         numOfUsers++;
     }

     data.close();

     printList(users, numOfUsers);

     std::ofstream newFile;
     newFile.open(argv[2]); //Creates or overwrites a file
     //For each user in the array...
     for(int i = 0; i<numOfUsers; i++)
     {
          //If the users GPA is higher then the inputed min then write it to a file
          if(users[i].gpa > std::stof(argv[3]))
          {
               newFile << users[i].username << "," << users[i].gpa << "," << users[i].age << std::endl;
          }
     }
     newFile.close();
 }
