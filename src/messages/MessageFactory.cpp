
/* Standard library headers */
#include <inttypes.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdexcept>

/* Internal headers */
#include "messages/Message.hpp"
#include "messages/MessageFactory.hpp"
// #include "MessageContainers.hpp"
// #include "market_messages/container_interface.hpp"




Message* MessageFactory::get_message_container(std::string message_type){
  Message* message;
  if (message_type.compare("A") == 0){ // order add
    message = new OrderAdd();
  }
  else if (message_type.compare("X") == 0){ // order cancel
    message = new OrderCancel();
  }
  else if (message_type.compare("E") == 0){ // order executed
    message = new OrderExecuted();
  }
  else if (message_type.compare("P") == 0){ // Trade
    message = new Trade();
  }
  else { // unimplemented error
    printf("Message type not recognised: %s\n", message_type.c_str());
    throw std::invalid_argument( "Message type not implemented" );
  }
  return message;
}
