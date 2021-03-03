#ifndef RECORDER_MANAGER_H
#define RECORDER_MANAGER_H

/* Standard library headers */
#include <string>
#include <map>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/InstrumentRecorder.hpp"

// forward declaration
struct Trade;

class RecorderManager {
private:
  std::map<std::string, std::unique_ptr<InstrumentRecorder> > instrument_recorders; // instrument, InstrumentRecorder*
  std::map<std::string, std::string > id_to_instrument; // order id, instrument

public:
  RecorderManager(){}
  ~RecorderManager();

  void receive_update(OrderAdd&);
  void receive_update(OrderExecuted& );
  void receive_update(OrderCancel&);
  void receive_update(Trade&);
  std::map<std::string, int> get_instrument_volume_map();

};

#endif
