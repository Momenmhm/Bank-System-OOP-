#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std ; 

class clsCurrencyCalculatorScreen : protected clsScreen {
    
     private :
         
         static string ReadCurrencyCode(){
             
             string Code ="" ; 
             bool Falid = false ; 
             do{
                 
                 if (Falid ){
                     
                     cout <<"\n Currency Code not found! enter again :  " ; 
                 }
                 
                 Code = clsInputValidate:: ReadString (); 
                                 
                 
             } while (!clsCurrency:: IsCurrencyExist (Code));
             
             return Code ; 
         }
         
         static float _ConvertCurrencies(float FromRate , float ToRate , float Amount ){
             
             return ((Amount/FromRate)* ToRate ); 
             
         }
         static void PrintCalculation (float Amount , clsCurrency Currency , float ToRate , string ToCode  ){
             
             cout << to_string(int(Amount)) << " " << Currency.CurrencyCode() << " = " << _ConvertCurrencies(Currency.Rate() , ToRate , Amount) << " " << ToCode  << endl ;
         }
         
         static void ConvertFromCurrencyToUSD(clsCurrency Currency , float Amount ){
             
             cout <<"\n convert from : " ; 
             Currency.Print() ; 
             
             PrintCalculation(Amount , Currency , 1 , "USD" ) ; 
             
         }
         
         static void ConvertFromCurrencyToAnother(clsCurrency Currency1 , clsCurrency Currency2 , float Amount){
             
             cout <<"\n convert from : " ; 
             Currency1.Print() ; 
             
             cout <<"\n\n convert from USD to : \n" ;
             Currency2.Print(); 
             PrintCalculation(Amount , Currency1 , Currency2.Rate(), Currency2.CurrencyCode())  ; 
                       
         }
                 
         
      public : 
          
          
          static void ShowCurrencyCalclatorScreen(){ 
              
            system ("cls");
            _DrawScreenHeader("    Find Currency Screen ");
            
            char answer = 'n' ; 
            do {
                
                cout <<"\n enter currency 1 code : " ; 
                clsCurrency Currency1 = clsCurrency:: FindByCode (ReadCurrencyCode()) ; 
                
                cout <<"\n enter currency 2 code : " ; 
                clsCurrency Currency2 = clsCurrency:: FindByCode (ReadCurrencyCode()) ; 
            
                cout <<"\n enter the Amount : " ; 
                float Amount = clsInputValidate:: ReadFloatNumber ();
                
                if (Currency2.CurrencyCode() == "USD" ){
                    
                    ConvertFromCurrencyToUSD( Currency1 , Amount); 
                    
                }
                else {
                    
                    ConvertFromCurrencyToAnother( Currency1 , Currency2 , Amount);
                    
                }
                
                cout <<"\n Do you want to preform another calculator ? (y/n) :  " ; 
                
                cin >> answer ; 
                system ("cls"); 
            }while( tolower(answer) =='y' ) ;
              
          }                
        
}; 
