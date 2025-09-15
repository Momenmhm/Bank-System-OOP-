#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsFindUserScreen.h"
#include "clsUsersListScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsAddNewUserScreen.h"

using namespace std;

class clsManageUsersScreen :protected clsScreen{

    private:
        enum enManageUsersMenueOptions {
            eListUsers = 1, eAddNewUser = 2,
            eDeleteUser = 3,eUpdateUser = 4,
            eFindUser = 5,    eMainMenue = 6
        };
    
        static short ReadManageUsersMenueOption(){
            
            cout  << left << "" << "Choose what do you want to do? [1 to 6]? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
            return Choice;
        }
    
        static void _GoBackToManageUsersMenue(){
            
            cout << "\n\nPress any key to go back to Manage Users Menue...";
            system("pause>0");
            ShowManageUsersMenue();
        }
    
        static void _ShowListUsersScreen(){

            clsUsersListScreen :: ShowUsersList();
    
        }
    
        static void _ShowAddNewUserScreen(){
            

            clsAddNewUserScreen :: ShowAddNewUserScreen() ; 
    
        }
    
        static void _ShowDeleteUserScreen(){
            
            clsDeleteUserScreen :: ShowDeleteUserScreen() ; 
    
        }
    
        static void _ShowUpdateUserScreen(){
            
            clsUpdateUserScreen :: ShowUpdateUserScreen() ;
        }
    
        static void _ShowFindUserScreen(){
             
             clsFindUserScreen :: ShowFindUserScreen();  
             
        }
    
    
        static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOptio n) {
    
            switch (ManageUsersMenueOption) {
            case enManageUsersMenueOptions::eListUsers:{
                system("cls");
                _ShowListUsersScreen();
                _GoBackToManageUsersMenue();
                break;
            }
    
            case enManageUsersMenueOptions::eAddNewUser:{
                system("cls");
                _ShowAddNewUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }
    
            case enManageUsersMenueOptions::eDeleteUser:{
                system("cls");
                _ShowDeleteUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }
    
            case enManageUsersMenueOptions::eUpdateUser:{
                system("cls");
                _ShowUpdateUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }
    
            case enManageUsersMenueOptions::eFindUser:{
                system("cls");
    
                 _ShowFindUserScreen();
                _GoBackToManageUsersMenue();
                break;
            }
    
            case enManageUsersMenueOptions::eMainMenue: {
                
                break  ; 
             }
          }    
        }   
        
    public:
       
        static void ShowManageUsersMenue(){
            
            
             if (!CheckAccessRights(clsUser::enPermissions:: pManageUsers )){
            return;
        }
            
            system("cls");
            _DrawScreenHeader(" Manage Users Screen");
    
            cout  << left << "" << "===========================================\n";
            cout << left << "" << "\t\t  Manage Users Menue\n";
            cout << left << "" << "===========================================\n";
            cout << left << "" << "\t[1] List Users.\n";
            cout << left << "" << "\t[2] Add New User.\n";
            cout << left << "" << "\t[3] Delete User.\n" ;
            cout << left << "" << "\t[4] Update User.\n";
            cout << left << "" << "\t[5] Find User.\n";
            cout << left << "" << "\t[6] Main Menue.\n";
            cout  << left << "" << "===========================================\n";
    
            _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
        }
    
};
