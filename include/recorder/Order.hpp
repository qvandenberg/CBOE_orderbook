#ifndef ORDER_HPP
#define ORDER_HPP

/* Standard library headers */
#include <string>
#include <memory>

/* Internal headers */
#include "messages/Message.hpp"

// forward declarations
struct OrderAdd;
struct OrderExecuted;
struct OrderCancel;

class Order {
private:
  int remaining_quantity;
  // more attributes can be added to compute prices or other quantities

public:
  Order(OrderAdd&);
  ~Order(){}

  // existence flag: false if order quantity is now zero, true if nonzero
  bool add_order_mutation(OrderExecuted&);
  bool add_order_mutation(OrderCancel&); };


#endif
