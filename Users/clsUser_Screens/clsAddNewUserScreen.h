#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h" 

using namespace std ;

class clsAddNewUserScreen : protected clsScreen {
    
    private :
        
        static void _ReadUserInfo(clsUser& User ){
            
            cout << "\nEnter First Name: ";
            User.FirstName( clsInputValidate::ReadString());
    
            cout << "\nEnter Last Name: ";
            User.SetLastName( clsInputValidate::ReadString());
        
            cout << "\nEnter Email: ";
            User.SetEmail( clsInputValidate::ReadString());
        
            cout << "\nEnter Phone: ";
            User.SetPhone( clsInputValidate::ReadString());
        
            cout << "\nEnter Password : ";
            User.SetPassword( clsInputValidate::ReadString());
        
            cout << "\nEnter Permissions : ";
            User.SetPermissions( ReadPermissionsToSet ());
            
        }
        static int ReadPermissionsToSet(){
            
            int Permissions = 0; 
            char answer = 'n' ; 
            
            cout <<"\n do you want to set all permissions ? (y/n) " ;
            cin >> answer ; 
            if (tolower(answer) =='y' ){
                
                Permissions += (clsUser :: enPermissions ::eAll ); 
                return Permissions ; 
            }
            else { 
                 cout << "\n Give a Permission to show list client ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pListClients  ; 
                 }
                 cout << "\n Give a Permission to Add new client ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pAddNewClient ; 
                 }
                 cout << "\n Give a Permission to delete client ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pDeleteClient ; 
                 }
                 
                 cout << "\n Give a Permission to update client ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pUpdateClients ; 
                 }
                 
                 cout << "\n Give a Permission to find client ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pFindClient ; 
                 }
                 
                 cout << "\n Give a Permission to transactions ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pTranactions ; 
                 }
                 
                 cout << "\n Give a Permission to ManageUsers ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pManageUsers ; 
                 }
                 
                 cout << "\n Give a Permission to Login Register ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pLogRegister ; 
                 }
                 
                 return Permissions ; 
            }
            
            
        }
        
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
        
        
        static void ShowAddNewUserScreen(){

            _DrawScreenHeader("\t  Add New User Screen");
    
            string UserName = "";
    
            cout << "\nPlease Enter UserName: ";
            UserName = clsInputValidate::ReadString();
            while (clsUser::IsUserExist(UserName))
            {
                cout << "\nUserName Is Already Used, Choose another one: ";
                UserName = clsInputValidate::ReadString();
            }
    
            clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
    
            _ReadUserInfo(NewUser);
    
            clsUser::enSaveResults SaveResult;
    
            SaveResult = NewUser.Save();
    
            switch (SaveResult){
                
                case  clsUser::enSaveResults::svSucceeded:{
                    
                    cout << "\nUser Addeded Successfully :-)\n";
                    _PrintUser(NewUser);
                    break;
                }
                case clsUser::enSaveResults::svFaildEmptyObject:{
                    
                    cout << "\nError User was not saved because it's Empty";
                    break;
        
                }
                case clsUser::enSaveResults::svFaildUserExists:{
                    
                    cout << "\nError User was not saved because UserName is used!\n";
                    break;
        
                }
            }
    }
        
    
    
};
