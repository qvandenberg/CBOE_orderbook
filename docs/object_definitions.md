Below are the functions of the different objects that occur in this code:

Message:
* Object definitions for internal data representation

MessageFactory (Abstract factory method):
* Generate polymorphic objects based on message flag

MarketDataReader:
* Open data file
* Read line of text data  
* Split line to extract: timestamp, message type
* Construct container of appropriate data type through calls to the MessageFactory (polymorphic objects)
* Pass remainder of string into container object
* Feed containers to a recorder object through smart pointers (function overloading, use non-polymorphic container type )

InstrumentRecorder (observer pattern):
* maintain orderbook of 1 stock
* Increment trade amounts
* return flags to RecorderManager to update OrderID->instrument map

RecorderManager:
* Create one InstrumentRecorder object per instrument
* Route trades and order updates to correct recorder
* Retrieve map of (instrument : volume) pairs

InstrumentRanker:
* Sort all stocks by volume and print result
