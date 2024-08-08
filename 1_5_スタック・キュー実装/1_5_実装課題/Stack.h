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
    using ConstIterator = typename DoublyLinkedList<T>::ConstIterator;
    using Iterator = typename DoublyLinkedList<T>::Iterator;

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
     * @return ポップが成功するとtrue、リストが空だとfalse
     */
    bool pop();

    /**
     * @brief スタックの先頭イテレータを取得する
     * @return 先頭イテレータ
     */
    Iterator GetBegin();

    /**
     * @brief スタックの先頭コンストイテレータを取得する
     * @return 先頭コンストイテレータ
     */
    ConstIterator GetBeginConst() const;

    /**
     * @brief スタックの終端イテレータを取得する
     * @return 終端イテレータ
     */
    Iterator GetEnd();

    /**
     * @brief スタックの終端コンストイテレータを取得する
     * @return 終端コンストイテレータ
     */
    ConstIterator GetEndConst() const;
};

#include "Stack.inl"