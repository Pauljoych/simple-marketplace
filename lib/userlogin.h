#include <iostream>
#include <string>
using namespace std;

class UserLogin
{
private:
public:
  struct User
  {
    int userId;
    string userName;
    int userPassword;
  };

  int userDataIndex;
  User userData[255];

  string curentUserName;

  void init()
  {
    userDataIndex = 0;
  }

  bool userLogin()
  {
    bool isRegister = false;
    string tempUserName;
    int tempUserPassword;

    cout << "Login" << endl;
    cout << "====================" << endl;
    cout << "Username : ";
    getline(cin, tempUserName);
    cout << "Password : ";
    cin >> tempUserPassword;

    for (int i = 0; i < userDataIndex; i++)
    {
      if (userData[i].userName == tempUserName)
      {
        if (userData[i].userPassword == tempUserPassword)
        {
          isRegister = true;
          curentUserName = tempUserName;
        }
      }
    }

    return isRegister;
  };

  bool userRegister()
  {
    bool isUserNameAvail = true;
    string tempUserName;
    int tempUserPassword;

    cout << "Register" << endl;
    cout << "====================" << endl;
    cout << "Username : ";
    getline(cin, tempUserName);
    cout << "Password : ";
    cin >> tempUserPassword;

    for (int i = 0; i < userDataIndex; i++)
    {
      if (userData[userDataIndex].userName == tempUserName)
      {
        isUserNameAvail = false;
      }
    }

    if (isUserNameAvail)
    {
      userData[userDataIndex].userId = userDataIndex;
      userData[userDataIndex].userName = tempUserName;
      userData[userDataIndex].userPassword = tempUserPassword;
      userDataIndex++;
    }

    return isUserNameAvail;
  };
};
