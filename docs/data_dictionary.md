

Index | Character or type | meaning
0     | "S"               | None, skip this
1-8   | Integer number    | # ms past midnight Eastern Time
9      | string             | Message type. 'A' = order add, 'X' = order cancel, 'P': trade  



MarketDataReader:
* Open data file
* Read line of text data  
* Split line to extract: timestamp, message type
* Construct container of appropriate data type (polymorphic objects)
* Pass remainder of string into container object
* Feed containers to a recorder object through smart pointers (function overloading, use non-polymorphic container type )

Orderbook:
* Receive updates to maintain current orderbook for 1 instrument
* When receiving 'order executed', return the amount traded

InstrumentRecorder (observer pattern):
* forward orderbook updates to 1 orderbook attribute
* Increment trade amounts

RecorderManager:
* Create one Recorder object per instrument
* Route trades and order updates to correct recorder

Output:
* rank recorders by volume
* Prepare output map
* Write to file
