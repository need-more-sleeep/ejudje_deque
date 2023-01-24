#include <regex>
#include <iostream>
class Deque {

	std::string* data;
	int size;
	int capacity;
	int head;
	int tail;
public:

	Deque() :capacity(0), size(0), head(-1), tail(0), data(nullptr) {}

	~Deque()
	{
		delete[] data;
	}

	void set_size(int size_) {
		capacity = size_;
		tail = capacity;
		data = new std::string[capacity];
	}

	void print() {
		if (size == 0) {
			std::cout << "empty\n";
			return;
		}
		if (head <= tail) {
			for (size_t i = head; i <= tail; i++)
			{
				std::cout << data[i];
				if (i < tail) {
					std::cout << " ";
				}
			}
		}
		else if (head > tail) {
			for (size_t i = head; i < capacity; i++)
			{
				std::cout << data[i] << " ";
			}
			for (size_t i = 0; i <= tail; i++)
			{
				std::cout << data[i];
				if (i < tail) {
					std::cout << " ";
				}
			}
		}
		std::cout << "\n";
	}

	void pushb(std::string num) {
		if (size == capacity) {
			std::cout << "overflow\n";
			return;
		}
		if (size == 0) {
			head = tail = capacity / 2;
		}
		else if (tail == capacity - 1) {
			tail = 0;
		}
		else {
			++tail;
		}
		data[tail] = num;
		++size;
	}

	void pushf(std::string num) {
		if (size == capacity) {
			std::cout << "overflow\n";
			return;
		}
		if (size == 0) {
			head = tail = capacity / 2;
		}
		else if (head == 0) {
			head = capacity - 1;
		}
		else {
			--head;
		}
		data[head] = num;
		++size;
	}

	std::string popb() {
		if (size == 0) {
			return "";
		}
		if (tail == 0) {
			std::string res = data[tail];
			tail = capacity - 1;
			--size;
			return res;
		}
		else if (size == 1) {
			std::string res = data[tail];
			head = -1;
			tail = capacity;
			--size;
			return res;
		}
		else {
			--size;
			return data[tail--];
		}
	}

	std::string popf() {
		if (size == 0) {
			return "";
		}
		if (head == capacity - 1) {
			std::string res = data[head];
			head = 0;
			--size;
			return res;
		}
		else if (size == 1) {
			std::string res = data[tail];
			head = -1;
			tail = capacity;
			--size;
			return res;
		}
		else {
			--size;
			return data[head++];
		}
	}

};


int main() {
	Deque d;

	std::regex regex_pushf("^pushf ([^ ]+)$");
	std::regex regex_pushb("^pushb ([^ ]+)$");

	std::regex regex_set_size("^set_size ([0-9]+)$");

	std::regex regex_popb("^popb$");
	std::regex regex_popf("^popf$");
	std::regex regex_print("^print$");

	std::smatch match;
	std::string str;

	bool set_size_found = false;

	while (std::getline(std::cin, str)) {
		if (str.empty()) {
			continue;
		}
		if (std::regex_match(str, match, regex_set_size)) {
			
			if (set_size_found) {
				std::cout << "error\n";
				continue;
			}
			int num = std::stoi(match[1]);
			d.set_size(num);
			set_size_found = true;
		}
		else if (!set_size_found) {
			std::cout << "error\n";
			continue;
		}
		else if (std::regex_match(str, match, regex_pushf)) {
			d.pushf(match[1]);
		}
		else if (std::regex_match(str, match, regex_pushb)) {
			d.pushb(match[1]);
		}
		else if (std::regex_match(str,match, regex_popb)) {
			std::string result = d.popb();
			if (result.empty()) {
				std::cout << "underflow\n";
			}
			else {
				std::cout << result << "\n";
			}
		}
		else if (std::regex_match(str, match, regex_popf)) {

			std::string result = d.popf();
			if (result.empty()) {
				std::cout << "underflow\n";
			}
			else {
				std::cout << result << "\n";
			}
		}
		else if (std::regex_match(str, match, regex_print)) {
			d.print();
		}
		else {
			std::cout << "error\n";
		}
	}
}




