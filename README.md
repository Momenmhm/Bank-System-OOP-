# 🏦 Bank System

A console-based banking system built with C++ and OOP. It covers the main operations you'd expect in a real bank, from managing accounts to handling currencies.

---

##  Features

- Create and manage bank accounts
- Deposit, withdraw, and check balances
- View transaction history
- Currency exchange and management
- User login system with different access levels
- Input validation throughout the program

---

## Technologies Used
- C++ (Core language).
- Object-Oriented Programming (OOP).
- Clean code.

---

##  Project Structure
Bank-System-OOP/
│
├── 📂 Bank_Client/                  # Client data and all client-related screens
│   ├── clsBankClient.h
│   └── 📂 Bank_Client_Screens/
│       ├── clsAddNewClientScreen.h
│       ├── clsClientListScreen.h
│       ├── clsDeleteClientScreen.h
│       ├── clsFindClientScreen.h
│       ├── clsTransferScreen.h
│       ├── clsUpdateClientScreen.h
│       └── 📂 Transaction_Screens/
│           ├── clsDepositScreen.h
│           ├── clsWithdrawScreen.h
│           ├── clsTransActionScreen.h
│           └── clsTotalBalancesScreen.h
│
├── 📂 Users/                        # User accounts and permissions
│   ├── clsUser.h
│   └── 📂 clsUser_Screens/
│       ├── clsAddNewUserScreen.h
│       ├── clsDeleteUserScreen.h
│       ├── clsFindUserScreen.h
│       ├── clsManageUsersScreen.h
│       ├── clsUpdateUserScreen.h
│       └── clsUsersListScreen.h
│
├── 📂 currencies/                   # Currency data and exchange screens
│   ├── clsCurrency.h
│   └── 📂 Currency_Screens/
│       ├── clsCurrenciesListScreen.h
│       ├── clsCurrencyCalculatorScreen.h
│       ├── clsCurrencyExchangeMainScreen.h
│       ├── clsFindCurrencyScreen.h
│       └── clsUpdateCurrencyScreen.h
│
├── 📂 Main_Screens/                 # Login, main menu, and navigation
│   ├── clsLoginScreen.h
│   ├── clsMainScreen.h
│   ├── clsLoginRegisterScreen.h
│   ├── clsTransferLogScreen.h
│   ├── clsScreen.h
│   └── Global.h
│
├── 📂 library/                      # Shared utilities used across the project
│   ├── clsDate.h
│   ├── clsInputValidate.h
│   ├── clsPeraon.h
│   ├── clsString.h
│   └── clsUtil.h
│
├── main.cpp

---

## This project helped me strengthen my skills in:

- Applying OOP principles in real-world simulations.
- Implementing Data Structures inside a practical project.
- Writing clean, modular, and reusable code.
- Problem-solving and debugging.


 