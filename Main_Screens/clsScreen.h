#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected :
    static void _DrawScreenHeader(string Title,string SubTitle ="")
    {
        cout << "\t______________________________________";
        cout << "\n\n\t\t " << Title;
        if (SubTitle != "")
        {
            cout << "\n  " << SubTitle;
        }
        cout << "\n\t______________________________________\n\n";
        cout <<"\t User : "<< CurrentUser.UserName()<< "  ";
        clsDate Date ;
        cout <<"\t Date : " ; 
        Date.print();
        cout << " \n\n ";
        
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
     
            if (!CurrentUser.CheckAccessPermission(Permission))
            {
                cout << "\n______________________________________";
                cout << "\n\n\t  Access Denied! Contact your Admin.";   
                cout << "\n______________________________________\n\n";
                return false;
            }
            else
            {
                return true;
            }

    }

};
