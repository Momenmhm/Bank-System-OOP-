#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std ; 

class clsCurrencyExchangeMainScreen : protected clsScreen {
    
    private : 
    
        enum enCurrenciesMainMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3, eCurrencyCalculator = 4, eMainMenue = 5 };
        
        static short ReadCurrenciesMainMenueOptions() {
            
            cout << "Choose what do you want to do? [1 to 5]? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
            return Choice;
        }
        
        
        static void _GoBackToCurrenciesMenue(){
            
            cout << "\n\nPress any key to go back to Currencies Menue...\n\n";
            
            system("pause>0");
            ShowCurrenciesMenue();
        }
    
        static void _ShowCurrenciesListScreen(){
        

            clsCurrenciesListScreen:: ShowCurrenciesListScreen(); 
    
        }
    
        static void _ShowFindCurrencyScreen(){
        
            clsFindCurrencyScreen:: ShowFindCurrencyScreen();
    
        }
    
        static void _ShowUpdateCurrencyRateScreen(){
        
            clsUpdateCurrencyScreen:: ShowUpdateCurrencyScreen(); 
        }
    
        static void _ShowCurrencyCalculatorScreen(){
        
            clsCurrencyCalculatorScreen :: ShowCurrencyCalclatorScreen(); 
    
        }
        
        static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions){
            
            
            switch (CurrenciesMainMenueOptions){
                
                
                case enCurrenciesMainMenueOptions :: eListCurrencies :{
                    
                    system("cls");
                    _ShowCurrenciesListScreen();
                   _GoBackToCurrenciesMenue();
                    break ; 
                }
                
                case enCurrenciesMainMenueOptions::  eFindCurrency :{
                    
                    system("cls");
                    _ShowFindCurrencyScreen();
                    _GoBackToCurrenciesMenue();
                    break ; 
                }
                
                case enCurrenciesMainMenueOptions::  eUpdateCurrencyRate  :{
                    
                    system("cls");
                    _ShowUpdateCurrencyRateScreen();
                    _GoBackToCurrenciesMenue();
                    break ; 
                }
                
                case enCurrenciesMainMenueOptions:: eCurrencyCalculator   :{
                    
                    system("cls");
                    _ShowCurrencyCalculatorScreen();
                    _GoBackToCurrenciesMenue();
                    break ; 
                }
                
                case enCurrenciesMainMenueOptions::  eMainMenue  :{
                    
                    system("cls");
                    break ; 
                }                                                
            }            
        }
        
    
    public : 
        
        
        static void ShowCurrenciesMenue(){
            
            
            system("cls");
            _DrawScreenHeader("  Currancy Exhange Main Screen");
    
            cout << left << "" << "===========================================\n";
            cout << left << "" << "\t\t  Currency Exhange Menue\n";
            cout << left << "" << "===========================================\n";
            cout << left << "" << "\t[1] List Currencies.\n";
            cout << left << "" << "\t[2] Find Currency.\n";
            cout << left << "" << "\t[3] Update Rate.\n";
            cout << left << "" << "\t[4] Currency Calculator.\n";
            cout << left << "" << "\t[5] Main Menue.\n";
            cout << left << "" << "===========================================\n";
    
            _PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)ReadCurrenciesMainMenueOptions());
                
                
            }    
        
    
};
