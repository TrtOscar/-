#include<iostream>
#include<cassert>
using namespace std;

class Person {
public:
	string name;
	int age;
public:
	Person() {
		name = "trt";
		age = 18;
		cout << "���캯��" << endl;
	}
	~Person() {
		cout << "��������" << endl;
	}
};

template<class T>
class smartPointer {
private:
	T* _ptr;
	size_t* _count;
public:
	smartPointer(T* p = nullptr) {
		_ptr = p;
		if (p==nullptr) {
			_count = new size_t(0);
		}
		else {
			_count = new size_t(1);
		}
	}
	smartPointer(smartPointer& sp) {
		_ptr = sp._ptr;
		_count = sp._count;
		(*_count)++;
	}
	T* operator->() {
		assert(_ptr != nullptr);
		return _ptr;
	}
	T& operator*() {
		assert(_ptr != nullptr);
		return *_ptr;
	}
	size_t use_count() {
		return *_count;
	}
	~smartPointer() {
		if (_ptr == nullptr) {
			cout << "ָ��Ϊ��" << endl;
			delete _count;
			return;
		}
		(*_count)--;
		if (*_count == 0) {
			delete _ptr;
			delete _count;
			cout << "����ָ��������ͷ�" << endl;
		}
	}
};

int main() {
	smartPointer<Person> sp(new Person());
	cout << sp->name << endl;
	cout << (*sp).age << endl;
	cout << sp.use_count() << endl;
	smartPointer<Person> sp2(sp);
	cout << sp.use_count() << endl;
}