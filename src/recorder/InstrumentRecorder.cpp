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
  for (auto& [id, ptr] : order_book) {
    ptr.reset();
  }
  order_book.clear();
}

void InstrumentRecorder::add_order_mutation(OrderAdd& add){
  order_book[add.order_ID] = std::make_unique<Order>(add);
}

void InstrumentRecorder::add_trade(Trade& trade){
  trade_quantity += trade.order_quantity;
}

bool InstrumentRecorder::add_order_mutation(OrderExecuted& executed){
  trade_quantity += executed.execution_quantity;
  bool delete_flag = order_book[executed.order_ID]->add_order_mutation(executed);
  if (delete_flag){
    delete_orderbook_entry(executed.order_ID);
  }
  return delete_flag;
}

bool InstrumentRecorder::add_order_mutation(OrderCancel& cancel){
  bool delete_flag = order_book[cancel.order_ID]->add_order_mutation(cancel);
  if (delete_flag){
    delete_orderbook_entry(cancel.order_ID);
  }
  return delete_flag;
}

void InstrumentRecorder::delete_orderbook_entry(std::string id){
  order_book[id].reset();
  order_book.erase(id);
}

int InstrumentRecorder::get_executed_volume(){
  return trade_quantity;
}
