#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std ;

class clsUpdateClientScreen : protected clsScreen{
    
    private :
        
        static void _ReadClientInfo(clsBankClient& Client ){
            
            cout << "\nEnter First Name: ";
            Client.FirstName( clsInputValidate::ReadString());
    
            cout << "\nEnter Last Name: ";
            Client.SetLastName( clsInputValidate::ReadString());
        
            cout << "\nEnter Email: ";
            Client.SetEmail( clsInputValidate::ReadString());
        
            cout << "\nEnter Phone: ";
            Client.SetPhone( clsInputValidate::ReadString());
        
            cout << "\nEnter PinCode: ";
            Client.SetPinCode( clsInputValidate::ReadString());
        
            cout << "\nEnter Account Balance: ";
            Client.SetAccountBalance( clsInputValidate::ReadFloatNumber());
            
        }
        
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
        
        static void ShowUpdateClientScreen(){
            
            
            if (!CheckAccessRights(clsUser::enPermissions:: pUpdateClients )){
            return;
        }
              
           _DrawScreenHeader(" Delete Client Screen");
            
            
            string AccountNumber = "" ; 
    
            cout << "\n enter the account number to update : " ;
            AccountNumber=clsInputValidate::ReadString();
            while (! clsBankClient :: IsClientExist (AccountNumber) ){
                
                cout << "\nAccount number is not found, choose another one: ";
                AccountNumber = clsInputValidate::ReadString();
                        
            }
            clsBankClient client = clsBankClient:: Find(AccountNumber) ; 
            _PrintClient(client);
            
            cout <<"\n are you sure to update client info ?  (y/n) : " ;
            char answer = 'n' ; 
            cin >> answer ; 
            
            if ( tolower(answer) != 'y' ) {
                return ; 
            }
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";    
            
            _ReadClientInfo(client );
            
            clsBankClient :: enSaveResults SaveResult ; 
            
            SaveResult = client.Save() ;
            
            switch (SaveResult){
                
                case clsBankClient :: enSaveResults ::  svFaildEmptyObject : {
                    
                    cout <<"\n Error happened ! , client not updated because it's empty \n";
                    break ; 
                }
                case clsBankClient :: enSaveResults ::  svSucceeded :{
                    
                    cout <<"\n client updated successfully! \n" ;
                    _PrintClient(client);
                }
            }
                                
        }
                    
    
};
