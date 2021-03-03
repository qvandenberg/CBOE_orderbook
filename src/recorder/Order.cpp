/* Standard library headers */
#include <string>
#include <map>
#include <stdio.h>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/Order.hpp"


Order::Order(OrderAdd& add){
  remaining_quantity = add.order_quantity;
}

bool Order::add_order_mutation(OrderCancel& cancel){
  remaining_quantity -= cancel.cancel_quantity;
  return !(remaining_quantity > 0);
}

bool Order::add_order_mutation(OrderExecuted& executed){
  remaining_quantity -= executed.execution_quantity;
  return !(remaining_quantity > 0);
}
