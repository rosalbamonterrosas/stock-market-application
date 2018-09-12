/*
 ============================================================================
 Stock Market Application
 File Name   : simulator.h
 Author      : Rosalba Monterrosas
 Date        : July 11, 2018
 ============================================================================
 */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXIMUM_CAPACITY 100
#define MAX_MY_STOCKS 5
#define MAX_TICKER_SIZE 10

typedef struct{
    char ticker[MAX_TICKER_SIZE];
    double price;
} StockPrice;

typedef struct{
    StockPrice myStockPrices[MAX_MY_STOCKS];
     int myStocksSize;
     int myStocksCapacity;  //Should be set to MAX_MY_STOCKS
} MyStockPrices;

void initializeSimulator(char* fileName, MyStockPrices* pMyStockPrices);
StockPrice* findStockPrice(MyStockPrices* pMyStockPrices, char* ticker);
double priceSimulatorInternal(double price);
void inputPriceSimulator(char* pPriceSimulatorTicker, int menuOptionSelected2);
double priceSimulator(MyStockPrices* pMyStockPrices, char* ticker,int simAll);

#endif /* SIMULATOR_H */
