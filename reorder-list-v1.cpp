void reorderList(ListNode *head) {
  if (head == nullptr)
    return;
  ListNode *cur = head;
  bool finish = 0;
  rec(head->next, &cur);
}

ListNode *rec(ListNode *node, ListNode **cur) {
  if (node == nullptr) {
    return nullptr;
  }

  if (node->next != nullptr) {
    ListNode *change = rec(node->next, cur);

    if (change == nullptr) {
      return nullptr;
    }

    if (*cur == node || (*cur)->next == node) {
      node->next = nullptr;
      return nullptr;
    }
  }

  ListNode *next = (*cur)->next;
  if (next == node) {
    return nullptr;
  }
  (*cur)->next = node;
  node->next = next;
  *cur = next;
  return node;
}
