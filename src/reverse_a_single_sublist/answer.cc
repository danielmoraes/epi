/*
 *
 * EPI
 * Reverse Single Sublist (8.2)
 *
 */

#include <linked_list.h>
#include <memory>
#include <utils.h>

using std::make_shared;
using std::shared_ptr;

// @include
shared_ptr<ListNode<int>> reverse_sublist(shared_ptr<ListNode<int>> L,
                                          int s, int f) {
  if (s == f) {
    return L;
  }

  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto sublist_head = dummy_head;

  for (int i = 1; i < s; ++i) {
    sublist_head = sublist_head->next;
  }

  auto sublist_iter = sublist_head->next;

  while (s++ < f) {
    auto temp = sublist_iter->next;
    sublist_iter->next = temp->next;
    temp->next = sublist_head->next;
    sublist_head->next = temp;
  }

  return dummy_head->next;
}
// @exclude

int main(int argc, char* argv[]) {
  shared_ptr<ListNode<int>> L = make_shared<ListNode<int>>(ListNode<int>{
      1, make_shared<ListNode<int>>(ListNode<int>{
        2, make_shared<ListNode<int>>(ListNode<int>{
          3, make_shared<ListNode<int>>(ListNode<int>{
            4, make_shared<ListNode<int>>(ListNode<int>{
              5, make_shared<ListNode<int>>(ListNode<int>{6, nullptr})
            })
          })
        })
      })
    });

  print_list(L);

  L = reverse_sublist(L, 1, 6);
  print_list(L);

  L = reverse_sublist(L, 2, 5);
  print_list(L);

  L = reverse_sublist(L, 1, 6);
  print_list(L);

  return 0;
}
