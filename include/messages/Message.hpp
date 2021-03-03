#ifndef MESSAGE_BASE_HPP
#define MESSAGE_BASE_HPP

/* Standard library headers */
#include <inttypes.h>
#include <stdint.h>
#include <string>

/* Internal headers */
#include "recorder/RecorderManager.hpp"


class Message {
public:
  Message() {}
  virtual ~Message() {}
  virtual void add_attributes(std::string) = 0;
  virtual void pass_to_recorder(RecorderManager*) = 0;
};


struct OrderAdd : public Message { // MessageType: 0x414F, total of 52 bytes
  /* Timestamp offset (ms since midnight), length 8  */
  int timestamp_offset;
  /* CBOE-assigned order ID, length 12 */
  std::string order_ID;
  /* buy/sell flag, ('B': buy, 'S' : sell), length 1  */
  std::string side;
  /* order quantity, length 6  */
  int order_quantity;
  /* Instrument, length 8  */
  std::string instrument;
  /* 1E4 *  limit price, length 10 (represents 10^4 * price ) */
  int limit_price;
  /* Visibility flag */
  bool YN;

public:
  OrderAdd(){}
  OrderAdd(std::string line);
  ~OrderAdd(){}
  void pass_to_recorder(RecorderManager*) override;
  void add_attributes(std::string) override;
};


struct OrderCancel : public Message {
  /* Timestamp offset (ms since midnight), length 8  */
  int timestamp_offset;
  /* CBOE-assigned order ID, length 12 */
  std::string order_ID;
  /* order quantity, length 6  */
  int cancel_quantity;

public:
  OrderCancel(){}
  OrderCancel(std::string line);
  ~OrderCancel(){}
  void pass_to_recorder(RecorderManager*) override;
  void add_attributes(std::string) override;
};

struct OrderExecuted : public Message {
  /* Timestamp offset (ms since midnight), length 8  */
  int timestamp_offset;
  /* CBOE-assigned order ID, length 12 */
  std::string order_ID;
  /* CBOE-assigned execution ID, length 12 */
  std::string execution_ID;
  /* order quantity, length 6  */
  int execution_quantity;

public:
  OrderExecuted(){}
  OrderExecuted(std::string line);
  ~OrderExecuted(){}
  void pass_to_recorder(RecorderManager*) override;
  void add_attributes(std::string) override;
};

struct Trade : public Message {
  /* Timestamp offset (ms since midnight), length 8  */
  int timestamp_offset;
  /* CBOE-assigned order ID, length 12 */
  std::string order_ID;
  /* CBOE-assigned execution ID, length 12 */
  std::string execution_ID;
  /* buy/sell flag, ('B': buy, 'S' : sell), length 1  */
  std::string side;
  /* order quantity, length 6  */
  int order_quantity;
  /* Limit price, lenth 6  */
  std::string instrument;
  /* limit price, length 10 (represents 10^4 * price ) */
  int price;
  /* Visibility flag */
  bool YN;

public:
  Trade(){}
  Trade(std::string line);
  ~Trade(){}
  void pass_to_recorder(RecorderManager*) override;
  void add_attributes(std::string) override;
};




#endif
