Hi Quincy,
Thanks again for speaking with us yesterday. We have all software engineering candidates complete a coding exercise before moving to the next stage in the interview process. This is not a timed exercise and you can work on it at times convenient to you; but returning the exercise is required to proceed with the interview process. When you return your coding exercise, you should hear back from us within 5 business days (usually less). If you do not hear back from us within that time, please contact me by phone at the number listed below to make sure the email filters did not suppress the email.

Using the PITCH specification, write a program which reads PITCH data from standard input and, at the end of the input, shows a table of the top ten symbols by executed volume. For example, your table should look something like this:

SPY   24486275
QQQQ  15996041
XLF   10947444
IWM    9362518
MSFT   8499146
DUG    8220682
C      6756932
F      6679883
EDS    6673983
QID    6526201


In short, you'll need to read Add Order messages and remember what orders are open so you can apply Order Cancel and Order Executed messages. Trade Messages are sent for orders which were hidden. You'll need to use both Order Executed and Trade Messages to compute total volume. For simplicity, ignore any Trade Break and long messages (‘B’, ‘r’, ‘d’).

I've included a portion of live PITCH data in a file named pitch_example_data.gz. (Note that each line in the sample file begins with an extra character, 'S', not mentioned in the specification. This character is not part of the message and should be skipped by your program.)

Take as much or as little time solving the problem as you'd like. Try to write code that is "production quality" (make it efficient, make sure it doesn't leak memory, etc.). Use standard, cross-platform C++. You can use components from the STL and Boost.

Finally, we ask that you don’t post your solution on any public source repositories (i.e. GitHub, etc.) – instead, please upload everything to the Proofpoint link sent in a separate email.

If you have any questions about the problem or data set, feel free to email me.

Kind regards,
Glyn Davies


Glyn Davies | Software Engineering Manager
Cboe Europe
11 Monument Street | London, EC3R 8AF
M. +44 7976 254 850
gdavies@cboe.com | cboe.com
