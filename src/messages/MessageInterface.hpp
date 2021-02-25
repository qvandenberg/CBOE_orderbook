#ifndef MESSAGE_INTERFACE_HPP
#define MESSAGE_INTERFACE_HPP

/* Standard library headers */
#include <inttypes.h>
#include <stdint.h>
#include <string>

/* Internal headers */
// #include "market_messages/container_interface.hpp"


/* Message types
All message types as they are listed below.
This provides the input to switch statements
to operator the file reader.

*/
enum class MTypes {
  OrderAdd,
  OrderCancel,
  OrderExecuted,
  Trade
};

class MessageBase {
public:

  // research virtual constructor

  virtual ~MessageBase(){}

  virtual void add_attributes(std::string message_attributes) = 0;

};





#endif
