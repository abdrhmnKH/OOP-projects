
# Bank Management System (C++ OOP)

A console-based bank management system written in modern C++ (C++20) as an Object-Oriented Programming practice project. It manages bank clients, their transactions, system users with role-based permissions, and a currency exchange module. All data is stored in plain text files, so no database is needed.

## Features

**Authentication**
- Login screen with a limit of 3 failed attempts.
- Every successful login is recorded in a login register (date, user, permissions).
- Logout returns to the login screen.

**Client management**
- List all clients in a table.
- Add, update, delete, and find a client by account number.

**Transactions**
- Deposit and withdraw (withdrawals are rejected if the balance is not enough).
- Transfer money between two accounts.
- View total balances of all clients.
- Transfer log: every transfer is saved with date, both accounts, amount, balances after the transfer, and the user who did it.

**User management** (admin)
- List, add, update, delete, and find users.
- Set each user's permissions individually.

**Currency exchange**
- List all currencies (222 currencies with rates relative to USD).
- Find a currency by code or country.
- Update a currency's rate.
- Currency calculator to convert an amount between any two currencies.

## Permissions

Each user has a single integer that works as a bit mask. A screen opens only if the user has the matching bit, otherwise it shows "Access Denied".

| Permission | Value |
|---|---|
| All permissions | `-1` |
| Show clients list | `1` |
| Add new client | `2` |
| Delete client | `4` |
| Update client | `8` |
| Find client | `16` |
| Transactions | `32` |
| Manage users | `64` |
| Login register list | `128` |
| Transfer log list | `256` |
| Currency exchange | `512` |

To give a user several permissions, add their values. For example, `1 + 16 + 32 = 49` allows listing clients, finding clients, and transactions.

## Data Files

All files use `#//#` as the field separator, one record per line.

| File | Content |
|---|---|
| `Clients.txt` | `FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance` |
| `Users.txt` | `FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#EncryptedPassword#//#Permissions` |
| `Currencies.txt` | `Country#//#Code#//#Name#//#RateToUSD` |
| `LoginRegister.txt` | `DateTime#//#UserName#//#EncryptedPassword#//#Permissions` |
| `TransferLog.txt` | `DateTime#//#From#//#To#//#Amount#//#BalanceFrom#//#BalanceTo#//#UserName` |

## Project Structure

The project is header-only except for `oop projects.cpp`, which contains `main()`. Every screen is its own class.

```
oop projects/
├── oop projects.cpp            # Entry point: runs the login loop
├── Global.h                    # Holds the CurrentUser object
│
├── Core classes
│   ├── clsPerson.h             # Base class: name, email, phone
│   ├── clsBankClient.h         # Client data, deposit, withdraw, transfer, transfer log
│   ├── clsUser.h               # User data, permissions, login register
│   ├── clsCurrency.h           # Currency data and rates
│   └── clsDate.h               # Date and time helpers
│
├── Utility classes
│   ├── clsString.h             # String helpers (split, upper, lower, ...)
│   ├── clsUtil.h               # Encrypt/decrypt, random values, number to text
│   └── clsInputValidate.h      # Safe input reading and validation
│
├── Screens (all inherit from clsScreen)
│   ├── clsScreen.h             # Base screen: header, access check, user and date line
│   ├── clsLogin.h, clsMainScreen.h
│   ├── Clients:      clsClientListScreen.h, clsAddNewClient.h, clsUpdateClient.h,
│   │                 clsDeleteClient.h, clsFindClientScreen.h
│   ├── Transactions: clsTransactionScreen.h, clsDepositScreen.h, clsWithdrawScreen.h,
│   │                 clsTransferScreen.h, clsTransferLogScreen.h, clsShowTotalBalancesScreen.h
│   ├── Users:        clsManageUsersScreen.h, clsUsersListScreen.h, clsAddNewUser.h,
│   │                 clsUpdateUserScreen.h, clsDeleteUser.h, clsFindUserScreen.h
│   ├── Currency:     clsCurrencyExchangeScreen.h, clsCurrenciesListScreen.h,
│   │                 clsFindCurrencyScreen.h, clsShowUpdateRateScreen.h,
│   │                 clsCurrencyCalculatorScreen.h
│   └── clsShowLoginRegisterScreen.h
│
└── *.txt                       # Data files (see above)
```

## OOP Concepts Used

- **Inheritance:** `clsBankClient` and `clsUser` inherit from `clsPerson`; all screens inherit from `clsScreen`.
- **Encapsulation:** private fields with getters and setters exposed as properties.
- **Static methods:** screens and lookup functions (`Find`, `IsClientExist`, ...) are static, so no object is needed to use them.
- **Object modes:** each record object has a mode (Empty, Update, AddNew, Delete), and one `Save()` method decides what to do with it.
- **Separation of concerns:** data classes handle files, screen classes handle only the UI.

## Notes and Limitations

- This is a learning project, not production banking software.
- Passwords in `Users.txt` are only shifted by a fixed key, which is obfuscation and not real encryption. Client PIN codes are stored as plain text.
- Storing data in text files means there is no protection against two instances writing at the same time.

## Author
[abdrhmnKH](https://github.com/abdrhmnKH)
