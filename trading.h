/*
 ============================================================================
 Stock Market Application
 File Name   : trading.h
 Author      : Rosalba Monterrosas
 Date        : July 11, 2018
 Description : Facilitates trading on the stock market
 ============================================================================
 */

#ifndef TRADING_H
#define TRADING_H

#include "simulator.h"

typedef struct{
    char ticker[MAX_TICKER_SIZE];
    double shares;
    double buyPrice;
} Stock;

typedef struct{
    Stock myStocks[MAX_MY_STOCKS];
    double balance;
    int myStocksSize;
    int myStocksCapacity;  //Should be set to MAX_MY_STOCKS
} Portfolio;

void initializePortfolio(char* fileName,Portfolio* pMyPortfolio, double balance);
void savePortfolio(char* fileName, Portfolio* pMyPortfolio);
void readPortfolio(char* fileName, Portfolio* pMyPortfolio,int isSystem);
void printStock(Stock* pStock);
void printPortfolio(Portfolio* pMyPortfolio);
double getBalance(Portfolio* pMyPortfolio);
int inputBuy(char* pBuyTicker, double* pBuyShares,int menuOptionSelected,MyStockPrices* pMyStockPrices);
void buy(MyStockPrices* pMyStockPrices, Portfolio* pMyPortfolio, char* pBuyTicker,double* pBuyShares);
int inputSell(char* pSellTicker,double* pSellShares,int menuOptionSelected,MyStockPrices* pMyStockPrices);
void sell(MyStockPrices* pMyStockPrices, Portfolio* pMyPortfolio, char* pSellTicker, double* pSellShares);
void saveStockPrices(char* fileName, MyStockPrices* pMyStockPrices);

#endif /* TRADING_H */
