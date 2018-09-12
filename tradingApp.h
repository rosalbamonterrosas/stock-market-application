/*
 ============================================================================
 Stock Market Application
 File Name   : tradingApp.h
 Author      : Rosalba Monterrosas
 Date        : July 11, 2018
 Description : Allows the user to trade on the stock market
 ============================================================================
 */

#ifndef TRADINGAPP_H
#define TRADINGAPP_H

#include "trading.h"

void banner();
int getStockManagementMenuOptions();
int getCheckPriceMenuOptions();
void processCheckPrices(int menuOptionSelected2,MyStockPrices* pMyStockPrices, char* pPriceSimulatorTicker);
void processStockManagement(int menuOptionSelected,double balance,MyStockPrices* pMyStockPrices, char* pPriceSimulatorTicker,char* pBuyTicker,char* pSellTicker,double* pBuyShares,double* pSellShares,Portfolio* pMyPortfolio,char* fileName,char* fileName1);
void process();

#endif /* TRADINGAPP_H */
