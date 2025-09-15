#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std ;

class clsFindClientScreen : protected clsScreen{
    
     private : 
         
         static void _PrintClient (clsBankClient& Client ){
            
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirst Name   : " << Client.GetFirstName();
            cout << "\nLast Name    : " << Client.GetLastName();
            cout << "\nFull Name   : " << Client.Full_Name();
            cout << "\nEmail       : " << Client.GetEmail();
            cout << "\nPhone       : " << Client.GetPhone();
            cout << "\nAcc. Number : " << Client.AccountNumber();
            cout << "\nPassword    : " << Client.PinCode();
            cout << "\nBalance     : " << Client.AccountBalance();
            cout << "\n___________________\n";
                                   
        }        
                         
        
     public :
         
         static void ShowFindClientScreen(){
             
             
             if (!CheckAccessRights(clsUser::enPermissions:: pFindClient )){
            return;
        }
              
           _DrawScreenHeader(" Delete Client Screen");


            _DrawScreenHeader("Find Client Screen");
    
            string AccountNumber;
            cout << "\nPlease Enter Account Number: ";
            AccountNumber = clsInputValidate::ReadString();
            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nAccount number is not found, choose another one: ";
                AccountNumber = clsInputValidate::ReadString();
            }
    
            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    
            if (!Client1.IsEmpty())
            {
                cout << "\nClient Found :-)\n";
            }
            else
            {
                cout << "\nClient Was not Found :-(\n";
            }
    
            _PrintClient(Client1);    
    }
                  
};
