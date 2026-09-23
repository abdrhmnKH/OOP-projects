#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsDate.h"
class clsShowLoginRegisterScreen : protected clsScreen
{
private :
    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord) {
            cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
            cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
            cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
            cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
    }
public :
    static void ShowLoginRegisterList() {
        if (!CheckAccessRights(clsUser::_enPermissions::prLoginRegisterList)) {
            return;
        }
        vector <clsUser::stLoginRegisterRecord> vLoginRegisters = clsUser::GetLoginRegisterUsersList();
        string Title = "Login Register List Screen";
        string subtitle = "(" + to_string(vLoginRegisters.size()) + ")" + " Record(s).";
        _DrawScreenHeader(Title, subtitle);
        UserAndDate();
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cout << setw(8) << left << ""
            << "| " << setw(35) << left << "Date/Time"
            << "| " << setw(20) << left << "UserName"
            << "| " << setw(20) << left << "Password"
            << "| " << setw(10) << left << "Permissions"
            << "|\n";
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        for (clsUser::stLoginRegisterRecord Record : vLoginRegisters)
        {
            PrintLoginRegisterRecordLine(Record);
            cout << endl;
        }
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
    }
};

