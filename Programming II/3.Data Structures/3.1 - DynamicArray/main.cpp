#include <iostream>
using namespace std;

#define DYNAMIC_ARRAY_CHUNK_SIZE 5
#define DYNAMIC_ARRAY_INITIAL_CAPACITY 5

class DynamicArray {
private:
	int* mArray = nullptr;
	unsigned int mCapacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;
	unsigned int mSize = 0;

	void IncreaseCapacity() {
		mCapacity += DYNAMIC_ARRAY_CHUNK_SIZE;
		int* arr = new int[mCapacity];
		for (int i = 0; i < mSize; ++i) {
			arr[i] = mArray[i];
		}
		delete[] mArray;
		mArray = arr;
	}

public:
	DynamicArray() {
		mArray = new int[mCapacity];
	}
	~DynamicArray(){
		delete[] mArray;
	}

	void push_back(int elem) {
		insert(mSize, elem);
	}
	void push_front(int elem) {
		insert(0, elem);
	}
	void insert(int index, int elem) {
		if (mSize == mCapacity) {
			IncreaseCapacity();
		}
		for (int i = mSize; i > index; --i) {
			mArray[i] = mArray[i - 1];
		}
		mArray[index] = elem;
		mSize++;
	}
	void erase(int index) {
		for (int i = index; i < mCapacity - 1; ++i) {
			mArray[i] = mArray[i + 1];
		}
		mSize--;
	}
	void clear(){
		mSize = 0; //The array is not deleted, in fact, not even the numbers on it, with mSize = 0 we indicate that we are not using any of the elements

	}
	void printArray() {
		for (int i = 0; i < mSize; ++i) {
			cout << mArray[i] << " ";
		}
		cout << endl;
	}

	int& operator[](unsigned int index) {
		return mArray[index];
	}
	const int& operator[](unsigned int index) const {
		return mArray[index];
	}

	bool empty() const {
		if (mSize == 0) return true;
		else			return false;
	}
	unsigned int size() const {
		return mSize;
	}

	void shrink_to_fit() {
		mCapacity = mSize;
		while (mCapacity % DYNAMIC_ARRAY_CHUNK_SIZE != 0) {
			mCapacity++;
		}
	}
	unsigned int GetCapacity() const{
		return mCapacity;
	}
};

int main() {
	DynamicArray a;
	a.push_back(1);
	a.printArray();
	a.push_back(2);
	a.printArray();
	a.push_back(3);
	a.printArray();
	a.push_front(69);
	a.printArray();
	a.insert(2, 70);
	a.printArray();
	a.erase(3);
	cout << a[2] << endl;
	a.printArray();
	cout << "Empty? " << a.empty() << endl;
	cout << "Size? " << a.size() << endl << endl;
	a.clear();
	cout << "Empty? " << a.empty() << endl;
	cout << "Size? " << a.size() << endl << endl;
	a.printArray();
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.printArray();
	a.erase(3);
	a.erase(3);
	a.erase(3);
	a.erase(3);
	a.erase(3);
	a.erase(3);
	a.erase(3);
	a.erase(3);
	a.erase(3);
	a.erase(3);
	a.printArray();
	cout << a.GetCapacity() << endl;
	a.shrink_to_fit();
	cout << a.GetCapacity() << endl;
}