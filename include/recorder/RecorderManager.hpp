#ifndef RECORDERS_MANAGER_H
#define RECORDERS_MANAGER_H

/* Standard library headers */
#include <string>
#include <map>

/* Internal headers */
#include "messages/Message.hpp"
#include "io/Output.hpp"
// #include "io/writer.hpp"

/*
Interface for recorder objects:
these objects hold the internal representation and computations
that are done on the market data. Examples are an orderbook class
that aggregate all order additions and cancellations, or a direct
export to text files.

Polymorphic objects of the Recorder type can receive input from the
Reader object.
*/
class RecorderManager {
private:

public:
  RecorderManager();
  ~RecorderManager();

  void set_output_sink(Output*  writer);

  void receive_market_update(OrderAdd order_add);
  void receive_market_update(OrderCancel order_cancel);
  void receive_market_update(OrderExecuted order_executed);
  void receive_market_update(Trade trade);

};

#endif
