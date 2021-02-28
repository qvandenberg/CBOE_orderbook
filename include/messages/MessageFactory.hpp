#ifndef MESSAGE_FACTORY_HPP
#define MESSAGE_FACTORY_HPP

/* Standard library headers */
#include <inttypes.h>
#include <stdint.h>
#include <string>

/* Internal headers */
#include "messages/Message.hpp"
// #include "MessageContainers.hpp"
// #include "market_messages/container_interface.hpp"


/* MessageContainerGenerator
Generate empty container of appropriate type based on message type input
*/
class MessageFactory {
  MessageFactory() = default;
  ~MessageFactory() = default;

public:
  Message* get_message_container(std::string message_type);
};






#endif
