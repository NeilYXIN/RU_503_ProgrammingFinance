
#include "BankAccount.h"
#include "StockAccount.h"
#include "LinkedList.h"
#include "Strategy.h"
#include <iostream>

#include <fstream>

using namespace std;

void printMainMenu();
void printStockMenu();
void printBankMenu();





int main()
{
	cout << endl << "Welcome to the Account Management System." << endl;
	int mainchoice = -1;
	double balance = 0.0;
	double portfolio = 0.0;
	//Account account;
	StockAccount stockaccount;
	BankAccount bankaccount;
	// template design pattern
	Account * array[] = { &stockaccount, &bankaccount };

	stockaccount.accountInitializer(&balance, &portfolio);
	
	while (mainchoice != 3)
	{
		printMainMenu();
		cin >> mainchoice;


		
		switch (mainchoice)
		{
		default:
		{
			cout << "invalid main menu choice, please select again!" << endl << endl;
			break;
		}
		// stock account
		case 1:
		{
			int stockchoice = -1;
			while (stockchoice != 7)
			{
				printStockMenu();
				
				cin >> stockchoice;

				switch (stockchoice)
				{
				default: // invalid input
				{
					cout << "invalid stock menu choice, please select again!" << endl << endl;
					break;
				}
				case 1: // Display the price for a stock symbol
				{
					string stockname;
					cout << "Please enter the stock symbol: " << endl;
					cin >> stockname;
					double price = stockaccount.getRandompPrice(stockname);
					// if price exist, 
					// format print price
                    // else print no such stock name handled in priceGetter
					if (price != -1.0)
					{
						cout.setf(ios::left); // left align
						cout.width(20); // set print length
						cout << endl << "Company-Symbol"  << "Price per share" << endl;
						cout.width(20); // set print length
						cout << stockname << price << endl;
					}
					break;
				}
				case 2: // Display the current portfolio
				{
					
					cout << endl << "Cash balance = $"<< balance << endl;
					stockaccount.printPortfolio();
				
					break;
				}
				case 3: // Buy shares
				{
					int stocknum = 0;
					string stockname;
					double idealprice = 0.0;
					
					cout << "Please enter the stock symbol you wish to purchase: ";
					cin >> stockname;
					cout << "Please enter the number of shares: ";
					cin >> stocknum;
					cout << "Please enter the maximum amount you are willing to pay per share: ";
					cin >> idealprice;
					double price = stockaccount.getRandompPrice(stockname);
					double total = price*stocknum;
					// determine various situations

					// money not enough
					if (idealprice*stocknum > balance)
					{
						cout << endl << "You don't have enough money for your purchase!" << endl;
					}
					// stock name not found
					else if (stockaccount.getRandompPrice(stockname) == -1.0)
					{
						cout << endl << "Stock name not found!" << endl;
					}
					// price is higher than willing
					else if (total/stocknum > idealprice)
					{
						cout << endl << "The price is higher than your bid!" << endl;
					}
					// buy success
					else
					{
						stockaccount.buyStock(stockname, stocknum, price); // buy stock
						bankaccount.withdraw(total, &balance); // add to bank history
						stockaccount.addStockHistory("Buy", stockname, stocknum, price);
						
						// add to stock history
						// add to portfolio // meaningless
						// update account info portfolio value
						// sort
					}
					
					break;
				}
				case 4: // Sell shares
				{
					int stocknum = 0;
					string stockname;
					double idealprice = 0.0;

					cout << "Please enter the stock symbol you wish to sell: ";
					cin >> stockname;
					cout << "Please enter the number of shares: ";
					cin >> stocknum;
					cout << "Please enter the minimun amount you are willing to get per share: ";
					cin >> idealprice;
					double price = stockaccount.getRandompPrice(stockname);
					double total = price*stocknum;
					// determine various situations
					// invalid stockname
					if (!stockaccount.bought(stockname))
					{
						cout << endl << "You don't have this stock in your account." << endl;
					}
					// insufficient stock number
					else if (stockaccount.getStockNum(stockname) < stocknum)
					{
						cout << endl << "You don't have enough stock in your account." << endl;
					}
					else if (stockaccount.getRandompPrice(stockname) < idealprice)
					{
						cout << endl << "The price is lower than your expected." << endl;
					}
					else
					{
						stockaccount.sellStock(stockname, stocknum, price);
						bankaccount.deposit(total, &balance);
						stockaccount.addStockHistory("Sell", stockname, stocknum, price);
					}

					break;
				}
				case 5: // View a graph for the portfolio value
				{
					// Strategy Design Pattern implemented here
					Strategy strategy;
					cout << endl << "Plot how many points? 0 for 10, 1 for 20: ";
					int in = -1;
					cin >> in;
					if (in == 0)
					{
						strategy.showTen();
						strategy.show();
					}
					else if (in == 1)
					{
						strategy.showTwenty();
						strategy.show();
					}
					else
					{
						cout << "invalid input!" << endl << endl;
					}
					break;
				}
				case 6: // View transaction history
				{
					// template design pattern
					array[0]->execute();
					break;
				}
				case 7: // back to main menu
				{
					break;
				}
				}
			}
			break;
		}
		// bank account
		case 2:
		{
			int bankchoice = -1;

			while (bankchoice != 5)
			{
				printBankMenu();
				cin >> bankchoice;
				switch (bankchoice)
				{
				default: // invalid input
				{
					cout << "invalid bank menu choice, please select again!" << endl << endl;
					break;
				}
				case 1: // View account balance
				{
					cout << "You have $" <<balance << " in your bank account." << endl;
					break;
				}
				case 2: // Deposit money
				{
					double money = 0.0;
					cout << "Please type the amount you wish to deposit: $";
					cin >> money;
					if (money >= 0)
					{
						bankaccount.deposit(money, &balance);

					}
					else
					{
						cout << "invalid input!" << endl;
					}
					break;
				}
				case 3: // Withdraw money
				{
					double money = 0.0;
					cout << "Please type the amount you wish to withdraw: $";
					cin >> money;
					if (money >= 0)
					{
						bankaccount.withdraw(money, &balance);
					}
					else
					{
						cout << "invalid input!" << endl;
					}
					
					break;
				}
				case 4: // Print out history
				{
					// template design pattern
					array[1]->execute();
					break;
				}
				case 5: // back to main menu
				{
					break;
				}
				}
			}
			break;
		}
		// exit program
		case 3:
		{
			
			stockaccount.savePortfolioHistory(balance, portfolio);
			stockaccount.savePortfolio();
			break;
		}
		}
	}
	return 0;
}

void printMainMenu() // print main menu
{
	cout << endl << "Please select an account to access:" << endl;
	cout << "1. Stock Portfolio Account" << endl;
	cout << "2. Bank Account" << endl;
	cout << "3. Exit" << endl;
	cout << endl << "Option: " << endl;
}

void printStockMenu()
{
	cout << endl << "Stock Portfolio Account" << endl << endl;
	cout << "Please select an option:" << endl;
	cout << "1. Display the price for a stock symbol" << endl;
	cout << "2. Display the current portfolio" << endl;
	cout << "3. Buy shares" << endl;
	cout << "4. Sell shares" << endl;
	cout << "5. View a graph for the portfolio value" << endl;
	cout << "6. View transaction history" << endl;
	cout << "7. Return to previous menu" << endl;
	cout << endl << "Option: " << endl;
}

void printBankMenu()
{
	cout << endl << "Bank Account" << endl << endl;
	cout << "Please select an option:" << endl;
	cout << "1. View account balance" << endl;
	cout << "2. Deposit money" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "4. Print out history" << endl;
	cout << "5. Return to previous menu" << endl;
	cout << endl << "Option: " << endl;
}





