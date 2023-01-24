#include <iostream>
#include <string>
#include <vector>

class deque {
	int size = 0;
	std::string* arr = nullptr;
	int capacity = 0;
	int head, tail; //индексы начала и конца
public:
	~deque()
	{
		delete[] arr;
	}

	void set_size(int N) {
		capacity = N;
		arr = new std::string[capacity];
	}

	void push_b(std::string& el) {
		if (capacity == size) {
			std::cout << "overflow" << std::endl;
			return;
		}
		if (size == 0) {
			head = tail = capacity / 2;
			arr[tail] = el;
		}
		else {
			tail = (tail + 1) % capacity;
			arr[tail] = el;
		}
		++size;
	}

	void push_f(std::string& el) {
		if (capacity == size) {
			std::cout << "overflow" << std::endl;
			return;
		}
		if (size == 0) {
			head = tail = capacity / 2;
			arr[head] = el;
		}
		else {
			head = (head - 1 + capacity) % capacity;
			arr[head] = el;
		}
		++size;
	}

	void pop_b() {
		if (size == 0) {
			std::cout << "underflow" << std::endl;
			return;
		}
		std::cout << arr[tail] << std::endl;;
		tail = (tail - 1 + capacity) % capacity;
		--size;
	}

	void pop_f() {
		if (size == 0) {
			std::cout << "underflow" << std::endl;
			return;
		}
		std::cout << arr[head] << std::endl;
		head = (head + 1) % capacity;
		--size;
	}

	void print() {
		if (size == 0) {
			std::cout << "empty\n";
			return;
		}

		int i = head;
		while (i != tail) {
			std::cout << arr[i] << " ";
			i = (i + 1) % capacity;
		}
		std::cout << arr[tail] << "\n";
	}

};


void split(std::string& line, std::vector<std::string>& split_line) {
	split_line.clear();
	std::string temp = "";
	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] != ' ') {
			temp += line[i];
		}
		else {
			split_line.push_back(temp);
			temp.clear();
		}
		if (i == line.length() - 1) {
			split_line.push_back(temp);
		}
	}
}

bool is_positive_num(std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i]>'9') {
			return false;
		}
	}
	return true;
}

int main() {

	deque d;
	std::string line;
	std::vector<std::string> split_line;
	while (std::getline(std::cin, line)) {
		if (line.empty()) {
			continue;
		}
		split(line, split_line);
		if (split_line[0] == "set_size" && split_line.size() == 2) {
			if (is_positive_num(split_line[1])) {
				d.set_size(std::stoi(split_line[1]));
				break;
			}
		}
		std::cout << "error\n";
	}
	while (std::getline(std::cin, line)) {
		if (line.empty()) {
			continue;
		}
		split(line, split_line);

		if (split_line[0] == "pushb" && split_line.size() == 2) {
			d.push_b(split_line[1]);
			continue;
		}
		if (split_line[0] == "pushf" && split_line.size() == 2) {
			d.push_f(split_line[1]);
			continue;
		}
		if (split_line[0] == "popf" && split_line.size() == 1) {
			d.pop_f();
			continue;
		}
		if (split_line[0] == "popb" && split_line.size() == 1) {
			d.pop_b();
			continue;
		}
		if (split_line[0] == "print" && split_line.size() == 1) {
			d.print();
			continue;
		}
		std::cout << "error\n";
	}
}