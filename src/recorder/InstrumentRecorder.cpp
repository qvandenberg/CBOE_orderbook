/* Standard library headers */
#include <string>
#include <map>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/Order.hpp"
#include "recorder/InstrumentRecorder.hpp"

InstrumentRecorder::InstrumentRecorder(std::string instrument) : instrument(instrument){
  trade_quantity = 0;
}

void InstrumentRecorder::add_order_mutation(OrderAdd* add){
  // add entry
  // order_book[add->order_ID]->add_order_mutation(add);
}

void InstrumentRecorder::add_order_mutation(OrderExecuted* executed){
  // add entry
  // order_book[add->order_ID]->add_order_mutation(add);
}

void InstrumentRecorder::add_order_mutation(OrderCancel* cancel){
  // add entry
  // order_book[add->order_ID]->add_order_mutation(add);
}

void InstrumentRecorder::add_trade(Trade* trade){
  // add entry
  // order_book[add->order_ID]->add_order_mutation(add);
}
