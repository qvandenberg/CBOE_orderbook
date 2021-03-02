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
  unsigned int trade_quantity; // trades only, does not count OrderExecuted
  std::map<std::string, Order* > order_book; // order_ID, Order*

public:
  InstrumentRecorder(std::string instrument);
  ~InstrumentRecorder() = default;

  void add_order_mutation(OrderAdd* add);
  void add_order_mutation(OrderExecuted* executed);
  void add_order_mutation(OrderCancel* cancel);
  void add_trade(Trade* trade);

};


#endif
