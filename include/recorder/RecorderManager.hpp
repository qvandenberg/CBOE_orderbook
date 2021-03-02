#ifndef RECORDERS_MANAGER_H
#define RECORDERS_MANAGER_H

/* Standard library headers */
#include <string>
#include <map>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/InstrumentRecorder.hpp"
#include "io/Output.hpp"
// #include "io/writer.hpp"

// forward declaration
struct Trade;

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
  std::map<std::string, std::shared_ptr<InstrumentRecorder> > instrument_recorders; // instrument, Order*
  std::map<std::string, std::string > id_to_instrument; // order id, instrument

public:
  RecorderManager() = default;
  ~RecorderManager() = default;

  void receive_update(OrderAdd*);
  void receive_update(OrderExecuted* );
  void receive_update(OrderCancel*);
  void receive_update(Trade* );

  // RecorderManager& operator+=(const OrderAdd* add);
  // RecorderManager& operator+=(const OrderExecuted* executed);
  // RecorderManager& operator+=(const OrderCancel* cancel);
  // RecorderManager& operator+=(const Trade* trade);

};

#endif
