#include "DoublyLinkedList.h"

/**
 * @brief キューを実装するクラス
 * @tparam T キューに格納するデータ型
 */
template<typename T>
class Queue {
private:
    DoublyLinkedList<T> list;

public:
    /**
     * @brief データ数の取得
     * @return データ数
     */
    int GetDataNum() const;

    /**
     * @brief キューにデータをエンキューする
     * @param data エンキューするデータ
     * @return エンキューが成功するとtrue、失敗するとfalse
     */
    bool enqueue(const T& data);

    /**
     * @brief キューからデータをデキューする
     * @return デキューが成功するとtrue、リストが空だとfalse
     */
    bool dequeue();
};

#include "Queue.inl"
