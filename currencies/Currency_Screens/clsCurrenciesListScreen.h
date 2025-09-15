#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
//#include "clsInputValidate.h"

using namespace std ;

class clsCurrenciesListScreen : protected clsScreen {
    
    
    private :
        
        static void PrintCurrencyRecordLine(clsCurrency Currency){

            cout  << left << "" << "| " << setw(30) << left << Currency.Country();
            cout << "| " <<setw(8)<<  left << Currency.CurrencyCode();
            cout << "| " << setw(45) << left << Currency.CurrencyName();
            cout << "| " << setw(10) << left << Currency.Rate();
    
        }
    
        static void PrintCurrenciesListHeader (){
            
             cout << left << "" << "\n_______________________________________________________";
            cout << "_______________________________________________\n" << endl;
    
            cout  << left << "" << "| " << left << setw(30) << "Country";
            cout << "| " << left << setw(8) << "Code";
            cout << "| " << left << setw(45) << "Name";
            cout << "| " << left << setw(10) << "Rate/(1$)";
            cout << setw(8) << left << "" << "\n_______________________________________________________";
            cout << "_______________________________________________\n" << endl;
                  
            } 
            
        
    public : 
        
        static void ShowCurrenciesListScreen(){
  
            vector <clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();
            string Title = "  Currencies List Screen";
            string SubTitle = "  \t\t\t (" + to_string(vCurrencys.size()) + ") Currency.";
    
            _DrawScreenHeader(Title, SubTitle);
            
            PrintCurrenciesListHeader();
            
            if (vCurrencys.size() == 0)
            cout << "\t\tNo Currencies Available In the System!";
        else{

            for (clsCurrency Currency : vCurrencys){
            
                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        }
        
        cout << setw(8) << left << "" << "\n_______________________________________________________";
        cout << "_______________________________________________\n" << endl;
            
        }
};
