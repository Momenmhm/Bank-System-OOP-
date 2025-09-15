#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen {
    
    private : 
        
        enum enFindOption { eCode = 1 , eCountry = 2 };
        
        static short _ReadFindMenueOption (){
            
            short Option = clsInputValidate:: ReadShortNumberBetween (1 , 2, "Please enter number between (1/2) : ") ; 
            
            return Option ; 
        }
        
        
        
    public :
        
        
        static void ShowFindCurrencyScreen(){
            
            _DrawScreenHeader("    Find Currency Screen ");
            
            cout <<"\n Find By :    [1].Code  or   [2].Country " ; 
            short Option = _ReadFindMenueOption() ;
            
            switch ((enFindOption) Option ){
                
                                                
                case enFindOption :: eCode :  {
                    
                    cout <<"\n enter the Currency Code : " ;
                    string Code = clsInputValidate:: ReadString (); 
                    
                    clsCurrency Currency = clsCurrency:: FindByCode (Code) ; 
                    
                    if (!Currency.IsEmpty()){                        
                        
                        cout <<"\n Currency found :-) \n" ; 
                       Currency.Print();            
                       return ; 
                    }
                    break ; 
                                        
                }
                                                
                case enFindOption :: eCountry : {
                    
                    cout <<"\n enter the Currency Country : " ;
                    string Country = clsInputValidate:: ReadString (); 
                    
                    clsCurrency Currency = clsCurrency:: FindByCountry (Country) ;
                    
                    if (!Currency.IsEmpty()){
                        
                        cout <<"\n Currency found :-) \n" ; 
                        Currency.Print();     
                        return ;        
                                      
                    }
                    break ;                     
                }
                
            } 
           cout <<"\n Currency not found !  ";         
                                     
        }    
    
};
