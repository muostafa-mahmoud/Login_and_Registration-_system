//OOP_project
// Login and Registration System
#include <bits/stdc++.h>
using namespace std;
void NewRegister();
bool validEmail(string);
bool validfirstname(string);
bool validlastname(string);
bool validpassword(string);
void verificationcode();
void Login();
int main()  // when the user opens the website
{
    cout << "Hey.." << endl;
    cout << "Welcome to our website!" << endl;
    cout << "Let's begin the journey.." << endl
         << endl;
    NewRegister();
    return 0;
}
// This function asks the user if he is a new user or have already an account
void NewRegister()
{

    string NewRegister, Username, Password, firstname, lastname, email;

    cout << "New register?  "
            "\n(Note: if you are a new user type Yes, otherwise type No) \n";

    // must be "yes" if he is a new user or "no" if he is not a new user
    cin >> NewRegister;
    cin.ignore();

    if (NewRegister == "Yes" || NewRegister == "yEs" || NewRegister == "yES"
            || NewRegister == "YeS"|| NewRegister == "YEs" || NewRegister == "YES")
    {
        // enter first name
        cout << "First name : ";
        cin >> firstname;
        while (validfirstname(firstname) == false)
        {
            cout << "The first name is not valid please try again : " << endl;
            cin >> firstname;
        }
        cout << endl
             << "Valid first name." << endl
             << endl;

        // enter last name
        cout << "Last name : ";
        cin >>lastname ;
        while (validlastname(lastname) == false)
        {
            cout << "The last name is not valid please try again : " << endl;
            cin >> lastname;
        }
        cout << endl
             << "Valid last name." << endl
             << endl;
        // enter email
        cout << "Email : ";
        cin >> email;
        while (validEmail(email) == false)
        {
            cout << "The email address is not valid please try again : " << endl;
            cin >> email;
        }
        cout << endl
             << "Valid email address." << endl
             << endl;
        // enter password
        cout << "Password : \n(Note: your password must be at least one digit,one special character, one uppercase letter, and one lowercase letter) \n";
        cin >> Password;
        while (validpassword(Password) == false)
        {
            cout << "The password is not valid please try again : " << endl;
            cin >> Password;
        }
        cout << endl
             << "Valid password." << endl
             << endl;

        cout << "Registration completed! \n" << endl;
        verificationcode();
    }
    // have already an account
    else if (NewRegister == "No"  ||NewRegister == "no" ||NewRegister == "nO")
    {
		string Username, Password;
    cout << endl    << "\tLog in\t" << endl<< endl;
    cout << "Enter your username :" << endl;
    getline(cin, Username);

    cout << "Enter your password :" << endl;
    cin >> Password;

    cout << endl
         << "Login success!" << endl;
    }
}
// function to check the validity of the first name

bool validfirstname(string firstname)
{
    if (firstname[0] >= 'A' && firstname[0] <= 'Z')
      return true;
	  else
	  return false;
}
// function to check the validity of the last name
bool validlastname(string lastname)
{
    if (lastname[0] >= 'A' && lastname[0] <= 'Z')
      return true;
    else
  	 return false;
}
// function to check the validity of the email
bool validEmail(string email)
{
    // variables to store the position of ( @ )and (dot)
    int AT = -1, dot = -1;
    // check if there is more than one (@) or (dot)
    int counterforAT = 0, counterforDot = 0;
    // if the email address start with letter(valid )
    if ((email[0] >= 'a' && email[0] <= 'z') || (email[0] >= 'A' && email[0] <= 'Z'))
    {
        for (int i = 0; i < email.length(); i++)
        {
            // If the character is '@'
            if (email[i] == '@')
            {
                AT = i;
                ++counterforAT;
            }
            // If character is '.'
            else if (email[i] == '.')
            {
                dot = i;
                ++counterforDot;
            }
        }
        // If (@) or (dot)is not present
        if (AT == -1 || dot == -1)

            return false;
        // If (dot) is present before(@)
        if (AT > dot)

            return false;

        if (counterforDot > 1 || counterforAT > 1)
            return false;

        return !(dot >= (email.length() - 1));
    }
    // if the email address start with number (not valid )
    else if (email[0] >= '0' && email[0] <= '9')
    {
        return false;
    }
    // if the email address start with other symbols (not valid)
    else
    {
        return false;
    }
}
// function to check the validity of the password
bool validpassword(string password)
{
    // counter to find if password contain at least one digit,one special character, one uppercase letter, and one lowercase letter
    int digit = 0, uppercase = 0, lowercase = 0, specialchar = 0;
    if (password.length() >= 8 && password.length() <= 15)
    {

        if (password.find(" ") == -1)
        {
            for (int i = 0; i < password.length(); i++)
            {
                if (password[i] >= '0' && password[i] <= '9')
                {
                    ++digit;
                }
                else if (password[i] >= 'a' && password[i] <= 'z')
                {
                    ++lowercase;
                }
                else if (password[i] >= 'A' && password[i] <= 'Z')
                {
                    ++uppercase;
                }
                else if (password[i] == '@' || password[i] == '#' || password[i] == '_')
                {
                    ++specialchar;
                }
            }

            if (digit == 0 || uppercase == 0 || lowercase == 0 || specialchar == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (password.find(" ") != -1)
        {

            return false;
        }
    }

    cout << "Note : your password length less than 8 characters or more than 15 characters." << endl;
    return false;
}
// verifying account
void verificationcode() {
    int code;

    cout << "We have sent a verification code to your email to confirm your account." << endl
         << "Please check your email." << endl;


    cout << "Email message: Your verification code is  ";
    srand(time(0));
    vector<int> verifi(4);
    int x = rand()%10000;
    cout<<x<<endl;
    cout << "\nEnter the verification code here : \n";
    cin >> code;
    bool flag = false;
    while(flag == false)
    if(code==x)
    {

        cout << "Your account has been verified." << endl;
        Login();
        flag =true;
    }
    else
    {
        cout << "wrong code check again ." << endl;
        cin >> code;
    }
}
void Login()
{
    string Username, Password;

    cin.ignore();
    cout << endl    << "\tLog in\t" << endl<< endl;
    cout << "Enter your username :" << endl;
    getline(cin, Username);

    cout << "Enter your password :" << endl;
    cin >> Password;

    cout << endl
         << "Login success!" << endl;
}