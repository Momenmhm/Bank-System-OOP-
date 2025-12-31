#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include "clsString.h"
#include "clsCurrencyExchangeMainScreen.h"

using namespace std ; 

const string CurrencyFilePath = "Currencies.txt" ; 

class clsCurrency {
        
    private : 
        
        enum enMode { EmptyMode = 0 ,
                                     UpdateMode = 1 } ;
                                     
        enMode _Mode ; 
        string _Country;
    	string _CurrencyCode;
    	string _CurrencyName;
    	float _Rate;
    	
    	
    	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#"){
    	   
            vector<string> vCurrencyData;
            vCurrencyData = clsString:: split(Line, Seperator);
    
            return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
    
        }
        
        static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {

            string stCurrencyRecord = "";
            stCurrencyRecord += Currency.Country() + Seperator;
            stCurrencyRecord += Currency.CurrencyCode() + Seperator;
            stCurrencyRecord += Currency.CurrencyName() + Seperator;
            stCurrencyRecord += to_string(Currency.Rate());
           
            return stCurrencyRecord;
    
        }
        
        static  vector <clsCurrency> _LoadCurrencysDataFromFile(){

            vector <clsCurrency> vCurrencys;
    
            fstream MyFile;
            MyFile.open(CurrencyFilePath, ios::in);//read Mode
    
            if (MyFile.is_open()){
                
                string Line;
    
                while (getline(MyFile, Line)){
                
    
                    clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
    
                    vCurrencys.push_back(Currency);
                }
    
                MyFile.close();    
            }   
             
            return vCurrencys;
    
        }
        
        static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys){
    
            fstream MyFile;
            MyFile.open(CurrencyFilePath, ios::out);//overwrite
    
            string DataLine;
    
            if (MyFile.is_open()){
            
    
                for (clsCurrency C : vCurrencys){
                
                     DataLine = _ConverCurrencyObjectToLine(C);
                        MyFile << DataLine << endl;
                            
                }
    
                MyFile.close();    
            }
    
        }
        
        void _Update (){
            
            vector<clsCurrency> vCurrency = _LoadCurrencysDataFromFile ();
            
            for (clsCurrency & C : vCurrency ){
                
                if(C.CurrencyCode() == CurrencyCode ()){
                    
                    C = *this ; 
                    _SaveCurrencyDataToFile(vCurrency) ;
                    break ;
                }
            }
            
        }
        
        static clsCurrency _GetEmptyCurrencyObject (){
            
            return clsCurrency (enMode :: EmptyMode , "" , "" ,"" , 0 ) ; 
        }
        
    
    public : 
        
        clsCurrency ( enMode Mode , string Country , string CurrencyCode , string CurrencyName , float Rate ){
            
            _Mode = Mode ; 
            _Country = Country ; 
            _CurrencyCode = CurrencyCode ; 
            _CurrencyName = CurrencyName ; 
            _Rate = Rate ; 
            
        }
        
        string Country (){
            
            return _Country ; 
        }
        
        string CurrencyCode (){
            
            return _CurrencyCode ; 
        }
        
        string CurrencyName (){
            
            return _CurrencyName ;            
        }
        
        float Rate (){
            
            return _Rate ; 
            _Update();
        }
        
        void SetRate (float Rate ){
            
            _Rate = Rate ; 
            _Update() ; 
        }
        
        bool IsEmpty (){
            
            return (_Mode == enMode:: EmptyMode ) ; 
        }
        
        
        static clsCurrency FindByCode(string CurrencyCode){
            
            CurrencyCode =  clsString :: UpperAllString (CurrencyCode) ;
            
            fstream MyFile ; 
            MyFile.open(CurrencyFilePath , ios :: in) ; 
                
            if (MyFile.is_open()){
                
                string DataLine = "" ; 
                while (getline (MyFile , DataLine )){
                    
                    clsCurrency C = _ConvertLineToCurrencyObject(DataLine ) ; 
                    
                    if(C.CurrencyCode() == CurrencyCode){
                        
                        MyFile.close();
                        return C ; 
                    }
                    
                }
                MyFile.close();
                
            }
            return _GetEmptyCurrencyObject();
        }
        
        static clsCurrency FindByCountry(string Country){
            
            fstream MyFile ; 
            MyFile.open(CurrencyFilePath , ios :: in) ; 
                
            if (MyFile.is_open()){
                
                string DataLine = "" ; 
                while (getline (MyFile , DataLine )){
                    
                    clsCurrency C = _ConvertLineToCurrencyObject(DataLine ) ; 
                    
                    if(clsString :: UpperAllString(C.Country()) == clsString :: UpperAllString(Country)){
                        
                        MyFile.close();
                        return C ; 
                    }
                    
                }
                MyFile.close();
                
            }
            return _GetEmptyCurrencyObject();
            
        }
        
        
        static bool IsCurrencyExist (string CurrencyCode){
           
            clsCurrency C = clsCurrency::  FindByCode(CurrencyCode) ;
            
            return !(C.IsEmpty() ) ; 
            
        }
        
        static vector<clsCurrency> GetCurrenciesList(){
            
             return _LoadCurrencysDataFromFile();
              
       } 
       void Print(){
        
        cout <<"\n Currency card : " ; 
        cout <<"\n________________________\n" ; 
        cout <<"Country      : "<< Country();
        cout <<"\nCode     : "<< CurrencyCode();
        cout <<"\nName   : "<< CurrencyName (); 
        cout <<"\nRate(1$) =  : " << Rate(); 
        cout <<"\n________________________\n" ; 
        
       }
        
}; 
