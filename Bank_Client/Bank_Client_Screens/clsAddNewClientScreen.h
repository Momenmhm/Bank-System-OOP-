#pragma once 
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen {
    
    
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
        
        static void ShowAddNewClientScreen(){
            
            system("cls") ;
            
            if (!CheckAccessRights(clsUser::enPermissions:: pAddNewClient ))
        {
            return;// this will exit the function and it will not continue
        }
            
            _DrawScreenHeader(" Add New Client Screen");

            
            string AccountNumber = "" ; 
    
            cout << "\n enter account number : " ; 
            
            AccountNumber = clsInputValidate  :: ReadString() ; 
            
            while (clsBankClient:: IsClientExist (AccountNumber )){
                
                cout <<"\n Account number is already used , please choose another one : " ; 
                AccountNumber = clsInputValidate :: ReadString() ; 
                
            }
            clsBankClient NewClient = clsBankClient :: GetAddNewClientObject (AccountNumber ) ;
             
            ReadClientInfo(NewClient ); 
            
            clsBankClient :: enSaveResults SaveResult ; 
            
            SaveResult = NewClient.Save(); 
            
            switch (SaveResult){
                
                case clsBankClient :: enSaveResults :: svSucceeded : {
                    
                      cout << "\nAccount Addeded Successfully :-)\n";
                     NewClient.Print();
                     break;
                }
                case clsBankClient :: enSaveResults :: svFaildEmptyObject:{
                    
                    cout << "\nError account was not saved because it's Empty";
                    break;
        
                }
                case  clsBankClient :: enSaveResults :: svFaildAccountNumberExists: {
                    
                cout << "\nError account was not saved because account number is used!\n";
                break;
                }                   
            }                                                           
        }                        
};
