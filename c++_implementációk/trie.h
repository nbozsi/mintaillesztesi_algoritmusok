#include <unordered_map>
using namespace std;
// TODO hiba élek gyors létrehozása
class Node
{
public:
    Node(char value);
    Node();
    // ÁLLANDOK
    char betu;
    string szo_veg = "";
    unordered_map<char, Node *> gyerek;
    Node *hiba = nullptr;
    // FÜGGVÉNYEK
    Node *lepes(char b);
};

Node::Node(char value)
{
    betu = value;
}
Node::Node()
{
    betu = '.';
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
