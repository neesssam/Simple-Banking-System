#include <iostream>
using namespace std;

int main() {

    // VARIABLES
    unsigned int checkBalance;
    unsigned int saveBalance;
    char yn;
    char transferChoice;
    unsigned int sTransferamt;
    unsigned int cTransferamt;

    // INITIAL INPUT: CHECKING + SAVINGS BALANCE
    cout << "Please enter your checking account balance: $";
    cin >> checkBalance;

    cout << "Please enter your savings account balance: $";
    cin >> saveBalance;

    // TRANSFER SUGGESTION
    if (checkBalance > 5000) {
        cout << "You have more than $5,000 in your checking account. Consider transferring money into your savings account to earn interest" << endl;
    }

    // MAIN DIALOGUE - TRANSFER [yes or no]
    cout << "Would you like to transfer money to and from your accounts? \n[Y]es\t[N]o\n";
    cin >> yn;

    while (yn == 'y' || yn == 'Y') {
        // choosing where to transfer to/from
        cout << "Which account would you like to transfer to/from?" << endl;
        cout << "[S]avings to checking" << endl;
        cout << "[C]hecking to savings" << endl;
        cin >> transferChoice;

        // SAVING TO CHECKING
        if (transferChoice == 's' || transferChoice == 'S') {
            cout << "Input the amount you would like to take out of your savings account to put into your checking account: $";
            cin >> sTransferamt;

            // insufficient funds
            if (sTransferamt > saveBalance) {
                cout << "WARNING: Insufficient funds, Please try again" << endl;
            }
            else {
                checkBalance += sTransferamt;
                saveBalance -= sTransferamt;
                cout << "Complete! Your total checking account balance is $" << checkBalance << " and your total savings account balance is $" << saveBalance << endl;
            }
        }

        // CHECKING TO SAVING
        if (transferChoice == 'c' || transferChoice == 'C') {
            cout << "Input the amount you would like to take out of your checking account to put into your savings account: $";
            cin >> cTransferamt;

            // insufficient funds
            if (cTransferamt > checkBalance) {
                cout << "WARNING: Insufficient funds, Please try again" << endl;
            }
            else {
                checkBalance -= cTransferamt;
                saveBalance += cTransferamt;
                cout << "Complete! Your total checking account balance is $" << checkBalance << " and your total savings account balance is $" << saveBalance << endl;
            }
        }

        // ask if user wants to make another transfer
        cout << "Would you like to make another transfer? \n[Y]es\t[N]o\n";
        cin >> yn;
    }

    return 0;
}
