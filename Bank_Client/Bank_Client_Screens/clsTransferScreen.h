#pragma once 
#include <iostream>
#include "Global.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsTransferScreen : protected  clsScreen {
    
    private :        
        
        static void PrintClientCard (clsBankClient Client){
            
            cout <<"\n Client Card : ";
            cout <<"\n________________________\n";
            cout <<" Name : " << Client.Full_Name();
            cout <<"\n acc number : "<< Client.AccountNumber();
            cout <<" \n acc Balance : "<< Client.AccountBalance(); 
            cout <<"\n________________________\n";
            
        }
        
        static string _ReadAccountNumber(bool IsFrom = true ){
            string AccountNumber = "" ;    

            do {
                
                if (IsFrom){
                    cout << "\n enter the account number you want to transfer from : " ;
                }
                else {
                    cout << "\n enter the account number you want to transfer to : " ;
                }
        
                AccountNumber = clsInputValidate :: ReadString ();
                                  
                } while (!(clsBankClient :: IsClientExist (AccountNumber)));
               
                
                return AccountNumber ;     
        }      
        
        
    public :
        
        static void ShowTransferScreen(){
            
            _DrawScreenHeader("  Transfer Screen "); 
            
             clsBankClient FromClient = clsBankClient :: Find (_ReadAccountNumber(true)) ; 
                                             
             
            PrintClientCard(FromClient) ;              
                     
            clsBankClient ToClient = clsBankClient :: Find (_ReadAccountNumber()) ; 
                      
            
            PrintClientCard(ToClient) ; 
            
            cout <<"\n\n enter the amount to transfer : ";
            double Amount = clsInputValidate:: ReadDblNumber (); 
            
            cout <<"\n Are you sure to complete the transfer action ? (y/n) : " ;
            char answer = 'n' ;
            cin >> answer ; 
            
            if (tolower(answer) != 'y'){
                cout <<"\nOperation was cancelled.\n" ; 
                return ; 
            }
            
            if ( FromClient.Transfer(Amount ,ToClient ,CurrentUser.UserName() ) ){
                             
                cout <<"\n  transfere done successfully... "; 
//                FromClient.SaveTransferLogToFile(ToClient , Amount , CurrentUser.UserName() );
                PrintClientCard(FromClient) ;         
                PrintClientCard(ToClient) ;         
            }
            else {
                
                cout <<"\n transfer Action Valid !\n     Client [ " << FromClient.Full_Name() <<" ] have not enough money to tranfer " ;  
                     
            }                        
            
        }
           
};
