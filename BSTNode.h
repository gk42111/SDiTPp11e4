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
	//zmienne pomocnicze - wska�nik p i prev. Wska�nik p
	//ustawiamy na korzeniu drzewa, wska�nik prev "za
	//korzeniem"
	BSTNode<T> *p = Root, *prev = 0;
	while (p != 0)/*przechodzimy drzewo od g�ry (od korzenia) do
	li�ci*/
	{
		//wska�nik prev za ka�dym razem wskazuje na w�ze�
		prev = p;
		//wska�nik p wykorzystywany jest do badania dzieci
		if (p->Data < el)/*je�eli element wstawiany jest
		wi�kszy od elementu danego w�z�a...*/
			p = p->Right;//...przejd� na prawo
		else
			p = p->Left;//...je�eli nie, przejd� na lewo
	}
	if (Root == 0) //je�eli drzewo by�o puste:
	{
		//element wstawiany staje si� korzeniem
		Root = new BSTNode<T>(el);
	}
	/*po przej�ciu do ostatniego poziomu drzewa, element
	wstawiany jest we w�a�ciwe miejsce*/
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
//argumentem funkcji niech b�dzie element szukany (Data)
//zwracany b�dzie wska�nik na szukany w�ze�
template<typename T> BSTNode<T>* BST<T>::Find(T El)
{
	//ustawiamy wska�nik pomocniczy na korzeniu
	BSTNode<T>* p = Root;
	//dop�ki nie wyjdziemy poza drzewo,
	//lub nie napotkamy szukanego elementu
	while (p != NULL && p->Data != El)
	{
		//je�eli szukany element jest mniejszy
		//ni� warto�� w w�le
		if (p->Data > El)
			//przejd� na lewo
		{
			p = p->Left;
		}
		else
			//w przeciwnym wypadku przejd� na prawo
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