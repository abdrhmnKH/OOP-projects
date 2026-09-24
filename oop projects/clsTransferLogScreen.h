#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsDate.h"

class clsTransferLogScreen : protected clsScreen
{
private:

    static void PrintTransferLogRecordLine(
        clsBankClient::stTransferLogRecord TransferLogRecord)
    {
        cout << setw(5) << left << "" << "| "
            << setw(18) << left << TransferLogRecord.DateTime
            << "| " << setw(13) << left << TransferLogRecord.AccountNumberFrom
            << "| " << setw(13) << left << TransferLogRecord.AccountNumberTo
            << "| " << setw(12) << left << TransferLogRecord.Amount
            << "| " << setw(15) << left << TransferLogRecord.AccountBalanceFrom
            << "| " << setw(15) << left << TransferLogRecord.AccountBalanceTo
            << "| " << setw(8) << left << TransferLogRecord.UserName
            << " |";
    }
public:

    static void ShowTransferLogScreen()
    {
        if (!CheckAccessRights(clsUser::_enPermissions::prTransferLogList))
        {
            return;
        }
        vector<clsBankClient::stTransferLogRecord> vTransferLog =
            clsBankClient::GetTransferLogList();
        string Title = "Transfer Log List Screen";
        string subtitle = "(" + to_string(vTransferLog.size()) + ") Record(s).";
        _DrawScreenHeader(Title, subtitle);
        UserAndDate();
        cout << "==============================================================================================================\n";
        cout << setw(5) << left << ""
            << "| " << setw(18) << left << "Date/Time"
            << "| " << setw(13) << left << "From Acc.Num"
            << "| " << setw(13) << left << "To Acc.Num"
            << "| " << setw(12) << left << "Amount"
            << "| " << setw(15) << left << "From Balance"
            << "| " << setw(15) << left << "To Balance"
            << "| " << setw(8) << left << "User"
            << " |\n";
        cout << "==============================================================================================================\n";
        for (clsBankClient::stTransferLogRecord Record : vTransferLog)
        {
            PrintTransferLogRecordLine(Record);
            cout << endl;
        }
        cout << "==============================================================================================================\n";
    }
};