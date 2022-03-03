#include "BookStore.h"
#include <iomanip> // to set the decimal precision for price float
#include <iostream>

/* This tester assumes the Book class works and does not test it
// also assumes Book class is declared and defined in BookStore.h
// and BookStore class is declared in BookStore.h
//
// Keep in mind, some tests are pretty hardcoded
*/
int main()
{
    BookStore* myStore = new BookStore("Cope Harder Bookstore");

    // this is C++17 but dw abt it :-)
    Book myBooks[] = {Book("C++ For Dummies", 35.99), Book("Javascript For Dummies", 35.99), Book("Minecraft For Dummies", 2.00),
                      Book("Fortnite For Dummies", 0.10), Book("50 Shades of Grey", 19.99), Book("On Liberty", 9.99)};
    int numMyBooks = sizeof(myBooks)/sizeof(myBooks[0]);

    // adding books
    std::cout << "\nAdding books..." << std::endl;

    for (int i = 0; i < numMyBooks; ++i)
    {
        myStore->addBook(myBooks[i].getTitle(), myBooks[i].getPrice());
    }

    std::cout << "\n>>>> Test 1: Getting Books..." << std::endl;
    for (int i = 0; i < numMyBooks; ++i)
    {
        Book* gotBook;
        myStore->getBook(myBooks[i].getTitle(), &gotBook);
        std::cout << std::fixed << std::setprecision(2) << "Found book #" << i + 1 << ": " << gotBook->getTitle()
                  << " - $" << gotBook->getPrice() << std::endl;
    }
    std::cout << "There should be " << numMyBooks << " books (check)" << std::endl;

    // hard-coded, change if you add stuff
    std::cout << "\n>>>> Test 2: Finding lowest price book..." << std::endl;
    {
        Book* gotBook;
        myStore->getMinPrice(&gotBook);
        if (gotBook->getTitle() == "Fortnite For Dummies")
        {
            std::cout << "Success!" << std::endl;
        }
        else
        {
            std::cout << "FAILED...\n\"Fortnite For Dummies\" - $0.10 should be the cheapest." << std::endl;
        }
        std::cout << "The book returned was: " << gotBook->getTitle() << " - $" << gotBook->getPrice() << std::endl;
    }

    std::cout << "\n>>>> Test 3: Removing unappealing books..." << std::endl;
    {
        Book* gotBook;
        myStore->removeBook("Javascript For Dummies", &gotBook);
        std::cout << "Removed: "<< gotBook->getTitle() << std::endl;
        delete gotBook;
        myStore->removeBook("Fortnite For Dummies", &gotBook);
        std::cout << "Removed: "<< gotBook->getTitle() << std::endl;
        delete gotBook;
    }

    // hard-coded, change if you add stuff
    std::cout << "\n>>>> Test 4: Finding lowest price book - again..." << std::endl;
    {
        Book* gotBook;
        myStore->getMinPrice(&gotBook);
        if (gotBook->getTitle() == "Minecraft For Dummies") 
        {
            std::cout << "Success!" << std::endl;
        }
        else
        {
            std::cout << "FAILED...\n\"Minecraft For Dummies\" - $2.00 should be the cheapest." << std::endl;
        }
        std::cout << "The book returned was: " << gotBook->getTitle() << " - $" << gotBook->getPrice() << std::endl;;
    }

    std::cout << "\n>>>> Test 5: Cloning Bookstore..." << std::endl;

    BookStore* myStoreClone = new BookStore(*myStore);

    std::cout << "\n>>>> Freeing Old Store... (Check your valgrind)" << std::endl;
    delete myStore;

    // hard-coded, change if you add stuff
    std::cout << "\n>>>> Test 6: Getting Copied Books..." << std::endl;
    for (int i = 0; i < numMyBooks; ++i)
    {
        Book* gotBook = NULL;
        myStoreClone->getBook(myBooks[i].getTitle(), &gotBook);
        if (gotBook != NULL)
        {
             std::cout << std::fixed << std::setprecision(2) << "Found book #" << i + 1 << ": " << gotBook->getTitle()
                  << " - $" << gotBook->getPrice() << std::endl;
        }
    }
    std::cout << "There should be " << numMyBooks - 2 << " books (check)" << std::endl;

    std::cout << "\n>>>> Freeing Cloned Store... (Check your valgrind)\n" << std::endl;
    delete myStoreClone;
}