
/* Standard library headers */
#include <string>
#include <map>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/InstrumentRecorder.hpp"
#include "recorder/RecorderManager.hpp"

void RecorderManager::receive_update(OrderAdd* add){
  if ( instrument_recorders.find(add->instrument) == instrument_recorders.end() ) {
    instrument_recorders[add->instrument] = std::make_shared<InstrumentRecorder>(add->instrument);
  }
  instrument_recorders[add->instrument]->add_order_mutation(add);
}



// RecorderManager& RecorderManager::operator+=(const OrderAdd* add){
//   if ( instrument_recorders.find(add->instrument) == instrument_recorders.end() ) {
//     instrument_recorders[add->instrument] = std::make_shared<InstrumentRecorder>(add->instrument);
//   }
//   instrument_recorders[add->instrument]->add_order_mutation(add);
//   return *this;
// }

// RecorderManager& RecorderManager::operator+=(const OrderExecuted* executed){
//   std::string instr = id_to_instrument[executed->order_ID];
//   instrument_recorders[instr]->add_order_mutation(executed);
//   return *this;
// }

void RecorderManager::receive_update(OrderExecuted* executed){
  std::string instr = id_to_instrument[executed->order_ID];
  instrument_recorders[instr]->add_order_mutation(executed);
}

// RecorderManager& RecorderManager::operator+=(const OrderCancel* cancel){
//   std::string instr = id_to_instrument[cancel->order_ID];
//   instrument_recorders[instr]->add_order_mutation(cancel);
//   return *this;
// }

void RecorderManager::receive_update(OrderCancel* cancel){
  std::string instr = id_to_instrument[cancel->order_ID];
    instrument_recorders[instr]->add_order_mutation(cancel);
}

// RecorderManager& RecorderManager::operator+=(const Trade* trade){
//   instrument_recorders[trade->instrument]->add_trade(trade);
//   return *this;
// }

void RecorderManager::receive_update(Trade* trade){
    instrument_recorders[trade->instrument]->add_trade(trade);
}
