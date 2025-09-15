#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "clsTotalBalancesScreen.h"
using namespace std ;

class clsTransActionScreen :protected clsScreen{
    
    private : 
        
        enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eShowTransfer =4 ,
        eShowTransferList = 5,eShowMainMenue=6
        
        };
        
        static short _ReadTransactionsMenueOption(){
            
            cout <<"\n  Choose what do you want to do? [1 to 6]? "; 
            short option = clsInputValidate :: ReadShortNumberBetween ( 1 , 6 ,"Enter Number between 1 to 6? " ) ; 
            
            return option ;
        }
        
        static void _GoBackToTransActionMenue(){
            
            cout <<"\n press any key to go back to main screen ....\n\n" << endl ; 
            ShowTransactionsMenue();
//            cout << endl << endl ; 
//            system("pause>0");
            
        }
        
        
        static void _ShowDepositScreen(){
                     
            clsDepositScreen :: ShowDepositScreen() ;
            cout << endl << endl ; 
            system("pause>0");
         }
    
        static void _ShowWithdrawScreen(){
            
            clsWithdrawScreen :: ShowWithdrawScreen() ;
            cout << endl << endl ; 
            system("pause>0");
        }
    
        static void _ShowTotalBalancesScreen(){

            clsTotalBalancesScreen :: ShowTotalBalances() ; 
            cout << endl << endl ; 
            system("pause>0");
        }
        static void _ShowTransferScreen(){

            clsTransferScreen:: ShowTransferScreen();
            cout << endl << endl ; 
            system("pause>0");
            
        }
        static void _ShowTransferListScreen(){
                
                clsTransferLogScreen:: ShowTransferLogScreen();
                cout << endl << endl ; 
                system("pause>0");
        }
                
        
    
       static void _PerformTransactionsMenueOption (enTransactionsMenueOptions Option ){
           
           switch (Option){               
               
               case enTransactionsMenueOptions :: eDeposit :{
                   
                   system("cls");
                   _ShowDepositScreen();
                   _GoBackToTransActionMenue();
                   break ; 
               }
               
               case enTransactionsMenueOptions :: eWithdraw :{
                   
                   system("cls");
                   _ShowWithdrawScreen();
                   _GoBackToTransActionMenue();
                   break ;
               }
               case enTransactionsMenueOptions :: eShowTotalBalance :{
                   
                   system("cls");
                   _ShowTotalBalancesScreen();
                   _GoBackToTransActionMenue();
                   break ; 
               }
               case enTransactionsMenueOptions :: eShowTransfer :{
                   
                   system("cls");
                   _ShowTransferScreen();
                   _GoBackToTransActionMenue();
                   
               }
               
               case  enTransactionsMenueOptions :: eShowTransferList :{
                   
                   system("cls");
                   _ShowTransferListScreen();
                   _GoBackToTransActionMenue();
               }
               
               case enTransactionsMenueOptions :: eShowMainMenue :{
                   
    //                clsMainScreen :: ShowMainMenue() ;
//                    break ;  
               }
               
               
           }
           
       }
    
    public :
        
        static void ShowTransactionsMenue(){
            
            
            if (!CheckAccessRights(clsUser:: enPermissions:: pTranactions )){
            return;
        }
              
    //       _DrawScreenHeader(" Delete Client Screen");
            
            system("cls");
            _DrawScreenHeader(" Transactions Screen");
    
            cout << left << "" << "===========================================\n";
            cout << left << "" << "\t\t  Transactions Menue\n";
            cout << left << "" << "===========================================\n";
            cout  << left << "" << "\t[1] Deposit.\n";
            cout << left << "" << "\t[2] Withdraw.\n";
            cout  << left << "" << "\t[3] Total Balances.\n";
            cout << left << "" << "\t[4] Transfer.  \n";
            cout << left << "" << "\t[5] Transfer List.  \n";
            
            cout << left << "" << "\t[6] Main Menue.\n";
            cout << left << "" << "===========================================\n";
    
            _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
        }
        
        
        
    
};
