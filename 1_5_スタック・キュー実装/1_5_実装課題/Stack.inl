template<typename T>
int Stack<T>::GetDataNum() const {
    return list.GetDataNum();
}

template<typename T>
bool Stack<T>::push(const T& data) {
    bool success = list.Insert(list.GetEnd(), data);
    return success;
}

template<typename T>
bool Stack<T>::pop(T& data) {
    if (list.GetDataNum() == 0) return false;
    
    auto it = --list.GetEnd();
    data = *it;
    bool success = list.Erase(it);
    return success;
}