template<typename T>
int Queue<T>::GetDataNum() const {
    return list.GetDataNum();
}

template<typename T>
bool Queue<T>::enqueue(const T& data) {
    bool success = list.Insert(list.GetEnd(), data);
    return success;
}

template<typename T>
bool Queue<T>::dequeue(T& data) {
    if (list.GetDataNum() == 0) return false;
    
    auto it = list.GetBegin();
    data = *it;
    bool success = list.Erase(it);
    return success;
}