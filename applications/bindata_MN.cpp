#include <iostream>
#include <fstream>
#include <vector>

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
    // mh->m_length;
    // mh->sequence_no;
    // mh->buffer_;

    return mh;
  }

};

// std::ifstream in("somefile", std::ios::binary);
// vector<char> contents((std::istreambuf_iterator<char>(in)),
// 		(std::istreambuf_iterator<char>()));

int main()
{
   MessageHeader testout = {12, 0x5348, 1};
   string fileName = "message_header_test.bin"; // Binary file name

   ofstream outputFile;
   outputFile.open(fileName.c_str(), ios::binary);

   ///// Write Binary File ////
   if(outputFile.is_open()){
      outputFile.write(reinterpret_cast<char*>(&testout), sizeof(MessageHeader));
      outputFile.close();
   } else {
      cout << "Could not create file " + fileName + "\n";
   }

   ///// Read Binary File ////
   MessageHeaderGenerator* gen = new MessageHeaderGenerator();
   MessageHeader * read_mh = gen->get_container_instance();

   ifstream inputFile;
   inputFile.open(fileName.c_str(), ios::binary);
   if(inputFile.is_open()) {
      inputFile.read(reinterpret_cast<char*>(read_mh), sizeof(MessageHeader));
      inputFile.close();
   } else {
      cout << "Could not read file " + fileName;
   }

   cout << read_mh->m_length << ", " << read_mh->sequence_no << ", " << read_mh->m_type << endl;
   return 0;
}
