#include <iostream>
#include <string>
using namespace std;
/*=============================== Double Linked List ===============================*/
typedef int elementType;
struct Node
{
    elementType Data;
    Node* Next;
    Node* Previous;
};

typedef Node* Position;
class DB_Linked_List
{
private:
    Position Head;
    Position Tail;
    int counter;
public:
    DB_Linked_List()
    {
        MAKENULL();
    }
    void MAKENULL()
    {
        Head = NULL;
        Tail = NULL;
        counter = 0;
    }
    Position FIRST()
    {
        return Head;
    }
    Position END()
    {
        return Tail;
    }
    void INSERT(elementType x, Position p)
    {
        Position new_node = new Node;
        new_node->Data = x;
        if (Head == NULL)
        {
            Head = Tail = new_node;
            new_node->Next = new_node->Previous = NULL;
        }
        else if (p == Head)
        {
            new_node->Next = Head;
            new_node->Previous = NULL;
            Head->Previous = new_node;
            Head = new_node;
        }
        else if (p == Tail || p == NULL)
        {
            new_node->Next = NULL;
            new_node->Previous = Tail;
            Tail->Next = new_node;
            Tail = new_node;
        }
        else
        {
            new_node->Next = p;
            new_node->Previous = p->Previous;
            p->Previous->Next = new_node;
            p->Previous = new_node;
        }
        counter++;
    }
    void DELETE(Position p)
    {
        if (p == NULL)
        {
            cout << "Error : NO Elements To Delete\n";
            return;
        }
        if (p == Head)
        {
            Head = Head->Next;
            Head->Previous = NULL;
        }
        else if (p == Tail)
        {
            Tail = Tail->Previous;
            Tail->Next = NULL;
        }
        else
        {
            p->Previous->Next = p->Next;
            p->Next->Previous = p->Previous;
        }
        delete p;
        counter--;
    }

    void PRINT()
    {
        Position temp = Head;
        while (temp != NULL)
        {
            cout << temp->Data << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
    int SIZE()
    {
        return counter;
    }
    Position NEXT(Position p)
    {
        if (p == Tail || p == NULL)
        {
            cout << "Nothing Next\n";
            return NULL;
        }
        return p->Next;
    }
    Position PREVIOUS(Position p)
    {
        if (p == Head || p == NULL)
        {
            cout << "Nothing Previous\n";
            return NULL;
        }
        return p->Previous;
    }
    elementType RETRIEVE(Position p)
    {
        if (p == NULL)
        {
            cout << "Invalid Position\n";
            return -1;
        }
        return p->Data;
    }
    Position LOCATE(elementType x)
    {
        Position temp = Head;
        while (temp != NULL)
        {
            if (temp->Data == x)
            {
                return temp;
            }
            temp = temp->Next;
        }
        return NULL;
    }
};
int main()
{
    DB_Linked_List L;
    L.INSERT(1, L.FIRST());
    L.INSERT(2, L.FIRST());
    L.INSERT(3, L.END());
    L.INSERT(4, L.FIRST());
    L.INSERT(5, L.END());
    L.INSERT(6, L.FIRST());
    L.INSERT(7, L.END());
    L.INSERT(8, L.END());
    L.INSERT(9, L.END());
    L.INSERT(10, L.END());
    L.INSERT(11, L.FIRST());
    cout << "The Data In List : \n";
    L.PRINT();
    cout << "The Size Of The List = " << L.SIZE() << endl;
    cout << "The List After Deleting The First Node: \n";
    L.DELETE(L.FIRST());
    L.PRINT();
    cout << "The Size After Delete The Element = " << L.SIZE() << endl;
    cout << "The Data In Last Node = " << L.RETRIEVE(L.END()) << endl;
    cout << "The Data In First Node = " << L.RETRIEVE(L.FIRST()) << endl;
    int x;
    cout << "Enter An Element To Return It's Position\n";
    cin >> x;
    Position position = L.LOCATE(x);
    if (position)
    {
        cout << "The Element " << x << " Is Found In The List" << endl;
    }
    else
    {
        cout << "The Element " << x << " Does Not Existing In The List" << endl;
    }
    return 0;
}



