/* Standard library headers */
#include <inttypes.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>

/* Internal headers */
#include "messages/Message.hpp"
#include "messages/MessageFactory.hpp"


std::unique_ptr<Message> MessageFactory::get_message_container(std::string message_type){
  std::unique_ptr<Message> message;
  if (message_type.compare("A") == 0){ // order add
    message = std::make_unique<OrderAdd>();
  }
  else if (message_type.compare("X") == 0){ // order cancel
    message = std::make_unique<OrderCancel>();
  }
  else if (message_type.compare("E") == 0){ // order executed
    message = std::make_unique<OrderExecuted>();
  }
  else if (message_type.compare("P") == 0){ // Trade
    message = std::make_unique<Trade>();
  }
  else { // unimplemented error
    printf("Message type not recognised: %s\n", message_type.c_str());
    throw std::invalid_argument( "Message type not implemented" );
  }
  return message;
}
