template<typename K, typename V, typename HF, size_t BucketSize>
HashTable<K, V, HF, BucketSize>::HashTable() : dataNum(0) {}

template<typename K, typename V, typename HF, size_t BucketSize>
size_t HashTable<K, V, HF, BucketSize>::GetDataNum() const {
    return dataNum;
}

template<typename K, typename V, typename HF, size_t BucketSize>
bool HashTable<K, V, HF, BucketSize>::Insert(const K& key, const V& value) {
    size_t index = hashFunction(key);
    DoublyLinkedList<Pair<K, V>>& bucket = table[index];
    for (auto it = bucket.GetBegin(); it != bucket.GetEnd(); ++it) {
        if ((*it).key == key) return false;
    }
    bool success = bucket.Insert(bucket.GetEnd(), Pair<K, V>(key, value));
    ++dataNum;
    return success;
}

template<typename K, typename V, typename HF, size_t BucketSize>
bool HashTable<K, V, HF, BucketSize>::Erase(const K& key) {
    size_t index = hashFunction(key);
    DoublyLinkedList<Pair<K, V>>& bucket = table[index];
    for (auto it = bucket.GetBegin(); it != bucket.GetEnd(); ++it) {
        if ((*it).key == key) {
            bool success = bucket.Erase(it);
            --dataNum;
            return success;
        }
    }
    return false;
}

template<typename K, typename V, typename HF, size_t BucketSize>
bool HashTable<K, V, HF, BucketSize>::Search(const K& key, V& value) {
    size_t index = hashFunction(key);
    DoublyLinkedList<Pair<K, V>>& bucket = table[index];
    for (auto it = bucket.GetBegin(); it != bucket.GetEnd(); ++it) {
        if ((*it).key == key) {
            value = (*it).value;
            return true;
        }
    }
    return false;
}