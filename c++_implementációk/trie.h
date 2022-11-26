#include <map>
using namespace std;
// TODO hiba élek gyors létrehozása
class Node
{
public:
    Node(char value, bool veg);
    Node();
    // ÁLLANDOK
    char betu;
    bool szoveg;
    map<char, Node *> gyerek;
    Node *hiba = nullptr;
    // FÜGGVÉNYEK
    Node *lepes(char b);
};

Node::Node(char value, bool veg)
{
    betu = value;
    szoveg = veg;
}
Node::Node()
{
    betu = '.';
    szoveg = false;
    hiba = this;
}
Node *Node::lepes(char b)
{
    if (gyerek.find(b) == gyerek.end())
    {
        return hiba;
    }
    return gyerek[b];
}
