#include <iostream>
#include <iomanip>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsLogin.h"
#include "Global.h"
int main()
{
    while (true) {

        if (!clsLogin::ShowLoginScreen())
            break;
    }
    system("pause>0");
    return 0;
}