#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std ; 

class clsUpdateCurrencyScreen : protected clsScreen {
    
    private :
        
        
        
        
    public : 
        
        static void ShowUpdateCurrencyScreen(){
            
            system ("cls");
            _DrawScreenHeader("    Find Currency Screen ");
            
            cout <<" \n enter currncy code : ";
            
            string Code = clsInputValidate:: ReadString (); 
            clsCurrency C = clsCurrency:: FindByCode(Code);
            
            if (!C.IsEmpty()){
                
                cout <<"\n Currency found :-) " ; 
                C.Print(); 
                
                cout <<"\n Are you sure to update the Currency Rate ? (y/n) : " ; 
                char answer = 'n' ;                
                cin >> answer ; 
                
                if (answer == 'y' || answer == 'Y'){
                    
                    cout <<"\n Enter New Currency Rate :  "; 
                    float CurrencyRate = clsInputValidate:: ReadFloatNumber ();
                    
                    C.SetRate(CurrencyRate) ; 
                    C.Print();
                    return ;
                }
                else return ; 
                
                
            }
            cout <<"\n Currency not found :-( " ; 
            
     }
        
        
    
};
