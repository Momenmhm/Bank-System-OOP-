#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std ;

class clsFindUserScreen : protected clsScreen {
    
    
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
        
        
        static void ShowFindUserScreen()
    {

            _DrawScreenHeader("Find User Screen");
    
            string UserName;
            cout << "\nPlease Enter User Name : ";
            UserName = clsInputValidate::ReadString();
            while (!clsUser::IsUserExist(UserName))
            {
                cout << "\nUser Name  is not found, choose another one: ";
                UserName = clsInputValidate::ReadString();
            }
    
            clsUser User1 = clsUser::Find(UserName);
    
            if (!User1.IsEmpty())
            {
                cout << "\nUser Found :-)\n";
            }
            else
            {
                cout << "\nUser Was not Found :-(\n";
            }
    
            _PrintUser(User1);    
    }

        
    
    
};
