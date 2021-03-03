#ifndef MESSAGE_FACTORY_HPP
#define MESSAGE_FACTORY_HPP

/* Standard library headers */
#include <string>
#include <memory>

/* Internal headers */
#include "messages/Message.hpp"

class MessageFactory {
public:
  MessageFactory() = default;
  ~MessageFactory() = default;
  std::unique_ptr<Message> get_message_container(std::string message_type);
};

#endif
