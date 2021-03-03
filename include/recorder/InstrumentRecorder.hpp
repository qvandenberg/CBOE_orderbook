#ifndef INSTRUMENT_RECORDER_HPP
#define INSTRUMENT_RECORDER_HPP

/* Standard library headers */
#include <string>
#include <map>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/Order.hpp"

//forward declaration
struct Trade;

class InstrumentRecorder {
private:
  std::string instrument;
  int trade_quantity;
  std::map<std::string, std::unique_ptr<Order> > order_book; // order_ID, Order*

public:
  InstrumentRecorder(std::string instrument);
  ~InstrumentRecorder();

  void add_order_mutation(OrderAdd& add);
  void add_trade(Trade& trade);
  bool add_order_mutation(OrderExecuted& executed);
  bool add_order_mutation(OrderCancel& cancel);
private:
  void delete_orderbook_entry(std::string);
};


#endif
