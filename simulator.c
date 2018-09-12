/*
 ============================================================================
 Stock Market Application
 File Name   : simulator.c
 Author      : Rosalba Monterrosas
 Date        : July 11, 2018
 ============================================================================
 */

#include "simulator.h"

void initializeSimulator(char* fileName, MyStockPrices* pMyStockPrices){
    char stockInfo[MAXIMUM_CAPACITY];
    pMyStockPrices->myStocksSize=0;
    pMyStockPrices->myStocksCapacity=MAX_MY_STOCKS;

    FILE* pFile=0;
    pFile=fopen(fileName,"r");
    if(pFile==NULL){
        printf("File did not open for reading.\n");
        exit(0);
    }
    while(fgets(stockInfo,MAXIMUM_CAPACITY-1,pFile)!=NULL){
        sscanf(stockInfo," %s %lf",pMyStockPrices->myStockPrices[pMyStockPrices->myStocksSize].ticker,&(pMyStockPrices->myStockPrices[pMyStockPrices->myStocksSize].price));
        (pMyStockPrices->myStocksSize)++;
        if((pMyStockPrices->myStocksSize) >= (pMyStockPrices->myStocksCapacity)) return;
    }
    if(pFile) fclose(pFile);
}

StockPrice* findStockPrice(MyStockPrices* pMyStockPrices, char* ticker){
    int ret;
    StockPrice* sp;
    int i;

    for (i = 0; i < (pMyStockPrices->myStocksSize); i++) {
        ret = strcmp(ticker, pMyStockPrices->myStockPrices[i].ticker);
        if (ret == 0) {
            sp = &(pMyStockPrices->myStockPrices[i]);
            //printf("Price of %s = %lf\n",pMyStockPrices->myStockPrices[i].ticker,sp->price);
            return sp;
        }
    }
    return 0;
}

double priceSimulatorInternal(double price){
    double perturbation=1/price;
    double multiplier;
    multiplier  =  ((double) rand())/RAND_MAX*perturbation;
    multiplier -= perturbation/2;
    multiplier +=1;
    return multiplier*price;
}

void inputPriceSimulator(char* pPriceSimulatorTicker, int menuOptionSelected2){
    if(menuOptionSelected2==2){
        printf("To check the current price of the stock, please enter a ticker from the following options: LULU, TSLA, AMD, AMZN, DOGZ\n");
        scanf(" %s",pPriceSimulatorTicker);
    }
}

double priceSimulator(MyStockPrices* pMyStockPrices, char* pPriceSimulatorTicker,int simAll){
    StockPrice* sp;
    double currentPrice;
    int i;

    if(simAll==1){
        for(i=0;i<(pMyStockPrices->myStocksSize);i++){
            currentPrice = priceSimulatorInternal(pMyStockPrices->myStockPrices[i].price);
            pMyStockPrices->myStockPrices[i].price = currentPrice;
            printf("Current price of %s = $%.2lf\n", pMyStockPrices->myStockPrices[i].ticker,pMyStockPrices->myStockPrices[i].price);
        }
    }else{
        do {
            sp = findStockPrice(pMyStockPrices, pPriceSimulatorTicker);
            if (sp == 0)
                printf("You entered an incorrect ticker. Please try again.\n");
        } while (sp == 0);
        currentPrice = priceSimulatorInternal(sp->price);
        sp->price = currentPrice;
        printf("Current price of %s = $%.2lf\n", pPriceSimulatorTicker,currentPrice);
    }
    return currentPrice;
}
