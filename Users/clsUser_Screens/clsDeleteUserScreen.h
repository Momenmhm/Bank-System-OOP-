//#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std ; 

class clsDeleteUserScreen : protected clsScreen {
    
    private :
        
        static void _PrintUser(clsUser& User){
            
            cout << "\nUser Card:";
            cout << "\n___________________";
            cout << "\nFirst Name   : " << User.GetFirstName();
            cout << "\nLast Name    : " << User.GetLastName();
            cout << "\nFull Name   : " << User.Full_Name();
            cout << "\nEmail       : " << User.GetEmail();
            cout << "\nPhone       : " << User.GetPhone();
            
            cout << "\nPassword    : " << User.Password();
            cout << "\nPermissions     : " << User.Permissions();
            cout << "\n___________________\n";
                                   
        }        
                        
    public : 
        
        static void ShowDeleteUserScreen  (){
          
           _DrawScreenHeader(" Delete User Screen");
           
           string UserName = "";

        cout << "\nPlease Enter User Name : ";
        UserName  = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser :: Find(UserName); 
        _PrintUser(User); 
        
        cout << "\n Are you sure to delete this User ? (y/n) ? "; 
        char answer = 'n' ; 
        cin >> answer ; 
        
        if (answer == 'y' || answer == 'Y'){
            
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
    
                _PrintUser(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
                
            }
        }                
    }       
};
