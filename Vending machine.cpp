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
        itemCost = 0;
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
    cout << "1A. Сок Добрый (80 руб)" << endl;
    cout << "2А. Шоколадный батончик Snickers (120 руб)" << endl;
    cout << "3А. Палпи (90 руб)" << endl;
}

void sellProduct(dispenserType& dispenser, cashRegister& cashRegister) 
{
    int choice;
    int amount;

    cout << "Введите номер продукта: ";
    cin >> choice;

    switch (choice) 
    {
    case 1:
        cout << "Вы выбрали Сок Добрый." << endl;
        cout << "Цена: 80 руб" << endl;
        break;
    case 2:
        cout << "Вы выбрали Шоколадный батончик Snickers." << endl;
        cout << "Цена: 120 руб" << endl;
        break;
    case 3:
        cout << "Вы выбрали Палпи." << endl;
        cout << "Цена: 90 руб" << endl;
        break;
    default:
        cout << "Указан неверный номер." << endl;
        return;
    }

    cout << "Введите сумму: ";
    cin >> amount;

    if (amount < dispenser.getCost()) 
    {
        cout << "Недостаточно средств." << endl;
    }
    else 
    {
        dispenser.makeSale(); 
        cashRegister.acceptAmount(amount); 
        cout << "Покупка выполнена." << endl;
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    dispenserType dispenser;
    cashRegister cash;

    showSelection();
    sellProduct(dispenser, cash);

    return 0;
}