#include<iostream>

using namespace std;

/*
** LinkedList 

struct Node
{
	Node* Front;
	int Value;
	Node* Back;
}; 


class Node
{
public:
	int Value;
};

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
	

	
	{
	cout << pList->Value << endl;
	cout << pList->Back->Value << endl;
	cout << pList->Back->Back->Value << endl;
	cout << pList->Back->Back->Back->Value << endl;
	}
	
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

*/

/*
template <typename T>
class Node
{
public:
	T Value;
};
template <typename T>
class List
{
private:
	Node<T> Value;
public:
	void Setter(const T _Value) { Value.Value = _Value; }
	T Getter() { return Value.Value; }
};


template <typename T>
class List
{
private:
	T Value;
public:
	void Setter(const T _Value) { Value.Value = _Value; }
	T Getter() { return Value.Value; }
};
class TempClass
{
public:
	template<typename T>
	T TemplateClass( T _Value)
	{
		return _Value;
	}
};
*/


template <typename T>
class Vector
{
private:
	T* Value;
	int m_size;
	int m_capacity;

public:
	void push_back(T _Value)
	{
		if (m_size == m_capacity)
		{
			if (m_capacity < 3)
				m_capacity += 1;
			else
				m_capacity += (m_capacity * 0.5f);


			int* Temp = new T[sizeof(T) * m_size];
			for (int i = 0; i < m_size; ++i)
				Temp[i] = Value[i];

			delete Value;

			Value = new T[sizeof(T) * m_capacity];

			for (int i = 0; i < m_size; ++i)
				Value[i] = Temp[i];
		}

		Value[m_size] = _Value;
		m_size += 1;
	}
	int size()const { return m_size; }
	int capacity()const { return m_capacity; }
	void Output(int _Where)
	{
		if (_Where <= m_size)
			cout << Value[_Where] << endl;
	}

	void Insert(int _Where, int _Value)
	{
		if (_Where <= m_size)
		{
			if (m_size <= m_capacity)
			{
				int* Temp = new T[sizeof(T) * m_size + 1];
				for (int i = _Where-1; i < m_size; ++i)
					Temp[i] = Value[i];

				Temp[_Where - 2] = _Value;

				for (int i = _Where - 1; i < m_size; ++i)
					Value[i] = Temp[i-1];
				m_size += 1;
			}
		}
	}
	void Delete()
	{
		Value[m_size - 1] = Value[m_size];
		m_size -= 1;
	}
	void Front() 
	{
		// ** 첫번쨰 원소를 가르킴
		cout << Value[0] << endl;
	}
	void Back()
	{
		// ** 마지막 원소를 가르킴
		cout << Value[m_size-1] << endl;
	}
	void Clear()
	{
		// ** 전체 삭제
		delete Value;
		Value = nullptr;
		m_size = 0;
		m_capacity = 0;

	}
	void Erase(int _Where)
	{
		// ** 원소 삭제
		if (_Where <= m_size)
		{
			int* Temp = new T[sizeof(T) * m_size+1];
			for (int i = _Where-1; i < m_size; ++i)
				Temp[i] = Value[i];
			
			for (int i = _Where-1; i < m_size; ++i)
				Value[i] = Temp[i+1];
			m_size -= 1;
		}
	}
public:
	Vector()
	{
		Value = new T[sizeof(T)];
		m_size = 0;
		m_capacity = 0;
	}
};
int main()
{
	/*
	 ** 템플릿은 클래스에 사용할경우 클래스 이름 뒤에 붙여 사용
	 ** class_name<DataType>
	Vector<int> VecTemp;
	VecTemp.Setter(10);

	cout << VecTemp.Getter() << endl;

	List<int> liTemp;
	liTemp.Setter(10);

	cout << liTemp.Getter() << endl;

	 ** 템플릿은 함수에 사용할경우 함수 이름 뒤에 붙여 사용
	TempClass TC;
	cout << TC.TemplateClass<int>(10) << endl;
	*/

	int* Array = new int;

	Vector<int> vecNumbers;
	for (int i = 0; i < 10; i++)
	{
		vecNumbers.push_back(10 * i + 10);
	}
	vecNumbers.Front();
	cout<< endl;
	vecNumbers.Back();
	cout<< endl;
	vecNumbers.Insert(3, 25);
	vecNumbers.Erase(5);
	vecNumbers.Delete();
	for (int i = 0; i < 10; i++)
	{
		vecNumbers.Output(i);
		cout << endl;
	}
	vecNumbers.Clear();
	cout << "test" << endl;
	vecNumbers.Output(1);
	vecNumbers.Output(5);

	return 0;
}