#include <cstddef>
#include <type_traits>
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class BSTNode
{
public:
	T Data;
	int Level;
	BSTNode *Left, *Right;
	BSTNode(T el) { Data = el; Left = Right = 0; }
};
template <class T>
class BST
{
private:
	BSTNode<T> *Root;
public:
	BST() { Root = 0; }
	BSTNode<T>* RetRoot() { return Root; }
	void insert(T el);
	void BFS();
	BSTNode<T>* Find(T El);
	BSTNode<T>* MaksBST();
	BSTNode<T>* MinBST();
	void BSTPrint();
	void SumNode();
}; template <typename T> void BST<T>::insert(T el)
{
	//zmienne pomocnicze - wskaünik p i prev. Wskaünik p
	//ustawiamy na korzeniu drzewa, wskaünik prev "za
	//korzeniem"
	BSTNode<T> *p = Root, *prev = 0;
	while (p != 0)/*przechodzimy drzewo od gÛry (od korzenia) do
	liúci*/
	{
		//wskaünik prev za kaødym razem wskazuje na wÍze≥
		prev = p;
		//wskaünik p wykorzystywany jest do badania dzieci
		if (p->Data < el)/*jeøeli element wstawiany jest
		wiÍkszy od elementu danego wÍz≥a...*/
			p = p->Right;//...przejdü na prawo
		else
			p = p->Left;//...jeøeli nie, przejdü na lewo
	}
	if (Root == 0) //jeøeli drzewo by≥o puste:
	{
		//element wstawiany staje siÍ korzeniem
		Root = new BSTNode<T>(el);
	}
	/*po przejúciu do ostatniego poziomu drzewa, element
	wstawiany jest we w≥aúciwe miejsce*/
	else if (prev->Data < el)
	{
		prev->Right = new BSTNode<T>(el);
	}
	else
	{
		prev->Left = new BSTNode<T>(el);
	}
}
template<class T>
inline void BST<T>::BFS()
{
	BSTNode<T>* v;
	queue<BSTNode<T>*> Q;
	Q.push(Root);
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		cout << v->Data << " ";
		if (v->Left) Q.push(v->Left);
		if (v->Right) Q.push(v->Right);
	}
}
//argumentem funkcji niech bÍdzie element szukany (Data)
//zwracany bÍdzie wskaünik na szukany wÍze≥
template<typename T> BSTNode<T>* BST<T>::Find(T El)
{
	//ustawiamy wskaünik pomocniczy na korzeniu
	BSTNode<T>* p = Root;
	//dopÛki nie wyjdziemy poza drzewo,
	//lub nie napotkamy szukanego elementu
	while (p != NULL && p->Data != El)
	{
		//jeøeli szukany element jest mniejszy
		//niø wartoúÊ w wÍüle
		if (p->Data > El)
			//przejdü na lewo
		{
			p = p->Left;
		}
		else
			//w przeciwnym wypadku przejdü na prawo
		{
			p = p->Right;
		}
	}
	return p;
}

template<class T>
inline BSTNode<T>* BST<T>::MaksBST()
{
	BSTNode<T> *p = Root;
	BSTNode<T> *c = 0;
	while (p != NULL)
	{
		p = p->Right;
		if (p == NULL) {
			break;
		}
		c = p;
	}
	return c;
}

template<class T>
inline BSTNode<T>* BST<T>::MinBST()
{

	BSTNode<T> *d = Root;
	BSTNode<T> *c = 0;
	while (d->Left!=NULL)
	{
		d = d->Left;
	}
	return d;
}

template<class T>
inline void BST<T>::BSTPrint()
{
	BFS();
}

template<class T>
inline void BST<T>::SumNode()
{
	BSTNode<T>* v;
	queue<BSTNode<T>*> Q;
	Q.push(Root);
	int suma = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		suma += v->Data;
		if (v->Left) Q.push(v->Left);
		if (v->Right) Q.push(v->Right);
	}
	cout << " suma: " << suma << endl;
}