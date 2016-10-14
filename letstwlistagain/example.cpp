#include "list.h"

struct Item : public ListHook {
  Item();
  Item(const Item&) = delete;
  Item(Item&&) = delete;
  Item& operator = (const Item&) = delete;
  Item& operator = (Item&&) = delete;
};


void Example() {
  List<Item> l;
  Item i1, i2, i3;
  
  l.PushBack(&i1);
  l.PushBack(&i2);
  l.PushBack(&i3);

  ASSERT_EQ(++l.IteratorTo(&i2), l.IteratorTo(&i3));
  l3.Unlink();
}
