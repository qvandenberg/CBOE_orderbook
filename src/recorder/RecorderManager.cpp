/* Standard library headers */
#include <string>
#include <map>
#include <stdio.h>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/InstrumentRecorder.hpp"
#include "recorder/RecorderManager.hpp"

RecorderManager::~RecorderManager(){
  printf("Delete RecorderManager\n");
  // delete all instrument recorders
  for (auto& [id, ptr] : instrument_recorders) {
    ptr.reset();
  }
  instrument_recorders.clear();
  id_to_instrument.clear();
}

void RecorderManager::receive_update(OrderAdd& add){
  if ( instrument_recorders.find(add.instrument) == instrument_recorders.end() ) { // new financial instrument
    instrument_recorders[add.instrument] = std::make_unique<InstrumentRecorder>(add.instrument);
  }
  instrument_recorders[add.instrument]->add_order_mutation(add);
  id_to_instrument[add.order_ID] = add.instrument;
}

void RecorderManager::receive_update(OrderExecuted& executed){
  std::string instr = id_to_instrument[executed.order_ID];
  bool delete_flag = instrument_recorders[instr]->add_order_mutation(executed);
  if (delete_flag){ id_to_instrument.erase(executed.order_ID); }
}

void RecorderManager::receive_update(OrderCancel& cancel){
  std::string instr = id_to_instrument[cancel.order_ID];
    bool delete_flag = instrument_recorders[instr]->add_order_mutation(cancel);
    if (delete_flag){ id_to_instrument.erase(cancel.order_ID); }
}

void RecorderManager::receive_update(Trade& trade){
  if ( instrument_recorders.find(trade.instrument) == instrument_recorders.end() ) { // new financial instrument
    instrument_recorders[trade.instrument] = std::make_unique<InstrumentRecorder>(trade.instrument);
  }
  instrument_recorders[trade.instrument]->add_trade(trade);
}
