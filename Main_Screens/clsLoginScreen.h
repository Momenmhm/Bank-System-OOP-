#pragma once 
#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "clsUser.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"

class clsLoginScreen : protected clsScreen {
    
    private : 
        
        
        
        
        static bool _Login(){
            
            string UserName = ""; 
            string Password = ""; 
            bool LoginFalid = false ; 
            short FalidCounter = 2 ; 
            do {
                
                if ( LoginFalid ){
                    
                    if (FalidCounter == 0 ){
                        cout <<"\n your have Locked ! Try Again Later ."; 
                        return false ; 
                    }
                    else {
                        cout <<"\n Invalid User Name/ Password!  you have [ " << FalidCounter << " ] more trail(s) . " ; 
                        FalidCounter-- ; 
                    }
                }
                
                cout <<"\n Enter user name : "; 
                UserName = clsInputValidate :: ReadString(); 
                
                cout << "\n Enter User Password : "; 
                Password = clsInputValidate :: ReadString(); 
                
                CurrentUser = clsUser :: Find(UserName , Password); 
                
                LoginFalid =  CurrentUser.IsEmpty();
                
            } while( LoginFalid );
            
            CurrentUser.SaveLogRegisterToFile();
            clsMainScreen :: ShowMainMenue ();
            return true ; 
        }
        
        
    public : 
        
        
        static bool ShowLoginScreen(){
            
            system ("cls");
            _DrawScreenHeader(" Login Screen "); 
            return _Login();
            
        }
    
    
};
