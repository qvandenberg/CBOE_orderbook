/* Standard library headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
#include <inttypes.h>

/* Internal headers */
#include "io.h"

// read and write binary file
// #define READ_BINARY(file, var, type) file.read(reinterpret_cast<char*> &(var), sizeof(type))
// #define READ_BINARY_ARRAY(file, var, type, n) file.read(reinterpret_cast<char*> &(var[0]), sizeof(type)*n)
#define READ_BINARY(file, var, type) file.read((char*) &(var), sizeof(type))
#define READ_BINARY_ARRAY(file, var, type, n) file.read((char*) &(var[0]), sizeof(type)*n)

using namespace std;

/* Define data structures for different message types */

struct message_header {
  uint32_t message_length;
  uint32_t message_type;
  long int sequence;
};

int main(int argc, char* argv[]) {
  // read the input filename
  std::string input_fname;
  if (argc > 1) {
      input_fname = argv[1];
  } else {
      input_fname = "../data/binary/itch-daily-2020-11-22_ldprof.itch";
      printf("No filename provided in argument:\t");
      printf("Using %s as a default.\n", input_fname.c_str());
      // exit(1);
  }

  std::ifstream infile(input_fname.c_str(), ios::in | ifstream::binary);

  unsigned short int dummy_var; // 2 bytes, message length
  READ_BINARY(infile, dummy_var, unsigned short int);
  printf("message length %hu\n", dummy_var);

  READ_BINARY(infile, dummy_var, unsigned short int); // 2 bytes, message type
  printf("message type %#.4X\n", dummy_var); // printed in big endian style (order reversed compared to little endian)

  // test conditional statements
  if (dummy_var == 0X4853){
    cout << "hex value matches snapshot header" << "\n";
  }
  long int seq_no; // 8 bytes, sequence number
  READ_BINARY(infile, seq_no,  long int);
  cout << "header sequence no: " << (seq_no) << "\n";

  /* first message */
  unsigned long int snap_seq; // 8 bytes, snapshot sequence
  READ_BINARY(infile, snap_seq, unsigned long int);
  cout << "\nFirst message snap_seq: " << (snap_seq) << "\n";

  unsigned int snap_timestamp; // 4 bytes, Snapshot Timestamp
  READ_BINARY(infile, snap_timestamp, unsigned int);
  cout << " snap_timestamp: " << (snap_timestamp) << "\n";

  unsigned int snap_timestamp2; // Snapshot offset
  READ_BINARY(infile, snap_timestamp2, unsigned int);
  cout << " timestamp offset: " << (snap_timestamp2) << "\n";

  READ_BINARY(infile, dummy_var, unsigned short int); // 2 bytes, snapshot footer
  printf("next message length %hu\n", dummy_var);

  // printf("message type %#.4X\n", dummy_var); // printed in big endian style (order reversed compared to little endian)


  /*
  uint32_t dummy_var;
  infile.read ((char*) &(dummy_var), sizeof(dummy_var));
  cout << "length of message: " << dummy_var << "\n";
  infile.read ((char*) &(dummy_var), sizeof(dummy_var));
  cout << "message type: " << dummy_var << "\n";
  long int dummy2;
  infile.read ((char*) &(dummy2), sizeof(dummy2));
  cout << "sequence number: " << dummy2 << "\n";
  */

  // char* message_type;
  // READ_BINARY(infile, message_length, uint32_t);
  // printf("Read message header of length %zu\n", message_length);
  //
  // char * buffer = new char [4];
  // READ_BINARY(infile, buffer, int);
  // printf("Read message header of length %s\n", buffer);
  //
  // uint32_t dummy_var;
  // READ_BINARY(infile, dummy_var, uint32_t);
  // printf("Read message header of length %d\n", dummy_var);

  infile.close();

  return 0;
}
