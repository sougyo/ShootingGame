#ifndef ___TABLE_H
#define ___TABLE_H

namespace gameutil {
	template <typename> class Table;
}

template <typename Type>
class gameutil::Table {
private:
	int maxSize;
	int size;
	bool isActive_;
	Type** tableElements;

private:
	Table(const gameutil::Table<Type>&);
	gameutil::Table<Type>& operator=(const gameutil::Table<Type>&);
	
public:
	explicit Table(int);
	~Table(void);
	
	void add(Type*, int, int);
	void clear(void);
	void move(void);
	void draw(void);
	Type** getArray(void);
	
	inline bool isActive(void) const { return isActive_; }
	inline int getSize(void) { return size; }
};

template <typename Type>
gameutil::Table<Type>::Table(int maxSize) : maxSize(maxSize), size(0) {
	tableElements = new Type*[maxSize];
	for (int i = 0; i < maxSize; i++)
		tableElements[i] = 0 /* NULL */;
}

template <typename Type>
gameutil::Table<Type>::~Table(void) {
	delete[] tableElements;
}

template <typename Type>
void gameutil::Table<Type>::add(Type* tableElement, int x, int y) {
	isActive_ = true;
	for (int i = 0; i < maxSize; i++) {
		if (tableElements[i] == 0 /* NULL */) {
			if (size <= i)
				size = i + 1;
			tableElements[i] = tableElement;
			tableElement->fire(x, y);
			return;
		}
	}
}

template <typename Type>
void gameutil::Table<Type>::clear(void) {
	for (int i = 0; i < size; i++)
		tableElements[i] = 0;
	size = 0;
	isActive_ = false;
}

template <typename Type>
void gameutil::Table<Type>::move(void) {
	if (isActive_) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (tableElements[i] == 0/* NULL */)
				continue;
			if (!tableElements[i]->isActive()) {
				tableElements[i] = 0/* NULL */;
				continue;
			}
			tableElements[i]->move();
			count++;
		}
		if (count == 0) {
			isActive_ = false;
			size = 0;
		}
	}
}

template <typename Type>
void gameutil::Table<Type>::draw(void) {
	if (isActive_) {
		for (int i = 0; i < size; i++) {
			if (tableElements[i] != 0/* NULL */)
				tableElements[i]->draw();
		}
	}
}

template <typename Type>
Type** gameutil::Table<Type>::getArray(void) {
	return tableElements;
}

#endif // ___TABLE_H
