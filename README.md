Stock Market Application

Simulation of stock market trading

The application first initializes the simulator by reading the file mystocks.txt, which contains five tickers and their prices. This data is stored in the MyStockPrices struct.

The user is first presented a menu in which they have five options: 
1. View the current price of one or more stocks 
2. Buy a stock
3. Sell a stock
4. View their portfolio
5. Quit the application

If the user decides to view the current price of one or more stocks, another menu is presented to the user. This sub-menu allows the user to choose between: viewing the current price of all stocksview, or viewing the current price of a single stock. A price that is modified based on a multiplier will be printed to the user. After the user checks the price(s), the user can go back to the main menu to choose other options.

When the user wants to buy a stock, the application first makes sure that the user has enough balance to complete the transaction. If the user does not have enough balance, the user is notified that the transaction cannot be completed. If the transaction is successful, the user's portfolio is updated with the new stock and the balance is decreased. After the transaction is completed, the buy price of the stock, the number of shares bought in the transaction, the total cost of the transaction, the new balance, and the total number of shares for the ticker bought is printed to the user.

When the user wants to sell a stock, the application first ensures that the user has enough shares of the stock that they would like to sell before completing the transaction. If the user does not have enough shares, the user is notified that the transaction cannot be completed. If the transaction is successful, the user's portfolio is updated with the coorect amount of shares of the recently sold stock and the balance is increased. After the transaction is completed, the buy price of the stock, the number of shares sold in the transaction, the total proceeds from the transaction, the new balance, and the total number of shares for the ticker sold is printed to the user.

If the user choose to view their portfolio before buying or selling a stock, a new portfolio will be set up for the user and the user will be notified of this update. If the user decides to view their portfolio after completing a transaction, their current portfolio will be displayed to them. 

After the user chooses an option on the menu, the user will go back to the main menu to continue choosing other options. 

When the user quits the program, the current data in the portfolio is saved.
