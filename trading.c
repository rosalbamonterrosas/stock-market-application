/*
 ============================================================================
 Stock Market Application
 File Name   : trading.c
 Author      : Rosalba Monterrosas
 Date        : July 11, 2018
 ============================================================================
 */

#include "trading.h"

void initializePortfolio(char* fileName,Portfolio* pMyPortfolio, double balance){
    char stockInfo[MAXIMUM_CAPACITY];
    int i=0;
    pMyPortfolio->myStocksSize=0;
    pMyPortfolio->myStocksCapacity=MAX_MY_STOCKS;

    FILE* pFile=0;
    pFile = fopen(fileName, "r");
    if (pFile == NULL) {
        printf("File did not open for reading.\n");
        exit(0);
    }
    while (fgets(stockInfo, MAXIMUM_CAPACITY - 1, pFile) != NULL) {
        sscanf(stockInfo, " %s", pMyPortfolio->myStocks[i].ticker);
        pMyPortfolio->myStocks[i].shares=0.0;
        pMyPortfolio->myStocks[i].buyPrice=0.0;
        i++;
        (pMyPortfolio->myStocksSize)++;
    }
    pMyPortfolio->balance=balance;

    if(pFile) fclose(pFile);
}

void savePortfolio(char* fileName, Portfolio* pMyPortfolio){
    int i;
    FILE* pFile=0;
    pFile=fopen(fileName,"w");
    if (pFile == NULL) {
            printf("File did not open for writing.\n");
            exit(0);
        }
    for(i=0;i<(pMyPortfolio->myStocksSize);i++){
        fprintf(pFile,"%s %lf %lf\n",pMyPortfolio->myStocks[i].ticker,pMyPortfolio->myStocks[i].shares,pMyPortfolio->myStocks[i].buyPrice);
    }
    fprintf(pFile,"%lf\n",pMyPortfolio->balance);

    if(pFile) fclose(pFile);
}

void readPortfolio(char* fileName, Portfolio* pMyPortfolio, int isSystem){
    int i=0;
    char stockInfo[MAXIMUM_CAPACITY];
    FILE* pFile=0;
    pFile = fopen(fileName, "r");
    if (pFile == NULL) {
        if(isSystem==0){
            printf("There is no existing portfolio. A new account is now set up.\n\n");
        }
        return;
    }

        while (fgets(stockInfo, MAXIMUM_CAPACITY - 1, pFile) != NULL) {
            if (i < (pMyPortfolio->myStocksSize)){
                sscanf(stockInfo, " %s %lf %lf", pMyPortfolio->myStocks[i].ticker,&pMyPortfolio->myStocks[i].shares,&pMyPortfolio->myStocks[i].buyPrice);
                i++;
            }
            else sscanf(stockInfo,"%lf",&pMyPortfolio->balance);
        }
    if(pFile) fclose(pFile);

//    for(i=0;i<5;i++)
//        printf("ticker: %s, shares: %lf, balance: %lf\n",pMyPortfolio->myStocks[i].ticker,pMyPortfolio->myStocks[i].shares,pMyPortfolio->balance);
}

void printStock(Stock* pStock){
    printf("\nTicker: %s\n",pStock->ticker);
    printf("Shares: %.2lf\n",pStock->shares);
    printf("Buy Price: $%.2lf\n",pStock->buyPrice);
}

void printPortfolio(Portfolio* pMyPortfolio){
    int i;

    for(i=0;i<(pMyPortfolio->myStocksSize);i++){
          printStock(&pMyPortfolio->myStocks[i]);
    }
    printf("\nBalance: $%.2lf\n",pMyPortfolio->balance);
}

double getBalance(Portfolio* pMyPortfolio){
  return pMyPortfolio->balance;
}

int inputBuy(char* pBuyTicker, double* pBuyShares,int menuOptionSelected,MyStockPrices* pMyStockPrices){
    StockPrice* sp;
    int goBack;

    if(menuOptionSelected==2){
        printf("Please enter the ticker you would like to buy.(LULU/TSLA/AMD/AMZN/DOGZ)\n");
        scanf(" %s",pBuyTicker);
        sp = findStockPrice(pMyStockPrices, pBuyTicker);
        printf("Current price of %s = $%.2lf\n",pBuyTicker,sp->price);
        printf("Please enter 1 to continue or 2 to go back to the main menu.\n");
        scanf(" %d",&goBack);
        if(goBack==2){
            return goBack;
        }

        printf("Please enter the number of the shares of %s you would like to buy.\n",pBuyTicker);
        scanf(" %lf",pBuyShares);
    }
    return goBack;
}

void buy(MyStockPrices* pMyStockPrices, Portfolio* pMyPortfolio, char* pBuyTicker,double* pBuyShares){
    int i;
    int ret;
    StockPrice* sp;
    double price;
    double totalCost;
    double previousBalance;
    double newBalance;

    sp=findStockPrice(pMyStockPrices,pBuyTicker);
    price=sp->price;
    totalCost=price*(*pBuyShares);
    previousBalance=getBalance(pMyPortfolio);
    newBalance=previousBalance-totalCost;

    if(newBalance>=0){
        for(i=0;i<(pMyPortfolio->myStocksSize);i++) {
            ret = strcmp(pBuyTicker, pMyPortfolio->myStocks[i].ticker);
            if (ret == 0) {
                pMyPortfolio->myStocks[i].shares+=(*pBuyShares);
                pMyPortfolio->myStocks[i].buyPrice=price;
                break;
            }
        }
            pMyPortfolio->balance = newBalance;
            printf("Buy Price of %s = $%.2lf\n",pBuyTicker,pMyPortfolio->myStocks[i].buyPrice);
            printf("Number of Shares Bought in this Transaction = %.2lf\n",(*pBuyShares));
            printf("Total Cost of this Transaction = $%.2lf\n",totalCost);
            printf("New Balance = $%.2lf\n",pMyPortfolio->balance);
            printf("Total number of %s shares = %.2lf\n",pBuyTicker,pMyPortfolio->myStocks[i].shares);
            printf("\nYour portfolio has been updated.\n");
    } else{
        printf("Your balance is not large enough to complete this transaction.\n");
        return;
    }
}

int inputSell(char* pSellTicker,double* pSellShares,int menuOptionSelected,MyStockPrices* pMyStockPrices){
    StockPrice* sp;
    int goBack;

    if(menuOptionSelected==3){
        printf("Please enter the ticker you would like to sell.(LULU/TSLA/AMD/AMZN/DOGZ)\n");
        scanf(" %s",pSellTicker);
        sp = findStockPrice(pMyStockPrices, pSellTicker);
        printf("Current price of %s = $%.2lf\n",pSellTicker,sp->price);
        printf("Please enter 1 to continue or 2 to go back to the main menu.\n");
        scanf(" %d",&goBack);
        if(goBack==2){
            return goBack;
        }

        printf("Please enter the number of the shares of %s you would like to sell.\n",pSellTicker);
        scanf(" %lf",pSellShares);
    }
    return goBack;
}

void sell(MyStockPrices* pMyStockPrices, Portfolio* pMyPortfolio, char* pSellTicker, double* pSellShares){
    StockPrice* sp;
    double price;
    double totalIncome;
    double previousBalance;
    double newBalance;
    int i;
    int ret;

    for(i=0;i<(pMyPortfolio->myStocksSize);i++) {
        ret = strcmp(pSellTicker, pMyPortfolio->myStocks[i].ticker);
        if (ret == 0) {
            if((*pSellShares)<=pMyPortfolio->myStocks[i].shares){
                sp=findStockPrice(pMyStockPrices,pSellTicker);
                price=sp->price;
                totalIncome=price*(*pSellShares);
                previousBalance=getBalance(pMyPortfolio);
                newBalance=previousBalance+totalIncome;
                pMyPortfolio->balance = newBalance;
                pMyPortfolio->myStocks[i].shares-=(*pSellShares);
                //printf("shares test = %lf\n",pMyPortfolio->myStocks[i].shares);
                if(pMyPortfolio->myStocks[i].shares==0){
                    pMyPortfolio->myStocks[i].buyPrice=0;
                }
            }
            else{
                printf("You do not have enough shares to complete this transaction.\n");
                return;
            }
            break;
        }
    }

    printf("Buy Price of %s = $%.2lf\n",pSellTicker,pMyPortfolio->myStocks[i].buyPrice);
    printf("Number of Shares Sold in this Transaction = %.2lf\n",(*pSellShares));
    printf("Total Proceeds from this Transaction = $%.2lf\n",totalIncome);
    printf("New Balance = $%.2lf\n",pMyPortfolio->balance);
    printf("Total number of %s shares = %.2lf\n",pSellTicker,pMyPortfolio->myStocks[i].shares);
    printf("\nYour portfolio has been updated.\n");
}

void saveStockPrices(char* fileName, MyStockPrices* pMyStockPrices){
    int i;
    FILE* pFile=0;
    pFile=fopen(fileName,"w");
    if (pFile == NULL) {
            printf("File did not open for writing.\n");
            exit(0);
        }
    for(i=0;i<(pMyStockPrices->myStocksSize);i++){
        fprintf(pFile,"%s %lf\n",pMyStockPrices->myStockPrices[i].ticker,pMyStockPrices->myStockPrices[i].price);
    }

    if(pFile) fclose(pFile);
}
