#pragma once 
#include <iostream>
#include "Global.h"
#include "clsUtil.h"
#include <iomanip>
#include  "clsString.h" 
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsLoginRegisterScreen : protected clsScreen {
    
    private : 
        
        static void PrintListHeader (vector<string> vLogUsers ){
            
            cout << "\n\t\t             Login Regester  ";//(" << vLogUsers.size() << ")Log User(s).";
            cout << "\n_______________________________________";
            cout << "_________________________________________\n" << endl;
        
            cout << "| " << left << setw(25) << "Date/Time";
            cout << "| " << left << setw(20) << "User Name";
            cout << "| " << left << setw(15) << "Password";
            cout << "| " << left << setw(15) << "Permissions|" ;
            cout << "\n______________________________________________";
            cout << "__________________________________\n" << endl;
                        
        }       
        
        static void _PrintLoginUserLine (vector<string> vLogUsers ){
            
             cout << left << "" << "| " << setw(25) << left << vLogUsers[0];
            cout << "| " << setw(20) << left << vLogUsers[1];
            cout << "| " << setw(15) << left << clsUtil:: DecryptText (vLogUsers[2], 11) ;
            cout << "| " << setw(11) << left << vLogUsers[3] << "|";
                      
        }
                
    public : 
        
        static void  ShowLoginRegisterScreen (){
            
            if (!CheckAccessRights(clsUser::enPermissions:: pLogRegister )){
            return;
        }
            
            _DrawScreenHeader(" Login Regester Screen "); 
                                    
           fstream MyFile ;
           MyFile.open("/storage/emulated/0/LogFile.txt" , ios :: in );
           
           if(MyFile. is_open()){
               
               vector<string> vLogUsers ; 
               string DataLine ="";
               PrintListHeader(vLogUsers);
               while (getline (MyFile , DataLine )){
                   
                   vLogUsers = clsString:: split(DataLine);
                   _PrintLoginUserLine(vLogUsers ); 
                   cout << endl ; 
                   
               }
               cout << "\n______________________________________________";
               cout << "__________________________________\n" << endl;
                        
           }
           MyFile.close();
           
        }    
    
};
