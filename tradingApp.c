/*
 ============================================================================
 Stock Market Application
 File Name   : tradingApp.c
 Author      : Rosalba Monterrosas
 Date        : July 11, 2018
 Description : Allows the user to trade on the stock market
 ============================================================================
 */

#include "tradingApp.h"

void banner(){
//Prints a banner

    printf("Welcome to the Stock Market Application\n");
    printf("***************************************\n");
}

int getStockManagementMenuOptions(){
//Prints the menu options to the user

    int menuOptionSelected;

    printf("\nPress 1 to view the current price of one or more stocks.\n");
    printf("Press 2 to buy a stock.\n");
    printf("Press 3 to sell a stock.\n");
    printf("Press 4 to view your portfolio.\n");
    printf("Press 5 to quit the application.\n");
    scanf(" %d",&menuOptionSelected);

    return menuOptionSelected;
}

int getCheckPriceMenuOptions(){
//Prints the sub-menu options for checking the current price

    int menuOptionSelected2;

    printf("\nPress 1 to view the current price of all stocks.\n");
    printf("Press 2 to view the current price of a single stock.\n");
    scanf(" %d",&menuOptionSelected2);

    return menuOptionSelected2;
}

void processCheckPrices(int menuOptionSelected2,MyStockPrices* pMyStockPrices, char* pPriceSimulatorTicker){
//Invokes simulator functions to get the current price

    switch(menuOptionSelected2){
    case 1:
        priceSimulator(pMyStockPrices,pPriceSimulatorTicker,1);
        break;
    case 2:
        inputPriceSimulator(pPriceSimulatorTicker, menuOptionSelected2);
        priceSimulator(pMyStockPrices,pPriceSimulatorTicker,-1);
        break;
    default:
        printf("You did not enter a correct option. Please enter 1 or 2.\n");
    }

}

void processStockManagement(int menuOptionSelected,double balance,MyStockPrices* pMyStockPrices, char* pPriceSimulatorTicker,char* pBuyTicker,char* pSellTicker,double* pBuyShares,double* pSellShares,Portfolio* pMyPortfolio,char* fileName,char* fileName1){
//Invokes trading functions based on the menu choice selected by the user

    int menuOptionSelected2;
    initializePortfolio(fileName1,pMyPortfolio,balance);
    readPortfolio(fileName,pMyPortfolio,1);

    switch(menuOptionSelected){
    case 1:
        menuOptionSelected2 = getCheckPriceMenuOptions();
        processCheckPrices(menuOptionSelected2,pMyStockPrices,pPriceSimulatorTicker);
        break;
    case 2:
        buy(pMyStockPrices,pMyPortfolio,pBuyTicker,pBuyShares);
        savePortfolio(fileName,pMyPortfolio);
        break;
    case 3:
        sell(pMyStockPrices,pMyPortfolio,pSellTicker,pSellShares);
        savePortfolio(fileName,pMyPortfolio);
        break;
    case 4:
        readPortfolio(fileName,pMyPortfolio,0);
        printPortfolio(pMyPortfolio);
        break;
    case 5:
        printf("You have exited the application. Thank you for using The Stock Market Application.\n");
        printf("Your current portfolio has been saved.\n");
        savePortfolio(fileName,pMyPortfolio);
        saveStockPrices(fileName1,pMyStockPrices);
        exit(0);
    default:
        printf("You did not enter a correct option. Please enter 1, 2, 3, 4, or 5.\n");
    }
}

void process(){
//Driver of the tradingApp

    char* fileName1="mystocks.txt";
    char* fileName="portfolio.txt";
    MyStockPrices myStockPrices;
    srand(time(0));
    char priceSimulatorTicker[10];
    char buyTicker[10];
    char sellTicker[10];
    Portfolio myPortfolio;
    double buyShares=0;
    double sellShares=0;
    int menuOptionSelected;
    double balance=20000;
    int goBack;

    banner();
    initializeSimulator(fileName1, &myStockPrices);
    while(1){
        menuOptionSelected=getStockManagementMenuOptions();
        goBack = inputBuy(buyTicker,&buyShares,menuOptionSelected,&myStockPrices);
        if(goBack==2) continue;
        goBack = inputSell(sellTicker,&sellShares,menuOptionSelected,&myStockPrices);
        if(goBack==2) continue;
        processStockManagement(menuOptionSelected,balance,&myStockPrices,priceSimulatorTicker,buyTicker,sellTicker,&buyShares,&sellShares,&myPortfolio,fileName,fileName1);
    }
}
