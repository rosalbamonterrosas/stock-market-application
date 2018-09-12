/*
 ============================================================================
 Stock Market Application
 File Name   : project3main.c
 Author      : Rosalba Monterrosas
 Date        : July 11, 2018
 Description : Simulation of stock market trading
 ============================================================================
 */

#include "tradingApp.h"

void test3(){
//Tests the simulator and trading functions

    MyStockPrices myStockPrices;
    StockPrice* pStockPrice;
    int i;
    double internalResult;
//    char priceSimulatorTicker[10];
//    char buyTicker[10];
//    char sellTicker[10];
//    double buyShares=0;
//    double sellShares=0;
    double buyShares2 =2;
    double sellShares2 =1;
    srand(time(0));
    Portfolio myPortfolio;
    double balance1;

    banner();

    //Testing initializeSimlator()
    printf("Testing initializeSimlator()\n");
    initializeSimulator("mystocks.txt", &myStockPrices);
       for(i=0;i<myStockPrices.myStocksSize;i++) {
           printf("Ticker=%s;  Price=%lf\n",myStockPrices.myStockPrices[i].ticker,myStockPrices.myStockPrices[i].price);
       }
    //Testing findStockPrices()
    printf("\nTesting findStockPrices()\n");
    pStockPrice = findStockPrice(&myStockPrices, "LULU");
    if(pStockPrice) {
        printf("Ticker = %s;  Price=%lf\n",pStockPrice->ticker,pStockPrice->price);
    }else{
        printf("Ticker Not found\n");
    }

    //Testing priceSimulatorInternal()
    printf("\nTesting priceSimulatorInternal()\n");
    internalResult = priceSimulatorInternal(4.5);
    printf("New price with multiplier = %lf\n",internalResult);

//    //Testing inputPriceSimulator()
//    printf("\nTesting inputPriceSimulator()\n");
//    inputPriceSimulator(priceSimulatorTicker,2);
//    printf("Ticker = %s\n",priceSimulatorTicker);

    //Testing priceSimulator()
    printf("\nTesting priceSimulator()\n");
    for(i=0;i<10;i++){
        priceSimulator(&myStockPrices,"DOGZ",-1);
    }

    //Testing initializePortfolio() and printPortfolio()
    printf("\nTesting initializePortfolio() and printPortfolio()\n");
    initializePortfolio("mystocks.txt",&myPortfolio,20000);
    printPortfolio(&myPortfolio);

    //Testing printStock()
    printf("\nTesting printStock()\n");
    for(i=0;i<(myPortfolio.myStocksSize);i++){
          printStock(&myPortfolio.myStocks[i]);
    }

    //Testing readPortfolio()
    printf("\nTesting readPortfolio()\n");
    readPortfolio("portfolio.txt",&myPortfolio,0);
    printf("Printing portfolio:\n");
    printPortfolio(&myPortfolio);

    //Testing getBalance()
    printf("\nTesting getBalance()\n");
    balance1 = getBalance(&myPortfolio);
    printf("Balance = %lf\n",balance1);

//    //Testing inputBuy()
//    printf("\nTesting inputBuy()\n");
//    inputBuy(buyTicker,&buyShares,2,&myStockPrices);
//    printf("Buy ticker = %s; Buy shares = %lf\n",buyTicker,buyShares);

    //Testing buy()
    printf("\nTesting buy()\n");
    buy(&myStockPrices,&myPortfolio,"AMD",&buyShares2);

//    //Testing inputSell()
//    printf("\nTesting inputSell()\n");
//    inputSell(sellTicker,&sellShares,3,&myStockPrices);
//    printf("Sell ticker = %s; Sell shares = %lf\n",sellTicker,sellShares);

    //Testing sell()
    printf("\nTesting sell()\n");
    sell(&myStockPrices,&myPortfolio, "AMD", &sellShares2);

    //Testing savePortfolio()
    printf("\nTesting savePortfolio()\n");
    savePortfolio("portfolio.txt",&myPortfolio);
    readPortfolio("portfolio.txt",&myPortfolio,0);
    printPortfolio(&myPortfolio);

    //Testing saveStockPrices()
    printf("\nTesting saveStockPrices()\n");
    saveStockPrices("mystocks.txt",&myStockPrices);
    initializeSimulator("mystocks.txt", &myStockPrices);
       for(i=0;i<myStockPrices.myStocksSize;i++) {
           printf("Ticker=%s;  Price=%lf\n",myStockPrices.myStockPrices[i].ticker,myStockPrices.myStockPrices[i].price);
       }
}

void test4(){
//Tests the tradingApp functions

//    int menuOptionSelected;
//    int menuOptionSelected2;
    MyStockPrices myStockPrices;
    Portfolio myPortfolio;
    char priceSimulatorTicker[10];
    double buyShares=2;
    double sellShares=1;

//    //Testing getStockManagementMenuOptions()
//    printf("Testing getStockManagementMenuOptions()\n");
//    menuOptionSelected = getStockManagementMenuOptions();
//    printf("Menu Option Selected = %d\n",menuOptionSelected);
//
//    //Testing getCheckPriceMenuOptions()
//    printf("\nTesting getCheckPriceMenuOptions()\n");
//    menuOptionSelected2 = getCheckPriceMenuOptions();
//    printf("Menu Option Selected = %d\n",menuOptionSelected2);

    //Testing processCheckPrices()
    printf("\nTesting processCheckPrices()\n");
    initializeSimulator("mystocks.txt", &myStockPrices);
    processCheckPrices(1,&myStockPrices,priceSimulatorTicker);

    //Testing processStockManagement()
    printf("\nTesting processStockManagement()\n");
    processStockManagement(2,20000,&myStockPrices,priceSimulatorTicker,"DOGZ","DOGZ",&buyShares,&sellShares,&myPortfolio,"portfolio.txt","mystocks.txt");
}

int main() {
    //test3();
    //test4();
    process();
    return 0;
}
