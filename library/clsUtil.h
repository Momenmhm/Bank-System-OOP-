#pragma once 
#include <iostream>
#include <ctime>
#include "clsDate.h" 
using namespace std ; 

class  clsUtil  {
    
       
    public : 
        
        enum enCharType { small = 1 , capital = 2 , mix = 3 , digit = 4 , specialchar = 5  };
        
        
        static void Srand (){
            
            srand((unsigned)time(NULL));
        }
        
        static int RandomNumber (int from , int to){
            

            return rand()%(to -from+1)+from ;            
        }
        
        static char RandomSmallChar(){
            
             return char(RandomNumber(97,122));
              }
              
         static char  RandomCapitalChar(){
            
             return char(RandomNumber(65,90));
              }
              
         static bool RandomBool (){
             
                   return RandomNumber(0,1);
           }     
            
         static char RandomMix (){
             
               switch ( RandomNumber(1,4)){
                   
                    case 1 :{
                         
                         return RandomCapitalChar();
                         break ; 
                    }   
                    case 2 :{
                        
                          return RandomSmallChar();
                          break ;                 
                    }  
                    case 3 : {
                        
                        return RandomNumber (48,57);
                        break ; 
                     }     
                   case 4 :{
                       
                       return RandomNumber (33,47);
                       break ;          
                   }
              } 
              
          }
                            
        static char RandomChar ( enCharType type){
            
            switch ( type){
                
                case capital: {
                    
                    return RandomCapitalChar ();
                    break ; 
                }
                case small : {
                    
                    return RandomSmallChar ();
                    break ; 
                }
                case mix :{
                    
                    return RandomMix();
                    break ; 
                }
                case digit :{
                    return (RandomNumber (48,57));
                    break ; 
                }
                case specialchar : {
                    
                    return char (RandomNumber (33,47));
                    break ; 
                  }
              }
            
         }
         
         
         static string GenrateWord ( enCharType type ,  short len){
                 
   
                       
                string word ;
                for (short i =1 ; i <= len ; i++){
                    
                    word += RandomChar(type);
                }
                
                return word ;
        }
        
        static string GenrateKey (enCharType type){
    
            string key ;
            for (short i =1; i <= 4 ; i++){
                 
               key += GenrateWord( type , 4 );
               
               if (i < 4 )
                   key += "-"; 
                }
            return key ;
        }
        
        
        static void GenrateKeys (short num, enCharType type ){
    
                short counter=0;
                string key ;
                for (short i =1 ; i<= num; i++){
                    
                      counter ++;
                      key =  GenrateKey(type );
                      
                      cout <<". key [ "<< counter<<" ] "<< key << endl;
                }
                
         }
         
        static string Tap (short n){
    
              string tap ="";
              for (short i = 0 ; i < n ; i++  ){
                  
                   tap += "     " ;
              } 
              return tap ;
        }

                                       
         static void swap ( int& n1 , int& n2 ){
    
                int temp ;
                temp = n1 ;
                n1 = n2 ;
                n2 = temp ;                       
          }
          static void swap ( short& n1 , short& n2 ){
    
                short temp ;
                temp = n1 ;
                n1 = n2 ;
                n2 = temp ;                       
          }
          
          static void swap( float& n1 , float& n2 ){
    
                float temp ;
                temp = n1 ;
                n1 = n2 ;
                n2 = temp ;                       
          }
          
          
          static void swap ( double& n1 , double& n2 ){
    
                double temp ;
                temp = n1 ;
                n1 = n2 ;
                n2 = temp ;                       
          }
                    
          static void swap ( string& s1 , string& s2 ){
    
                string temp ;
                temp = s1 ;
                s1 = s2 ;
                s2 = temp ;                       
          }     
            
         static void swap ( char& s1 , char& s2 ){
    
               char temp ;
                temp = s1 ;
                s1 = s2 ;
                s2 = temp ;                                
          }  
          
          static void swap (clsDate& d1 , clsDate & d2){
              
              d1.Swap( d2);
          }
        
         static int shufflearray (int array[] , short length){
       
                for (int i = 0 ; i < length ; i++){
                            
                    swap (array[RandomNumber (1,length)-1],array[RandomNumber(1,length)-1]);
                }    
            }
            
          static string shufflearray (string array[] , short length){
       
                for (int i = 0 ; i < length ; i++){
                            
                    swap (array[RandomNumber (1,length)-1],array[RandomNumber(1,length)-1]);
                }    
            }
         
         static string encyptText(string text, short key){
    
            int len = text.length();
            for (int i = 0 ; i < len ; i++){
                
                   text[i] = char ( (int) text[i] + key );
            }
            return text ;
        }
        
        
        static string DecryptText(string encrypted , short key ){
    
            int len = encrypted.length();
            for (int i = 0 ; i < len ; i++){
                
                  encrypted[i] = char( (int)encrypted[i] - key);
        
            }
            return encrypted;            
        }
        
        static string NumberToText(int Number){

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }


   }
                
};
