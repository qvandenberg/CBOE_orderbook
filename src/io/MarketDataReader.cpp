
/* Standard library headers */
#include <string>
#include <fstream>
#include <memory>
#include <iostream>
#include <memory>

/* Internal headers */
#include "io/io.hpp"
#include "io/MarketDataReader.hpp"
#include "recorder/RecorderManager.hpp"
// #include "recorder/recorder_interface.hpp"



MarketDataReader::MarketDataReader(std::string file_path) : market_data_file_path_(file_path) {
  bytes_read_ = 0;
}

MarketDataReader::~MarketDataReader(){
  in_file_.close();
}

unsigned int MarketDataReader::get_file_size(){
  unsigned int file_size;
  if (is_file_exist(market_data_file_path_.c_str())){
    file_size = std::filesystem::file_size(market_data_file_path_);
  }
  else {
    printf("File %s does not exist.\n", market_data_file_path_.c_str());
  }
  return file_size;
}

unsigned int MarketDataReader::get_remaining_size(){
  return (get_file_size() - bytes_read_);
}


void MarketDataReader::set_recorder(RecorderManager* recorder){
  recorder_ = recorder;
}

void MarketDataReader::read_file_to_recorder(){

  in_file_.open(market_data_file_path_);
  std::string line;
  std::string file_contents;
  std::string message_type;

  while (std::getline(in_file_, line)) {
    bytes_read_ += line.length();
    message_type = line.substr(9,1);
    std::shared_ptr<Message> message = m_factory->get_message_container(message_type);
    message->add_attributes(line);
    message->pass_to_recorder(recorder_);
  }
  in_file_.close();
}
