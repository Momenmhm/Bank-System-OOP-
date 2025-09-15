#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsUtil.h"
#include "clsDate.h"
#include "clsString.h"
#include "clsInputValidate.h"

const string FilePath = "/storage/emulated/0/Clients.txt" ; 

class clsBankClient : public clsPerson {
    
    private : 
    // empty mode that mean the object is empty 
        enum enMode { EmptyMode = 0 , UpdateMode = 1 , AddNewMode = 2 } ; 
        
        enMode _Mode ;
        string _AccountNumber ; 
        string _PinCode ;
        double _AccountBalance ; 
        bool _IsMarkForDelete = false ; 
        
        static clsBankClient _ConvertLineToClientObject ( string line , string separator = "#//#" ){
            
            vector<string> vClientData ; 
            vClientData = clsString :: split(line , separator); 
            
            return clsBankClient(enMode:: UpdateMode , vClientData[0] ,vClientData[1] , vClientData[2] , vClientData[3] , vClientData[4] , clsUtil:: DecryptText (vClientData[5],11) ,stod( vClientData[6])) ; 
            
        }
        
        static clsBankClient _GetEmptyClientObject(){
            
            return clsBankClient(enMode :: EmptyMode , "" , "" , "" , "" , "" , "" , 0) ; 
            
        } 
        
        
        static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

            string stClientRecord = "";
            stClientRecord += Client.GetFirstName() + Seperator;
            stClientRecord += Client.GetLastName() + Seperator;
            stClientRecord += Client.GetEmail() + Seperator;
            stClientRecord += Client.GetPhone() + Seperator;
            stClientRecord += Client.AccountNumber() + Seperator;
            stClientRecord += clsUtil :: encyptText ( Client.PinCode() ,11 ) + Seperator;
            stClientRecord += to_string(Client.AccountBalance());
    
            return stClientRecord;
    
        }
    
        
        
        void _SaveClientsDataToFile(vector<clsBankClient>& vClients){
            
            fstream MyFile ;
            MyFile.open(FilePath, ios :: out );
            
            if (MyFile.is_open()){
                
                string LineData ; 
                for ( clsBankClient& C : vClients ){
                    
                    if (!(C.MarkForDelete())){
                        
                    LineData = _ConverClientObjectToLine(C) ; 
                    
                    MyFile << LineData << endl ; 
                    }
                }
                MyFile.close() ;
            }            
        }
        
       static vector<clsBankClient> _LoadClientsDataFromFile(){
            
            vector<clsBankClient> vClients ;
            fstream MyFile ; 
            MyFile.open(FilePath , ios :: in ) ;
            
            if (MyFile.is_open()){
                string Line ; 
                while (getline(MyFile , Line )){
                    
                    vClients.push_back( _ConvertLineToClientObject(Line) ) ;
                    
                }
            }
            MyFile.close() ;
            return vClients ;            
        }
       void _AddDataLineToFile(string stDataLine){
                                
                fstream MyFile;
                MyFile.open( FilePath, ios::out | ios::app);
        
                if (MyFile.is_open()) {
                            
                    MyFile << stDataLine << endl;        
                    MyFile.close();
                }                        
       }
       
       void _AddNew (){       
            _AddDataLineToFile(_ConverClientObjectToLine(*this));
       }
        
        void _Update(){
            
            vector<clsBankClient> vClients ; 
            vClients = _LoadClientsDataFromFile();
            
            for (clsBankClient& C : vClients ){
                
                if (C.AccountNumber() == AccountNumber () ){
                    
                    C = (*this) ; 
                    break ; 
                }
                
            }
            _SaveClientsDataToFile( vClients ) ; 
        }
         
        string ConectionClientData (clsBankClient ToClient , double Amount , string UserName ,   string separator = "#//#"){
            
             string ClientData = "" ; 
             
              ClientData += clsDate :: GetCurrentDateTime()  + separator ; 
              ClientData += this->_AccountNumber + separator ;
              ClientData += ToClient.AccountNumber() + separator ;
              ClientData += to_string(Amount) + separator ;  
              ClientData += to_string(this-> _AccountBalance) + separator ; 
              ClientData += to_string(ToClient.AccountBalance())+ separator ; 
              ClientData += UserName ; 
              
              return ClientData ;
       } 
       
       void SaveTransferLogToFile(clsBankClient ToClient , double Amount , string UserName ){
            
            fstream MyFile ; 

            string DataLine = ConectionClientData(ToClient , Amount , UserName ) ; 
            
            MyFile.open("/storage/emulated/0/TransfersLog.txt" , ios :: out | ios :: app );
            
            if (MyFile.is_open()){
                
                MyFile << DataLine << endl; 
                
            }
            MyFile.close();
            
        }
        
 //   struct stTrnsferLogRecord;

    

        
        
        string _PrepareTransferLogRecord(float Amount,clsBankClient DestinationClient, string UserName, string Seperator = "#//#"){
            
            string TransferLogRecord = "";
            TransferLogRecord += clsDate:: GetCurrentDateTime() + Seperator;
            TransferLogRecord += AccountNumber() + Seperator;
            TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
            TransferLogRecord += to_string(Amount) + Seperator;
            TransferLogRecord += to_string(_AccountBalance) + Seperator;
            TransferLogRecord += to_string(DestinationClient.AccountBalance()) + Seperator;
            TransferLogRecord += UserName;
            return TransferLogRecord;
       }
       

    public : 
    
        struct stTrnsferLogRecord{
            
            string DateTime;
            string SourceAccountNumber;
            string DestinationAccountNumber;
            float Amount;
            float srcBalanceAfter;
            float destBalanceAfter;
            string UserName;
    
        };
    
        clsBankClient (enMode Mode , string
 FirstName , string LastName , string Email , string Phone , string AccountNumber , string PinCode , float AccountBalance ) : 
        clsPerson (FirstName , LastName , Email , Phone ){
            
            _Mode = Mode ;
            _AccountNumber = AccountNumber ; 
            _PinCode = PinCode ; 
            _AccountBalance = AccountBalance ; 
            
        }        
        
        
        static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#"){
        
            stTrnsferLogRecord TrnsferLogRecord;
    
            vector <string> vTrnsferLogRecordLine = clsString:: split(Line, Seperator);
            TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
            TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
            TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
            TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
            TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
            TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
            TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];
    
            return TrnsferLogRecord;

        }
        
        
        bool IsEmpty (){
            
            return (*this)._Mode == enMode :: EmptyMode ; 
        }
        
        string AccountNumber (){
            
            return _AccountNumber ; 
        }
        
        void SetPinCode (string PinCode ){
            
            this->_PinCode = PinCode ; 
        }
        
        string PinCode() {
            
            return  _PinCode ; 
        }
        
        void SetAccountBalance (float AccountBalance ){
            
            this->_AccountBalance = AccountBalance ; 
        }
        
        double AccountBalance (){
            
            return _AccountBalance ;
        }
        bool MarkForDelete (){
            
            return _IsMarkForDelete ; 
        }
        
        
        static clsBankClient Find ( string AccountNumber ) {
            
            
       fstream MyFile;
        MyFile.open(FilePath, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }              
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();

        }
        
        
        bool Transfer (double Amount , clsBankClient & ToClient , string UserName ){
            
            if (Amount > this->_AccountBalance ){
                return false ; 
            }
            Withdraw (Amount); 
            ToClient.Deposit(Amount) ; 
            
            SaveTransferLogToFile (ToClient , Amount , UserName ) ;
            return true ; 
            
        }
        
        static clsBankClient Find ( string AccountNumber , string PinCode ) {
                        
            fstream MyFile ; 

            MyFile.open(FilePath , ios :: in) ; 
            
            if (MyFile.is_open()){
                
                string Line ; 
                
                
                while (getline(MyFile , Line)){
                    
                    clsBankClient Client = _ConvertLineToClientObject(Line) ; 
                    if ( Client.AccountNumber() == AccountNumber && Client.PinCode() == PinCode) {
                        
                        MyFile.close();
                        return Client ; 
                    }                    
                }                
                
            }
            MyFile.close(); 
            
            return _GetEmptyClientObject();
        }
                        
        
       static bool IsClientExist(string AccountNumber){
           
           clsBankClient c1 = clsBankClient :: Find(AccountNumber);
           
           return !(c1.IsEmpty());
                      
       }
       
       bool Delete (){
           
            vector <clsBankClient> _vClients;
            _vClients = _LoadClientsDataFromFile();
    
            for (clsBankClient& C : _vClients)
            {
                if (C.AccountNumber() == _AccountNumber)
                {
                    C._IsMarkForDelete = true;
                    break;
                }   
            }
    
            _SaveClientsDataToFile(_vClients);
    
            *this = _GetEmptyClientObject();
    
            return true; 

       }
       
       static clsBankClient GetAddNewClientObject(string AccountNumber){
        
            return clsBankClient (enMode:: AddNewMode , "" , "" , "" , "" , AccountNumber , "" , 0 ) ; 
       }
        
        enum enSaveResults { svFaildEmptyObject = 0 , svSucceeded = 1 , svFaildAccountNumberExists = 2 } ;
        
        enSaveResults Save (){
            
            switch ( _Mode ){
                
                case enMode:: EmptyMode : {
                    
                    return enSaveResults :: svFaildEmptyObject ; 
                }
                
                case enMode :: UpdateMode  :{
                              
                      _Update() ; 
                      return enSaveResults ::svSucceeded ;
                } 
                case enMode :: AddNewMode :{
                    
                      if(clsBankClient:: IsClientExist(_AccountNumber)){
                          
                          return enSaveResults :: svFaildAccountNumberExists ; 
                          
                      }
                      else {
                          
                          _AddNew();
                          _Mode = enMode :: UpdateMode ;
                           
                          return enSaveResults :: svSucceeded ; 
                                                    
                      } 
                }         
            }            
        }
        
        static vector<clsBankClient> ClientsList (){
                
                return _LoadClientsDataFromFile(); 
        }
        
        static double GetTotalBalances (){
                
                vector<clsBankClient> vClients = _LoadClientsDataFromFile() ;
                double TotalBalance = 0 ; 
                 for (const clsBankClient & C : vClients ){
                     
                      TotalBalance += C._AccountBalance ; 
                 } 
                 return TotalBalance ; 
        }
        void Deposit (double amount){
                
                _AccountBalance += amount ;
                Save();
        }
       
        bool Withdraw (double amount){
            
            if (amount > _AccountBalance ){
                  
                  return false ;
            }
            else {
              _AccountBalance -= amount ;    
              Save();    
              return true ;
              }        
         } 
           
           
          static  vector <stTrnsferLogRecord> GetTransfersLogList(){
              
            vector <stTrnsferLogRecord> vTransferLogRecord;
    
            fstream MyFile;
            MyFile.open("/storage/emulated/0/TransfersLog.txt", ios::in);//read Mode
    
            if (MyFile.is_open()){
    
                string Line;
    
                stTrnsferLogRecord TransferRecord;
    
                while (getline(MyFile, Line)){
    
                    TransferRecord = _ConvertTransferLogLineToRecord(Line);
    
                    vTransferLogRecord.push_back(TransferRecord);
    
                }
    
                MyFile.close();
    
            }
    
            return vTransferLogRecord;

        }

         
        
        void Print() {
            
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirst Name   : " << GetFirstName();
            cout << "\nLast Name    : " << GetLastName();
            cout << "\nFull Name   : " << Full_Name();
            cout << "\nEmail       : " << GetEmail();
            cout << "\nPhone       : " << GetPhone();
            cout << "\nAcc. Number : " << _AccountNumber;
            cout << "\nPassword    : " << _PinCode;
            cout << "\nBalance     : " << _AccountBalance;
            cout << "\n___________________\n";
    
        }
};


//  some additional function  *********
void ReadClientInfo(clsBankClient& Client){
       
        cout << "\nEnter First Name: ";
        Client.FirstName( clsInputValidate::ReadString());
    
        cout << "\nEnter Last Name: ";
        Client.SetLastName( clsInputValidate::ReadString());
    
        cout << "\nEnter Email: ";
        Client.SetEmail( clsInputValidate::ReadString());
    
        cout << "\nEnter Phone: ";
        Client.SetPhone( clsInputValidate::ReadString());
    
        cout << "\nEnter PinCode: ";
        Client.SetPinCode( clsInputValidate::ReadString());
    
        cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance( clsInputValidate::ReadFloatNumber());
}

void UpdateClient (){
    
    string AccountNumber = "" ; 
    
    cout << "\n enter the account number to update : " ;
    AccountNumber=clsInputValidate::ReadString();
    while (! clsBankClient :: IsClientExist (AccountNumber) ){
        
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
                
    }
    clsBankClient client = clsBankClient:: Find(AccountNumber) ; 
    client.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";    
    
    ReadClientInfo(client );
    
    clsBankClient :: enSaveResults SaveResult ; 
    
    SaveResult = client.Save() ;
    
    switch (SaveResult){
        
        case clsBankClient :: enSaveResults ::  svFaildEmptyObject : {
            
            cout <<"\n Error happened ! , client not updated because it's empty \n";
            break ; 
        }
        case clsBankClient :: enSaveResults ::  svSucceeded :{
            
            cout <<"\n client updated successfully! \n" ;
            client.Print();
        }
    }
    
}

void AddNewClient (){
        
    string AccountNumber = "" ; 
    
    cout << "\n enter account number : " ; 
    
    AccountNumber = clsInputValidate  :: ReadString() ; 
    
    while (clsBankClient:: IsClientExist (AccountNumber )){
        
        cout <<"\n Account number is already used , please choose another one : " ; 
        AccountNumber = clsInputValidate :: ReadString() ; 
        
    }
    clsBankClient NewClient = clsBankClient :: GetAddNewClientObject (AccountNumber ) ;
     
    ReadClientInfo(NewClient ); 
    
    clsBankClient :: enSaveResults SaveResult ; 
    
    SaveResult = NewClient.Save(); 
    
    switch (SaveResult){
        
        case clsBankClient :: enSaveResults :: svSucceeded : {
            
              cout << "\nAccount Addeded Successfully :-)\n";
             NewClient.Print();
             break;
        }
        case clsBankClient :: enSaveResults :: svFaildEmptyObject:{
            
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case  clsBankClient :: enSaveResults :: svFaildAccountNumberExists: {
            
        cout << "\nError account was not saved because account number is used!\n";
        break;
        }                   
    }       
}
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsUtil.h"
#include "clsDate.h"
#include "clsString.h"
#include "clsInputValidate.h"

const string FilePath = "/storage/emulated/0/Clients.txt" ; 

class clsBankClient : public clsPerson {
    
    private : 
    // empty mode that mean the object is empty 
        enum enMode { EmptyMode = 0 , UpdateMode = 1 , AddNewMode = 2 } ; 
        
        enMode _Mode ;
        string _AccountNumber ; 
        string _PinCode ;
        double _AccountBalance ; 
        bool _IsMarkForDelete = false ; 
        
        static clsBankClient _ConvertLineToClientObject ( string line , string separator = "#//#" ){
            
            vector<string> vClientData ; 
            vClientData = clsString :: split(line , separator); 
            
            return clsBankClient(enMode:: UpdateMode , vClientData[0] ,vClientData[1] , vClientData[2] , vClientData[3] , vClientData[4] , clsUtil:: DecryptText (vClientData[5],11) ,stod( vClientData[6])) ; 
            
        }
        
        static clsBankClient _GetEmptyClientObject(){
            
            return clsBankClient(enMode :: EmptyMode , "" , "" , "" , "" , "" , "" , 0) ; 
            
        } 
        
        
        static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

            string stClientRecord = "";
            stClientRecord += Client.GetFirstName() + Seperator;
            stClientRecord += Client.GetLastName() + Seperator;
            stClientRecord += Client.GetEmail() + Seperator;
            stClientRecord += Client.GetPhone() + Seperator;
            stClientRecord += Client.AccountNumber() + Seperator;
            stClientRecord += clsUtil :: encyptText ( Client.PinCode() ,11 ) + Seperator;
            stClientRecord += to_string(Client.AccountBalance());
    
            return stClientRecord;
    
        }
    
        
        
        void _SaveClientsDataToFile(vector<clsBankClient>& vClients){
            
            fstream MyFile ;
            MyFile.open(FilePath, ios :: out );
            
            if (MyFile.is_open()){
                
                string LineData ; 
                for ( clsBankClient& C : vClients ){
                    
                    if (!(C.MarkForDelete())){
                        
                    LineData = _ConverClientObjectToLine(C) ; 
                    
                    MyFile << LineData << endl ; 
                    }
                }
                MyFile.close() ;
            }            
        }
        
       static vector<clsBankClient> _LoadClientsDataFromFile(){
            
            vector<clsBankClient> vClients ;
            fstream MyFile ; 
            MyFile.open(FilePath , ios :: in ) ;
            
            if (MyFile.is_open()){
                string Line ; 
                while (getline(MyFile , Line )){
                    
                    vClients.push_back( _ConvertLineToClientObject(Line) ) ;
                    
                }
            }
            MyFile.close() ;
            return vClients ;            
        }
       void _AddDataLineToFile(string stDataLine){
                                
                fstream MyFile;
                MyFile.open( FilePath, ios::out | ios::app);
        
                if (MyFile.is_open()) {
                            
                    MyFile << stDataLine << endl;        
                    MyFile.close();
                }                        
       }
       
       void _AddNew (){       
            _AddDataLineToFile(_ConverClientObjectToLine(*this));
       }
        
        void _Update(){
            
            vector<clsBankClient> vClients ; 
            vClients = _LoadClientsDataFromFile();
            
            for (clsBankClient& C : vClients ){
                
                if (C.AccountNumber() == AccountNumber () ){
                    
                    C = (*this) ; 
                    break ; 
                }
                
            }
            _SaveClientsDataToFile( vClients ) ; 
        }
         
        string ConectionClientData (clsBankClient ToClient , double Amount , string UserName ,   string separator = "#//#"){
            
             string ClientData = "" ; 
             
              ClientData += clsDate :: GetCurrentDateTime()  + separator ; 
              ClientData += this->_AccountNumber + separator ;
              ClientData += ToClient.AccountNumber() + separator ;
              ClientData += to_string(Amount) + separator ;  
              ClientData += to_string(this-> _AccountBalance) + separator ; 
              ClientData += to_string(ToClient.AccountBalance())+ separator ; 
              ClientData += UserName ; 
              
              return ClientData ;
       } 
       
       void SaveTransferLogToFile(clsBankClient ToClient , double Amount , string UserName ){
            
            fstream MyFile ; 

            string DataLine = ConectionClientData(ToClient , Amount , UserName ) ; 
            
            MyFile.open("/storage/emulated/0/TransfersLog.txt" , ios :: out | ios :: app );
            
            if (MyFile.is_open()){
                
                MyFile << DataLine << endl; 
                
            }
            MyFile.close();
            
        }
        
 //   struct stTrnsferLogRecord;

    

        
        
        string _PrepareTransferLogRecord(float Amount,clsBankClient DestinationClient, string UserName, string Seperator = "#//#"){
            
            string TransferLogRecord = "";
            TransferLogRecord += clsDate:: GetCurrentDateTime() + Seperator;
            TransferLogRecord += AccountNumber() + Seperator;
            TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
            TransferLogRecord += to_string(Amount) + Seperator;
            TransferLogRecord += to_string(_AccountBalance) + Seperator;
            TransferLogRecord += to_string(DestinationClient.AccountBalance()) + Seperator;
            TransferLogRecord += UserName;
            return TransferLogRecord;
       }
       

    public : 
    
        struct stTrnsferLogRecord{
            
            string DateTime;
            string SourceAccountNumber;
            string DestinationAccountNumber;
            float Amount;
            float srcBalanceAfter;
            float destBalanceAfter;
            string UserName;
    
        };
    
        clsBankClient (enMode Mode , string
 FirstName , string LastName , string Email , string Phone , string AccountNumber , string PinCode , float AccountBalance ) : 
        clsPerson (FirstName , LastName , Email , Phone ){
            
            _Mode = Mode ;
            _AccountNumber = AccountNumber ; 
            _PinCode = PinCode ; 
            _AccountBalance = AccountBalance ; 
            
        }        
        
        
        static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#"){
        
            stTrnsferLogRecord TrnsferLogRecord;
    
            vector <string> vTrnsferLogRecordLine = clsString:: split(Line, Seperator);
            TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
            TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
            TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
            TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
            TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
            TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
            TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];
    
            return TrnsferLogRecord;

        }
        
        
        bool IsEmpty (){
            
            return (*this)._Mode == enMode :: EmptyMode ; 
        }
        
        string AccountNumber (){
            
            return _AccountNumber ; 
        }
        
        void SetPinCode (string PinCode ){
            
            this->_PinCode = PinCode ; 
        }
        
        string PinCode() {
            
            return  _PinCode ; 
        }
        
        void SetAccountBalance (float AccountBalance ){
            
            this->_AccountBalance = AccountBalance ; 
        }
        
        double AccountBalance (){
            
            return _AccountBalance ;
        }
        bool MarkForDelete (){
            
            return _IsMarkForDelete ; 
        }
        
        
        static clsBankClient Find ( string AccountNumber ) {
            
            
       fstream MyFile;
        MyFile.open(FilePath, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }              
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();

        }
        
        
        bool Transfer (double Amount , clsBankClient & ToClient , string UserName ){
            
            if (Amount > this->_AccountBalance ){
                return false ; 
            }
            Withdraw (Amount); 
            ToClient.Deposit(Amount) ; 
            
            SaveTransferLogToFile (ToClient , Amount , UserName ) ;
            return true ; 
            
        }
        
        static clsBankClient Find ( string AccountNumber , string PinCode ) {
                        
            fstream MyFile ; 

            MyFile.open(FilePath , ios :: in) ; 
            
            if (MyFile.is_open()){
                
                string Line ; 
                
                
                while (getline(MyFile , Line)){
                    
                    clsBankClient Client = _ConvertLineToClientObject(Line) ; 
                    if ( Client.AccountNumber() == AccountNumber && Client.PinCode() == PinCode) {
                        
                        MyFile.close();
                        return Client ; 
                    }                    
                }                
                
            }
            MyFile.close(); 
            
            return _GetEmptyClientObject();
        }
                        
        
       static bool IsClientExist(string AccountNumber){
           
           clsBankClient c1 = clsBankClient :: Find(AccountNumber);
           
           return !(c1.IsEmpty());
                      
       }
       
       bool Delete (){
           
            vector <clsBankClient> _vClients;
            _vClients = _LoadClientsDataFromFile();
    
            for (clsBankClient& C : _vClients)
            {
                if (C.AccountNumber() == _AccountNumber)
                {
                    C._IsMarkForDelete = true;
                    break;
                }   
            }
    
            _SaveClientsDataToFile(_vClients);
    
            *this = _GetEmptyClientObject();
    
            return true; 

       }
       
       static clsBankClient GetAddNewClientObject(string AccountNumber){
        
            return clsBankClient (enMode:: AddNewMode , "" , "" , "" , "" , AccountNumber , "" , 0 ) ; 
       }
        
        enum enSaveResults { svFaildEmptyObject = 0 , svSucceeded = 1 , svFaildAccountNumberExists = 2 } ;
        
        enSaveResults Save (){
            
            switch ( _Mode ){
                
                case enMode:: EmptyMode : {
                    
                    return enSaveResults :: svFaildEmptyObject ; 
                }
                
                case enMode :: UpdateMode  :{
                              
                      _Update() ; 
                      return enSaveResults ::svSucceeded ;
                } 
                case enMode :: AddNewMode :{
                    
                      if(clsBankClient:: IsClientExist(_AccountNumber)){
                          
                          return enSaveResults :: svFaildAccountNumberExists ; 
                          
                      }
                      else {
                          
                          _AddNew();
                          _Mode = enMode :: UpdateMode ;
                           
                          return enSaveResults :: svSucceeded ; 
                                                    
                      } 
                }         
            }            
        }
        
        static vector<clsBankClient> ClientsList (){
                
                return _LoadClientsDataFromFile(); 
        }
        
        static double GetTotalBalances (){
                
                vector<clsBankClient> vClients = _LoadClientsDataFromFile() ;
                double TotalBalance = 0 ; 
                 for (const clsBankClient & C : vClients ){
                     
                      TotalBalance += C._AccountBalance ; 
                 } 
                 return TotalBalance ; 
        }
        void Deposit (double amount){
                
                _AccountBalance += amount ;
                Save();
        }
       
        bool Withdraw (double amount){
            
            if (amount > _AccountBalance ){
                  
                  return false ;
            }
            else {
              _AccountBalance -= amount ;    
              Save();    
              return true ;
              }        
         } 
           
           
          static  vector <stTrnsferLogRecord> GetTransfersLogList(){
              
            vector <stTrnsferLogRecord> vTransferLogRecord;
    
            fstream MyFile;
            MyFile.open("/storage/emulated/0/TransfersLog.txt", ios::in);//read Mode
    
            if (MyFile.is_open()){
    
                string Line;
    
                stTrnsferLogRecord TransferRecord;
    
                while (getline(MyFile, Line)){
    
                    TransferRecord = _ConvertTransferLogLineToRecord(Line);
    
                    vTransferLogRecord.push_back(TransferRecord);
    
                }
    
                MyFile.close();
    
            }
    
            return vTransferLogRecord;

        }

         
        
        void Print() {
            
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirst Name   : " << GetFirstName();
            cout << "\nLast Name    : " << GetLastName();
            cout << "\nFull Name   : " << Full_Name();
            cout << "\nEmail       : " << GetEmail();
            cout << "\nPhone       : " << GetPhone();
            cout << "\nAcc. Number : " << _AccountNumber;
            cout << "\nPassword    : " << _PinCode;
            cout << "\nBalance     : " << _AccountBalance;
            cout << "\n___________________\n";
    
        }
};

void ReadClientInfo(clsBankClient& Client){
       
        cout << "\nEnter First Name: ";
        Client.FirstName( clsInputValidate::ReadString());
    
        cout << "\nEnter Last Name: ";
        Client.SetLastName( clsInputValidate::ReadString());
    
        cout << "\nEnter Email: ";
        Client.SetEmail( clsInputValidate::ReadString());
    
        cout << "\nEnter Phone: ";
        Client.SetPhone( clsInputValidate::ReadString());
    
        cout << "\nEnter PinCode: ";
        Client.SetPinCode( clsInputValidate::ReadString());
    
        cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance( clsInputValidate::ReadFloatNumber());
}

void UpdateClient (){
    
    string AccountNumber = "" ; 
    
    cout << "\n enter the account number to update : " ;
    AccountNumber=clsInputValidate::ReadString();
    while (! clsBankClient :: IsClientExist (AccountNumber) ){
        
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
                
    }
    clsBankClient client = clsBankClient:: Find(AccountNumber) ; 
    client.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";    
    
    ReadClientInfo(client );
    
    clsBankClient :: enSaveResults SaveResult ; 
    
    SaveResult = client.Save() ;
    
    switch (SaveResult){
        
        case clsBankClient :: enSaveResults ::  svFaildEmptyObject : {
            
            cout <<"\n Error happened ! , client not updated because it's empty \n";
            break ; 
        }
        case clsBankClient :: enSaveResults ::  svSucceeded :{
            
            cout <<"\n client updated successfully! \n" ;
            client.Print();
        }
    }
    
}

void AddNewClient (){
        
    string AccountNumber = "" ; 
    
    cout << "\n enter account number : " ; 
    
    AccountNumber = clsInputValidate  :: ReadString() ; 
    
    while (clsBankClient:: IsClientExist (AccountNumber )){
        
        cout <<"\n Account number is already used , please choose another one : " ; 
        AccountNumber = clsInputValidate :: ReadString() ; 
        
    }
    clsBankClient NewClient = clsBankClient :: GetAddNewClientObject (AccountNumber ) ;
     
    ReadClientInfo(NewClient ); 
    
    clsBankClient :: enSaveResults SaveResult ; 
    
    SaveResult = NewClient.Save(); 
    
    switch (SaveResult){
        
        case clsBankClient :: enSaveResults :: svSucceeded : {
            
              cout << "\nAccount Addeded Successfully :-)\n";
             NewClient.Print();
             break;
        }
        case clsBankClient :: enSaveResults :: svFaildEmptyObject:{
            
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case  clsBankClient :: enSaveResults :: svFaildAccountNumberExists: {
            
        cout << "\nError account was not saved because account number is used!\n";
        break;
        }                   
    }       
}

void DeleteClient (){
    
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient client = clsBankClient :: Find(AccountNumber); 
    client.Print(); 
    
    cout << "\n Are you sure to delete this client ? (y/n) ? "; 
    char answer = 'n' ; 
    cin >> answer ; 
    if (answer == 'y' || answer == 'Y'){
        
        if (client.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";

            client.Print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }    
}

void PrintClientRecordLine(clsBankClient Client){
    
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.Full_Name();
    cout << "| " << setw(12) << left << Client.GetPhone();
    cout << "| " << setw(20) << left << Client.GetEmail();
    cout << "| " << setw(10) << left << Client.PinCode();
    cout << "| " << setw(12)  << left <<  Client.AccountBalance();

}

void ShowClientsList (){
    
    
    vector <clsBankClient> vClients = clsBankClient :: ClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void PrintClientRecordBalanceLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.Full_Name();
    cout << "| " << setw(12) << left << Client.AccountBalance();

}


void ShowTotalBalances(){

    vector <clsBankClient> vClients = clsBankClient:: ClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
    cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
}Enter
void DeleteClient (){
    
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient client = clsBankClient :: Find(AccountNumber); 
    client.Print(); 
    
    cout << "\n Are you sure to delete this client ? (y/n) ? "; 
    char answer = 'n' ; 
    cin >> answer ; 
    if (answer == 'y' || answer == 'Y'){
        
        if (client.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";

            client.Print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }    
}

void PrintClientRecordLine(clsBankClient Client){
    
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.Full_Name();
    cout << "| " << setw(12) << left << Client.GetPhone();
    cout << "| " << setw(20) << left << Client.GetEmail();
    cout << "| " << setw(10) << left << Client.PinCode();
    cout << "| " << setw(12)  << left <<  Client.AccountBalance();

}

void ShowClientsList (){
    
    
    vector <clsBankClient> vClients = clsBankClient :: ClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
