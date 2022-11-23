#include <map>
using namespace std;
// TODO failure élek gyors létrehozása
class Node
{
public:
    Node(char value, bool veg);
    Node();
    // ÁLLANDOK
    char betu;
    bool szoveg;
    map<char, Node *> gyerek;
    Node *hiba;
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
}
Node *Node::lepes(char b)
{
    if (gyerek.find(b) == gyerek.end())
    {
        return gyerek[b];
    }
    return hiba;
}
