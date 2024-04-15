#include <iostream>

using namespace std;

class cashRegister 
{
private:
    int cashOnHand;

public:
    cashRegister() 
    {
        cashOnHand = 500; 
    }

    cashRegister(int cash) 
    {
        cashOnHand = cash; 
    }

    int getCurrentBalance() 
    {
        return cashOnHand;
    }

    void acceptAmount(int amount) 
    {
        cashOnHand += amount; 
    }
};

class dispenserType
{
private:
    int numberOfItems;
    int itemCost;

public:
    dispenserType()
    {
        numberOfItems = 50;
        itemCost = 50;
    }

    dispenserType(int items, int cost)
    {
        numberOfItems = items;
        itemCost = cost;
    }

    int getNoOfItems()
    {
        return numberOfItems;
    }

    int getCost()
    {
        return itemCost;
    }

    void makeSale()
    {
        numberOfItems--;
    }

};


void showSelection() 
{
    cout << "1. Сок Добрый (80 руб)" << endl;
    cout << "2. Шоколадный батончик Snickers (120 руб)" << endl;
    cout << "3. Палпи (90 руб)" << endl;
    cout << "Введите номер товара: ";
}

void sellProduct(dispenserType& dispenser, cashRegister& cashRegister) 
{
    int cost = dispenser.getCost();
    int balance = cashRegister.getCurrentBalance();
    int cash;
    if (dispenser.getNoOfItems() > 0) {
        cout << "Стоимость товара: " << cost << "руб.\n"  << "Введите сумму(руб): ";
        cin >> cash;
        if (cash >= cost) {
            if (balance >= cash - cost) {
                dispenser.makeSale();
                cashRegister.acceptAmount(cost);
                cout << "Подождите, идет выдача товара.\n";
                cout << "Ваша сдача: " << cash - cost << "руб.\n";
            }
            else {
                cout << "В автомате нет сдачи \nВнесите меньшую сумму.\n";
            }
        }
        else {
            cout << "Недостаточно средств. Внесите большую сумму.\n";
        }
    }
    else {
        cout << "Товара нет в наличии:(\n";
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    dispenserType juice(1, 80), chocolate(2, 120), pulpy(3,90);
    cashRegister cash(2000);

    int choice;
    showSelection();
    cin >> choice;

    switch (choice)
    {
    case 1:
        sellProduct(juice, cash);
        break;
    case 2:
        sellProduct(chocolate, cash);
        break;
    case 3:
        sellProduct(pulpy, cash);
        break;
    default:
        cout << "Неправильный выбор.\n";
        break;
    }


    return 0;
}