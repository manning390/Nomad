template<class T>
class Stack {
public:
    Stack(const std::initializer_list<T>& i):elem(i) {}
    int size() const { return elem.size(); }
    bool empty() const { return elem.empty();}
    void push(const T&);
    T pop();
    T peek();
private:
    std::vector<T> elem;
};


template<class T>
void Stack<T>::push(const T& t) {
    elem.push_back(t);
}

template<class T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("underflow");
    }
    auto x = elem.back();
    elem.pop_back();
    return x;
}

template<class T>
T Stack<T>::peek() {
    if (empty()) {
        throw std::out_of_range("underflow");
    }
    return elem.back();
}