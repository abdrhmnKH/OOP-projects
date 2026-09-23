#pragma once
#include <iostream>
#include"clsUser.h"
#include <iomanip>
#include "Global.h"
using namespace std;
class clsScreen
{
protected :
        static void _DrawScreenHeader(string Title, string SubTitle = "")
        {
            cout << "\t\t\t\t     ========================================================";
            cout << "\n\n\t\t\t\t\t\t      " << Title;
            if (SubTitle != "")
            {
                cout << "\n\t\t\t\t\t\t\t  " << SubTitle;
            }
            cout << "\n\t\t\t\t     ========================================================\n\n";
        }
        static bool CheckAccessRights(clsUser::_enPermissions permission) {
            if (!CurrentUser.CheckUserPermission(permission)) {
                cout << "\t\t\t\t     ========================================================";
                cout << "\n\n\t\t\t\t\t\t   Access Denied .Contact your Admin.";
                cout << "\n\t\t\t\t     ========================================================";
                return false;
            }
            else
                return true;
        }
};

