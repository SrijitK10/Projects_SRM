#include <iostream>
#include <queue>
#include <string>

using namespace std;

class BankAccount {
public:
    string name;
    double balance;
    bool hasDebitCard;
    bool hasCreditCard;
    bool hasInternetBanking;
    bool hasFixedDeposit;
    bool hasLocker;

    BankAccount(string n, double b, bool debitCard, bool creditCard, bool internetBanking, bool fixedDeposit, bool locker)
        : name(n), balance(b), hasDebitCard(debitCard), hasCreditCard(creditCard),
          hasInternetBanking(internetBanking), hasFixedDeposit(fixedDeposit), hasLocker(locker) {}
};

queue<BankAccount> accounts;

void calculateInterest(double rate) {
    while (!accounts.empty()) {
        BankAccount acc = accounts.front();
        accounts.pop();
        double interest = (acc.balance * rate) / 100;
        acc.balance += interest;
        cout << "Interest calculated for " << acc.name << ": $" << interest << endl;
        accounts.push(acc);
    }
}

void deposit() {
    string name;
    double amount;
    bool debitCard, creditCard, internetBanking, fixedDeposit, locker;

    cout << "Enter account holder's name: ";
    cin >> name;
    cout << "Enter initial deposit amount: $";
    cin >> amount;
    cout << "Does the account have a debit card? (1 for Yes, 0 for No): ";
    cin >> debitCard;
    cout << "Does the account have a credit card? (1 for Yes, 0 for No): ";
    cin >> creditCard;
    cout << "Is internet banking available for the account? (1 for Yes, 0 for No): ";
    cin >> internetBanking;
    cout << "Does the account have a fixed deposit? (1 for Yes, 0 for No): ";
    cin >> fixedDeposit;
    cout << "Does the account have a locker? (1 for Yes, 0 for No): ";
    cin >> locker;

    BankAccount acc(name, amount, debitCard, creditCard, internetBanking, fixedDeposit, locker);
    accounts.push(acc);
    cout << "Account created successfully." << endl;
}

void withdraw() {
    if (accounts.empty()) {
        cout << "No accounts available for withdrawal." << endl;
        return;
    }
    string name;
    double amount;
    cout << "Enter account holder's name: ";
    cin >> name;
    cout << "Enter withdrawal amount: $";
    cin >> amount;
    BankAccount acc = accounts.front();
    if (acc.balance >= amount) {
        acc.balance -= amount;
        cout << "Withdrawal successful. Remaining balance: $" << acc.balance << endl;
    } else {
        cout << "Insufficient balance for withdrawal." << endl;
    }
}

void checkLoanEligibility() {
    if (accounts.empty()) {
        cout << "No accounts available for loan eligibility check." << endl;
        return;
    }
    BankAccount acc = accounts.front();
    if (acc.balance >= 1000) {
        cout << "Congratulations! " << acc.name << " is eligible for a loan." << endl;
    } else {
        cout << acc.name << " is not eligible for a loan due to insufficient balance." << endl;
    }
}

void openFixedDeposit() {
    if (accounts.empty()) {
        cout << "No accounts available for fixed deposit." << endl;
        return;
    }
    string name;
    double depositAmount;
    cout << "Enter account holder's name: ";
    cin >> name;
    cout << "Enter fixed deposit amount: $";
    cin >> depositAmount;
    BankAccount acc = accounts.front();
    acc.balance += depositAmount;
    acc.hasFixedDeposit = true;
    accounts.pop();
    accounts.push(acc);
    cout << "Fixed deposit created successfully." << endl;
}

void openLocker() {
    if (accounts.empty()) {
        cout << "No accounts available for locker facility." << endl;
        return;
    }
    string name;
    cout << "Enter account holder's name: ";
    cin >> name;
    BankAccount acc = accounts.front();
    acc.hasLocker = true;
    accounts.pop();
    accounts.push(acc);
    cout << "Locker facility opened successfully." << endl;
}

void exchangeCurrency() {
    if (accounts.empty()) {
        cout << "No accounts available for currency exchange." << endl;
        return;
    }
    string name;
    double exchangeAmount;
    cout << "Enter account holder's name: ";
    cin >> name;
    cout << "Enter amount to exchange: $";
    cin >> exchangeAmount;
    BankAccount acc = accounts.front();
    if (acc.balance >= exchangeAmount) {
        acc.balance -= exchangeAmount;
        cout << "Currency exchanged successfully. Remaining balance: $" << acc.balance << endl;
    } else {
        cout << "Insufficient balance for currency exchange." << endl;
    }
}

int main() {
    int choice;
    double interestRate;

    do {
        cout << "\nBank Management System Menu:\n";
        cout << "1. Calculate Interest\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Loan Eligibility\n";
        cout << "5. Open Fixed Deposit\n";
        cout << "6. Open Locker\n";
        cout << "7. Exchange Currency\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter interest rate: ";
                cin >> interestRate;
                calculateInterest(interestRate);
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkLoanEligibility();
                break;
            case 5:
                openFixedDeposit();
                break;
            case 6:
                openLocker();
                break;
            case 7:
                exchangeCurrency();
                break;
            case 8:
                cout << "Exiting program. Thank you!";
                break;
            default:
                cout << "Invalid choice. Please try again.";
        }
    } while (choice != 8);

    return 0;
}