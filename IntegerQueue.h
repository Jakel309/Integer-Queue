#include <iostream>

class IntegerQueue{
	public:
		void push(int val);
		int pop();
		bool empty() const;
		int size() const;
		IntegerQueue();
		IntegerQueue(const IntegerQueue&);
		~IntegerQueue();
		friend std::ostream& operator<<(std::ostream& lhs, const IntegerQueue& rhs);
		IntegerQueue& operator=(const IntegerQueue& rhs);
	private:
		int* queue;
		int qSize;
		int head;
		int tail;
};