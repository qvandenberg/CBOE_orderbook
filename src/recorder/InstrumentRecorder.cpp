/* Standard library headers */
#include <string>
#include <map>
#include <stdio.h>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/Order.hpp"
#include "recorder/InstrumentRecorder.hpp"

InstrumentRecorder::InstrumentRecorder(std::string instrument) : instrument(instrument), trade_quantity(0) {}

InstrumentRecorder::~InstrumentRecorder(){
  printf("Delete InstrumentRecorder\n");
  for (auto& [id, ptr] : order_book) {
    ptr.reset();
  }
  order_book.clear();
}

void InstrumentRecorder::add_order_mutation(OrderAdd& add){
  // printf("order ID: %s\tAdded quantity: %d \n", add.order_ID.c_str(), add.order_quantity);
  order_book[add.order_ID] = std::make_unique<Order>(add);
}

void InstrumentRecorder::add_trade(Trade& trade){
  // printf("order ID: %s\tTraded quantity: %d \n", trade.order_ID.c_str(), trade.order_quantity);
  // printf("Currently traded: %d\n", trade.order_quantity);
  trade_quantity += trade.order_quantity;
}

bool InstrumentRecorder::add_order_mutation(OrderExecuted& executed){
  // printf("order ID: %s\tExecuted quantity: %d \n", executed.order_ID.c_str(), executed.execution_quantity);
  trade_quantity += executed.execution_quantity;
  bool delete_flag = order_book[executed.order_ID]->add_order_mutation(executed);
  if (delete_flag){
    // printf("Deleting executed\n");
    delete_orderbook_entry(executed.order_ID);
  }
  return delete_flag;
}

bool InstrumentRecorder::add_order_mutation(OrderCancel& cancel){
  // printf("order ID: %s\tCancel quantity: %d \n", cancel.order_ID.c_str(), cancel.cancel_quantity);
  bool delete_flag = order_book[cancel.order_ID]->add_order_mutation(cancel);
  if (delete_flag){
    // printf("Deleting cancelled\n");
    delete_orderbook_entry(cancel.order_ID);
  }
  return delete_flag;
}

void InstrumentRecorder::delete_orderbook_entry(std::string id){
  order_book[id].reset();
  order_book.erase(id);
}
