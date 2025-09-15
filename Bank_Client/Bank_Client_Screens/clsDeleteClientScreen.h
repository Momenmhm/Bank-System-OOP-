//#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std ; 

class clsDeleteClientScreen : protected clsScreen {
    
    private :
        
        static void _PrintClient(clsBankClient Client){
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << Client.GetFirstName();
            cout << "\nLastName    : " << Client.GetLastName();
            cout << "\nFull Name   : " << Client.Full_Name();
            cout << "\nEmail       : " << Client.GetEmail();
            cout << "\nPhone       : " << Client.GetPhone();
            cout << "\nAcc. Number : " << Client.AccountNumber();
            cout << "\nPassword    : " << Client.PinCode();
            cout << "\nBalance     : " << Client.AccountBalance();
            cout << "\n___________________\n";
    
        }
                        
    public : 
        
        static void ShowDeleteClientScreen  (){
          
              
              if (!CheckAccessRights(clsUser::enPermissions:: pDeleteClient )){
            return;
        }
              
           _DrawScreenHeader(" Delete Client Screen");
           
           string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient :: Find(AccountNumber); 
        _PrintClient(client); 
        
        cout << "\n Are you sure to delete this client ? (y/n) ? "; 
        char answer = 'n' ; 
        cin >> answer ; 
        
        if (answer == 'y' || answer == 'Y'){
            
            if (client.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
    
                _PrintClient(client);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
                
            }
        }                
    }       
}; 
