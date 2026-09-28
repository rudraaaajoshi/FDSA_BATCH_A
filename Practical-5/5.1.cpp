#include <iostream>
using namespace std;

struct Node {
    string song;
    Node *prev, *next;
};

Node *head = NULL;

// Add at beginning
void addBeginning(string song) {
    Node *n = new Node;
    n->song = song;
    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

// Add at end
void addEnd(string song) {
    Node *n = new Node;
    n->song = song;
    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// Insert after a given song
void insertAfter(string given, string song) {
    Node *temp = head;

    while (temp != NULL && temp->song != given)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Song not found\n";
        return;
    }

    Node *n = new Node;
    n->song = song;

    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

// Remove first song
void removeFirst() {
    if (head == NULL) {
        cout << "Playlist is empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Count songs
int countSongs() {
    int count = 0;
    Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Display
void display() {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->song << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
    cout << "Total songs = " << countSongs() << "\n";
}

int main() {

    addBeginning("Song A");
    display();

    addEnd("Song B");
    display();

    insertAfter("Song A", "Song C");
    display();

    removeFirst();
    display();

    return 0;
}