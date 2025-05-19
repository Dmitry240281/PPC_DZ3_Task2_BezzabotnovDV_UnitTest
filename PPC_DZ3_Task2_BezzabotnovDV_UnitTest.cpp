// Задание 2 Проверка функций добавления и получения элементов из двусвязного списка
//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <cstdint>

#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

//юнит-тест
TEST_CASE("Empty are computed", "[Empty]") {
    ListNode L1(2);
    ListNode L2(6);
    ListNode LN(1, &L1, &L2);
    List L;
    SECTION("Test List 1") {
        L.PushFront(5);
        L.PushBack(3);
        CHECK(L.PopFront() == 5);
        CHECK(L.PopBack() == 3);
    }
    SECTION("Test List 2") {
        L.PushFront(21);
        L.PushBack(15);
        INFO("List(21) return wrong");
        CHECK(L.PopFront() == 12);
        INFO("List(15) return wrong");
        CHECK(L.PopBack() == 10);
    }
    SECTION("Test List 3") {
        L.PushFront(334);
        L.PushBack(571);
        CHECK(L.PopFront() == 334);
        INFO("List(571) return wrong");
        CHECK(L.PopBack() == 500);
    }
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}