#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;


#pragma pack(push, 1)

struct MessageHeader {
  unsigned short int m_length;
  /* message type, 2 bytes  */
  unsigned short int m_type;
  /* sequence number, 8 bytes  */
  long int sequence_no;
};

#pragma pack(pop)

class MessageHeaderGenerator {
private:
  const size_t mheader_len = 12;

public:
  MessageHeaderGenerator() = default;

  MessageHeader* get_container_instance(){
    MessageHeader* mh = new MessageHeader();
    return mh;
  }

};

int main() {
   string fileName = "../data/binary/itch-daily-2020-11-22_ldprof.itch"; // Binary file name

   ///// Read Binary File ////
   MessageHeaderGenerator* gen = new MessageHeaderGenerator();
   // MessageHeader * read_mh = gen->get_container_instance();

   ifstream inputFile;
   inputFile.open(fileName.c_str(), ios::binary);
   if(inputFile.is_open()) {
      const size_t mh_size = 12;

      while(!inputFile.eof()) {
        // MessageHeader * read_mh = gen->get_container_instance();
        MessageHeader read_mh = MessageHeader();

        inputFile.read((char*)(&read_mh), sizeof(MessageHeader));
        size_t remaining_bytes = static_cast<size_t>(read_mh.m_length) - mh_size;
        char buffer[remaining_bytes];
        inputFile.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
        printf("Read message with length: %d type: %#.4X\n", remaining_bytes, read_mh.m_type);

      }
      inputFile.close();
   } else {
      cout << "Could not read file " + fileName;
   }
   /* Delete objects */
   // delete read_mh;
   delete gen;

   return 0;
}
