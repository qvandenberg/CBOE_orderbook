
/* Standard library headers */
#include <string>
#include <fstream>
#include <memory>
#include <iostream>
#include <memory>
#include <sys/stat.h>

/* Internal headers */
// #include "io/io.hpp"
#include "io/MarketDataReader.hpp"
#include "recorder/RecorderManager.hpp"
// #include "recorder/recorder_interface.hpp"



MarketDataReader::MarketDataReader(std::string file_path) : market_data_file_path_(file_path) {
  bytes_read_ = 0;
  m_factory = new MessageFactory();
  recorder_ = new RecorderManager();
}

MarketDataReader::~MarketDataReader(){
  in_file_.close();
  delete m_factory;
  delete recorder_;
}

void MarketDataReader::set_recorder_manager(RecorderManager* recorder){
  recorder_ = recorder;
}

void MarketDataReader::read_file_to_recorder(){
  // printf("File size: %u bytes\n", get_file_size());
  in_file_.open(market_data_file_path_);
  std::string line;
  std::string file_contents;
  std::string message_type;

  while (std::getline(in_file_, line)) {
    bytes_read_ += line.length();
    message_type = line.substr(9,1);
    std::unique_ptr<Message> message = m_factory->get_message_container(message_type);
    message->add_attributes(line);
    message->pass_to_recorder(recorder_);
  }
  in_file_.close();

  /* Difference with actual text file size is likely the header */
  // printf("Read in %u \n", get_file_size()- get_remaining_size());
}


inline bool MarketDataReader::file_exists() {
    struct stat buffer;
    return (stat(market_data_file_path_.c_str(), &buffer) == 0);
}

unsigned int MarketDataReader::get_file_size(){
  unsigned int file_size;
  if (file_exists()){ //market_data_file_path_.c_str())){
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
