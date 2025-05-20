#include "my_list.h"

//юнит-тест
TEST_CASE("List item defined", "[Empty]") {
    ListNode L1(2);
    ListNode L2(6);
    ListNode LN(1, &L1, &L2);
    List L;
    SECTION("Test List 1") {
        //L.PushFront(5);
        //L.PushBack(3);
        CHECK_THROWS(L.PopFront());
        CHECK_THROWS(L.PopBack());
    }
    SECTION("Test List 2") {
        L.PushFront(21);
        L.PushBack(15);
        //INFO("List(21) return wrong");
        CHECK(L.PopFront() == 21);
        //INFO("List(15) return wrong");
        CHECK(L.PopBack() == 15);
    }
    SECTION("Test List 3") {
        L.PushFront(334);
        L.PushBack(571);
        REQUIRE_NOTHROW(L.PopFront() == 334);
        INFO("List(571) return wrong");
        CHECK_THROWS(L.PopBack() == 500);
    }
}