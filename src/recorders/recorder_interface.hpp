#ifndef RECORDERS_INTERFACE_H
#define RECORDERS_INTERFACE_H

/* Standard library headers */
#include <string>
/* Internal headers */
#include "io/writer.hpp"

/*
Interface for recorder objects:
these objects hold the internal representation and computations
that are done on the market data. Examples are an orderbook class
that aggregate all order additions and cancellations, or a direct
export to text files.

Polymorphic objects of the Recorder type can receive input from the
Reader object.
*/
class RecorderInterface {
public:
  /* Required to have well-defined destructor behaviour in derived classes */
  virtual ~RecorderInterface(){}

  virtual void set_output_sink(out::Writer  writer) = 0;

  virtual void receive_market_update(OrderAdd order_add) = 0;

  virtual void receive_market_update(OrderCancel order_cancel) = 0;

  virtual void receive_market_update(OrderTrade order_trade) = 0;

  virtual void receive_market_update(Heartbeat heartbeat) = 0;

  virtual void receive_market_update(SnapshotHeader header) = 0;

  virtual void receive_market_update(SnapshotFooter footer) = 0;

  virtual void receive_market_update(OrderbookStatus status) = 0;

};

#endif
