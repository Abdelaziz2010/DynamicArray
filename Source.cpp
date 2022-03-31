#include<iostream>
using namespace std;
template <class T>
class ArrayList
{
private:
	T* data;
	int index;
	int size;
	void ReGrow()
	{
		int newsize = size + 10;
		T* temp = new T[newsize];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[]data;
		data = temp;
		size = newsize;
	}
public:
	ArrayList()
	{
		data = NULL;
		size = 0;
		index = 0;
	}
	ArrayList(int size)
	{
		data = new T[size];
		index = 0;
		this->size = size;
	}
	~ArrayList()
	{
		if (data)
		{
			delete[]data;
			data = NULL;
		}
	}
	void Add(T value)
	{
		if (index==size)
		{
			ReGrow();
		}
		data[index++] = value;
	}
	T& operator [](int index)
	{
		return data[index];
	}
	T& GetItem()
	{
		return data[index];
	}
	void DeleteItem(int loc)
	{
		if (loc < 0 || loc >= this->index)
		{
			throw exception("out of bound of the array!!!");
		}
		for (int i = loc; i < index; i++)
		{
			data[i] = data[i + 1];
		}
		index--;
	}
	int GetSize()
	{
		return this->size;
	}
	int GetCount()
	{
		return this->index;
	}
};
int main()
{
	ArrayList<int> l(5);
	while (true)
	{
		cout << "please enter number and enter -1 to terminate: " << endl;
		int n;
		cin >> n;
		if (n == -1)
			break;
		l.Add(n);
	}
	l.DeleteItem(2);
	for (int i = 0; i < l.GetCount(); i++)
	{
		cout << l[i] << endl;
	}
	 
	
	return 0;
}