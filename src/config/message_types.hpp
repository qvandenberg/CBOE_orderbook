#ifndef MESSAGE_TYPES_H
#define MESSAGE_TYPES_H

/* Standard library headers */
#include <string>

/* External headers */
#include "market_messages/containers.hpp"
#include "parallel_hashmap/btree.h"


/*
Map the LMAX message type definitions to an enumerable class object. This will be used to call the appropriate container generator.

All message types are specified in big endian format.
*/

namespace LMAX {

  MTypes message_type_to_enum(unsigned short int m_type){
    MTypes message_type;
    switch(m_type){
      case (0x2E48): // heartbeat
        message_type = MTypes::Heartbeat;
        break;
      case (0x4853): // snapsnot header
        message_type = MTypes::SnapshotHeader;
        break;
      case (0x4653): // snapshot footer
        message_type = MTypes::SnapshotFooter;
        break;
      case (0x5342): // OrderbookStatus
        message_type = MTypes::OrderbookStatus;
        break;
      case (0x414F): // OrderAdd
        message_type = MTypes::OrderAdd;
        break;
      case (0x434F): // OrderCancel
        message_type = MTypes::OrderCancel;
        break;
      case (0x5245): // ErrorCode
        message_type = MTypes::ErrorCode;
        break;
      case (0x544F): // OrderTrade
        message_type = MTypes::OrderTrade;
        break;
      default: // message type unknown
        printf("Warning: Message type %#.4X not implemented\n", m_type);
        message_type = MTypes::Unknown;
        break;
    }

    return message_type;
  }


  size_t message_size_from_type(MTypes m_type){
    size_t size;
    switch(m_type){
      case (MTypes::MessageHeader):{ // heartbeat
        size = 12;
        break;
      }
      case (MTypes::Heartbeat):{ // heartbeat
        size = 4;
        break;
      }
      case (MTypes::SnapshotHeader):{ // snapsnot header
        size = 16;
        break;
      }
      case (MTypes::SnapshotFooter):{ // snapshot footer
        size = 0;
        break;
      }
      case (MTypes::OrderbookStatus):{ // OrderbookStatus
        size = 12;
        break;
      }
      case (MTypes::OrderAdd):{ // OrderAdd
        size = 52;
        break;
      }
      case (MTypes::OrderCancel):{ // OrderCancel
        size = 52;
        break;
      }
      case (MTypes::ErrorCode):{ // ErrorCode
        size = 4;
        break;
      }
      case (MTypes::OrderTrade):{ // OrderTrade
        size = 0;
        break;
      }
      case (MTypes::Unknown): {// Unknown message type
        size = 0;
        break;
      }
    }

    return size;
  }


}


#endif
