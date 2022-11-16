#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <boost/algorithm/string.hpp>
using namespace std;
class Karta
{

public:
    string rodzaj;
    string temp;
    Karta()
    {

    }
    ~Karta()
    {
    }
    Karta(string rodzaj) {
        this->rodzaj = rodzaj;
    }
    void display()
    {
        cout << "\n Karta: " << rodzaj;
    }
    void checkForPin(int pin)
    {
        if (pin > 0 || pin < 9999)
        {
            cout << "\nPin jest nie poprawny.\n";
        }
    }
    auto getValue(string kar) const
    {

        if (kar == this->rodzaj)
            return  0;
        else
            return 1;
    }
    
};

inline vector<Karta*> addCards(vector<Karta*> karty, string karta)
{
    boost::algorithm::to_lower(karta);
    karty.push_back(new Karta(karta));
    return karty;
}

void checkCards(vector<Karta*> tempList, string* card)
{
   
    string cardRzut = "";
    cardRzut = *card;
    boost::algorithm::to_lower(cardRzut);
    if (std::find_if(tempList.begin(), tempList.end(), [&cardRzut](Karta* my) { return my->getValue(cardRzut) == 0; }) != tempList.end())
   {
        cout << "\nKarta znaleziona.\n";
   }
    else
    {
        cout << "\nKarta nie istnieje.\n";
        exit(1);
    }
    
}

void showCards(vector<Karta*> tempList)
{
    for (auto i : tempList)
    {
        i->display();
    }
}

int main(int argc, char** argv) {
    string karta;
    string* choosenCard;
    Karta* pinPtr = new Karta;
    string choosenCardE = "";

    choosenCard = &choosenCardE;
    int repeat;
    int pin;
    vector<Karta*> karty{};
    cout << "\nPodaj liczbe akceptowalnych kart\n";
    cin >> repeat;
    for (int i = 0; i < repeat; i++) {
        cout << "\nPrzed instalacja bankomatu, podaj akceptowalne karty:\n";
        cin >> karta;
        karty = addCards(karty, karta);
    }

    cout << "\nBANKOMAT QUAGMIRE ATM\n";
    cout << "\nKARTY AKCEPTOWANE PRZEZ BANKOMAT:\n";
    showCards(karty);
    cout << "\nWloz karte: \n";
    cin >> *choosenCard;
 
    checkCards(karty, choosenCard);
    cout << "\nWprowadz pin: \n";
    cin >> pin;
    pinPtr->checkForPin(pin);
    return 0;
}
