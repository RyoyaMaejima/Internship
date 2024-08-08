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
bool Stack<T>::pop() {
    if (list.GetDataNum() == 0) return false;

    bool success = list.Erase(--list.GetEnd());
    return success;
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::GetBegin() {
    return list.GetBegin();
}

template<typename T>
typename Stack<T>::ConstIterator Stack<T>::GetBeginConst() const {
    return list.GetBegin();
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::GetEnd() {
    return list.GetEnd();
}

template<typename T>
typename Stack<T>::ConstIterator Stack<T>::GetEndConst() const {
    return list.GetEnd();
}