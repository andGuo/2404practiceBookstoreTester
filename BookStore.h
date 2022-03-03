#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <string>
#define MAX_ARR 200
using namespace std;

class Book
{
  public:
    Book(const string& t, float p) : title(t), price(p)
    {
    }
    const string& getTitle()
    {
        return title;
    }
    float getPrice()
    {
        return price;
    }

  private:
    string title;
    float price;
};

class BookStore
{

  public:
    BookStore(const string& name);
    BookStore(const BookStore&);
    ~BookStore();

    void addBook(const string& title, float price);
    void getBook(const string& title, Book**);
    void removeBook(const string& title, Book**);
    void getMinPrice(Book**) const;

  private:
    string name;
    Book** books;
    int numBooks;
};

#endif // BOOKSTORE_H