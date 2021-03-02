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


std::shared_ptr<Message> MessageFactory::get_message_container(std::string message_type){
  std::shared_ptr<Message> message;
  if (message_type.compare("A") == 0){ // order add
    message = std::make_shared<OrderAdd>();
  }
  else if (message_type.compare("X") == 0){ // order cancel
    message = std::make_shared<OrderCancel>();
  }
  else if (message_type.compare("E") == 0){ // order executed
    message = std::make_shared<OrderExecuted>();
  }
  else if (message_type.compare("P") == 0){ // Trade
    message = std::make_shared<Trade>();
  }
  else { // unimplemented error
    printf("Message type not recognised: %s\n", message_type.c_str());
    throw std::invalid_argument( "Message type not implemented" );
  }
  return message;
}
