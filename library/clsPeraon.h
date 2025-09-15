#pragma once 
#include <iostream>

using namespace std ;

class clsPerson {
    
    protected: 
        
        string _first_name ;
        string _last_name ; 
        string _email ;
        string _phone ; 
    
    public :        
       static short counter; 
        clsPerson (string fname , string lname , string email  , string phone ){
            
            _first_name = fname ; 
            _last_name = lname ; 
            _email = email ;
            _phone = phone ;
            counter ++ ;
        }
        string Full_Name (){
            
            return _first_name + " " + _last_name  ;
        }
        void FirstName (string fname ){
            
            _first_name = fname ;
        }
        string GetFirstName (){
            
            return _first_name ;
        }
        
        void SetLastName (string lname ){
            
            _last_name = lname ;
        }
        string GetLastName (){
            
            return _last_name ;
        }
        
        void SetEmail (string email ){
            
            _email= email ;
        }
        string GetEmail(){
            
            return _email ;
        }
        
        void SetPhone (string phone ){
            
            _phone = phone ;
        }
        string GetPhone(){
            
            return _phone ;
        }
        
        
        void Print (){
            
            cout <<" \n_____________________________\n";
            cout <<" \n first name : "<< _first_name ;
            cout <<" \n last name  : "<< _last_name ;
            cout <<" \n full name  : "<< Full_Name () ; 
            cout <<" \n email      : "<< _email ;
            cout <<" \n phone      : "<< _phone ;            
            cout <<" \n_____________________________\n";
                        
        }
               
        void SendEmail (string sub , string body ){
            
            cout <<"\n the following massage will send to email : " << _email << endl;
            cout << " subject  : "<< sub << endl ; 
            cout << " body  : "<< body << endl ;   
            
        }
        
        void SendSMS (string msg){
            
            cout <<"\n the following sms send to phone : " << _phone << endl ; 
            
            cout << msg << endl ;
             
        }
        
};
short clsPerson :: counter = 0 ; 
