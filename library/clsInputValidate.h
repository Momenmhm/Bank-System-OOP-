#pragma once 
#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std ; 

class clsInputValidate {
    
    public  : 
    
        static bool IsNumBetween( int n , int from , int to   ){
            
            if (from > to) {
                clsUtil :: swap (from , to); 
            }
            return n >= from && n <= to ; 
        }
        
        static bool IsNumBetween( short n , short from , short to  ){
            
              if (from > to) {
                clsUtil :: swap (from , to); 
            }
            
            return n >= from && n <= to ;  ; 
        }
        
        static bool IsNumBetween( float n , float from, float to  ){
              
              if (from > to) {
                clsUtil :: swap (from , to); 
            }
            return n >= from && n <= to ; 
        }
        
        static bool IsNumBetween( double n , double from , double to   ){
            
              if (from > to) {
                clsUtil :: swap (from , to); 
            }
            
            return n >= from && n <= to ;  
        }
        
        static bool IsDateBetween( clsDate Date , clsDate From , clsDate To   ){
            
            
            if ((clsDate:: IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) 
			&&
			(clsDate::IsDate1BeforDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
		  )
		{
			return true;
		}
		
		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate:: IsDate1EqualDate2(Date, To)) 
			&&
			(clsDate::IsDate1BeforDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
		   )
		{
			return true;
		}

		return false;
		
            
            
          //  return clsDate :: IsDateInPeriod(date , from , to )  ; 
}
        
        static int ReadIntNumber(string ErrorMessage="Invalid Number, Enter again\n"){
    		int Number;
    		while (!(cin >> Number)) {
    			cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			cout << ErrorMessage ;
    		}
    		return Number;
	  }
	  
	  static short ReadShortNumber(string ErrorMessage="Invalid Number, Enter again\n"){
    		short Number;
    		while (!(cin >> Number)) {
    			cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			cout << ErrorMessage ;
    		}
    		return Number;
	  }
	  
	  
	  static double ReadDblNumber(string ErrorMessage="Invalid Number, Enter again\n"){
    		double Number;
    		while (!(cin >> Number)) {
    			cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			cout << ErrorMessage ;
    		}
    		return Number;
	   }
	   
	   static float ReadFloatNumber(string ErrorMessage="Invalid Number, Enter again\n"){
    		float Number;
    		while (!(cin >> Number)) {
    			cin.clear();
    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
    			cout << ErrorMessage ;
    		}
    		return Number;
	   }
	  
	  static string ReadString (){
	      
	      string s = ""; 	      
	      getline(cin >> ws , s );
	      
	      return s ; 
	  }
	  
	   static int ReadIntNumberBetween( int from , int to , string ErrorMessage="please enter a number in the valid range ! \n"){
	   	
	   	int n = ReadIntNumber();
	   	
	   	while(!IsNumBetween(n, from , to)){
	   	    
	   	    cout << ErrorMessage ; 
	   	    n = ReadIntNumber();
	   	}
	   	return n ; 
	   }
	   
	   static short ReadShortNumberBetween( short from , short to , string ErrorMessage="please enter a number in the valid range ! \n"){
	   	
	   	short n = ReadShortNumber();
	   	
	   	while(!IsNumBetween(n, from , to)){
	   	    
	   	    cout << ErrorMessage ; 
	   	    n = ReadShortNumber();
	   	}
	   	return n ; 
	   }
	   
	   static double ReadDblNumberBetween( double from , double to , string ErrorMessage="please enter a number in the valid range ! \n"){
	   	
	   	double n = ReadDblNumber();
	   	
	   	while(!IsNumBetween(n, from , to)){
	   	    
	   	    cout << ErrorMessage ; 
	   	    n = ReadDblNumber();
	   	}
	   	return n ; 
	   }
	   
	   static bool IsValidateDate (clsDate date ){
	       
	       return clsDate :: IsValidateDate(date) ;
	   }
};
