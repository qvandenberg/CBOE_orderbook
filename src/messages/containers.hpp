#ifndef MESSAGE_CONTAINERS_HPP
#define MESSAGE_CONTAINERS_HPP

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

The MessageHeader is not included as this will
always be the first 12 bytes.
*/
enum class MTypes {
  MessageHeader,
  Heartbeat,
  SnapshotHeader,
  SnapshotFooter,
  OrderbookStatus,
  OrderAdd,
  OrderCancel,
  ErrorCode,
  OrderTrade,
  Unknown
};

/* Remove padding at bit level */
#pragma pack(push, 1)



struct OrderAdd { // MessageType: 0x414F, total of 52 bytes
  /* Timestamp offset (ms since midnight), length 8  */
  unsigned int timestamp_offset;
  /* Order addition flag, length 1 */
  char A;
  /* CBOE-assigned order ID, length 12 */
  std::string order_ID;
  /* buy/sell flag, ('B': buy, 'S' : sell), length 1  */
  char side;
  /* order quantity, length 6  */
  unsigned int order_quantity;
  /* Limit price, lenth 6  */
  char instrument;
  /* limit price, length 10 (represents 10^4 * price ) */
  int limit_price;
  /* Visibility flag */
  char YN;
};

struct OrderCancel {
  /* Timestamp offset (ms since midnight), length 8  */
  unsigned int timestamp_offset;
  /* Order cancel flag, length 1 */
  char X;
  /* CBOE-assigned order ID, length 12 */
  std::string order_ID;
  /* order quantity, length 6  */
  unsigned int cancel_quantity;
};


// not present in current market data, therefore not implemented
struct OrderTrade { };

#pragma pack(pop)




#endif
