#ifndef ORDERBOOK_H
#define ORDERBOOK_H

/* Standard library headers */

/* Internal headers */
#include "recorder/recorder_interface.hpp"
#include "market_messages/containers.hpp"

class Orderbook : public RecorderInterface {
private:
  // orderbook parameters

public:
  Orderbook() = default;
  ~Orderbook() = default;

  void set_output_sink(out::Writer  writer);

  void receive_market_update(OrderAdd order_add);

  void receive_market_update(OrderCancel order_cancel);

  void receive_market_update(OrderTrade order_trade);

  void receive_market_update(Heartbeat heartbeat);

  void receive_market_update(SnapshotHeader header);

  void receive_market_update(SnapshotFooter footer);

  void receive_market_update(OrderbookStatus status);



};


#endif
