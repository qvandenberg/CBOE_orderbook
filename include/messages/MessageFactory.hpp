#ifndef MESSAGE_FACTORY_HPP
#define MESSAGE_FACTORY_HPP

/* Standard library headers */
#include <inttypes.h>
#include <stdint.h>
#include <string>
#include <memory>

/* Internal headers */
#include "messages/Message.hpp"
// #include "MessageContainers.hpp"
// #include "market_messages/container_interface.hpp"


/* MessageContainerGenerator
Generate empty container of appropriate type based on message type input
*/
class MessageFactory {
public:
  MessageFactory() = default;
  ~MessageFactory() = default;
  std::unique_ptr<Message> get_message_container(std::string message_type);
};






#endif
