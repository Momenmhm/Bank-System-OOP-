#pragma once 
#include <iostream>
#include <vector>
//#include <string>

using namespace std ; 

class clsString {
    
    private : 
        string  _value ; 
//        struct stClint {
//    
//            string name ;
//            string AccountNum ;
//            int PinCode ;
//            string Phone ;
//            double Balance ;        
//        };
    
    
    public : 
        
        clsString (string str){
            
            _value = str ; 
        }
        clsString (){
           _value = "" ;
        }
        
//        void SetValue (string str){
//            
//            _value = str ; 
//        }
//        string GetValue (){
//            
//            return _value ; 
//        }
        
        static void PrintSmallLetter(string message){
    
            char letter ;
            for (short let =0  ; let < message.length() ; let++){
                letter =message [let];
                if ( message [let] != ' ' ){
                    
                    message[let] = tolower(letter);
                }
        
            }
            cout <<"    "<< message <<endl ;
        } ; 
        
//        void PrintSmallLetter(){
//            
//            PrintSmallLetter(_value) ;
//        } ; 
        
        
        static void PrintCapitalLetter(string message){
    
            char letter ;
            for (short let =0  ; let < message.length() ; let++){
                letter =message [let];
                if ( message [let] != ' ' ){
                    
                    message[let] = toupper(letter);
                }
        
            }
            cout <<"    "<< message <<endl ;
        } ; 
        
//        void PrintCapitalLetter(){
//            
//            PrintCapitalLetter( _value) ;
//        } ;
        
        
        static short CountEachWord (string str ){
    
        //    cout <<"\n your string words are : \n\n";
            
            string sword ;
            string space =" ";
            short pos =0;
            short counter=0;
            while ((pos = str.find(space) )!= std :: string :: npos){        
                
                sword = str.substr(0,pos);
                if (sword != "")
                    counter++;
                
                str.erase(0,pos + space.length());
            }
            if (str != "")
                counter ++ ;
                
            return counter;
        }
        
        short CountEachWord (){
            
            return CountEachWord(_value); 
        }
    
        static void PrintFiponatshiSeries(short num, short prev1 , short prev2 ){
  
          
            int febNum =0;
        
            if (num > 0){    
            
                 febNum = prev2 + prev1;         
                 
                 prev1 = prev2 ;
                 prev2 = febNum;
                 cout <<" "<< febNum<<"  ";
                 PrintFiponatshiSeries(num-1,prev1, prev2);
            }
        }
        private : char inverchar (char ch){
    
            return isupper (ch) ? tolower(ch) : toupper (ch);    
        }
        public : 
        
        string InvertAllLetter (string str){
            
            for (short i =0; i < str.length(); i++){
                
                if (str[i] != ' '){
                    
                    str[i] = inverchar (str[i]);
                }      
           }
           return str ;     
        }
        
//       void InvertAllLetter (){
//            _value =  InvertAllLetter(_value); 
//       }
        
       static void PrintFirstLetter(string message){
    
            bool isfirstletter = true ;
            
            for (short let =0  ; let < message.length() ; let++){
                
                if (message[let] != ' ' && isfirstletter ){
                    
                    cout <<" "<< message[let]<<endl ;
                }
                
                isfirstletter= (message [let] == ' ' ? true : false );
            }
        } 
        
:
        
        
        private : bool IsVowl (char ch ){
            
             ch = tolower(ch);
             return ((ch == 'a') || (ch == 'u') || (ch == 'e') || (ch =='i') || (ch == 'o'));                       
        } 
        public :

        void PrintVowels (string str ){
            
              for (short i =0; i < str. length(); i++){
                
                  if (IsVowl(str[i]))
                      cout <<"  "<< str[i];     
              }
        
        }  
         
        
        
        
        static string RemovePunc (string str ){
               short pos =0;
                string s2 ="" ;
                for (short i =0; i < str.length(); i++){
                    
                    if (! ispunct(str[i]) ){
                        
                        s2 += str[i]  ;
                    }                
                }
                return s2 ;    
            }
        
        
        
        static string ReplaceWord (string s1 , string oldword , string newword){
        
        short pos = s1.find(oldword);
        while ((pos!= std:: string :: npos )){
            
            s1.replace(pos , oldword. length(),newword);
            pos = s1.find(oldword);        
        }
        return s1 ;
        
        }
        
        void ReplaceWord ( string oldword , string newword){
            
           _value = ReplaceWord(_value , oldword , newword ) ; 
        }
        
        private : 
        
        string mytolower (string n ){    
     
            for (short i =0; i < n.length() ; i++){
                
                n[i] = tolower(n[i]);        
            }    
            return n  ;
        }
       
        public : 
        
        static vector<string> ReverseString (string str ){
    
            vector<string> vRevStr ;
            string sword ="";
            short countword =0;
        
            for (short i = str.length() -1 ; i > 0 ; i --){
        //            "momen mahmoud salih";
                
                if ( str[i] != ' '  ){
                    countword++;            
                }
                else {           
                      if (countword > 0){
                        sword = str.substr(i +1 , i + countword);
                        vRevStr. push_back(sword);
                        str.erase(i  ,  i + countword);
                        countword=0;   
                        
                        }                              
                }
            }
            
            vRevStr.push_back(str) ;
            return vRevStr ;
        }
        
        vector<string> ReverseString (){
            
            return ReverseString(_value) ;            
        }

        static void PrintVectorString (vector<string> vnames){
            

            vector<string> :: iterator iter = vnames.end();
            
            while (vnames. begin() != iter ){
                
                cout << *iter <<" " ;
                iter--;
            }            
        }
                
        
        static vector<string> split (string str, string space ="#//#" ){
    
            vector<string> vWords ;
            
            string sword ;
            short pos =0;
            
            while ((pos = str.find(space) )!= std :: string :: npos){        
                
                sword = str.substr(0,pos);
        //        if (sword != "")
                    vWords.push_back(sword);
                
                str.erase(0,pos + space.length());
            }
            if (str != "")
                vWords.push_back(str);
                
            return vWords ;
        }

  //      vector<string> split ( string space =" " ){
//                  
//                  return split (this->_value , space ); 
//        }
        
        
        string TrempLeft (string str ){

        for (short i =0 ; i < str.length() ; ){
           
            if (str[i] == ' '){
                
                str.erase(0,1);
            }
           else 
               break ;         
        }
        return str ;
    }
    
        string TrempRight (string str ){
    
            for (short i = str.length() ; i >0  ;i-- ){
              
                if (str[i-1] != ' ')            
                   return str.substr(0, str.length()- i);   
                     
            }
            return str ;
        }
        
        string Tremp (string str ){
 
              return TrempLeft (TrempRight (str));
   
        }
        
        static string LowerAllString(string message){
    
            char letter ;
            
            for (short let =0  ; let < message.length() ; let++){
                letter =message [let];
                if ( message [let] != ' ' ){
                    
                    message[let] = tolower(letter);
                }
    
            }
            return message ;
    
        }
    
    static string UpperAllString(string message){
        
        char letter ;
        for (short let =0  ; let < message.length() ; let++){
            letter =message [let];
            if ( message [let] != ' ' ){
                
                message[let] = toupper(letter);
            }

        }
        return message ; 
        
    }

    

                              
        
        //static string JoinString (stClint& vnames , string space = " "){
//    
//            string names ="";
//        
//            names += vnames.AccountNum + space ;
//            
//           names +=to_string( vnames.PinCode) +space ;
//           
//           names += vnames.name +space ;
//           
//           names += vnames.Phone + space ;
//           names += to_string(vnames. Balance ); 
//            
//            return names ;
//            //return names.substr(0,names.length() - space.length());
//        }
//        
//        string JoinString (){
//            
//            return JoinString (_value );
//        }
        
    
};
