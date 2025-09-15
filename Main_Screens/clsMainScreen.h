#pragma once 
#include <iomanip>
#include <iostream>
#include "Global.h"
#include "clsScreen.h"
#include "clsLoginScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h" 
#include "clsFindClientScreen.h"
#include "clsTransActionScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

class clsMainScreen  : protected clsScreen {
    
    
    private : 
        
        enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2,
            eDeleteClient = 3, eUpdateClient = 4,
            eFindClient = 5, 
            eShowTransactionsMenue = 6,
            eManageUsers = 7, eLogRegesterList = 8 ,eCurrencyExchange = 9 ,  eExit = 10
        };
        
        
        static short _ReadMainMenueOption(){
            
            cout <<"\n  Choose what do you want to do? [1 to 10]? "; 
            short option = clsInputValidate :: ReadShortNumberBetween ( 1 , 10 ,"Enter Number between 1 to 10? " ) ; 
            
            return option ;
        }
        
        static void _GoBackToMainMenue(){
            
            cout <<"\n press any key to go back to main screen ....\n" << endl ; 
            
            system(" pause>0");
            ShowMainMenue() ; 
        }
        
        
        static void _ShowAllClientsScreen(){
            
                clsClientListScreen :: ShowClientsList();
        
       }

       static void _ShowAddNewClientsScreen(){
           
           clsAddNewClientScreen :: ShowAddNewClientScreen () ;
       }

       static void _ShowDeleteClientScreen()  {
           
           clsDeleteClientScreen :: ShowDeleteClientScreen();

       }

       static void _ShowUpdateClientScreen(){

           
           clsUpdateClientScreen :: ShowUpdateClientScreen () ;
       }

       static void _ShowFindClientScreen() {

           clsFindClientScreen :: ShowFindClientScreen() ; 

       }

       static void _ShowTransactionsMenue() {

           clsTransActionScreen :: ShowTransactionsMenue (); 

       }

       static void _ShowManageUsersMenue()  {
           
           clsManageUsersScreen :: ShowManageUsersMenue() ;
           
       }
       static void _ShowCurrencyExchangeMenue(){
           
           clsCurrencyExchangeMainScreen:: ShowCurrenciesMenue(); 
       }
       static void _ShowLoginRegesterScreen(){
           
           clsLoginRegisterScreen:: ShowLoginRegisterScreen () ;
       }

      // static void _ShowEndScreen() {
//               cout << "\nEnd Screen Will be here...\n";

//           }
        static void _Logout (){
            
            CurrentUser = clsUser :: Find("","");
       //     clsLoginScreen :: ShowLoginScreen();
        }
        
        
        static void _PerfromMainMenueOption (enMainMenueOptions MenueOption ){
            
            
            switch ( MenueOption ){
                
                case enMainMenueOptions :: eListClients : {
                    system("cls");
                    _ShowAllClientsScreen(); 
                    _GoBackToMainMenue(); 
                    break ; 
                }
               case  enMainMenueOptions :: eAddNewClient :{
                    system("cls");
                    _ShowAddNewClientsScreen();
                    _GoBackToMainMenue();
                    break ; 
               }
               
               case  enMainMenueOptions ::eDeleteClient : {
                    system("cls");
                    _ShowDeleteClientScreen();
                    _GoBackToMainMenue();
                    break ; 
               }
                
               case  enMainMenueOptions ::eUpdateClient :{
                    system("cls");
                    _ShowUpdateClientScreen();
                    _GoBackToMainMenue();
                    break ; 
               }
                
              case enMainMenueOptions ::eFindClient :{
                    system("cls");
                    _ShowFindClientScreen();
                    _GoBackToMainMenue();
                    break ; 
              }
              
              case   enMainMenueOptions ::eShowTransactionsMenue :{
                  system("cls");
                  _ShowTransactionsMenue();
                  _GoBackToMainMenue();
                  break ; 
              }
              
              case enMainMenueOptions :: eManageUsers :{
                  system("cls");
                  _ShowManageUsersMenue();
                  _GoBackToMainMenue();
                  break ; 
              }
              case  enMainMenueOptions :: eLogRegesterList  : {
                  
                  system ("cls");
                  _ShowLoginRegesterScreen();
                  _GoBackToMainMenue();
                  break ;
              }
              case enMainMenueOptions:: eCurrencyExchange:{
                  
                  system ("cls");
                  _ShowCurrencyExchangeMenue();
                  _GoBackToMainMenue();
                  
              }
              
              
              case enMainMenueOptions :: eExit :{
                  system("cls");
                  _Logout();
           //       _GoBackToMainMenue();
                  break ; 
              }
            }                                    
        }
    
    
    public : 
        
        
        static void ShowMainMenue() {
           
            system("cls");
            _DrawScreenHeader("Main Screen");

            cout  << left <<""<< "===========================================\n";
            cout << left << "" << "\t\t Main Menue\n";
            cout  << left << "" << "===========================================\n";
            cout << left << "" << "\t[1] Show Client List.\n";
            cout  << left << "" << "\t[2] Add New Client.\n";
            cout  << left << "" << "\t[3] Delete Client.\n";
            cout << left << "" << "\t[4] Update Client Info.\n";
            cout  << left << "" << "\t[5] Find Client.\n";
            cout  << left << "" << "\t[6] Transactions.\n";
            cout  << left << "" << "\t[7] Manage Users.\n";
            cout << left << "" << "\t[8] Show Login Regester. \n" ; 
            cout << left << "" << "\t[9] Currency Exchange. \n" ; 
            cout << left << "" << "\t[10] Logout.\n";
            cout  << left << "" << "===========================================\n";
            
           _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
            
      }   
    
};
