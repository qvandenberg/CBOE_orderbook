
/* Standard library headers */
#include <string>
#include <fstream>
#include <memory>

/* Internal headers */
#include "io/io.hpp"
#include "market_messages/containers.hpp"
#include "recorders/recorder_interface.hpp"
#include "io/binary_reader.hpp"
#include "config/message_types.hpp"


BinaryReader::BinaryReader(){
// log action
 }

BinaryReader::BinaryReader(std::string file_path) : market_data_file_path_(file_path) {
  // log action
  in_file_.open(market_data_file_path_.c_str(), std::ios::binary);
  bytes_read_ = 0;
}

BinaryReader::~BinaryReader(){
  // log
  in_file_.close();
}

unsigned int BinaryReader::get_file_size(){
  unsigned int file_size;
  if (is_file_exist(market_data_file_path_.c_str())){
    file_size = std::filesystem::file_size(market_data_file_path_);
  }
  else {
    printf("File %s does not exist.\n", market_data_file_path_.c_str());
  }
  return file_size;
}

void BinaryReader::set_input_file(std::string input_file){
  market_data_file_path_ = input_file;
  in_file_.open(market_data_file_path_.c_str(), std::ios::binary);
  bytes_read_ = 0;
}

void BinaryReader::set_recorder(RecorderInterface* recorder){
  recorder_ = recorder;
}

void BinaryReader::read_file_to_recorder(){
  if(in_file_.is_open()) {
    /*
    Traverse through file in one pass and write blocks of bytes to corresponding message types.
    Copy the structs holding messages to a Recorder object for further processing (call by value to avoid issues around object lifetime in the switch statement)
    */
    MTypes next_message_type = MTypes::MessageHeader;
    unsigned int message_size;
    while(!in_file_.eof()) {
      switch (next_message_type){
        case (MTypes::MessageHeader): {
          MessageHeader mh = MessageHeader();
          message_size = LMAX::message_size_from_type(MTypes::MessageHeader);
          in_file_.read((char*)(&mh), message_size);
          next_message_type = LMAX::message_type_to_enum(mh.m_type);
          if (1200519490 < mh.sequence_no){
          printf("Mh %hu %#.4X %ld\t", mh.m_length, mh.m_type, mh.sequence_no);
          printf("Bytes read in %u\n", bytes_read_);
        }
          break;
        }

        case (MTypes::Heartbeat): {
          Heartbeat hb = Heartbeat();
          message_size = LMAX::message_size_from_type(MTypes::Heartbeat);
          in_file_.read((char*)(&hb), message_size);
          next_message_type = MTypes::MessageHeader;
          // printf("HB %ul\n", hb.timestamp);
          break;
        }

        case (MTypes::SnapshotHeader): {
          SnapshotHeader sh = SnapshotHeader();
          message_size = LMAX::message_size_from_type(MTypes::SnapshotHeader);
          in_file_.read((char*)(&sh), message_size);
          next_message_type = MTypes::MessageHeader;
          // printf("SH %ul\n", sh.timestamp);
          break;
        }

        case (MTypes::SnapshotFooter): {
          SnapshotFooter sf = SnapshotFooter();
          message_size = LMAX::message_size_from_type(MTypes::SnapshotFooter);
          in_file_.read((char*)(&sf), message_size);
          next_message_type = MTypes::MessageHeader;
          // printf("SF\n");
          break;
        }

        case (MTypes::OrderbookStatus): {
          OrderbookStatus obs = OrderbookStatus();
          message_size = LMAX::message_size_from_type(MTypes::OrderbookStatus);
          in_file_.read((char*)(&obs), message_size);
          next_message_type = MTypes::MessageHeader;
          // printf("OBS %hu\n", obs.orderbook_id);
          break;
        }

        case (MTypes::OrderAdd): {
          OrderAdd oa = OrderAdd();
          message_size = LMAX::message_size_from_type(MTypes::OrderAdd);
          in_file_.read((char*)(&oa), message_size);
          next_message_type = MTypes::MessageHeader;
          // printf("OA %ld\n", oa.order_id);
          break;
        }

        case (MTypes::OrderCancel): {
          OrderCancel oc = OrderCancel();
          message_size = LMAX::message_size_from_type(MTypes::OrderCancel);
          in_file_.read((char*)(&oc), message_size);
          next_message_type = MTypes::MessageHeader;
          // printf("OC %ld\n", oc.order_id);
          break;
        }

        case (MTypes::ErrorCode): {
          ErrorCode ec = ErrorCode();
          message_size = LMAX::message_size_from_type(MTypes::ErrorCode);
          in_file_.read((char*)(&ec), message_size);
          next_message_type = MTypes::MessageHeader;
          // printf("EC %ud\n", ec.error_code);
          break;
        }

        case (MTypes::Unknown): {
          printf("Message type BinaryReader not implemented.\n");
          printf("%u bytes read.\n", bytes_read_);
          // log error
          break;
        }
      }
      bytes_read_ += message_size;
    }
  }
}
