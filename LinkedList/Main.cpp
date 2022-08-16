#include<iostream>

using namespace std;

struct Node
{
	Node* Front;
	int Value;
	Node* Back;
}; 

/*
class Node
{
public:
	int Value;
};
*/
void Output(Node* _pList);
void Output2(Node* _pList);
void push_back(Node* _pList, int _Value);
void Delete(Node* _pList);
void Delete2(Node* _pList, int _Where);
void Insert(Node* _pList, int _Where, int _Value);

int Size=0;

int main()
{
	Node* pList = new Node;
	pList->Front = nullptr;
	pList->Value = 10;
	pList->Back = nullptr;
	int number = 0;
	/*
	{
		pList->Back = new Node;
		pList->Back->Value = 20;
		pList->Back->Back = nullptr;
	}

	{
		pList->Back->Back = new Node;
		pList->Back->Back->Value = 30;
		pList->Back->Back->Back = nullptr;
	}

	{
		pList->Back->Back->Back = new Node;
		pList->Back->Back->Back->Value = 40;
		pList->Back->Back->Back->Back = nullptr;
	}
	*/

	/*
	{
	cout << pList->Value << endl;
	cout << pList->Back->Value << endl;
	cout << pList->Back->Back->Value << endl;
	cout << pList->Back->Back->Back->Value << endl;
	}
	*/
	for (int i = 0; i < 5; i++)
	{
		push_back(pList, (i + 2) * 10);
	}
	Delete2(pList, 3);
	Delete2(pList, 3);
	Delete2(pList, 3);
	Output(pList);
	Insert(pList, 2, 15);
	Output2(pList);

	return 0;
}

void Output(Node* _pList)
{
	cout << _pList->Value << endl;
	if (_pList->Back != nullptr)
		Output(_pList->Back);
}

void Output2(Node* _pList)
{
	Node* pNode=_pList;

	while (true)
	{
		if (pNode != nullptr)
		{
			cout << pNode->Value << endl;
			pNode = pNode->Back;
		}
		else
			break;
	}
}

void push_back(Node* _pList,int _Value)
{
	/*
	if (_pList->Back == nullptr)
	{
		Node* pNode = new Node;
		
		pNode->Front = _pList;
		pNode->Value = _Value;
		pNode->Back = nullptr;

		_pList->Back = pNode;
		Size += 1;
	}
	else	
		push_back(_pList->Back, _Value);
	*/
	Node* pNode = _pList;
	Node* pInNode = new Node;

	while (true)
	{
		if (pNode->Back == nullptr)
		{
			pInNode->Front = pNode;
			pInNode->Value = _Value;
			pInNode->Back = nullptr;

			pNode->Back = pInNode;
			pNode = pInNode;
			Size += 1;
		}
		else
			break;
	}
}

void Delete(Node* _pList)
{
	if (_pList->Back != nullptr)
	{
		delete _pList->Back;
		_pList->Back = nullptr;
	}
}

void Delete2(Node* _pList, int _Where)
{
	if (Size >= _Where && _Where == 1)
	{
		_pList->Front->Back = _pList->Back;
		_pList->Back->Front = _pList->Front;

		delete _pList;
	}
	else
		Delete2(_pList->Back, _Where - 1);
}

void Insert(Node* _pList, int _Where, int _Value)
{
	if (Size >= _Where && _Where == 1)
	{
		Node* pNode = new Node;

		pNode->Front = _pList->Front;
		pNode->Value = _Value;
		pNode->Back = _pList;

		_pList->Front->Back = pNode;
		_pList->Front = pNode;

		Size += 1;
	}
	else
		Insert(_pList->Back, _Where - 1, _Value);
}
