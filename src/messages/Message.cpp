/* Standard library headers */
#include <inttypes.h>
#include <stdint.h>
#include <string>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/RecorderManager.hpp"

OrderAdd::OrderAdd(std::string line){
  add_attributes(line);
}

void OrderAdd::add_attributes(std::string line){
  timestamp_offset = stoi(line.substr(1,8));
  order_ID = line.substr(10,12);
  side = line.substr(22,1);
  order_quantity = std::stoi(line.substr(23,6));
  instrument = line.substr(29,6); // ignore 2 final spaces to be consistent with Trade instrument
  limit_price = std::stoi(line.substr(35,10));
  YN = (line.substr(45,1).compare("Y") == 0) ? true : false;
}

void OrderAdd::pass_to_recorder(RecorderManager* rm){
  rm->receive_update(*this);
}

OrderCancel::OrderCancel(std::string line){
  add_attributes(line);
}

void OrderCancel::add_attributes(std::string line){
  timestamp_offset = std::stoi(line.substr(1,8));
  order_ID = line.substr(10,12);
  cancel_quantity = std::stoi(line.substr(22,6));
}

void OrderCancel::pass_to_recorder(RecorderManager* rm){
  rm->receive_update(*this);
}

OrderExecuted::OrderExecuted(std::string line){
  add_attributes(line);
}

void OrderExecuted::add_attributes(std::string line){
  timestamp_offset = std::stoi(line.substr(1,8));
  order_ID = line.substr(10,12);
  execution_quantity = std::stoi(line.substr(22,6));
  execution_ID = line.substr(28,12);
}

void OrderExecuted::pass_to_recorder(RecorderManager* rm){
  rm->receive_update(*this);
}

Trade::Trade(std::string line){
  add_attributes(line);
}

void Trade::add_attributes(std::string line){
  timestamp_offset = std::stoi(line.substr(1,8));
  order_ID = line.substr(10,12);
  side = line.substr(22,1);
  order_quantity = stoi(line.substr(23,6));
  instrument = line.substr(29,6);
  price = std::stoi(line.substr(35,10));
  execution_ID = line.substr(45,12);
}

void Trade::pass_to_recorder(RecorderManager* rm){
  rm->receive_update(*this);
}
