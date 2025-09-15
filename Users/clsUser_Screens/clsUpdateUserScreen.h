#pragma once 
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std ;

class clsUpdateUserScreen : protected clsScreen {
    
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
                 cout << "\n Give a Permission to show list User ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pListClients  ; 
                 }
                 cout << "\n Give a Permission to Add new User ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pAddNewClient ; 
                 }
                 cout << "\n Give a Permission to delete User ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pDeleteClient ; 
                 }
                 
                 cout << "\n Give a Permission to update User ? " ;
                 cin >> answer ; 
                 if (tolower(answer) =='y'){
                     Permissions += clsUser :: enPermissions :: pUpdateClients ; 
                 }
                 
                 cout << "\n Give a Permission to find User ? " ;
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
        
        
    
    
    public : 
        
        static void ShowUpdateUserScreen(){
            
            string UserName = "" ; 
    
            cout << "\n enter the User Name to update : " ;
            UserName=clsInputValidate::ReadString();
            while (! clsUser :: IsUserExist (UserName) ){
                
                cout << "\nUser Name is not found, choose another one: ";
                UserName = clsInputValidate::ReadString();
                        
            }
            clsUser User = clsUser:: Find(UserName) ; 
            _PrintUser(User);
            
            cout <<"\n are you sure to update User info ?  (y/n) : " ;
            char answer = 'n' ; 
            cin >> answer ; 
            
            if ( tolower(answer) != 'y' ) {
                return ; 
            }
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";    
            
            _ReadUserInfo(User );
            
            clsUser :: enSaveResults SaveResult ; 
            
            SaveResult = User.Save() ;
            
            switch (SaveResult){
                
                case clsUser :: enSaveResults ::  svFaildEmptyObject : {
                    
                    cout <<"\n Error happened ! , User not updated because it's empty \n";
                    break ; 
                }
                case clsUser :: enSaveResults ::  svSucceeded :{
                    
                    cout <<"\n User updated successfully! \n" ;
                    _PrintUser(User);
                }
            }
                                
        }    
    
};
