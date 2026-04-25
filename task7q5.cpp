#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool checkedOut;
public:
    Media(string t, string date, string id, string pub)
        : title(t), publicationDate(date), uniqueID(id), publisher(pub), checkedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << " | ID: " << uniqueID
             << " | Publisher: " << publisher
             << " | Date: " << publicationDate << endl;
    }
    void checkOut() {
        if (!checkedOut) { checkedOut = true;  cout << "\"" << title << "\" checked out." << endl; }
        else cout << "Already checked out!" << endl;
    }
    void returnItem() {
        if (checkedOut) { checkedOut = false; cout << "\"" << title << "\" returned." << endl; }
        else cout << "Was not checked out!" << endl;
    }
    
    bool search(string t)  { return title == t; }
    bool search(int year)  { return publicationDate.find(to_string(year)) != string::npos; }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string date, string id, string pub,
         string auth, string isbn, int pages)
        : Media(t, date, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        cout << "[Book] ";
        Media::displayInfo();
        cout << "  Author: " << author
             << " | ISBN: " << ISBN
             << " | Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    string director, rating;
    int duration;
public:
    DVD(string t, string date, string id, string pub,
        string dir, int dur, string rat)
        : Media(t, date, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() override {
        cout << "[DVD] ";
        Media::displayInfo();
        cout << "  Director: " << director
             << " | Duration: " << duration << " min"
             << " | Rating: " << rating << endl;
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string date, string id, string pub,
       string art, int tracks, string gen)
        : Media(t, date, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        cout << "[CD] ";
        Media::displayInfo();
        cout << "  Artist: " << artist
             << " | Tracks: " << numberOfTracks
             << " | Genre: " << genre << endl;
    }
};

int main() {
    Media* library[3];
    library[0] = new Book("The Alchemist", "1988", "B001", "HarperCollins",
                           "Paulo Coelho", "978-0062315007", 208);
    library[1] = new DVD("Inception", "2010", "D001", "Warner Bros",
                          "Christopher Nolan", 148, "PG-13");
    library[2] = new CD("Thriller", "1982", "C001", "Epic Records",
                         "Michael Jackson", 9, "Pop");


    for (int i = 0; i < 3; i++) {
        library[i]->displayInfo();
        cout << endl;
    }


    library[0]->checkOut();
    library[0]->checkOut();
    library[0]->returnItem();

    cout << "\nSearch 'Inception' by title: "
         << (library[1]->search("Inception") ? "Found" : "Not Found") << endl;
    cout << "Search by year 1982: "
         << (library[2]->search(1982) ? "Found" : "Not Found") << endl;

    for (int i = 0; i < 3; i++) delete library[i];
    return 0;
}