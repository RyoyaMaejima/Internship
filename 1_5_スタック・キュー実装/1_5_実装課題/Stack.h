#include "DoublyLinkedList.h"

/**
 * @brief スタックを実装するクラス
 * @tparam T スタックに格納するデータ型
 */
template<typename T>
class Stack {
private:
    DoublyLinkedList<T> list;

public:
    /**
     * @brief スタックのデータ数を取得する
     * @return データ数
     */
    int GetDataNum() const;

    /**
     * @brief スタックにデータをプッシュする
     * @param data プッシュするデータ
     * @return プッシュが成功するとtrue、失敗するとfalse
     */
    bool push(const T& data);

    /**
     * @brief スタックからデータをポップする
     * @param data ポップしたデータを格納する変数
     * @return ポップが成功するとtrue、リストが空だとfalse
     */
    bool pop(T& data);
};

#include "Stack.inl"