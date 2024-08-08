#pragma once

#include <functional>

/**
 * @brief 双方向リストクラス
 * @tparm T リストに格納するデータ型
 */
template<typename T>
class DoublyLinkedList {
private:
    /**
     * @brief ノード
     */
    struct Node {
        T data;  /**< データ */
        Node* prev;       /**< 前のノードへのポインタ */
        Node* next;       /**< 次のノードへのポインタ */

        /**
         * @brief コンストラクタ
         * @param rd 格納するデータ
         */
        Node(const T& rd);
    };

    Node* head;  /**< リストの先頭 */
    Node* tail;  /**< リストの末尾 */
    int dataNum;    /**< データ数 */

public:
    /**
     * @brief 双方向リストの定数イテレータクラス
     */
    class ConstIterator {
    public:
        Node* current;  /**< 現在のノード */
        const DoublyLinkedList* list; /**< 所属リストへのポインタ */

        /**
         * @brief コンストラクタ
         * @param node 現在のノード
         * @param list 所属するリスト
         */
        ConstIterator(Node* node, const DoublyLinkedList* list);

        /**
         * @brief コピーコンストラクタ
         * @param other 他のイテレータ
         */
        ConstIterator(const ConstIterator& other);

        /**
         * @brief リストの先頭に向かって一つ進める
         * @return データへの参照
         */
        ConstIterator& operator--();

        /**
        * @brief リストの先頭に向かって一つ進める
        * @return データへの参照
        */
        ConstIterator operator--(int);

        /**
         * @brief リストの末尾に向かって一つ進める
         * @return データへの参照
         */
        ConstIterator& operator++();

        /**
         * @brief リストの末尾に向かって一つ進める
         * @return データへの参照
         */
        ConstIterator operator++(int);

        /**
         * @brief イテレータの指す要素を取得する
         * @return データへの定数参照
         */
        const T& operator*() const;

        /**
         * @brief 代入を行う
         * @param other 他のイテレータ
         */
        void operator=(const ConstIterator& other);

        /**
         * @brief 同一か比較する
         * @param other 比較対象のイテレータ
         * @return 同一ならtrue、異なればfalse
         */
        bool operator==(const ConstIterator& other) const;

        /**
         * @brief 異なるか比較する
         * @param other 比較対象のイテレータ
         * @return 異なればtrue、同一ならfalse
         */
        bool operator!=(const ConstIterator& other) const;
    };

    /**
     * @brief 双方向リストのイテレータクラス
     */
    class Iterator : public ConstIterator {
    public:
        /**
         * @brief コンストラクタ
         * @param node 現在のノード
         * @param list 所属するリスト
         */
        Iterator(Node* node, const DoublyLinkedList* list);

        /**
         * @brief リストの先頭に向かって一つ進める
         * @return データへの参照
         */
        Iterator& operator--();

        /**
        * @brief リストの先頭に向かって一つ進める
        * @return データへの参照
        */
        Iterator operator--(int);

        /**
         * @brief リストの末尾に向かって一つ進める
         * @return データへの参照
         */
        Iterator& operator++();

        /**
         * @brief リストの末尾に向かって一つ進める
         * @return データへの参照
         */
        Iterator operator++(int);

        /**
         * @brief イテレータの指す要素を取得する
         * @return データへの参照
         */
        T& operator*();
    };

    /**
     * @brief コンストラクタ
     */
    DoublyLinkedList();

    /**
     * @brief データ数の取得
     * @return データ数
     */
    int GetDataNum() const;

    /**
     * @brief データの挿入
     * @param iter 挿入位置のイテレータ
     * @tparam data 挿入するデータ
     * @return 挿入が成功すればtrue、別のリストのイテレータを指定するとfalse
     */
    bool Insert(const Iterator& iter, const T& data);

    /**
     * @brief データの削除
     * @param iter 削除する位置のイテレータ
     * @return 削除が成功すればtrue、イテレータがnullまたは別のリストのイテレータを指定するとfalse
     */
    bool Erase(const Iterator& iter);

    /**
     * @brief リストの先頭イテレータを取得する
     * @return 先頭イテレータ
     */
    Iterator GetBegin();

    /**
     * @brief 先頭コンストイテレータ取得
     * @return 先頭コンストイテレータ
     */
    ConstIterator GetBeginConst() const;

    /**
     * @brief 終端イテレータ取得
     * @return 終端イテレータ
     */
    Iterator GetEnd();

    /**
     * @brief 終端コンストイテレータ取得
     * @return 終端コンストイテレータ
     */
    ConstIterator GetEndConst() const;

    /**
     * @brief デストラクタ
     */
    ~DoublyLinkedList();
};

#include "DoublyLinkedList.inl"
